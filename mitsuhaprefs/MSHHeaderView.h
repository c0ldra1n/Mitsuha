//
//  MSBHeaderView.h
//  Musubi
//
//  Created by c0ldra1n on 3/1/17.
//  Copyright © 2017 c0ldra1n. All rights reserved.
//

#import <UIKit/UIKit.h>

@interface MSHHeaderView : UIView {
    
    UIImage *backgroundImage;
    UIImage *overlayImage;
}

@property (nonatomic, retain) UIImageView *backgroundView;

@property (nonatomic, retain) UIImageView *overlayView;

-(instancetype)initWithBackground:(UIImage *)background overlay:(UIImage *)overlay;

@end
