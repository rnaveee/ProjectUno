#ifndef PLAYER_H
#define PLAYER_H

#include <iostream>
#include "UnoDeck.h"

class Player {
private:
    // define private node
    struct Node {
        Card card;
        Node* link;
    };
    typedef Node* NodePtr;

    int numCards;
    std::string name;
    NodePtr head;

public:
    Player (std::string name);
    // Precondition: name contains the player's name.
    // Postcondition: Creates a player with the specified name and
    // an empty hand containing no cards.

    ~Player ();
    // Postcondition: All dynamically allocated memory used by the
    // player's hand is released and the player object is destroyed.


    void drawCard (const Card& card);
    // Precondition: card is a valid Card object.
    // Postcondition: card is added to the player's hand and the
    // number of cards in the hand is increased by one.
    void displayHand() const;
    // Precondition: None.
    // Postcondition: Displays all cards currently in the player's
    // hand. The player's hand is not modified.


    Card playCard (int index);
    // Precondition: index refers to a valid card position in the
    // player's hand.
    // Postcondition: The selected card is removed from the player's
    // hand and returned. The number of cards is decreased by one.


    bool isValidPlay (int index, const Card& topCard) const;
    // Precondition: index refers to a valid card position in the
    // player's hand.
    // Postcondition: Returns true if the card at index can legally
    // be played on topCard according to UNO rules, and false otherwise.

    bool hasPlayableCard (const Card& card) const;
    // Precondition: card represents the current top card or current
    // game state being checked.
    // Postcondition: Returns true if the player has at least one
    // playable card in their hand and false otherwise.

    bool hasWon () const;
    // Postcondition: Returns true if the player has no cards remaining
    // in their hand and false otherwise.


    std::string getName () const;
    // Postcondition: Returns the player's name without modifying
    // the player object.
};

#endif