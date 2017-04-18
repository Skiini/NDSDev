/*
 * physics.h
 *
 *  Created on: Mar 28, 2017
 *      Author: efarhan
 */

#ifndef INCLUDE_PHYSICS_H_
#define INCLUDE_PHYSICS_H_

#include <nds.h>

#define Fixed int

class Point
{
	//pixel positions
public:
	Point(int x, int y);

private:
	int x,y;
};

class Vector2
{
	//physics position
private:
	Fixed x,y;

};

class Rigidbody
{

};

class Box
{

};

class Circle
{

};

#endif /* INCLUDE_PHYSICS_H_ */
