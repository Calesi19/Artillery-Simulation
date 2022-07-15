


#include "position.h"
#include "projectile.h"



double Projectile::circleArea(double r) {

	/*
	a = area of a circle (m2)
	r = radius of a circle
	*/

	double a = 3.14 * pow(r, 2);
	return a;

}


bool Projectile::checkIsMoving() {
	return this->isMoving;
}

void Projectile::setAngle(double angle) {
	this->angle = angle * 100 + 90;
	this->radians = this->angle * (3.14 / 180);
}

double Projectile::getAngle() {
	return this->angle;
}

double Projectile::getXPosition() {
	return this->position.getMetersX();
}

double Projectile::getYPosition() {
	return this->position.getMetersY();
}

void Projectile::setXPosition(double value) {
	this->position.setMetersX(value);
}

void Projectile::setYPosition(double value) {
	this->position.setMetersY(value);
}


void Projectile::setVelocity(double velocity) {
	this->velocity.push_back(velocity);
}

double Projectile::getVelocity() {
	return this->velocity.back();
}

double Projectile::getDiameter() {
	return this->diameter;
}

double Projectile::getMass() {
	return this->mass;
}

void Projectile::toggleIsMoving() {
	if (this->isMoving) {
		this->isMoving = false;
	}
	else {
		this->isMoving = true;
	}
}

void Projectile::updateHangTime(double dt) {
	this->hangTime += dt;
}

double Projectile::getHangTime() {
	return this->hangTime;
}

double Projectile::getSurfaceArea() {
	return this->surfaceArea;
}

void Projectile::reset(Position ptUpperRight) {
	// Resets the projectile's position (usually) after colliding with something
	position = ptUpperRight;

	projectilePath.push_back(position);
	setVelocity(0);
	Ax = 0;
	Ay = 0;
	toggleIsMoving();
	return;
}