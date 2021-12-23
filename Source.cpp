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
	Figure(const Figure& f) //переносит все свойства из того объекта, который передали
	{
		printf("Figure(const Figure& f)\n");
		corner = f.corner;
		side = f.side;
	}
	~Figure()
	{
		printf("%d, %d\n", corner, side); //вывод текущего состояния объекта
		printf("~Figure\n");
	}
	void DifFigPlus(int coef) //изменение фигуры (добавить углы и стороны); реализация метода в определении класса
	{
		corner = corner + coef;
		side = side + coef;
	}
	void DifFigMinus(int coef);
};
void Figure::DifFigMinus(int coef) //реализация метода после определения
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
	ColoredFigure(const ColoredFigure& f) //переносит все свойства из того объекта, который передали
	{
		printf("ColoredFigure(const Figure& f)\n");
		corner = f.corner;
		side = f.side;
		color = f.color;
	}
	~ColoredFigure()
	{
		printf("%d, %d, color = %d\n", corner, side, color); //вывод текущего состояния объекта
		printf("~ColoredFigure\n");
	}
	void change_color(int color2) //изменение фигуры (добавить углы и стороны); реализация метода в определении класса
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
	TwoFigures(const TwoFigures& tf) //глубокое копирование
	{
		printf("TwoFigures(const TwoFigures &tf)\n");
		f1 = new Figure((*tf.f1)); //tf - это объект, f1 - это указатель на Figure, поэтому мы должны его разыменовать
		f2 = new Figure((*tf.f2));
	}
	//TwoFigures(const TwoFigures &tf) //неправильный вариант конструктора копирования, который приводит к ошибке, поверхностное копирование
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
	//статические объекты
	{
		Figure f1;
		Figure f2(3, 3);
		Figure f3(f2);
	} //необходимо для удаления созданных объектов

			//создание классов, атрибутов, конструкторов, создание и уничтожение статических объектов

	printf("\n\n");

	//динамические объекты
	Figure* f4 = new Figure;
	Figure* f5 = new Figure(3, 3);
	Figure* f6 = new Figure(*f5);

	//удаление динамических объектов
	delete f4;
	delete f5;
	delete f6;

	//создание динамических объектов, создание д.о. с помощью разных конструкторов, удаление д.о.

	printf("\n\n");

	//f1->corner = 5; //для проверки доступности атрибутов

	//вызов методов класса
	Figure* f7 = new Figure(3, 3);
	f7->DifFigPlus(2);
	delete f7;

	Figure* f8 = new Figure(6, 6);
	f8->DifFigMinus(2);
	delete f8;

	//проверка доступности атрибутов, реализация методов, реализация методов в определении и после него

	printf("\n\n");

	ColoredFigure* f9 = new ColoredFigure(3, 3, 56);
	delete f9;

	//создание классов-наследников, проверка какие деструкторы и конструкторы вызываются

	printf("\n\n");

	Figure* f10 = new ColoredFigure(4, 4, 77);
	//ColoredFigure* f11 = new Figure(3, 3);
	//Figure* f12 = new Figure(3, 3);
	//ColoredFigure* f13 = f12;
	delete f10;

	//помещение объектов в переменные различных типов

	printf("\n\n");
	TwoFigures* tf1 = new TwoFigures;
	TwoFigures* tf2 = new TwoFigures(*tf1);
	delete tf1; delete tf2;

	//композиция объектов

//В классе-предке есть конструктор и деструктор, а в классе-потомке нет ни того, ни того; что происходит при создании предка, при создании потомка?

	printf("\n\n");
	Figure* f = new Figure;
	Figure* f1 = new AncestorFigure;
	AncestorFigure* af = new AncestorFigure;

	delete f;
	delete f1;
	delete af;

	return 0;
}