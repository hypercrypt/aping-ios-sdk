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

@import Foundation;

#import "APING.h"

#import "BNGAccount.h"
#import "BNGAccountDetails.h"
#import "BNGAccountFunds.h"
#import "BNGAPIError.h"
#import "BNGAPIError_Private.h"
#import "BNGAPIResponseParser.h"
#import "BNGCancelExecutionReport.h"
#import "BNGCancelInstruction.h"
#import "BNGCancelInstructionReport.h"
#import "BNGCompetition.h"
#import "BNGCompetitionResult.h"
#import "BNGCountryCode.h"
#import "BNGCountryCodeResult.h"
#import "BNGCurrentOrderSummaryReport.h"
#import "BNGEvent.h"
#import "BNGEventResult.h"
#import "BNGEventType.h"
#import "BNGEventTypeResult.h"
#import "BNGExBestOffersOverrides.h"
#import "BNGExchangePrices.h"
#import "BNGExecutionReport.h"
#import "BNGHeartbeat.h"
#import "BNGHeartbeatReport.h"
#import "BNGInstructionReport.h"
#import "BNGLimitOnCloseOrder.h"
#import "BNGLimitOrder.h"
#import "BNGLoginURLProtocol.h"
#import "BNGMarketBook.h"
#import "BNGMarketCatalogue.h"
#import "BNGMarketCatalogueDescription.h"
#import "BNGMarketCatalogueFilter.h"
#import "BNGMarketFilter.h"
#import "BNGMarketOnCloseOrder.h"
#import "BNGMarketProfitAndLoss.h"
#import "BNGMatch.h"
#import "BNGMutableURLRequest.h"
#import "BNGOrder.h"
#import "BNGPlaceExecutionReport.h"
#import "BNGPlaceInstruction.h"
#import "BNGPlaceInstructionReport.h"
#import "BNGPriceProjection.h"
#import "BNGPriceSize.h"
#import "BNGReplaceExecutionReport.h"
#import "BNGReplaceInstruction.h"
#import "BNGReplaceInstructionReport.h"
#import "BNGRunner.h"
#import "BNGRunnerProfitAndLoss.h"
#import "BNGStartingPrices.h"
#import "BNGTimeRange.h"
#import "BNGUpdateExecutionReport.h"
#import "BNGUpdateInstruction.h"
#import "BNGUpdateInstructionReport.h"
#import "BNGVenue.h"
#import "BNGVenueResult.h"

#import "NSDictionary+BNGError.h"
#import "NSNumber+DecimalConversion.h"
#import "NSString+RandomCustomerReferenceId.h"
#import "NSString+URLEncoding.h"
#import "NSURL+BNG.h"
#import "NSURLConnection+BNGJSON.h"
#import "NSURLRequest+HTTPBody.h"

/**
 * Import this file via `#import <BNGAPI/BNGAPI.h>` to start accessing Betfair's services. This import is just a convenience header so you don't have to clutter up your .h files with a bunch of imports.
 */
@interface BNGAPI : NSObject

@end
