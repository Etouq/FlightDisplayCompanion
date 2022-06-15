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
requires requires(T container)
{
    std::is_integral_v<decltype(container.size())>;
    std::is_same_v<typename T::const_iterator, decltype(container.cbegin())>;
    std::is_same_v<typename T::const_iterator, decltype(container.cend())>;
    requires requires(typename T::value_type a)
    {
        std::is_same_v<QByteArray, decltype(convert(a))>;
    };
}
[[nodiscard]] inline QByteArray convert(const T &container)
{
    QByteArray ret(static_cast<uint16_t>(container.size()), sizeof(uint16_t));
    for (const typename T::value_type &val : container)
        ret += convert(val);

    return ret;
}

// from binary converters
template<typename T>
requires requires(T container, uint16_t size)
{
    container.reserve(size);
    // std::is_same_v<T, QList<typename T::value_type>> || std::is_same_v<T, QVector<typename T::value_type>>;
    requires requires(typename T::value_type a, QIODevice & data)
    {
        convert<typename T::value_type>(data);
        container.append(a);
    };
}
[[nodiscard]] inline T convert(QIODevice &data)
{
    uint16_t size = convert<uint16_t>(data);
    T ret;
    ret.reserve(size);

    ++size;
    while (--size)
        ret.append(convert<typename T::value_type>(data));

    return ret;
}

template<typename T>
requires requires(T container, uint16_t size)
{
    container.reserve(size);
    container.clear();
    // std::is_same_v<T, QList<typename T::value_type>> || std::is_same_v<T, QVector<typename T::value_type>>;
    requires requires(typename T::value_type a, QIODevice & data)
    {
        convert<typename T::value_type>(data);
        container.append(a);
    };
}
inline void convert(QIODevice &data, T &container)
{
    container.clear();
    uint16_t size = convert<uint16_t>(data);
    container.reserve(size);

    ++size;
    while (--size)
        container.append(convert<typename T::value_type>(data));
}

}  // namespace Converters


#endif  // __LIST_CONVERTERS_HPP__