#include <iostream>
#include <fstream>
#include <string>
#include <stdexcept>
#include <cstdlib>
#include <windows.h> 
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

class UserManager {
private:
    string loggedInUser;
    string loggedInPassword;
    bool isLoggedIn = false;

public:
    void registerUser() {
        try {
            while (true) {
                cout << "Enter a username to register: ";
                getline(cin, loggedInUser);

                if (isUsernameTaken(loggedInUser)) {
                    cout << "Username is unavailable. Please try again." << endl;
                } else {
                    break;
                }
            }
            
            cout << "Enter a password: ";
            getline(cin, loggedInPassword);
            saveCredentials();
            cout << "Registration successful! Please log in." << endl;
        } catch (const exception& e) {
            cout << "Error: " << e.what() << endl;
        }
    }

    void login() {
        try {
            system("Cls");
            string username, password;
            cout << "Enter your username: ";
            getline(cin, username);

            int attempts = 3;
            while (attempts > 0) {
                cout << "Enter your password (Attempts left: " << attempts << "): ";
                getline(cin, password);

                if (checkCredentials(username, password)) {
                    system("cls");
                    isLoggedIn = true;
                    loggedInUser = username;
                    loggedInPassword = password;
                    cout << "Login successful!" << endl;
                    loadConversationHistory();  
                    return;  
                } else {
                    attempts--;
                    if (attempts > 0) {
                        cout << "Incorrect password. Please try again." << endl;
                    } else {
                        cout << "Wrong password. You can reset your password if you wish." << endl;
                        cout << "Press 1 to reset your password or 2 to return to the main menu: ";
                        int choice;
                        cin >> choice;
                        cin.ignore(); 

                        if (choice == 1) {
                            forgotPassword(username);
                        }
                        return;
                    }
                }
            }
        } catch (const exception& e) {
            cout << "Error: " << e.what() << endl;
        }
    }

    void logout() {
        try {
            if (isLoggedIn) {
                cout << "Logging out..." << endl;
                isLoggedIn = false;
                loggedInUser.clear();
                loggedInPassword.clear();
            } else {
                cout << "No user is logged in." << endl;
            }
        } catch (const exception& e) {
            cout << "Error: " << e.what() << endl;
        }
    }

    bool isUserLoggedIn() const {
        return isLoggedIn;
    }

    void saveConversationHistory(const string& conversation) {
        if (!isLoggedIn) return;  
        string filename = loggedInUser + "_conversation.txt";
        ofstream file(filename, ios::app);
        if (!file) throw runtime_error("Failed to open file for saving conversation history.");
        file << conversation << endl;
        file.close();
    }

    void loadConversationHistory() {
        if (!isLoggedIn) return; 
        string filename = loggedInUser + "_conversation.txt";
        if (fileExists(filename)) {
            ifstream file(filename);
            if (!file) throw runtime_error("Failed to open file for loading conversation history.");
            string line;
            while (getline(file, line)) {
                cout << line << endl;
            }
            file.close();
        } else {
            cout << "No previous conversation found." << endl;
        }
    }

    void forgotPassword(const string& username) {
        try {
            string newPassword;
            cout << "Enter your new password: ";
            cin >> newPassword;

            if (resetPassword(username, newPassword)) {
                cout << "Password reset successfully!" << endl;
            } else {
                cout << "Username not found. Could not reset password." << endl;
            }
        } catch (const exception& e) {
            cout << "Error: " << e.what() << endl;
        }
    }

private:
    void saveCredentials() {
        ofstream file("users.txt", ios::app);
        if (!file) throw runtime_error("Failed to open file for saving credentials.");
        file << loggedInUser << ":" << loggedInPassword << endl;
        file.close();
    }

    bool checkCredentials(const string& username, const string& password) {
        ifstream file("users.txt");
        if (!file) throw runtime_error("Failed to open file for reading credentials.");
        string savedUsername, savedPassword;
        while (getline(file, savedUsername, ':')) {
            getline(file, savedPassword);
            if (username == savedUsername && password == savedPassword) {
                return true;
            }
        }
        return false;
    }

    bool isUsernameTaken(const string& username) {
        ifstream file("users.txt");
        if (!file) {
            ofstream newFile("users.txt");
            newFile.close();
            return false; 
        }

        string savedUsername, savedPassword;
        while (getline(file, savedUsername, ':')) {
            getline(file, savedPassword);
            if (username == savedUsername) {
                return true;
            }
        }
        return false;
    }

    bool fileExists(const string& filename) {
        ifstream file(filename);
        return file.good();
    }

    bool resetPassword(const string& username, const string& newPassword) {
        ifstream inFile("users.txt");
        ofstream tempFile("temp.txt");
        string id, pass;
        bool userFound = false;

        while (inFile >> id >> pass) {
            if (id == username) {
                tempFile << id << ":" << newPassword << endl;
                userFound = true;
            } else {
                tempFile << id << ":" << pass << endl;
            }
        }
        inFile.close();
        tempFile.close();

        remove("users.txt");
        rename("temp.txt", "users.txt");

        return userFound;
    }
};

class LoginRegistration {
private:
    UserManager userManager;

public:
    void heroBeforeLogin() {
        int choice;
        do {
            system("cls");
            cout << endl << endl;
            cout << BLUE << BOLD << "\t\t\t\t\t\t\t\tHi, I am KDA bot" << endl;
            cout << BLUE << BOLD << "\t\t\t\t\t\t\tI am your personal Assistant!" << endl;
            cout << endl << endl ;
            
            if (userManager.isUserLoggedIn()) {
                cout << CYAN << BOLD << "\t\t\t\t---------------------------------------------------------------------------------" << endl;
                cout << CYAN << BOLD << "\t\t\t\t|                    Do you want to logout or continue?                         |" << endl;
                cout << CYAN << BOLD << "\t\t\t\t---------------------------------------------------------------------------------" << endl;
                cout << YELLOW << "\t\tPress 1 to LOGOUT" << endl;
                cout << YELLOW << "\t\tPress 2 to CONTINUE" << endl;
                cin >> choice;
                cin.ignore(); 

                if (choice == 1) {
                    userManager.logout();
                } else if (choice == 2) {
                    heroAfterLogin();
                }
            } else {
                cout << CYAN << BOLD << "\t\t\t\t---------------------------------------------------------------------------------" << endl;
                cout << CYAN << BOLD << "\t\t\t\t|                     Please LOGIN OR REGISTER to continue.........             |" << endl;
                cout << CYAN << BOLD << "\t\t\t\t---------------------------------------------------------------------------------" << endl;
                cout << YELLOW << "\t\tPress 1 to LOGIN " << endl;
                cout << YELLOW << "\t\tPress 2 to REGISTER" << endl;
                cout << YELLOW << "\t\tPress 3 to EXIT" << endl;
                cin >> choice;
                cin.ignore(); 

                switch (choice) {
                    case 1:
                        userLogin();
                        break;
                    case 2:
                        userManager.registerUser();
                        break;
                    case 3:
                        system("cls");
                        cout << "/t/t/t Thank you!" << endl;
                        system("cls");
                        break;
                    default:
                        cout << "Please choose a valid number \n" << endl;
                        break;
                }
            }
        } while (choice != 3 && !userManager.isUserLoggedIn());
    }

    void userLogin() {
        userManager.login();
        if (userManager.isUserLoggedIn()) {
            heroAfterLogin();
        }
    }

    void heroAfterLogin() {
        cout << "Press any key to continue " << endl;
        cin.ignore();
        cin.get();
        system("cls");
        system("start KDABOT.exe");
        heroBeforeLogin();
    }

};

int main() {
    LoginRegistration lg;
    lg.heroBeforeLogin();
    return 0;
}


