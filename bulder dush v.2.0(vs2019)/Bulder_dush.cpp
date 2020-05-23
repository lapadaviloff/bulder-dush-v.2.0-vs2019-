// bulder dush v.2.0(vs2019).cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//miam.devsoft@gmail.com
//19.05.2020

#include"Bulder_dush.h"
int main()
{
	// 	SetConsoleCP(1251);
	// 	SetConsoleOutputCP(1251);
	// 	setlocale(LC_ALL, "Russian");


	Gamesound sound_step1("resource/sound/step1.wav");
	Gamesound sound_step2("resource/sound/step2.wav");
	Gamesound sound_stone("resource/sound/stone.wav");
	Gamesound sound_stone_left("resource/sound/stone_left.wav");
	Gamesound sound_life("resource/sound/life2.wav");
	Gamesound sound_almaz("resource/sound/almaz.wav");
	Gamesound start_door("resource/sound/start_door.wav");
	Gamesound door("resource/sound/door.wav");



	int time = 10, H, W, i, j, max_level; //скорость игры,размер игрового поля, количество алмазов для следующего уровня, максимальное количество карт
	Win win;							   // устанавливается в start
	int number_level = 1;
	bool gameover(false);
	win.flag_win = false;
	bool rockfall = false; //пропуск первой проверки камней
	int quantity;   
	Flash flash;   //моргание обьекта
	int pldy = 0;// двигался игрок или нет
	bool button_no_press = true;
	int kill = 0;
	int count_enemy = 0;
	string** TileMap = start(number_level, &H, &W, &win);
	Enemy* enemy = create_enemy(TileMap, H, W, &quantity);

	RenderWindow window(VideoMode(400, 225), "boulder dash");

	Texture texture;

	try {
		if (!(texture.loadFromFile("resource/fang.png")))throw L"texture not load";//загружаем в него звук
	}
	catch (LPCTSTR s) {
		MessageBox(GetActiveWindow(), s, L"Boulder dash", MB_ICONERROR);
		exit(1);
	}
	Font font;//шрифт 

	try {
		if (!(font.loadFromFile("resource/Impact Regular.ttf")))throw L"Font not load";//загружаем в него звук
	}
	catch (LPCTSTR s) {
		MessageBox(GetActiveWindow(), s, L"Boulder dash", MB_ICONERROR);
		exit(1);
	}

	Sprite sprite_map(texture);

	float currentFrame = 0;
	Player mario(texture, TileMap);

	std::ifstream  fil("resource/game.cfg");
	if (!fil.is_open()) {
		MessageBox(GetActiveWindow(), L"not load game.cfg!", L"Boulder dash", MB_ICONERROR);
		exit(1);
	}
	string temp = "";
	getline(fil, temp, '\n');
	time = string_to_int(temp);
	getline(fil, temp, '\n');
	mario.live = string_to_int(temp);
	getline(fil, temp, '\n');
	max_level = string_to_int(temp);
	fil.close();
	//	Clock clock;
	set_player(window, sprite_map, mario, TileMap, &H, &W, time, start_door);
	while (window.isOpen())
	{
		Event event;
		while (window.pollEvent(event)) {
			if (event.type == Event::Closed) { window.close(); exit(0); }

		}

		if (button_no_press && Keyboard::isKeyPressed(Keyboard::Add)) time += 1;

		if (Keyboard::isKeyPressed(Keyboard::Subtract)) time -= 1;

		if (time < 0)time = 0;

		button_no_press = true;// запрешаеи нажатия двух клавиш одновременно

		if (button_no_press && Keyboard::isKeyPressed(Keyboard::Left)) { mario.dx = -16; sound_step1.play(); button_no_press = false; }

		if (button_no_press && Keyboard::isKeyPressed(Keyboard::Right)) { mario.dx = 16; sound_step1.play(); button_no_press = false; }

		if (button_no_press && Keyboard::isKeyPressed(Keyboard::Up)) { mario.dy = -16; sound_step2.play(); button_no_press = false; }

		if (button_no_press && Keyboard::isKeyPressed(Keyboard::Down)) { mario.dy = 16; sound_step2.play(); button_no_press = false; }

		if (mario.dx + mario.dy == 0)mario.sprite.setTextureRect(IntRect(16, 0, 16, 16));

		if (mario.rect.left > 208)mario.offsetX = mario.rect.left - 208;// установка игрока по центру
		else mario.offsetX = 0;

		if (mario.rect.top > 123)mario.offsetY = mario.rect.top - 123;
		else mario.offsetY = 0;

		window.clear(Color(25, 29, 25));

		if (pldy - mario.dy == 0) { rockfall = true; pldy = mario.dy; }
		else { rockfall = false; pldy = mario.dy; }
		mario.update(time);
		show(window, sprite_map, TileMap, &H, &W, flash, mario);
		kill = move_enemy(TileMap, enemy, quantity, mario);

		if (rockfall) {        // пропуск одного камня 
			for (i = H - 1; i > 0; i--) {
				for (j = W - 1; j > 0; j--) {
					if (TileMap[i][j] == 'R') {  // если встретился камень
						kill = gravity(TileMap, i, j, mario.rect.left / 16, mario.rect.top / 16, sound_stone_left, sound_stone, enemy, quantity, &count_enemy);
					}
					if (kill == 1)
					{   // если камень попал по игроку
						TileMap[win.x][win.y] = 'E';
						win.flag_win = false;
						kill = 0;
						mario.diamant = 0;
						int x, y;
						for (int c = 0; c < 3; c++) {
							for (int i_ = 0; i_ < 3; i_++) {
								for (int j_ = 0; j_ < 3; j_++) {  //рисуем взрыв камня

									y = i_ - 1 + mario.rect.left / 16;
									x = j_ - 1 + mario.rect.top / 16;

									if (TileMap[x][y] != 'H')	TileMap[x][y] = int_to_string(c);
								}
							}
							show(window, sprite_map, TileMap, &H, &W, flash, mario);
							window.display();
							for (int t = 0; t < 30; t++) { Sleep(time); }
						}
						mario.live--;
						if (mario.live == 0)gameover = true;
						delete_map(TileMap, &H, enemy, quantity);
						TileMap = start(number_level, &H, &W, &win);
						mario.TileMap = TileMap;
						set_player(window, sprite_map, mario, TileMap, &H, &W, time, start_door);
						enemy = create_enemy(TileMap, H, W, &quantity);

					}

					if (kill == 2)
					{   // если камень попал по врагу
						enemy[count_enemy].live = 0;
						//quantity--;
						kill = 0;
						int x, y;
						for (int c = 0; c < 2; c++) {
							for (int i_ = 0; i_ < 3; i_++) {
								for (int j_ = 0; j_ < 3; j_++) {  //рисуем взрыв камня
									y = i_ - 1 + enemy[count_enemy].x;
									x = j_ - 1 + enemy[count_enemy].y;
									if (TileMap[x][y] != 'H')	TileMap[x][y] = int_to_string(c);
									if (TileMap[x][y] != 'H' && c >= 1)	TileMap[x][y] = ' ';
								}
							}
							show(window, sprite_map, TileMap, &H, &W, flash, mario);
							window.display();
							for (int t = 0; t < 30; t++) { Sleep(time); }
						}

					}
					if (kill == 3)
					{   // если камень попал по врагу X
						enemy[count_enemy].live = 0;
						//quantity--;
						kill = 0;
						int x, y;
						for (int c = 0; c < 2; c++) {
							for (int i_ = 0; i_ < 3; i_++) {
								for (int j_ = 0; j_ < 3; j_++) {  //рисуем взрыв камня
									y = i_ - 1 + enemy[count_enemy].x;
									x = j_ - 1 + enemy[count_enemy].y;
									if (TileMap[x][y] != 'H')	TileMap[x][y] = int_to_string(c);
									if (TileMap[x][y] != 'H' && c >= 1)	TileMap[x][y] = 'D';
								}
							}
							show(window, sprite_map, TileMap, &H, &W, flash, mario);
							window.display();
							for (int t = 0; t < 30; t++) { Sleep(time); }
						}

					}



				}
			}
		}


		flash.diamant_flash += 1;
		if (flash.diamant_flash > 7)flash.diamant_flash = 0; //меняем спрайт алмаза
		flash.cube_flash += 1;
		if (flash.cube_flash > 3)flash.cube_flash = 0; //меняем спрайт алмаза
		flash.star_flash += 1;
		if (flash.star_flash > 3)flash.star_flash = 0; //меняем спрайт алмаза


		window.draw(mario.sprite);

		std::ostringstream shift;    // объявили переменную
		shift << mario.diamant;


		Text text1("", font, 10);//создаем объект текст. закидываем в объект текст строку, шрифт, размер шрифта(в пикселях);//сам объект текст (не строка)
		text1.setOutlineColor(Color::White);//покрасили текст в красный. если убрать эту строку, то по умолчанию он белый
	   // text.setStyle(sf::Text::Bold | sf::Text::Underlined);//жирный и подчеркнутый текст. по умолчанию он "худой":)) и не подчеркнутый

		text1.setString(L"Собрано камней:" + shift.str());//задает строку тексту
		text1.setPosition(0, 0);
		window.draw(text1);

		Text text2("", font, 10);
		shift.str("");
		shift << time;
		text2.setPosition(120, 0);//задаем позицию текста, центр камеры
		text2.setString(L"замедление игры " + shift.str());
		window.draw(text2);//рисую этот текст

		Text text3("", font, 10);
		shift.str("");
		shift << mario.live;
		text3.setPosition(250, 0);//задаем позицию текста, центр камеры
		text3.setString(L"     жизнь " + shift.str());
		window.draw(text3);//рисую этот текст

		Text text4("", font, 10);
		shift.str("");
		shift << number_level;
		text4.setPosition(320, 0);//задаем позицию текста, центр камеры
		text4.setString(L"уровень " + shift.str());
		window.draw(text4);//рисую этот текст

		window.display();
		if (gameover) {     // проигрыш
			delete_map(TileMap, &H, enemy, quantity);
			while (1) {
				window.clear(Color(25, 29, 25));
				Text text2("", font, 40);
				text2.setPosition(100, 80);//задаем позицию текста, центр камеры
				text2.setString(" GAME  OVER ");
				window.draw(text2);//рисую этот текст
				window.display();
				while (window.pollEvent(event)) {
					if (event.type == Event::Closed) { window.close(); exit(0); }

					if (Keyboard::isKeyPressed(Keyboard::Escape) || Keyboard::isKeyPressed(Keyboard::Return))exit(0);
				}
			}
		}
		if (mario.diamant >= win.win && win.flag_win == false) { //при наборе нужного количестве алмазов открываем дверь
			win.flag_win = true;
			/*
			for (i = 0; i < H; i++) {
				for (j = 0; j < W; j++)
				{
					if (win.x==i||win.y==j) { TileMap[i][j] = 'e'; door.play(); }
				}
			}

		*/
			TileMap[win.x][win.y] = 'e'; door.play();

		}
		i = (mario.rect.top) / 16;
		j = (mario.rect.left) / 16;
		if (TileMap[i][j] == 'e') {  //переход игрока на другой уровень
			number_level++;
			if (number_level > max_level) {
				delete_map(TileMap, &H, enemy, quantity);
				while (1) {
					window.clear(Color(25, 29, 25));
					Text text2("", font, 40);
					text2.setPosition(100, 80);//задаем позицию текста, центр камеры
					text2.setString(" YOU WIN  ");
					window.draw(text2);//рисую этот текст
					while (window.pollEvent(event)) {
						if (event.type == Event::Closed) { window.close(); exit(0); }
						window.display();
						if (Keyboard::isKeyPressed(Keyboard::Escape) || Keyboard::isKeyPressed(Keyboard::Return))exit(0);

					}
				}
			}
			mario.diamant = 0;
			//mario.offsetX = 0;
			//mario.offsetY = 0;
			win.flag_win = false;
			delete_map(TileMap, &H, enemy, quantity);

			TileMap = start(number_level, &H, &W, &win);
			mario.TileMap = TileMap;
			set_player(window, sprite_map, mario, TileMap, &H, &W, time, start_door);
			enemy = create_enemy(TileMap, H, W, &quantity);

		}

	}
	return 0;
}