#include <bits/stdc++.h> 

int main() {
    std::string current_line;
    int sum = 0;
    
    int card_number = 1;
    std::unordered_map<int, int> map; // card # - > amount of cards

    std::vector<std::string> temp_vector;

    for (int i = 1; i < 203; i++) {
        map[i] = 1;
    }

    while(std::getline(std::cin, current_line)) {
       
        std::vector<int> winning_numbers;
        std::vector<int> my_numbers;
        
        int start_index = current_line.find(':');
        bool swap = false;

        for (int i = start_index; i < current_line.size(); i++) {
            std::string number_string = "";
            if (std::isdigit(current_line[i]) && !std::isdigit(current_line[i - 1])) {
                number_string = number_string + current_line[i];
                if (std::isdigit(current_line[i + 1])) {
                    number_string = number_string + current_line[i + 1];
                    if (swap) {
                        winning_numbers.push_back(std::stoi(number_string));
                    }
                    else {
                        my_numbers.push_back(std::stoi(number_string));
                    }
                }
                else {
                    if (swap) {
                        winning_numbers.push_back(std::stoi(number_string));
                    }
                    else {
                        my_numbers.push_back(std::stoi(number_string));
                    }
                }
            }
            if (current_line[i] == '|') {
                swap = true;
            }
        }
        int wins = 0;
        for (auto num : my_numbers) {
            
            auto it = std::find(winning_numbers.begin(), winning_numbers.end(), num);

            if (it != winning_numbers.end()) {
                wins++;
            }
        }
        // sum += (std::pow(2, wins - 1));
         
        for (int i = card_number + 1; i <= (card_number + wins); i++) {
            map[i] += map[card_number];
        }

        card_number++;
    }

    for (auto count : map) {
        std::cout << count.first << " has " << count.second << std::endl;
        sum += count.second;
    }

    std::cout << "Sum: " << sum << std::endl;
}