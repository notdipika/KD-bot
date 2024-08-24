#include <iostream>
#include <fstream>
#include <string>
#include <cstdio> 
#include <cmath>  
#include <iomanip> 

using namespace std;

class ScientificCalculator {
public:
    void performOperation() {
        char operation;
        double num1, num2;

        showCalculator();
        cout << "Enter operation: ";
        cin >> operation;

        if (operation == 'k' || operation == '.') {
            return; 
        }

        if (operation == '+' || operation == '-' || operation == '*' || operation == '/' || operation == 'm' || operation == 'p') {
            cout << "Enter num1: ";
            cin >> num1;
            cout << "Enter num2: ";
            cin >> num2;
        } else {
            cout << "Enter num1: ";
            cin >> num1;
        }

        double result = 0.0;
        switch (operation) {
            case '+':
                result = num1 + num2;
                break;
            case '-':
                result = num1 - num2;
                break;
            case '*':
                result = num1 * num2;
                break;
            case '/':
                result = num1 / num2;
                break;
            case 'm':
                result = static_cast<int>(num1) % static_cast<int>(num2);
                break;
            case 'L':
                result = log(num1);
                break;
            case 'S':
                result = num1 * num1;
                break;
            case 'C':
                result = num1 * num1 * num1;
                break;
            case 'p':
                result = pow(num1, num2);
                break;
            case 's':
                result = sin(num1);
                break;
            case 'c':
                result = cos(num1);
                break;
            case 't':
                result = tan(num1);
                break;
            case 'r':
                result = sqrt(num1);
                break;
            default:
                cout << "Invalid operation." << endl;
                return;
        }

        displayOutput(result);
    }

private:
    void showCalculator() {
        cout << "--------------------------------------------------------------------------------------" << endl;
        cout << "-                                            SCIENTIFIC                               -" << endl;
        cout << "---                                          CALCULATOR                            --- " << endl;
        cout << "-                                                                                     -" << endl;
        cout << "----------------------------------------------------------------------------------------" << endl;
        cout << "-        +               |             -             |           *                      -" << endl;
        cout << "-       Add              |          Subtract         |         Multiply                 -" << endl;
        cout << "----------------------------------------------------------------------------------------" << endl;
        cout << "-        /               |             m             |           L                     -" << endl;
        cout << "-     Divide             |            Mod            |          Log                    -" << endl;
        cout << "----------------------------------------------------------------------------------------" << endl;
        cout << "-        S               |             C             |           P                      -" << endl;
        cout << "-       Square           |            Cube           |         Power                    -" << endl;
        cout << "----------------------------------------------------------------------------------------" << endl;
        cout << "-        r               |             k             |           .                      -" << endl;
        cout << "-     Sq root            |          Clear            |         Close                   -" << endl;
        cout << "----------------------------------------------------------------------------------------" << endl;
    }

    void displayOutput(double result) {
        cout << "--------------------------------------------------------------------------------------" << endl;
        cout << "------                                                                ----------------" << endl;
        cout << "---                                           Current                |        " << endl;
        cout << "-                                             Output is:              |" << result << endl;
        cout << "---                                                                    -----------------" << endl;
        cout << "----------------------------------------------------------------------------------------" << endl;
        showCalculator();
    }
};

// Conversation Manager Class
class ConversationManager {
public:
    // Method to save the conversation to a file
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

    // Method to delete the conversation file
    void deleteConversation(const string& username) {
        if (remove((username + "_conversation.txt").c_str()) == 0) {
            cout << "Conversation deleted successfully!" << endl;
        } else {
            cout << "Error deleting conversation or no conversation to delete." << endl;
        }
    }

    // Method to load and display the conversation from a file
    void loadConversation(const string& username) {
        ifstream file(username + "_conversation.txt");
        if (file.is_open()) {
            cout << "Previous conversation loaded:\n";
            string line;
            while (getline(file, line)) {
                cout << line << endl;
            }
            file.close();
        } else {
            cout << "No previous conversation found." << endl;
        }
    }

    // Method to start a chat and interact with the user
    void startChat() {
        cout << endl;
        cout << endl;
        system("cls");
        cout << "\t\t\t\t\t\t\t\tHi, I am KD bot" << endl;
        cout << "\t\t\t\t\t\t\t\tAsk anything to me!" << endl;

        string conversation;
        cout << "Enter your message (type 'calculator' to use the scientific calculator, 'exit' to end): " << endl;
        cin.ignore(); 
        while (true) {
            string line;
            getline(cin, line);
            if (line == "exit") break;
            if (line == "calculator") {
                ScientificCalculator calc;
                calc.performOperation();
            } else {
                conversation += line + "\n";
            }
        }

        saveConversation(loggedInUser, conversation);
        showMainMenu();
    }

    // Method to display the main menu
    void showMainMenu() {
        int choice;
        cout << endl;
        cout << endl;
        system("cls");  
        cout << "\t\t\t\t\t\t\t\tHi, I am KD bot" << endl;
        cout << "\t\t\t\t\t\t\t\tAsk anything to me!" << endl;
        cout << "\t\tPlease login to continue............" << endl;
        cout << "\t\tPress 1 to LOGIN " << endl;
        cout << "\t\tPress 2 to REGISTER" << endl;
        cout << "\t\tPress 3 to EXIT" << endl;
        cin >> choice;
        cout << endl;

        switch (choice) {
            case 1:
                login();
                break;
            case 2:
                registerUser();
                break;
            case 3:
                cout << "Thank you!" << endl;
                break;
            default:
                system("cls");
                cout << "Please choose a valid number \n" << endl;
                showMainMenu();
        }
    }

private:
    string loggedInUser;

    // Method to handle user login
    void login() {
        string username, password, storedPassword;
        system("cls");
        cout << "Please enter the username and password: " << endl;
        cout << "Username: ";
        cin >> username;
        cout << "Password: ";
        cin >> password;

        if (findUser(username, storedPassword) && storedPassword == password) {
            loggedInUser = username;
            cout << username << "\nYour login is successful \nThanks for logging in!\n";
            loadConversation(username);
            startChat();
        } else {
            cout << "\nIncorrect username or password." << endl;
            int option;
            cout << "Press 1 if you forgot your password." << endl;
            cout << "Press 2 to try again." << endl;
            cin >> option;

            if (option == 1) {
                forgotPassword();
            } else if (option == 2) {
                login();
            } else {
                cout << "Invalid choice." << endl;
                login();
            }
        }
    }

    // Method to handle user registration
    void registerUser() {
        string username, password, dummyPassword;

        cout << "Enter the username: ";
        cin >> username;

        if (findUser(username, dummyPassword)) {
            cout << "Username already exists. Please try again." << endl;
            return showMainMenu();
        }

        cout << "Enter the password: ";
        cin >> password;

        ofstream write("records.txt", ios::app);
        if (write.is_open()) {
            write << username << ' ' << password << endl;
            write.close();
            system("cls");
            cout << "Registration is successful! Please login to continue." << endl;
        } else {
            cerr << "Error: Could not open records file for writing." << endl;
        }
        showMainMenu();
    }

    // Method to handle forgotten passwords
    void forgotPassword() {
        string username, password;
        cout << "Enter your username: ";
        cin >> username;

        if (findUser(username, password)) {
            cout << "Your account is found!\n";
            resetPassword(username);
        } else {
            cout << "Sorry! Your account is not found." << endl;
        }
    }

    // Method to reset the password
    void resetPassword(const string& username) {
        string newPassword;
        cout << "Enter new password: ";
        cin >> newPassword;

        ifstream read("records.txt");
        ofstream temp("temp.txt");

        if (read.is_open() && temp.is_open()) {
            string fileUsername, filePassword;
            while (read >> fileUsername >> filePassword) {
                if (fileUsername == username) {
                    temp << username << ' ' << newPassword << endl;
                } else {
                    temp << fileUsername << ' ' << filePassword << endl;
                }
            }
            read.close();
            temp.close();
            remove("records.txt");
            rename("temp.txt", "records.txt");
            cout << "Password updated successfully!" << endl;
        } else {
            cerr << "Error: Could not open files for reading/writing." << endl;
        }
        showMainMenu();
    }

    // Method to find a user in the records
    bool findUser(const string& username, string& password) {
        ifstream read("records.txt");
        if (read.is_open()) {
            string fileUsername, filePassword;
            while (read >> fileUsername >> filePassword) {
                if (fileUsername == username) {
                    password = filePassword;
                    return true;
                }
            }
            read.close();
        }
        return false;
    }
};

int main() {
    ConversationManager cm;
    cm.showMainMenu();
    return 0;
}
