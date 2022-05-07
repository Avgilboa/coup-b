#include "Game.hpp"
namespace coup{
    class Duke:public Player{
    public:
        Duke(Game & meant,const char * name);
        void block(Player &other); //can block forgien add
        void tax();
        std::string role();

    };
}