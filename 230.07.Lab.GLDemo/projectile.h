#pragma once
#include "position.h"


class Projectile {
	


public:

	double mass;
	Position position;
	double diameter;
	double velocity;
	double angle;
	bool isMoving;
	double hangTime;


	bool checkIsMoving();

	void setAngle(double angle);

	double getAngle();

	double getXPosition();

	double getYPosition();

	void setXPosition(double value);

	void setYPosition(double value);

	void setVelocity(double velocity);

	double getVelocity();

	double getDiameter();

	double getMass();

	void toggleIsMoving();

	void updateHangTime(double dt);

	double getHangTime();

	double getSurfaceArea();
};