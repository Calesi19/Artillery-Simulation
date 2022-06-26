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

bool Howitzer::checkCanFire()
{
	if (this->canFire == true)
		return true;
	else
		return false;
}

void Howitzer::fireProjectile()
{
	// TODO: Make this function work.
	canFire = false;
};


void Howitzer::toggleCanFire()
{
	if (this->canFire == true)
		this->canFire = false;
	else
		this->canFire = true;

}