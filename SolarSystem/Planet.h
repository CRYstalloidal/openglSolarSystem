#pragma once
#include "GLRequire.h"

struct Planet
{
	float AroundPos;	// ��ת�Ƕ�ֵ
	float SelfPos;		// ��ת�Ƕ�ֵ

	float AroundSpeed;	//��ת�ٶ�
	float SelfSpeed;	//��ת�ٶ�

	float AroundRadius;	// ���ǵ�Χ�ư뾶
	float SelfRadius;	// ���ǵİ뾶

	struct Planet * father; // ���������ָ��

	struct PlanetTexture* texture; // ���ǵ�����

	// ���ǵĹ��캯��
	Planet();

	// ���ǵĹ��캯��
	Planet(const char * texname, float as, float ss, float ar, float sr, struct Planet* father, GLuint texture_id);

	// ��ȡ�����������Ϣ
	void GetPosition(bool needRadius);

	// ���ǵĻ��ƺ���
	void DrawPlanet(bool needRadius, int Speed);
};


