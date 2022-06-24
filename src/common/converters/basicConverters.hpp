#ifndef __BASIC_CONVERTERS_HPP__
#define __BASIC_CONVERTERS_HPP__

#include <QByteArray>
#include <QColor>
#include <QIODevice>

#include <type_traits>

namespace Converters
{

// template declarations
template<typename T>
QByteArray convert(T val);
// template declarations
template<typename T>
T convert(QIODevice &data);

// to binary converters
template<typename T>
requires std::is_arithmetic_v<T> || std::is_enum_v<T>
inline QByteArray convert(T val)
{
    return QByteArray(reinterpret_cast<char *>(&val), sizeof(val));
}

inline QByteArray convert(const QString &str)
{
    QByteArray bytes = str.toUtf8();
    uint8_t size = bytes.size();
    return bytes.prepend(reinterpret_cast<char *>(&size), sizeof(size));
}

inline QByteArray convert(const QColor &col)
{
    return convert<uint8_t>(col.red()) + convert<uint8_t>(col.green()) + convert<uint8_t>(col.blue());
}

// from binary converters
template<typename T>
requires std::is_arithmetic_v<T> || std::is_enum_v<T>
inline T convert(QIODevice &data)
{
    T val;
    data.read(reinterpret_cast<char *>(&val), sizeof(val));
    return val;
}

template<typename T>
requires std::is_arithmetic_v<T> || std::is_enum_v<T>
inline void convert(QIODevice &data, T &val)
{
    data.read(reinterpret_cast<char *>(&val), sizeof(val));
}


inline QString convertString(QIODevice &data)
{
    const uint8_t size = convert<uint8_t>(data);
    return size == 0 ? "" : QString::fromUtf8(data.read(size));
}

inline void convertString(QIODevice &data, QString &val)
{
    const uint8_t size = convert<uint8_t>(data);
    val = size == 0 ? "" : QString::fromUtf8(data.read(size));
}

inline QString convertString(QIODevice &data, uint8_t size)
{
    return QString::fromUtf8(data.read(size));
}


inline QColor convertColor(QIODevice &data)
{
    return QColor(convert<uint8_t>(data), convert<uint8_t>(data), convert<uint8_t>(data));
}

inline void convert(QIODevice &data, QColor &val)
{
    val.setRgb(convert<uint8_t>(data), convert<uint8_t>(data), convert<uint8_t>(data));
}

}  // namespace Converters


#endif  // __BASIC_CONVERTERS_HPP__
