#ifndef UNOCARD_H
#define UNOCARD_H

#include <iostream>
#include <string>

// enum only accepts the variables within the scope
// not case sensitive
enum class cardColor{RED, BLUE, GREEN, YELLOW, WILD};
enum class cardType{NUMBER, SKIP, REVERSE, WILD, DRAW_TWO, DRAW_FOUR};

class Card {
private:
    cardColor color;
    cardType type;
    int number; // number 0-9, action cards = -1

public:
    // default constructor
    Card(); 

    // parameterized constructor 
    // pre condition: c is a valid cardColor, t is a valid cardType. If t is NUMBER, num is 0-9
    // post condition: card object initialized with type and color
    Card(cardColor c, cardType t, int num = -1); 
    
    // destructor
    ~Card();
    
    // getter functions
    cardColor getColor() const;
    cardType getType() const;
    int getNumber() const;

    // setter function for setting a new color when a player uses a wild card
    // pre condition: newColor is a valid cardColor enum
    // post condition: The card's internal color variable is updated to newColor. Type and number stays same
    void setColor(cardColor newColor);

    // to check if the current playing card is a valid card to place on top of the pile
    // pre condition: topCard is a valid object representing the top card of the card pile
    // post condition: returns true if this card is a Wild or Wild Draw Four, or if it has
    // the same color as topCard, or if both cards are NUMBER cards with the same number,
    // or if both cards are the same action type (Skip, Reverse, Draw Two).
    // Two NUMBER cards with different colors and different numbers do NOT match.
    // The cards are not modified.                                          // NEW
    bool isValid(const Card& topCard) const;

    // overloading insertion operator for printing out card's detail
    // pre condition: os is a functional output stream and card is a fully initialized card object
    // post condition: readable string is pushed to output stream. Returned by reference
    friend std::ostream& operator<<(std::ostream& os, const Card& card);
};

#endif
