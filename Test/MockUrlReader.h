#ifndef MOCKURLREADER_H
#define MOCKURLREADER_H
#include <gmock/gmock.h>
#include "include/urlreader.h"
class MockUrlReader : public UrlReader
{
public:
    MOCK_METHOD0(getUrls, std::vector<std::string>());
    MOCK_METHOD0(loadUrls, void());
};
#endif // MOCKURLREADER_H
