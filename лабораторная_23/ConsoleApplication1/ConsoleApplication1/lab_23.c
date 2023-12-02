#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <Windows.h>
#include <stdlib.h>

#define MAX_LEN 80
char s[MAX_LEN];

char filenameIn[] = "D:\\Учёба\\1 курс\\Основы алгоримизации и программирование (Власенко)\\лабораторная_23\\file_txt\\text5.txt";
char filenameHTML[] = "D:\\Учёба\\1 курс\\Основы алгоримизации и программирование (Власенко)\\лабораторная_23\\file_txt\\text5_out.html";


int getNextDelim(FILE* fp, char token[]);
int getNextWord(FILE* fp, char token[], int maxLen);
void task_1();
void task_2();
void task_3();
void task_4();
void task_5();
void task_6();
void task_7();

void main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	task_5();
}

void task_1() {
	printf("Фатхутдинов Абдулрауф Илгизарович Пибд-13\n");
	printf("ЛР23 задача 1\n");

	FILE* fin = fopen("D:\\Учёба\\1 курс\\Основы алгоримизации и программирование (Власенко)\\лабораторная_23\\file_txt\\text1.txt", "rt");
	if (fin == NULL) {
		printf("File not found\n");
		return;
	}

	FILE* fout = fopen("D:\\Учёба\\1 курс\\Основы алгоримизации и программирование (Власенко)\\лабораторная_23\\file_txt\\out1.txt", "wt");
	if (fout == NULL) {
		printf("File not create\n");
		return;
	}

	while (!feof(fin)) {
		if (fgets(s, MAX_LEN - 1, fin) != NULL) {
			for (int i = 0; s[i] != '\0'; i++) {
				if (s[i] == '\t') {
					s[i] = '%';
				}
			}

			fprintf(fout, "%s", s);
			printf(">>%s<<\n", s);
		}
	}
	fclose(fout);
	fclose(fin);
}

void task_2() {
	printf("Фатхутдинов Абдулрауф Илгизарович Пибд-13\n");
	printf("ЛР23 задача 2\n");

	FILE* fin = fopen("D:\\Учёба\\1 курс\\Основы алгоримизации и программирование (Власенко)\\лабораторная_23\\file_txt\\text2.txt", "rt");
	if (fin == NULL) {
		printf("File not found\n");
		return;
	}

	FILE* fout = fopen("D:\\Учёба\\1 курс\\Основы алгоримизации и программирование (Власенко)\\лабораторная_23\\file_txt\\out2.txt", "wt");
	if (fout == NULL) {
		printf("File not create\n");
		return;
	}

	while (!feof(fin)) {
		if (fgets(s, MAX_LEN - 1, fin) != NULL) {
			
			for (int i = 0; s[i] != '\0'; i++) {
				if (s[i] > 96 && isalpha(s[i])) {
					s[i] -= 32;
				}
			}
			fprintf(fout, "%s", s);
			printf(">>%s<<\n", s);
		}
	}
	fclose(fout);
	fclose(fin);
}

void task_3() {
	printf("Фатхутдинов Абдулрауф Илгизарович Пибд-13\n");
	printf("ЛР23 задача 3\n");

	FILE* fin = fopen("D:\\Учёба\\1 курс\\Основы алгоримизации и программирование (Власенко)\\лабораторная_23\\file_txt\\text3.txt", "rt");
	if (fin == NULL) {
		printf("File not found\n");
		return;
	}

	FILE* fout = fopen("D:\\Учёба\\1 курс\\Основы алгоримизации и программирование (Власенко)\\лабораторная_23\\file_txt\\out3.txt", "wt");
	if (fout == NULL) {
		printf("File not create\n");
		return;
	}

	while (!feof(fin)) {
		if (fgets(s, MAX_LEN - 1, fin) != NULL) {
			if (strlen(s) != 1) {
				for (int i = 0; s[i] != '\0'; i++) {
					if (s[i] == '\n') {
						s[i] = '#';
						s[i + 1] = '\n';
						s[i + 2] = '\0';
						break;
					}
				}
			}
			fprintf(fout, "%s", s);
			printf(">>%s<<\n", s);
		}
	}
	fclose(fout);
	fclose(fin);
}

int getNextDelim(FILE* fp, char token[]) {
	int ch = getc(fp);
	if (ch == EOF) {
		return 0;
	}
	if (isalpha((unsigned char)ch)) {
		ungetc(ch, fp);
		return 0;
	}
	token[0] = (unsigned char)ch;
	token[1] = '\0';
	return 1;
}

int getNextWord(FILE* fp, char token[], int maxLen) {
	int i = 0;
	int ch;
	while (((ch = getc(fp)) != EOF) && (i < maxLen - 1)) {
		if (!isalpha((unsigned char)(ch))) {
			break;
		}
		token[i++] = ch;
	}
	ungetc(ch, fp);
	token[i] = '\0';
	if (i == 0) {
		return 0;
	}
	return 1;
}

void task_4() {
	printf("Фатхутдинов Абдулрауф Илгизарович Пибд-13\n");
	printf("ЛР23 задача 4\n");

	printf("BEGIN!!!\n");

	FILE* fin = fopen("D:\\Учёба\\1 курс\\Основы алгоримизации и программирование (Власенко)\\лабораторная_23\\file_txt\\text4.txt", "rt");
	if (fin == NULL) {
		printf("File not found\n");
		return;
	}

	char token[MAX_LEN];

	while (!feof(fin)) {
		while (getNextDelim(fin, token)) {
			printf("<DELIM>%s<DELIM>\n", token);
		}
		while (getNextWord(fin, token, MAX_LEN)) {
			printf("<WORD>%s<WORD>\n", token);
		}
	}
	printf("END!!!\n");
	fclose(fin);
}
	
void task_5() {
	printf("Фатхутдинов Абдулрауф Илгизарович Пибд-13\n");
	printf("ЛР23 задача 5\n");
	printf("BEGIN!!!\n");

	FILE* fin = fopen(filenameIn, "rt");
	if (fin == NULL) {
		printf("File not found\n");
		return;
	}

	FILE* fout = fopen(filenameHTML, "wt");
	if (fout == NULL) {
		fclose(fin);
		printf("File not create\n");
		return;
	}

	fprintf(fout, "<!DOCTYPE html>");
	fprintf(fout, "<html>");
	fprintf(fout, "<head>");
	fprintf(fout, "<meta http - equiv = \"Content-Type\" content = \"text/html; charset=utf-8\" />");
	fprintf(fout, "<title>HTML Document</title>");
	fprintf(fout, "</head>");
	fprintf(fout, "<body>");

	int ch;

	while ((ch = getc(fin)) != EOF) {
		fprintf(fout, "%c", ch);
		if (ch == '\n') {
			fprintf(fout, "<br>");
		}
	}

	fprintf(fout, "</body>");
	fprintf(fout, "</html>");

	fclose(fout);
	fclose(fin);

	printf("END!!!\n");
}

void task_6() {
	printf("Фатхутдинов Абдулрауф Илгизарович Пибд-13\n");
	printf("ЛР23 задача 6\n");

	FILE* fin = fopen("D:\\Учёба\\1 курс\\Основы алгоримизации и программирование (Власенко)\\лабораторная_23\\file_txt\\text6.txt", "rt");
	if (fin == NULL) {
		printf("File not found\n");
		return;
	}

	FILE* fout = fopen("D:\\Учёба\\1 курс\\Основы алгоримизации и программирование (Власенко)\\лабораторная_23\\file_txt\\out6.txt", "wt");
	if (fout == NULL) {
		printf("File not create\n");
		return;
	}
	int count = 0;
	char str[10];
	while (!feof(fin)) {
		if (fgets(s, MAX_LEN - 1, fin) != NULL) {
			count = 0;
			for (int i = 0; s[i] != '\0'; i++) {
				if (s[i] == ';') {
					count++;
				}
				if (s[i + 1] == '\0') {
					snprintf(str, sizeof str, "%d", count);
					for (int j = 0; j < strlen(str); j++, ++i) {
						s[i] = str[j];
					}
				}
			}

			fprintf(fout, "%s", s);
			printf(">>%s<<\n", s);
		}
	}
	fclose(fout);
	fclose(fin);
}

void task_7() {
	printf("Фатхутдинов Абдулрауф Илгизарович Пибд-13\n");
	printf("ЛР23 задача 7\n");
	printf("Вариант 10\n");

	FILE* fin = fopen("D:\\Учёба\\1 курс\\Основы алгоримизации и программирование (Власенко)\\лабораторная_23\\file_txt\\text7.txt", "rt");
	if (fin == NULL) {
		printf("File not found\n");
		return;
	}

	FILE* fout = fopen("D:\\Учёба\\1 курс\\Основы алгоримизации и программирование (Власенко)\\лабораторная_23\\file_txt\\out7.txt", "wt");
	if (fout == NULL) {
		printf("File not create\n");
		return;
	}

	while (!feof(fin)) {
		if (fgets(s, MAX_LEN - 1, fin) != NULL) {
			for (int i = 0; s[i] != '\0'; i++) {
				if (s[i] == '-' || s[i] == '/' || s[i] == '+' || s[i] == '*') {
					s[i] = '_';
				}
			}

			fprintf(fout, "%s", s);
			printf(">>%s<<\n", s);
		}
	}
	fclose(fout);
	fclose(fin);
}


