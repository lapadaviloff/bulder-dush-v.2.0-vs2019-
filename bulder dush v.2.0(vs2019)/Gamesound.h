#ifndef GAMESOUND_H_
#define GAMESOUND_H_
#include <SFML/Audio.hpp>
#include <Windows.h>
using namespace sf;
using namespace std;

class Gamesound {
private:
	SoundBuffer sound_bufer;
	Sound sound;
	string filename_;
public:
	Gamesound(string filename);
	void play() {sound.play();}
};
#endif 