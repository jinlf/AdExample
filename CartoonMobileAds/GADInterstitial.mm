//
//  GADInterstitial.m
//  AdExample
//
//  Created by jinlongfei on 16/7/21.
//  Copyright © 2016年 Long Way Studio. All rights reserved.
//

#import <CartoonMobileAds/GADInterstitial.h>

#include "firebase/admob.h"
#include "firebase/future.h"

@interface GADInterstitial()

-(void) setIsReady:(BOOL) isReady;

@end

void InitializedCompletionCallback(const ::firebase::Future<void>& result_data, void* user_data) {
//    GADInterstitial *interstitial = (__bridge GADInterstitial *)user_data;
}

void LoadCompletionCallback(const ::firebase::Future<void>& result_data, void* user_data) {
    GADInterstitial *interstitial = (__bridge GADInterstitial *)user_data;
    if (interstitial && interstitial.delegate) {
        if (result_data.Status() == firebase::kFutureStatusComplete) {
            if (result_data.Error() == ::firebase::admob::AdMobError::kAdMobErrorNone) {
                [interstitial setIsReady: YES];
                if ([interstitial.delegate respondsToSelector:@selector(interstitialDidReceiveAd:)]) {
                    [interstitial.delegate interstitialDidReceiveAd: interstitial];
                }
            } else {
                if ([interstitial.delegate respondsToSelector:@selector(interstitial:didFailToReceiveAdWithError:)]) {
                    [interstitial.delegate interstitial:interstitial didFailToReceiveAdWithError:[GADRequestError errorWithDomain:@"CartoonMobileAds" code:result_data.Error() userInfo:nil]];
                }
            }
        } else {
            if ([interstitial.delegate respondsToSelector:@selector(interstitial:didFailToReceiveAdWithError:)]) {
                [interstitial.delegate interstitial:interstitial didFailToReceiveAdWithError:[GADRequestError errorWithDomain:@"CartoonMobileAds" code:firebase::admob::AdMobError::kAdMobErrorInternalError userInfo:nil]];
            }
        }
    }
}

@implementation GADInterstitial {
    ::firebase::admob::InterstitialAd *mAd;
    ::firebase::Future<void> mInitializeFuture;
    ::firebase::Future<void> mLoadFuture;
    ::firebase::Future<void> mShowFuture;
    BOOL mReady;
}

@synthesize isReady = mReady;

-(void) setIsReady: (BOOL) isReady {
    mReady = isReady;
}


-(instancetype) init {
    return [self initWithAdUnitID:@"invalide ad unit id"];
}

- (instancetype)initWithAdUnitID:(NSString *)adUnitID {
    if (self = [super init]) {
        mAd = new ::firebase::admob::InterstitialAd();
        const char *ad_unit_id = adUnitID.UTF8String;
        mInitializeFuture = mAd->Initialize(nullptr, ad_unit_id);
        void *user_data = (__bridge void *)self;
        mInitializeFuture.OnCompletion(InitializedCompletionCallback, user_data);
    }
    return self;
}

- (void)loadRequest:(GADRequest *GAD_NULLABLE_TYPE)request {
    ::firebase::admob::AdRequest req;
    mLoadFuture = mAd->LoadAd(req);
    void *user_data = (__bridge void *)self;
    mLoadFuture.OnCompletion(LoadCompletionCallback, user_data);
}

- (void)presentFromRootViewController:(UIViewController *)rootViewController {
    UIViewController *controller = [[UIViewController alloc] init];
    controller.view.backgroundColor = [UIColor clearColor];
    UIView *alphaView = [[UIView alloc] initWithFrame:controller.view.frame];
    UIView *baseView = [[UIView alloc] initWithFrame:controller.view.frame];
    alphaView.backgroundColor = [UIColor clearColor];
    baseView.backgroundColor = [UIColor blackColor];
    baseView.alpha = 0.7;
    
    UIImage *image = [UIImage imageNamed:@"screen568x568"];
    UIImageView *imageView = [[UIImageView alloc] initWithImage:image];
    imageView.center = controller.view.center;
    [controller.view addSubview:baseView];
    [controller.view addSubview:alphaView];
    [controller.view addSubview:imageView];
    

    controller.modalTransitionStyle = UIModalTransitionStyleCrossDissolve;
    if ([[UIDevice currentDevice].systemVersion floatValue] >= 8.0) {
        controller.providesPresentationContextTransitionStyle = YES;
        controller.definesPresentationContext = YES;
        controller.modalPresentationStyle = UIModalPresentationOverCurrentContext;
        [rootViewController presentViewController:controller animated:YES completion:^{
            dispatch_async(dispatch_get_main_queue(), ^{
                usleep(3 * 1000 * 1000);
                [controller dismissViewControllerAnimated:YES completion:^{
                    
                }];
            });
        }];
    } else {
        rootViewController.view.window.rootViewController.modalPresentationStyle = UIModalPresentationCurrentContext;
        [rootViewController presentViewController:controller animated:NO completion:^{
            dispatch_async(dispatch_get_main_queue(), ^{
                usleep(3 * 1000 * 1000);
                [controller dismissViewControllerAnimated:YES completion:^{
                    
                }];
            });
        }];
        rootViewController.view.window.rootViewController.modalPresentationStyle = UIModalPresentationFullScreen;
    }
}

@end