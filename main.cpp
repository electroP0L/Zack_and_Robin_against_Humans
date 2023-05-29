#include "game.hpp"

String path = "Bureau/Informatique/"; // Chemin vers le dossier contenant le projet

int main(int argc, char** argv)
{
  Game game(path);

  game.run();

  return 0;
}