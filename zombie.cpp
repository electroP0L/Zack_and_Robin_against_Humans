#include "zombie.hpp"

Zombie::Zombie(SDL_Texture* texture, SDL_Renderer* renderer){
  SDL_QueryTexture(texture, NULL, NULL, &this->rect.w, &this->rect.h);
  rect.w /= 6;
  rect.h /= 6;
  setpos(0 + 10, SCREEN_HEIGHT - rect.h);
  hitbox = rect;
} 

void Zombie::bouger(Command cmd){
  const Uint8 *keyboard_state = cmd.getKeyboardState();
  if (keyboard_state[SDL_SCANCODE_W]) {this->rect.y -= 300 / 70;}
  if (keyboard_state[SDL_SCANCODE_S]) {this->rect.y += 300 / 70;}
  if (keyboard_state[SDL_SCANCODE_A]) {this->rect.x -= 300 / 70;}
  if (keyboard_state[SDL_SCANCODE_D]) {this->rect.x += 300 / 70;}
  // Gestion des déplacements diagonaux
  if (keyboard_state[SDL_SCANCODE_W] && keyboard_state[SDL_SCANCODE_A]) {
    this->rect.y -= 300 / 500;
    this->rect.x -= 300 / 500;
  }
  if (keyboard_state[SDL_SCANCODE_W] && keyboard_state[SDL_SCANCODE_D]) {
    this->rect.y -= 300 / 500;
    this->rect.x += 300 / 500;
  }
  if (keyboard_state[SDL_SCANCODE_S] && keyboard_state[SDL_SCANCODE_A]) {
    this->rect.y += 300 / 500;
    this->rect.x -= 300 / 500;
  }
  if (keyboard_state[SDL_SCANCODE_S] && keyboard_state[SDL_SCANCODE_D]) {
    this->rect.y += 300 / 500;
    this->rect.x += 300 / 500;
  }


  // Screen bounds
  if (this->rect.x + this->rect.w > SCREEN_WIDTH){this->rect.x = SCREEN_WIDTH - this->rect.w;}
  if (this->rect.x < 0){this->rect.x = 0;}
  if (this->rect.y + this->rect.h > SCREEN_HEIGHT){this->rect.y = SCREEN_HEIGHT - this->rect.h;}
  if (this->rect.y < 0){this->rect.y = 0;}


  //Ajouter le traitement des obstacles
}