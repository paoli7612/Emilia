#include <iostream>

using namespace std;

extern "C" {
    double man(double);
    void echo(double n) {std::cout << n << std::endl;}
    void echo2(double n, double m) {std::cout << n << " " << m << std::endl;}
}

int main(int argc, char const *argv[])
{
    std::cout << "____________________________________________" << std::endl;
    double a;
    cin >> a;
    man(a);
    return 0;
}
