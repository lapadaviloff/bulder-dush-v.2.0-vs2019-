#ifndef ENEMY_H_
#define ENEMY_H_
struct Enemy {
	Enemy() :x(0), y(0), step(1), live(1), symbol('-') {};
	int x, y, step, live;
	char symbol;
};
#endif
