#include"Enemy.h"
Enemy* create_enemy(string** Tilemap, int H, int W, int* quantity) {
	char name_enemy1 = 'C';
	char name_enemy2 = 'X';
	int quantity_ = 0;
	for (int i = 0; i < H; i++) {
		for (int j = 0; j < W; j++)
		{
			if (Tilemap[i][j] == name_enemy1 || Tilemap[i][j] == name_enemy2)
			{
				quantity_++;
			}
		}
	}
	*quantity = quantity_;
	if (quantity_ == 0) {
		Enemy* temp;

		return temp = 0;
	}
	Enemy* temp = new Enemy[quantity_];
	int c = 0;
	for (int i = 0; i < H; i++)
		for (int j = 0; j < W; j++) {
			if (Tilemap[i][j] == name_enemy1) {
				temp[c].x = j; temp[c].y = i; temp[c].symbol = name_enemy1; c++;
			}
			if (Tilemap[i][j] == name_enemy2) {
				temp[c].x = j; temp[c].y = i; temp[c].symbol = name_enemy2; c++;
			}
		}
	return temp;
}
//************************************************************************************************************************************
int move_enemy(string** TileMap, Enemy* enemy, int quantity, Player player) {
	if (quantity == 0)return 0;
	int player_x = player.rect.left / 16;
	int player_y = player.rect.top / 16;

	for (int c = 0; c < quantity; c++) {
		if (enemy[c].live == 0)continue;

		if ((enemy[c].y == player_y && enemy[c].x - 1 == player_x) || (enemy[c].y + 1 == player_y && enemy[c].x == player_x) || (enemy[c].y == player_y && enemy[c].x + 1 == player_x) || (enemy[c].y - 1 == player_y && enemy[c].x == player_x))return 1;


		switch (enemy[c].step) {

		case 1:

			if (TileMap[enemy[c].y - 1][enemy[c].x] == ' ') {
				TileMap[enemy[c].y - 1][enemy[c].x] = enemy[c].symbol;
				TileMap[enemy[c].y][enemy[c].x] = ' ';
				enemy[c].y--;
				enemy[c].step = 4;
			}
			else
				if (TileMap[enemy[c].y][enemy[c].x - 1] == ' ') {
					TileMap[enemy[c].y][enemy[c].x - 1] = enemy[c].symbol;
					TileMap[enemy[c].y][enemy[c].x] = ' ';
					enemy[c].x--;
				}

				else enemy[c].step = 2;
			break;
		case 2:

			if (TileMap[enemy[c].y][enemy[c].x - 1] == ' ') {
				TileMap[enemy[c].y][enemy[c].x - 1] = enemy[c].symbol;
				TileMap[enemy[c].y][enemy[c].x] = ' ';
				enemy[c].x--;
				enemy[c].step = 1;
			}
			else if (TileMap[enemy[c].y + 1][enemy[c].x] == ' ') {
				TileMap[enemy[c].y + 1][enemy[c].x] = enemy[c].symbol;
				TileMap[enemy[c].y][enemy[c].x] = ' ';
				enemy[c].y++;
			}
			else enemy[c].step = 3;
			break;
		case 3:

			if (TileMap[enemy[c].y + 1][enemy[c].x] == ' ') {
				TileMap[enemy[c].y + 1][enemy[c].x] = enemy[c].symbol;;//
				TileMap[enemy[c].y][enemy[c].x] = ' ';
				enemy[c].y++;
				enemy[c].step = 2;
			}
			else  if (TileMap[enemy[c].y][enemy[c].x + 1] == ' ') {
				TileMap[enemy[c].y][enemy[c].x + 1] = enemy[c].symbol;
				TileMap[enemy[c].y][enemy[c].x] = ' ';
				enemy[c].x++;

			}
			else enemy[c].step = 4;
			break;
		case 4:

			if (TileMap[enemy[c].y][enemy[c].x + 1] == ' ') {
				TileMap[enemy[c].y][enemy[c].x + 1] = enemy[c].symbol;
				TileMap[enemy[c].y][enemy[c].x] = ' ';
				enemy[c].x++;
				enemy[c].step = 3;
			}

			else if (TileMap[enemy[c].y - 1][enemy[c].x] == ' ') {
				TileMap[enemy[c].y - 1][enemy[c].x] = enemy[c].symbol;
				TileMap[enemy[c].y][enemy[c].x] = ' ';
				enemy[c].y--;
			}
			else  enemy[c].step = 1;
			break;

		}
	}
	return 0;
}