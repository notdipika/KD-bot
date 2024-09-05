#include <iostream>
#include <cmath>
#include <utility>
#include <bitset>
#include <iomanip>
using namespace std;
const string RESET = "\033[0m";
const string RED = "\033[31m";
const string GREEN = "\033[32m";
const string BOLD = "\033[1m";

class heroSection{
    public:

    void introCalculator() {
     cout << RED << BOLD << "\t\t---------------------------------------------------------------------------------------------------------------------"<< RESET  << endl;
     cout << RED << BOLD<< "\t\t-                                                                                                                  --"<< RESET << endl;
     cout << RED << BOLD<< "\t\t---                                             KDA Calculator                                                    ----"<< RESET << endl;                     
     cout << RED << BOLD<< "\t\t-                                      solve your math problem here...                                             --"<< RESET << endl;
     cout << RED << BOLD<< "\t\t---------------------------------------------------------------------------------------------------------------------"<< RESET  << endl;
     cout << GREEN << "\t\t-     +       |      -       |          *       |       /      |      %      |       p        |         !           |" << RESET << endl;
     cout << GREEN << "\t\t-    Add      |   Subtract   |       multiply   |     Divide   |     mod     |     power      |      factorial      |"<< RESET  << endl;
     cout << GREEN << "\t\t---------------------------------------------------------------------------------------------------------------------"<< RESET  << endl;
     cout << GREEN << "\t\t-     s       |      c       |          t       |        P     |      C      |        x       |         y           |"<< RESET  << endl;
     cout << GREEN << "\t\t-    sin      |     cos      |         tan      |       npr    |     ncr     |      c to p    |       p yo c        |"<< RESET  << endl;
     cout << GREEN << "\t\t---------------------------------------------------------------------------------------------------------------------" << RESET << endl;
     cout << GREEN << "\t\t-     z       |      M       |          1        |       q     |      2      |        3       |         B            |  " << RESET << endl;
     cout << GREEN << "\t\t-  complex    |   matrix     |       ax+b=0      | ax^2+bx+c=0 |  anx+bny=cn | anx+bny+cnz=dn |        Base          |" << RESET << endl;
     cout << GREEN << "\t\t---------------------------------------------------------------------------------------------------------------------" << RESET << endl;
     cout << GREEN << "\t\t-     4       |      5       |          6        |       L     |      l      |        k       |         .            | "<< RESET <<endl;
     cout << GREEN << "\t\t-    sin'1    |    cos'1     |        tan'1      |      log    |     ln      |      clear     |        close         | "<< RESET <<endl; 
     cout << GREEN << "\t\t-----------------------------------------------------------------------------------------------------------------------"<< RESET <<endl;          
        
    }
};
class Addition {
public:
    double calculate(double num1, double num2) {
        return num1 + num2;
    }
};

class Subtraction {
public:
    double calculate(double num1, double num2) {
        return num1 - num2;
    }
};

class Multiplication {
public:
    double calculate(double num1, double num2) {
        return num1 * num2;
    }
};

class Division {
public:
    double calculate(double num1, double num2) {
        if (num2 == 0) {
            cout << "Error: Division by zero." << endl;
            return 0;
        }
        return num1 / num2;
    }
};

class Modulus {
public:
    int calculate(int num1, int num2) {
        return num1 % num2;
    }
};

class Power {
public:
    double calculate(double base, double exponent) {
        return pow(base, exponent);
    }
};

class Sin {
public:
    double calculate(double num) {
        return sin(num);
    }
};

class Cos {
public:
    double calculate(double num) {
        return cos(num);
    }
};

class Tan {
public:
    double calculate(double num) {
        return tan(num);
    }
};

class Factorial {
public:
    long long factorial(int n) {
        if (n == 0 || n == 1) {
            return 1;
        }
        return n * factorial(n - 1);
    }
};

class Permutation {
public:
    double permutation(int n, int r) {
        Factorial fact;
        return fact.factorial(n) / fact.factorial(n - r);
    }
};

class Combination {
public:
    double combination(int n, int r) {
        Factorial fact;
        return fact.factorial(n) / (fact.factorial(r) * fact.factorial(n - r));
    }
};

class CartesianToPolar {
public:
    pair<double, double> convert(double x, double y) {
        double r = sqrt(x * x + y * y);
        double theta = atan2(y, x);
        return make_pair(r, theta);
    }
};

class PolarToCartesian {
public:
    pair<double, double> convert(double r, double theta) {
        double x = r * cos(theta);
        double y = r * sin(theta);
        return make_pair(x, y);
    }
};

class LinearEquation {
public:
    double solve(double a, double b) {
        if (a == 0) {
            cout << "No solution (a cannot be 0 in a linear equation)" << endl;
            return NAN;
        } else {
            return -b / a;
        }
    }
};

class QuadraticEquation {
public:
    void solve() {
        double a, b, c;
        cout << "Enter the value of a, b, and c: ";
        cin >> a >> b >> c;
        double discriminant = b * b - 4 * a * c;
        double sqrt_val = sqrt(fabs(discriminant));

        if (discriminant > 0) {
            double root1 = (-b + sqrt_val) / (2 * a);
            double root2 = (-b - sqrt_val) / (2 * a);
            cout << "Roots are real and different.\n";
            cout << "Root 1 = " << root1 << "\n";
            cout << "Root 2 = " << root2 << "\n";
        } else if (discriminant == 0) {
            double root = -b / (2 * a);
            cout << "Roots are real and the same.\n";
            cout << "Root 1 = Root 2 = " << root << "\n";
        } else {
            double realPart = -b / (2 * a);
            double imaginaryPart = sqrt_val / (2 * a);
            cout << "Roots are complex and different.\n";
            cout << "Root 1 = " << realPart << " + " << imaginaryPart << "i\n";
            cout << "Root 2 = " << realPart << " - " << imaginaryPart << "i\n";
        }
    }
};

class TwoVariableEquation {
public:
    void solve() {
        double a1, b1, c1, a2, b2, c2;
        cout << "Enter the coefficients a1, b1, c1 for the first equation: ";
        cin >> a1 >> b1 >> c1;
        cout << "Enter the coefficients a2, b2, c2 for the second equation: ";
        cin >> a2 >> b2 >> c2;

        double det = a1 * b2 - a2 * b1;
        if (det == 0) {
            cout << "No unique solution (determinant is 0)" << endl;
        } else {
            double x = (c1 * b2 - c2 * b1) / det;
            double y = (a1 * c2 - a2 * c1) / det;
            cout << "The values of x and y are: x = " << x << ", y = " << y << endl;
        }
    }
};

class ThreeVariableEquation {
public:
    void solve() {
        double a1, b1, c1, d1, a2, b2, c2, d2, a3, b3, c3, d3;
        cout << "Enter the coefficients a1, b1, c1, d1 for the first equation: ";
        cin >> a1 >> b1 >> c1 >> d1;
        cout << "Enter the coefficients a2, b2, c2, d2 for the second equation: ";
        cin >> a2 >> b2 >> c2 >> d2;
        cout << "Enter the coefficients a3, b3, c3, d3 for the third equation: ";
        cin >> a3 >> b3 >> c3 >> d3;

        double det = a1 * (b2 * c3 - b3 * c2) - b1 * (a2 * c3 - a3 * c2) + c1 * (a2 * b3 - a3 * b2);
        if (det == 0) {
            cout << "No unique solution (determinant is 0)" << endl;
        } else {
            double x = (d1 * (b2 * c3 - b3 * c2) - b1 * (d2 * c3 - d3 * c2) + c1 * (d2 * b3 - d3 * b2)) / det;
            double y = (a1 * (d2 * c3 - d3 * c2) - d1 * (a2 * c3 - a3 * c2) + c1 * (a2 * d3 - a3 * d2)) / det;
            double z = (a1 * (b2 * d3 - b3 * d2) - b1 * (a2 * d3 - a3 * d2) + d1 * (a2 * b3 - a3 * b2)) / det;
            cout << "The values of x, y, and z are: x = " << x << ", y = " << y << ", z = " << z << endl;
        }
    }
};

class MatrixOperations {
private:
    int matrix1_2x2[2][2];
    int matrix2_2x2[2][2];
    int result_2x2[2][2];

    int matrix1_3x3[3][3];
    int matrix2_3x3[3][3];
    int result_3x3[3][3];

public:
    void inputMatrix2x2(int matrix[2][2], const string& name) {
        cout << "Enter the elements of " << name << " (2x2):" << endl;
        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < 2; j++) {
                cout << "Element [" << i + 1 << "][" << j + 1 << "]: ";
                cin >> matrix[i][j];
            }
        }
    }

    void inputMatrix3x3(int matrix[3][3], const string& name) {
        cout << "Enter the elements of " << name << " (3x3):" << endl;
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                cout << "Element [" << i + 1 << "][" << j + 1 << "]: ";
                cin >> matrix[i][j];
            }
        }
    }

    void displayMatrix2x2(int matrix[2][2]) {
        cout << "Matrix:" << endl;
        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < 2; j++) {
                cout << matrix[i][j] << " ";
            }
            cout << endl;
        }
    }

    void displayMatrix3x3(int matrix[3][3]) {
        cout << "Matrix:" << endl;
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                cout << matrix[i][j] << " ";
            }
            cout << endl;
        }
    }

    void addMatrices2x2() {
        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < 2; j++) {
                result_2x2[i][j] = matrix1_2x2[i][j] + matrix2_2x2[i][j];
            }
        }
        cout << "Sum of matrices (2x2):" << endl;
        displayMatrix2x2(result_2x2);
    }

    void subtractMatrices2x2() {
        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < 2; j++) {
                result_2x2[i][j] = matrix1_2x2[i][j] - matrix2_2x2[i][j];
            }
        }
        cout << "Difference of matrices (2x2):" << endl;
        displayMatrix2x2(result_2x2);
    }

    void multiplyMatrices2x2() {
        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < 2; j++) {
                result_2x2[i][j] = 0;
                for (int k = 0; k < 2; k++) {
                    result_2x2[i][j] += matrix1_2x2[i][k] * matrix2_2x2[k][j];
                }
            }
        }
        cout << "Product of matrices (2x2):" << endl;
        displayMatrix2x2(result_2x2);
    }

    void addMatrices3x3() {
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                result_3x3[i][j] = matrix1_3x3[i][j] + matrix2_3x3[i][j];
            }
        }
        cout << "Sum of matrices (3x3):" << endl;
        displayMatrix3x3(result_3x3);
    }

    void subtractMatrices3x3() {
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                result_3x3[i][j] = matrix1_3x3[i][j] - matrix2_3x3[i][j];
            }
        }
        cout << "Difference of matrices (3x3):" << endl;
        displayMatrix3x3(result_3x3);
    }

    void multiplyMatrices3x3() {
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                result_3x3[i][j] = 0;
                for (int k = 0; k < 3; k++) {
                    result_3x3[i][j] += matrix1_3x3[i][k] * matrix2_3x3[k][j];
                }
            }
        }
        cout << "Product of matrices (3x3):" << endl;
        displayMatrix3x3(result_3x3);
    }

    void determinant3x3() {
        int det = matrix1_3x3[0][0] * (matrix1_3x3[1][1] * matrix1_3x3[2][2] - matrix1_3x3[1][2] * matrix1_3x3[2][1]) -
                  matrix1_3x3[0][1] * (matrix1_3x3[1][0] * matrix1_3x3[2][2] - matrix1_3x3[1][2] * matrix1_3x3[2][0]) +
                  matrix1_3x3[0][2] * (matrix1_3x3[1][0] * matrix1_3x3[2][1] - matrix1_3x3[1][1] * matrix1_3x3[2][0]);
        cout << "Determinant of the matrix (3x3): " << det << endl;
    }

    void setMatrix2x2() {
        inputMatrix2x2(matrix1_2x2, "Matrix 1");
        inputMatrix2x2(matrix2_2x2, "Matrix 2");
    }

    void setMatrix3x3() {
        inputMatrix3x3(matrix1_3x3, "Matrix 1");
        inputMatrix3x3(matrix2_3x3, "Matrix 2");
    }
};

class ComplexNumber {
public:
    double real, imag;

    ComplexNumber(double r = 0, double i = 0) : real(r), imag(i) {}

    ComplexNumber add(const ComplexNumber& other) const {
        return ComplexNumber(real + other.real, imag + other.imag);
    }

    ComplexNumber subtract(const ComplexNumber& other) const {
        return ComplexNumber(real - other.real, imag - other.imag);
    }

    ComplexNumber multiply(const ComplexNumber& other) const {
        return ComplexNumber(real * other.real - imag * other.imag,
                             real * other.imag + imag * other.real);
    }

    ComplexNumber divide(const ComplexNumber& other) const {
        double denom = other.real * other.real + other.imag * other.imag;
        return ComplexNumber((real * other.real + imag * other.imag) / denom,
                             (imag * other.real - real * other.imag) / denom);
    }

    void display() const {
        if (imag >= 0) {
            cout << real << " + " << imag << "i" << endl;
        } else {
            cout << real << " - " << -imag << "i" << endl;
        }
    }
};

class BaseConversion {
public:
    static void decimalToBinary(int number) {
        cout << "Binary: " << bitset<32>(number) << endl;
    }

    static void decimalToHexadecimal(int number) {
        cout << "Hexadecimal: " << hex << uppercase << number << endl;
    }

    static void decimalToOctal(int number) {
        cout << "Octal: " << oct << number << endl;
    }
};
class kdaCalculator:public heroSection {
private:
    Addition add;
    Subtraction sub;
    Multiplication mul;
    Division div;
    Modulus mod;
    Power pow;
    Sin sin;
    Cos cos;
    Tan tan;
    Factorial fact;
    Permutation perm;
    Combination comb;
    CartesianToPolar cartToPolar;
    PolarToCartesian polarToCart;
    LinearEquation linEq;
    QuadraticEquation quadEq;
    TwoVariableEquation twoVarEq;
    ThreeVariableEquation threeVarEq;
    MatrixOperations matrixOps;

public:
    void performOperation() {
        double num1, num2;
        int intNum1, intNum2;
        char op='\n';
        while(op!='.'){
          heroSection ::introCalculator(); 
          cout<<"Enter operator: "<<endl;
          cin>>op;

        switch (op) {
            case '+':
                cout << "Enter two numbers for addition: ";
                cin >> num1 >> num2;
                cout << "Result: " << add.calculate(num1, num2) << endl;
                break;
            case '-':
                cout << "Enter two numbers for subtraction: ";
                cin >> num1 >> num2;
                cout << "Result: " << sub.calculate(num1, num2) << endl;
                break;
            case '*':
                cout << "Enter two numbers for multiplication: ";
                cin >> num1 >> num2;
                cout << "Result: " << mul.calculate(num1, num2) << endl;
                break;
            case '/':
                cout << "Enter two numbers for division: ";
                cin >> num1 >> num2;
                cout << "Result: " << div.calculate(num1, num2) << endl;
                break;
            case '%':
                cout << "Enter two integers for modulus: ";
                cin >> intNum1 >> intNum2;
                cout << "Result: " << mod.calculate(intNum1, intNum2) << endl;
                break;
            case 'p':
                cout << "Enter base and exponent for power: ";
                cin >> num1 >> num2;
                cout << "Result: " << pow.calculate(num1, num2) << endl;
                break;

            case 's': {
            Sin sinObj;
            double num;
            cout << "Enter a number: ";
            cin >> num;
            cout << "sin(" << num << ") = " << sinObj.calculate(num) << endl;
            break;
        }
        case 'c': {
            Cos cosObj;
            double num;
            cout << "Enter a number: ";
            cin >> num;
            cout << "cos(" << num << ") = " << cosObj.calculate(num) << endl;
            break;
        }
        case 't': {
            Tan tanObj;
            double num;
            cout << "Enter a number: ";
            cin >> num;
            cout << "tan(" << num << ") = " << tanObj.calculate(num) << endl;
            break;
        }
        case '!': {
            Factorial factObj;
            int n;
            cout << "Enter a number: ";
            cin >> n;
            cout << n << "! = " << factObj.factorial(n) << endl;
            break;
        }
        case 'P': {
            Permutation permObj;
            int n, r;
            cout << "Enter n and r: ";
            cin >> n >> r;
            cout << "Permutation: P(" << n << ", " << r << ") = " << permObj.permutation(n, r) << endl;
            break;
        }
        case 'C': {
            Combination combObj;
            int n, r;
            cout << "Enter n and r: ";
            cin >> n >> r;
            cout << "Combination: C(" << n << ", " << r << ") = " << combObj.combination(n, r) << endl;
            break;
        }
        case 'x': {
            CartesianToPolar cartToPolarObj;
            double x, y;
            cout << "Enter x and y: ";
            cin >> x >> y;
            auto result = cartToPolarObj.convert(x, y);
            cout << "r = " << result.first << ", theta = " << result.second << endl;
            break;
        }
        case 'y': {
            PolarToCartesian polarToCartObj;
            double r, theta;
            cout << "Enter r and theta: ";
            cin >> r >> theta;
            auto result = polarToCartObj.convert(r, theta);
            cout << "x = " << result.first << ", y = " << result.second << endl;
            break;
        }
        case '1': {
            LinearEquation linEqObj;
            double a, b;
            cout << "Enter a and b: ";
            cin >> a >> b;
            double solution = linEqObj.solve(a, b);
            if (!isnan(solution)) {
                cout << "Solution: x = " << solution << endl;
            }
            break;
        }

         case 'q':
                quadEq.solve();
                break;
            case '2':
                twoVarEq.solve();
                break;
            case '3':
                threeVarEq.solve();
                break;
            case 'M':
                int size;
                cout << "Choose matrix size (2: 2x2, 3: 3x3): ";
                cin >> size;
                if (size == 2) {
                matrixOps.setMatrix2x2();
                int matrixChoice;
                cout << "Choose matrix operation (1: Addition, 2: Subtraction, 3: Multiplication): ";
                cin >> matrixChoice;
                switch (matrixChoice) {
                    case 1:
                    matrixOps.addMatrices2x2();
                    break;

                    case 2:
                    matrixOps.subtractMatrices2x2();
                    break;

                    case 3:
                    matrixOps.multiplyMatrices2x2();
                    break;

                    default:
                    cout << "Invalid choice" << endl;
                    break;
                    } 
                }else if (size == 3) {
                        matrixOps.setMatrix3x3();
                        int matrixChoice;
                        cout << "Choose matrix operation (1: Addition, 2: Subtraction, 3: Multiplication, 4: Determinant): ";
                        cin >> matrixChoice;
                        switch (matrixChoice) {
                        case 1:
                        matrixOps.addMatrices3x3();
                        break;

                        case 2:
                        matrixOps.subtractMatrices3x3();
                        break;
                        
                        case 3:
                        matrixOps.multiplyMatrices3x3();
                        break;
                        
                        case 4:
                        matrixOps.determinant3x3();
                        break;
                        
                        default:
                        cout << "Invalid choice" << endl;
                        break;
                    }
                } else {
                    cout << "Invalid matrix size" << endl;
                }
                break;
            
            case 'z': {
            int op;
            double r1, i1, r2, i2;
            cout << "Enter the real and imaginary parts of the first complex number (r1 i1): ";
            cin >> r1 >> i1;
            ComplexNumber c1(r1, i1);
            
            cout << "Enter the real and imaginary parts of the second complex number (r2 i2): ";
            cin >> r2 >> i2;
            ComplexNumber c2(r2, i2);
            
            cout << "Select operation:" << endl;
            cout << "1. Addition" << endl;
            cout << "2. Subtraction" << endl;
            cout << "3. Multiplication" << endl;
            cout << "4. Division" << endl;
            cout << "Enter your choice: ";
            cin >> op;

            switch (op) {
                case 1:
                    c1.add(c2).display();
                    break;
                case 2:
                    c1.subtract(c2).display();
                    break;
                case 3:
                    c1.multiply(c2).display();
                    break;
                case 4:
                    c1.divide(c2).display();
                    break;
                default:
                    cout << "Invalid operation." << endl;
                    break;
            }
            break;
        }
        case 'B': {
            int number;
            cout << "Enter a decimal number: ";
            cin >> number;
             int choice;
            cout << "Select conversion:" << endl;
            cout << "1. Decimal to Binary" << endl;
            cout << "2. Decimal to Hexadecimal" << endl;
            cout << "3. Decimal to Octal" << endl;
            cout << "Enter your choice: ";
            cin >> choice;

            switch (choice) {
                case 1:
                    BaseConversion::decimalToBinary(number);
                    break;
                case 2:
                    BaseConversion::decimalToHexadecimal(number);
                    break;
                case 3:
                    BaseConversion::decimalToOctal(number);
                    break;
                default:
                    cout << "Invalid conversion." << endl;
                    break;
            }
            break;
        }

        case '4': {
                double value;
                cout << "Enter a value : ";
                 cin >> value;
            if (value < -1.0 || value > 1.0) {
                cerr << "Value out of range for asin." << endl;
            } else {
                double result = asin(value);
                cout << "asin(" << value << ") = " << result << " radians" << endl;
            }
            break;
        }
        case '5': {
            double value;
            cout<<"Enter value:"<<endl;
            if (value < -1.0 || value > 1.0) {
                cerr << "Value out of range for acos." << endl;
            } else {
                double result = acos(value);
                cout << "acos(" << value << ") = " << result << " radians" << endl;
            }
            break;
        }
        case '6': {
         double value;
            cout<<"Enter value:"<<endl;
            double result = atan(value);
            cout << "atan(" << value << ") = " << result << " radians" << endl;
            break;
        };

        case 'L': {
            double num;
            cout<<"Enter number: "<<endl;
            cin>>num;
            cout<<log10(num);
            break;
        }
        case 'l': {
            double num;
            cout<<"Enter number:"<<endl;
            cin>>num;
             cout<<log(num);

            break;
        }
        case '.':
        cout<<"press any key to EXIT"<<endl;
        cin.ignore();
        cin.get();
        break;

         
         case 'k':
            system("cls");
            heroSection::introCalculator();

            default:
                cout << "Invalid choice" << endl;
                break;
        }
        cout<<"press any key to continue "<<endl;
        cin.ignore();
        cin.get();
        system("cls");
       
        
        }
    }
};

int main() {
    system("cls");
    kdaCalculator calc;
    calc.performOperation();
    return 0;
    }