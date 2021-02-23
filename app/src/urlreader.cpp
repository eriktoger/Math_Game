#include "../include/urlreader.h"
#include "../include/paths.h"
UrlReader::UrlReader()
{

}

void UrlReader::loadUrls()
{
    int baseLength = QML_PREFIX.size();
    for (const auto & entry : std::filesystem::directory_iterator(QUIZ_IMAGE_PATH)){
        std::string filePath = entry.path();
        urls.emplace_back(filePath.substr(baseLength));
    }

}
