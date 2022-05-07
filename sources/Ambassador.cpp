#include "Ambassador.hpp"
using namespace std;
namespace coup{
    Ambassador::Ambassador(Game & meant,const char * name) : Player(meant, name){
        this->_role = "Ambassador";
        this->src = NULL;
        this->dst = NULL;
    }
    void Ambassador::transfer(Player& src, Player& dst){
        if(src.coins()==0){
            throw logic_error ("you have zero coins!!");
        }
        checkPossible();
        this->checkCoins();
            this->src = &src;
            this->dst = &dst;
            src._coin-=1;
            dst._coin+=1;
        this->game->next();
    }

    void Ambassador::block(Player& other){
      if(other._role=="Captain" && other.act==Steal){
                for (unsigned int i=0; i < this->stolen;i++){
                    other._coin-=1;
                    other.influence->_coin+=1;
                }
            }
            if(other._role!="Captain" || other.act!=Steal){
                throw logic_error ("cant block Captain");
            }
    }
    
    string Ambassador::role(){
        return string("Ambassador");
    }

}
