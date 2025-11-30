#include <fstream>
#include <cmath>
#include <iomanip>
#include <iostream>

double f_1(double x, double y)
{
    return std::sin(x+y) - 1.3*x;
}

double f_2(double x, double y)
{
    return x*x + y*y - 1;
}

struct Vector
{
    double x;
    double y;
    Vector(double x = 0.0, double y = 0.0) : x(x), y(y) {}
};

struct Matrix
{
    double a;
    double b;
    double c;
    double d;
    Matrix(double a, double b, double c, double d) : a(a), b(b), c(c), d(d) {}
};

Vector operator+(const Vector &a, const Vector &b)
{
    return Vector(a.x + b.x, a.y + b.y);
}

Vector operator-(const Vector &a, const Vector &b)
{
    return Vector(a.x - b.x, a.y - b.y);
}


Vector operator*(const Matrix& A, const Vector& b)
{
    return Vector(A.a * b.x + A.b * b.y, A.c * b.x + A.d * b.y);
}

Matrix operator*(const double &a, const Matrix &A)
{
    return Matrix(A.a * a, A.b * a, A.c * a, A.d * a);
}

double norm(Vector x)
{
    return std::sqrt(x.x*x.x + x.y*x.y);
}

Vector F(Vector x)
{
    return {f_1(x.x, x.y), f_2(x.x, x.y)};
}

Matrix reverseDF(Vector x_)
{
    double x = x_.x;
    double y = x_.y;
    return (1.0 / (2*y*(std::cos(x+y) - 1.3) - 2*x*std::cos(x+y))) * Matrix(2*y, -std::cos(x+y), -2*x, std::cos(x+y) - 1.3);
}

int main()
{
    Vector x_prev(0.3, 0.3); 
    Vector x_new = x_prev;
    double eps = 1e-3;
    std::cout << "x_0 = " << x_prev.x << " y_0 = " << x_prev.y << std::endl << std::endl;
     
    for(int i = 1; i < 1000; i++)
    {
        x_new = x_prev - reverseDF(x_prev)*F(x_prev);

        std::cout << "x_" << i << " = " << x_new.x << " y_" << i << " = " << x_new.y << std::endl;
        std::cout << "||x_" << i << " - x_" << i - 1 << "|| = " << norm(x_new - x_prev) << std::endl << std::endl;
        if (norm(x_new - x_prev) < eps)
            break;
        x_prev = x_new;
    }    


    return 0;
}

