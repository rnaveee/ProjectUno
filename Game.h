#ifndef GAME_H
#define GAME_H

#include "UnoCard.h"
#include "UnoDeck.h"
#include "Player.h"
#include "UserInterface.h"

const int STARTING_HAND_SIZE = 4;

class Game
{
public:
    Game();
    // Postcondition:
    // A 2-player game has been created. Same as Game(2).

    Game(int numPlayers);
    // Precondition:
    // numPlayers is between 2 and 4 inclusive.
    // Postcondition:
    // A dynamic array of numPlayers players, named "Player 1",
    // "Player 2", and so on, has been created. The draw pile and discard
    // pile are empty. Player 1 is the current player and play is clockwise.

    Game(const Game& other);
    // Postcondition:
    // The new game is a deep copy of other. It has its own dynamic array
    // of players holding the same hands, and the same draw pile, discard
    // pile, current player, and direction as other.

    Game& operator=(const Game& other);
    // Postcondition:
    // If this game and other are the same object, nothing changes.
    // Otherwise, the old players array has been deleted and this game is
    // now a deep copy of other. Returns a reference to this game.

    ~Game();
    // Postcondition:
    // The dynamic array of players has been deleted.

    void setup();
    // Postcondition:
    // The draw pile has been built and shuffled, each player has been
    // dealt STARTING_HAND_SIZE cards, and a number card has been moved
    // to the discard pile to start the game. If the flipped card is not a
    // number card, it is returned to the draw pile, the pile is reshuffled,
    // and a new card is flipped.

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
    // Menu choices are 1-based, and are converted to 0-based indexes
    // before calling Player functions.

    bool isValidPlay(Card card);
    // Postcondition:
    // Returns true if card.isValid(top discard card) is true. A Wild Draw
    // Four is only valid if the current player has no card matching the
    // current colour. Otherwise, returns false.
    // The game state is unchanged.

    void playCard(int cardIndex);
    // Precondition:
    // cardIndex is a 0-based position in the current player's hand and
    // the card at that position is a valid play.
    // Postcondition:
    // The card has been removed from the hand, placed on the discard
    // pile, and its effect has been applied.

    void drawUntilPlayable();
    // Postcondition:
    // The current player has drawn cards from the draw pile until
    // isValidPlay is true for a drawn card, and is then prompted to play.
    // If the draw pile is empty, the discard pile (except its top card) is
    // reshuffled into it. If no playable card remains, the turn ends.

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
    // The next player has drawn numCards cards from the draw pile.
    // The discard pile is reshuffled into it if it runs out.

    void reshuffleDiscardPile();
    // Precondition:
    // The draw pile is empty and the discard pile has more than one card.
    // Postcondition:
    // All discard pile cards except the top card have been moved to the
    // draw pile and shuffled. Any Wild card moved has its colour reset
    // to WILD. The top discard card stays in place.

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
    Deck drawPile;
    Deck discardPile;
    UserInterface ui;
    int numPlayers;
    int currentPlayer;   // 0-based index of the player whose turn it is
    int direction;       // 1 = clockwise, -1 = counter-clockwise
};

#endif
