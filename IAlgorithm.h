#ifndef IALGORITHM_H
#define IALGORITHM_H

#include <QString>

struct IAlgorithm
{
    virtual bool inject(const QString& key);
    virtual bool detach();
};

#endif // IALGORITHM_H
