/*
 * SneeuwMan.cpp
 *
 *  Created on: 27 feb. 2012
 *      Author: Bjorn Hoogeveen
 */

#include "SneeuwMan.hpp"
#include <ma.h>


// constructor
SneeuwMan::SneeuwMan(int positionX, int positionY)
{
	this->positionX = positionX;
	this->positionY = positionY;
}


// tekenfunctie voor sneeuwman
void SneeuwMan::draw()
{
	maSetColor (0x888888); //grijs
	maFillRect (this->positionX, this-> positionY, 50, 50);
}


// beweeg sneeuwman op x-as
void SneeuwMan::moveSide(int direction)
{
	this->positionX += direction;
}


// beweeg sneeuwman op y-as
void SneeuwMan::moveUpDown(int updown)
{
	this->positionY += updown;
}


// haal y positie op voor check zwevende sneeuwman
int SneeuwMan::getY()
{
	return positionY;
}
