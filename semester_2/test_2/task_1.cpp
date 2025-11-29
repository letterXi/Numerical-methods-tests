#include <iostream>
#include <fstream>

int main()
{
    double a = 2.0;
    double b = 3.0;
//    double eps = 1e-3;
    int n = 8;
    double tau = -1.0/8.0;
    double x = (a + b) / 2.0;

    std::ofstream file("task_1_fpi.txt");
        if (!file.is_open())
    {
        return 1;
    }

    file << "sqrt(" << n << ") = ?" << std::endl;
    file << "f(x) = x^2 - " << n << std::endl;
    file << "phi(x) = x + tau * f(x)" << std::endl;
    file << "tau = " << -1.0/8.0 << std::endl;
    file << "x_0 = " << x << std::endl;
    file << std::endl;

    for(int i = 1; i <=  n; i++)
    {
        x = x + tau * (x*x - n);
        file << "x_" << i << " = " <<  x << std::endl;
    }
    file << std::endl << "x = " << x << std::endl; 
    file.close();
    return 0;
}
