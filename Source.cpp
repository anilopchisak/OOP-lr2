#include <iostream>
using namespace std;

class Figure
{
protected:
	int corner;
	int side;
public:
	Figure()
	{
		printf("Figure()\n");
		corner = 0;
		side = 0;
	}
	Figure(int corner, int side)
	{
		printf("Figure(int corner, int side)\n");
		this->corner = corner;
		this->side = side;
	}
	Figure(const Figure& f) //��������� ��� �������� �� ���� �������, ������� ��������
	{
		printf("Figure(const Figure& f)\n");
		corner = f.corner;
		side = f.side;
	}
	~Figure()
	{
		printf("%d, %d\n", corner, side); //����� �������� ��������� �������
		printf("~Figure\n");
	}
	void DifFigPlus(int coef) //��������� ������ (�������� ���� � �������); ���������� ������ � ����������� ������
	{
		corner = corner + coef;
		side = side + coef;
	}
	void DifFigMinus(int coef);
};
void Figure::DifFigMinus(int coef) //���������� ������ ����� �����������
{
	corner = corner - coef;
	side = side - coef;
}

class ColoredFigure : public Figure
{
protected:
	int color;
public:
	ColoredFigure() : Figure()
	{
		printf("ColoredFigure()\n");
		color = 0;
	}
	ColoredFigure(int corner, int side, int color) : Figure(corner, side)
	{
		printf("ColoredFigure(int corner, int side, int color)\n");
		this->color = color;
	}
	ColoredFigure(const ColoredFigure& f) //��������� ��� �������� �� ���� �������, ������� ��������
	{
		printf("ColoredFigure(const Figure& f)\n");
		corner = f.corner;
		side = f.side;
		color = f.color;
	}
	~ColoredFigure()
	{
		printf("%d, %d, color = %d\n", corner, side, color); //����� �������� ��������� �������
		printf("~ColoredFigure\n");
	}
	void change_color(int color2) //��������� ������ (�������� ���� � �������); ���������� ������ � ����������� ������
	{
		color = color2;
	}
};

class TwoFigures
{
protected:
	Figure* f1;
	Figure* f2;
public:
	TwoFigures()
	{
		printf("TwoFigures()\n");
		f1 = new Figure;
		f2 = new Figure;
	}
	TwoFigures(int corner1, int side1, int corner2, int side2)
	{
		printf("TwoFigures(int corner1, int side1, int corner2, int side2)\n");
		f1 = new Figure(corner1, side1);
		f2 = new Figure(corner2, side2);
	}
	TwoFigures(const TwoFigures& tf) //�������� �����������
	{
		printf("TwoFigures(const TwoFigures &tf)\n");
		f1 = new Figure((*tf.f1)); //tf - ��� ������, f1 - ��� ��������� �� Figure, ������� �� ������ ��� ������������
		f2 = new Figure((*tf.f2));
	}
	//TwoFigures(const TwoFigures &tf) //������������ ������� ������������ �����������, ������� �������� � ������, ������������� �����������
	//{
	//	printf("TwoFigures(const TwoFigures *f)\n");
	//	f1 = tf.f1;
	//	f2 = tf.f2;
	//}
	~TwoFigures()
	{
		delete f1;
		delete f2;
		printf("~TwoFigures()\n");
	}
};

class AncestorFigure : public Figure
{
protected:
	int corner;
	int side;
};

int main()
{
	//����������� �������
	{
		Figure f1;
		Figure f2(3, 3);
		Figure f3(f2);
	} //���������� ��� �������� ��������� ��������

			//�������� �������, ���������, �������������, �������� � ����������� ����������� ��������

	printf("\n\n");

	//������������ �������
	Figure* f4 = new Figure;
	Figure* f5 = new Figure(3, 3);
	Figure* f6 = new Figure(*f5);

	//�������� ������������ ��������
	delete f4;
	delete f5;
	delete f6;

	//�������� ������������ ��������, �������� �.�. � ������� ������ �������������, �������� �.�.

	printf("\n\n");

	//f1->corner = 5; //��� �������� ����������� ���������

	//����� ������� ������
	Figure* f7 = new Figure(3, 3);
	f7->DifFigPlus(2);
	delete f7;

	Figure* f8 = new Figure(6, 6);
	f8->DifFigMinus(2);
	delete f8;

	//�������� ����������� ���������, ���������� �������, ���������� ������� � ����������� � ����� ����

	printf("\n\n");

	ColoredFigure* f9 = new ColoredFigure(3, 3, 56);
	delete f9;

	//�������� �������-�����������, �������� ����� ����������� � ������������ ����������

	printf("\n\n");

	Figure* f10 = new ColoredFigure(4, 4, 77);
	//ColoredFigure* f11 = new Figure(3, 3);
	//Figure* f12 = new Figure(3, 3);
	//ColoredFigure* f13 = f12;
	delete f10;

	//��������� �������� � ���������� ��������� �����

	printf("\n\n");
	TwoFigures* tf1 = new TwoFigures;
	TwoFigures* tf2 = new TwoFigures(*tf1);
	delete tf1; delete tf2;

	//���������� ��������

//� ������-������ ���� ����������� � ����������, � � ������-������� ��� �� ����, �� ����; ��� ���������� ��� �������� ������, ��� �������� �������?

	printf("\n\n");
	Figure* f = new Figure;
	Figure* f1 = new AncestorFigure;
	AncestorFigure* af = new AncestorFigure;

	delete f;
	delete f1;
	delete af;

	return 0;
}