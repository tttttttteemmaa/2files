#include <iostream>
#include <string>
#include <fstream>

using namespace std;


int main(void) {
	setlocale(LC_ALL, "RUS");
	string str1, str2;
	string file1, file2;
	string msg = "";

	cout << "Введите название 1-го файла: ";
	cin >> file1;
	file1 += ".txt";

	cout << "Введите название 2-го файла: ";
	cin >> file2;
	file2 += ".txt";

	ifstream fin1;
	ifstream fin2;

	fin1.open(file1);
	fin2.open(file2);

	if (!fin1.is_open() or !fin2.is_open()) {
		cout << "ERROR 1" << endl;
	}
	else {
		while (!fin1.eof()) {
			getline(fin1, str1);
			getline(fin2, str2);

			if (str1 != str2) {
				msg += "Файлы не одинаковые!!!";
				break;
			}
			msg += "Файлы одинаковые";
		}

		fin1.close();
		fin2.close();
	}

	cout << msg << endl;

	return 0;
}