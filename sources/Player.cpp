#include "Player.hpp"
using namespace std;
namespace coup{
class Game;
prevPlayer::prevPlayer(){
    this->act = Start;
    this->NumCoins =0;
    this->PIsalive =true;
}
const unsigned int NeedToCoup =7;
const unsigned int  NeedToCoupAss=3;
const unsigned int maxPlayer =5;
    Player::Player(Game & meant,const char * name){
        if(meant.begin || meant.actors.size()>maxPlayer){
            throw logic_error ("the game begin alreade");}
        this->_name = string(name);
        this->act = Start;
        this->IsAlive = true;
        this->influence = NULL;
        this->_coin = 0;
        this->stolen =0;
        this->game = &meant;
        this->past=prevPlayer();
        this->id = ++this->game->NumPlayers;
        this->game->actors.push_back(this);
        this->game = &meant;

    }

    void Player::updatePast(){
        this->past.act= this->act;
        this->past.NumCoins = this->_coin;
        this->past.PIsalive = this->IsAlive;
    }
    void Player::income(){
        try
        {
            checkPossible();
        }
        catch(const std::exception& e)
        {
            throw e;
        }
        
        this->checkCoins();
        this->act = Income;
        this->influence = NULL;
        this->_coin+=1;
        this->game->next();
    }
    void Player::foreign_aid(){
        checkPossible();
        this->checkCoins();
        this->game->next();
        this->act = Foreign_aid;
        this->influence = NULL;
        this->_coin+=2;
    }
    void Player::coup(Player& other){
        checkCoup(other);
        bool f = false;
        this->influence = &other;
        if(this->_coin>=NeedToCoup){
            f = true;
            this->act = Coup;
            this->_coin-=NeedToCoup;
            }
        if(this->_role =="Assassin" && this->_coin>=NeedToCoupAss && !f){
            this->act = Acoup;
            this->_coin-=NeedToCoupAss;
        }
        other.IsAlive = false;
        this->game->NumPlayers--;
        this->game->next();
    }
    unsigned int Player::coins() const{
        return this->_coin;
    }
    string Player::Get_Name() const{
        return this->_name;
    }

    unsigned int Player::GetTurnId() const{
        return this->id;
    }

    void Player::checkPossible(){
        if(this->game->actors.size()==1){
            throw logic_error ("1 player");
        }
        if(!this->IsAlive){
            throw logic_error ("this player is dead");
        }
        if(this->game->actors.at(this->game->p_turn)->id
                !=this->id){
                    throw logic_error ("this is not your turn to play");
                }
        this->game->begin = true;
        if(this->act == Coup || this->act== Acoup){
            RemoveFromList(*this->influence);
        }
        updatePast();
    }
    void Player::checkCoup(Player& other){
        if(!other.IsAlive){
            throw logic_error ("this player is dead");
        }
        if(this->_role=="Assassin" && this->coins()<NeedToCoupAss){
            throw logic_error ("Assassin you don't have enogh coins");
        }if(this->_role!="Assassin" && this->_coin<NeedToCoup){
            throw logic_error ("not Assassin you don't have enogh coins to coup");
        }
        checkPossible();
    }
    void Player::checkCoins() const{
        const unsigned int needCoup =10;
        if(this->coins()>=needCoup){
            throw runtime_error ("you have alot of coins use coup!");
        }
    }

    void Player::RemoveFromList(Player& other) const{
        // for(unsigned int i=0; i<this->game->actors.size();i++){
        //     if(this->game->actors.at(i)->id==other.id){
        //         this->game->actors.erase(this->game->actors.begin()+i);}
        // }
    }

    Player* Player::GetPlayer() const{
        return this->game->actors.at(this->game->p_turn);
    }

    void Player::replay(){
            this->_coin = this->past.NumCoins;
            this->act = this->past.act;
            this->IsAlive = this->past.PIsalive;
    }

}