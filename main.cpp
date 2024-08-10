#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class ConversationManager {
public:
    void saveConversation(const string& username, const string& conversation);
    void deleteConversation(const string& username);
    void loadConversation(const string& username);
};

class UserManager {
public:
    void login();
    void registerUser();
    void forgotPassword();
    void displayMenu();
    void showMainMenu();
    void startChat();
    void resetPassword(const string& username);

private:
    string loggedInUser;
    ConversationManager conversationManager;
};

int main() {
    UserManager userManager;
    userManager.showMainMenu();
    return 0;
}

void UserManager::showMainMenu() {
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

void UserManager::login() {
    int count = 0;
    string username, password, id, pass;
    system("cls");
    cout << "Please enter the username and password: " << endl;
    cout << "Username: ";
    cin >> username;
    cout << "Password: ";
    cin >> password;

    ifstream read("records.txt"); // to read the data
    while (read >> id >> pass) {
        if (id == username && pass == password) {
            count = 1;
            loggedInUser = username;
        }
    }
    read.close();

    if (count == 1) {
        cout << username << "\nYour login is successful \nThanks for logging in!\n";
        conversationManager.loadConversation(username);
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

void UserManager::registerUser() {
    string username, password;

    cout << "Enter the username: ";
    cin >> username;
    ifstream read("records.txt");
    string id, pass;
    while (read >> id >> pass) {
        if (id == username) {
            cout << "Username already exists. Please try again." << endl;
            return showMainMenu();
        }
    }
    read.close();

    cout << "Enter the password: ";
    cin >> password;

    ofstream write("records.txt", ios::app);
    write << username << ' ' << password << endl;
    write.close();

    system("cls");
    cout << "Registration is successful!" << endl;
    showMainMenu();
}

void UserManager::forgotPassword() {
    int count = 0;
    string username, id, pass;
    cout << "Enter your username: ";
    cin >> username;
    
    ifstream forg("records.txt");
    while (forg >> id >> pass) {
        if (id == username) {
            count = 1;
            break;
        }
    }
    forg.close();

    if (count == 1) {
        cout << "Your account is found!\n";
        resetPassword(username);
    } else {
        cout << "Sorry! Your account is not found" << endl;
    }
}

void UserManager::resetPassword(const string& username) {
    string newPassword;
    cout << "Enter your new password: ";
    cin >> newPassword;

    ifstream inFile("records.txt");
    ofstream tempFile("temp.txt");

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

    remove("records.txt");
    rename("temp.txt", "records.txt");

    cout << "Password reset successfully!" << endl;
    showMainMenu();
}

void UserManager::startChat() {
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

void ConversationManager::saveConversation(const string& username, const string& conversation) {
    ofstream file(username + "_conversation.txt", ios::app);
    file << conversation << endl;
    file.close();
    cout << "Conversation saved successfully!" << endl;
}

void ConversationManager::deleteConversation(const string& username) {
    if (remove((username + "_conversation.txt").c_str()) == 0) {
        cout << "Conversation deleted successfully!" << endl;
    } else {
        cout << "Error deleting conversation or no conversation to delete." << endl;
    }
}

void ConversationManager::loadConversation(const string& username) {
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
