#ifndef ENEMY_H_
#define ENEMY_H_
#include <cstring>
#include"Player.h"
//using namespace sf;
using namespace std;
struct Enemy {
	Enemy() :x(0), y(0), step(1), live(1), symbol('-') {};
	int x, y, step, live;
	char symbol;
};

Enemy* create_enemy(string** Tilemap, int H, int W, int* quantity);
int move_enemy(string** TileMap, Enemy* enemy, int quantity, Player player);


#endif
