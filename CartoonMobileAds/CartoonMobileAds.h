//
//  CartoonMobileAds.h
//  Cartoon Mobile Ads SDK
//
//  Copyright 2014 Cartoon Inc. All rights reserved.

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

#if __IPHONE_OS_VERSION_MIN_REQUIRED < __IPHONE_6_0
#error The Cartoon Mobile Ads SDK requires a deployment target of iOS 6.0 or later.
#endif

//! Project version string for CartoonMobileAds.
FOUNDATION_EXPORT const unsigned char CartoonMobileAdsVersionString[];

// Header files.
#import <CartoonMobileAds/CartoonMobileAdsDefines.h>

#import <CartoonMobileAds/GADAdDelegate.h>
//#import <CartoonMobileAds/GADAdNetworkExtras.h>
//#import <CartoonMobileAds/GADAdSize.h>
//#import <CartoonMobileAds/GADBannerView.h>
//#import <CartoonMobileAds/GADBannerViewDelegate.h>
//#import <CartoonMobileAds/GADCorrelator.h>
//#import <CartoonMobileAds/GADCorrelatorAdLoaderOptions.h>
//#import <CartoonMobileAds/GADExtras.h>
//#import <CartoonMobileAds/GADInAppPurchase.h>
//#import <CartoonMobileAds/GADInAppPurchaseDelegate.h>
#import <CartoonMobileAds/GADInterstitial.h>
#import <CartoonMobileAds/GADInterstitialDelegate.h>
//#import <CartoonMobileAds/GADMobileAds.h>
//#import <CartoonMobileAds/GADNativeExpressAdView.h>
//#import <CartoonMobileAds/GADNativeExpressAdViewDelegate.h>
#import <CartoonMobileAds/GADRequest.h>
#import <CartoonMobileAds/GADRequestError.h>
//#import <CartoonMobileAds/GADVideoController.h>
//#import <CartoonMobileAds/GADVideoControllerDelegate.h>
//#import <CartoonMobileAds/GADVideoOptions.h>
//
//#import <CartoonMobileAds/DFPBannerView.h>
//#import <CartoonMobileAds/DFPCustomRenderedAd.h>
//#import <CartoonMobileAds/DFPCustomRenderedBannerViewDelegate.h>
//#import <CartoonMobileAds/DFPCustomRenderedInterstitialDelegate.h>
//#import <CartoonMobileAds/DFPInterstitial.h>
//#import <CartoonMobileAds/DFPRequest.h>
//#import <CartoonMobileAds/GADAdSizeDelegate.h>
//#import <CartoonMobileAds/GADAppEventDelegate.h>
//
//#import <CartoonMobileAds/GADAdLoader.h>
//#import <CartoonMobileAds/GADAdLoaderAdTypes.h>
//#import <CartoonMobileAds/GADAdLoaderDelegate.h>
//
//#import <CartoonMobileAds/GADNativeAd.h>
//#import <CartoonMobileAds/GADNativeAdDelegate.h>
//#import <CartoonMobileAds/GADNativeAdImage.h>
//#import <CartoonMobileAds/GADNativeAdImage+Mediation.h>
//#import <CartoonMobileAds/GADNativeAppInstallAd.h>
//#import <CartoonMobileAds/GADNativeContentAd.h>
//#import <CartoonMobileAds/GADNativeCustomTemplateAd.h>
//
//#import <CartoonMobileAds/GADNativeAdImageAdLoaderOptions.h>
//
//#import <CartoonMobileAds/GADCustomEventBanner.h>
//#import <CartoonMobileAds/GADCustomEventBannerDelegate.h>
//#import <CartoonMobileAds/GADCustomEventExtras.h>
//#import <CartoonMobileAds/GADCustomEventInterstitial.h>
//#import <CartoonMobileAds/GADCustomEventInterstitialDelegate.h>
//#import <CartoonMobileAds/GADCustomEventNativeAd.h>
//#import <CartoonMobileAds/GADCustomEventNativeAdDelegate.h>
//#import <CartoonMobileAds/GADCustomEventParameters.h>
//#import <CartoonMobileAds/GADCustomEventRequest.h>
//#import <CartoonMobileAds/GADMediatedNativeAd.h>
//#import <CartoonMobileAds/GADMediatedNativeAdDelegate.h>
//#import <CartoonMobileAds/GADMediatedNativeAdNotificationSource.h>
//#import <CartoonMobileAds/GADMediatedNativeAppInstallAd.h>
//#import <CartoonMobileAds/GADMediatedNativeContentAd.h>
//
//#import <CartoonMobileAds/GADDynamicHeightSearchRequest.h>
//#import <CartoonMobileAds/GADSearchBannerView.h>
//#import <CartoonMobileAds/GADSearchRequest.h>
//
//#import <CartoonMobileAds/GADAdReward.h>
//#import <CartoonMobileAds/GADRewardBasedVideoAd.h>
//#import <CartoonMobileAds/GADRewardBasedVideoAdDelegate.h>
