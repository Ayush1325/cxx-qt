#include "cxx-qt-gen/include/my_object.h"
#include "cxx-qt-gen/src/my_object.rs.h"

namespace cxx_qt::my_object {

MyObject::MyObject(QObject* parent)
  : QObject(parent)
  , m_rustObj(createRs())
{
  initialiseCpp(*this);
  m_initialised = true;
}

MyObject::~MyObject() = default;

bool
MyObject::getBoolean() const
{
  return m_boolean;
}

void
MyObject::setBoolean(bool value)
{
  if (!m_initialised) {
    m_boolean = value;
    return;
  }

  if (value != m_boolean) {
    m_boolean = value;

    Q_ASSERT(
      QMetaObject::invokeMethod(this, "booleanChanged", Qt::QueuedConnection));
  }
}

float
MyObject::getFloat32() const
{
  return m_float32;
}

void
MyObject::setFloat32(float value)
{
  if (!m_initialised) {
    m_float32 = value;
    return;
  }

  if (value != m_float32) {
    m_float32 = value;

    Q_ASSERT(
      QMetaObject::invokeMethod(this, "float32Changed", Qt::QueuedConnection));
  }
}

double
MyObject::getFloat64() const
{
  return m_float64;
}

void
MyObject::setFloat64(double value)
{
  if (!m_initialised) {
    m_float64 = value;
    return;
  }

  if (value != m_float64) {
    m_float64 = value;

    Q_ASSERT(
      QMetaObject::invokeMethod(this, "float64Changed", Qt::QueuedConnection));
  }
}

qint8
MyObject::getInt8() const
{
  return m_int8;
}

void
MyObject::setInt8(qint8 value)
{
  if (!m_initialised) {
    m_int8 = value;
    return;
  }

  if (value != m_int8) {
    m_int8 = value;

    Q_ASSERT(
      QMetaObject::invokeMethod(this, "int8Changed", Qt::QueuedConnection));
  }
}

qint16
MyObject::getInt16() const
{
  return m_int16;
}

void
MyObject::setInt16(qint16 value)
{
  if (!m_initialised) {
    m_int16 = value;
    return;
  }

  if (value != m_int16) {
    m_int16 = value;

    Q_ASSERT(
      QMetaObject::invokeMethod(this, "int16Changed", Qt::QueuedConnection));
  }
}

qint32
MyObject::getInt32() const
{
  return m_int32;
}

void
MyObject::setInt32(qint32 value)
{
  if (!m_initialised) {
    m_int32 = value;
    return;
  }

  if (value != m_int32) {
    m_int32 = value;

    Q_ASSERT(
      QMetaObject::invokeMethod(this, "int32Changed", Qt::QueuedConnection));
  }
}

quint8
MyObject::getUint8() const
{
  return m_uint8;
}

void
MyObject::setUint8(quint8 value)
{
  if (!m_initialised) {
    m_uint8 = value;
    return;
  }

  if (value != m_uint8) {
    m_uint8 = value;

    Q_ASSERT(
      QMetaObject::invokeMethod(this, "uint8Changed", Qt::QueuedConnection));
  }
}

quint16
MyObject::getUint16() const
{
  return m_uint16;
}

void
MyObject::setUint16(quint16 value)
{
  if (!m_initialised) {
    m_uint16 = value;
    return;
  }

  if (value != m_uint16) {
    m_uint16 = value;

    Q_ASSERT(
      QMetaObject::invokeMethod(this, "uint16Changed", Qt::QueuedConnection));
  }
}

quint32
MyObject::getUint32() const
{
  return m_uint32;
}

void
MyObject::setUint32(quint32 value)
{
  if (!m_initialised) {
    m_uint32 = value;
    return;
  }

  if (value != m_uint32) {
    m_uint32 = value;

    Q_ASSERT(
      QMetaObject::invokeMethod(this, "uint32Changed", Qt::QueuedConnection));
  }
}

std::unique_ptr<CppObj>
newCppObject()
{
  return std::make_unique<CppObj>();
}

} // namespace cxx_qt::my_object
