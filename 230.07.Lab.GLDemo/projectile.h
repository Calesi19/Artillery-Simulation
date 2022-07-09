#pragma once
#include "position.h"
#include <vector>
#include <iostream>

using namespace std;

class TestProjectile;

class Projectile {
	


public:
	friend TestProjectile;

	double mass = 46.7;
	Position position = Position(0, 0);
	double diameter = 154.89;

	double iVelocity = 827;

	vector<double> velocity;
	vector<double> xVelocity;
	vector<double> yVelocity;

	double angle;
	double radians;


	bool isMoving = false;
	double hangTime = 0;

	double Ax;
	double Ay;
	
	double circleArea(double r);

	double surfaceArea = circleArea((diameter / 2)) / 1000000;

	bool checkIsMoving();

	void setAngle(double angle);

	double getAngle();

	double getXPosition();

	double getYPosition();

	void setXPosition(double value);

	void setYPosition(double value);

	void setVelocity(double velocity);

	void setXVelocity(double velocity);

	void setYVelocity(double velocity);

	vector<double> getVelocity();

	vector<double> getXVelocity();

	vector<double> getYVelocity();

	void setAx(double newAx);

	void setAy(double newAy);

	double getAx();

	double getAy();

	double getDiameter();

	double getMass();

	void toggleIsMoving();

	void updateHangTime(double dt);

	double getHangTime();

	double getSurfaceArea();
};