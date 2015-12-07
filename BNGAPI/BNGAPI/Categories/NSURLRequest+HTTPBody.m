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

#import "NSURLRequest+HTTPBody.h"

#import "NSString+URLEncoding.h"

@implementation NSURLRequest (HTTPBody)

- (NSDictionary<NSString *, NSString *> *)httpQueryParams
{
    NSMutableDictionary<NSString *, NSString *> *parameters = [NSMutableDictionary dictionary];
    
    for (NSString *queryItem in [self.URL.query componentsSeparatedByString:@"&"]) {
        
        NSArray<NSString *> *keyValuePair = [queryItem componentsSeparatedByString:@"="];
        
        if (keyValuePair.count == 2) {
            
            NSString *key =     [keyValuePair[0] stringByReplacingPercentEscapesUsingEncoding:NSUTF8StringEncoding];
            NSString *value =   [keyValuePair[1] stringByReplacingPercentEscapesUsingEncoding:NSUTF8StringEncoding];
            
            [parameters setObject:value forKey:key];
        }
    }
    
    return [parameters copy];
}

- (NSDictionary<NSString *, NSString *> *)httpBodyDictionary
{
    NSString *httpBodyString = [[NSString alloc] initWithData:self.HTTPBody encoding:NSUTF8StringEncoding];
    
    NSArray<NSString *> *parts = [httpBodyString componentsSeparatedByString:@"&"];
    NSMutableDictionary<NSString *, NSString *> *bodyDictionary = [[NSMutableDictionary alloc] initWithCapacity:parts.count];
    
    for (NSString *part in parts) {
        NSArray<NSString *> *keyValueArray = [part componentsSeparatedByString:@"="];
        switch (keyValueArray.count) {
            case 1: {
                bodyDictionary[keyValueArray[0]] = @"";
            } break;
            case 2: {
                bodyDictionary[keyValueArray[0]] = keyValueArray[1];
            } break;
            default: break;
        }
    }
    return [bodyDictionary copy];
}

@end

@implementation NSMutableURLRequest (HTTPBody)

- (void)addBodyKey:(NSString *)key value:(NSString *)value
{
    NSParameterAssert(key);
    NSParameterAssert(value);
    
    NSString *httpBodyString = [[NSString alloc] initWithData:self.HTTPBody encoding:NSUTF8StringEncoding];
    NSString *httpBodyToAdd  = [@[key.urlEncodedString, value.urlEncodedString] componentsJoinedByString:@"="];

    if (httpBodyString.length) {
        NSString *httpBodyNew = [@[httpBodyString, httpBodyToAdd] componentsJoinedByString:@"&"];
        self.HTTPBody = [httpBodyNew dataUsingEncoding:NSUTF8StringEncoding];
    } else {
        self.HTTPBody = [httpBodyToAdd dataUsingEncoding:NSUTF8StringEncoding];
    }
}

@end
