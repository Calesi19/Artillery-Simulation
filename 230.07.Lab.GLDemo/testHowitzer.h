/***********************************************************************
 * Header File:
 *    Test Howitzer : Test the Howitzer class
 * Author:
 *    Carlos Lespin and Braxton Meyer
 * Summary:
 *    All the unit tests for Howitzer
 ************************************************************************/


#pragma once

#include <iostream>
#include "howitzer.h"
#include "position.h"
#include <cassert>

using namespace std;

/*******************************
 * TEST Howitzer
 * A friend class for Howitzer which contains the Howitzer unit tests
 ********************************/
class TestHowitzer
{
public:
    void run()
    {

        // Test toggleCanFire
        toggleCanFire1();
        toggleCanFire2();

        // Test setters
        setAngle();
        setXPosition();
        setYPosition();

        // Test getters
        getAngle();
        getXPosition();
        getYPosition();
    }

private:

    
    void toggleCanFire1() const
    {   // setup
        Howitzer how;
        how.canFire = true;
        how.angle = 45;
        how.point.x = 5;
        how.point.y = 5;
        // exercise
        how.toggleCanFire();
        // verify
        assert(how.canFire == false);
    }  // teardown

    void toggleCanFire2() const
    {   // setup
        Howitzer how;
        how.canFire = false;
        how.angle = 45;
        how.point.x = 5;
        how.point.y = 5;
        // exercise
        how.toggleCanFire();
        // verify
        assert(how.canFire == true);
    }  // teardown

    void setAngle() const
    {
        // setup
        Howitzer how;
        how.canFire = false;
        how.angle = 0;
        how.point.x = 0;
        how.point.y = 0;
        // exercise
        how.setAngle(45);
        // verify
        assert(how.angle == 45);
    }  // teardown

    void setXPosition() const
    {
        // setup
        Howitzer how;
        how.canFire = false;
        how.angle = 0;
        how.point.x = 0;
        how.point.y = 0;
        // exercise
        how.setXPosition(5);
        // verify
        assert(how.point.x == 5);
    }  // teardown

    void setYPosition() const
    {
        // setup
        Howitzer how;
        how.canFire = false;
        how.angle = 0;
        how.point.x = 0;
        how.point.y = 0;
        // exercise
        how.setYPosition(5);
        // verify
        assert(how.point.y == 5);
    }  // teardown

    void getAngle() const
    {
        // setup
        Howitzer how;
        how.canFire = true;
        how.angle = 45;
        how.point.x = 5;
        how.point.y = 5;
        // exercise
        double angle = how.getAngle();
        // verify
        assert(angle == 45);
    }  // teardown

    void getXPosition() const
    {
        // setup
        Howitzer how;
        how.canFire = true;
        how.angle = 45;
        how.point.x = 5;
        how.point.y = 5;
        // exercise
        double xPos = how.getXPosition();
        // verify
        assert(xPos == 5);
    }  // teardown

    void getYPosition() const
    {
        // setup
        Howitzer how;
        how.canFire = true;
        how.angle = 45;
        how.point.x = 5;
        how.point.y = 5;
        // exercise
        double yPos = how.getYPosition();
        // verify
        assert(yPos == 5);
    }  // teardown
    
};
