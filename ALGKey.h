#ifndef ALGKEY_H
#define ALGKEY_H

#include "IAlgorithm.h"

class ALGKey : public IAlgorithm
{
    bool inject(const QString& key) override;
    bool detach() override;
};

#endif // ALGKEY_H
