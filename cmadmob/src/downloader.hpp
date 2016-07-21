//
//  downloader.hpp
//  AdExample
//
//  Created by jinlongfei on 16/7/21.
//  Copyright © 2016年 Long Way Studio. All rights reserved.
//

#ifndef downloader_hpp
#define downloader_hpp

#include <string>

class Downloader {
public:
    virtual std::string getApps(const std::string &publisher) = 0;
    virtual std::string downloadImage(const std::string &advertiser, const std::string type, const std::string lang) = 0;
    virtual std::string getInfo(const std::string &advertiser, const std::string type, const std::string lang) = 0;
};

class DownloaderFactory {
public:
    static Downloader *getDownloader(const std::string &name);
};

#endif /* downloader_hpp */
