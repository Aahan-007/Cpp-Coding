#include <iostream>
#include <iomanip>
using namespace std;

// Multiplies reading by calibration factor (template function with const reference)
template <typename T>
T calibrateValue(const T &x, char factor) {
    return x * factor;
}

// Adjusts sensor reading using pointer (default offset = 1.25)
void adjustReading(double* value, double offset = 1.25) {
    *value += offset;
}

// Clamps sensor reading between 0 and 100
void clampReading(double &v) {
    if (v > 100) v = 100;
    if (v < 0)   v = 0;
}

// Returns difference between integer and double reading
double computeDifference(int a, double b) {
    return a - b;
}

int main() {

    int intSensor;
    double doubleSensor;

    // Take user input for both sensors
    cout << "Enter integer sensor reading: ";
    cin >> intSensor;
    cout << "Enter double sensor reading: ";
    cin >> doubleSensor;

    // Calibrate both readings by factor = 2
    intSensor    = calibrateValue(intSensor, 2);
    doubleSensor = calibrateValue(doubleSensor, 2);

    cout << "\nCalibrated Values:\n";
    cout << setw(10) << fixed << setprecision(4) << intSensor << endl;
    cout << setw(10) << fixed << setprecision(4) << doubleSensor << endl;

    // Convert integer to double
    double intAsDouble = (double)intSensor;

    // Adjust readings: one with default offset, one with custom offset
    adjustReading(&intAsDouble);
    adjustReading(&doubleSensor, 3.4);

    cout << "\nAfter Adjustment:\n";
    cout << setw(10) << intAsDouble << endl;
    cout << setw(10) << doubleSensor << endl;

    // Clamp both values within range 0–100
    clampReading(intAsDouble);
    clampReading(doubleSensor);

    cout << "\nAfter Clamping:\n";
    cout << setw(10) << intAsDouble << endl;
    cout << setw(10) << doubleSensor << endl;

    // Convert double sensor reading back to int
    int finalValue = (int)intAsDouble;
    cout << "\nConverted back to integer: "
         << setw(10) << finalValue << endl;

    // Compute and print the difference
    double diff = computeDifference(finalValue, doubleSensor);

    cout << "\nDifference (int - double): "
         << setw(10) << fixed << setprecision(4) << diff << endl;

    return 0;
}
