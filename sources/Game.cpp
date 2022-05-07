#include "Game.hpp"
using namespace std;
namespace coup{

/*  constractor
    starting turn is 0
    number of players in the game is 0 at the beggin
       */
    Game::Game(){
        this->begin = false;
        this->p_turn =0;
        this->NumPlayers =0;
    }
    /* iterate the turn to the next player in the vector. by using mod numOfPlayers  */
    void Game::next(){
        p_turn+=1;
        p_turn%=this->actors.size();
        if(!this->actors.at(p_turn)->IsAlive){
            next();
        }

    }

    void Game::prev(){
        p_turn-=1;
        p_turn%=this->actors.size();
    }

    /* iterate of the object players and make new vector of the names of the players */
    vector<string> Game::players(){
        vector<string> names;
        for(size_t i=0; i<this->actors.size();i++){
            if(this->actors.at(i)->IsAlive){
                names.push_back(this->actors.at(i)->Get_Name());}
        }
        return names;
    } 
    
    string Game::winner(){
        bool f=false;
        if(this->begin){
        for(size_t i=0; i<this->actors.size();i++){
            if(this->actors.at(i)->IsAlive){
                if (f){throw __EXCEPTION__ ("The Game is not ending yet");}
                f=true;
                }
        }
        for(size_t i=0; i<this->actors.size();i++){
            if(this->actors.at(i)->IsAlive){
                return this->actors.at(i)->Get_Name();
            }
        }
    }
        throw __EXCEPTION__ ("The Game is not ending yet");
    }

    string Game::turn(){
        return this->actors.at(this->p_turn)->Get_Name();
    }
    Player* Game::GetPlayerTurn(){
        return (this->actors.at(p_turn));
    }
}