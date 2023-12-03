#include <bits/stdc++.h>

int main() {

    int sum = 0;
    std::string current_string;
    std::unordered_map<std::string, int> map;
    int current_game;

    while (std::getline(std::cin, current_string)) {
        bool flag = true;
        std::vector<int> vector;
        int current_red;
        int current_green;
        int current_blue;
        int current_game;

        if (std::isdigit(current_string[5]) && !(std::isdigit(current_string[6]))) {
            current_game = current_string[5] - '0';
        }

        else if (std::isdigit(current_string[5]) && std::isdigit(current_string[6]) && !(std::isdigit(current_string[7]))) {
            current_game = (10 * (current_string[5] - '0')) + (current_string[6] - '0');
        }

        else {
            current_game = 100;
        }
        
        

        for (int i = 0; i < current_string.size(); i++) {

            if (current_string[i] == 'r') {
                if (current_string.substr(i, 3) == "red") {
                    current_red = (current_string[i - 2] - '0');
                    if (std::isdigit(current_string[i - 3])) {
                        current_red += (10 * (current_string[i - 3] - '0'));
                    }
                }
            }

            else if (current_string[i] == 'g') {
                if (current_string.substr(i, 5) == "green") {
                    current_green = (current_string[i - 2] - '0');
                    if (std::isdigit(current_string[i - 3])) {
                        current_green += (10 * (current_string[i - 3] - '0'));
                    }
                }
            }

            else if (current_string[i] == 'b') {
                if (current_string.substr(i, 4) == "blue") {
                    current_blue = (current_string[i - 2] - '0');
                    if (std::isdigit(current_string[i - 3])) {
                        current_blue += (10 * (current_string[i - 3] - '0'));
                    }
                }
            }

            else if(current_string[i] == ';' || (current_string[i] == '\n' || current_string[i] == '\r') ) {
                vector.push_back(current_red);
                vector.push_back(current_green);
                vector.push_back(current_blue);

                if (vector[0] <= 12 && vector[1] <= 13 && vector[2] <= 14) {
                    for (int i = 0; i < vector.size(); i++) {
                        std::cout << vector[i] << " ";
                    }
                    std::cout << std::endl;

                    vector.clear();
                    current_red = 0;
                    current_green = 0;
                    current_blue = 0;
                    continue;

                    

                }
                else {
                    flag = false;
                    std::cout << "Failed Vector Below" << std::endl;
                    for (int i = 0; i < vector.size(); i++) {
                        std::cout << vector[i] << " ";
                    }
                    std::cout << std::endl;
                    vector.clear();
                    current_red = 0;
                    current_green = 0;
                    current_blue = 0;
                    break;
                }
            }

        }

        if (flag) {
            std::cout << "Current Sum: " << sum << std::endl << "Adding: " << current_game << " to sum" << std::endl;
            sum += current_game;
        }
    }

    std::cout << "Sum: " << sum << std::endl;


    // std::string current_string = "Game 1: 3 blue, 4 red; 1 red, 2 green, 6 blue; 2 green";
    // int current_game = current_string[5] - '0';
    // std::cout << current_game << std::endl;
    // current_string = "Game 2: 1 blue, 2 green; 3 green, 4 blue, 1 red; 1 green, 1 blue";
    // current_game = current_string[5] - '0';
    // std::cout << current_game << std::endl;
}