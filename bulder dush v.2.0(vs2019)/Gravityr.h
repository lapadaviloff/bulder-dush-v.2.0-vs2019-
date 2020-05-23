#ifndef GRAVITY_H_
#define GRAVITY_H_
#include"Gamesound.h"
#include"Enemy.h"
using namespace sf;
using namespace std;



int gravity(string** TileMap, int i, int j, int plx, int ply, Gamesound& stone_left, Gamesound& stone, Enemy* enemy, int qantity, int* count_enemy);

#endif // !GRAVITY_H_

