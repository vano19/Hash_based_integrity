#ifndef IALGORITHM_H
#define IALGORITHM_H

#include <QString>

struct IAlgorithm
{
    virtual bool inject(const QString& key, const QString& pathToFile) = 0;
    virtual bool detach(const QString& key, const QString& pathToFile) = 0;
};

#endif // IALGORITHM_H
