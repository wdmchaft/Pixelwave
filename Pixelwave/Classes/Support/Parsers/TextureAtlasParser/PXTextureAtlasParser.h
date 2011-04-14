//
//  PXTextureAtlasParser.h
//  Pixelwave
//
//  Created by Oz Michaeli on 4/11/11.
//  Copyright 2011 NA. All rights reserved.
//

#import "PXParser.h"

@class PXTextureAtlas;
@protocol PXTextureModifier;

@interface PXTextureAtlasParser : PXParser {
@protected
	float contentScaleFactor;
}

- (id) initWithData:(NSData *)data
 contentScaleFactor:(float)contentScaleFactor
		   modifier:(id<PXTextureModifier>)modifier
			 origin:(NSString *)origin;

- (PXTextureAtlas *)newTextureAtlas;

@end

/// @cond DX_IGNORE
@interface PXTextureAtlasParser (PrivateButPublic)
- (id) _initWithData:(NSData *)data
  contentScaleFactor:(float)contentScaleFactor
			modifier:(id<PXTextureModifier>)modifier
			  origin:(NSString *)origin;
- (BOOL) _parseWithModifier:(id<PXTextureModifier>)modifier;
@end

/// @endcond