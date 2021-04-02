#include "../include/imageInfo.h"
#include "../include/paths.h"

ImageInfo::ImageInfo() : shown(QVector<bool>(9)) {
    shownCounter = 0;
    imageDone = false;
    randomGeneratorPtr = std::make_shared<RandomGenerator>();
}

void ImageInfo::setRandomGenerator(std::shared_ptr<RandomGenerator> rgPtr) {
    randomGeneratorPtr = rgPtr;
}

void ImageInfo::addUrl( std::string newUrl) {
    urls.emplace_back(newUrl);
}

void ImageInfo::setRandomUrl(){
    int upperLimit = urls.size() > 0 ? urls.size() - 1 : 0;
    randomGeneratorPtr->setBounderies(0, upperLimit);
    int randomImageIndex = randomGeneratorPtr->randomInt();
    url = QString::fromStdString(urls[randomImageIndex]);
}

QString ImageInfo::getUrl() {
    return url;
}

unsigned ImageInfo::getUrlsSize() {
    return urls.size();
}

void ImageInfo::setCurrentByIndex(unsigned i) {

    if (i >= shown.size()) {
        return;
    }
    if(shown.at(i) == current){
        return;
    }
    current = shown.at(i);
}


void ImageInfo::showMore() {
    if (shownCounter >= shown.size()) {
        return;
    }

    randomGeneratorPtr->setBounderies(0, shown.size() - 1);
    unsigned i = randomGeneratorPtr->randomInt();
    if (shown.at(i)) {
        while (true) {
            i++;
            i %= shown.size();
            if (!shown.at(i)) {
                break;
            }
        }
    }

    shown[i] = true;
    shownCounter++;
    emit currentChanged();
    if (shownCounter > 0 && shownCounter % 9 == 0) { // && shownCounter % 9 == 0
        imageDone = true;
        emit imageDoneChanged();
    }

}

void ImageInfo::setUrl(QString newUrl) {
    if (url == newUrl) {
        return;
    }
    url = newUrl;
    emit urlChanged();
}


QString ImageInfo::getUrlByIndex(unsigned i) {
    if (i >= urls.size()) {
        return QString();
    }
    return QString::fromStdString(urls[i]);
}

void ImageInfo::setImageDone(bool newStatus) {
    if (newStatus != imageDone) {
        imageDone = newStatus;
        emit imageDoneChanged();
        // set new image
        auto it = find(begin(urls), end(urls), url.toStdString());
        it++;
        if (it == end(urls)) {
            url = QString::fromStdString(urls[0]);
        } else {
            url = QString::fromStdString(*it);
        }
        std::fill(shown.begin(), shown.end(), false);
        emit currentChanged();
        emit urlChanged();
    }
}
