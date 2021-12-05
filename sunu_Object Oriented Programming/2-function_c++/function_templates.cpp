
// Function template maximum test program.
#include <iostream>
//#include "maximum.h" // include definition of function template maximum

template <typename T>  // or template<class T>      
T maximum(T value1, T value2, T value3) {
    T maximumValue{ value1 }; // assume value1 is maximum    

    // determine whether value2 is greater than maximumValue
    if (value2 > maximumValue) {
        maximumValue = value2;
    }

    // determine whether value3 is greater than maximumValue
    if (value3 > maximumValue) {
        maximumValue = value3;
    }

    return maximumValue;
}

using namespace std;

int main() {
    // demonstrate maximum with int values
    cout << "Input three integer values: ";
    int int1, int2, int3;
    cin >> int1 >> int2 >> int3;

    // invoke int version of maximum
    cout << "The maximum integer value is: "
        << maximum(int1, int2, int3);

    // demonstrate maximum with double values
    cout << "\n\nInput three double values: ";
    double double1, double2, double3;
    cin >> double1 >> double2 >> double3;

    // invoke double version of maximum
    cout << "The maximum double value is: "
        << maximum(double1, double2, double3);

    // demonstrate maximum with char values
    cout << "\n\nInput three characters: ";
    char char1, char2, char3;
    cin >> char1 >> char2 >> char3;

    // invoke char version of maximum
    cout << "The maximum character value is: "
        << maximum(char1, char2, char3) << endl;
} // end main// Function template maximum header.
