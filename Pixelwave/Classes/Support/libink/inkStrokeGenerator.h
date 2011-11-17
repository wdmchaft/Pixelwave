//
//  inkStrokeGenerator.h
//  ink
//
//  Created by John Lattin on 11/8/11.
//  Copyright (c) 2011 Spiralstorm Games. All rights reserved.
//

#ifndef _INK_STROKE_GENERATOR_H_
#define _INK_STROKE_GENERATOR_H_

#include "inkHeader.h"

#include "inkStroke.h"
#include "inkGeometry.h"

#include "inkTessellator.h"
#include "inkGenerator.h"

typedef struct
{
	inkGenerator* generator; // Parent - must be first argument

	inkStroke* stroke;
} inkStrokeGenerator;

inkExtern inkStrokeGenerator *inkStrokeGeneratorCreate(inkTessellator* tessellator, inkArray *renderGroups, inkStroke* stroke);
inkExtern void inkStrokeGeneratorDestroy(inkStrokeGenerator* generator);

inkExtern void inkStrokeGeneratorSetFill(inkStrokeGenerator* generator, void* fill);

inkExtern void inkStrokeGeneratorMoveTo(inkStrokeGenerator* generator, inkPoint position);
inkExtern void inkStrokeGeneratorLineTo(inkStrokeGenerator* generator, inkPoint position);
inkExtern void inkStrokeGeneratorCurveTo(inkStrokeGenerator* generator, inkPoint control, inkPoint anchor);
inkExtern void inkStrokeGeneratorEnd(inkStrokeGenerator* generator);

#endif