#include "Init.h"
void init() {





}

void set_player(RenderWindow& window, Sprite& sprite, Player& player, string** TileMap, int* H, int* W, int time, Gamesound& sound) {

	Flash f;
	int x = 1, y = 1;
	for (int i = 0; i < *H; i++) {
		for (int j = 0; j < *W; j++)
		{
			if (TileMap[i][j] == 'S') { TileMap[i][j] = ' '; y = j; x = i; }

		}
	}
	player.rect = IntRect(y * 16, x * 16, 16, 16);
	if (player.rect.left > 208) player.offsetX = player.rect.left - 208;// установка игрока по центру
	else player.offsetX = 0;
	if (player.rect.top > 123)player.offsetY = player.rect.top - 123;
	else player.offsetY = 0;
	player.update(time);
	for (int c = 0; c < 2; c++) {
		TileMap[x][y] = 'S';
		show(window, sprite, TileMap, H, W, f, player);
		window.display();
		sound.play();
		for (int t = 0; t < 30; t++) { Sleep(time); }
		TileMap[x][y] = 's';
		show(window, sprite, TileMap, H, W, f, player);
		window.display();
		for (int t = 0; t < 30; t++) { Sleep(time); }
		sound.play();
	}

}