#include <iostream>
using namespace std;

int main()
{
    char c;
    std::cout << "Enter the character: ";
    std::cin >> c;
    std::cout << "ASCII value of " << c << " is " << int(c) << endl;
    system("pause");
    return 0;
}
