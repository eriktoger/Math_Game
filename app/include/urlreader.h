#ifndef URLREADER_H
#define URLREADER_H
#include <string>
#include <vector>
#include <filesystem>
class UrlReader
{
private:
std::vector<std::string> urls;
public:
    UrlReader();
    virtual void loadUrls();
    virtual std::vector<std::string> getUrls(){return urls;}
};

#endif // URLREADER_H
