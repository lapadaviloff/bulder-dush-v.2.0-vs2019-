#include"Gamesound.h"

Gamesound::Gamesound(string filename) {
		filename_ = filename;
		sound_bufer.loadFromFile(filename);//��������� � ���� ����
		sound.setBuffer(sound_bufer); //������� ���� � ��������� � ���� ���� �� ������
	}