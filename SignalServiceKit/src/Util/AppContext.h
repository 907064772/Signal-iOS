//
//  Copyright (c) 2017 Open Whisper Systems. All rights reserved.
//

NS_ASSUME_NONNULL_BEGIN

typedef void (^BackgroundTaskExpirationHandler)(void);

@class OWSDatabaseMigration;

@protocol AppContext <NSObject>

- (BOOL)isMainApp;
- (BOOL)isMainAppAndActive;

// Should only be called if isMainApp is YES.
//
// In general, isMainAppAndActive will probably yield more readable code.
- (UIApplicationState)mainApplicationState;

// Should start a background task if isMainApp is YES.
// Should just return UIBackgroundTaskInvalid if isMainApp is NO.
- (UIBackgroundTaskIdentifier)beginBackgroundTaskWithExpirationHandler:
    (BackgroundTaskExpirationHandler)expirationHandler;
// Should be a NOOP if isMainApp is NO.
- (void)endBackgroundTask:(UIBackgroundTaskIdentifier)backgroundTaskIdentifier;

// Should only be called if isMainApp is YES.
- (void)setMainAppBadgeNumber:(NSInteger)value;

- (BOOL)isRTL;

- (NSArray<OWSDatabaseMigration *> *)allMigrations;

// Returns the VC that should be used to present alerts, modals, etc.
- (nullable UIViewController *)frontmostViewController;

// Should only be called if isMainApp is YES.
- (void)openSystemSettings;

@end

id<AppContext> CurrentAppContext(void);
void SetCurrentAppContext(id<AppContext> appContext);

NS_ASSUME_NONNULL_END
