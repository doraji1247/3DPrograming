#pragma once

#include <iostream>
#include <math.h>

using namespace std;

namespace MSM
{
	class vec3 //Ŭ���� vec3 ����
	{
	public:
		int Vec3[3][3]; //3*3 ��� ����

		void vector(int x, int y) //(3, 1) ��ǥ�� �ޱ� ���� �Լ� ����
		{
			Vec3[0][0] = x;
			Vec3[1][1] = y;
		}

		void RSVET() //3*3 ��� �ʱ�ȭ �Լ� ����
		{
			for (int i = 0; i < 3; i++)
			{
				for (int j = 0; j < 3; j++)
				{
					Vec3[i][j] = 0;
					if (i == j)
					{
						Vec3[i][j] = 1;
					}
				}
			}
		}

	};

	class mat3 
	{
		public:
			int TL[3][3]; //translate ���� �����ϱ� ���� ����
			double RT[3][3]; //rotate ���� �����ϱ� ���� ����
			int SC[3][3]; //scal ���� �����ϱ� ���� ����

			void RStranslate(int x, int y) //(3, 5) �̵��ϴ� ���� �ޱ� ���� �Լ� ����
			{
				TL[2][0] = x;
				TL[2][1] = y;
			}

			void Translate() //translate �� �ʱ�ȭ �Լ� ����
			{
				for (int i = 0; i < 3; i++)
				{
					for (int j = 0; j < 3; j++)
					{
						TL[i][j] = 0;
						if (i == j)
						{
							TL[i][j] = 1;
						}
					}
				}

			}

			void RSrotate(int x) //30�� ȸ���ϴ� ���� �ޱ� ���� �Լ� ����
			{
				SC[0][0] = cos(x);
				SC[0][1] = -sin(x);
				SC[1][0] = sin(x);
				SC[1][1] = cos(x);
			}

			void Rotate() //rotate �� �ʱ�ȭ �Լ� ����
			{
				for (int i = 0; i < 3; i++)
				{
					for (int j = 0; j < 3; j++)
					{
						RT[i][j] = 0;
						if (i == j)
						{
							RT[i][j] = 1;
						}
					}
				}
			}

			void RSscal(int x) //2�� Ȯ��Ǵ� ���� �ޱ� ���� �Լ� ����
			{
				SC[0][0] = x;
				SC[1][1] = x;
			}

			void Scal() //scal �� �ʱ�ȭ �Լ� ����
			{
				for (int i = 0; i < 3; i++)
				{
					for (int j = 0; j < 3; j++)
					{
						SC[i][j] = 0;
						if (i == j)
						{
							SC[i][j] = 1;
						}
					}
				}
			}

			double multiply(int ver[3][3], int tran[3][3], double Rot[3][3], int Sca[3][3]) //����� ���ϴ� �Լ� (ver * tran * Rot * Scal)
			{
				double a[3][3] = { 0 }; // ver�� tran ���� ���� a�� ����
				double b[3][3] = { 0 }; //a�� Rot ���� ���� b�� ����
				double c[3][3] = { 0 }; //b�� Scal ���� ���� c�� ���� �� ��� ���


				for (int i = 0; i < 3; i++) //vec3�� translate�� ����
				{
					for (int j = 0; j < 3; j++)
					{
						for (int k = 0; k < 3; k++)
						{
							a[i][j] += ver[i][k] * tran[k][j];
						}
					}
				}

				for (int i = 0; i < 3; i++) //a�� rotate�� ����
				{
					for (int j = 0; j < 3; j++)
					{
						for (int k = 0; k < 3; k++)
						{
							b[i][j] += a[i][k] * Rot[k][j];
						}
					}
				}

				for (int i = 0; i < 3; i++) //b�� Scal�� ����
				{
					for (int j = 0; j < 3; j++)
					{
						for (int k = 0; k < 3; k++)
						{
							c[i][j] += b[i][k] * Sca[k][j];
						}
					}
				}

				for (int i = 0; i < 3; i++) //��� ���
				{
					for (int k = 0; k < 3; k++)
					{

						cout << c[i][k];
						cout << ' ';
					}
					cout << endl;
				}

				return 0;
			}
	};
}