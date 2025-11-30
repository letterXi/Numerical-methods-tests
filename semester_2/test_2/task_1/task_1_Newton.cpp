#include <iostream>
#include <fstream>
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

    std::ofstream file("task_1_Newton.txt");
        if (!file.is_open())
    {
        return 1;
    }

    file << "sqrt(" << n << ") = ?" << std::endl;
    file << "f(x) = x^2 - " << n << std::endl;
    file << "f'(x) = 2*x" << std::endl;
    file << "phi(x) = x - f(x)/f'(x)" << std::endl;
    file << "x_0 = " <<  x << std::endl;
    file << "k = " << k << std::endl;
    file << std::endl;

    for(int i = 1; i <=  k; i++)
    {
        x = x - (x*x - n) / (2*x);
        file << std::scientific << std::setprecision(5) <<  "x_" << i << " = " <<  x << std::endl;
    }
    file << std::endl << "x = " << x << std::endl; 
    file.close();
    return 0;
}
