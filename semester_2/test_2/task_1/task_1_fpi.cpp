#include <iostream>
#include <iomanip>
#include <cmath>

int main()
{
    double a = 2.0;
    double b = 3.0;
    double eps = 1e-3;
    int n = 8;
    double tau = -0.125;
    double alpha = 0.5;
    double x_0  = (a + b) / 2.0;

    std::cout << "sqrt(" << n << ") = ?" << std::endl;
    std::cout << "f(x) = x^2 - " << n << std::endl;
    std::cout << "phi(x) = x + tau * f(x)" << std::endl;
    std::cout << "tau = " << tau << std::endl;
    std::cout << "x_0 = " << std::scientific << std::setprecision(4) <<  x_0  << std::endl;
    double x = x_0 + tau * (x_0 *x_0 - n); 
    std::cout << "x_1 = x_0 - tau * f(x_0) = " << x << std::endl;
    int k = static_cast<int>(std::log((1.0-alpha)*eps/std::abs(x - x_0))/std::log(alpha) + 1.0);
    std::cout << "k = " << k << std::endl;
    std::cout << std::endl; 

    for(int i = 2; i <=  k; i++)
    {
        x = x + tau * (x*x - n);
        std::cout << "x_" << i << " = " <<  x << std::endl;
    }
    std::cout << std::endl << "x = " << x << std::endl; 
    return 0;
}
