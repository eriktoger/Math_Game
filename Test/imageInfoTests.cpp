#include <gtest/gtest.h>
#include <QTest>
#include <QSignalSpy>
#include "include/imageInfo.h"
#include "MockImageInfo.h"
#include "MockRandomGenerator.h"
using namespace testing;

class ImageInfoSetup : public ::testing::Test {
public:
    ImageInfo imageInfo;

    std::vector<std::string> correctUrls{"path1", "path2"};

    virtual void SetUp() {
        imageInfo.addUrl(correctUrls.at(0));
        imageInfo.addUrl(correctUrls.at(1));
    }

};

TEST(ImageInfo, test_constructor) {
    ImageInfo imageInfo;
    EXPECT_FALSE(imageInfo.getImageDone());
    EXPECT_EQ(imageInfo.getShown().size(), 9);

}

TEST(ImageInfo, test_get_setUrl) {

    ImageInfo imageInfo;
    QString url("url");

    imageInfo.setUrl(url);
    EXPECT_EQ(imageInfo.getUrl(), url);

}

TEST(ImageInfo, setUrl_should_not_emit_urlChanged) {
    StrictMock<MockImageInfo> imageInfo;
    QString url("");
    imageInfo.setUrl(url);
}

TEST_F(ImageInfoSetup, test_add_url) {
    EXPECT_EQ(imageInfo.getUrlsSize(), 2);
    auto urls = imageInfo.getUrls();
    EXPECT_EQ(urls.at(0), correctUrls.at(0));
    EXPECT_EQ(urls.at(1), correctUrls.at(1));
}

TEST_F(ImageInfoSetup, test_initializeUrls_setting_url) {
    auto mockRandomGeneratorPtr = std::make_shared<MockRandomGenerator>();
    EXPECT_CALL(*mockRandomGeneratorPtr, randomInt()).WillOnce(Return(1));
    imageInfo.setRandomGenerator(mockRandomGeneratorPtr);
    imageInfo.setRandomUrl();

    auto url = imageInfo.getUrl().toStdString();
    EXPECT_EQ(url, correctUrls.at(1));
}

TEST(ImageInfo, test_showMore_set_shown) {
    ImageInfo imageInfo;
    auto mockRandomGeneratorPtr = std::make_shared<MockRandomGenerator>();
    EXPECT_CALL(*mockRandomGeneratorPtr, randomInt()).WillOnce(Return(1));
    imageInfo.setRandomGenerator(mockRandomGeneratorPtr);
    imageInfo.showMore();

    imageInfo.setCurrentByIndex(1);
    auto shown = imageInfo.getCurrent();
    EXPECT_TRUE(shown);
}

TEST(ImageInfo, test_showMore_set_shown_wrap_around) {
    ImageInfo imageInfo;
    auto mockRandomGeneratorPtr = std::make_shared<MockRandomGenerator>();
    EXPECT_CALL(*mockRandomGeneratorPtr, randomInt()).WillRepeatedly(Return(8));
    imageInfo.setRandomGenerator(mockRandomGeneratorPtr);
    imageInfo.showMore();
    imageInfo.showMore();

    imageInfo.setCurrentByIndex(8);
    auto shownLast = imageInfo.getCurrent();
    imageInfo.setCurrentByIndex(0);
    auto shownFirst = imageInfo.getCurrent();
    EXPECT_TRUE(shownLast);
    EXPECT_TRUE(shownFirst);
}

TEST(ImageInfo, test_emit_urlChanged) {

    ImageInfo imageInfo;
    QSignalSpy spy(&imageInfo, SIGNAL(urlChanged(QString)));
    QString url("url");
    imageInfo.setUrl(url);

    EXPECT_EQ(spy.count(), 1);
    QList<QVariant> arguments = spy.takeFirst();
    EXPECT_EQ(arguments.at(0), QString());

}

TEST(ImageInfo, test_not_emit_urlChanged) {

    ImageInfo imageInfo;
    QSignalSpy spy(&imageInfo, SIGNAL(urlChanged(QString)));
    QString url("");
    imageInfo.setUrl(url);

    EXPECT_EQ(spy.count(), 0);
}


TEST_F(ImageInfoSetup, test_set_ImageDone) {
    //maybe make another class with randomGenerator as well?
    auto mockRandomGeneratorPtr = std::make_shared<MockRandomGenerator>();
    EXPECT_CALL(*mockRandomGeneratorPtr, randomInt()).WillOnce(Return(1));
    imageInfo.setRandomGenerator(mockRandomGeneratorPtr);
    imageInfo.setRandomUrl();

    QSignalSpy spy1(&imageInfo, SIGNAL(currentChanged()));
    QSignalSpy spy2(&imageInfo, SIGNAL(imageDoneChanged()));
    imageInfo.setImageDone(true);
    EXPECT_EQ(imageInfo.getUrl().toStdString(),correctUrls.at(0));
    EXPECT_EQ(spy1.count(), 1);
    EXPECT_EQ(spy2.count(), 1);
}

