// RPG.cpp : �������̨Ӧ�ó������ڵ㡣
//
//question: Change the map when player arrive the door			--done
//question: NPC.cpp line:35		return string or other better return method		--doing
//ppt�����Լ�����Ϸ ս������  ���� ����  at least 20minutes
//���⣺ ����  Я������ 

//�������� ��չ���� ��Ϣ���� �ڴ��Ż�


//�������˾ͱ��� ._.    done
//����ѵ������֣����棬�ںõ���������ʱ���س�ʱ��������� loading �����ظ�����

//��ҹ������˵�Ѫ��	doing
//��ܵ��˻�þ���		done
//���ھ���������ʾ		done
//ս�������˳�������
//����װ���� experienceMax �������10  ��ɫ������������

//������ֱ���ڵ�ͼ������д����Ӧ��ɫID�Ͳ���Ҫ�ֶ���������row col ��
#include "stdafx.h"
#include "Menu.h"

//cDataRuler* dataRuler;
//cRuler* ruler;
int _tmain(int argc, _TCHAR* argv[])
{
	//��ʼ��
	//������ģʽ ÿ���ö���Ҫnew����
	//dataRuler = new cDataRuler();
	//ruler = new cRuler();

	//��Ҫ#include <windows.h>
	SetConsoleTitle(L"RPG Game");//�޸Ŀ���̨����  ����һ
	//system("title sokoban1");	//�޸Ŀ���̨����  ������

	cLoad();
	cDirector::getInstance()->replaceScene(new cMenu());
	cDirector::getInstance()->runGame();

	return 0;
}

