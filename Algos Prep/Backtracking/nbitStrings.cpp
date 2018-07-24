#include <bits/stdc++.h>
using namespace std;

char arr[10];

void Binary(int n)
{
    
    if (n < 1)
    {
        printf("%s\n",arr);
    }
    else
    {
        arr[n-1] = '0';
        Binary(n-1);
        arr[n-1] = '1';
        Binary(n-1);
    }
}

int main()
{
    int n;
    std::cout << "Enter no of bits: " << endl;
    std::cin >> n;
    Binary(n);

    system("pause");
    return 0;
}