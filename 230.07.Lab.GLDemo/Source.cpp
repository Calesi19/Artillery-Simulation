/*************************************************************
 * 1. Name:
 *      The Key
 * 2. Assignment Name:
 *      Lab 08: M777 Howitzer
 * 3. Assignment Description:
 *      Simulate firing the M777 howitzer 15mm artillery piece
 * 4. What was the hardest part? Be as specific as possible.
 *      ??
 * 5. How long did it take for you to complete the assignment?
 *      ??
 *****************************************************************/

#include <cassert>      // for ASSERT
#include "uiInteract.h" // for INTERFACE
#include "uiDraw.h"     // for RANDOM and DRAW*
#include "ground.h"     // for GROUND
#include "position.h"   // for POSITION
using namespace std;







int main() {

	double angle;
	double distance;
	double time;

	double speed = 827;   //m/s
	double weight = 46.7; //kg
	double diameter = 154.89; //mm
	cout << "What is the angle of the howitzer where 0 is up ? " << endl;
	cin >> angle;



	cout << "Distance : " << distance << "m     Hang Time : " << time << "s" << endl;




	return 0;
}