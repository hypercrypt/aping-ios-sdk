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

#import <Foundation/Foundation.h>

/**
 * Utility category on `NSURLRequest` which makes it easier to add body parameters or query string parameters to a `NSURLRequest`. Used internally for BNG API calls to contact Betfair services.
 */
@interface NSURLRequest (HTTPBody)

/**
 * Returns the current set of body parameters (UTF-8 decoded) in a handy `NSDictionary`
 */
@property (nonatomic, readonly) NSDictionary<NSString *, NSString *> *httpBodyDictionary;

/**
 * Returns the current set of query string parameters (UTF-8 decoded) in a handy `NSDictionary`
 */
@property (nonatomic, readonly) NSDictionary<NSString *, NSString *> *httpQueryParams;

@end

/**
 * Allows for body parameters to be easily added to a `NSMutableURLRequest`.
 */
@interface NSMutableURLRequest (HTTPBody)

/**
 * Adds a parameter to the HTTP POST body.
 * @param key the key which uniquely identifies this parameter in the POST body.
 * @param value the value associated with the key in the POST body.
 */
- (void)addBodyKey:(NSString *)key value:(NSString *)value;

@end
