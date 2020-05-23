#include"Start_delete.h"
string** start(int number_level, int* H_, int* W_, Win* win) {

	//int win;
	int H, W;
	string temp = "";
	string level = "resource/maps/level";
	level += int_to_string(number_level);
	level += ".map";

	std::ifstream  fil(level); // (ВВЕЛИ НЕ КОРРЕКТНОЕ ИМЯ ФАЙЛА)
	if (!fil.is_open()) { // если файл не открыт
		MessageBox(GetActiveWindow(), L"not file map!", L"Boulder dash", MB_ICONERROR);
		exit(1);
	}
	getline(fil, temp, '\n');
	win->win = string_to_int(temp);
	getline(fil, temp, '\n');
	H = string_to_int(temp);
	getline(fil, temp, '\n');
	W = string_to_int(temp);

	string** TileMap = new string * [H];
	for (int i = 0; i < H; i++) {          // двумерный
		TileMap[i] = new string[W]; // массив 
	}

	int i = 0;
	temp = "";
	while (i < H) {// считываем карту

		getline(fil, temp, '\n');
		if (temp.length() != W) {
			MessageBox(GetActiveWindow(), L"wrong map file!", L"Boulder dash", MB_ICONERROR);
			exit(1);
		}
		for (int j = 0; j < W; j++) {
			TileMap[i][j] = temp[j];
		}
		temp = "";
		i++;
	}
	if (i != H) {
		MessageBox(GetActiveWindow(), L"wrong map file!", L"Boulder dash", MB_ICONERROR);
		exit(1);
	}
	fil.close(); // закрываем файл


	for (int i = 0; i < H; i++)
		for (int j = 0; j < W; j++)
		{

			if (TileMap[i][j] == 'E') {
				win->x = i;
				win->y = j;
				break;
			}


		}

	*H_ = H;
	*W_ = W;
	return TileMap;
}
//***************************************************************************************************************************************
void delete_map(string** TileMap, int* H_, Enemy* enemy, int qantity) {
	int H = *H_;
	for (int i = 0; i < H; i++) {          // двумерный
		delete[] TileMap[i];
	}
	delete[]TileMap;

	if (qantity > 1)delete[] enemy;

	else delete enemy;


}