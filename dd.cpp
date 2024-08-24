#include <iostream>
#include <fstream>
#include <string>
#include <cmath>
#include <complex>
#include <vector>
#include <sstream>

using namespace std;

class ConversationManager {
public:
    void saveConversation(const string& username, const string& conversation) {
        ofstream file(username + "_conversation.txt", ios::app);
        if (file.is_open()) {
            file << conversation << endl;
            file.close();
            cout << "Conversation saved successfully!" << endl;
        } else {
            cerr << "Error: Could not save conversation." << endl;
        }
    }

    void deleteConversation(const string& username) {
        if (remove((username + "_conversation.txt").c_str()) == 0) {
            cout << "Conversation deleted successfully!" << endl;
        } else {
            cout << "Error deleting conversation or no conversation to delete." << endl;
        }
    }

    void loadConversation(const string& username) {
        ifstream file(username + "_conversation.txt");
        if (file.is_open()) {
            string line;
            while (getline(file, line)) {
                cout << line << endl;
            }
            file.close();
        } else {
            cerr << "Error: Could not open conversation file." << endl;
        }
    }
};

class Bot {
public:
    virtual void start() = 0; // Pure virtual function
    void setLoggedInUser(const string& user) {
        loggedInUser = user;
    }
protected:
    string loggedInUser;
};

class MathBot : public Bot {
public:
    void start() override {
        cout << "Enter a command or math expression:" << endl;
        cout << "Commands: sqrt(x), pow(x,y), sin(x), cos(x), tan(x), log(x), solve_quadratic(a,b,c), complex_op(a,b,c,d), matrix_solver(matrix) or type 'exit' to end:" << endl;

        while (true) {
            string input;
            getline(cin, input);

            if (input == "exit") return; // Exit from MathBot interaction

            if (input.find("sqrt(") == 0) {
                // Handle square root
                double operand;
                if (parseFunction(input, "sqrt(", operand)) {
                    cout << "Result: " << sqrt(operand) << endl;
                } else {
                    cout << "Error: Invalid input for sqrt function." << endl;
                }
            } else if (input.find("pow(") == 0) {
                // Handle power function
                double base, exponent;
                if (parseFunction(input, "pow(", base, exponent)) {
                    cout << "Result: " << pow(base, exponent) << endl;
                } else {
                    cout << "Error: Invalid input for pow function." << endl;
                }
            } else if (input.find("sin(") == 0) {
                // Handle sine function
                double angle;
                if (parseFunction(input, "sin(", angle)) {
                    cout << "Result: " << sin(toRadians(angle)) << endl; // Convert degrees to radians
                } else {
                    cout << "Error: Invalid input for sin function." << endl;
                }
            } else if (input.find("cos(") == 0) {
                // Handle cosine function
                double angle;
                if (parseFunction(input, "cos(", angle)) {
                    cout << "Result: " << cos(toRadians(angle)) << endl; // Convert degrees to radians
                } else {
                    cout << "Error: Invalid input for cos function." << endl;
                }
            } else if (input.find("tan(") == 0) {
                // Handle tangent function
                double angle;
                if (parseFunction(input, "tan(", angle)) {
                    cout << "Result: " << tan(toRadians(angle)) << endl; // Convert degrees to radians
                } else {
                    cout << "Error: Invalid input for tan function." << endl;
                }
            } else if (input.find("log(") == 0) {
                // Handle logarithm function
                double value;
                if (parseFunction(input, "log(", value)) {
                    cout << "Result: " << log10(value) << endl;
                } else {
                    cout << "Error: Invalid input for log function." << endl;
                }
            } else if (input.find("solve_quadratic(") == 0) {
                // Solve quadratic equation
                double a, b, c;
                if (parseFunction(input, "solve_quadratic(", a, b, c)) {
                    solveQuadratic(a, b, c);
                } else {
                    cout << "Error: Invalid input for quadratic equation solver." << endl;
                }
            } else if (input.find("complex_op(") == 0) {
                // Perform complex number operations
                double real1, imag1, real2, imag2;
                if (parseFunction(input, "complex_op(", real1, imag1, real2, imag2)) {
                    complex<double> c1(real1, imag1);
                    complex<double> c2(real2, imag2);
                    cout << "Addition: " << c1 + c2 << endl;
                    cout << "Subtraction: " << c1 - c2 << endl;
                    cout << "Multiplication: " << c1 * c2 << endl;
                    cout << "Division: " << c1 / c2 << endl;
                } else {
                    cout << "Error: Invalid input for complex number operations." << endl;
                }
            } else if (input.find("matrix_solver(") == 0) {
                // Solve matrix equations
                if (parseMatrix(input)) {
                    vector<vector<double>> matrix = { {1, 2, 3}, {4, 5, 6}, {7, 8, 9} }; // Placeholder for the actual parsed matrix
                    solveMatrix(matrix);
                } else {
                    cout << "Error: Invalid input for matrix solver." << endl;
                }
            } else {
                // Handle basic arithmetic
                double operand1, operand2;
                char operation;
                stringstream ss(input);
                if (ss >> operand1 >> operation >> operand2) {
                    double result;
                    bool validOperation = true;
                    switch (operation) {
                        case '+':
                            result = operand1 + operand2;
                            break;
                        case '-':
                            result = operand1 - operand2;
                            break;
                        case '*':
                            result = operand1 * operand2;
                            break;
                        case '/':
                            if (operand2 == 0) {
                                cout << "Error: Division by zero." << endl;
                                validOperation = false;
                            } else {
                                result = operand1 / operand2;
                            }
                            break;
                        default:
                            validOperation = false;
                            break;
                    }
                    if (validOperation) {
                        cout << "Result: " << result << endl;
                    } else {
                        cout << "Error: Invalid operation." << endl;
                    }
                } else {
                    cout << "Error: Invalid input format." << endl;
                }
            }
        }
    }

private:
    void solveQuadratic(double a, double b, double c) {
        double discriminant = b * b - 4 * a * c;
        if (discriminant > 0) {
            double root1 = (-b + sqrt(discriminant)) / (2 * a);
            double root2 = (-b - sqrt(discriminant)) / (2 * a);
            cout << "Roots: " << root1 << " and " << root2 << endl;
        } else if (discriminant == 0) {
            double root = -b / (2 * a);
            cout << "Root: " << root << endl;
        } else {
            cout << "Complex roots." << endl;
            double realPart = -b / (2 * a);
            double imaginaryPart = sqrt(-discriminant) / (2 * a);
            cout << "Root 1: " << realPart << " + " << imaginaryPart << "i" << endl;
            cout << "Root 2: " << realPart << " - " << imaginaryPart << "i" << endl;
        }
    }

    void solveMatrix(const vector<vector<double>>& matrix) {
        // Placeholder for matrix solver implementation
        cout << "Matrix solver is not implemented yet." << endl;
    }

    bool parseFunction(const string& input, const string& func, double& result) {
        size_t start = input.find('(');
        size_t end = input.find(')');
        if (start == string::npos || end == string::npos || start >= end) return false;
        string numberStr = input.substr(start + 1, end - start - 1);
        stringstream ss(numberStr);
        return (ss >> result);
    }

    bool parseFunction(const string& input, const string& func, double& operand1, double& operand2) {
        size_t start = input.find('(');
        size_t comma = input.find(',');
        size_t end = input.find(')');
        if (start == string::npos || comma == string::npos || end == string::npos || start >= comma || comma >= end) return false;
        string number1Str = input.substr(start + 1, comma - start - 1);
        string number2Str = input.substr(comma + 1, end - comma - 1);
        stringstream ss1(number1Str);
        stringstream ss2(number2Str);
        return (ss1 >> operand1) && (ss2 >> operand2);
    }

    bool parseFunction(const string& input, const string& func, double& operand1, double& operand2, double& operand3) {
        size_t start = input.find('(');
        size_t comma1 = input.find(',');
        size_t comma2 = input.find(',', comma1 + 1);
        size_t end = input.find(')');
        if (start == string::npos || comma1 == string::npos || comma2 == string::npos || end == string::npos || start >= comma1 || comma1 >= comma2 || comma2 >= end) return false;
        string number1Str = input.substr(start + 1, comma1 - start - 1);
        string number2Str = input.substr(comma1 + 1, comma2 - comma1 - 1);
        string number3Str = input.substr(comma2 + 1, end - comma2 - 1);
        stringstream ss1(number1Str);
        stringstream ss2(number2Str);
        stringstream ss3(number3Str);
        return (ss1 >> operand1) && (ss2 >> operand2) && (ss3 >> operand3);
    }

    bool parseFunction(const string& input, const string& func, double& real1, double& imag1, double& real2, double& imag2) {
        size_t start = input.find('(');
        size_t comma1 = input.find(',', start);
        size_t comma2 = input.find(',', comma1 + 1);
        size_t end = input.find(')', comma2 + 1);
        if (start == string::npos || comma1 == string::npos || comma2 == string::npos || end == string::npos || start >= comma1 || comma1 >= comma2 || comma2 >= end) return false;
        string real1Str = input.substr(start + 1, comma1 - start - 1);
        string imag1Str = input.substr(comma1 + 1, comma2 - comma1 - 1);
        string real2Str = input.substr(comma2 + 1, end - comma2 - 1);
        stringstream ss1(real1Str);
        stringstream ss2(imag1Str);
        stringstream ss3(real2Str);
        stringstream ss4(imag1Str);
        return (ss1 >> real1) && (ss2 >> imag1) && (ss3 >> real2) && (ss4 >> imag2);
    }

    bool parseMatrix(const string& input) {
        // Placeholder for matrix parsing implementation
        return true; // Returning true for the sake of completeness
    }

    double toRadians(double degrees) {
        return degrees * (M_PI / 180.0);
    }
};

class UserBot : public Bot {
public:
    void start() override {
        cout << "Welcome to UserBot!" << endl;
        cout << "Type 'save', 'load', 'delete', or 'exit' to interact:" << endl;

        while (true) {
            string command;
            getline(cin, command);

            if (command == "exit") return; // Exit from UserBot interaction

            if (command == "save") {
                string conversation;
                cout << "Enter conversation to save:" << endl;
                getline(cin, conversation);
                conversationManager.saveConversation(loggedInUser, conversation);
            } else if (command == "load") {
                conversationManager.loadConversation(loggedInUser);
            } else if (command == "delete") {
                conversationManager.deleteConversation(loggedInUser);
            } else {
                cout << "Invalid command. Type 'save', 'load', 'delete', or 'exit'." << endl;
            }
        }
    }

private:
    ConversationManager conversationManager;
};

class ChatBot : public Bot {
public:
    void start() override {
        cout << "Welcome to ChatBot!" << endl;
        cout << "Type 'math', 'user', or 'exit' to choose a mode:" << endl;

        while (true) {
            string mode;
            getline(cin, mode);

            if (mode == "exit") return; // Exit from ChatBot interaction

            if (mode == "math") {
                mathBot.start();
            } else if (mode == "user") {
                userBot.setLoggedInUser(loggedInUser);
                userBot.start();
            } else {
                cout << "Invalid mode. Type 'math', 'user', or 'exit'." << endl;
            }
        }
    }

private:
    MathBot mathBot;
    UserBot userBot;
};

bool login(const string& username, const string& password) {
    ifstream file("user_credentials.txt");
    string storedUser, storedPass;
    while (file >> storedUser >> storedPass) {
        if (storedUser == username && storedPass == password) {
            return true; // Login successful
        }
    }
    return false; // Login failed
}

bool registerUser(const string& username, const string& password) {
    ofstream file("user_credentials.txt", ios::app);
    if (file.is_open()) {
        file << username << " " << password << endl;
        file.close();
        return true; // Registration successful
    }
    return false; // Registration failed
}

int main() {
    while (true) {
        cout << "1. Login" << endl;
        cout << "2. Register" << endl;
        cout << "3. Exit" << endl;
        cout << "Choose an option (1, 2, or 3): ";

        int choice;
        cin >> choice;
        cin.ignore(); // Ignore remaining newline character

        if (choice == 3) {
            break; // Exit the application
        }

        string username, password;
        if (choice == 1) {
            cout << "Enter username: ";
            getline(cin, username);
            cout << "Enter password: ";
            getline(cin, password);

            if (login(username, password)) {
                ChatBot chatBot;
                chatBot.setLoggedInUser(username);
                chatBot.start();
            } else {
                cerr << "Login failed. Please check your credentials." << endl;
            }
        } else if (choice == 2) {
            cout << "Enter username: ";
            getline(cin, username);
            cout << "Enter password: ";
            getline(cin, password);

            if (registerUser(username, password)) {
                cout << "Registration successful. You can now log in." << endl;
            } else {
                cerr << "Registration failed. Please try again." << endl;
            }
        } else {
            cerr << "Invalid option. Please choose 1, 2, or 3." << endl;
        }
    }

    return 0;
}
