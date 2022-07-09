#pragma once
#include "position.h"
#include "equations.h"
#include <vector>
#include <iostream>

using namespace std;

class TestProjectile;

class Projectile {
	


public:
	friend TestProjectile;

	double mass = 46.7;
	
	double diameter = 154.89;
	
	vector<Position> projectilePath;

	Position position;

	double iVelocity = 827;

	vector<double> velocity;
	vector<double> xVelocity;
	vector<double> yVelocity;

	double angle = 0;
	double radians;


	bool isMoving = false;
	double hangTime = 0;

	double surfaceArea = 3.14 * pow(diameter / 2, 2) / 1000000;

	double Ax;
	double Ay;

	double dt = .01;
	

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