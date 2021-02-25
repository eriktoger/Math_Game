#ifndef IMAGEINFO_H
#define IMAGEINFO_H

#include <QObject>
#include <QString>
#include <qqml.h>
#include <iostream>
#include <filesystem>
#include <memory>
#include "randomgenerator.h"
#include "urlreader.h"

class ImageInfo : public QObject {
Q_OBJECT
    Q_PROPERTY(bool current READ getCurrent NOTIFY currentChanged)
    Q_PROPERTY(QString url READ getUrl WRITE setUrl NOTIFY urlChanged)
    Q_PROPERTY(bool imageDone READ getImageDone WRITE setImageDone NOTIFY imageDoneChanged)
    QML_ELEMENT
private:
    QString url;
    QVector<bool> shown;
    bool current;
    unsigned index;
    std::vector<std::string> urls;
    unsigned shownCounter;
    bool imageDone;
    std::shared_ptr<UrlReader> urlReaderPtr;
    std::shared_ptr<RandomGenerator> randomGeneratorPtr;


public:
    ImageInfo();

    QString getUrl();

    void setUrl(QString newUrl);

    Q_INVOKABLE unsigned getUrlsSize();

    virtual void setUrlReader(std::shared_ptr<UrlReader> urlReaderPtr);

    void setRandomGenerator(std::shared_ptr<RandomGenerator> rgPtr);

    Q_INVOKABLE std::vector<std::string> getUrls() { return urls; }

    Q_INVOKABLE void setCurrentByIndex(unsigned i);

    bool getCurrent() { return current; }

    QVector<bool> getShown() { return shown; }

    Q_INVOKABLE QString getUrlByIndex(unsigned i);

    bool getImageDone() { return imageDone; }

    void setImageDone(bool newStatus);

    void initializeUrls();


public slots:

    void showMore();

signals:

    QString urlChanged(QString = QString());

    bool currentChanged();

    bool imageDoneChanged();
};

#endif // IMAGEINFO_H
