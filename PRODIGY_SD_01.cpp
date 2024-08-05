/*  Coder : Ankit Kumar 
 Task 1 - Build a c++ user driven program of temperature conversion program . 
*/

#include <iostream>
using namespace std;

// Function prototypes for Temperature program
double celsiusToFahrenheit(double celsius);
double celsiusToKelvin(double celsius);
double fahrenheitToCelsius(double fahrenheit);
double fahrenheitToKelvin(double fahrenheit);
double kelvinToCelsius(double kelvin);
double kelvinToFahrenheit(double kelvin);

int main() {
    int choice1, choice2;
    double temperature, convertedTemperature1, convertedTemperature2;

    cout << "Temperature Conversion Program\n";
    cout << "Select the temperature scale you want to convert from:\n";
    cout << "1. Celsius\n";
    cout << "2. Fahrenheit\n";
    cout << "3. Kelvin\n";
    cout << "Enter your choice (1-3): ";
    cin >> choice1;

    cout << "Select the temperature scale you want to convert to (you can choose two different scales):\n";
    cout << "1. Celsius\n";
    cout << "2. Fahrenheit\n";
    cout << "3. Kelvin\n";
    cout << "Enter your first choice (1-3): ";
    cin >> choice2;

    if (choice1 == choice2) {
        cout << "The same scale selected for conversion. Please choose different scales.\n";
        return 0;
    }

    cout << "Enter the temperature to convert: ";
    cin >> temperature;

    switch (choice1) {
        case 1: // Celsius
            if (choice2 == 2) {
                convertedTemperature1 = celsiusToFahrenheit(temperature);
                cout << "Converted temperature in Fahrenheit: " << convertedTemperature1 << " °F\n";
                convertedTemperature2 = celsiusToKelvin(temperature);
                cout << "Converted temperature in Kelvin: " << convertedTemperature2 << " K\n";
            } else {
                convertedTemperature1 = celsiusToKelvin(temperature);
                cout << "Converted temperature in Kelvin: " << convertedTemperature1 << " K\n";
                convertedTemperature2 = celsiusToFahrenheit(temperature);
                cout << "Converted temperature in Fahrenheit: " << convertedTemperature2 << " °F\n";
            }
            break;
        case 2: // Fahrenheit
            if (choice2 == 1) {
                convertedTemperature1 = fahrenheitToCelsius(temperature);
                cout << "Converted temperature in Celsius: " << convertedTemperature1 << " °C\n";
                convertedTemperature2 = fahrenheitToKelvin(temperature);
                cout << "Converted temperature in Kelvin: " << convertedTemperature2 << " K\n";
            } else {
                convertedTemperature1 = fahrenheitToKelvin(temperature);
                cout << "Converted temperature in Kelvin: " << convertedTemperature1 << " K\n";
                convertedTemperature2 = fahrenheitToCelsius(temperature);
                cout << "Converted temperature in Celsius: " << convertedTemperature2 << " °C\n";
            }
            break;
        case 3: // Kelvin
            if (choice2 == 1) {
                convertedTemperature1 = kelvinToCelsius(temperature);
                cout << "Converted temperature in Celsius: " << convertedTemperature1 << " °C\n";
                convertedTemperature2 = kelvinToFahrenheit(temperature);
                cout << "Converted temperature in Fahrenheit: " << convertedTemperature2 << " °F\n";
            } else {
                convertedTemperature1 = kelvinToFahrenheit(temperature);
                cout << "Converted temperature in Fahrenheit: " << convertedTemperature1 << " °F\n";
                convertedTemperature2 = kelvinToCelsius(temperature);
                cout << "Converted temperature in Celsius: " << convertedTemperature2 << " °C\n";
            }
            break;
        default:
            cout << "Invalid choice!\n";
            break;
    }

    return 0;
}

// Function definitions
double celsiusToFahrenheit(double celsius) {
    return (celsius * 9/5) + 32;
}

double celsiusToKelvin(double celsius) {
    return celsius + 273.15;
}

double fahrenheitToCelsius(double fahrenheit) {
    return (fahrenheit - 32) * 5/9;
}

double fahrenheitToKelvin(double fahrenheit) {
    return (fahrenheit - 32) * 5/9 + 273.15;
}

double kelvinToCelsius(double kelvin) {
    return kelvin - 273.15;
}

double kelvinToFahrenheit(double kelvin) {
    return (kelvin - 273.15) * 9/5 + 32;
}
