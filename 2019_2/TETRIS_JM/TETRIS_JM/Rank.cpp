#define _CRT_SECURE_NO_WARNINGS
#include "Rank.h"
#include <stdio.h>
#include <string.h>
#include <conio.h>

Rank::Rank()
{
}

Rank::~Rank()
{
}

void Rank::WriteRanking(char* name, int score)
{
	FILE* fp = NULL;

	fp = fopen("Ranking.txt", "a+");	//a+ : �б�, ����, ���ϻ��� O, ����, ���� ����� ���� X
	fprintf(fp, "%s %d\n", name, score);
	fclose(fp);
}

int Rank::Read_Ranking()
{
	FILE* file = NULL;

	RANK r[100];
	char buf[256];
	int len;
	int count = 0;
	int tmpscore;
	char tmpname[20];

	//�ټ� ����
	file = fopen("Ranking.txt", "a+");
	fclose(file);

	file = fopen("Ranking.txt", "r");
	while (1)
	{
		fgets(buf, sizeof(buf), file);
		len = strlen(buf);

		if (len == 0)
			break;

		count++;
		buf[0] = '\0';
	}
	fclose(file);

	//����
	file = fopen("Ranking.txt", "r");

	for (int i = 0; i < count; i++)
		fscanf(file, "%s %d", &r[i].name, &r[i].score);
	

	for (int i = 0; i < count - 1; i++)
		for (int j = 0; j < count - 1; j++)
			if (r[j].score < r[j + 1].score) {
				tmpscore = r[j].score;
				r[j].score = r[j + 1].score;
				r[j + 1].score = tmpscore;

				strcpy(tmpname, r[j].name);
				strcpy(r[j].name, r[j + 1].name);
				strcpy(r[j + 1].name, tmpname);
			}
	fclose(file);

	//ranking_fin.txt �ۼ�
	file = fopen("Ranking_fin.txt", "w");
	for (int i = 0; i < count; i++)
		fprintf(file, "%s %d\n", r[i].name, r[i].score);
	fclose(file);
	return count;
}

void Rank::Ranking(int size)
{
	FILE* fp = NULL;

	int key;
	int R_score[100] = { 0, };
	char R_name[100][20];

	for (int i = 0; i < 100; i++)
		strcpy(R_name[i], "_____");

	fp = fopen("Ranking_fin.txt", "a+");
	if (fp == NULL)
	{
		printf("Read Ranking_fin.txt Error\n");
		return;
	}
	for (int i = 0; i < size; i++)
		fscanf(fp, "%s %d", &R_name[i], &R_score[i]);
	fclose(fp);

	system("cls");
	printf("                        �ڡ١ڡ� R A N K I N G �١ڡ١�\n\n");
	for (int i = 0; i < 10; i++)
		printf("                                %d. %s %d\n\n", i + 1, R_name[i], R_score[i]);
	printf("\n\n�����̽���/"); printf("��"); printf("�� ������ ���� ȭ������ ���ư��ϴ�.\n");
	while (1) {
		key = _getch();
		if (key == SPACEBAR)
			break;
	}
}