#pragma once
#include "GLRequire.h"

struct GLFontMaker
{
	GLuint lists; // ��ʾ�б���
	GLsizei width; // ���ڿ��
	GLsizei height; // ���ڸ߶�

	// ���캯��
	GLFontMaker();
	
	// ѡ��������ʽ 
	void SelectFont(int size, int charset, const char* face);

	// �������
	void PrintText(float pos_x, float pos_y, float pos_z, const char * str);

	// ��Ļ����
	void PrintTextScreen(struct GLCamera camera, float pos_x, float pos_y, const char * str);
};

