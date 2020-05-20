#ifndef  PLAYER_H_
#define PLAYER_H_
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <Windows.h>
using namespace sf;
using namespace std;

class Player {
private:
	
	float currentFrame; // ����� �������
	
	SoundBuffer sound_bufer;
	Sound almaz;
public:
	int offsetX , offsetY ;
	Sprite sprite;
	int live;
	string** TileMap;     //�������� �����
	int diamant;         // ���������� ��������� �������
	IntRect rect; //���������� � ������ �������
	int dx, dy;    //����������� ����� � ���
	
public:
	Player(Texture& image, string** t);

	void update(DWORD time);

	void Collision();

};
#endif