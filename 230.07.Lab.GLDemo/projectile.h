#pragma once
#include "position.h"


class TestProjectile;

class Projectile {
	


public:
	friend TestProjectile;

	double mass = 46.7;
	Position position = Position(0, 0);
	double diameter = 154;
	double velocity = 827;
	double angle = 0;
	bool isMoving = false;
	double hangTime = 0;

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