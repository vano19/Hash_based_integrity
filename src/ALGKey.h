#ifndef ALGKEY_H
#define ALGKEY_H

#include "IAlgorithm.h"

class ALGKey : public IAlgorithm
{
    bool inject(const QString& key, const QString& pathToFile) override;
    bool detach(const QString& key, const QString& pathToFile) override;
};

#endif // ALGKEY_H
