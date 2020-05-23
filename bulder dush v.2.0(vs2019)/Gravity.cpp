#include "Gravityr.h"

int gravity(string** TileMap, int i, int j, int plx, int ply, Gamesound& stone_left, Gamesound& stone, Enemy* enemy, int qantity, int* count_enemy) {
	int count;
	if (TileMap[i + 1][j] == 'R' || TileMap[i + 1][j] == 'W') {
		if ((TileMap[i + 1][j + 1] == 'X' || TileMap[i + 1][j + 1] == 'C') && TileMap[i][j + 1] == ' ') {
			for (int c = 0; c < qantity; c++) {
				if (enemy[c].x == j + 1 && enemy[c].y == i + 1)*count_enemy = c;
			}
			count = *count_enemy;
			if (enemy[count].symbol == 'C')return 2;
			return 3;
		}
		if ((j + 1 == plx && i + 1 == ply) && TileMap[i][j + 1] == ' ')return 1;
		if (TileMap[i + 1][j + 1] == ' ' && TileMap[i][j + 1] == ' ') {
			//if(j+1==plx&&i+2==ply)return 1;
			TileMap[i + 1][j + 1] = TileMap[i][j];
			TileMap[i][j] = ' ';
			stone_left.play();
			return 0;
		}
		if ((TileMap[i + 1][j - 1] == 'X' || TileMap[i + 1][j - 1] == 'C') && TileMap[i][j - 1] == ' ') {
			for (int c = 0; c < qantity; c++) {
				if (enemy[c].x == j - 1 && enemy[c].y == i + 1)*count_enemy = c;
			}
			count = *count_enemy;
			if (enemy[count].symbol == 'C')return 2;
			return 3;
		}
		if ((j - 1 == plx && i + 2 == ply) && TileMap[i][j + 1] == ' ')return 1;
		if (TileMap[i + 1][j - 1] == ' ' && TileMap[i][j - 1] == ' ') {
			TileMap[i + 1][j - 1] = TileMap[i][j];
			TileMap[i][j] = ' ';
			stone_left.play();
			return 0;
		}
	}

	if (TileMap[i + 1][j] == 'X' || TileMap[i + 1][j] == 'C') {
		for (int c = 0; c < qantity; c++) {
			if (enemy[c].x == j && enemy[c].y == i + 1)*count_enemy = c;
		}
		count = *count_enemy;
		if (enemy[count].symbol == 'C')return 2;
		return 3;
	}
	if (TileMap[i + 1][j] != ' ')return 0;
	if (j == plx && i + 2 == ply)
	{
		return 1;
	}

	TileMap[i + 1][j] = TileMap[i][j];
	TileMap[i][j] = ' ';
	stone.play();
	return 0;
}
