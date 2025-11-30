#include <iostream>
#include <iomanip>
#include <cmath>
#include <vector>

double f(double x)
{
    return 2*x*x*x - 3*x*x - 12*x + 10;
}

double phi_1(double x)
{
    return x - 1.0/36 * f(x); 
}
double phi_2(double x)
{
    return 1.0 / 12 * (2*x*x*x - 3*x*x + 10);
}
double phi_3(double x)
{
    return x - 1.0/21 * f(x);
}

bool sign(double x)
{
    return x > 0 ? true : false;
}

int main()
{
    std::cout << "Поиск количества корень (максимум 3)" << std::endl;
    for(double i = -3; i <= 3; i += 0.5)
    {
        std::cout  << "f(" << i << ")" << (sign(f(i)) ? " > " : " < ") << 0 << std::endl;
    }
    double a[3] = {-3, 0, 2.5};
    double b[3] = {-2, 1.5, 3};
    double x[3];
    double alpha[3] = {1.0/3.0, 1.0/8.0, 1.0/2.0};
    double eps = 0.0001;
    std::vector<double(*)(double)> phi = {phi_1, phi_2, phi_3};

    for(int i = 0; i < 3; i++)
        x[i] = (a[i] + b[i])/2;

    for(int i = 0; i < 3; i++)
   {
        std::cout << std::endl << "Корень " << i+1 << " на отрезке [" << a[i] << "; " << b[i] << "]"<< std::endl;
        std::cout << std::scientific << std::setprecision(6);
        std::cout << "Начальное приближение x_0 = " << x[i] << std::endl << std::endl;
        double x_1 = phi[i](x[i]);
        int K = 1 + static_cast<int>(std::log((1-alpha[i])*eps/std::abs(x[i] - x_1))/std::log(alpha[i])); 
        std::cout << "k = " << K << std::endl;
        for(int k = 1; k <= K; k++)
        {
            x[i] = phi[i](x[i]);
            std::cout << "x_" << k << " = " <<  x[i] << std::endl;
        } 
    }    
    return 0;
}
