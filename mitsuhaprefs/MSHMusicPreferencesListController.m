//
//  MSHMusicPreferencesListController.m
//  Mitsuha
//
//  Created by c0ldra1n on 4/29/17.
//  Copyright © 2017 c0ldra1n. All rights reserved.
//

#import "MSHMusicPreferencesListController.h"

#define kCRHeaderHeight 175

@interface MSHMusicPreferencesListController ()

@end

@implementation MSHMusicPreferencesListController


- (instancetype)init {
    self = [super init];
    if (self) {
        [self setupCephei];
    }
    return self;
}

-(instancetype)initWithCoder:(NSCoder *)aDecoder{
    
    self = [super initWithCoder:aDecoder];
    
    if (self) {
        [self setupCephei];
    }
    
    return self;
    
}

-(instancetype)initWithNibName:(NSString *)nibNameOrNil bundle:(NSBundle *)nibBundleOrNil{
    
    self = [super initWithNibName:nibNameOrNil bundle:nibBundleOrNil];
    
    if (self) {
        [self setupCephei];
    }
    
    return self;
    
}


-(void)setupCephei{
    
    HBAppearanceSettings *appearanceSettings = [[HBAppearanceSettings alloc] init];
    appearanceSettings.tintColor = [UIColor colorWithRed:1 green:0.176 blue:0.33 alpha:1.0];
    self.hb_appearanceSettings = appearanceSettings;
    
}

-(void)viewWillAppear:(BOOL)animated{
    [self clearCache];
    [self reload];
    [super viewWillAppear:animated];
}

- (NSArray *)specifiers {
    if (!_specifiers) {
        _specifiers = [self loadSpecifiersFromPlistName:@"Music" target:self];
    }
    
    return _specifiers;
}

@end
