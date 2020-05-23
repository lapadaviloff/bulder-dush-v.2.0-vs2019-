#include"Int_str.h"


int string_to_int(string s) {
	int n = 0;
	stringstream ss;
	ss << s;
	ss >> n;
	return n;
}
//*************************************************************************************************************************************
string int_to_string(int n) {
	string s;
	stringstream ss;
	ss << n;
	ss >> s;
	return s;
}