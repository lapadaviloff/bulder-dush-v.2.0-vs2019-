#include"Gamesound.h"


Gamesound::Gamesound(string filename) {
		filename_ = filename;
		try {
			if (!(sound_bufer.loadFromFile(filename)))throw L"sound not load";//��������� � ���� ����
		}
		catch (LPCTSTR s) {
			MessageBox(GetActiveWindow(), s, L"Boulder dash", MB_ICONERROR);
			exit(1);
		
		}	
			sound.setBuffer(sound_bufer); //������� ���� � ��������� � ���� ���� �� ������
	}