//
//  messengerRESTclient.h
//  socialNetwork-UTD
//
//  Created by Ankit Malhotra on 1/20/13.
//  Copyright (c) 2013 Ankit Malhotra. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "BaseRESTparser.h"
#import "messengerAppDelegate.h"
#import "ChallengeHandler.h"

@class BaseRESTparser; /*use this forward declaration to avoid class parse issues*/
@class ChallengeHandler;
@class messengerAppDelegate;

@interface messengerRESTclient : NSObject<NSURLConnectionDelegate,ChallengeHandlerDelegate>
{
    BaseRESTparser *accessPtr;
    NSMutableData *wipData;
    ChallengeHandler *currentChallenge;
    NSURLConnection *connection;
    NSTimer *earlyTimeoutTimer;
    NSString *serviceEndPoint;
    clock_t startTime;
    clock_t stopTime;
    int statusSignal;
    double elapsedConnDuration;
}


/*User specific endpoints*/
-(void)addNewUser :(NSString *)userID :(NSString *)userName :(NSString *)password :(NSString *)emailID :(NSString *)devToken :(NSString *)endPointURL;
-(void)userLogin :(NSString *)userID :(NSString *)password :(NSString *)endPointURL;

/*Posts related endpoints*/
-(void)createNewPost:(NSString *)userNumber :(NSString *)groupNumber :(NSString *) postMessage : (double)locationLatitude :(double)locationLongitude :(NSString *)accessToken :(NSString *)endPointURL;
-(void)showPostData:(NSString *)userNumber :(NSString *)groupNumber :(double)locationLat :(double)locationLong :(NSString *)accessToken :(NSString *)endPointURL;

/*Group specific endpoints*/
-(void)createGroup:(double)locationLatitude :(double)locationLongitude :(NSString *)groupName :(NSString *)userNumber :(NSString *)groupPwd :(NSString *)accessToken :(NSString *)endPointURL;
-(void)showMyGroups :(NSString *)userNumber :(double)locationLat :(double)locationLong :(NSString *)accessToken :(NSString *)endPointURL;
-(void)showAllGroups:(NSString *)userNumber :(double)locationLat :(double)locationLong :(NSString *)accessToken :(NSString *)endPointURL;
-(void)joinGroup: (NSString *)userNumber :(NSString *)groupNumber :(double)locationLatitude :(double)locationLongitude :(NSString *)groupPassword :(NSString *)accessToken :(NSString *)endPointURL;
-(void)unjoinGroups:(NSString *)userNumber :(NSString *)groupNumber :(NSString *)accessToken :(NSString *)endPointURL;

/*Friend/Chat specific endpoints*/
-(void)getFriendList: (NSString *)userNumber :(NSString *)groupNumber :(double)locationLatitude :(double)locationLongitude :(NSString *)accessToken :(NSString *)endPointURL;
-(void)chatMessage :(NSString *)senderNumber :(NSString *)receiverNumber :(NSString *)chatMessageData :(NSString *)endPointURL;

/*Change user's password endpoint*/
-(void)changeUserPassword :(NSString *)userNumber :(NSString *)userPassword :(NSString *)newPassword :(NSString *)accessToken :(NSString *)endPointURL;

/*Change user's email address endpoint*/
-(void)changeUserEmailAddress :(NSString *)userNumber :(NSString *)userPassword :(NSString *)emailAddress :(NSString *)accessToken :(NSString *)endPointURL;

/*Wipe all user data endpoint*/
-(void)wipeData :(NSString *)userNumber :(NSString *)userPassword :(NSString *)accessToken :(NSString *)endPointURL;

/*User roster from XMPP server*/
-(void)userRoster :(NSString *)userNumber :(NSString *)userName :(NSString *)accessToken :(NSString *)endPointURL;

/*Forgot Password*/
-(void)recoverPassword :(NSString *)userId :(NSString *)emailAddress :(NSString *)endPointURL;

/*Generic local functions*/
-(void)getUserID :(NSString *)userNumber :(NSString *)endPointURL;
-(void)valueToReturn:(int)value;
-(int)returnValue;
-(int)returnStatusSignal;


@end
