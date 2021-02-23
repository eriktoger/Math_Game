#ifndef MOCKIMAGEINFO_H
#define MOCKIMAGEINFO_H
#include <gmock/gmock.h>
#include "include/imageInfo.h"
#include "include/urlreader.h"
class MockImageInfo : public ImageInfo
{
public:
    MOCK_METHOD1(setUrlReader, void(UrlReader&));
};
#endif // MOCKIMAGEINFO_H
