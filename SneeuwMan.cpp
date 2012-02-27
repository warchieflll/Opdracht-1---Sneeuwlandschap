/*
 * SneeuwMan.cpp
 *
 *  Created on: 27 feb. 2012
 *      Author: HP
 */

#include "SneeuwMan.hpp"
#include <ma.h>

SneeuwMan::SneeuwMan(int positionX, int positionY)
{
	this->positionX = positionX;
	this->positionY = positionY;
}

/* void SneeuwVlok::draw()
{
	maSetColor ( 0xffffff ); // wit
	maFillRect (this->positionX, this->positieY, this->size, this->size);
}
*/

void SneeuwMan::draw()
{
	maSetColor (0x888888); //grijs
	maFillRect (this->positionX, this-> positionY, 50, 50);
}

void SneeuwMan::moveSide(int direction)
{
	this->positionX += direction;
}

void SneeuwMan::moveUpDown(int updown)
{
	this->positionY += updown;
}

int SneeuwMan::getY()
{
	return positionY;
}

