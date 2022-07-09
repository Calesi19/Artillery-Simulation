#pragma once
#include "position.h"
#include "equations.cpp"
#include <vector>
#include <iostream>

class TestProjectile;

class Projectile {
	


public:
	friend TestProjectile;

	double mass = 46.7;
	Position position = Position(0, 0);
	double diameter = 154.89;

	double iVelocity = 827;

	vector<double> Velocity;
	vector<double> xVelocity;
	vector<double> yVelocity;

	double angle;
	double radians;


	bool isMoving = false;
	double hangTime = 0;

	double surfaceArea = circleArea((diameter / 2)) / 1000000;

	double Ax;
	double Ay;
	

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