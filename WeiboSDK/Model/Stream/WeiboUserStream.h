//
//  WeiboUserStream.h
//  Weibo
//
//  Created by Wu Tian on 12-2-20.
//  Copyright (c) 2012年 Wutian. All rights reserved.
//

#import "WeiboAccountStream.h"

@class WeiboUser;

@interface WeiboUserStream : WeiboAccountStream

@property (retain,nonatomic) WeiboUser * user;

@end
