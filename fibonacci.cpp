#include <iostream>
using namespace std;

int main()
{
    int n, a = 0, b = 1, f = 0;

    std::cout << "Enter number of terms to be in fibonacci series: " << '\n';
    std::cin >> n;

    std::cout << "The Fibonacii series is: " << '\n';

    for (size_t i = 0; i < n; i++)
    {
        if (i == 0)
        {
            std::cout << a << " ";
            continue;
        }
        if (i == 1)
        {
            std::cout << b << " ";
            continue;
        }
        f = a + b;
        a = b;
        b = f;

        std::cout << f << " ";
    }
    
    system("pause");
    return 0;
}
