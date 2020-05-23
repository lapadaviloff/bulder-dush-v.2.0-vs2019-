#ifndef SHOW_H_
#define SHOW_H_
#include <SFML/Graphics.hpp>
#include"Flash.h"
#include"Player.h"

using namespace sf;
using namespace std; void show(RenderWindow&, Sprite&, string** TileMap, int* H, int* W, Flash flash, Player player);

#endif // !SHOW_H_
