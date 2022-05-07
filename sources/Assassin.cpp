#include "Assassin.hpp"
using namespace std;
namespace coup{
    /* do function iterate at the begining on the players id there is Is alive = false it kill him   */
    Assassin::Assassin(Game & meant,const char * name) : Player(meant, name){
        this->_role = "Assassin";
    }
    string Assassin::role(){
        return this->_role;
    }

    

}