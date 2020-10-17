#include "ALGCompression.h"
#include "Trace.h"
#include "Definitions.h"

#include <opencv2/core.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>

bool ALGCompression::inject(const QString&, const QString& pathToFile)
{
    bool isInjected = false;
    cv::Mat img = cv::imread(pathToFile.toStdString(), cv::IMREAD_COLOR);
    if (img.empty())
    {
        callMessage("Не можна відкрити зображення!");
    }
    else
    {
        isInjected = true;
    }
    return isInjected;
}

bool ALGCompression::detach(const QString&, const QString& pathToFile)
{
    bool isDetached = false;
    cv::Mat img = cv::imread(pathToFile.toStdString(), cv::IMREAD_COLOR);
    if (img.empty())
    {
        callMessage("Не можна відкрити зображення!");
    }
    else
    {
        isDetached = true;
    }
    return isDetached;
}

/*std::vector<int> params;
params.push_back(CV_IMWRITE_JPEG_QUALITY);
params.push_back(100);   // that's percent, so 100 == no compression, 1 == full
cv::imwrite("my.jpg",image,params);
std::vector<int> params;
params.push_back(CV_IMWRITE_PNG_COMPRESSION);
params.push_back(9);   // that's compression level, 9 == full , 0 == none
cv::imwrite("my.png",image,params);
*/
