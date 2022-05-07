#include "Contessa.hpp"
using namespace std;
namespace coup{
    Contessa::Contessa(Game & meant,const char * name) : Player(meant, name){
        this->_role = "Contessa";
    }
    void Contessa::block(Player& other){
        bool f = false;
         if(other._role == "Assassin"  && other.act == Acoup){
             f= true;
                other.influence->IsAlive = true;
                for(unsigned int i=0; i<this->game->actors.size();i++){
                    if(this->game->actors.at(i)->id==other.id){
                        this->game->actors.at(i)->IsAlive=true;
                    }
                }
            }
            if(!f){
                throw logic_error ("cant do contessa block!");
         }
    }
    string Contessa::role(){
        return this->_role;
    }
}