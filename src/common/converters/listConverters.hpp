#ifndef __LIST_CONVERTERS_HPP__
#define __LIST_CONVERTERS_HPP__

#include "structConverters.hpp"

#include <QByteArray>
#include <QIODevice>

#include <type_traits>


namespace Converters
{

// to binary converters
template<typename T>
inline QByteArray convert(const QList<T> &container)
{
    QByteArray ret(static_cast<uint16_t>(container.size()), sizeof(uint16_t));
    for (const T &val : container)
        ret += convert<T>(val);

    return ret;
}

// from binary converters
template<typename T>
inline QList<T> convertList(QIODevice &data)
{
    uint16_t size = convert<uint16_t>(data);
    QList<T> ret;
    ret.reserve(size);

    ++size;
    while (--size)
        ret.append(convert<T>(data));

    return ret;
}

template<typename T>
inline void convert(QIODevice &data, QList<T> &container)
{
    container.clear();
    uint16_t size = convert<uint16_t>(data);
    container.reserve(size);

    ++size;
    while (--size)
        container.append(convert<T>(data));
}

}  // namespace Converters


#endif  // __LIST_CONVERTERS_HPP__
