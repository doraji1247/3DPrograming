#include "MuSoenMath.h"

void main() 
{
	MSM::vec3 V; //MuSoenMath.h ������Ͽ� �ִ� vec3�� ���
	MSM::mat3 M; //MuSoenMath.h ������Ͽ� �ִ� mat3�� ���
	
	V.RSVET(); //vec3 �� �ʱ�ȭ
	V.vector(3, 1); //(3, 1) ��ǥ �� �Է�

	M.Translate(); //translate �� �ʱ�ȭ
	M.Rotate(); //rotate �� �ʱ�ȭ
	M.Scal(); //scal �� �ʱ�ȭ

	M.RStranslate(3,5); //(3, 5)�� �̵� [2][0] = 3, [2][1] = 5
	M.RSrotate(30); //30�� ȸ�� [0][0] = cos(30), [0][1] = -sin(30), [1][0] = sin(30), [1][1] = cos(30)
	M.RSscal(2); //2�� Ȯ�� [0][0] = 2 [1][1] = 2

	M.multiply(V.Vec3, M.TL, M.RT, M.SC); //vec, translate, rotate, scal ��ĵ��� ������� ���ϴ� �Լ�

}
