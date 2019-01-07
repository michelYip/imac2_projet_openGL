#include <View.hpp>
#include <Game.hpp>

int main(int argc, char** argv){
    Game game = Game();
    game.run(argv[0]);
	return EXIT_SUCCESS;
}