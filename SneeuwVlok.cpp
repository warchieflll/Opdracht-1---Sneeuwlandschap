/*
 * SneeuwVlok.cpp
 *
 *  Created on: 28 feb. 2012
 *      Author: Bjorn Hoogeveen
 */

#include "SneeuwVlok.hpp"
#include <conprint.h>

// constructor
SneeuwVlok::SneeuwVlok(int positionX, int positionY, int size, bool isdood) {
	this->positionX = positionX;
	this->positionY = positionY;
	this->size = size;
	this->isdood = isdood;
}


//teken functie die een sneeuwvlok tekent
void SneeuwVlok::draw()
{
		maSetColor (0xffffff); //wit
		maFillRect (this->positionX, positionY, size, size);
}


//functie die de y positie verandert
void SneeuwVlok::fall( int groundLevel)
{
	this->positionY += groundLevel;
}


// controleer of sneeuwvlok grond raakt, en verander a.d.h.v. resultaat de isdood.
bool SneeuwVlok::isDead(int grond)
{
	if (this->positionY < grond)
	{
		this->isdood = false;
	}
	else
	{
		this->isdood = true;
	}
	return isdood;
}
