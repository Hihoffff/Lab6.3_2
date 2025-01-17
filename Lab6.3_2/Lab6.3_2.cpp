#include "lib.h"
#include "lib.cpp"



int main()
{
	FILE* input = fopen("teams.txt", "r");
	FILE* inputTemp = fopen("inputTemp.bin", "w+b");
	FILE* outputTemp = fopen("resTemp.bin", "w+b");
	FILE* output = fopen("res.txt", "w");
	FILE* output2 = fopen("zashita.txt", "w");
	
	int curPos;
	double middleVal;
	char w[50];
	setlocale(LC_ALL, "RUS");
	if (input != 0) {
		tempFile(input, inputTemp);
		curPos = ftell(inputTemp);
		if (curPos > 0) {
			fseek(inputTemp, 0, SEEK_SET);

			middleVal = findMiddleVal(inputTemp);
			if (middleVal != -1) {
				fseek(inputTemp, 0, SEEK_SET);
				check(inputTemp, outputTemp, middleVal);
				fseek(outputTemp, 0, SEEK_SET);
				result(outputTemp, output);
			}
			else {
				cout << "Нет подходящих значений!" << endl;
			}

			//zashita
			int num;
			int winsMax;
			int cur = 0;
			cout << "Введите имя тренера: " << endl;
			cin.getline(w, sizeof(w));
			fseek(inputTemp, 0, SEEK_SET);
			startData(inputTemp, w, num, winsMax, cur);

			if (num != -1) {
				findTeam(inputTemp,w, num, winsMax, cur);
				zashita(inputTemp, output2, num);
			}
			else {
				cout << "Нет подходящих команд!" << endl;
				fputs("Нет подходящих команд!\n", output2);
			}
		}
		else {
			cout << "Файл пустой!" << endl;
		}
		fclose(input);
		fclose(inputTemp);
		fclose(outputTemp);
		fclose(output);
		fclose(output2);
	}
	else {
		cout << "Ошибка при открытии файла!" << endl;
	}

}

