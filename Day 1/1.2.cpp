#include <bits/stdc++.h>

int main() {
    int sum = 0;
    std::string current_string;
    std::vector<char> vector;
    while (std::getline(std::cin, current_string)) {

        std::string number_string = "99";
        int l = 0;

        std::unordered_map<std::string, char> map;
            map["one"] = '1';
            map["two"] = '2';
            map["three"] = '3';
            map["four"] = '4';
            map["five"] = '5';
            map["six"] = '6';
            map["seven"] = '7';
            map["eight"] = '8';
            map["nine"] = '9';

        while (l < current_string.size()) {
            if (std::isalpha(current_string[l])) {
                if (current_string[l] == 'o' || 
                    current_string[l] == 't' || 
                    current_string[l] == 'f' || 
                    current_string[l] == 's' || 
                    current_string[l] == 'e' || 
                    current_string[l] == 'n') 
                {
                    std::string substr_3 = current_string.substr(l, 3);
                    std::string substr_4 = current_string.substr(l, 4);
                    std::string substr_5 = current_string.substr(l, 5);

                    auto it3 = map.find(substr_3);
                    auto it4 = map.find(substr_4);
                    auto it5 = map.find(substr_5);

                    if (it3 != map.end()) {
                        vector.push_back(it3->second);
                    }
                    
                    else if (it4 != map.end()) {
                        vector.push_back(it4->second);
                    }

                    else if (it5 != map.end()) {
                        vector.push_back(it5->second);
                    }
                }
            
            }

            else if (std::isdigit(current_string[l])) {
                vector.push_back(current_string[l]);
            }


            std::cout << "Current L value: " << l << std::endl;
            std::cout << "Vector current size: " << vector.size() << std::endl;
            

            std::cout << "Current vector elements: ";
            for (int i = 0; i < vector.size(); i++) {
                std::cout << vector[i] << " ";
            }
            std::cout << std::endl;
            std::cout << std::endl;
            l++;
        }

        number_string[0] = vector[0];
        number_string[1] = vector[vector.size() - 1];
        int number = std::stoi(number_string);
        std::cout << "Adding: " << number << " to sum" << std::endl;
        sum += number;
        vector.clear();
    }
    std::cout << sum << std::endl;
}