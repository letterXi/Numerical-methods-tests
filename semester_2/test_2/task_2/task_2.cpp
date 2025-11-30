#include <iostream>
#include <cmath>
#include <iomanip>

double phi_1(double x, double y)
{
    return std::sin(y)/2 - 0.8 + 0.0 * x;
}

double phi_2(double x, double y)
{
    return 0.8 - std::cos(x + 0.5) + 0.0 * y;
}

struct Vector
{
    double x_;
    double y_;
};

double norm(Vector x, Vector y)
{
    return std::sqrt((x.x_ - y.x_)*(x.x_ - y.x_) + (x.y_ - y.y_)*(x.y_ - y.y_));
}

int main()
{
    double x = 0.0;
    double y = 0.0;
    double eps = 0.001;
    double new_x = 0.0;
    double new_y = 0.0;
    std::cout << "x_0 = " << x << " y_0 = " << y << std::endl << std::endl;
    for(int i = 1; i < 1000; i++)
    {
        new_x = phi_1(x, y);
        new_y = phi_2(x, y);
        std::cout << std::scientific << std::setprecision(7) << "x_" << i << " = " <<  new_x << " y_" << i << " = "  << new_y << std::endl;
        std::cout << "||x_" << i << " - x_" << i-1 << "|| = " << norm({new_x, new_y}, {x, y}) << std::endl << std::endl;
        if (norm({new_x, new_y}, {x, y}) < eps)
            break;
        x = new_x;
        y = new_y;    
    }
    return 0;
}
