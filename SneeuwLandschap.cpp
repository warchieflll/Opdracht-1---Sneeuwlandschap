/*
 * SneeuwLandschap.cpp
 *
 *  Created on: 8 feb. 2012
 *      Author: Bjorn Hoogeveen
 */

#include "SneeuwLandschap.hpp"
#include <conprint.h>

//globale variabelen voor breedte en hoogte van het scherm
int screenWidth;
int screenHeight;
// bovenkant van sneeuw
int grond;
// boolean of sneeuw is gevallen of niet, standaard op niet
bool isdood = false;


//constructor
SneeuwLandschap::SneeuwLandschap()
{
	//sla schermgrootte op in globale variabelen
	MAExtent screenSize = maGetScrSize();
	screenWidth = EXTENT_X( screenSize );
	screenHeight = EXTENT_Y( screenSize );

	//stel sneeuwhoogte in (vanaf bodem)
	this->sneeuwHoogte = 30;

	//maak een nieuwe sneeuwman
	this->sneeuwMan = new SneeuwMan( screenWidth / 2, screenHeight - this->sneeuwHoogte - 50 );

	// stel grondhoogte in
	this->grond = screenHeight - sneeuwHoogte;
}


//wordt aangeroepen als er input is (druk op de toets, touch van scherm)
void SneeuwLandschap::run( MAEvent event )
{
		//als er een key is ingetoetst
		if( event.type == EVENT_TYPE_KEY_PRESSED )
		{
			//pak de key code
			int key = maGetKeys();

			//kijk voor linkertoets
			if( key == MAKB_LEFT )
				this->sneeuwMan->moveSide( -3 );	//beweeg sneeuwman -3 pixels

			//kijk voor rechtertoets
			if( key == MAKB_RIGHT )
				this->sneeuwMan->moveSide( 3 );		//beweeg sneeuwman 3 pixels

			//kijk voor toets omhoog
			if( key == MAKB_UP && this->sneeuwMan->getY() > screenHeight - this->sneeuwHoogte - 50)
				this->sneeuwMan->moveUpDown( -3 );	//beweeg sneeuwman -3 pixels

			//kijk voor toets omlaag
			if( key == MAKB_DOWN )
				this->sneeuwMan->moveUpDown( 3 );		//beweeg sneeuwman 3 pixels
		}

	// een sneeuwvlok aanmaken en toevoegen aan array
		this->sneeuwVlok = new SneeuwVlok (rand()%screenWidth,0, rand()%15, isdood);
		this->sneeuwVlokArray.add(sneeuwVlok);
}


//wordt elke "tick" aangeroepen om het winterlandschap, sneeuwman en sneeuwvlokken te tekenen
void SneeuwLandschap::draw()
{
	//kleur de lucht blauw
	maSetColor( 0x0055ff );
	maFillRect( 0, 0, screenWidth, screenHeight );

	//maak sneeuw op de grond, a.d.h.v. sneeuwHoogte
	maSetColor( 0xffffff );
	maFillRect( 0, screenHeight - this->sneeuwHoogte, screenWidth, this->sneeuwHoogte );

	//teken de sneeuwman
	sneeuwMan->draw();

	//Teken alle sneeuwvlokken, laat ze vallen en verwijder ze
	for (int i= 0; i<sneeuwVlokArray.size(); i++)
	{
		// zolang de grond nog niet geraakt is...
		if (!sneeuwVlokArray[i]->isDead(grond))
		{
			// laat sneeuw vallen
			sneeuwVlokArray[i]->fall(5);
			// check of sneeuw grond heeft geraakt
			sneeuwVlokArray[i]->isDead(grond);
			// teken de sneeuw
			sneeuwVlokArray[i]->draw();
		}
		// als grond is geraakt
		else
		{
			// verwijder sneeuwvlok uit de array
			sneeuwVlokArray.remove(i);
		}
	}
}
