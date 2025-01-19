#include <iostream>
#include "teht2.h"

int main() {
    int maxNum;

    std::cout << "[DEBUG] Main: Kysy maksimiarvo" << std::endl;
    std::cout << "Anna maksimi ";
    std::cin >> maxNum;

    std::cout << "[DEBUG] Main: Luonti Game-olio" << std::endl;
    Game game(maxNum);

    std::cout << "[DEBUG] Main: Kutsu game.Play()" << std::endl;
    game.Play();

    return 0;
}
