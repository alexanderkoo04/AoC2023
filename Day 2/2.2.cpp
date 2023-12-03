#include <bits/stdc++.h>

int main() {
    int sum = 0;
    std::string current_string;

    while (std::getline(std::cin, current_string)) {
        int power;
        int min_red = 0;
        int min_green = 0;
        int min_blue = 0;

        for (int i = 0; i < current_string.size(); i++) {

            if (current_string[i] == 'r') {
                if (current_string.substr(i, 3) == "red") {
                    if (std::isdigit(current_string[i - 3])) {
                        min_red = std::max(min_red, ((10 * (current_string[i - 3] - '0')) + (current_string[i - 2] - '0')));
                    }
                    else {
                        min_red = std::max(min_red, (current_string[i - 2] - '0'));
                    }
                }
            }

            else if (current_string[i] == 'g') {
                if (current_string.substr(i, 5) == "green") {
                    if (std::isdigit(current_string[i - 3])) {
                        min_green = std::max(min_green, ((10 * (current_string[i - 3] - '0')) + (current_string[i - 2] - '0')));
                    }
                    else {
                        min_green = std::max(min_green, (current_string[i - 2] - '0'));
                    }
                }
            }

            else if (current_string[i] == 'b') {
                if (current_string.substr(i, 4) == "blue") {
                    if (std::isdigit(current_string[i - 3])) {
                        min_blue = std::max(min_blue, ((10 * (current_string[i - 3] - '0')) + (current_string[i - 2] - '0')));
                    }
                    else {
                        min_blue = std::max(min_blue, (current_string[i - 2] - '0'));
                    }
                }
            }

            else if (current_string[i] == '\n' || current_string[i] == '\r') {
                power = min_red * min_green * min_blue;
                std::cout << "min_red = " << min_red << " min_green = " << min_green << " min_blue = " << min_blue << std::endl;
                std::cout << "Line Power = " << power << std::endl;
                sum += power;
            }
        }
    }

    std::cout << "Sum: " << sum << std::endl;
}