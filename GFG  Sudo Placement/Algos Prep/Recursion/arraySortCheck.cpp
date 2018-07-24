#include <bits/stdc++.h>
using namespace std;

bool isArraySorted(int a[], int n) {
    if (n == 1) {
        return 1;
    } else
    {
        return (a[n-1] < a[n-2]) ? 0 : isArraySorted(a, n-1);
    }
}

int main()
{
    int n;
    std::cout << "Enter Size of array:" << '\n';
    std::cin >> n;
    int arr[n];
    for (size_t i = 0; i < n; i++)
    {
        std::cout << "Enter element " << i << ": " << '\n';
        std::cin >> arr[i];
    }

    if (n == 0) {
        std::cout << "Array is empty" << endl; 
    } else {
        isArraySorted(arr, n) ? std::cout << "Sorted" << endl : std::cout << "Unsorted" << endl;;
    }

    
    system("pause");
    return 0;
}