#include <iostream>
#include <cstdlib>
#include <ctime>
#include "teht2.h"

Game::Game(int maxNum) {
    std::cout << "[DEBUG] Game::Game() kutsuttu maksimiarvo: " << maxNum << std::endl;
    maxNumber = maxNum;
    srand(static_cast<unsigned int>(time(0)));
    targetNumber = rand() % maxNumber + 1;
    attempts = 0;

    std::cout << "[DEBUG] Arvottu luku (hidden): " << targetNumber << std::endl;
}

void Game::Play() {
    int guess = 0;

    std::cout << "[DEBUG] Game::Play() kutsuttu" << std::endl;
    std::cout << "Arvaa luku valiltä 1 ja " << maxNumber << std::endl;

    while (guess != targetNumber) {
        std::cout << "Anna arvaus ";
        std::cin >> guess;
        attempts++;

        std::cout << "[DEBUG] Arvauksesi: " << guess << attempts << std::endl;

        if (guess < targetNumber) {
            std::cout << "Arvausliian pieni" << std::endl;
        } else if (guess > targetNumber) {
            std::cout << "Arvaus liian suuri" << std::endl;
        } else {
            std::cout << "Oikea arvaus" << targetNumber << std::endl;
        }
    }

    printGameResult();
}

void Game::printGameResult() {
    std::cout << "[DEBUG] Game::printGameResult() kutsuttu" << std::endl;
    std::cout << "Oikea luku oli " << targetNumber << std::endl;
    std::cout << "Tarvitsit arvauksia: " << attempts << std::endl;
}
