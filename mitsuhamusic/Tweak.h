//
//  Tweak.h
//  Mitsuha
//
//  Created by c0ldra1n on 2/5/17.
//  Copyright © 2017 c0ldra1n. All rights reserved.
//
//

#import <UIKit/UIKit.h>

#import <AVFoundation/AVFoundation.h>

#import <substrate.h>

#import "../xctheos.h"

#import "../MSHJelloView.h"

@interface MPQueuePlayer : NSObject

@property (nonatomic, readonly) AVPlayer *_player;
@property (nonatomic,readonly) AVPlayerItem * currentItem;

- (AVPlayerItem *)currentItem;

@end

@interface MPAVController : NSObject

@property (nonatomic, readonly) MPQueuePlayer *avPlayer;

@property (assign,nonatomic) float volume;

-(void)togglePlayback;

-(void)play;
-(void)pause;
-(BOOL)isPlaying;

-(void)notifyAVPlayerItemWillChange:(id)arg1;
-(void)notifyAVPlayerItemDidChange:(id)arg1;

-(void)_itemWillChange:(id)arg1 ;
-(void)_itemDidChange:(id)arg1 ;

-(void)_tracksDidChange:(id)arg1 ;

-(void)configureMitsuhaFilter;

@end

@interface MPUAVPlayer : MPAVController

@end


@interface RURadioAVPlayer : MPUAVPlayer

@end

@class MusicNowPlayingViewController;

@interface MusicAVPlayer : RURadioAVPlayer

+(id)sharedAVPlayer;

-(void)_connectAVPlayer;

-(void)beginPlayback;
-(void)beginOrTogglePlayback;

@end

@interface MusicArtworkView : UIImageView

@end

@interface MusicNowPlayingItemViewController : UIViewController{
    
    MusicArtworkView *_imageView;
    
}

-(UIImage *)artworkImage;


@end

@interface MusicPlaybackProgressSliderView : UIView

@end


@interface MPVolumeSlider : UISlider
@end

@interface MusicNowPlayingVolumeSlider : MPVolumeSlider
@end

@interface MusicNowPlayingTitlesView : UIControl
@end




@interface MPUTransportControl : NSObject

@property (nonatomic, readonly) long long type;

- (id)initWithType:(long long)arg1 group:(int)arg2;

@end

@interface MPUTransportButton : UIButton

@property (nonatomic, retain) UIImage *transportButtonImage;
@property (nonatomic, retain) NSNumber *type;

@end


@interface MPUTransportControlsView : UIView

- (void)_configureTransportButton:(MPUTransportButton *)arg1 forTransportControl:(MPUTransportControl *)arg2;

- (void)_transportControlTapped:(MPUTransportButton *)arg1;

- (void)_transportControlTouchEntered:(MPUTransportButton *)arg1;
- (void)_transportControlTouchExited:(MPUTransportButton *)arg1;

@end


@interface MPUGradientView : UIView
@end

@interface MPUEffectView : UIView
@end


@interface MPUPinningView : UIView

@property (nonatomic,retain) UIView * contentView;                      //@synthesize contentView=_contentView - In the implementation block
@property (nonatomic,retain) UIView * pinningSourceView;                //@synthesize pinningSourceView=_pinningSourceView - In the implementation block
@property (nonatomic,retain) CALayer * pinningSourceLayer;              //@synthesize pinningSourceLayer=_pinningSourceLayer - In the implementation block

@end

@interface MPUBlurEffectView : MPUEffectView

@property (nonatomic,retain) MPUPinningView * blurView;                //@synthesize blurView=_blurView - In the implementation block

@end

@interface MPUVibrantContentEffectView : MPUEffectView

@property (nonatomic,retain) UIView *contentView;
@property (nonatomic,retain) MPUPinningView *maskedView;
@property (assign,nonatomic) BOOL vibrancyEnabled;

-(void)disableVibrancyForLayer:(id)arg1 ;

@end


@interface MusicNowPlayingViewController : UIViewController

#pragma mark custom

@property BOOL shouldSendUpdateMessage;

@property (nonatomic, retain) MSHJelloView *mitsuhaJelloView;

@property (nonatomic, retain) UIImageView *blurgroundView;

-(void)applyCustomLayout;
-(void)refreshWave;

#pragma mark original

-(void)_updateNowPlayingInfo;

@property (nonatomic,readonly) MPAVController *player;

@property (nonatomic,readonly) MusicNowPlayingItemViewController * currentItemViewController;

@property (nonatomic,readonly) MusicPlaybackProgressSliderView * playbackProgressSliderView;

@property (nonatomic,readonly) MusicNowPlayingTitlesView * titlesView;

@property (nonatomic,readonly) MPUTransportControlsView * transportControls;

@property (nonatomic,readonly) MusicNowPlayingVolumeSlider * volumeSlider;

@property (nonatomic,readonly) MPUTransportControlsView * secondaryTransportControls;

@property (nonatomic,readonly) MPUGradientView * statusBarLegibilityGradient;

@property (nonatomic,readonly) NSArray * persistentAnimationLayers;

@property (nonatomic,readonly) UIView * currentItemViewControllerContainerView;
@property (nonatomic,readonly) UIView * currentItemViewControllerBackgroundView;
@property (nonatomic,readonly) UIViewController * presentedDetailViewController;
@property (nonatomic,retain) UIView * backgroundClippingView;

@property (nonatomic,retain) MPUBlurEffectView * backgroundView;
@property (nonatomic,retain) MPUVibrantContentEffectView * vibrantEffectView;

@end




@interface MusicUpNextViewController : UIViewController <UIViewControllerTransitioningDelegate>

-(void)_dismissUpNext;

@end


@interface MusicUpNextTransitionController : NSObject <UIViewControllerAnimatedTransitioning>

@end
