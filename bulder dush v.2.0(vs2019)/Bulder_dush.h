#ifndef BUOLDER_DUSH_H_
#define BUOLDER_DUSH_H_
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
#include <Windows.h>
#include <sstream>
#include <cstring>
#include <fstream>
#include"Gamesound.h"
#include"Player.h"
#include"Flash.h"
#include"Enemy.h"
#include "Win.h"
using namespace sf;
using namespace std;

int gravity(string**, int, int, int, int, Gamesound&, Gamesound&, Enemy* enemy, int qantity, int* count_enemy);
int string_to_int(string);
string int_to_string(int);
string** start(int number_level, int* H_, int* W_, Win* win);
void delete_map(string** TileMap, int* H, Enemy* cube, int qantity);
void show(RenderWindow&, Sprite&, string** TileMap, int* H, int* W, Flash flash, Player player);
void set_player(RenderWindow& window, Sprite& sprite, Player& player, string** TileMap, int* H, int* W, int time, Gamesound& sound);
Enemy* create_enemy(string** Tilemap, int H, int W, int* quantity);
int move_enemy(string** TileMap, Enemy* enemy, int quantity, Player player);

#endif 