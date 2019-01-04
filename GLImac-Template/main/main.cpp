#include <View.hpp>
#include <Game.hpp>

int main(int argc, char** argv){
    Game game = Game();
    // game.init();
    game.run(argv[0]);
    return 0;
}