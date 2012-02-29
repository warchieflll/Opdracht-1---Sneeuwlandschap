/*
 * SneeuwLandschap.hpp
 *
 *  Created on: 8 feb. 2012
 *      Author: Bjorn Hoogeveen
 */

#ifndef SNEEUWLANDSCHAP_HPP_
#define SNEEUWLANDSCHAP_HPP_


#include <ma.h>
#include <MAUtil/Vector.h>

#include "SneeuwMan.hpp"
#include "SneeuwVlok.hpp"



class SneeuwLandschap
{
private:
	SneeuwMan* sneeuwMan;
	SneeuwVlok* sneeuwVlok;
	MAUtil::Vector<SneeuwVlok*> sneeuwVlokArray;
	int sneeuwHoogte;
	int grond;

public:
	SneeuwLandschap();
	void draw();
	void run( MAEvent event );
};

#endif /* SNEEUWLANDSCHAP_HPP_ */
