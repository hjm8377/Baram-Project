#pragma once
#include "Console.h"
#include "sound.h"

class Init
{
private:	//���� ������(�����)
	int consoleX = 80;
	int consoleY = 30;
public:	//���� ������(����)
	Init();	//����Ʈ ������
	~Init();	//�Ҹ���

	void init();
	void info();
	int setting();
	int menu();
	sound sound;
};