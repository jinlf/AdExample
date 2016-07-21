//
//  downloader.cpp
//  AdExample
//
//  Created by jinlongfei on 16/7/21.
//  Copyright © 2016年 Long Way Studio. All rights reserved.
//

#include "downloader.hpp"
#include "github_downloader.hpp"

static Downloader *getDownloader(const std::string &name) {
    if (name == "github") {
        return new GithubDownloader();
    }
    return nullptr;
}
