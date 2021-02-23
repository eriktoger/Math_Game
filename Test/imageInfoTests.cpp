#include <gtest/gtest.h>
#include "include/imageInfo.h"
#include "MockImageInfo.h"
#include "MockUrlReader.h"
using namespace testing;

class ImageInfoSetup : public ::testing::Test
{
public:
  ImageInfo imageInfo;
  std::shared_ptr<MockUrlReader> mockUrlReaderPtr;
  std::vector<std::string> correctUrls{"path1","path2"};

  virtual void SetUp()
  {

     mockUrlReaderPtr = std::make_shared<MockUrlReader>();
     imageInfo.setUrlReader(mockUrlReaderPtr);
     EXPECT_CALL(*mockUrlReaderPtr,getUrls()).WillOnce(Return(correctUrls));
     EXPECT_CALL(*mockUrlReaderPtr,loadUrls());

     imageInfo.setUrlReader(mockUrlReaderPtr);
   }

};



TEST(ImageInfo,test_constructor){

}

TEST_F(ImageInfoSetup, test_using_url_reader)
{
    imageInfo.initializeUrls();

    EXPECT_EQ(imageInfo.getUrlsSize(), 2);
    auto urls = imageInfo.getUrls();
    EXPECT_EQ(urls.at(0), correctUrls.at(0));
    EXPECT_EQ(urls.at(1), correctUrls.at(1));
}

