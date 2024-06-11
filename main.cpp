#include "headers/GameSFML.h"

int main() {
    char *configFile = "./config.txt";
    GameSFML game(configFile);
    game.Run();
    return 0;
}
