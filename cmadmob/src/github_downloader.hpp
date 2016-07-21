//
//  github_downloader.hpp
//  AdExample
//
//  Created by jinlongfei on 16/7/21.
//  Copyright © 2016年 Long Way Studio. All rights reserved.
//

#ifndef github_downloader_hpp
#define github_downloader_hpp

#include "downloader.hpp"

class GithubDownloader: public Downloader {
public:
    virtual std::string getApps(const std::string &publisher);
    virtual std::string downloadImage(const std::string &advertiser, const std::string type, const std::string lang);
    virtual std::string getInfo(const std::string &advertiser, const std::string type, const std::string lang);
private:
    std::string getBaseURL();
};

#endif /* github_downloader_hpp */
