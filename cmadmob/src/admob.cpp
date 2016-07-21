//
//  admob.cpp
//  AdExample
//
//  Created by jinlongfei on 16/7/21.
//  Copyright © 2016年 Long Way Studio. All rights reserved.
//

#include "firebase/admob.h"

namespace firebase {
    
    /// @brief API for AdMob with Firebase.
    ///
    /// This AdMob API allows you to load and display AdMob banners
    /// (@ref BannerView) and interstitials (@ref InterstitialAd). Each instance of
    /// BannerView or InterstitialAd will create and control a corresponding
    /// platform-specific mobile ad view class.
    namespace admob {
        
        /// Initializes AdMob via Firebase.
        ///
        /// @param app The Firebase app for which to initialize mobile ads.
        void Initialize(const ::firebase::App& app) {
            
        }
        
#ifdef __ANDROID__
        /// Initialize AdMob without Firebase.
        ///
        /// The arguments to @ref Initialize are platform specific so the caller must
        /// do something like this:
        /// @code
        /// #if defined(__ANDROID__)
        /// firebase::admob::Initialize(jni_env, activity);
        /// #else
        /// firebase::admob::Initialize();
        /// #endif
        /// @endcode
        ///
        /// @param[in] jni_env JNIEnv pointer.
        /// @param[in] activity Activity used to start the application.
        void Initialize(JNIEnv* jni_env, jobject activity) {
            
        }
#else
        /// Initialize AdMob without Firebase.
        void Initialize() {
            
        }
#endif  // __ANDROID__
        
        /// @brief Terminate AdMob.
        ///
        /// Frees resources associated with AdMob that were allocated during
        /// @ref firebase::admob::Initialize().
        void Terminate() {
            
        }
        
    }  // namespace admob
}  // namespace firebase