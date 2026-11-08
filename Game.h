#ifndef GAME_H
#define GAME_H

#include "Card.h"
#include "Deck.h"
#include "Player.h"
#include "UserInterface.h"

const int STARTING_HAND_SIZE = 4;

class Game
{
public:
    Game();
    
    Game(int numPlayers);
    // Precondition:
    // numPlayers is between 2 and 4 inclusive.
    // Postcondition:
    // A dynamic array of numPlayers players has been created.
    // Player 1 is the current player and play is clockwise.

    Game(const Game& other);
    // Postcondition:
    // The new game is a deep copy of other. It has its own dynamic array
    // of players holding the same hands, and the same deck, current
    // player, and direction as other.

    Game& operator=(const Game& other);
    // Postcondition:
    // The old players array of this game has been deleted, and this game
    // is now a deep copy of other. Self-assignment leaves the game
    // unchanged. Returns a reference to this game.

    ~Game();
    // Postcondition:
    // The dynamic array of players has been deleted.

    void setup();
    // Postcondition:
    // The deck has been shuffled, each player has been dealt
    // STARTING_HAND_SIZE cards, and a number card has been placed
    // on the discard pile to start the game.

    void run();
    // Precondition:
    // setup has been called.
    // Postcondition:
    // Turns have been played until a player has no cards left,
    // and that player has been announced as the winner.

private:
    void takeTurn();
    // Postcondition:
    // The current player has played a card or drawn cards.
    // Viewing the hand or making an invalid play does not end the turn.

    bool isValidPlay(Card card);
    // Postcondition:
    // Returns true if card matches the top discard card by colour,
    // number, or symbol, or if card is a Wild.
    // A Wild Draw Four is only valid if the current player has no card
    // matching the current colour. Otherwise, returns false.

    void playCard(int cardIndex);
    // Precondition:
    // cardIndex is a position in the current player's hand and
    // the card at that position is a valid play.
    // Postcondition:
    // The card has been removed from the hand, placed on the discard
    // pile, and its effect has been applied.

    void drawUntilPlayable();
    // Postcondition:
    // The current player has drawn cards until a playable card is received.
    // If no playable card is left in the deck, the turn ends.

    void applyCardEffect(Card card);
    // Postcondition:
    // The effect of card has been applied:
    // Skip: the next player loses their turn.
    // Reverse: the direction is reversed (acts as Skip with 2 players).
    // Draw Two: the next player draws 2 cards and loses their turn.
    // Wild: the current player chooses a new colour.
    // Wild Draw Four: the current player chooses a new colour, and the next
    // player draws 4 cards and loses their turn.
    // Number cards have no effect.

    void forceDraw(int numCards);
    // Precondition:
    // numCards is greater than 0.
    // Postcondition:
    // The next player has drawn numCards cards.

    void advanceTurn(int skips);
    // Precondition:
    // skips is 0 or greater.
    // Postcondition:
    // The current player has moved to the next player in the current
    // direction, passing over skips players and wrapping around.

    bool checkWinner();
    // Postcondition:
    // Returns true if the current player has no cards left.
    // Otherwise, returns false.

    Player* players;     // Dynamic array of players
    Deck deck;
    UserInterface ui;
    int numPlayers;
    int currentPlayer;   // Index of the player whose turn it is
    int direction;       // 1 = clockwise, -1 = counter-clockwise
};

#endif