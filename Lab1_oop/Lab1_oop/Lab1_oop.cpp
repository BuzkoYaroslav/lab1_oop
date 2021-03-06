// Lab1_oop.cpp: ���������� ����� ����� ��� ����������� ����������.
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

		char *comand = new char[256]{ NULL };
		cout << "Input command: "
			<< "M - maximizing angle "
			<< "T - determine type "
			<< "D - distance between centers "
			<< "A - determine angles "
			<< "I - info about triangle\n";
		cin >> comand;
		
		if (strcmp(comand, "M") == 0) {
			int percent = 0;
			
			cout << "Input desired percentage: ";
			cin >> percent;

			triangles[index]->increaseAngle(percent);
		} 
		else if (strcmp(comand, "T") == 0) {
			cout << triangleTextType(triangles[index]) << endl;
		} 
		else if (strcmp(comand, "D") == 0) {
			cout << "Distance between centers = "
				<< fixed << setprecision(3)
				<< triangles[index]->calculateLengthBetweenCenters() << endl;
		} 
		else if (strcmp(comand, "A") == 0) {
			cout << anglesString(triangles[index]) << endl;
		}
		else if (strcmp(comand, "I") == 0) {
			writeInfo(triangles[index], &cout);
		}
		else {
			cout << "Incorrect command!";
		}

		delete comand;
	}

	return 0;
}

void writeInfo(Triangle *triangle, ostream *stream) {
	*stream << "Info about triangle\n";

	*stream << "Side 1 = " << triangle->side1 << endl;
	*stream << "Side 2 = " << triangle->side2 << endl;
	*stream << "Angle in degrees = " << Triangle::radiansToDegrees(triangle->angle) << endl;
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
		char *strAngle = new char[3]{ NULL };

		itoa(angles[i], strAngle, 10);

		strcat(str, "angle = ");
		strcat(str, strAngle);
		strcat(str, " degrees, ");

		delete strAngle;
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

		result[i] = new Triangle(angle, side1, side2);
	}

	return result;
}


