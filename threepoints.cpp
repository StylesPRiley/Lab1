/*
    Title: Lab 1: threepoints.cpp
    Purpose: Read three coordinates and determine if they form a line or triangle.
    Author: Riley Pleas
    Date: October 27 1019
*/
#include <iostream>
#include <cmath>
#include <math.h>
#include <iomanip>

using std::cout;
using std::cin;
using std::endl;
using std::fixed;

int main() {

    const double PI = 3.14159265;
    double x1, y1, x2, y2, x3, y3, area, distance1, distance2, distance3, s, slope;

    cout << "Enter the value for x1: " << endl;
    cin >> x1;
    cout << "Enter the value for y1: " << endl;
    cin >> y1;
    cout << "Enter the value for x2: " << endl;
    cin >> x2;
    cout << "Enter the value for y2: " << endl;
    cin >> y2;
    cout << "Enter the value for x3: " << endl;
    cin >> x3;
    cout << "Enter the value for y3: " << endl;
    cin >> y3;
//Use the distance formula to find the distance between the coordinates
    distance1 = sqrt((x2 - x1) * (x2 - x1) + ((y2 - y1) * (y2 - y1)));
    distance2 = sqrt((x3 - x2) * (x3 - x2) + ((y3 - y2) * (y3 - y2)));
    distance3 = sqrt((x3 - x1) * (x3 - x1) + ((y3 - y1) * (y3 - y1)));

    s = (distance1 + distance2 + distance3) / 2;
    area = sqrt(s * (s - distance1) * (s - distance2) * (s - distance3));

    double perimeter = (distance1 + distance2 + distance3);
    double angle1, angle2, angle3;
    double angleDegrees1, angleDegrees2, angleDegrees3;

//Law of cosines is used to find the internal angles of the triangle
    angle1 = acos(((distance2 * distance2) + (distance3 * distance3) - (distance1 * distance1)) /
                  (2 * distance2 * distance3));
    angle2 = acos(((distance1 * distance1) + (distance3 * distance3) - (distance2 * distance2)) /
                  (2 * distance1 * distance3));
    angle3 = acos(((distance1 * distance1) + (distance2 * distance2) - (distance3 * distance3)) /
            (2 * distance1 * distance2));
//Convert radians to degrees
    angleDegrees1 = angle1 * 180/PI;
    angleDegrees2 = angle2 * 180/PI;
    angleDegrees3 = angle3 * 180/PI;

    cout << "Input Point 1: " << x1 << " " << y1 << endl;
    cout << "Input Point 2: " << x2 << " " << y2 << endl;
    cout << "Input Point 3: " << x3 << " " << y3 << endl;

    //end program if a vertical line is found
    if ((x1 == x2) || (x1 == x3) || (x2 == x3)){
        cout << "Infinite Slope" << endl;
        return 0;
    }
//if it's a triangle this should be the output
    if (area > 0) {
        cout << "A Triangle" << endl;

        cout << "Sides: " << endl;
        cout << std::setprecision(2) << fixed << distance1 << endl;
        cout << distance2 << endl;
        cout << distance3 << endl;

        cout << "Angles in Radians: " << endl;
        cout << std::setprecision(2) << fixed << angle1 << endl;
        cout << angle2 << endl;
        cout << angle3 << endl;

        cout << "Angles in Degrees: " << endl;
        cout << std::setprecision(2) << fixed << angleDegrees1 << endl;
        cout << angleDegrees2 << endl;
        cout << angleDegrees3 << endl;

        cout << "Perimeter:  " << perimeter << endl;
        cout << "Area:       " << std::setprecision(2) << fixed << area << endl;
//if it's not a triangle it's a straight line...
    } else if (area == 0) {
        cout << "A Line" << endl;
        cout << "Slope:  " << std::setprecision(2) << fixed << ((y3 - y1) / (x3 - x1)) << endl;

        if ((distance1 >= distance2) && (distance1 >= distance3)) {

            cout << "Length: " << distance1 << endl;

        } else if ((distance2 >= distance1) && (distance2 >= distance3)) {
            cout << "Length: " << distance2 << endl;

        } else if ((distance3 >= distance2) && (distance3 >= distance1)) {

            cout << "Length: " << distance3 << endl;
        }


        return 0;
    }
}

