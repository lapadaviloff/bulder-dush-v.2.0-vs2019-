#ifndef INIT_H_
#define INIT_H_
#include <SFML/Graphics.hpp>
#include"Player.h"
#include"Gamesound.h"
#include"Flash.h"
#include"Show.h"
using namespace sf;
using namespace std;

void set_player(RenderWindow& window, Sprite& sprite, Player& player, string** TileMap, int* H, int* W, int time, Gamesound& sound);
void init(); 

#endif // !INIT_H_

