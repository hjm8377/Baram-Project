#pragma once
#include "Console.h"

class Rank
{
private:

public:
	Rank();
	~Rank();
	/*��ŷ ���� ������ ���� ����ü*/
	typedef struct {
		char name[20] = "\0";
		int score = 0;
	}RANK;
	void WriteRanking(char* name, int score);
	int Read_Ranking();
	void Ranking(int size);
};