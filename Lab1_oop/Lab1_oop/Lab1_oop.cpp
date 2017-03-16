// Lab1_oop.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include "Triangle.h"
#include <iomanip>
#include <iostream>
using namespace std;

const char *triangleType1 = "Type1";
const char *triangleType2 = "Type2";
const char *triangleType3 = "Type3";

const int anglesCount = 3;

const double PI = 3.14;

void writeInfo(Triangle *triangle, ostream *stream);
const char* triangleTextType(Triangle *triangle);
char* anglesString(Triangle *triangle);
Triangle** readTrianglesFromConsole(int num);

int main()
{
	int num = 0;
	cout << "Input count of triangles: ";
	cin >> num;

	Triangle** triangles = readTrianglesFromConsole(num);

	while (true) {
		int index = 0;

		cout << "Input triangle's index: ";
		cin >> index;
		
		index--;

		if (index < 0 || index >= num) {
			cout << "Wrong index!";
			continue;
		}

		char *command = new char[256]{ NULL };
		cout << "Input command:" << endl
			<< "M - maximizing angle" << endl
			<< "T - determine type" << endl
			<< "D - distance between centers" << endl
			<< "A - determine angles" << endl
			<< "I - info about triangle" << endl;
		cin.getline(command, 255);
		
		if (strcmp(command, "M") == 0) {
			int percent = 0;
			
			cout << "Input desired percentage: ";
			cin >> percent;

			triangles[index]->increaseAngle(percent);
		} 
		else if (strcmp(command, "T") == 0) {
			cout << triangleTextType(triangles[index]) << endl;
		} 
		else if (strcmp(command, "D") == 0) {
			cout << "Distance between centers = "
				<< fixed << setprecision(3)
				<< triangles[index]->calculateLengthBetweenCenters() << endl;
		} 
		else if (strcmp(command, "A") == 0) {
			cout << anglesString(triangles[index]);
		}
		else if (strcmp(command, "I") == 0) {
			writeInfo(triangles[index], &cout);
		}
		else {
			cout << "Incorrect command!";
		}

		delete command;
	}

	return 0;
}

void writeInfo(Triangle *triangle, ostream *stream) {
	*stream << "Info about triangle";

	*stream << "Side 1 = " << triangle->side1 << endl;
	*stream << "Side 2 = " << triangle->side2 << endl;
	*stream << "Angle in degrees = " << triangle->angle / PI * 180 << endl;
}

const char* triangleTextType(Triangle *triangle) {
	int res = triangle->determineType();

	switch (res)
	{
	case 1:
		return triangleType1;
	case 2:
		return triangleType2;
	case 3:
		return triangleType3;
	}
}

char* anglesString(Triangle *triangle) {
	int *angles = triangle->getAngles();
	char *str = new char[256]{ NULL };

	for (int i = 0; i < anglesCount; i++) {
		strcat(str, "angle = ");
		strcat(str, itoa(i, NULL, 10));
		strcat(str, itoa(angles[i], NULL, 10));
		strcat(str, "degrees ");
	}
	
	return str;
}

Triangle** readTrianglesFromConsole(int num) {
	

	Triangle **result = new Triangle*[num];

	for (int i = 0; i < num; i++) {
		double side1 = 0,
			side2 = 0,
			angle = 0;

		cout << "Input first side: ";
		cin >> side1;
		cout << "Input second side: ";
		cin >> side2;
		cout << "Input angle (degrees) between them: ";
		cin >> angle;

		result[i] = new Triangle(angle * PI / 180, side1, side2);
	}

	return result;
}


