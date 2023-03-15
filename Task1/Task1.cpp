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