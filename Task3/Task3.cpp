#include <iostream>

class Figure {
protected:
    std::string name_;
    bool checked = false;
    int sides_count = 0;

    virtual bool check() {
        if (sides_count != 0) return false;
    }

public:
    std::string get_name() { return name_; }

    virtual void print_info() {
        std::cout << "\n" << name_ << ":\n";
        if (check()) std::cout << "Правильная\n";
        else std::cout << "Неправильная\n";
        std::cout << "Количество сторон: " << sides_count << std::endl;
    }
};


class Triangle : public Figure {
protected:
    int a_ = 0;
    int b_ = 0;
    int c_ = 0;
    int A_ = 0;
    int B_ = 0;
    int C_ = 0;

    bool check() override {
        if ((A_ + B_ + C_) == 180) return true;
        else return false;
    }
public:
    Triangle(int a, int b, int c, int A, int B, int C) {
        name_ = "Треугольник";
        a_ = a;
        b_ = b;
        c_ = c;
        A_ = A;
        B_ = B;
        C_ = C;

        sides_count = 3;
        checked = check();
    }

    int get_a() { return a_; }
    int get_b() { return b_; }
    int get_c() { return c_; }
    int get_A() { return A_; }
    int get_B() { return B_; }
    int get_C() { return C_; }

    void print_info() override 
    {
        Figure::print_info();

        std::cout << "Стороны: " << "a = " << get_a() << ", b = " << get_b() << ", с = " << get_c()
            << "\nУглы: " << "А = " << get_A() << ", В = " << get_B() << ", С = " << get_C() << std::endl;
    }
};


class RightTriangle : public Triangle {
protected:
    bool check() override {
        if (Triangle::check() && C_ == 90) return true;
        else return false;
    }

public:
    RightTriangle(int a, int b, int c, int A, int B, int C) : Triangle(a, b, c, A, B, C) {
        Triangle::name_ = "Прямоугольный треугольник";
    }
};


class IsoscelesTriangle : public Triangle {
protected:
    bool check() override {
        if (Triangle::check() && A_==C_ && a_==c_) return true;
        else return false;
    }

public:
    IsoscelesTriangle(int a, int b, int c, int A, int B, int C) : Triangle(a, b, c, A, B, C) {
        Triangle::name_ = "Равнобедренный треугольник";
    }
};


class EquilateralTriangle : public Triangle {
protected:
    bool check() override {
        if (Triangle::check() && A_ == B_ && B_ == C_ && a_ == c_ && c_ == b_) return true;
        else return false;
    }

public:
    EquilateralTriangle(int a, int b, int c, int A, int B, int C) : Triangle(a, b, c, A, B, C) {
        Triangle::name_ = "Равносторонний треугольник";
    }
};


class Quadrilateral : public Figure {
protected:
    int a_ = 0;
    int b_ = 0;
    int c_ = 0;
    int d_ = 0;
    int A_ = 0;
    int B_ = 0;
    int C_ = 0;
    int D_ = 0;

    bool check() override {
        if ((A_ + B_ + C_ + D_) == 90) return true;
        else return false;
    }

    bool check90() {
        if (A_==90 && B_==90 && C_==90 && D_==90) return true;
        else return false;
    }

    bool check_sides_pairs() {
        if ((a_=c_) && (b_==d_)) return true;
        else return false;
    }

    bool check_all_sides() {
        if ((a_ = b_) && (b_ == c_) && (c_ = d_)) return true;
        else return false;
    }

    bool check_angles_pairs() {
        if ((A_ = C_) && (B_ == D_)) return true;
        else return false;
    }

public:
    Quadrilateral(int a, int b, int c, int d, int A, int B, int C, int D) {
        name_ = "Четырехугольник";
        sides_count = 4;

        a_ = a;
        b_ = b;
        c_ = c;
        d_ = d;

        A_ = A;
        B_ = B;
        C_ = C;
        D_ = D;
    }

    int get_a() { return a_; }
    int get_b() { return b_; }
    int get_c() { return c_; }
    int get_d() { return d_; }
    int get_A() { return A_; }
    int get_B() { return B_; }
    int get_C() { return C_; }
    int get_D() { return D_; }

    void print_info() override
    {
        Figure::print_info();

        std::cout << "Стороны: " << "a = " << get_a() << ", b = " << get_b() << ", с = " << get_c() << ", с = " << get_c() << ", d = " << get_d()
            << "\nУглы: " << "А = " << get_A() << ", В = " << get_B() << ", С = " << get_C() << ", D = " << get_D() << std::endl;
    }
};


class Rectangle : public Quadrilateral {
protected:
    bool check() override {
        if (Quadrilateral::check() && Quadrilateral::check90() && Quadrilateral::check_sides_pairs()) return true;
        else return false;
    }

public:
    Rectangle(int a, int b, int c, int d, int A, int B, int C, int D) : Quadrilateral(a, b, c, d, A, B, C, D) {
        Quadrilateral::name_ = "Прямоугольник";
    }
};


class Square : public Rectangle {
protected:
    bool check() override {
        if (Quadrilateral::check() && Quadrilateral::check90() && Quadrilateral::check_all_sides()) return true;
        else return false;
    }

public:
    Square(int a, int b, int c, int d, int A, int B, int C, int D) : Rectangle(a, b, c, d, A, B, C, D) {
        Quadrilateral::name_ = "Квадрат";
    }
};


class Parallelogram : public Quadrilateral {
protected:
    bool check() override {
        if (Quadrilateral::check() && Quadrilateral::check_angles_pairs() && Quadrilateral::check_sides_pairs()) return true;
        else return false;
    }

public:
    Parallelogram(int a, int b, int c, int d, int A, int B, int C, int D) : Quadrilateral(a, b, c, d, A, B, C, D) {
        Quadrilateral::name_ = "Параллелограмм";
    }
};


class Rhombus : public Parallelogram {
protected:
    bool check() override {
        if (Quadrilateral::check() && Quadrilateral::check_angles_pairs() && Quadrilateral::check_all_sides()) return true;
        else return false;
    }

public:
    Rhombus(int a, int b, int c, int d, int A, int B, int C, int D) : Parallelogram(a, b, c, d, A, B, C, D) {
        Parallelogram::name_ = "Ромб";
    }
};


int main() {
    system("chcp 1251");

    Figure figure;

    Triangle tri(10, 20, 30, 50, 60, 70);
    Figure* fig_tri = &tri;
    fig_tri->print_info();

    RightTriangle right_triangle(10, 20, 30, 50, 60, 90);
    Figure* fig_right_triangle = &right_triangle;
    fig_right_triangle->print_info();

    IsoscelesTriangle isosceles_triangle(10, 20, 10, 50, 60, 50);
    Figure* fig_isosceles_triangle = &isosceles_triangle;
    fig_isosceles_triangle->print_info();

    EquilateralTriangle equilateral_triangle(30, 30, 30, 60, 60, 60);
    Figure* fig_equilateral_triangle = &equilateral_triangle;
    fig_equilateral_triangle->print_info();

    Quadrilateral quadrilateral(10, 20, 30, 40, 50, 60, 70, 80);
    Figure* fig_quadrilateral = &quadrilateral;
    fig_quadrilateral->print_info();

    Rectangle rectangle(10, 20, 10, 20, 90, 90, 90, 90);
    Figure* fig_rectangle = &rectangle;
    fig_rectangle->print_info();

    Square square(20, 20, 20, 20, 90, 90, 90, 90);
    Figure* fig_square = &square;
    fig_square->print_info();

    Parallelogram parallelogram(20, 30, 20, 30, 30, 40, 30, 40);
    Figure* fig_parallelogram = &parallelogram;
    fig_parallelogram->print_info();

    Rhombus rhomb(30, 30, 30, 30, 30, 40, 30, 40);
    Figure* fig_rhomb = &rhomb;
    fig_rhomb->print_info();

    return 0;
}

