# ProjectUno
ENSC251 Project

# Group: Goup
Amir Farahani | amf24@sfu.ca | 301650847
John Cha | jca641@sfu.ca | 301653022
Ryan Pineda | rpa99@sfu.ca | 301649747
Ryan Nave | grn1@sfu.ca | 301624051

# Game: UNO
This project is a two-player terminal card game based on the real-life card game, UNO.
It is intended for a project for ENSC251 at SFU

## Rules
Each player is dealt seven random cards hidden from the other players. The remaining cards form a draw pile, and the top card is placed face-up to start the discard pile. Players take turns playing one card that matches the top discard card by colour, number, or symbol. If a player cannot play a matching card, they must draw one card from the draw pile. Number cards have no special effects. Skip cards cause the next player to lose their turn, Reverse cards change the direction of play, Draw Two cards force the next player to draw two cards and lose their turn, Wild cards allow the player to choose the next colour, and Wild Draw Four cards allow the player to choose the next colour and force the next player to draw four cards and lose their turn. A Wild Draw Four can only be played when the player has no cards matching the current colour. When a player has one card remaining, they must declare "UNO." If they fail to do so before the next player begins their turn, they must draw two penalty cards if caught. The first player to play all their cards wins. If the draw pile runs out, the discard pile is reshuffled to form a new draw pile. 
For a more detailed explanation, visit https://www.unorules.com/ .

# Team Responsibilites

## Amir Farahani – Game Logic and Turn Management
Responsible for implementing the main game loop, managing turn order, validating player moves, determining the winner, and implementing special card effects (Skip, Reverse, Draw Two, and Wild cards).

## John Cha – Card and Deck Management
Responsible for implementing the Card and Deck classes, including card attributes (colour, number, and type), deck initialization, random shuffling, dealing cards, drawing cards, and managing the discard pile.

## Ryan Pineda – Player and Hand Management
Responsible for implementing the Player class and managing individual player hands. This includes adding and removing cards, displaying player hands, checking playable cards, and tracking the number of cards each player holds.

## Ryan Nave – User Interface and Input Handling
Responsible for implementing the text-based user interface, handling player input, displaying game information and error messages, managing player transitions, and clearing the terminal to maintain hand privacy. Also responsible for initiating and organizing the Git system that will be used for collaboration.


