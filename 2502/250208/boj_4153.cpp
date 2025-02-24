#include <iostream>
#include <algorithm>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    int input[3];
    while (true) {
        std::cin >> input[0] >> input[1] >> input[2];
        if (input[0] == 0 && input[1] == 0 && input[2] == 0) break;
        std::sort(input, input + 3);
        if ((input[0] * input[0] + input[1] * input[1]) == (input[2] * input[2])) std::cout << "right" << std::endl;
        else std::cout << "wrong" << std::endl;
    }
    return 0;
}