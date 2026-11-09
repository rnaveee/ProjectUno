#include "Player.h"
#include "Card.h"
#include "Deck.h"

#include <iostream>

#ifndef USERINTERFACE_H
#define USERINTERFACE_H

class UserInterface {
public:
    int showMenu();
    void showPlayerInfo(const Player& player, const Card& topCard, int otherCardCount);
    void showHand(const Player& player);
    int chooseCard(const Player& player);
    void passTurn(const std::string& nextPlayerName);
    void showWinner(const Player& player);

private:
    void clearScreen();
    void waitForEnter();
};

#endif
