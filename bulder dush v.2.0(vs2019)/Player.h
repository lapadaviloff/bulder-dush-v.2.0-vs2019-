#ifndef  PLAYER_H_
#define PLAYER_H_
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <Windows.h>
using namespace sf;
using namespace std;

class Player {
private:
	
	float currentFrame; // смена спрайта
	
	SoundBuffer sound_bufer;
	Sound almaz;
public:
	int offsetX , offsetY ;
	Sprite sprite;
	int live;
	string** TileMap;     //основная карта
	int diamant;         // количество собранных алмазов
	IntRect rect; //координаты и размер спрайта
	int dx, dy;    //перемещение вверх и низ
	
public:
	Player(Texture& image, string** t);

	void update(DWORD time);

	void Collision();

};
#endif