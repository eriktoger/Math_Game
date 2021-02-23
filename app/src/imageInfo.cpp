#include "../include/imageInfo.h"
#include "../include/paths.h"
ImageInfo::ImageInfo():shown(QVector<bool>(9))
{
    shownCounter = 0;
    imageDone = false;
    urlReaderPtr = std::make_shared<UrlReader>();
    randomGeneratorPtr = std::make_shared<RandomGenerator>();
}

void ImageInfo::setUrlReader( std::shared_ptr<UrlReader> urPtr){
    urlReaderPtr = urPtr;
}
void ImageInfo::setRandomGenerator( std::shared_ptr<RandomGenerator> rgPtr){
    randomGeneratorPtr = rgPtr;
}

void ImageInfo::initializeUrls(){
    urlReaderPtr->loadUrls();
    urls = urlReaderPtr->getUrls();
    int upperLimit = urls.size() > 0 ? urls.size() -1 : 0;
    randomGeneratorPtr->setBounderies(0, upperLimit);
    int randomImageIndex = randomGeneratorPtr->randomInt();
    std::cout <<"index: "<<randomImageIndex<<std::endl;
    url = QString::fromStdString(urls[randomImageIndex]);
}

QString ImageInfo::getUrl(){
    return url;
}

unsigned ImageInfo::getUrlsSize(){
    return urls.size();
}

void ImageInfo::newUrl(){

}

void ImageInfo::setIndex(unsigned i){
    index = i;
    if( i > shown.size()){
        return;
    }
    current = shown.at(i);
}


bool ImageInfo::showIndex(unsigned i){
    index = i;
    if( i > shown.size()){
        return false;
    }
    return shown.at(i);
}
void ImageInfo::setCurrentByIndex(unsigned i){

    if( i >= shown.size()){
        return;
    }

    current = shown.at(i);
}


void ImageInfo::showMore(){
    if(shownCounter >= shown.size()){
        //return;
    }

    srand(time(0));
    unsigned i = rand() % shown.size();
    if(shown.at(i)){

        while(true){
            i++;
            if(i == shown.size()){
                i = 0;
            }
            if( !shown.at(i)){
                break;
            }

        }

    }

    shown[i] = true;
    shownCounter++;
    emit currentChanged();
    if(shownCounter > 0 && shownCounter % 9 == 0 ){ // && shownCounter % 9 == 0
        imageDone = true;
        emit imageDoneChanged();
    }

}

void ImageInfo::setUrlByIndex(unsigned i ){
    if( i >= urls.size()){
        return;
    }
    url = QString::fromStdString(urls[i]);
    emit urlChanged();
}
void ImageInfo::setUrl(QString newUrl){
    if(url == newUrl){
        return;
    }
    url = newUrl;
    emit urlChanged();
}


QString ImageInfo::getUrlByIndex(unsigned i ){
    if( i >= urls.size()){
        return QString();
    }
    return QString::fromStdString(urls[i]);
}

void ImageInfo::setImageDone(bool newStatus){
    if(newStatus != imageDone){
        imageDone = newStatus;
        emit imageDoneChanged();
        // set new image
        auto it = find(begin(urls),end(urls), url.toStdString() );
        it++;
        if(it == end(urls)){
            url =  QString::fromStdString(urls[0]);
        }else{
            url = QString::fromStdString(*it);
        }
        std::fill(shown.begin(), shown.end(), false);
        emit currentChanged();
        emit urlChanged();
    }
}
