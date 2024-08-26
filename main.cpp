#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <ctime>
#include <algorithm> // For std::transform

using namespace std;

// Placeholder classes for the different functionalities
class WeatherBot {
public:
    void getWeather(const string& city) {
        // Placeholder for weather information
        cout << "Fetching weather information for " << city << "..." << endl;
    }
};

class TimeBot {
public:
    void tellTime() {
        // Provide current time
        time_t now = time(0);
        tm *ltm = localtime(&now);
        cout << "Current time is: " << setfill('0') << setw(2) << ltm->tm_hour << ":"
             << setfill('0') << setw(2) << ltm->tm_min << ":" << setfill('0') << setw(2) << ltm->tm_sec << endl;
    }
};

class MapBot {
public:
    void openMaps(const string& location) {
        cout << "Opening Google Maps for " << location << "..." << endl;
        // Placeholder for opening Google Maps
        string command = "start https://www.google.com/maps/search/" + location;
        system(command.c_str());
    }
};

class ApplicationBot {
public:
    void openApplication(const string& appName) {
        if (appName == "notepad") {
            system("notepad.exe");
        } else if (appName == "word") {
            system("start winword.exe");
        } else if (appName == "excel") {
            system("start excel.exe");
        } else if (appName == "powerpoint") {
            system("start powerpnt.exe");
        } else {
            cout << "Application not recognized. Please try again." << endl;
        }
    }
};

class JokeBot {
public:
    void tellJoke() {
        // Placeholder for telling a joke
        cout << "Why don't scientists trust atoms? Because they make up everything!" << endl;
    }
};

class RiddleBot {
public:
    void giveRiddle() {
        // Placeholder for giving a riddle
        cout << "I speak without a mouth and hear without ears. I have no body, but I come alive with the wind. What am I?" << endl;
    }
};

class UserManager {
    WeatherBot weatherBot;
    TimeBot timeBot;
    MapBot mapBot;
    ApplicationBot applicationBot;
    JokeBot jokeBot;
    RiddleBot riddleBot;

public:
    void startChat() {
        system("cls");
        cout << "\t\t\t\t\t\t\t\tHi, I am KD bot" << endl;
        cout << "\t\t\t\t\t\t\t\tHi " << loggedInUser << ", how are you feeling today?" << endl;

        string response;
        getline(cin, response);
        transform(response.begin(), response.end(), response.begin(), ::tolower); // Convert to lowercase

        // Provide current date
        time_t now = time(0);
        tm *ltm = localtime(&now);
        cout << "Today's date is: " << 1900 + ltm->tm_year << "-" 
             << setfill('0') << setw(2) << 1 + ltm->tm_mon << "-" 
             << setfill('0') << setw(2) << ltm->tm_mday << endl;

        if (response.find("good") != string::npos || 
            response.find("great") != string::npos || 
            response.find("happy") != string::npos || 
            response.find("nice") != string::npos) {
            cout << "That's great! Thank you for sharing. Do you have any work for me?" << endl;
        } 
        else if (response.find("sad") != string::npos || 
                 response.find("bad") != string::npos || 
                 response.find("off") != string::npos || 
                 response.find("not good") != string::npos) {
            cout << "I'm sorry to hear that. Would you like to hear a joke, try a riddle, play some games, listen to songs, or watch some videos? (joke/riddle/games/songs/videos): ";
            string choice;
            getline(cin, choice);
            transform(choice.begin(), choice.end(), choice.begin(), ::tolower);

            if (choice.find("joke") != string::npos) {
                jokeBot.tellJoke();
            } else if (choice.find("riddle") != string::npos) {
                riddleBot.giveRiddle();
            } else if (choice.find("games") != string::npos) {
                cout << "Let's play some games!" << endl;
                system("tictactoe.exe"); // Opens the Tic-Tac-Toe game
            } else if (choice.find("songs") != string::npos) {
                system("start https://www.youtube.com"); // Opens YouTube in the default web browser
            } else if (choice.find("videos") != string::npos) {
                system("start https://www.youtube.com"); // Opens YouTube in the default web browser
            } else {
                cout << "Alright, if you need anything else, just let me know!" << endl;
            }
        } 
        else if (response.find("hate") != string::npos || 
                 response.find("angry") != string::npos) {
            cout << "I'm really sorry if I upset you. Please let me help you in a different way." << endl;
        } 
        else if (response.find("thank") != string::npos || 
                 response.find("grateful") != string::npos) {
            cout << "Thank you! I'm glad to be of help. Do you have any work for me?" << endl;
        } 
        else {
            cout << "I hope everything is okay. If you need anything, just let me know!" << endl;
        }

        string conversation;
        cout << "Enter your conversation (type 'exit' to end): " << endl;
        while (true) {
            string line;
            getline(cin, line);

            if (line == "exit") break;
            else if (line.find("weather") != string::npos) {
                cout << "Please enter the city name to get weather information: ";
                string city;
                getline(cin, city);
                weatherBot.getWeather(city);
            }
            else if (line.find("time") != string::npos) {
                timeBot.tellTime();
            }
            else if (line.find("map") != string::npos) {
                cout << "Please enter the location to open in Google Maps: ";
                string location;
                getline(cin, location);
                mapBot.openMaps(location);
            }
            else if (line.find("open") != string::npos) {
                if (line.find("notepad") != string::npos || line.find("notes") != string::npos) {
                    applicationBot.openApplication("notepad");
                }
                else if (line.find("word") != string::npos) {
                    applicationBot.openApplication("word");
                }
                else if (line.find("excel") != string::npos) {
                    applicationBot.openApplication("excel");
                }
                else if (line.find("powerpoint") != string::npos || line.find("ppt") != string::npos) {
                    applicationBot.openApplication("powerpoint");
                }
                else {
                    cout << "Please specify a valid application to open (e.g., Notepad, Word, Excel, PowerPoint)." << endl;
                }
            }
            else if (line.find("joke") != string::npos) {
                jokeBot.tellJoke();
            }
            else if (line.find("riddle") != string::npos) {
                riddleBot.giveRiddle();
            }
            else if (line.find("add") != string::npos || 
                     line.find("subtract") != string::npos || 
                     line.find("sum") != string::npos || 
                     line.find("product") != string::npos ||
                     line.find("math") != string::npos) {
                cout << "Would you like to open a calculator? (yes/no): ";
                string answer;
                getline(cin, answer);
                transform(answer.begin(), answer.end(), answer.begin(), ::tolower);

                if (answer.find("yes") != string::npos) {
                    cout << "Do you want to use a simple calculator or an advanced calculator? (simple/advanced): ";
                    getline(cin, answer);
                    transform(answer.begin(), answer.end(), answer.begin(), ::tolower);

                    if (answer.find("simple") != string::npos) {
                        system("simpleCalculator.exe");
                    } else if (answer.find("advanced") != string::npos) {
                        system("advancedCalculator.exe");
                    } else {
                        cout << "Invalid choice. Please specify 'simple' or 'advanced'." << endl;
                    }
                } else if (answer.find("no") != string::npos) {
                    cout << "Alright, if you need anything else, just let me know!" << endl;
                } else {
                    cout << "I didn't quite get that. Please respond with 'yes' or 'no'." << endl;
                }
            }
            else if (line.find("entertain") != string::npos) {
                cout << "Would you like to hear a joke, try a riddle, play some games, listen to songs, or watch some videos? (joke/riddle/games/songs/videos): ";
                string choice;
                getline(cin, choice);
                transform(choice.begin(), choice.end(), choice.begin(), ::tolower);

                if (choice.find("joke") != string::npos) {
                    jokeBot.tellJoke();
                } else if (choice.find("riddle") != string::npos) {
                    riddleBot.giveRiddle();
                } else if (choice.find("games") != string::npos) {
                    cout << "Let's play some games!" << endl;
                    system("tictactoe.exe"); // Opens the Tic-Tac-Toe game
                } else if (choice.find("songs") != string::npos) {
                    system("start https://www.spotify.com"); // Opens YouTube in the default web browser
                } else if (choice.find("videos") != string::npos) {
                    system("start https://www.youtube.com"); // Opens YouTube in the default web browser
                } else {
                    cout << "Alright, if you need anything else, just let me know!" << endl;
                }
            }
            else {
                conversation += line + "\n";
            }
        }
    }

private:
    string loggedInUser;
    string loggedInPassword;
    bool isLoggedIn = false;

public:
    void registerUser() {
        cout << "Enter a username to register: ";
        getline(cin, loggedInUser);
        cout << "Enter a password: ";
        getline(cin, loggedInPassword);
        saveCredentials();
    }

    void login() {
        string username, password;
        cout << "Enter your username: ";
        getline(cin, username);
        cout << "Enter your password: ";
        getline(cin, password);

        if (checkCredentials(username, password)) {
            isLoggedIn = true;
            loggedInUser = username;
            loggedInPassword = password;
            cout << "Login successful!" << endl;
            startChat();
        } else {
            cout << "Username or password incorrect. Please try again." << endl;
        }
    }

    void logout() {
        isLoggedIn = false;
        loggedInUser = "";
        loggedInPassword = "";
        cout << "You have successfully logged out." << endl;
    }

    void saveConversationHistory(const string &conversation) {
        ofstream outFile(loggedInUser + "_conversation.txt", ios::app);
        outFile << conversation;
        outFile.close();
    }

    void loadConversationHistory() {
        ifstream inFile(loggedInUser + "_conversation.txt");
        if (!inFile) {
            cout << "No previous conversation found." << endl;
        } else {
            string line;
            while (getline(inFile, line)) {
                cout << line << endl;
            }
            inFile.close();
        }
    }

    void deleteConversationHistory() {
        if (remove((loggedInUser + "_conversation.txt").c_str()) == 0) {
            cout << "Conversation history deleted successfully." << endl;
        } else {
            cout << "Error deleting conversation history." << endl;
        }
    }

private:
    void saveCredentials() {
        ofstream outFile("users.txt", ios::app);
        outFile << loggedInUser << " " << loggedInPassword << endl;
        outFile.close();
    }

    bool checkCredentials(const string& username, const string& password) {
        ifstream inFile("users.txt");
        string storedUsername, storedPassword;

        while (inFile >> storedUsername >> storedPassword) {
            if (storedUsername == username && storedPassword == password) {
                return true;
            }
        }

        return false;
    }
};

int main() {
    UserManager userManager;
    int choice;

    while (true) {
        cout << "1. Register" << endl;
        cout << "2. Login" << endl;
        cout << "3. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore(); // To consume the newline character left by cin

        if (choice == 1) {
            userManager.registerUser();
        } else if (choice == 2) {
            userManager.login();
        } else if (choice == 3) {
            break;
        } else {
            cout << "Invalid choice, please try again." << endl;
        }
    }

    return 0;
}
