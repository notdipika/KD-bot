
#include <iostream>
#include <cmath>
#include <windows.h>
#include <string>
#include <cstdlib>
using namespace std;
const string RESET = "\033[0m";
const string RED = "\033[31m";
const string GREEN = "\033[32m";
const string YELLOW = "\033[33m";
const string BLUE = "\033[34m";
const string MAGENTA = "\033[35m";
const string CYAN = "\033[36m";
const string WHITE = "\033[37m";
const string BOLD = "\033[1m";
const string UNDERLINE = "\033[4m";

using namespace std;
class Calculator {
public:
    void kdaCalculator() {
    cout << RED << BOLD << "-----------------------------------------" << RESET << endl;
    cout << RED << BOLD << "----                                  ---" << RESET << endl;
    cout << RED << BOLD << "-                  KDA                  -" << RESET << endl;
    cout << RED << BOLD << "-              CALCULATOR               -" << RESET << endl;
    cout << RED << BOLD << "---                                   ---" << RESET << endl;
    cout << RED << BOLD << "-----------------------------------------" << RESET << endl;
    cout << GREEN << "-      " << "+     |      " << "-      |      " << "*     -" << RESET << endl;
    cout << GREEN << "-     " << "Add    |   " << "Subtract  |  " << "Multiply  -" << RESET << endl;
    cout << GREEN << "-----------------------------------------" << RESET << endl;

    cout << GREEN << "-      " << "/     |      " << "m      |      " << "L     -" << RESET << endl;
    cout << GREEN << "-   " << "Divide   |     " << "Mod     |     " << "Log    -" << RESET << endl;
    cout << GREEN << "-----------------------------------------" << RESET << endl;

    cout << GREEN << "-      " << "S     |      " << "C      |      " << "p     -" << RESET << endl;
    cout << GREEN << "-    " << "Square  |    " << "Cube     |    " << "Power   -" << RESET << endl;
    cout << GREEN << "-----------------------------------------" << RESET << endl;

    cout << GREEN << "-      " << "s     |      " << "c      |      " << "t     -" << RESET << endl;
    cout << GREEN << "-     " << "sin    |     " << "cos     |     " << "tan    -" << RESET << endl;
    cout << GREEN << "-----------------------------------------" << RESET << endl;

    cout << GREEN << "-      " << "r     |      " << "k      |      " << ".     -" << RESET << endl;
    cout << GREEN << "-  " << "sq root   |    " << "clear    |    " << "close   -" << RESET << endl;
    cout << GREEN << "-----------------------------------------" << RESET << endl;
    }

    void displayOutput(double answer) {
    cout << RED << BOLD << "-----------------------------------------" << RESET << endl;
    cout << RED << BOLD << "----                     ----------------" << RESET << endl;
    cout << RED << BOLD << "-       Your             |     " << RESET << endl;
    cout << RED << BOLD << "-       answer is:       |  " << GREEN << answer << RESET << endl;
    cout << RED << BOLD << "---                      ----------------" << RESET << endl;
    cout << RED << BOLD << "-----------------------------------------" << RESET << endl;

    cout << GREEN << "-      " << "+     |      " << "-" << "      |      " << "*" << "     -" << RESET << endl;
    cout << GREEN << "-     " << "Add    |    " << "Minus    |  " << "Multiply  -" << RESET << endl;
    cout << GREEN << "-----------------------------------------" << RESET << endl;

    cout << GREEN << "-      " << "/     |      " << "m" << "      |      " << "L" << "     -" << RESET << endl;
    cout << GREEN << "-   " << "Divide   |     " << "Mod     |     " << "Log    -" << RESET << endl;
    cout << GREEN << "-----------------------------------------" << RESET << endl;

    cout << GREEN << "-      " << "S     |      " << "C" << "      |      " << "p" << "     -" << RESET << endl;
    cout << GREEN << "-    " << "Square  |    " << "Cube     |    " << "Power   -" << RESET << endl;
    cout << GREEN << "-----------------------------------------" << RESET << endl;

    cout << GREEN << "-      " << "s     |      " << "c" << "      |      " << "t" << "     -" << RESET << endl;
    cout << GREEN << "-     " << "sin    |     " << "cos     |     " << "tan    -" << RESET << endl;
    cout << GREEN << "-----------------------------------------" << RESET << endl;

    cout << GREEN << "-      " << "r     |      " << "k" << "      |      " << "." << "     -" << RESET << endl;
    cout << GREEN << "-  " << "sq root   |    " << "clear    |    " << "close   -" << RESET << endl;
    cout << GREEN << "-----------------------------------------" << RESET << endl;

    }

    void run() {
        double num1 = 0.0;
        double num2 = 0.0;
        double answer = 0.0;
        char inp = '\n';
        bool converter = 0;

        while (inp != '.') {
            if (converter == 1) {
                displayOutput(answer);
                cout << "Enter: ";
                cin >> inp;
                if (inp == '+' || inp == '-' || inp == '*' || inp == '/' || inp == 'm' || inp == 'p') {
                    num1 = answer;
                    cout << "Enter num 2: ";
                    cin >> num2;
                } else if (inp == 'k' || inp == '.') {
                   
                } else {
                    num1 = answer;
                }
            } else {
                kdaCalculator();
                cout << "Enter operator : "<<endl;
                cin >> inp;
                if (inp == '+' || inp == '-' || inp == '*' || inp == '/' || inp == 'm' || inp == 'p') {
                    cout << "Enter num 1: ";
                    cin >> num1;
                    cout << "Enter num 2: ";
                    cin >> num2;
                } else if (inp == 'k' || inp == '.') {
                   
                } 
                else {
                    cout << "Enter num 1: ";
                    cin >> num1;
                }

                converter = 1;
            }

            switch (inp) {
            case '+':
                answer = num1 + num2;
                break;
            case '-':
                answer = num1 - num2;
                break;
            case '*':
                answer = num1 * num2;
                break;
            case '/':
                answer = num1 / num2;
                break;
            case 'm':
                answer = static_cast<int>(num1) % static_cast<int>(num2);
                break;
            case 'L':
                answer = log(num1);
                break;
            case 'S':
                answer = num1 * num1;
                break;
            case 'C':
                answer = num1 * num1 * num1;
                break;
            case 'p':
                answer = pow(num1, num2);
                break;
            case 's':
                answer = sin(num1);
                break;
            case 'c':
                answer = cos(num1);
                break;
            case 't':
                answer = tan(num1);
                break;
            case 'r':
                answer = sqrt(num1);
                break;
            case 'k':
                converter = 0;
                break;
            case '.':
                cout<<"Press any key to EXIT "<<endl;
                cin.ignore();
                cin.get();
                break;             
            default:
                cout << "*****Please enter a valid number!***** " << endl;
            }

            system("cls");
        }
    }
};

int main() {
    system("cls");
    Calculator calc;
    calc.run();
    return 0;
}
