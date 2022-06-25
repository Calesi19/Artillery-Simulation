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
        // Test canFire() function
        falseCanFire();
        trueCanFire();

        // Test toggleCanFire
        toggleCanFire1();
        toggleCanFire2();

        // Test fireProjectile
        invalidFireProjectile();
        validFireProjectile();

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

    Howitzer setup_howitzerReadyToFire() const
    {
        // setup fixture
        Howitzer how;
        how.canFire = true;
        how.angle = 45;
        how.position.x = 5;
        how.position.y = 5;

        return how;
    }

    Howitzer setup_howitzerNotReadyToFire() const
    {
        // setup fixture
        Howitzer how;
        how.canFire = false;
        how.angle = 45;
        how.position.x = 5;
        how.position.y = 5;

        return how;
    }

    Howitzer setup_howitzerEmptyVariables() const
    {
        // setup fixture
        Howitzer how;
        how.canFire = false;
        how.angle = 0;
        how.position.x = 0;
        how.position.y = 0;

        return how;
    }

    void falseCanFire() const
    {   // setup
        Howitzer how = setup_howitzerNotReadyToFire();
        // exercise
        result = how.canFire();
        // verify
        assert(result == false);
    }  // teardown

    void trueCanFire() const
    {   // setup
        Howitzer how = setup_howitzerReadyToFire();
        // exercise
        result = how.canFire();
        // verify
        assert(result == true);
    }  // teardown
    
    void toggleCanFire1() const
    {   // setup
        Howitzer how = setup_howitzerReadyToFire();
        // exercise
        how.toggleCanFire();
        // verify
        assert(how.canFire == false);
    }  // teardown

    void toggleCanFire2() const
    {   // setup
        Howitzer how = setup_howitzerNotReadyToFire();
        // exercise
        how.toggleCanFire();
        // verify
        assert(how.canFire == true);
    }  // teardown

    void invalidFireProjectile() const
    {
        // setup
        Howitzer how = setup_howitzerNotReadyToFire();
        // exercise
        how.fireProjectile();
        // verify
        assert(how.canFire == false);
        assert(how.angle == 45);
        assert(how.projectile == NULL)
    }  // teardown

    void validFireProjectile() const
    {
        // setup
        Howitzer how = setup_howitzerReadyToFire();
        // exercise
        how.fireProjectile();
        // verify
        assert(how.canFire == false);
        assert(how.angle == 45);
        assert(how.projectile != NULL)
    }  // teardown

    void setAngle() const
    {
        // setup
        Howitzer how = setup_howitzerEmptyVariables();
        // exercise
        how.setAngle(45);
        // verify
        assert(how.angle == 45);
    }  // teardown

    void setXPosition() const
    {
        // setup
        Howitzer how = setup_howitzerEmptyVariables();
        // exercise
        how.setXPosition(5);
        // verify
        assert(how.position.x == 5);
    }  // teardown

    void setYPosition() const
    {
        // setup
        Howitzer how = setup_howitzerEmptyVariables();
        // exercise
        how.setYPosition(5);
        // verify
        assert(how.position.Y == 5);
    }  // teardown

    void getAngle() const
    {
        // setup
        Howitzer how = setup_howitzerReadyToFire();
        // exercise
        angle = how.getAngle()
        // verify
        assert(angle == 45);
    }  // teardown

    void getXPosition() const
    {
        // setup
        Howitzer how = setup_howitzerReadyToFire();
        // exercise
        xPos = how.getPosition();
        // verify
        assert(xPos == 5);
    }  // teardown

    void getYPosition() const
    {
        // setup
        Howitzer how = setup_howitzerReadyToFire();
        // exercise
        yPos = how.getYPosition();
        // verify
        assert(yPos == 5);
    }  // teardown
    
};
