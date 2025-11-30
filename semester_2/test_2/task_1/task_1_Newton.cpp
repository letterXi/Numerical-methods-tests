#include <iostream>
#include <cmath>
#include <iomanip>

int main()
{
    double a = 2.0;
    double b = 3.0;
    double eps = 1e-3;
    int n = 8;
    double x = (a + b) / 2.0;
    
    int k = static_cast<int>(std::log(std::log(eps/2.0)/std::log(0.5))/std::log(2)) + 1; 

    std::cout << "sqrt(" << n << ") = ?" << std::endl;
    std::cout << "f(x) = x^2 - " << n << std::endl;
    std::cout << "f'(x) = 2*x" << std::endl;
    std::cout << "phi(x) = x - f(x)/f'(x)" << std::endl;
    std::cout << "x_0 = " <<  x << std::endl;
    std::cout << "k = " << k << std::endl;
    std::cout << std::endl;

    for(int i = 1; i <=  k; i++)
    {
        x = x - (x*x - n) / (2*x);
        std::cout << std::scientific << std::setprecision(5) <<  "x_" << i << " = " <<  x << std::endl;
    }
    std::cout << std::endl << "x = " << x << std::endl; 
    return 0;
}
