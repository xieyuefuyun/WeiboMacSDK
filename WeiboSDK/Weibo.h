//
//  Weibo.h
//  Weibo
//
//  Created by Wu Tian on 12-2-10.
//  Copyright (c) 2012年 Wutian. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "WeiboConstants.h"

extern NSString * const WeiboAccountSetDidChangeNotification;
extern NSString * const WeiboDidHeartbeatNotification;

@class WeiboAccount, WTCallback;

@interface Weibo : NSObject {
    NSMutableArray * accounts;
    NSTimer *heartbeatTimer;
    NSTimeInterval heartbeatInterval;
    NSTimer *cachePruningTimer;
}

+ (Weibo *)sharedWeibo;
- (void)heartbeat:(id)sender;
- (void)pruneCaches:(id)sender;
- (void)shutdown;
- (NSMutableArray *)accounts;

// Use When Grant Type == Password
- (void)signInWithUsername:(NSString *)aUsername 
                  password:(NSString *)aPassword 
                  callback:(WTCallback *)aCallback;
// Use When Grant Type == Authorization Code 
- (void)signInWithAccessToken:(NSString *)accessToken tokenExpire:(NSTimeInterval)expireTime userID:(WeiboUserID)userID callback:(WTCallback *)aCallback;

- (void)refreshTokenForAccount:(WeiboAccount *)aAccount 
                      password:(NSString *)aPassword 
                      callback:(WTCallback *)aCallback;
- (void)didSignIn:(id)response info:(id)info;
- (void)addAccount:(WeiboAccount *)aAccount;
- (void)removeAccount:(WeiboAccount *)aAccount;
- (BOOL)containsAccount:(WeiboAccount *)aAccount;
- (WeiboAccount *)accountWithUsername:(NSString *)aUsername;
- (WeiboAccount *)accountWithUserID:(WeiboUserID)userID;

- (WeiboAccount *)defaultAccount;
- (void)reorderAccountFromIndex:(NSUInteger)fromIndex toIndex:(NSUInteger)toIndex;
- (void)refresh;
- (BOOL)hasFreshMessages;
- (BOOL)hasFreshAnythingApplicableToStatusItem;
- (BOOL)hasFreshAnythingApplicableToDockBadge;
- (BOOL)hasAnythingUnread;

- (NSInteger)unreadCountForDockBadge;


@end
