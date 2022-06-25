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
#include <projectile.h>
#include <trajectory.h>
#include <point.h>
using namespace std;

/*******************************
 * TEST Projectile
 * A friend class for Projectile which contains the Projectile unit tests
 ********************************/
class testProjectile {

public:
	void run() {

		this.test_inMoving();
		this.test_setAngle();
		this.test_getAngle();
		this.test_getXPosition();
		this.test_setXPosition();
		this.test_getYPosition();
		this.test_setYPosition();
		this.test_getVelocity();
		this.test_setVelocity();
		this.test_getDiameter();
		this.test_getMass();
		this.test_toggleIsMoving();
		this.test_updateHangTime();
		this.test_getHangTime();
		this.test_getSurfaceArea();
		this.test_updateTrajectory();
		this.test_getTrajectoryX();
		this.test_getTrajectoryY();
	}


private:

	void test_isMoving() {

		Projectile test = new Projectile();
		test.isMoving == true;
		assert(test.isMoving() == true);
		delete test;

		Projectile test = new Projectile();
		test.isMoving == false;
		assert(test.isMoving() == false);
		delete test;

	};

	void test_setAngle() {

		Projectile test = new Projectile();
		test.angle = 0;
		test.setAngle(50);
		assert(test.angle == 50);
		delete test;


		Projectile test = new Projectile();
		test.angle = 0;
		test.setAngle(-50);
		assert(test.angle == -50);
		delete test;

	
	};

	void test_getAngle() {
		
		Projectile test = new Projectile();
		test.angle = 0;
		assert(test.getAngle == 0);
		delete test;

		Projectile test = new Projectile();
		test.angle = 10;
		assert(test.getAngle ==10);
		delete test;

		Projectile test = new Projectile();
		test.angle = -10;
		assert(test.getAngle == -10);
		delete test;

	};

	void test_getXPosition() {
		
		Projectile test = new Projectile();
		test.position.x = 0;
		assert(test.getXPosition() == 0);
		delete test;

		Projectile test = new Projectile();
		test.position.x = 330;
		assert(test.getXPosition() == 330);
		delete test;

		Projectile test = new Projectile();
		test.position.x = -330;
		assert(test.getXPosition() == -330);
		delete test;

	};

	void test_setXPosition() {

		Projectile test = new Projectile();
		test.position.x = 0;
		test.setXPosition(50);
		assert(test.position.x == 50);
		delete test;

		Projectile test = new Projectile();
		test.position.x = 0;
		test.setXPosition(-50);
		assert(test.position.x == -50);
		delete test;
	
	};

	void test_getYPosition() {

		Projectile test = new Projectile();
		test.position.y = 0;
		assert(test.getYPosition() == 0);
		delete test;

		Projectile test = new Projectile();
		test.position.y = 330;
		assert(test.getYPosition() == 330);
		delete test;

		Projectile test = new Projectile();
		test.position.y = -330;
		assert(test.getYPosition() == -330);
		delete test;

	};

	void test_setYPosition() {
		
		Projectile test = new Projectile();
		test.position.y = 0;
		test.setYPosition(50);
		assert(test.position.Y == 50);
		delete test;

		Projectile test = new Projectile();
		test.position.y = 0;
		test.setYPosition(-50);
		assert(test.position.y == -50);
		delete test;

	};

	void test_getVelocity() {
	
		Projectile test = new Projectile();
		test.velocity = 330;
		assert(test.getVelocity() == 330);
		delete test;

		Projectile test = new Projectile();
		test.velocity = -330;
		assert(test.getVelocity() == -330);
		delete test;


	};

	void test_setVelocity() {
		
		Projectile test = new Projectile();
		test.velocity = 0;
		test.setVelocity(50);
		assert(test.velocity == 50);
		delete test;

		Projectile test = new Projectile();
		test.velocity = 0;
		test.setVelocity(-50);
		assert(test.velocity == -50);
		delete test;

	};


	void test_getDiameter() {
		
		Projectile test = new Projectile();
		test.diameter = 330;
		assert(test.getDiameter() == 330);
		delete test;

	};

	void test_getMass() {
		
		Projectile test = new Projectile();
		test.mass = 4040;
		assert(test.getMass() == 4040);
		delete test;

		Projectile test = new Projectile();
		test.mass = -4040;
		assert(test.getMass() == -4040);
		delete test;

	};


	void test_toggleIsMoving() {

		Projectile test = new Projectile();
		test.isMoving = true;
		test.toggleIsMoving()
		assert(test.IsMoving() == false);
		delete test;

		Projectile test = new Projectile();
		test.isMoving = false;
		test.toggleIsMoving()
		assert(test.IsMoving() == true);
		delete test;

	};

	void test_updateHangTime() {
		
		Projectile test = new Projectile();
		test.hangTime = 0;
		test.updateHangTime(5);
		assert(test.hangTime == 5);
		delete test;

		Projectile test = new Projectile();
		test.hangTime = 10;
		test.updateHangTime(5);
		assert(test.hangTime == 15);
		delete test;

		Projectile test = new Projectile();
		test.hangTime = -5;
		test.updateHangTime(5);
		assert(test.hangTime == 0);
		delete test;


	};

	void test_getHangTime() {
		
		Projectile test = new Projectile();
		test.hangTime = 0;
		assert(test.getHangTime() == 0);
		delete test;

		Projectile test = new Projectile();
		test.hangTime = 45;
		assert(test.getHangTime() ==45);
		delete test;

		Projectile test = new Projectile();
		test.hangTime = -45;
		assert(test.getHangTime() == -45);
		delete test;


	};

	void test_getSurfaceArea() {
		
		Projectile test = new Projectile();
		test.surfaceArea = -45;
		assert(test.getSurfaceArea() == -45);
		delete test;

		Projectile test = new Projectile();
		test.surfaceArea = 45;
		assert(test.getSurfaceArea() == 45);
		delete test;


	};

	void test_updateTrajectory() {
		
		Projectile test = new Projectile();
		test.trajectory.x = [1,2,3];
		test.trajectory.y = [5,6,7];
		test.position.x = 4;
		test.position.y = 8;

		test.updateTrajectory();
 
		assert(test.trajectory.x == [1,2,3,4]);
		assert(test.trajectory.y == [5,6,7,8]);

		delete test;

	};

	void test_getTrajectoryX() {
		
		Projectile test = new Projectile();
		test.trajectory.x = [1, 2, 3, 4];
		assert(test.getTrajectoryX == [1, 2, 3, 4]);
		delete test;

	};

	void test_getTrajectoryY() {
		
		Projectile test = new Projectile();
		test.trajectory.y = [1, 2, 3, 4];
		assert(test.getTrajectoryY == [1, 2, 3, 4]);
		delete test;

	};

};
