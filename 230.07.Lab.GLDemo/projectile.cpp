


#include "position.h"



class Projectile {

public:


	double mass = 46.7;
	Position position = Position(0, 0);
	double diameter = 154;
	double velocity = 827;
	double angle = 0;
	bool isMoving = false;
	double hangTime = 0;



	bool checkIsMoving() {
		return this->isMoving;
	}

	void setAngle(double angle) {
		this->angle = angle;
	}

	double getAngle() {
		return this->angle;
	}

	double getXPosition() {
		return this->position.getMetersX();
	}

	double getYPosition() {
		return this->position.getMetersY();
	}

	void setXPosition(double value) {
		this->position.setMetersX(value);
	}

	void setYPosition(double value) {
		this->position.setMetersY(value);
	}

	void setVelocity(double velocity) {
		this->velocity = velocity;
	}

	double getVelocity() {
		return this->velocity;
	}

	double getDiameter() {
		return this->diameter;
	}

	double getMass() {
		return this->mass;
	}

	void toggleIsMoving() {
		if (this->isMoving) {
			this->isMoving = false;
		}
		else {
			this->isMoving = true;
		}
	}

	void updateHangTime(double dt) {
		this->hangTime += dt;
	}

	double getHangTime() {
		return this->hangTime;
	}

	double getSurfaceArea() {
		return 3.14 * pow((this->getDiameter() / 2), 2);
	}
};