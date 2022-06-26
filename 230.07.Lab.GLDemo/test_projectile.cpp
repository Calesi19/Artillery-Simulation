/***********************************************************************
 * Header File:
 *    Test Howitzer : Test the Projectile class
 * Author:
 *    Carlos Lespin and Braxton Meyer
 * Summary:
 *    All the unit tests for Projectile
 ************************************************************************/

#pragma once

#include <iostream>
#include <assert.h>
#include "projectile.h"

using namespace std;

/*******************************
 * TEST Projectile
 * A friend class for Projectile which contains the Projectile unit tests
 ********************************/
class testProjectile {

public:
	void run() {

		test_isMoving();
		test_setAngle();
		test_getAngle();
		test_getXPosition();
		test_setXPosition();
		test_getYPosition();
		test_setYPosition();
		test_getVelocity();
		test_setVelocity();
		test_getDiameter();
		test_getMass();
		test_toggleIsMoving();
		test_updateHangTime();
		test_getHangTime();
		test_getSurfaceArea();
	
	}


private:

	void test_isMoving() {

		Projectile test1;
		test1.isMoving = true;
		assert(test1.checkIsMoving());
		


		Projectile test2;
		test2.isMoving = false;
		assert(test2.checkIsMoving());
	

	};

	void test_setAngle() {

		Projectile test1;
		test1.angle = 0;
		test1.setAngle(50);
		assert(test1.angle == 50);
		


		Projectile test2;
		test2.angle = 0;
		test2.setAngle(-50);
		assert(test2.angle == -50);


	};

	void test_getAngle() {

		Projectile test1;
		test1.angle = 0;
		assert(test1.getAngle() == 0);
		

		Projectile test2;
		test2.angle = 10;
		assert(test2.getAngle() == 10);
		

		Projectile test3;
		test3.angle = -10;
		assert(test3.getAngle() == -10);
		

	};

	void test_getXPosition() {

		Projectile test1;
		test1.position.setMetersX(0);
		assert(test1.getXPosition() == 0);
		

		Projectile test2;
		test2.position.setMetersX(330);
		assert(test2.getXPosition() == 330);
		

		Projectile test3;
		test3.position.setMetersX(-330);
		assert(test3.getXPosition() == -330);
		

	};

	void test_setXPosition() {

		Projectile test1;
		test1.position.setMetersX(0);
		test1.setXPosition(50);
		assert(test1.position.getMetersX() == 50);
	

		Projectile test2;
		test2.position.setMetersX(0);
		test2.setXPosition(-50);
		assert(test2.position.getMetersX() == -50);
		

	};

	void test_getYPosition() {

		Projectile test1;
		test1.position.setMetersY(0);
		assert(test1.getYPosition() == 0);
		

		Projectile test2;
		test2.position.setMetersY(330);
		assert(test2.getYPosition() == 330);
		

		Projectile test3;
		test3.position.setMetersY(-330);
		assert(test3.getYPosition() == -330);
		

	};

	void test_setYPosition() {

		Projectile test1;
		test1.position.setMetersY(0);
		test1.setYPosition(50);
		assert(test1.position.getMetersY() == 50);
		

		Projectile test2;
		test2.position.setMetersY(0);
		test2.setYPosition(-50);
		assert(test2.position.getMetersY() == -50);
		

	};

	void test_getVelocity() {

		Projectile test1;
		test1.velocity = 330;
		assert(test1.getVelocity() == 330);
		

		Projectile test2;
		test2.velocity = -330;
		assert(test2.getVelocity() == -330);
		
	};

	void test_setVelocity() {

		Projectile test1;
		test1.velocity = 0;
		test1.setVelocity(50);
		assert(test1.velocity == 50);
		

		Projectile test2;
		test2.velocity = 0;
		test2.setVelocity(-50);
		assert(test2.velocity == -50);
		

	};


	void test_getDiameter() {

		Projectile test1;
		test1.diameter = 330;
		assert(test1.getDiameter() == 330);
	

	};

	void test_getMass() {

		Projectile test1;
		test1.mass = 4040;
		assert(test1.getMass() == 4040);
		

		Projectile test2;
		test2.mass = -4040;
		assert(test2.getMass() == -4040);
		

	};


	void test_toggleIsMoving() {

		Projectile test1;
		test1.isMoving = true;
		test1.toggleIsMoving();
		assert(test1.isMoving == false);
		

		Projectile test2;
		test2.isMoving = false;
		test2.toggleIsMoving();
		assert(test2.isMoving == true);
	

	};

	void test_updateHangTime() {

		Projectile test1;
		test1.hangTime = 0;
		test1.updateHangTime(5);
		assert(test1.hangTime == 5);
		

		Projectile test2;
		test2.hangTime = 10;
		test2.updateHangTime(5);
		assert(test2.hangTime == 15);
		

		Projectile test3;
		test3.hangTime = -5;
		test3.updateHangTime(5);
		assert(test3.hangTime == 0);
		


	};

	void test_getHangTime() {

		Projectile test1;
		test1.hangTime = 0;
		assert(test1.getHangTime() == 0);
		

		Projectile test2;
		test2.hangTime = 45;
		assert(test2.getHangTime() == 45);
		

		Projectile test3;
		test3.hangTime = -45;
		assert(test3.getHangTime() == -45);
		


	};

	void test_getSurfaceArea() {

		Projectile test1;
		test1.diameter = -45;
		assert(test1.getSurfaceArea() == -45);
		

		Projectile test2;
		test2.diameter = 45;
		assert(test2.getSurfaceArea() == 45);
		
	};
};