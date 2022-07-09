


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
	this->angle = angle;
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

void Projectile::setVelocity(double newVelocity) {
	this->velocity.push_back(newVelocity);
}

void Projectile::setXVelocity(double newVelocity) {
	this->xVelocity.push_back(newVelocity);
}

void Projectile::setYVelocity(double newVelocity) {
	this->yVelocity.push_back(newVelocity);
}

vector<double> Projectile::getVelocity() {
	return velocity;
}

vector<double> Projectile::getXVelocity() {
	return xVelocity;
}

vector<double> Projectile::getYVelocity() {
	return yVelocity;
}

void Projectile::setAx(double newAx) {
	this->Ax = newAx;
}

void Projectile::setAy(double newAy) {
	this->Ay = newAy;
}

double Projectile::getAx() {
	return Ax;
}

double Projectile::getAy() {
	return Ay;
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