#include"Gamesound.h"

Gamesound::Gamesound(string filename) {
		filename_ = filename;
		sound_bufer.loadFromFile(filename);//загружаем в него звук
		sound.setBuffer(sound_bufer); //создаем звук и загружаем в него звук из буфера
	}