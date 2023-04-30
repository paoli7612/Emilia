#include <iostream>

using namespace std;

extern "C" {
    double myMain();
}

int main(int argc, char const *argv[])
{
    cout << "myFun() -> " << myMain() << endl;
    return 0;
}
