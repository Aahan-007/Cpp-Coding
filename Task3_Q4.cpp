#include <iostream>
#include <iomanip>
using namespace std;

// Multiplies reading by a calibration factor
template <typename T>
T calibrateValue(T x, char factor) {
    return x * factor;
}

// Increases reading by an offset (default = 1.25)
void adjustReading(double* value, double offset = 1.25) {
    *value += offset;
}

// Keeps reading within 0–100
void clampReading(double &v) {
    if (v > 100) v = 100;
    if (v < 0)   v = 0;
}

// Returns difference (int minus double)
double computeDifference(int a, double b) {
    return a - b;
}

int main() {

    int intSensor;
    double doubleSensor;

    // Input
    cout << "Enter integer sensor reading: ";
    cin >> intSensor;
    cout << "Enter double sensor reading: ";
    cin >> doubleSensor;

    // (ii) multiply both values by factor = 2
    intSensor = calibrateValue(intSensor, 2);
    doubleSensor = calibrateValue(doubleSensor, 2);

    cout << "\nCalibrated Values:\n";
    cout << setw(10) << fixed << setprecision(4) << intSensor << endl;
    cout << setw(10) << fixed << setprecision(4) << doubleSensor << endl;

    // (iii) convert int → double
    double intAsDouble = (double)intSensor;

    // (iv) adjust values
    adjustReading(&intAsDouble);          // uses default 1.25
    adjustReading(&doubleSensor, 3.4);    // custom offset

    cout << "\nAfter Adjustment:\n";
    cout << setw(10) << intAsDouble << endl;
    cout << setw(10) << doubleSensor << endl;

    // (v) clamp both to 0–100
    clampReading(intAsDouble);
    clampReading(doubleSensor);

    cout << "\nAfter Clamping:\n";
    cout << setw(10) << intAsDouble << endl;
    cout << setw(10) << doubleSensor << endl;

    // (vi) convert adjusted double back to int
    int finalValue = (int)intAsDouble;
    cout << "\nConverted back to integer: "
         << setw(10) << finalValue << endl;

    // (vii) compute difference
    double diff = computeDifference(finalValue, doubleSensor);

    cout << "\nDifference (int - double): "
         << setw(10) << fixed << setprecision(4) << diff << endl;

    return 0;
}
