//
//  GADRequest.m
//  AdExample
//
//  Created by jinlongfei on 16/7/21.
//  Copyright © 2016年 Long Way Studio. All rights reserved.
//

#import <CartoonMobileAds/GADRequest.h>


@implementation GADRequest

- (id)copyWithZone:(nullable NSZone *)zone {
    return self;
}

+ (instancetype)request {
    return [[self alloc]init];
}

+ (NSString *)sdkVersion {
    return @"1.0.0";
}

- (void)setLocationWithLatitude:(CGFloat)latitude
                      longitude:(CGFloat)longitude
                       accuracy:(CGFloat)accuracyInMeters {
    
}

- (void)tagForChildDirectedTreatment:(BOOL)childDirectedTreatment {
    
}

- (void)setBirthdayWithMonth:(NSInteger)month
                         day:(NSInteger)day
                        year:(NSInteger)year {
    
}

- (void)setLocationWithDescription:(NSString *GAD_NULLABLE_TYPE)locationDescription {
    
}

@end