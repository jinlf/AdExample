//
//  github_downloader.cpp
//  AdExample
//
//  Created by jinlongfei on 16/7/21.
//  Copyright © 2016年 Long Way Studio. All rights reserved.
//

#include <strstream>
#include "github_downloader.hpp"
#include "curl/curl.h"

using namespace std;

size_t write_data(void *ptr, size_t size, size_t nmemb, void *stream)
{
    string *output = (string *)stream;
    output->append((char*)ptr, size * nmemb);
    return (size * nmemb);
}


std::string GithubDownloader::getApps(const std::string &publisher) {
    strstream ss;
    ss << getBaseURL() << "/publisher/" << publisher << "/ads.json";
    
    string output;
    CURL *curl = curl_easy_init();
    if(curl) {
        CURLcode res;
        curl_easy_setopt(curl, CURLOPT_URL, ss.str());
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, write_data);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, &output);
        res = curl_easy_perform(curl);
        curl_easy_cleanup(curl);
        if (res != CURLE_OK) {
            throw res;
        }
    }
    return output;
}

std::string GithubDownloader::downloadImage(const std::string &advertiser, const std::string type, const std::string lang) {
    string info = getInfo(advertiser, type, lang);
    return info;    //TODO
}

std::string GithubDownloader::getInfo(const std::string &advertiser, const std::string type, const std::string lang) {
    strstream ss;
    ss << getBaseURL() << "/advertiser/" << advertiser << "/" << type << "/" << lang << "/info.json";
    
    string output;
    CURL *curl = curl_easy_init();
    if(curl) {
        CURLcode res;
        curl_easy_setopt(curl, CURLOPT_URL, ss.str());
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, write_data);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, &output);
        res = curl_easy_perform(curl);
        curl_easy_cleanup(curl);
        if (res != CURLE_OK) {
            throw res;
        }
    }
    return output;
}

std::string GithubDownloader::getBaseURL() {
    return "https://api.github.com/repos/jinlf/revresda";
}