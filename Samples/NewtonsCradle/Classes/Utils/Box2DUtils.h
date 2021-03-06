/*
 *  _____                       ___                                            
 * /\  _ `\  __                /\_ \                                           
 * \ \ \L\ \/\_\   __  _    ___\//\ \    __  __  __    ___     __  __    ___   
 *  \ \  __/\/\ \ /\ \/ \  / __`\\ \ \  /\ \/\ \/\ \  / __`\  /\ \/\ \  / __`\ 
 *   \ \ \/  \ \ \\/>  </ /\  __/ \_\ \_\ \ \_/ \_/ \/\ \L\ \_\ \ \_/ |/\  __/ 
 *    \ \_\   \ \_\/\_/\_\\ \____\/\____\\ \___^___ /\ \__/|\_\\ \___/ \ \____\
 *     \/_/    \/_/\//\/_/ \/____/\/____/ \/__//__ /  \/__/\/_/ \/__/   \/____/
 *       
 *           www.pixelwave.org + www.spiralstormgames.com
 *                            ~;   
 *                           ,/|\.           
 *                         ,/  |\ \.                 Core Team: Oz Michaeli
 *                       ,/    | |  \                           John Lattin
 *                     ,/      | |   |
 *                   ,/        |/    |
 *                 ./__________|----'  .
 *            ,(   ___.....-,~-''-----/   ,(            ,~            ,(        
 * _.-~-.,.-'`  `_.\,.',.-'`  )_.-~-./.-'`  `_._,.',.-'`  )_.-~-.,.-'`  `_._._,.
 * 
 * Copyright (c) 2011 Spiralstorm Games http://www.spiralstormgames.com
 * 
 * This software is provided 'as-is', without any express or implied
 * warranty. In no event will the authors be held liable for any damages
 * arising from the use of this software.
 * 
 * Permission is granted to anyone to use this software for any purpose,
 * including commercial applications, and to alter it and redistribute it
 * freely, subject to the following restrictions:
 *
 * 1. The origin of this software must not be misrepresented; you must not
 *    claim that you wrote the original software. If you use this software
 *    in a product, an acknowledgment in the product documentation would be
 *    appreciated but is not required.
 * 2. Altered source versions must be plainly marked as such, and must not be
 *    misrepresented as being the original software.
 * 3. This notice may not be removed or altered from any source distribution.
 */

#import "Pixelwave.h"
#import "Box2D.h"

// Roughly 9.8 m/(s^2)
#define GRAVITY 9.8f
#define POINTS_PER_METER (128.0f)

#define PointsToMeters(_points_) ((_points_) / POINTS_PER_METER)
#define MetersToPoints(_meters_) ((_meters_) * POINTS_PER_METER)

// Create a b2Vec2 by taking in pixels and converting to meters
#define b2Vec2_px2m(_x_,_y_) (b2Vec2(PointsToMeters(_x_), PointsToMeters(_y_)))

@interface Box2DUtils : NSObject
{
}

// Does a hit test to check if a box2d shape is under a given point
+ (b2Fixture *)fixtureInWorld:(b2World *)physicsWorld
						  atX:(float)xInPoints
							y:(float)yInPoints;

// Base Functions
+ (b2Body *)bodyInWorld:(b2World *)physicsWorld
			withBodyDef:(b2BodyDef *)bodyDef
			 fixtureDef:(b2FixtureDef *)fixtureDef
				 shapes:(b2Shape *)shape0, ...;

// Utilities
+ (b2Body *)staticBodyInWorld:(b2World *)physicsWorld
				 withFriction:(float)friction
				  restitution:(float)restitution
					   shapes:(b2Shape *)shape0, ...;
+ (b2Body *)staticBodyInWorld:(b2World *)physicsWorld
				 withFriction:(float)friction
				  restitution:(float)restitution
					    shape:(b2Shape *)shape;
+ (b2Body *)staticBodyInWorld:(b2World *)physicsWorld
					withShape:(b2Shape *)shape;

+ (b2Body *)dynamicBodyInWorld:(b2World *)physicsWorld
				  withFriction:(float)friction
				   restitution:(float)restitution
						shapes:(b2Shape *)shape0, ...;
+ (b2Body *)dynamicBodyInWorld:(b2World *)physicsWorld
				  withFriction:(float)friction
				   restitution:(float)restitution
						 shape:(b2Shape *)shape;
+ (b2Body *)dynamicBodyInWorld:(b2World *)physicsWorld
					 withShape:(b2Shape *)shape;

+ (b2Body *)staticBorderInWorld:(b2World *)physicsWorld
						   rect:(PXRectangle *)rect
					  thickness:(float)thickness;

@end
