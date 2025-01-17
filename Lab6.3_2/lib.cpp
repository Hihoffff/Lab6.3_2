void tempFile(FILE* input, FILE* inputTemp) {
	team Team;
	while (fscanf(input, "%s %s %d", Team.name, &Team.trainer , &Team.wins) == 3) {
		fwrite(&Team, sizeof(Team), 1, inputTemp);
	}
	return;
}
double findMiddleVal(FILE* file) {
	int winsSum = 0;
	team Team;
	int i = 0;
	double res;
	while (fread(&Team, sizeof(Team), 1, file) != 0) {
		winsSum += Team.wins;
		i++;
	}
	if (i != 0) { res = (double)(winsSum / i); }
	else { res = -1; }
	return res;
}
void check(FILE* inputTemp, FILE* outputTemp, double middleVal) {
	team Team;
	while (fread(&Team, sizeof(Team), 1, inputTemp) != 0) {
		if (Team.wins < middleVal) {
			fwrite(&Team, sizeof(Team), 1, outputTemp);
		}
	}
	return;
}
void result(FILE* outputTemp, FILE* output) {
	team Team;
	while (fread(&Team, sizeof(Team), 1, outputTemp) != 0) {
		fprintf(output, "%s %s\n", Team.name, Team.trainer);
	}
	return;
}
//zashita
//найти комманду с наибольшим кол-вом побед у заданного тренера

void findTeam(FILE* inputTemp, char w[50], int& num, int& winsMax, int& cur) {
	team Team;
	fseek(inputTemp, num, SEEK_SET);
	while (fread(&Team, sizeof(Team), 1, inputTemp) != 0) {
		if (strcmp(w, Team.trainer) == 0 && winsMax < Team.wins) {
			winsMax = Team.wins;
			num = cur;
		}
		cur = ftell(inputTemp);
	}
	return;
}
void startData(FILE* inputTemp, char w[50], int& num, int& winsMax, int& cur) {
	bool flag = true;
	team Team;
	while (fread(&Team, sizeof(Team), 1, inputTemp) != 0 && flag) {
		if (strcmp(w, Team.trainer) == 0) {
			flag = false;
			winsMax = Team.wins;
			num = cur;
		}
		cur = ftell(inputTemp);
	}
	if (flag) {
		num = -1;
	}
	return;
}
void zashita(FILE* file, FILE* res, int num) {
	fseek(file, num, SEEK_SET);
	team Team;
	fread(&Team, sizeof(Team), 1, file);
	fprintf(res, "%s", Team.name);
}