#ifndef PLAYER_H
#define PLAYER_H

#include <iostream>
#include <string>          
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
    Player ();         
    // Postcondition: Creates a player with an empty name and an empty
    // hand containing no cards. Needed so Game can create an array of
    // players with new Player[numPlayers].

    Player (std::string name);
    // Precondition: name contains the player's name.
    // Postcondition: Creates a player with the specified name and
    // an empty hand containing no cards.

    Player (const Player& other);  
    // Precondition: other is a valid Player.
    // Postcondition: Creates a deep copy of other. The new player has
    // the same name and the same cards in the same order, stored in
    // separate memory locations.

    Player& operator= (const Player& other);   
    // Postcondition: If this player and other are the same object,
    // nothing changes. Otherwise, this player's old hand is released and
    // this player becomes a deep copy of other. Returns a reference to
    // this player.

    ~Player ();
    // Postcondition: All dynamically allocated memory used by the
    // player's hand is released and the player object is destroyed.


    void setName (std::string newName);   
    // Postcondition: The player's name is changed to newName.
    // The hand is not modified.

    void drawCard (const Card& card);
    // Precondition: card is a valid Card object.
    // Postcondition: card is added to the player's hand and the
    // number of cards in the hand is increased by one.

    void displayHand() const;
    // Precondition: None.
    // Postcondition: Displays all cards currently in the player's
    // hand. The player's hand is not modified.


    Card playCard (int index);
    // Precondition: index is a 0-based position in the player's hand,
    // from 0 to getNumCards() - 1.
    // Postcondition: The selected card is removed from the player's
    // hand and returned. The number of cards is decreased by one.

    Card getCard (int index) const;  
    // Precondition: index is a 0-based position in the player's hand,
    // from 0 to getNumCards() - 1.
    // Postcondition: Returns a copy of the card at index. The hand is
    // not modified.

    int getNumCards () const;  
    // Postcondition: Returns the number of cards in the player's hand.


    bool isValidPlay (int index, const Card& topCard) const;
    // Precondition: index is a 0-based position in the player's hand,
    // from 0 to getNumCards() - 1.
    // Postcondition: Returns true if the card at index can legally
    // be played on topCard according to UNO rules, and false otherwise.

    bool hasPlayableCard (const Card& card) const;
    // Precondition: card represents the current top card or current
    // game state being checked.
    // Postcondition: Returns true if the player has at least one
    // playable card in their hand and false otherwise.

    bool hasColor (cardColor c) const;  
    // Precondition: c is a valid cardColor.
    // Postcondition: Returns true if the player holds at least one card
    // of colour c, and false otherwise. Used for the Wild Draw Four
    // restriction. The hand is not modified.

    bool hasWon () const;
    // Postcondition: Returns true if the player has no cards remaining
    // in their hand and false otherwise.


    std::string getName () const;
    // Postcondition: Returns the player's name without modifying
    // the player object.
};

#endif
