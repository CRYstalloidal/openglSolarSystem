#pragma once
#include "GLRequire.h"

// ������ķ�װ��
struct GLCamera
{
	float EYE_X; // ������� x ����
	float EYE_Y; // ������� y ����
	float EYE_Z; // ������� z ����

	float VIEW_POS; // �������ת��

	// ������Ĺ��캯��
	GLCamera(float eye_x, float eye_y, float eye_z, float view_pos);

	// ������ƶ�
	void GLMove(float offset_right, float offset_up, float offset_forward);

	// �������ת
	void GLRotate(float offset_view_pos);
};

