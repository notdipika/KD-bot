#include <iostream>
#include <vector>
#include <iomanip>
#include <string>
#include <ctime>
#include <chrono>
#include <cstdlib>
#include <unordered_map>
#include <stdexcept>
#include <algorithm>
#include <windows.h>

using namespace std;

class TimeBot {
public:
    void tellTime() {
        try {
            auto now = chrono::system_clock::now();
            auto time = chrono::system_clock::to_time_t(now);
            auto localTime = localtime(&time);
            if (!localTime) throw runtime_error("Failed to get local time.");
            cout << "Current time is: " << put_time(localTime, "%H:%M:%S") << endl;
        } catch (const runtime_error& e) {
            cout << "Error: " << e.what() << endl;
        }
    }
};

class MapBot {
public:
    void openMaps(const string& location) {
        try {
            string command = "start https://www.google.com/maps/search/" + location;
            if (system(command.c_str()) != 0) throw runtime_error("Failed to open Google Maps.");
        } catch (const runtime_error& e) {
            cout << "Error: " << e.what() << endl;
        }
    }
};

class ApplicationBot {
public:
    void openApplication(const string& appName) {
        try {
            string command;
            if (appName == "notepad") {
                command = "notepad.exe";
            } else if (appName == "word") {
                command = "start winword.exe";
            } else if (appName == "excel") {
                command = "start excel.exe";
            } else if (appName == "powerpoint") {
                command = "start powerpnt.exe";
            } else {
                throw invalid_argument("Application not recognized.");
            }
            if (system(command.c_str()) != 0) throw runtime_error("Failed to open application.");
        } catch (const exception& e) {
            cout << "Error: " << e.what() << endl;
        }
    }
};

class MediaBot {
public:
    void playMedia(const string& mediaType) {
        try {
            string command;
            if (mediaType == "song") {
                command = "start yourMusicPlayer.exe"; 
            } else if (mediaType == "video") {
                command = "start yourVideoPlayer.exe"; 
            } else {
                throw invalid_argument("Media type not recognized.");
            }
            if (system(command.c_str()) != 0) throw runtime_error("Failed to open media player.");
        } catch (const exception& e) {
            cout << "Error: " << e.what() << endl;
        }
    }
};

class JokeBot {
private:
    vector<string> jokes = {
        "Why don't scientists trust atoms?",
        "What do you call fake spaghetti?",
        "Why did the scarecrow win an award? ",
        "How does a penguin build its house? ",
        "Why did the bicycle fall over? "
    };
public:
    void tellJoke() {
        try {
            seedRandom(); 
            int index = rand() % jokes.size();
            cout << jokes[index] << endl;

            string userResponse;
            getline(cin, userResponse);
  
            cout << getJokeAnswer(index) << endl;
        } catch (const runtime_error& e) {
            cout << "Error: " << e.what() << endl;
        }
    }

private:
    void seedRandom() {
        srand(static_cast<unsigned int>(time(nullptr)));
    }

    string getJokeAnswer(int index) {
        static vector<string> answers = {
            "Because they make up everything!",
            "An impasta!",
            "Because he was outstanding in his field!",
            "Igloos it together!",
            "Because it was two-tired!"
        };
        return answers[index];
    }
};

class RiddleBot {
private:
    vector<pair<string, string>> riddles = {
        {"I speak without a mouth and hear without ears. I have nobody, but I come alive with the wind. What am I?", "An echo."},
        {"What has keys but can’t open locks?", "A piano."},
        {"I’m tall when I’m young, and I’m short when I’m old. What am I?", "A candle."},
        {"What has a heart that doesn’t beat?", "An artichoke."},
        {"The more you take, the more you leave behind. What am I?", "Footsteps."}
    };
public:
    void giveRiddle() {
        try {
            seedRandom(); 
            int index = rand() % riddles.size();
            cout << riddles[index].first << endl;
            string answer;
            cout << "Your answer: ";
            getline(cin, answer);
            if (answer == riddles[index].second) {
                cout << "Correct!" << endl;
            } else {
                cout << "Wrong. The correct answer is: " << riddles[index].second << endl;
            }
        } catch (const runtime_error& e) {
            cout << "Error: " << e.what() << endl;
        }
    }

private:
    void seedRandom() {
        srand(static_cast<unsigned int>(time(nullptr)));
    }
};

class ChatBot {
    TimeBot timeBot;
    MapBot mapBot;
    ApplicationBot applicationBot;
    MediaBot mediaBot;
    JokeBot jokeBot;
    RiddleBot riddleBot;

    unordered_map<string, string> urlMapping = {
        {"oops notes", "https://github.com/notdipika/cpp-lab"},
        {"edc manual", "https://drive.google.com/drive/folders/1jNfgqS1i-_BngSqL2S8XKWSoctjmF4Ad"},
        {"edc notes", "https://drive.google.com/drive/folders/1jNfgqS1i-_BngSqL2S8XKWSoctjmF4Ad"},
        {"ecm notes", "https://drive.google.com/drive/folders/1_plPwJp0k5AdHEtlizsv8ODRZuBJnkvc"},
        {"electric machine manual", "https://drive.google.com/drive/folders/1_plPwJp0k5AdHEtlizsv8ODRZuBJnkvc"},
        {"electrical notes", "https://drive.google.com/drive/folders/1_plPwJp0k5AdHEtlizsv8ODRZuBJnkvc"},
        {"electric machine slides", "https://drive.google.com/drive/folders/1_plPwJp0k5AdHEtlizsv8ODRZuBJnkvc"},
        {"electric circuit manual", "https://drive.google.com/drive/folders/1_plPwJp0k5AdHEtlizsv8ODRZuBJnkvc"},
        {"chemistry notes", "https://drive.google.com/drive/folders/1xz-8rz5xLBQ5aG7GbtTgKL4zY4rgmSsh"},
        {"maths solutions", "https://drive.google.com/drive/folders/1J96LJ5I4wVoa9nUqd12ITSXls6UaF-Or"},
        {"dl manual", "https://drive.google.com/drive/folders/1tkUxoBZW4XbclbP0n5Ui5ACeni1CxefK"},
        {"dl notes", "https://drive.google.com/drive/folders/1tkUxoBZW4XbclbP0n5Ui5ACeni1CxefK"},
        {"question bank", "https://drive.google.com/drive/folders/1IdXFOWEpc1SHHjT9Uu1-Ns9QVOSlpN"},
        {"past questions", "https://drive.google.com/drive/folders/1IdXFOWEpc1SHHjT9Uu1-Ns9QVOSlpN"},
        {"syllabus", "https://drive.google.com/drive/folders/1k2wFsxbFKTXX6OcH1tFsNWOxCG5jjPAI"}
    };

    vector<string> chatHistory;

public:
    void startChat() {
        try {
            system("cls");
            greetUser();
            handleUserMood();

            string conversation;
            while (true) {
                cout << "Enter your message (type 'exit' to end): ";
                getline(cin, conversation);
                if (conversation == "exit") {
                cout << "Goodbye! Have a great day!" << endl;
                system("cls");
                exit(0);
                } 
                processInput(toLowerCase(trim(conversation)));
            }
        } catch (const exception& e) {
            cout << "Error: " << e.what() << endl;
        }
    }

private:
    void greetUser() {
        cout << "Hi, how are you feeling today?" << endl;
    }

    void handleUserMood() {
        string mood;
        getline(cin, mood);
        string lowerMood = toLowerCase(trim(mood));
        if (lowerMood.find("sad") != string::npos || lowerMood.find("bad") != string::npos || lowerMood.find("off") != string::npos) {
            cout << "I'm sorry to hear that. Would you like to listen to a song, watch a video, hear a joke, a riddle, or play some games? (song/video/joke/riddle/games)" << endl;
        } else if (lowerMood.find("happy") != string::npos || lowerMood.find("good") != string::npos || lowerMood.find("great") != string::npos) {
            cout << "That's great! Do you have any work for me? (yes/no)" << endl;
        }
    }

    void processInput(const string& input) {
        if (input == "yes") {
            cout << "What would you like me to do?" << endl;
        } else if (input == "no") {
            cout << "Okay, let me know if you need anything." << endl;
        } else if (input.find("time") != string::npos) {
            timeBot.tellTime();
        } else if (input.find("maps") != string::npos) {
            string location;
            cout << "Enter location: ";
            getline(cin, location);
            mapBot.openMaps(location);
            saveChat("Maps", location);
            cout<< "Opened" << location << 
        } else if (input.find("wikipedia") != string::npos) {
            string query = input.substr(input.find("wikipedia") + 10); 
            searchWikipedia(trim(query));
        } else if (input.find("notepad") != string::npos) {
            applicationBot.openApplication("notepad");
        } else if (input.find("word") != string::npos) {
            applicationBot.openApplication("word");
        } else if (input.find("excel") != string::npos) {
            applicationBot.openApplication("excel");
        } else if (input.find("powerpoint") != string::npos) {
            applicationBot.openApplication("powerpoint");
        } else if (input.find("joke") != string::npos) {
            jokeBot.tellJoke();
        } else if (input.find("riddle") != string::npos) {
            riddleBot.giveRiddle();
        } else if (input.find("calculator") != string::npos) {
            cout << "Would you like to use a simple or advanced calculator? (simple/advanced): ";
            string choice;
            getline(cin, choice);
            openCalculator(toLowerCase(trim(choice)));
        } else if (input.find("tictactoe") != string::npos) {
            cout << "Would you like to play Tic-Tac-Toe? (yes/no): ";
            string response;
            getline(cin, response);
            if (toLowerCase(trim(response)) == "yes") {
                playTicTacToe();
            } else {
                cout << "Alright, let me know if you want to play later." << endl;
            }
        } else if (input.find("song") != string::npos) {
            mediaBot.playMedia("song");
        } else if (input.find("video") != string::npos) {
            mediaBot.playMedia("video");
        } else if (input.find("thank you") != string::npos) {
            cout << "You're welcome!" << endl;
        } else if (input.find("i like you") != string::npos) {
            cout << "I like you too!" << endl;
        } else if (input.find("i hate you") != string::npos) {
            cout << "I'm sorry to hear that. If there's anything specific bothering you, let me know." << endl;
        } else {
            openUrl(input);
        }
    }

    void openCalculator(const string& type) {
        string command;
        if (type == "simple") {
            command = "start simpleCalculator.exe";
        } else if (type == "advanced") {
            command = "start advancedCalculator.exe";
        } else {
            cout << "Calculator type not recognized." << endl;
            return;
        }
        if (system(command.c_str()) != 0) {
            cout << "Failed to open calculator." << endl;
        }
    }

    void playTicTacToe() {
        try {
            if (system("start tictactoe.exe") != 0) {
                throw runtime_error("Failed to open Tic-Tac-Toe game.");
            }
        } catch (const exception& e) {
            cout << "Error: " << e.what() << endl;
        }
    }

    void openUrl(const string& input) {
        auto it = urlMapping.find(input);
        if (it != urlMapping.end()) {
            try {
                string command = "start " + it->second;
                if (system(command.c_str()) != 0) throw runtime_error("Failed to open URL.");
                chatHistory.push_back(it->second);
            } catch (const exception& e) {
                cout << "Error: " << e.what() << endl;
            }
        } else {
            cout << "Sorry, I don't have a link for that." << endl;
        }
    }

    void searchWikipedia(const string& query) {
        try {
            string command = "start https://en.wikipedia.org/wiki/Special:Search?search=" + query;
            if (system(command.c_str()) != 0) throw runtime_error("Failed to open Wikipedia search.");
        } catch (const runtime_error& e) {
            cout << "Error: " << e.what() << endl;
        }
    }

    void saveChat(const string& action, const string& detail) {
        string entry = action + ": " + detail;
        chatHistory.push_back(entry);
    }

    string trim(const string& str) {
        string trimmed = str;
        trimmed.erase(trimmed.find_last_not_of(" \n\r\t")+1);
        trimmed.erase(0, trimmed.find_first_not_of(" \n\r\t"));
        return trimmed;
    }

    string toLowerCase(string str) {
        transform(str.begin(), str.end(), str.begin(), ::tolower);
        return str;
    }
};

int main() {
    ChatBot chatBot;
    chatBot.startChat();
    return 0;
}
