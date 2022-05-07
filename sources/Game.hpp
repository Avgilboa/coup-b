#pragma once

#include <iostream>
#include <string>
#include <vector>
#include "Player.hpp"

/* @brief: this object calss holds the current stage of the game.
    1. The list of all the objects players that still in the game and they states
    2. pointer to the current turn 
    3. the numbers of players still playing
    4. boolean flag that know if the game already start or not

    function in this method:
        1. next -> move the turn to the next player (obj)
        2. players -> return vector contain the names of all the players by the order they join the game
        3. turn() -> return the current turn player name
        4. winner() -> if the game end it return the name of the winner player
    
        constractor to this method.

        ##### this method hold all the players that still playing ###
 */
namespace coup{
class Player;
class Game
{
    public: 
        bool begin;
        unsigned int p_turn;
        unsigned int NumPlayers;
        std::vector<Player*> actors;

        
        void next();
        void prev();
        
    
        std::vector<std::string> players();
        std::string turn(); /// print the turn of the current player
        std::string winner(); /// return the name of the winner
        Player* GetPlayerTurn();
        Game();
        ~Game(){};
};


}