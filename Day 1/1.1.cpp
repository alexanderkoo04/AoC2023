#include <bits/stdc++.h>

int main() {
    int sum = 0;
    std::string current_string;
    
    while (std::getline(std::cin, current_string)) {
        std::string number_string = "XX";

        int l = 0;
        int r = current_string.size() - 1;
        bool flag_l = true;

        while (l < (r + 1) && flag_l) {
            if (std::isdigit(current_string[l])) {
                number_string[0] = current_string[l];
                flag_l = false;
            }
            else {
                l++;
            }
        }

        bool flag_r = true;
        while (r > (l - 1) && flag_r) {
            if (std::isdigit(current_string[r])) {
                number_string[1] = current_string[r];
                flag_r = false;
            }
            else {
                r--;
            }
        }
        int number = std::stoi(number_string);
        sum += number;
    }
    std::cout << sum;
}