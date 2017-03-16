#pragma once
#include <fstream>
class Triangle
{
private:
	const double epsilan = 0.001;
	const double PI = 3.14;

	double calculateThirdSide();
	double calculateBigRadius();
	double calculateSmallRadius();
public:
	double angle;
	double side1, side2;

	void increaseAngle(int percentage);
	// 1 - for 3 different sides
	// 2 - for 2 equal sides
	// 3 - for all equal sides
	int determineType();
	// return array with 3 elements - angles
	int* getAngles();
	double calculateLengthBetweenCenters();

	Triangle(double angle, double side1, double side2);
};

