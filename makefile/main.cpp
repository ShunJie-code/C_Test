#include <iostream>
#include "functions.h"
using namespace std;

int main()
{
    PrintHello();
    cout << "This is "<< __func__ << endl;
    cout << "The factorial of 5 is: " << Factorial(5) << endl;
    return 0; 
}