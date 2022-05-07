#pragma once
#include "Game.hpp"
namespace coup{
enum prevMove{Start,Income,Foreign_aid,Coup, Acoup, Steal,Transfer, Tax};
class prevPlayer{
public:
    bool PIsalive;
    unsigned int NumCoins;
    prevMove act;
    prevPlayer();
};
/*  @brief This obj holds a player refernce

    1. Id - this is uniqe id that will be recognize every player
    2. _name - of the player
    3. _role - what is the player card of charcter he is playing
    4. act - what is the player previous act
    5. IsAlive - a bool variable that hold if block is accept to relive the player.
    6. game - point to the game the player is part of.
    7. prevGame - will hold the situation at the begin of its turn. if it will be block we will start from here
    ^^ copy constractor ^^
    8._coin - save the numbers of coins the player hold

    functions:

    income()-> coins++
    forgienadd -> coins+=2
    coup(other player) -> killed the other player
    coins() return the number of coins the player hold
    check coins -> check if the player has more then 10 and need to coup now.
 */
class Game;
    class Player
    {
    public:
        unsigned int id;
        std::string _name;
        prevMove act;
        std::string _role;
        bool IsAlive;
        Game* game;       
        Player* influence;
        unsigned int _coin;
        unsigned int stolen;

        prevPlayer past;
        
        void income();  // the player takes one coin
        void foreign_aid(); // the player takes two coins ~~ if there is a duke he can prevent the taking 2 cions
        virtual void coup (Player&other); //cost 7 coins and kill one of the players
        unsigned int coins() const; // return the number of coins the player has.
        std::string Get_Name() const;
        
        
        
        unsigned int GetTurnId() const;
        void checkPossible();
        void checkCoup(Player& other);
        void checkCoins() const;
        void RemoveFromList(Player& other) const;
        Player(Game & meant,const char * name);
        void updatePast();

        Player* GetPlayer() const;
        void replay();






    };
    
    
}