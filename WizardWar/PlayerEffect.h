//
//  Effect.h
//  WizardWar
//
//  Created by Sean Hess on 6/11/13.
//  Copyright (c) 2013 The LAB. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "Simulated.h"

// NOTE: effects are GLOBAL, don't store any state on them. See Wizard.effect and Wizard.effectStartTick

#define EFFECT_INDEFINITE 0

@class Wizard;
@class Spell;

@interface PlayerEffect : NSObject
@property (nonatomic) BOOL disablesPlayer;
@property (nonatomic) BOOL cancelsOnCast;
@property (nonatomic) BOOL cancelsOnHit;
@property (nonatomic) NSTimeInterval delay; // how long it takes to activate
@property (nonatomic) NSTimeInterval duration; // how long before it wears off?
@property (nonatomic, strong) NSString * description;

-(NSComparisonResult)compare:(PlayerEffect*)effect;
-(void)start:(NSInteger)tick player:(Wizard*)player;
-(void)cancel:(Wizard*)player;
-(void)activateEffect:(Wizard*)wizard;
-(BOOL)applySpell:(Spell*)spell onWizard:(Wizard*)wizard currentTick:(NSInteger)currentTick;
-(BOOL)interceptSpell:(Spell*)spell onWizard:(Wizard*)wizard interval:(NSTimeInterval)interval currentTick:(NSInteger)currentTick;
-(void)simulateTick:(NSInteger)currentTick interval:(NSTimeInterval)interval player:(Wizard*)player;

@end