#ifndef ALGCOMPRESSION_H
#define ALGCOMPRESSION_H

#include "IAlgorithm.h"

class ALGCompression : public IAlgorithm
{
    bool inject(const QString& key, const QString& pathToFile) override;
    bool detach(const QString& key, const QString& pathToFile) override;
};

#endif // ALGCOMPRESSION_H

