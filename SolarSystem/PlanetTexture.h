#pragma once
#include "GLRequire.h"

struct PlanetTexture
{
	GLuint texture; // ������� id

	// �����캯��
	PlanetTexture();

	// �����캯��
	PlanetTexture(const char * filename, GLuint texture);

	// �󶨵�ǰ����
	void GLBindTexture();
};

