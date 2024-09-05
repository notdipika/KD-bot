#include <iostream>
#include <vector>
#include <iomanip>
#include <string>
#include <ctime>
#include <cstdlib>
#include <unordered_map>
#include <stdexcept>
#include <algorithm>
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


class TimeBot {
public:
    void tellTime() {
        time_t now = time(0);
        tm *ltm = localtime(&now);
        cout << BLUE << "Current time : " << setfill('0') << setw(2) << ltm->tm_hour << ":"
             << setfill('0') << setw(2) << ltm->tm_min << ":" << setfill('0') << setw(2) << ltm->tm_sec << RESET<<  endl;
    }
};

class MapBot {
public:
    void openMaps(const string& location) {
        try {
            string command = "start https://www.google.com/maps/search/" + location;
            if (system(command.c_str()) != 0) throw runtime_error("Failed to open Google Maps.");
            cout << GREEN <<"Google Maps opened for " << location << RESET <<endl;
        } catch (const runtime_error& e) {
            cout << RED <<"Error: " << e.what() << RESET << endl;
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
                cout<< GREEN <<  "Opened Notepad" << RESET << endl;
            } else if (appName == "word") {
                command = "start winword.exe";
                cout<< GREEN << "Opened Word" << RESET << endl;
            } else if (appName == "excel") {
                command = "start excel.exe";
                cout<< GREEN <<  "Opened Excel" << RESET <<endl;
            } else if (appName == "powerpoint") {
                command = "start powerpnt.exe";
                cout<< GREEN<<  "Opened PowerPoint" << RESET<< endl;
            } else {
                cout << RED;
                throw invalid_argument("Application not recognized.");
                cout<< RESET;
            }
            cout << RED;
            if (system(command.c_str()) != 0) throw runtime_error("Failed to open application.");
            cout<< RESET;
        } catch (const exception& e) {
            cout<< RED << "Error: " << e.what() << RESET << endl;
        }
    }
};

class MediaBot {
public:
    void playMedia(const string& mediaType) {
        try {
            string command;
            if (mediaType == "song") {
                command = "start https://open.spotify.com/"; 
                cout<< GREEN <<"Opened Spotify" << RESET << endl;
            } else if (mediaType == "video") {
                command = "start https://www.youtube.com/";
                cout<< GREEN << "Opened YouTube" << RESET << endl;
            } else {
                cout << RED;
                throw invalid_argument("Media type not recognized.");
                cout<< RESET;
            }
            cout << RED;
            if (system(command.c_str()) != 0) throw runtime_error("Failed to open media player.");
            cout<< RESET;
        } catch (const exception& e) {
            cout << RED << "Error: " << e.what() << RESET << endl;
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
            cout << BLUE << jokes[index] << RESET << endl;

            string userResponse;
            getline(cin, userResponse);
  
            cout << BLUE << getJokeAnswer(index) << RESET << endl;
        } catch (const runtime_error& e) {
            cout << RED <<"Error: " << e.what() << RESET << endl;
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
            cout << BLUE << riddles[index].first << RESET << endl;
            string answer;
            getline(cin, answer);
            if (answer == riddles[index].second) {
                cout <<BLUE << "Correct!" <<RESET<< endl;
            } else {
                cout <<BLUE<< "Wrong. The correct answer is: " << riddles[index].second << RESET<<endl;
            }
        } catch (const runtime_error& e) {
            cout << RED <<"Error: " << e.what() << RESET << endl;
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
        {"oop", "https://github.com/notdipika/cpp-lab"},
        {"edc", "https://drive.google.com/drive/folders/1jNfgqS1i-_BngSqL2S8XKWSoctjmF4Ad"},
        {"electronics", "https://drive.google.com/drive/folders/1jNfgqS1i-_BngSqL2S8XKWSoctjmF4Ad"},
        {"ecm", "https://drive.google.com/drive/folders/1_plPwJp0k5AdHEtlizsv8ODRZuBJnkvc"},
        {"electric machine", "https://drive.google.com/drive/folders/1_plPwJp0k5AdHEtlizsv8ODRZuBJnkvc"},
        {"electrical", "https://drive.google.com/drive/folders/1_plPwJp0k5AdHEtlizsv8ODRZuBJnkvc"},
        {"electric circuit ", "https://drive.google.com/drive/folders/1_plPwJp0k5AdHEtlizsv8ODRZuBJnkvc"},
        {"chemistry", "https://drive.google.com/drive/folders/1xz-8rz5xLBQ5aG7GbtTgKL4zY4rgmSsh"},
        {"maths", "https://drive.google.com/drive/folders/1J96LJ5I4wVoa9nUqd12ITSXls6UaF-Or"},
        {"dl", "https://drive.google.com/drive/folders/1tkUxoBZW4XbclbP0n5Ui5ACeni1CxefK"},
        {"digital logic", "https://drive.google.com/drive/folders/1tkUxoBZW4XbclbP0n5Ui5ACeni1CxefK"},
        {"question bank", "https://drive.google.com/drive/folders/1IdXFOWEpc1SHHjT9Uu1-Ns9QVOSlpN"},
        {"past questions", "https://drive.google.com/drive/folders/1IdXFOWEpc1SHHjT9Uu1-Ns9QVOSlpN"},
        {"question", "https://drive.google.com/drive/folders/1IdXFOWEpc1SHHjT9Uu1-Ns9QVOSlpN"},
        {"syllabus", "https://drive.google.com/drive/folders/1k2wFsxbFKTXX6OcH1tFsNWOxCG5jjPAI"}
    };

    vector<string> chatHistory;

public:
    void startChat(const string& loggedInUser) {
        try {
            system("cls");
            
            cout << "\t\t\t\t\t\t" << CYAN << "*************************************************************" << RESET << endl;
            cout << "\t\t\t\t\t\t" << CYAN << "*                                                           *" << RESET << endl;
            cout << "\t\t\t\t\t\t" << CYAN << "*" << BLUE << BOLD << "                       Hello, " + string(loggedInUser) << CYAN << " !                     *" << RESET << endl;
            cout << "\t\t\t\t\t\t" << CYAN << "*             " << BLUE << BOLD << "           I am KDA-BOT." << CYAN << "                      *" << RESET << endl;
            cout << "\t\t\t\t\t\t" << CYAN << "*                                                           *" << RESET << endl;
            cout << "\t\t\t\t\t\t" << CYAN << "*************************************************************" << RESET << endl;

        time_t now = time(0);
        tm *ltm = localtime(&now);
        cout << YELLOW << "Today's date : " << 1900 + ltm->tm_year << "-" 
             << setfill('0') << setw(2) << 1 + ltm->tm_mon << "-" 
             << setfill('0') << setw(2) << ltm->tm_mday << "                                                                                                           Type 'exit' to end "<< RESET << endl<<endl;
        
        handleUserMood();
            string conversation;
            while (true) {
                getline(cin, conversation);
                if (conversation == "exit") {
                cout << BLUE << "Goodbye! Have a great day!" <<RESET<< endl;
                cin.ignore();
                system("cls");
                exit(0);
                } 
                processInput(toLowerCase(trim(conversation)));
            }
        } catch (const exception& e) {
            cout << RED <<"Error: " << e.what()<< RESET << endl;
        }
    }

private:
    void handleUserMood() {
    string greet;
    getline(cin, greet);
    transform(greet.begin(), greet.end(), greet.begin(), ::tolower);
    if (greet.find("hi") != string::npos || 
        greet.find("hello") != string::npos || 
        greet.find("hii") != string::npos || 
        greet.find("hlo") != string::npos  || 
        greet.find("namaste") != string::npos || 
        greet.find("hiii") != string::npos ){
            cout << BLUE << "How are you feeling today? " << RESET << endl;
            string response;
            transform(response.begin(), response.end(), response.begin(), ::tolower);
            getline(cin, response);
            if(response.find("good") != string::npos || 
            response.find("great") != string::npos || 
            response.find("happy") != string::npos || 
            response.find("nice") != string::npos) {
            cout << BLUE << "That's great! Thank you for sharing. Do you have any work for me?" << RESET << endl;
            } else if (response.find("sad") != string::npos || 
                 response.find("bad") != string::npos || 
                 response.find("off") != string::npos || 
                 response.find("not good") != string::npos) {
            cout << BLUE << "I'm sorry to hear that. Would you like to hear a joke, try a riddle, play some games, listen to songs, or watch some videos? "<<RESET << endl;
            string choice;
            getline(cin, choice);
            transform(choice.begin(), choice.end(), choice.begin(), ::tolower);

            if (choice.find("joke") != string::npos) {
                jokeBot.tellJoke();
            } else if (choice.find("riddle") != string::npos) {
                riddleBot.giveRiddle();
            } else if (choice.find("games") != string::npos) {
                cout << BLUE << "Let's play tic-tac-toe!" << RESET << endl;
                system("start tictactoe.exe");
            } else if (choice.find("songs") != string::npos) {
                system("start https://open.spotify.com"); 
            } else if (choice.find("videos") != string::npos) {
                system("start https://www.youtube.com"); 
            } else {
                cout << BLUE<< "Alright, if you need anything else, just let me know!" << RESET << endl;
            }
            } 
            else if (response.find("hate") != string::npos || 
                 response.find("angry") != string::npos) {
                 cout<< BLUE << "I'm really sorry if I upset you. Please let me help you in a different way." <<RESET << endl;
            } 
            else if (response.find("thank") != string::npos || 
                 response.find("grateful") != string::npos) {
            cout << BLUE << "Thank you! I'm glad to be of help. Do you have any work for me?" << RESET << endl;
            } 
            else {
            cout << BLUE << "I hope everything is okay. If you need anything, just let me know!" << RESET << endl;
            }
            }
            else if (greet.find("Bye") != string::npos || 
            greet.find("goodbye") != string::npos){
            cout<< BLUE << "Goodbye! Have a great day!" <<RESET<< endl;
            }
    }

    void processInput(const string& input) {
        if (input == "yes") {
            cout << BLUE << "What would you like me to do?" << RESET << endl;
        } 
        else if (input.find("hi") != string::npos || 
                     input.find("hii") != string::npos || 
                     input.find("hiii") != string::npos || 
                     input.find("hello") != string::npos ||
                     input.find("hlo") != string::npos||
                     input.find("namaste")!=string::npos
                     ) {
                cout << BLUE << "How can I help you? "<<RESET << endl;
        }else if (input == "no") {
            cout << BLUE <<  "Okay, let me know if you need anything."<<RESET  << endl;
        } else if (input.find("time") != string::npos) {
            timeBot.tellTime();
        } else if (input.find("maps") != string::npos) {
            string location;
            cout << BLUE << "Enter location: " << RESET ;
            getline(cin, location);
            mapBot.openMaps(location);
            saveChat("Maps", location);
        } else if (input.find("wikipedia") != string::npos) {
            string query = input.substr(input.find("wikipedia") + 10); 
            searchWikipedia(trim(query));
        } else if (input.find("google") != string::npos) {
            string query = input.substr(input.find("google") + 10); 
            searchGoogle(trim(query));
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
        } else if (input.find("add") != string::npos || 
                     input.find("subtract") != string::npos || 
                     input.find("sum") != string::npos || 
                     input.find("product") != string::npos ||
                     input.find("math") != string::npos||
                     input.find("log")!=string::npos||
                     input.find("value")!=string::npos||
                     input.find("calculator")!=string::npos||
                     input.find("calculation")!=string::npos||
                     input.find("maths")!=string::npos||
                     input.find("divide")!=string::npos||
                     input.find("multiply")!=string::npos||
                     input.find("solve")!=string::npos
                     ) {
                cout << BLUE << "Would you like to open a calculator? (yes/no) "<< RESET<<endl;
                string answer;
                getline(cin, answer);
                transform(answer.begin(), answer.end(), answer.begin(), ::tolower);

                if (answer.find("yes") != string::npos) {
                    cout<< BLUE << "Do you want to use a simple calculator or an advanced calculator? (simple/advanced) "<<RESET<<endl;
                    string choice;
                    getline(cin, choice);
                    openCalculator(toLowerCase(trim(choice)));

                } else if (answer.find("no") != string::npos) {
                    cout<< BLUE << "Alright, if you need anything else, just let me know!" << RESET<< endl;
                } else {
                    cout<< BLUE << "I didn't quite get that. Please respond with 'yes' or 'no'." <<RESET<< endl;
                }
        } else if (input.find("tictactoe") != string::npos || input.find("tic tac toe") != string::npos || input.find("TICTACTOE") != string::npos  || input.find("games") != string::npos || input.find("Game") != string::npos || input.find("game") != string::npos) {
            cout<< BLUE << "Would you like to play Tic-Tac-Toe? (yes/no) "<<RESET<<endl;
            string response;
            getline(cin, response);
            if (toLowerCase(trim(response)) == "yes") {
                playTicTacToe();
            } else {
                cout << BLUE<< "Alright, let me know if you want to play later." << RESET<<endl;
            }
        } else if (input.find("song") != string::npos|| 
                     input.find("music") != string::npos) {
            mediaBot.playMedia("song");
        } else if (input.find("video") != string::npos) {
            mediaBot.playMedia("video");
        } else if (input.find("thank you") != string::npos) {
            cout << BLUE << "You're welcome!" << RESET << endl;
        } else if (input.find("i like you") != string::npos) {
            cout<< BLUE <<  "I like you too!" << RESET << endl;
        } else if (input.find("i hate you") != string::npos) {
            cout << BLUE << "I'm sorry to hear that. If there's anything specific bothering you, let me know." << RESET<<endl;
        }else if (input.find("notes") != string::npos || 
                     input.find("note") != string::npos || 
                     input.find("study") != string::npos || 
                     input.find("books") != string::npos ||
                     input.find("book") != string::npos||
                     input.find("slide")!=string::npos||
                     input.find("manual")!=string::npos||
                     input.find("pdf")!=string::npos
                     ) {
                        cout << BLUE<< "Would you like to open some study materials? (yes/no) "<<RESET<<endl;
                        string answer;
                        getline(cin, answer);
                        transform(answer.begin(), answer.end(), answer.begin(), ::tolower);
                        if (answer.find("yes") != string::npos) {
                        cout<< BLUE << "What subject can i help you with?"<< RESET<<endl;
                        string choice;
                        getline(cin, choice);
                        openUrl(toLowerCase(trim(choice)));

                        } else if (answer.find("no") != string::npos) {
                        cout<< BLUE << "Alright, if you need anything else, just let me know!" <<RESET<< endl;
                        } else {
                        cout<< BLUE << "I didn't quite get that. Please respond with 'yes' or 'no'."<<RESET << endl;
                        }
        }else if (input.find("who are you") != string::npos ) {
                        cout << BLUE<<"I am KDA-BOT."<<RESET<<endl;
        }else if (input.find("created") != string::npos || 
                     input.find("creator") != string::npos || 
                     input.find("made you") != string::npos || 
                     input.find("coder") != string::npos ) {
                     cout << BLUE<< "I was created by Dipika, Karuna and Aarzu."<< RESET << endl;
                     string input;
                     getline(cin, input);
                     transform(input.begin(), input.end(), input.begin(), ::tolower);
                     if (input.find("who are they?") != string::npos ||
                     input.find("contact") != string::npos ||
                     input.find("more info") != string::npos ||
                     input.find("information") != string::npos) {
                        cout << BLUE<< "They are undergraduate computer engineering at IOE PURWANCHAL CAMPUS. Do you want to contact them?"<< RESET<<endl;
                        string answer;
                        getline(cin, answer);
                        transform(answer.begin(), answer.end(), answer.begin(), ::tolower);
                        if (input.find("yes") != string::npos ){
                            cout<< BLUE << "You can contact them at LinkedIn via: \nlinkedin.com/in/notdipika/ \nlinkedin.com/in/karuna-karki-52982a313/ \nlinkedin.com/in/aarzu-gautam-b610682b1/" <<RESET<< endl;
                        }
                     }
        else{
            cout << BLUE << "I didn't quite get that. "<<RESET<< endl;
        }
        }
    }

    void openCalculator(const string& type) {
        string command;
        if (type == "simple") {
            command = "start simpleCalculator.exe";
            cout<< GREEN << "Opened Simple Calculator " <<RESET<< endl;
        } else if (type == "advanced") {
            command = "start advancedCalculator.exe";
            cout << GREEN << "Opened Advanced Calculator"<< RESET << endl;
        } else {
            cout << "I didn't regognize the type of calculator."<< endl;
            return;
        }
        if (system(command.c_str()) != 0) {
            cout << RED << "Failed to open calculator." << RESET<< endl;
        }
    }

    void playTicTacToe() {
        try {
            if (system("start tictactoe.exe") != 0) {
                cout << RED;
                throw runtime_error("Failed to open Tic-Tac-Toe game.");
                cout << RESET;
            }
            else{
                cout << GREEN <<  "Tic-Tac-Toe game opened successfully." << RESET << endl;
            }
        } catch (const exception& e) {
            cout << RED << "Error: " << e.what() << RESET << endl;
        }
    }

    void openUrl(const string& input) {
        auto it = urlMapping.find(input);
        if (it != urlMapping.end()) {
            try {
                string command = "start " + it->second;
                cout<< RED;
                if (system(command.c_str()) != 0) throw runtime_error("Failed to open URL.");
                cout << RESET;
                cout << GREEN << "Opened notes for " << input << RESET << endl;
                chatHistory.push_back(it->second);
            } catch (const exception& e) {
                cout <<RED << "Error: " << e.what() << RESET << endl;
            }
        } else {
            cout << BLUE << "I'm sorry, I didn't understand that. Can you try rephrasing?" << RESET<<endl;
        }
    }

    void searchWikipedia(const string& query) {
        try {
            string command = "start https://en.wikipedia.org/wiki/Special:Search?search=" + query;
            if (system(command.c_str()) != 0) {
            cout<< RED;
            throw runtime_error("Failed to open Wikipedia search.");
            cout << RESET; 
            }
            else{
                cout<< GREEN <<"Seached"<< query<< "on Wikipedia"<< RESET<<  endl;
            }
        } catch (const runtime_error& e) {
            cout << RED << "Error: " << e.what() << RESET<< endl;
        }
    }


     void searchGoogle(const string& query) {
        try {
            string command = "start https://www.google.com/search?q=" + query;
            if (system(command.c_str()) != 0) {
            cout<< RED;
            throw runtime_error("Failed to open Google search.");
            cout << RESET; 
            }
            else{
                cout<< GREEN <<"Seached"<< query<< "on Google"<< RESET<<  endl;
            }
        } catch (const runtime_error& e) {
            cout << RED << "Error: " << e.what() << RESET<< endl;
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
    ChatBot kda;
    string loggedInUser;
    system ("cls");
    cout << BLUE << BOLD << "\t\t\t\t\t\t\tKDA-BOT\n" << RESET << endl;
    cout<<"\t\t\t\t\t\t  What do I call you? "<<endl;
    getline(cin,loggedInUser);
    kda.startChat(loggedInUser);
    return 0;
}