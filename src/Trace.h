#ifndef TRACE_H
#define TRACE_H

#include "QDebug"
#include "QString"
#include "QVariant"
#include "QStringRef"

template < typename T>
QString print(const T& value)
{
    return QVariant{value}.toString();
}

template <typename... Args>
QString print(const QString& file, const QString& function, Args... args)
{
    const int indexEnd = file.indexOf(".cpp");
    const int indexStart = file.lastIndexOf("\\") + 1; // +1 - next item

    const QStringRef nameClass{&file, indexStart, indexEnd - indexStart};
    return nameClass.toString() + ": " + function + ": " + print(std::forward<Args>(args)...);
}

#define FF\
    __FILE__, __FUNCTION__

#define LOG_INF(...)\
    qInfo() << print(FF, __VA_ARGS__)

#endif // TRACE_H
