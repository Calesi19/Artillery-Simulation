/***********************************************************************
 * Source File:
 *    Howitzer : The representation of the howtizer, it's position, and ability to fire
 * Author:
 *    Braxton Meyer and Carlos Lespin-Silva
 * Summary:
 *    Everything we need to know about the Howitzer
 ************************************************************************/
#include "position.h"
#include "howitzer.h"

void Howitzer::toggleCanFire()
{
	// Toggles ability to fire to the opposite of what it currently is.
	if (this->canFire == true)
		this->canFire = false;
	else
		this->canFire = true;

}