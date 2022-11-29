#include "pch.h"
#include "Planet.h"


Planet::Planet()
{
	AroundPos = 0;
	SelfPos = 0;
	AroundSpeed = 0;
	SelfSpeed = 0;
	AroundRadius = 0;
	SelfRadius = 0;
	texture = NULL;
	father = NULL;
}

Planet::Planet(const char * texname, float as, float ss, float ar, float sr, struct Planet* father_p, GLuint texture_id)
{
	texture = new PlanetTexture(texname, texture_id);
	father = father_p;
	if (father_p != NULL)
		AroundPos = float(rand() % 360);
	else
		AroundPos = 0;
	AroundSpeed = as;
	AroundRadius = ar;
	SelfPos = 0;
	SelfSpeed = ss;
	SelfRadius = sr;
}

void Planet::GetPosition(bool needRadius)
{
	if (father != NULL)
	{
		// ����������岻�Ǻ��ģ����ȹ�ȥ���������������Ϣ
		father->GetPosition(needRadius);
		// Ȼ�󣬱任�������������ת
		glRotatef(-father->SelfPos, 0.0f, 1.0f, 0.0f);
		//// ���ƹ�ת���
		if (needRadius)
		{
			glPushMatrix();// ���浱ǰģ����ͼ����
			// ����������
			glBegin(GL_LINE_LOOP);
			for (int i = 0; i < 360; i++)
				glVertex3f(AroundRadius*sin(EDGE_ANGLE*i), 0, AroundRadius*cos(EDGE_ANGLE*i));
			glEnd();
			glPopMatrix();// ����ģ����ͼ����
		}
	}
	// �任����Ĺ�ת�Ƕ�
	glRotatef(AroundPos, 0.0f, 1.0f, 0.0f);
	// �ƶ��������λ��
	glTranslatef(AroundRadius, 0.0f, 0.0f);
	// �任�������ת�Ƕ�
	glRotatef(SelfPos, 0.0f, 1.0f, 0.0f);
}

void Planet::DrawPlanet(bool needRadius, int Speed)
{
	// ��ȡ���ǵ��������
	texture->GLBindTexture();
	// ��������ϵ�任
	GetPosition(needRadius);
	// ��������ת90�ȣ���֤����λ����ȷ
	glRotatef(90.0f, 1.0f, 0.0f, 0.0f);
	// ���û���ģʽΪ���λ���
	glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
	glBegin(GL_QUADS);
	GLUquadricObj   *uquadric = gluNewQuadric();
	gluQuadricNormals(uquadric, GL_SMOOTH);
	gluQuadricTexture(uquadric, TRUE);
	gluSphere(uquadric, SelfRadius, 100, 100);
	gluDeleteQuadric(uquadric);
	//glTexCoord2f(0, 0); glVertex3f(-SelfRadius, SelfRadius, -SelfRadius);
	//glTexCoord2f(1, 0); glVertex3f(SelfRadius, SelfRadius, -SelfRadius);
	//glTexCoord2f(1, 1); glVertex3f(SelfRadius, -SelfRadius, -SelfRadius);
	//glTexCoord2f(0, 1); glVertex3f(-SelfRadius, -SelfRadius, -SelfRadius);
	//glTexCoord2f(0, 0); glVertex3f(SelfRadius, SelfRadius, SelfRadius);
	//glTexCoord2f(1, 0); glVertex3f(-SelfRadius, SelfRadius, SelfRadius);
	//glTexCoord2f(1, 1); glVertex3f(-SelfRadius, -SelfRadius, SelfRadius);
	//glTexCoord2f(0, 1); glVertex3f(SelfRadius, -SelfRadius, SelfRadius);
	//glTexCoord2f(0, 0); glVertex3f(SelfRadius, SelfRadius, -SelfRadius);
	//glTexCoord2f(1, 0); glVertex3f(SelfRadius, SelfRadius, SelfRadius);
	//glTexCoord2f(1, 1); glVertex3f(SelfRadius, -SelfRadius, SelfRadius);
	//glTexCoord2f(0, 1); glVertex3f(SelfRadius, -SelfRadius, -SelfRadius);
	//glTexCoord2f(0, 0); glVertex3f(-SelfRadius, SelfRadius, SelfRadius);
	//glTexCoord2f(1, 0); glVertex3f(-SelfRadius, SelfRadius, -SelfRadius);
	//glTexCoord2f(1, 1); glVertex3f(-SelfRadius, -SelfRadius, -SelfRadius);
	//glTexCoord2f(0, 1); glVertex3f(-SelfRadius, -SelfRadius, SelfRadius);
	//glTexCoord2f(0, 0); glVertex3f(-SelfRadius, SelfRadius, SelfRadius);
	//glTexCoord2f(1, 0); glVertex3f(SelfRadius, SelfRadius, SelfRadius);
	//glTexCoord2f(1, 1); glVertex3f(SelfRadius, SelfRadius, -SelfRadius);
	//glTexCoord2f(0, 1); glVertex3f(-SelfRadius, SelfRadius, -SelfRadius);
	//glTexCoord2f(0, 0); glVertex3f(-SelfRadius, -SelfRadius, -SelfRadius);
	//glTexCoord2f(1, 0); glVertex3f(SelfRadius, -SelfRadius, -SelfRadius);
	//glTexCoord2f(1, 1); glVertex3f(SelfRadius, -SelfRadius, SelfRadius);
	//glTexCoord2f(0, 1); glVertex3f(-SelfRadius, -SelfRadius, SelfRadius);
	glEnd();
	
	// �������ǵ�λ����Ϣ
	float _speed = 0;
	if (Speed == 0)
		_speed = UPDATE_PAUSE;
	if (Speed == 1)
		_speed = UPDATE_LOW;
	if (Speed == 2)
		_speed = UPDATE_MID;
	if (Speed == 3)
		_speed = UPDATE_HIGH;

	AroundPos += (AroundSpeed * _speed);
	SelfPos += (SelfSpeed*_speed);

	if (AroundPos > 360)
		AroundPos = 0;
	if (SelfPos > 360)
		SelfPos = 0;
	// ������ϵ��ԭ
	glRotatef(-90.0f, 1.0f, 0.0f, 0.0f);
}
