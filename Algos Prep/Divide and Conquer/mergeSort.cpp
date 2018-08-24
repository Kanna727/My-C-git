#include <bits/stdc++.h>
using namespace std;

void mergeSort(int arr[], int temp[], int l, int r);
void merge(int arr[], int l, int m, int r);

void merge(int arr[], int temp[], int l, int m, int r)
{
    int i, j, k;
    i = l;
    j = m;
    k = l;
    while ((i <= m - 1) && (j <= r))
    {
        if (arr[i] <= arr[j])
        {
            temp[k++] = arr[i++];
        }
        else
        {
            temp[k++] = arr[j++];
        }
    }

    while (i <= m - 1)
    {
        temp[k++] = arr[i++];
    }
    while (j <= r)
    {
        temp[k++] = arr[j++];
    }
    for (i = l; i <= r; i++)
    {
        arr[i] = temp[i];
    }
}

void _mergeSort(int arr[], int s){
    int *temp = (int *)malloc(sizeof(int)*s);
    mergeSort(arr, temp, 0, s-1);
}

void mergeSort(int arr[], int temp[], int l, int r)
{
    if (l < r)
    {
        int m = l + (r - l) / 2;
        mergeSort(arr, temp, l, m);
        mergeSort(arr, temp, m + 1, r);

        merge(arr, temp, l, m + 1, r);
    }
}

int main()
{
    int n;
    std::cout << "Enter no of elements to sort: " << endl;
    std::cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        int a;
        std::cin >> a;
        arr[i] = a;
    }
    _mergeSort(arr, n);
    for (int i = 0; i < n; i++)
    {
        std::cout << arr[i] << " ";
    }

    system("pause");
    return 0;
}