/*
 * SneeuwVlok.hpp
 *
 *  Created on: 8 feb. 2012
 *      Author: Bjorn Hoogeveen
 */

#ifndef SNEEUWVLOK_HPP_
#define SNEEUWVLOK_HPP_


//deze header hebben we nodig voor de functie rand()
#include <mastdlib.h>


//maak een klasse SneeuwVlok
class SneeuwVlok
{
private:
	int positionX;	//sneeuwvlok heeft x positie
	int positionY;	//sneeuwvlok heeft y positie
	int size;		//sneeuwvlok heeft (een willekeurige) grootte
	bool isdood;

public:
	SneeuwVlok( int positionX, int positionY, int size, bool isDead);	//constructor
	void fall( int groundLevel);				// functie die ypositie veranderd.
	void draw();								//teken functie die een sneeuwvlok tekent
	bool isDead(int grond);						//functie die de sneeuwvlok dead status teruggeeft
};



#endif /* SNEEUWVLOK_HPP_ */
