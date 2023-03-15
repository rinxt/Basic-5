#include <iostream>

class Figure {
protected:
    std::string name_;
    bool quadra_ = false;
    int a_ = 0;
    int b_ = 0;
    int c_ = 0;
    int d_ = 0;
    int A_ = 0;
    int B_ = 0;
    int C_ = 0;
    int D_ = 0;

public:
    std::string get_name() { return name_; }
    bool get_quadra() { return quadra_; }

    int get_a()  { return a_; }
    int get_b()  { return b_; }
    int get_c()  { return c_; }
    int get_d()  { return d_; }
    int get_A()  { return A_; }
    int get_B()  { return B_; }
    int get_C()  { return C_; }
    int get_D()  { return D_; }

};

class Triangle : public Figure {
public:
    Triangle(int a, int b, int c, int A, int B, int C) {
        name_ = "Треугольник";
        a_ = a;
        b_ = b;
        c_ = c;
        A_ = A;
        B_ = B;
        C_ = C;
    }
};

class RightTriangle : public Triangle {
public:
    RightTriangle(int a, int b, int c, int A, int B) : Triangle(a, b, c, A, B, 90) {
        Triangle::name_ = "Прямоугольный треугольник";
    }
};

class IsoscelesTriangle : public Triangle {
public:
    IsoscelesTriangle(int a, int b, int A) : Triangle(a, b, a, A, 180 - 2 * A, A) {
        Triangle::name_ = "Равнобедренный треугольник";
    }
};

class EquilateralTriangle : public Triangle {
public:
    EquilateralTriangle(int a) : Triangle(a, a, a, 60, 60, 60) {
        Triangle::name_ = "Равносторонний треугольник";
    }
};

class Quadrilateral : public Figure {
public:
    Quadrilateral(int a, int b, int c, int d, int A, int B, int C, int D) {
        name_ = "Четырехугольник";
        quadra_ = true;
        a_ = a;
        b_ = b;
        c_ = c;
        d_ = d;
        A_ = A;
        B_ = B;
        C_ = C;
        D_ = D;
    }
};

class Rectangle : public Quadrilateral {
public:
    Rectangle(int a, int b) : Quadrilateral(a, b, a, b, 90, 90, 90, 90) {
        Quadrilateral::name_ = "Прямоугольник";
    }
};

class Square : public Rectangle {
public:
    Square(int a) : Rectangle(a, a) {
        Quadrilateral::name_ = "Квадрат";
    }
};

class Parallelogram : public Quadrilateral {
public:
    Parallelogram(int a, int b, int A) : Quadrilateral(a, b, a, b, A, 180 - A, A, 180 - A) {
        Quadrilateral::name_ = "Параллелограмм";
    }
};

class Rhombus : public Parallelogram {
public:
    Rhombus(int a, int A) : Parallelogram(a, a, A) {
        Parallelogram::name_ = "Ромб";
    }
};

void print_info(Figure& figure)
{
    std::cout << std::endl;
    std::cout << figure.get_name() << ":" << std::endl;

    std::cout << "Стороны: ";
    std::cout << "a = " << figure.get_a() << ", b = " << figure.get_b() << ", с = " << figure.get_c();
    if (figure.get_quadra())
    {
        std::cout << ", d = " << figure.get_d() << std::endl;
    }
    else { std::cout << std::endl; }

    std::cout << "Углы: ";
    std::cout << "А = " << figure.get_A() << ", В = " << figure.get_B() << ", С = " << figure.get_C();
    if (figure.get_quadra()) { std::cout << ", D = " << figure.get_D() << std::endl; }
    else { std::cout << std::endl; }
}


int main() {
    system("chcp 1251");

    Triangle tri(10, 20, 30, 50, 60, 70);
    RightTriangle right_triangle(10, 20, 30, 50, 60);
    IsoscelesTriangle isosceles_triangle(10, 20, 50);
    EquilateralTriangle equilateral_triangle(30);
    Quadrilateral quadrilateral(10, 20, 30, 40, 50, 60, 70, 80);
    Rectangle rectangle(10, 20);
    Square square(20);
    Parallelogram parallelogram(20, 30, 30);
    Rhombus rhomb(10, 30);

    print_info(tri);
    print_info(right_triangle);
    print_info(isosceles_triangle);
    print_info(equilateral_triangle);
    print_info(quadrilateral);
    print_info(rectangle);
    print_info(square);
    print_info(parallelogram);
    print_info(rhomb);

    return 0;
}

