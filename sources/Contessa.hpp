#include "Game.hpp"

namespace coup{
    class Contessa:public Player{
    public:
        Contessa(Game & meant,const char * name);
        void block(Player& other); ///block the assasian from coup
        std::string role();
    };
}