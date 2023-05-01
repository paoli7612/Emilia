#include <iostream>

using namespace std;



extern "C" {
    double myMain();
    void print(double n) {std::cout << n << std::endl;}
}

int main(int argc, char const *argv[])
{
    myMain();
    return 0;
}
