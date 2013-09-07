//
//  WeiboReceivedDirectMessageStream.m
//  Weibo
//
//  Created by Wutian on 13-9-4.
//  Copyright (c) 2013年 Wutian. All rights reserved.
//

#import "WeiboReceivedDirectMessageStream.h"
#import "WeiboAPI+DirectMessages.h"
#import "WeiboAccount+Superpower.h"

@implementation WeiboReceivedDirectMessageStream

- (void)_loadNewer
{
    WeiboAPI * api = [self.account authenticatedSuperpowerRequest:[self loadNewerResponseCallback]];
    
    [api directMessagesSinceID:[self newestMessageID] maxID:0 count:200];
}

- (void)_loadOlder
{
    WeiboAPI * api = [self.account authenticatedSuperpowerRequest:[self loaderOlderResponseCallback]];
    
    [api directMessagesSinceID:0 maxID:[self oldestMessageID]-1 count:200];
}

@end
