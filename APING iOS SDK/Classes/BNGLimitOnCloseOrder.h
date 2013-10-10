// Copyright (c) 2013 The Sporting Exchange Limited
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
// THIS SOFTWARE IS PROVIDED BY <COPYRIGHT HOLDER> ''AS IS'' AND ANY
// EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
// WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
// DISCLAIMED. IN NO EVENT SHALL <COPYRIGHT HOLDER> BE LIABLE FOR ANY
// DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
// (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
// LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
// ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
// (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
// SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.

#import "BNGOrder.h"

#import "BNGDictionaryRepresentation.h"

/**
 * BSP with price order. A client would use this order when they want to place a BSP
 * bet which specifies a minimum price.
 */
@interface BNGLimitOnCloseOrder : BNGOrder <BNGDictionaryRepresentation>

/**
 * The minimum price at which the order should be matched.
 */
@property (nonatomic, strong) NSDecimalNumber *price;

/**
 * The liability which the client wishes to place on the market.
 */
@property (nonatomic, strong) NSDecimalNumber *liability;

/**
 * Initaliser for the class taking 'price' and 'liability' parameters.
 * @param price price for this `BNGLimitOnCloseOrder`.
 * @param liability liability associated with this `BNGLimitOnCloseOrder`
 * @return an instance of `BNGLimitOnCloseOrder`
 */
- (instancetype)initWithPrice:(NSDecimalNumber *)price liability:(NSDecimalNumber *)liability;

@end
