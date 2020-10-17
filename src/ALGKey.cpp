#include "ALGKey.h"
#include "Trace.h"
#include "Definitions.h"

#include <opencv2/core.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>

bool ALGKey::inject(const QString& key, const QString& pathToFile)
{
    bool isInjected = false;
    if (key.isEmpty())
    {
        callMessage("Ключ порожній.");
    }
    else
    {
        cv::Mat img = cv::imread(pathToFile.toStdString(), cv::IMREAD_COLOR);
        if (img.empty())
        {
            callMessage("Не можна відкрити зображення!");
        }
        else
        {
            isInjected = true;
        }
    }

    return isInjected;
}

bool ALGKey::detach(const QString& key, const QString& pathToFile)
{
    bool isDetached = false;
    if (key.isEmpty())
    {
        callMessage("Ключ порожній.");
    }
    else
    {
        cv::Mat img = cv::imread(pathToFile.toStdString(), cv::IMREAD_COLOR);
        if (img.empty())
        {
            callMessage("Не можна відкрити зображення!");
        }
        else
        {
            isDetached = true;
        }
    }

    return isDetached;
}
