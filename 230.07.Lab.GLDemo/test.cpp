/***********************************************************************
 * Source File:
 *    Test : Test runner
 * Author:
 *    Br. Helfrich
 * Summary:
 *    The test runner for all the unit tests
 ************************************************************************/

#include "test.h"
#include "testPosition.h"
#include "testGround.h"
#include "test_projectile.cpp"
#include "testHowitzer.h"

/*****************************************************************
 * TEST RUNNER
 * Runs all the unit tests
 ****************************************************************/
void testRunner()
{
   TestPosition().run();
   TestGround().run();
   testProjectile().run();
   TestHowitzer().run();
   cout << "Tests completed";
}