// Copyright (c) 2013 - 2015 The Sporting Exchange Limited
// All rights reserved.
//
// Redistribution and use in source and binary forms, with or without
// modification, are permitted provided that the following conditions are met:
// 1. Redistributions of source code must retain the above copyright
// notice, this list of conditions and the following disclaimer.
// 2. Redistributions in binary form must reproduce the above copyright
// notice, this list of conditions and the following disclaimer in the
// documentation and/or other materials provided with the distribution.
// 3. All advertising materials mentioning features or use of this software
// must display the following acknowledgement:
// This product includes software developed by The Sporting Exchange Limited.
// 4. Neither the name of The Sporting Exchange Limited nor the
// names of its contributors may be used to endorse or promote products
// derived from this software without specific prior written permission.
//
// THIS SOFTWARE IS PROVIDED BY THE SPORTING EXCHANGE LIMITED ''AS IS'' AND ANY
// EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
// WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
// DISCLAIMED. IN NO EVENT SHALL THE SPORTING EXCHANGE LIMITED BE LIABLE FOR ANY
// DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
// (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
// LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
// ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
// (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
// SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.

#import "BNGAccountDetails.h"

#import "APING.h"
#import "BNGAPIError_Private.h"
#import "BNGMutableURLRequest.h"
#import "NSURLConnection+BNGJSON.h"
#import "BNGAPIResponseParser.h"
#import "NSDictionary+BNGError.h"
#import "NSDictionary+BNGError.h"

@implementation BNGAccountDetails

#pragma mark API Calls

+ (void)getAccountDetailsWithCompletionBlock:(BNGAccountDetailsCompletionBlock)completionBlock
{
    NSParameterAssert(completionBlock);
    
    if (!completionBlock) return;
    
    NSURL *const url = [NSURL betfairNGAccountURLForOperation:BNGAccountOperation.getAccountDetails];
    
    BNGMutableURLRequest *const request = [BNGMutableURLRequest requestWithURL:url];
    
    [NSURLConnection sendAsynchronousJSONRequest:request
                                           queue:[NSOperationQueue mainQueue]
                               completionHandler:^(NSURLResponse *response, id JSONData, NSError *connectionError) {
                                   
                                   if (connectionError)
                                   {
                                       completionBlock(nil, connectionError, [[BNGAPIError alloc] initWithURLResponse:response]);
                                   }
                                   else if ([JSONData isKindOfClass:[NSDictionary class]])
                                   {
                                       NSDictionary *const data = JSONData;
                                       
                                       if ([data isBNGError])
                                       {
                                           completionBlock(nil, nil, [[BNGAPIError alloc] initWithAPINGErrorResponseDictionary:data]);
                                       }
                                       else
                                       {
                                           completionBlock([BNGAPIResponseParser parseBNGAccountDetailsFromResponse:data], connectionError, nil);
                                       }
                                   }
                                   else
                                   {
                                       completionBlock(nil, nil, [[BNGAPIError alloc] initWithDomain:BNGErrorDomain
                                                                                                code:BNGErrorCodeNoData
                                                                                            userInfo:nil]);
                                   }
                               }];
}

#pragma mark Description

- (NSString *)description
{
    return [NSString stringWithFormat:@"%@ BNGAccountDetails [currencyCode: %@] [firstName: %@] [lastName: %@] [localeCode: %@] [region: %@] [discountRate: %@] [pointsBalance: %@]",
            [super description],
            self.currencyCode,
            self.firstName,
            self.lastName,
            self.localeCode,
            self.region,
            self.discountRate,
            @(self.pointsBalance)];
}

@end
