#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

// Addition Class
class Addition {
public:
    double add(double a, double b) {
        return a + b;
    }
};

// Subtraction Class
class Subtraction {
public:
    double subtract(double a, double b) {
        return a - b;
    }
};

// Multiplication Class
class Multiplication {
public:
    double multiply(double a, double b) {
        return a * b;
    }
};

// Division Class
class Division {
public:
    double divide(double a, double b) {
        if (b != 0) {
            return a / b;
        } else {
            cout << "Error! Division by zero." << endl;
            return NAN;
        }
    }
};

// Modulus Class
class Modulus {
public:
    double modulus(double a, double b) {
        return fmod(a, b);
    }
};

// Logarithm Class
class Logarithm {
public:
    double logarithm(double a) {
        if (a > 0) {
            return log(a);
        } else {
            cout << "Error! Logarithm of non-positive number." << endl;
            return NAN;
        }
    }
};

// Trigonometric Functions Classes
class Sine {
public:
    double sine(double a) {
        return sin(a);
    }
};

class Cosine {
public:
    double cosine(double a) {
        return cos(a);
    }
};

class Tangent {
public:
    double tangent(double a) {
        return tan(a);
    }
};

// Power and Roots Classes
class Power {
public:
    double power(double a, double b) {
        return pow(a, b);
    }
};

class Square {
public:
    double square(double a) {
        return a * a;
    }
};

class Cube {
public:
    double cube(double a) {
        return a * a * a;
    }
};

class SquareRoot {
public:
    double squareRoot(double a) {
        if (a >= 0) {
            return sqrt(a);
        } else {
            cout << "Error! Square root of a negative number." << endl;
            return NAN;
        }
    }
};

class CubeRoot {
public:
    double cubeRoot(double a) {
        return cbrt(a);
    }
};

// Quadratic Solver Class
class QuadraticSolver {
public:
    pair<double, double> solve(double a, double b, double c) {
        double discriminant = b * b - 4 * a * c;
        if (discriminant >= 0) {
            double root1 = (-b + sqrt(discriminant)) / (2 * a);
            double root2 = (-b - sqrt(discriminant)) / (2 * a);
            return make_pair(root1, root2);
        } else {
            cout << "Complex roots: ";
            double realPart = -b / (2 * a);
            double imaginaryPart = sqrt(-discriminant) / (2 * a);
            return make_pair(realPart, imaginaryPart);
        }
    }
};

// Cartesian to Polar Conversion Class
class CartesianToPolar {
public:
    pair<double, double> convert(double x, double y) {
        double r = sqrt(x * x + y * y);
        double theta = atan2(y, x);
        return make_pair(r, theta);
    }
};

// Polar to Cartesian Conversion Class
class PolarToCartesian {
public:
    pair<double, double> convert(double r, double theta) {
        double x = r * cos(theta);
        double y = r * sin(theta);
        return make_pair(x, y);
    }
};

// Factorial Class
class Factorial {
public:
    double factorial(int n) {
        if (n == 0 || n == 1) {
            return 1;
        }
        return n * factorial(n - 1);
    }
};

// Permutation Class
class Permutation {
public:
    double permutation(int n, int r) {
        Factorial fact;
        return fact.factorial(n) / fact.factorial(n - r);
    }
};

// Combination Class
class Combination {
public:
    double combination(int n, int r) {
        Factorial fact;
        return fact.factorial(n) / (fact.factorial(r) * fact.factorial(n - r));
    }
};

// Matrix Operations Class
class MatrixOperations {
public:
    void addMatrices(int matrix1[2][2], int matrix2[2][2], int result[2][2]) {
        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < 2; j++) {
                result[i][j] = matrix1[i][j] + matrix2[i][j];
            }
        }
    }

    void subtractMatrices(int matrix1[2][2], int matrix2[2][2], int result[2][2]) {
        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < 2; j++) {
                result[i][j] = matrix1[i][j] - matrix2[i][j];
            }
        }
    }

    void multiplyMatrices(int matrix1[2][2], int matrix2[2][2], int result[2][2]) {
        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < 2; j++) {
                result[i][j] = 0;
                for (int k = 0; k < 2; k++) {
                    result[i][j] += matrix1[i][k] * matrix2[k][j];
                }
            }
        }
    }

    int determinant(int matrix[2][2]) {
        return matrix[0][0] * matrix[1][1] - matrix[0][1] * matrix[1][0];
    }
};

// Scientific Calculator Class
class ScientificCalculator {
public:
    void run();

private:
    void showCalculator();
    void displayOutput(double answer1, double answer2 = 0);
    void clearScreen();
    void handleOperation(char operation);

    double num1, num2, answer1, answer2;
    char operation;
};

void ScientificCalculator::showCalculator() {
    cout << "--------------------------------------------------------------------------------------" << endl;
    cout << "-                                            SCIENTIFIC                               -" << endl;
    cout << "---                                          CALCULATOR                            --- " << endl;
    cout << "-                                                                                     -" << endl;
    cout << "----------------------------------------------------------------------------------------" << endl;
    cout << "-        +               |             -             |           *                      -" << endl;
    cout << "-       Add              |          Subtract         |         Multiply                 -" << endl;
    cout << "----------------------------------------------------------------------------------------" << endl;
    cout << "-        /               |             m             |           L                     -" << endl;
    cout << "-     Divide            |            Mod            |          Log                    -" << endl;
    cout << "----------------------------------------------------------------------------------------" << endl;
    cout << "-        s               |             c             |           t                     -" << endl;
    cout << "-       sin              |            cos            |          tan                    -" << endl;
    cout << "----------------------------------------------------------------------------------------" << endl;
    cout << "-        S               |              C            |           p                      -" << endl;
    cout << "-      Square            |             Cube          |         Power                     -" << endl;
    cout << "----------------------------------------------------------------------------------------" << endl;
    cout << "-        r               |             k             |           .                      -" << endl;
    cout << "-     sq root            |          Clear           |         Close                    -" << endl;
    cout << "----------------------------------------------------------------------------------------" << endl;
    cout << "-        q               |             P             |           A                      -" << endl;
    cout << "-     Quadratic Solver   |  Polar to Cartesian    |  Cartesian to Polar             -" << endl;
    cout << "----------------------------------------------------------------------------------------" << endl;
    cout << "-        Z               |             z             |           d                      -" << endl;
    cout << "-     Permutations       |  Combinations          |  Determinant                   -" << endl;
    cout << "----------------------------------------------------------------------------------------" << endl;
}

void ScientificCalculator::displayOutput(double answer1, double answer2) {
    cout << "--------------------------------------------------------------------------------------" << endl;
    cout << "------                                                                ----------------" << endl;
    cout << "---                                           current                 |        " << endl;
    cout << "-                                             output is:              | " << fixed << setprecision(2) << answer1;
    if (answer2 != 0) {
        cout << ", " << fixed << setprecision(2) << answer2;
    }
    cout << endl;
    cout << "---                                                                    -----------------" << endl;
    cout << "----------------------------------------------------------------------------------------" << endl;
    showCalculator(); // Show the calculator menu again
}

void ScientificCalculator::clearScreen() {
    system("cls"); // Clear the screen (works on Windows)
}

void ScientificCalculator::handleOperation(char operation) {
    switch (operation) {
        case '+': {
            Addition addObj;
            answer1 = addObj.add(num1, num2);
            break;
        }
        case '-': {
            Subtraction subObj;
            answer1 = subObj.subtract(num1, num2);
            break;
        }
        case '*': {
            Multiplication mulObj;
            answer1 = mulObj.multiply(num1, num2);
            break;
        }
        case '/': {
            Division divObj;
            answer1 = divObj.divide(num1, num2);
            break;
        }
        case 'm': {
            Modulus modObj;
            answer1 = modObj.modulus(num1, num2);
            break;
        }
        case 'L': {
            Logarithm logObj;
            answer1 = logObj.logarithm(num1);
            break;
        }
        case 's': {
            Sine sinObj;
            answer1 = sinObj.sine(num1);
            break;
        }
        case 'c': {
            Cosine cosObj;
            answer1 = cosObj.cosine(num1);
            break;
        }
        case 't': {
            Tangent tanObj;
            answer1 = tanObj.tangent(num1);
            break;
        }
        case 'S': {
            Square sqObj;
            answer1 = sqObj.square(num1);
            break;
        }
        case 'C': {
            Cube cubeObj;
            answer1 = cubeObj.cube(num1);
            break;
        }
        case 'p': {
            Power powerObj;
            answer1 = powerObj.power(num1, num2);
            break;
        }
        case 'r': {
            SquareRoot sqrtObj;
            answer1 = sqrtObj.squareRoot(num1);
            break;
        }
        case 'q': {
            QuadraticSolver quadSolverObj;
            tie(answer1, answer2) = quadSolverObj.solve(num1, num2, answer1); // For Quadratic Solver
            break;
        }
        case 'A': {
            CartesianToPolar cartesianToPolarObj;
            tie(answer1, answer2) = cartesianToPolarObj.convert(num1, num2); // For Cartesian to Polar Conversion
            break;
        }
        case 'P': {
            PolarToCartesian polarToCartesianObj;
            tie(answer1, answer2) = polarToCartesianObj.convert(num1, num2); // For Polar to Cartesian Conversion
            break;
        }
        case 'Z': {
            Permutation permObj;
            answer1 = permObj.permutation(static_cast<int>(num1), static_cast<int>(num2)); // For Permutation
            break;
        }
        case 'z': {
            Combination combObj;
            answer1 = combObj.combination(static_cast<int>(num1), static_cast<int>(num2)); // For Combination
            break;
        }
        case 'd': {
            MatrixOperations matOpObj;
            int matrix[2][2] = {{static_cast<int>(num1), static_cast<int>(num2)}, {static_cast<int>(answer1), static_cast<int>(answer2)}};
            answer1 = matOpObj.determinant(matrix); // For Matrix Determinant
            break;
        }
        case 'k': {
            clearScreen(); // Clear the screen and show the menu again
            showCalculator();
            break;
        }
        case '.': {
            exit(0); // Exit the program
        }
        default: {
            cout << "Invalid Operation!" << endl;
        }
    }
    displayOutput(answer1, answer2); // Display the result after performing the operation
}

void ScientificCalculator::run() {
    showCalculator();
    while (true) {
        cout << "Enter operation: ";
        cin >> operation;
        if (operation == '.' || operation == 'k') {
            handleOperation(operation);
            continue; // Skip the number inputs if the operation is '.' or 'k'
        }

        cout << "Enter first number: ";
        cin >> num1;

        if (operation != 'L' && operation != 's' && operation != 'c' && operation != 't' && operation != 'S' && operation != 'C' && operation != 'r') {
            cout << "Enter second number: ";
            cin >> num2;
        }

        handleOperation(operation);
    }
}

int main() {
    ScientificCalculator calculator;
    calculator.run();
    return 0;
}
