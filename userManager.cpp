#include <iostream>
#include <fstream>
#include <string>
#include <stdexcept>
#include <cstdlib> // for system()

using namespace std;

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
            string username, password;
            cout << "Enter your username: ";
            getline(cin, username);

            int attempts = 3;
            while (attempts > 0) {
                cout << "Enter your password (Attempts left: " << attempts << "): ";
                getline(cin, password);

                if (checkCredentials(username, password)) {
                    isLoggedIn = true;
                    loggedInUser = username;
                    loggedInPassword = password;
                    cout << "Login successful!" << endl;
                    loadConversationHistory();  
                    system("start kdaBot.exe");
                    return;  
                } else {
                    attempts--;
                    if (attempts > 0) {
                        cout << "Incorrect password. Please try again." << endl;
                    } else {
                        cout << "Wrong password. Redirecting to main menu..." << endl;
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
            } else {
                cout << "No user is logged in." << endl;
            }
        } catch (const exception& e) {
            cout << "Error: " << e.what() << endl;
        }
    }

    bool isUserLoggedIn() {
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

        // Create the file if it doesn't exist
        if (!file) {
            ofstream newFile("users.txt");
            newFile.close();
            return false;  // No usernames taken yet since file was just created
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
};

int main() {
    try {
        UserManager userManager;
        while (true) {
            if (userManager.isUserLoggedIn()) {
                cout << "1. Logout" << endl;
                cout << "2. Exit" << endl;
                cout << "Enter your choice: ";
                int choice;
                cin >> choice;
                cin.ignore();

                switch (choice) {
                    case 1:
                        userManager.logout();
                        break;
                    case 2:
                        return 0;
                    default:
                        cout << "Invalid choice. Please try again." << endl;
                }
            } else {
                cout << "1. Register" << endl;
                cout << "2. Login" << endl;
                cout << "3. Exit" << endl;
                cout << "Enter your choice: ";
                int choice;
                cin >> choice;
                cin.ignore();  

                switch (choice) {
                    case 1:
                        userManager.registerUser();
                        break;
                    case 2:
                        userManager.login();
                        break;
                    case 3:
                        return 0;
                    default:
                        cout << "Invalid choice. Please try again." << endl;
                }
            }
        }
    } catch (const exception& e) {
        cout << "Error: " << e.what() << endl;
    }
}
