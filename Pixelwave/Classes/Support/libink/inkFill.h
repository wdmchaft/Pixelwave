//
//  inkFill.h
//  ink
//
//  Created by John Lattin on 11/9/11.
//  Copyright (c) 2011 Spiralstorm Games. All rights reserved.
//

#ifndef _INK_FILL_H_
#define _INK_FILL_H_

#include "inkHeader.h"
#include "inkTypes.h"
#include "inkGeometry.h"
#include "inkArray.h"

typedef struct
{
	inkFillType fillType; // Must be the first value

	unsigned int color;
	float alpha;
} inkSolidFill;

typedef struct
{
	inkFillType fillType; // Must be the first value

	inkMatrix matrix;

	bool repeat;
	bool smooth;
} inkBitmapFill;

typedef struct
{
	inkFillType fillType; // Must be the first value

	inkArray* colors;
	inkArray* alphas;
	inkArray* ratios;

	inkMatrix matrix;

	inkGradientType type;
	inkSpreadMethod spreadMethod;
	inkInterpolationMethod interpolationMethod;

	float focalPointRatio;
} inkGradientFill;

#define _inkSolidFillDefault {inkFillType_Solid, 0, 1.0f}
#define _inkBitmapFillDefault {inkFillType_Bitmap, _inkMatrixIdentity, true, false}
#define _inkGradientFillDefault {inkFillType_Gradient, NULL, NULL, NULL, _inkMatrixIdentity, inkGradientType_Linear, inkSpreadMethod_Pad, inkInterpolationMethod_RGB, 0.0f}

inkExtern const inkSolidFill inkSolidFillDefault;
inkExtern const inkBitmapFill inkBitmapFillDefault;
inkExtern const inkGradientFill inkGradientFillDefault;

inkExtern inkSolidFill inkSolidFillMake(unsigned int color, float alpha);
inkExtern inkBitmapFill inkBitmapFillMake(inkMatrix matrix, bool repeat, bool smooth);
inkExtern inkGradientFill inkGradientFillMake(inkMatrix matrix, inkArray* colors, inkArray* alphas, inkArray* ratios, inkGradientType type, inkSpreadMethod spreadMethod, inkInterpolationMethod interpolationMethod, float focalPointRatio);

#endif