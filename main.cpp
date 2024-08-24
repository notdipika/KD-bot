#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>

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
};

class UserManager {
public:
    void login() {
        string username, password, storedPassword;
        system("cls");
        cout << "Please enter the username and password: " << endl;
        cout << "Username: ";
        cin >> username;

        // Check if username exists
        if (!findUser(username, storedPassword)) {
            cout << "\nUsername not found." << endl;
            int option;
            cout << "Press 1 to REGISTER." << endl;
            cin >> option;

            if (option == 1) {
                registerUser();
            } else {
                cout << "Invalid choice. Returning to home page." << endl;
                showMainMenu();
            }
            return;  // Exit after handling the user's choice
        }

        cout << "Password: ";
        cin >> password;

        if (storedPassword == password) {
            loggedInUser = username;
            cout << username << "\nYour login is successful \nThanks for logging in!\n";
            conversationManager.loadConversation(username);
            startChat();
        } else {
            cout << "\nIncorrect password." << endl;
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

    void forgotPassword() {
        string username, password;
        cout << "Enter your username: ";
        cin >> username;

        // Check if username exists
        if (!findUser(username, password)) {
            cout << "Sorry! Your account is not found. Returning to main menu." << endl;
            showMainMenu();  // Return to main menu if username is not found
            return;
        }

        cout << "Your account is found!\n";
        resetPassword(username);
    }

    void resetPassword(const string& username) {
        string newPassword;
        cout << "Enter your new password: ";
        cin >> newPassword;

        ifstream inFile("records.txt");
        ofstream tempFile("temp.txt");

        if (!inFile.is_open() || !tempFile.is_open()) {
            cerr << "Error: Could not open files for password reset." << endl;
            return;
        }

        string id, pass;
        while (inFile >> id >> pass) {
            if (id == username) {
                tempFile << id << ' ' << newPassword << endl;
            } else {
                tempFile << id << ' ' << pass << endl;
            }
        }

        inFile.close();
        tempFile.close();

        if (remove("records.txt") != 0 || rename("temp.txt", "records.txt") != 0) {
            cerr << "Error: Could not update password." << endl;
        } else {
            cout << "Password reset successfully!" << endl;
        }
        showMainMenu();
    }

    void startChat() {
        cout << endl;
        cout << endl;
        system("cls");
        cout << "\t\t\t\t\t\t\t\tHi, I am KD bot" << endl;
        cout << "\t\t\t\t\t\t\t\tAsk anything to me!" << endl;

        string conversation;
        cout << "Enter your conversation (type 'exit' to end): " << endl;
        cin.ignore(); 
        while (true) {
            string line;
            getline(cin, line);
            if (line == "exit") break;
            conversation += line + "\n";
        }

        conversationManager.saveConversation(loggedInUser, conversation);
        showMainMenu();
    }

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
    ConversationManager conversationManager;

    bool findUser(const string& username, string& password) {
        ifstream read("records.txt");
        string id, pass;
        while (read >> id >> pass) {
            if (id == username) {
                password = pass;
                return true;
            }
        }
        return false;
    }
};


int main() {
    UserManager userManager;
    userManager.showMainMenu();
    return 0;
}
