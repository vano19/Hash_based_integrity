#ifndef IALGORITHM_H
#define IALGORITHM_H

#include <QString>

struct IAlgorithm
{
    virtual bool inject(const QString& key) = 0;
    virtual bool detach() = 0;
};

#endif // IALGORITHM_H
