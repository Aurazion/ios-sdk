//
//  LockConfiguration.h
//  FuturaeKit
//
//  Created by Armend Hasani on 12.5.22.
//  Copyright © 2022 Futurae. All rights reserved.
//

#import <Foundation/Foundation.h>
@import LocalAuthentication;

NS_ASSUME_NONNULL_BEGIN

typedef NS_ENUM(NSInteger, LockConfigurationType){
    LockConfigurationTypeNone = 1,
    LockConfigurationTypeBiometricsOnly = 2,
    LockConfigurationTypeBiometricsOrPasscode = 3,
    LockConfigurationTypeSDKPinWithBiometricsOptional = 4
};

typedef NS_ENUM(NSInteger, UnlockMethodType) {
    UnlockMethodTypeBiometric = 1,
    UnlockMethodTypeBiometricsOrPasscode = 2,
    UnlockMethodTypeSDKPin = 3,
    UnlockMethodTypeNone = 4,
};

typedef NS_ENUM(NSInteger, FTRLockError){
    FTRLockErrorOperationIsLocked = 1,
    FTRLockErrorInvalidConfiguration = 2,
    FTRLockErrorInvalidOperation = 3,
    FTRLockErrorAuthenticationFailed = 4,
    FTRLockErrorIncorrectSDKPin = 5,
    FTRLockErrorMechanismUnavailable = 6,
    FTRLockErrorBiometricsInvalidated = 7,
    FTRLockErrorIllegalArgument = 8,
    FTRLockErrorUnexpected = 9,
    FTRLockConnectionError = 10,
    FTRLockErrorIncorrectPinArchivedDevice = 11
};

typedef void (^FTRLockHandler)(NSError * _Nullable error);


@interface LockConfiguration : NSObject

@property (nonatomic) LockConfigurationType type;
@property (nonatomic) NSTimeInterval unlockDuration;
@property (nonatomic) BOOL invalidatedByBiometricsChange;

-(instancetype)initWithType:(LockConfigurationType)type;

-(instancetype)initWithType:(LockConfigurationType)type
unlockDuration: (NSTimeInterval)unlockDuration;

-(instancetype)initWithType:(LockConfigurationType)type
unlockDuration: (NSTimeInterval)unlockDuration
invalidatedByBiometricsChange: (BOOL)invalidatedByBiometricsChange;

+(void)set:(LockConfiguration *)config;
+(LockConfiguration * _Nullable)get;

+(SecAccessControlRef _Nullable)accessControl;
+(SecAccessControlRef _Nullable)accessControlWithPrivateKeyUsage;
-(BOOL)hasKeyProtection;
-(LAPolicy)laPolicy;

@end

NS_ASSUME_NONNULL_END
