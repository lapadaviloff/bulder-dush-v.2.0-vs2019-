#ifndef START_DELETE_H_
#define START_DELETE_H_
#include"Enemy.h"
#include "Win.h"
#include <fstream>
#include <sstream>
#include"Int_str.h"
using namespace sf;
using namespace std;

string** start(int number_level, int* H_, int* W_, Win* win);
void delete_map(string** TileMap, int* H, Enemy* cube, int qantity);


#endif // !START_DELETE_H_

