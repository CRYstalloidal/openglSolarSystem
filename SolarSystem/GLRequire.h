#pragma once
// �����������õ������е�ͷ�ļ�
#include "GL/glew.h"
#include "GL/glut.h"

#include <math.h>
#include <Windows.h>
#include <mmsystem.h>

#include <vector>
#include <iostream>

#include "PngLoader.h"
#include "PlanetTexture.h"
#include "GLCamera.h"
#include "Planet.h"
#include "GLSkyBox.h"
#include "GLFontMaker.h"

#pragma comment(lib,"winmm.lib")


using namespace std;

#define GL_WINDOW_WIDTH			1200 // ���ڵĿ��
#define GL_WINDOW_HEIGHT		800 // ���ڵĸ߶�

#define GL_DISPLAY_MODE			GLUT_RGBA | GLUT_DOUBLE // ������ʾģʽ����

#define MAX_CHAR				128 // �ַ���������

#define EYE_POS_X				0	// �������ʼ x ����
#define EYE_POS_Y				0	// �������ʼ y ����290
#define EYE_POS_Z				100 // �������ʼ z ����340

#define MOVE_SPEED				100 // �ƶ��ٶ�
#define JUMP_SPEED				100 // �����ٶ�
#define ROTATE_SPEED			2 // ��ת�ٶ�

#define UPDATE_PAUSE			0 // ������ͣ
#define UPDATE_LOW				0.3f // ��������
#define UPDATE_MID				1.0f // ��������
#define UPDATE_HIGH				2.0f // ���ٸ���

#define VIEW_ANGLE				45 // �ӽǽǶ�
#define VIEW_ANGLE_MAX			120 // �ӽǽǶ����ֵ
#define VIEW_ANGLE_MIN			30 // �ӽǽǶ���Сֵ

#define VIEW_DOWN				0.0f // ����ֵ-1.0
#define VIEW_DOWN_MAX			2.0f // ����ֵ���ֵ
#define VIEW_DOWN_MIN			-2.0f // ����ֵ��Сֵ

#define SKYBOX_SIZE				700 // ��պд�С

#define PLANET_COUNT			20 // ��������

#define EDGE_ANGLE				0.017453f  // 2PI/360
