#ifndef ALGCOMPRESSION_H
#define ALGCOMPRESSION_H

#include "IAlgorithm.h"

class ALGCompression : public IAlgorithm
{
    bool inject(const QString& key) override;
    bool detach() override;
};

#endif // ALGCOMPRESSION_H

