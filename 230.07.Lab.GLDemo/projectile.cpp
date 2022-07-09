


#include "position.h"
#include "projectile.h"




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