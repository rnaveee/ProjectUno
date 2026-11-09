#ifndef UNODECK_H
#define UNODECK_H

#include "UnoCard.h"

class Deck {
private:
    // define private node
    struct Node {
    Card card;
    Node* link;
    };
    typedef Node* NodePtr;

    int numCards;
    NodePtr head;

public:
    Deck ();
    //Postcondition: Creates an empty deck with 0 cards.

    Deck (const Deck& d);
    //Precondition: d is a valid deck
    //Postcondition: Creates a deep copy of d. The new deck contains
    //the same cards as d but stored in separate memory locations.

    ~Deck ();
    // Postcondition: All dynamically allocated memory used by the deck
    // is released and the deck is destroyed.


    int getNumCards () const;
    // Postcondition: Returns the current number of cards in the deck.


    Card viewTopCard();
    // Precondition: The deck is not empty.
    // Postcondition: Returns the top card of the deck without removing it.
    Card drawTopCard();
    // Precondition: The deck is not empty.
    // Postcondition: Removes the top card from the deck and returns it.
    // The number of cards in the deck is decreased by one.


    bool addCard (Card c);
    // Precondition: c is a valid Card object.
    // Postcondition: Adds c to the top of the deck and increases the
    // number of cards by one. Returns true if successful.

    bool isEmpty () const;
    // Postcondition: Returns true if the deck contains no cards and
    // false otherwise.


    void buildDeck ();
    // Precondition: The deck exists and can store cards.
    // Postcondition: The deck is populated with all cards required for
    // an UNO game. Any cards added are placed into the deck and the
    // number of cards is updated accordingly.

    void printDeck() const;
    // Postcondition: Displays all cards currently stored in the deck.
    // The deck itself is not modified.

    void shuffle ();
    // Precondition: The deck contains zero or more cards.
    // Postcondition: Randomly rearranges the order of cards in the deck.


    Deck& operator=(const Deck& d);
    // Precondition: d is a valid Deck object and is not the same object
    // as the destination deck.
    // Postcondition: The destination deck becomes a deep copy of d.
    // Any existing cards in the destination deck are properly released.
};

#endif