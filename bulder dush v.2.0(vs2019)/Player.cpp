#include"Player.h"

Player::Player(Texture& image, string** t)
	{
		sprite.setTexture(image);
		sprite.setTextureRect(IntRect(16, 0, 16, 16));
		rect = IntRect(1 * 16, 1 * 16, 16, 16);
		diamant = 0;
		dx = dy = 0;
		currentFrame = 0;
		TileMap = t;
		live = 1;
		offsetX = 0;
	    offsetY = 0;

		try {
			if (!(sound_bufer.loadFromFile("resource/sound/almaz.wav")))throw L"sound not load";//загружаем в него звук
		}
		catch (LPCTSTR s) {
			MessageBox(GetActiveWindow(), s, L"Boulder dash", MB_ICONERROR);
			exit(1);

		}
		almaz.setBuffer(sound_bufer);
	}

	void Player:: update(DWORD time)
	{

		Collision();   //проверка на столкновение

		rect.left += dx;

		rect.top += dy;

		if (currentFrame > 6) currentFrame -= 6; //смена спрайта двмженмя

		if (dx > 0)sprite.setTextureRect(IntRect(16 * int(currentFrame), 32, 16, 16));

		if (dx < 0) sprite.setTextureRect(IntRect(16 * int(currentFrame) + 16, 32, -16, 16));

		if (dy > 0)sprite.setTextureRect(IntRect(16 * int(currentFrame), 0, 16, 16));

		if (dy < 0) sprite.setTextureRect(IntRect(32, 0, 16, 16));

		for (int i = 0; i < 10; i++) { Sleep(time); }// задержка в игре
		currentFrame++;
		sprite.setPosition(static_cast<float>(rect.left - offsetX), static_cast<float>(rect.top - offsetY)); // установка игрока на поле

		dx = 0;
		dy = 0;
	}

	void Player:: Collision()
	{
		int i = (rect.top) / 16;
		int j = (rect.left) / 16;
		if (dx > 0 && (TileMap[i][j + 1] == 'R' && TileMap[i][j + 2] == ' ')) { TileMap[i][j + 2] = 'R'; TileMap[i][j] = ' '; TileMap[i][j + 1] = '-';  return; }
		if (dx < 0 && (TileMap[i][j - 1] == 'R' && TileMap[i][j - 2] == ' ')) { TileMap[i][j - 2] = 'R'; TileMap[i][j] = ' '; TileMap[i][j - 1] = '-';  return; }
		if (dx > 0 && (TileMap[i][j + 1] == 'W' || TileMap[i][j + 1] == 'H' || TileMap[i][j + 1] == 'R')) { dx = 0; return; }  //проверка на столкновение
		if (dx < 0 && (TileMap[i][j - 1] == 'W' || TileMap[i][j - 1] == 'H' || TileMap[i][j - 1] == 'R')) { dx = 0; return; }
		if (dy > 0 && (TileMap[i + 1][j] == 'W' || TileMap[i + 1][j] == 'H' || TileMap[i + 1][j] == 'R')) { dy = 0; return; }
		if (dy < 0 && (TileMap[i - 1][j] == 'W' || TileMap[i - 1][j] == 'H' || TileMap[i - 1][j] == 'R')) { dy = 0; return; }

		if (TileMap[i][j] == 'D')
		{
			diamant += 1;// собираем кристал
			TileMap[i][j] = '-';
			almaz.play();
		}


		if ((dx + dy) != 0)TileMap[i][j] = ' ';
	}

	