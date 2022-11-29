#pragma once
#include "GLRequire.h"

struct GLSkyBox
{
	float POS_X; // ���� x ����
	float POS_Y; // ���� y ����
	float POS_Z; // ���� z ����
	GLuint texture_id[6]; // ��պ� 6 ��������� id
	float size; // ��պд�С

	// ��պй��캯��
	GLSkyBox();

	// ��պй��캯��
	GLSkyBox(float pos_x, float pos_y, float pos_z, const char *texture_file[6], GLuint texture_id[6], float size);

	// ��պи�������
	void UpdatePosition(float pos_x, float pos_y, float pos_z);

	// ��պл��Ƴ���
	void DrawScence();
};

