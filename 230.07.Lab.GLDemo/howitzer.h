/***********************************************************************
 * Header File:
 *    Howitzer : The representation of the howtizer, it's position, and ability to fire
 * Author:
 *    Braxton Meyer and Carlos Lespin-Silva
 * Summary:
 *    Everything we need to know about the Howitzer
 ************************************************************************/

#pragma once

class Howitzer {


public:

	bool checkCanFire();

	void toggleCanFire();

	void fireProjectile();

	// Getters
	float getAngle()           const { return angle; }

	float getXPosition()       const { return point.getMetersX(); }

	float getYPosition()       const { return point.getMetersY(); }

	// Setters
	void setangle(double newAngle) { angle = newAngle; }

	void setXPosition(double xMeters) { point.setMetersX(xMeters); }

	void setYPosition(double yMeters) { point.setMetersY(yMeters); }

private:
	bool canFire;
	float angle;
	Position point;

};