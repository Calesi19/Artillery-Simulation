#pragma once
#include "position.h"
#include "equations.h"
#include <vector>
#include <iostream>

using namespace std;

class TestProjectile;

class Projectile {
	


public:


	Projectile() {
		for (int i = 0; i < 21; i++) {
			projectilePath.push_back(position);
		}

		velocity.push_back(827);

		

	}



	friend TestProjectile;

	double mass = 46.7;
	
	double diameter = 154.89;
	
	vector<Position> projectilePath;

	Position position = Position(0,0);


	vector<double> velocity;
	vector<double> xVelocity;
	vector<double> yVelocity;

	double angle = 0;
	double radians = angle * (3.14 / 180);


	bool isMoving = false;
	double hangTime = 0;

	double surfaceArea = 3.14 * pow(diameter / 2, 2) / 1000000;

	double Ax = 0;
	double Ay = 0;

	double dt = .5;
	

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