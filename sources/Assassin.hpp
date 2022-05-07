#include "Game.hpp"

namespace coup{

    class Assassin:public Player{
    public:
        Assassin(Game & meant,const char * name);
        std::string role();
    };
}