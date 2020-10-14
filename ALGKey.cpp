#include "ALGKey.h"
#include "Trace.h"
#include "definitions.h"

bool ALGKey::inject(const QString& key)
{
    bool isInjected = false;
    if (key.isNull())
    {
        callMessage("Ключ порожній.");
    }
    else
    {

    }
    return isInjected;
}

bool ALGKey::detach()
{
    return true;
}
