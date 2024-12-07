// Find the root of equation 3*x + sinx - e^(-x)
#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

double f(double x) {
    return 3 * x + sin(x) - exp(-x);
}

int main() {
    double x1, x2, x3, fx1, fx2, err, den, num;

    // Input
    cout << "Enter the initial guesses:" << endl;
    cout << "X1: ";
    cin >> x1;
    cout << "X2: ";
    cin >> x2;
    cout << "Accuracy: ";
    cin >> err;

    // Secant Method
    cout << fixed << setprecision(6); // Format output to 6 decimal places
    do {
        fx1 = f(x1);
        fx2 = f(x2);

        // Check for division by zero
        den = fx2 - fx1;
        if (fabs(den) < 1e-12) {
            cout << "Denominator is too small, cannot proceed!" << endl;
            return -1;
        }

        // Secant formula
        x3 = x2 - (fx2 * (x2 - x1)) / den;

        // Update values for the next iteration
        x1 = x2;
        x2 = x3;

    } while (fabs(fx2) > err); // Stopping condition

    // Output result
    cout << "Root is: " << x3 << endl;

    return 0;
}