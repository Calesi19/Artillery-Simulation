/***********************************************************************
 * Header File:
 *    Howitzer : The representation of the howtizer, it's position, and ability to fire
 * Author:
 *    Braxton Meyer and Carlos Lespin-Silva
 * Summary:
 *    Everything we need to know about the Howitzer
 ************************************************************************/


#include "position.h"

#pragma once
class TestHowitzer;

class Howitzer {


public:
	friend TestHowitzer;

	Howitzer() {
		point.setPixelsX(700 / 2.0);
		point.setPixelsY(500);
	}


	bool checkCanFire();

	void toggleCanFire();

	void fireProjectile();

	//Projectile projectile();

	// Getters
	double getAngle()           const { return angle; }

	double getXPosition()       const { return point.getMetersX(); }

	double getYPosition()       const { return point.getMetersY(); }

	// Setters
	void setAngle(double newAngle) { angle = newAngle; }

	void setXPosition(double xMeters) { point.setMetersX(xMeters); }

	void setYPosition(double yMeters) { point.setMetersY(yMeters); }

private:
	bool canFire;
	double angle;
	Position point;


	
	


};