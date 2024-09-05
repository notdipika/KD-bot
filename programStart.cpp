#include <iostream>
#include <fstream>
#include <string>
#include <stdexcept>
#include <cstdlib>
#include <windows.h> 
using namespace std;

const string RESET = "\033[0m";
const string YELLOW = "\033[33m";
const string BLUE = "\033[34m";
const string CYAN = "\033[36m";
const string BOLD = "\033[1m";

class UserManager {
private:
    string loggedInUser;
    string loggedInPassword;
    bool isLoggedIn = false;

public:
    void registerUser() {
        system("cls");
        cout << BLUE << BOLD << "\t\t\t\t\t\t\t   KDA-BOT\n" << endl;
        cout << CYAN <<"\t\t\t\t\t\t\tREGISTRATION"<< RESET <<endl;
        try {
            while (true) {
                cout << YELLOW << "\nEnter a username: "<<RESET;
                getline(cin, loggedInUser);

                if (isUsernameTaken(loggedInUser)) {
                    cout << "Username is unavailable. Please try again." << endl;
                } else {
                    break;
                }
            }
            
            cout << YELLOW << "Enter a password: "<<RESET;
            getline(cin, loggedInPassword);
            saveCredentials();
            cout << "Registration successful! Please log in." << endl;
        } catch (const exception& e) {
            cout << "Error: " << e.what() << endl;
        }
    }

    void login() {
        system("cls");
        cout << BLUE << BOLD << "\t\t\t\t\t\t\tKDA-BOT\n" << endl;
        cout << CYAN <<"\t\t\t\t\t\t\t LOGIN"<< RESET <<endl;
        try {
            string username, password;
            cout << YELLOW << "Username: "<<RESET;
            getline(cin, username);

            if (!isUsernameTaken(username)) {
            cout << "Username doesn't exist." << endl<< endl;
            cout<< CYAN<<"\t\t\t\t\t\t  1. TRY AGAIN" << RESET << endl;
            cout<< CYAN<<"\t\t\t\t\t\t  2. RETURN TO HOME" << RESET << endl;
            int choice;
            cin >> choice;
            cin.ignore();
            if (choice == 1) {
                login();  
            } 
            return; 
        }

            int attempts = 3;
            while (attempts > 0) {
                cout << YELLOW << "Password: "<<RESET;
                getline(cin, password);

                if (checkCredentials(username, password)) {
                    system("cls");
                    isLoggedIn = true;
                    loggedInUser = username;
                    loggedInPassword = password;
                    cout << CYAN << BOLD << "\n\n\n\t\t\t\t\t\tLogin successful."<< RESET << endl << endl;
                    return;  
                } else {
                    attempts--;
                    if (attempts > 0) {
                        cout << "Incorrect password. Please try again." << endl;
                    } else {
                        cout << "Incorrect password." << endl << endl;
                        cout<< CYAN<<"\t\t\t\t\t\t1. RESET YOUR PASSWORD"<< RESET <<endl;
                        cout<< CYAN<<"\t\t\t\t\t\t2. RETURN TO HOME"<< RESET << endl;
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

    void forgotPassword(const string& username) {
        try {
            string newPassword;
            cout << "Enter your new password: ";
            getline(cin, newPassword);

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
        string line;
        bool userFound = false;

        while (getline(inFile, line)) {
            size_t delimiterPos = line.find(':');
            string id = line.substr(0, delimiterPos);
            string pass = line.substr(delimiterPos + 1);

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
            cout << BLUE << BOLD << "\t\t\t\t\t\t\t\tHi, I am KDA-BOT" << endl;
            cout << BLUE << BOLD << "\t\t\t\t\t\t\tI am your personal Assistant!" << endl;
            cout << endl << endl ;
            
            if (userManager.isUserLoggedIn()) {
                cout << CYAN << BOLD << "\t\t\t\t---------------------------------------------------------------------------------" << endl;
                cout << CYAN << BOLD << "\t\t\t\t|                    Do you want to logout or continue?                         |" << endl;
                cout << CYAN << BOLD << "\t\t\t\t---------------------------------------------------------------------------------" << endl;
                cout << YELLOW << "\t\t\t\t\t\t\t1. LOGOUT" << endl;
                cout << YELLOW << "\t\t\t\t\t\t\t2. START A NEW CHAT" << endl;
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
                cout << YELLOW << "\t\t\t\t\t\t\t1. LOGIN " << endl;
                cout << YELLOW << "\t\t\t\t\t\t\t2. REGISTER" << endl;
                cout << YELLOW << "\t\t\t\t\t\t\t3. EXIT" << RESET << endl;
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
                        cout << BLUE << BOLD << "\t\t\t\t\t\t\t  KDA-BOT\n" << endl;
                        cout << CYAN << "\t\t\t\t\t\tTHANK YOU, PLEASE VISIT AGAIN!" << RESET <<endl;
                        cin.ignore();
                        system("Cls");
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
        cout << "\t\t\t\t\t   Press any key to continue " << endl;
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
