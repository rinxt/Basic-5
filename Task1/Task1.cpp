/*Вам нужно создать три класса: для фигуры, треугольника и четырёхугольника. Назовём их Figure, Triangle и Quadrangle.

Классы Triangle и Quadrangle будут наследовать класс Figure.

Для хранения информации о количестве сторон создайте поле sides_count в классе Figure. Оно будет защищённым, чтобы нельзя было изменить его извне, но можно изменить значение в наследниках. 
Либо оно может быть приватным, и тогда вам нужно передавать информацию о количестве сторон через конструктор.

Для доступа к информации о количестве сторон создайте публичный метод get_sides_count в классе Figure.
Он будет унаследован обоими фигурами.

Для правильной инициализации информации о количестве сторон создайте конструкторы в классах, в которых присвойте нужное значение полю sides_count. 
Если вы сделали sides_count защищённым, можете присвоить значение прямо в конструкторе.
Если приватным, то нужно создать в классе Figure защищённый конструктор с параметром (количество сторон) и публичный конструктор без параметров, который будет вызывать свой защищённый конструктор с параметром.
Защищённый конструктор должны будут вызывать дочерние классы в своих публичных конструкторах без параметров.

Также для удобства вывода названия фигуры можно создать защищённое поле name в классе Figure с соответствующим методом get_name и заполнением значения в каждом классе. 
В Figure это будет «Фигура» и т. д.*/
#include <iostream>

class Figure {
public:
	Figure(int sides_count = 0) : sides_count(sides_count), name("Фигура") {}
	int get_sides_count() { return sides_count; }
	std::string get_name() { return name; }
protected:
	int sides_count;
	std::string name;
};

class Triangle : public Figure{
public:
	Triangle() : Figure(3) { name = "Треугольник"; }
};

class Quadrangle : public Figure{
public:
	Quadrangle() : Figure(4) { name = "Четырехугольник"; }
};

int main() {
	system("chcp 1251");

	Figure figure;
	Triangle triangle;
	Quadrangle quadrangle;

	std::cout << figure.get_name() << ": " << figure.get_sides_count() << " сторон\n";
	std:: cout << triangle.get_name() << ": " << triangle.get_sides_count() << " стороны\n";
	std::cout << quadrangle.get_name() << ": " << quadrangle.get_sides_count() << " стороны\n";

	return 0;
}