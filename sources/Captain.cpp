#include "Captain.hpp"
using namespace std;
namespace coup{
    Captain::Captain(Game & meant,const char * name) : Player(meant, name){
        this->_role = "Captain";
        this->stolen = 0; 
    }

    void Captain::block(Player& other){
        if(other._role=="Captain" && other.act==Steal){
                for (unsigned int i=0; i < this->stolen;i++){
                    other._coin--;
                    other.influence->_coin++;
                }
            }
            if(other._role!="Captain" || other.act!=Steal){
                throw logic_error ("cant block Captain");
            }
    }

    void Captain::steal(Player & other){
        checkPossible();
        this->checkCoins();
        if(other._coin==1){
            this->stolen =1;
            this->_coin+=1;
            other._coin-=1;
        }
        if(other._coin==2){
            this->stolen =2;
            this->_coin+=2;
            other._coin-=2;
        }
        this->act = Steal;
        this->influence = &other;
        this->game->next();
    }

    string Captain::role(){
        return this->_role;
    }

}