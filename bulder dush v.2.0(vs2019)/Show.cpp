#include"Show.h"
void show(RenderWindow& window, Sprite& sprite, string** TileMap, int* H, int* W, Flash flash, Player player) {
	window.clear(Color(25, 29, 25));
	for (int i = 0; i < *H; i++)
		for (int j = 0; j < *W; j++)
		{
			if (TileMap[i][j] == 'W')    sprite.setTextureRect(IntRect(32, 48, 16, 16));

			if (TileMap[i][j] == 'D')  sprite.setTextureRect(IntRect(flash.diamant_flash * 16, 128, 16, 16));

			if (TileMap[i][j] == 'H')    sprite.setTextureRect(IntRect(0, 48, 16, 16));

			if (TileMap[i][j] == '-')    sprite.setTextureRect(IntRect(64, 48, 16, 16));

			if (TileMap[i][j] == 'R')    sprite.setTextureRect(IntRect(80, 48, 16, 16));

			if (TileMap[i][j] == '0')    sprite.setTextureRect(IntRect(112, 96, 16, 16));

			if (TileMap[i][j] == '1')    sprite.setTextureRect(IntRect(112, 80, 16, 16));

			if (TileMap[i][j] == '2')    sprite.setTextureRect(IntRect(112, 64, 16, 16));

			if (TileMap[i][j] == 'S')    sprite.setTextureRect(IntRect(0, 48, 16, 16));

			if (TileMap[i][j] == 's')   sprite.setTextureRect(IntRect(16, 48, 16, 16));

			if (TileMap[i][j]== 'e')   sprite.setTextureRect(IntRect(16, 48, 16, 16));

			if (TileMap[i][j] == 'C')    sprite.setTextureRect(IntRect(80, 64 + (16 * flash.cube_flash), 16, 16));

			if (TileMap[i][j] == 'X')    sprite.setTextureRect(IntRect(96, 64 + (16 * flash.star_flash), 16, 16));

			if (TileMap[i][j] == ' ') { continue; }

			sprite.setPosition(static_cast<float>(j * 16 - player.offsetX), static_cast<float>(i * 16 - player.offsetY));
			window.draw(sprite);

		}
	//window.display();

}