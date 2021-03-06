//
//  BARServer.h
//  Barista
//
//  Created by Steve Streza on 4/23/13.
//  Copyright (c) 2013: Steve Streza
//  
//  Permission is hereby granted, free of charge, to any person obtaining a copy of
//  this software and associated documentation files (the "Software"), to deal in
//  the Software without restriction, including without limitation the rights to
//  use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies
//  of the Software, and to permit persons to whom the Software is furnished to do
//  so, subject to the following conditions:
//  
//  The above copyright notice and this permission notice shall be included in all
//  copies or substantial portions of the Software.
//  
//  THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
//  IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
//  FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
//  AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
//  LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
//  OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
//  SOFTWARE.
//

#import <Foundation/Foundation.h>

#import "BARConnection.h"
#import "BaristaTypes.h"
#import "JLRoutes.h"

@interface BARServer : NSObject

+(instancetype)serverWithBoundHost:(NSString *)host port:(uint16_t)port;
+(instancetype)serverWithPort:(uint16_t)port;

@property (nonatomic, readonly, assign) NSString *boundHost;
@property (nonatomic, readonly, assign) uint16_t port;
@property (nonatomic, assign, getter=isListening) BOOL listening;

-(BOOL)startListening;
-(BOOL)stopListening;

#pragma mark Routes

-(void)setupRoutes;

-(void)addRoute:(NSString *)route forHTTPMethod:(NSString *)method handler:(BOOL (^)(BARConnection *connection, BARRequest *request, NSDictionary *parameters))handler;

#pragma mark Middleware

-(void)addGlobalMiddleware:(id<BaristaMiddleware>)middleware;
-(NSArray *)globalMiddleware;

-(void)connection:(BARConnection *)connection didReceiveRequest:(BARRequest *)request;
-(void)connection:(BARConnection *)connection willSendResponse:(BARResponse *)response forRequest:(BARRequest *)request handler:(void (^)(void))handler;

@end
