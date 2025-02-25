// SPDX-FileCopyrightText: 2021 Klarälvdalens Datakonsult AB, a KDAB Group company <info@kdab.com>
// SPDX-FileContributor: Andrew Hayzen <andrew.hayzen@kdab.com>
// SPDX-FileContributor: Gerhard de Clercq <gerhard.declercq@kdab.com>
//
// SPDX-License-Identifier: MIT OR Apache-2.0
use cxx_qt::make_qobject;

mod data;
pub mod sub;
mod types;

#[make_qobject]
mod my_object {
    #[derive(Default)]
    pub struct Data {
        number: i32,
        string: String,
        sub: crate::sub::sub_object::CppObj,
    }

    #[derive(Default)]
    struct RustObj {
        update_call_count: i32,
    }

    impl RustObj {
        #[invokable]
        fn double_number_self(&self, cpp: &mut CppObj) {
            let value = cpp.number() * 2;
            cpp.set_number(value);
        }

        #[invokable]
        fn double_number_sub(&self, sub: &mut crate::sub::sub_object::CppObj) {
            let value = sub.number() * 2;
            sub.set_number(value);
        }

        #[invokable]
        fn double_number(&self, number: i32) -> i32 {
            number * 2
        }

        #[invokable]
        fn say_hi(&self, string: &str, number: i32) {
            println!(
                "Hi from Rust! String is {} and number is {}",
                string, number
            );
        }

        #[invokable]
        fn request_update_test(&self, cpp: &mut CppObj) {
            let update_requester = cpp.update_requester();
            update_requester.request_update();
        }

        #[invokable]
        fn request_update_test_multi_thread(&self, cpp: &mut CppObj) {
            static N_THREADS: usize = 100;
            static N_REQUESTS: std::sync::atomic::AtomicUsize =
                std::sync::atomic::AtomicUsize::new(0);

            let mut handles = Vec::new();
            for _ in 0..N_THREADS {
                let update_requester = cpp.update_requester();
                handles.push(std::thread::spawn(move || {
                    update_requester.request_update();
                    N_REQUESTS.fetch_add(1, std::sync::atomic::Ordering::Relaxed);
                }));
            }

            for h in handles {
                h.join().unwrap();
            }

            // Make sure we actually ran all the threads
            assert_eq!(
                N_REQUESTS.load(std::sync::atomic::Ordering::Relaxed),
                N_THREADS
            );
        }

        #[invokable]
        fn update_call_count(&self) -> i32 {
            self.update_call_count
        }
    }

    impl UpdateRequestHandler<CppObj<'_>> for RustObj {
        fn handle_update_request(&mut self, _cpp: &mut CppObj) {
            self.update_call_count += 1;
        }
    }
}
