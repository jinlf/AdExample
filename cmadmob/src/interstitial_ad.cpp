//
//  interstitial_ad.cpp
//  AdExample
//
//  Created by jinlongfei on 16/7/21.
//  Copyright © 2016年 Long Way Studio. All rights reserved.
//

#include <unistd.h>
#include <string>
#include <vector>

#include "firebase/admob/interstitial_ad.h"
#include "future_detail.hpp"
#include "curl/curl.h"


namespace firebase {
    namespace admob {
        struct InterstitialAdData {
            InterstitialAd::PresentationState presentationState;
            AdParent parent;
            std::string ad_unit_id;
            InterstitialAd::Listener* listener;
            
            std::vector<Future<void> *> initializeFutures;
            std::vector<Future<void> *> loadFutures;
            std::vector<Future<void> *> showFutures;
        };
        
        InterstitialAd::InterstitialAd() {
            data_ = new InterstitialAdData();
        }
            
        InterstitialAd::~InterstitialAd() {
            if (data_) {
                delete data_;
            }
        }
        
        void initialize_func(InterstitialAd *ad, AdParent parent, const char *ad_unit_id, Future<void> *future, FutureObject *obj) {
            obj->futureStatus = kFutureStatusPending;
            obj->futureError = kAdMobErrorNone;
            obj->futureResult = nullptr;
            
            CURL *curl = curl_easy_init();
            if(curl) {
                CURLcode res;
                curl_easy_setopt(curl, CURLOPT_URL, "http://www.baidu.com");
                res = curl_easy_perform(curl);
                usleep(3 * 1000 * 1000);
                obj->futureStatus = kFutureStatusComplete;
                if (res != CURLE_OK) {
                    obj->futureError = kAdMobErrorNetworkError;
                }
                obj->callback(*future, obj->user_data);
                curl_easy_cleanup(curl);
            }
        }
        
        void load_func(InterstitialAd *ad, AdParent parent, const char *ad_unit_id, Future<void> *future, FutureObject *obj) {
            obj->futureStatus = kFutureStatusPending;
            obj->futureError = kAdMobErrorNone;
            obj->futureResult = nullptr;
            
            CURL *curl = curl_easy_init();
            if(curl) {
                CURLcode res;
                curl_easy_setopt(curl, CURLOPT_URL, "http://www.baidu.com");
                res = curl_easy_perform(curl);
                usleep(3 * 1000 * 1000);
                obj->futureStatus = kFutureStatusComplete;
                if (res != CURLE_OK) {
                    obj->futureError = kAdMobErrorNetworkError;
                }
                obj->callback(*future, obj->user_data);
                curl_easy_cleanup(curl);
            }
        }
        
        Future<void> InterstitialAd::Initialize(AdParent parent, const char* ad_unit_id) {
            data_->parent = parent;
            data_->ad_unit_id = ad_unit_id;
            
            FutureDetail *detail = new FutureDetail();
            FutureObject *obj = new FutureObject();
            Future<void> *future = new Future<void>(detail, (FutureHandle)obj);
            data_->initializeFutures.push_back(future);
            obj->future = std::async(initialize_func, this, parent, ad_unit_id, future, obj);
            return *future;
        }
            
            /// Returns a @ref Future containing the status of the last call to
            /// @ref Initialize.
        Future<void> InterstitialAd::InitializeLastResult() const {
            return Future<void>();
        }
            
            /// Begins an asynchronous request for an ad. The
            /// @ref InterstitialAd::GetPresentationState method can be used to track the
            /// progress of the request.
            /// @param[in] request An AdRequest struct with information about the request
            ///                    to be made (such as targeting info).
        Future<void> InterstitialAd::LoadAd(AdRequest request) {
            FutureDetail *detail = new FutureDetail();
            FutureObject *obj = new FutureObject();
            FutureHandle handler = (FutureHandle)obj;
            Future<void> *future = new Future<void>(detail, handler);
            data_->loadFutures.push_back(future);
            obj->future = std::async(load_func, this, data_->parent, data_->ad_unit_id.c_str(), future, obj);
            return *future;
        }
            
            /// Returns a @ref Future containing the status of the last call to
            /// @ref LoadAd.
        Future<void> InterstitialAd::LoadAdLastResult() const {
            return Future<void>();
        }
            
            /// Shows the @ref InterstitialAd. This should not be called unless an ad has
            /// already been loaded.
        Future<void> InterstitialAd::Show() {
            return Future<void>();
        }
            
            /// Returns a @ref Future containing the status of the last call to @ref Show.
        Future<void> InterstitialAd::ShowLastResult() const {
            return Future<void>();
        }
            
            /// Returns the current presentation state of the @ref InterstitialAd.
            ///
            /// @return The current presentation state.
        InterstitialAd::PresentationState InterstitialAd::GetPresentationState() const {
            return data_->presentationState;
        }
            
            /// Sets the @ref Listener for this @ref InterstitialAd.
            /// @param[in] listener A valid InterstititalAd::Listener to receive
            ///                     callbacks.
        void InterstitialAd::SetListener(Listener* listener) {
            data_->listener = listener;
        }
    }  // namespace admob
}  // namespace firebase