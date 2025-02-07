#include <iostream>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cout.tie(nullptr);

    int score;
    std::cin >> score;

    switch (score / 10) {
        case 10:
        case 9:
            std::cout << "A";
            break;
        case 8:
            std::cout << "B";
            break;
        case 7:
            std::cout << "C";
            break;  
        case 6:
            std::cout << "D";
            break;
        default:
            std::cout << "F";
            break;
    }
    return 0;
}
