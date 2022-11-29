#include "pch.h"
#include "PlanetTexture.h"


PlanetTexture::PlanetTexture()
{
	texture = 0;
}

PlanetTexture::PlanetTexture(const char * filename, GLuint texture)
{
	this->texture = texture;
	// ͼ��Ĵ洢����
	vector<unsigned char> image;
	// ͼ��Ŀ�Ⱥ͸߶�
	unsigned int width, height;
	// ����ͼƬ
	unsigned int error = lodepng::decode(image, width, height, filename);
	if (error != 0)
	{
		// ����ͼƬ����
		cout << "error " << error << ": " << lodepng_error_text(error) << endl;
		return;
	}
	// ����OpenGL����
	glEnable(GL_TEXTURE_2D);
	// ���ö�ȡ���ݵĶ��뷽ʽ
	glPixelStorei(GL_UNPACK_ALIGNMENT, 1);
	// �󶨸��������
	glBindTexture(GL_TEXTURE_2D, texture);
	// ��������S��T�ظ���ʽ
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP);
	// ָ��������ͼ�Ͳ��ʻ�ϵķ�ʽ
	glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);
	// �����������ѡ��
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
	// ����MipMap����
	gluBuild2DMipmaps(GL_TEXTURE_2D, 4, width, height, GL_RGBA, GL_UNSIGNED_BYTE, &image[0]);
	// �ر�OpenGL����
	glDisable(GL_TEXTURE_2D);
}

void PlanetTexture::GLBindTexture()
{
	glBindTexture(GL_TEXTURE_2D, texture);
}
