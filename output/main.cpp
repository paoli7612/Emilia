#include <iostream>

using namespace std;

extern "C" {
    double doppio(double);
}

int main(int argc, char const *argv[])
{
    cout << doppio(5);
    return 0;
}
