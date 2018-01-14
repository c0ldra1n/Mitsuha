
#import "MSHRootListController.h"
#import "MSHHeaderView.h"
#import <spawn.h>

#define kCRHeaderHeight 250

#define kMSHBundlePath @"/Library/PreferenceBundles/Mitsuha.bundle"


@implementation MSHRootListController

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

-(void)viewWillAppear:(BOOL)animated{
    [self clearCache];
    [self reload];
    [super viewWillAppear:animated];
}

-(void)setupCephei{
    
    HBAppearanceSettings *appearanceSettings = [[HBAppearanceSettings alloc] init];
    appearanceSettings.tintColor = [UIColor colorWithRed:0.22 green:0.77 blue:0.88 alpha:1.0];
    appearanceSettings.translucentNavigationBar = true;
    self.hb_appearanceSettings = appearanceSettings;
    
}

-(void)viewDidLoad{
    [super viewDidLoad];
    
    UIImage *backgroundImage = [UIImage imageWithContentsOfFile:[kMSHBundlePath stringByAppendingPathComponent:@"header-background.png"]];
    UIImage *overlayImage = [UIImage imageWithContentsOfFile:[kMSHBundlePath stringByAppendingPathComponent:@"header-overlay.png"]];
    
    self.table.tableHeaderView = [[MSHHeaderView alloc] initWithBackground:backgroundImage overlay:overlayImage];
    
    self.table.tableHeaderView.frame = CGRectMake(0, 0, self.table.bounds.size.width, kCRHeaderHeight);
    
}

- (NSArray *)specifiers {
    if (!_specifiers) {
        _specifiers = [self loadSpecifiersFromPlistName:@"Root" target:self];
    }
    
    return _specifiers;
}


-(void)restartMusic{
    NSLog(@"Restart: Music");
    system("killall -9 Music");
}

-(void)restartSpotify{
    NSLog(@"Restart: Spotify");
    system("killall -9 Spotify");
}

@end
