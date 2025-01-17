/*
 * SneeuwMan.hpp
 *
 *  Created on: 8 feb. 2012
 *      Author: Bjorn Hoogeveen
 */

#ifndef SNEEUWMAN_HPP_
#define SNEEUWMAN_HPP_


//bevat teken functies
#include <ma.h>


//de klasse SneeuwMan
class SneeuwMan
{
private:
	int positionX;	//x positie van sneeuwman
	int positionY;	//y positie van sneeuwman

public:
	//constructor
	SneeuwMan( int positionX, int positionY );

	//tekent een sneeuwman
	void draw();

	//beweeg de sneeuwman in de richting "direcion", negatief getal is links, positief is rechts
	void moveSide( int direction );

	//beweeg de sneeuwman omhoog of omlaag
	void moveUpDown ( int updown );

	// haal y positie op voor check zwevende sneeuwman
	int getY();
};

#endif /* SNEEUWMAN_HPP_ */
