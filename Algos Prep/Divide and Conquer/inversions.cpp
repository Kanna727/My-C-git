#include <bits/stdc++.h>
using namespace std;

unsigned long long int invCountMerge(vector<int> v, int l, int m, int r)
{
    int i, j, k, lRem;
    unsigned long long int inv;
    int n1 = m - l + 1;
    int n2 = r - m;

    int L[n1], R[n2];

    for (i = 0; i < n1; i++)
        L[i] = v[l + i];
    for (j = 0; j < n2; j++)
        R[j] = v[m + 1 + j];

    i = 0;
    j = 0;
    k = l;
    lRem = n1;
    inv = 0;

    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            v[k++] = L[i++];
            lRem--;
        }
        else
        {
            v[k++] = R[j++];
            inv += lRem;
        }
    }

    /* Copy the remaining elements of L[], if there 
       are any */
    while (i < n1)
    {
        v[k++] = L[i++];
    }

    /* Copy the remaining elements of R[], if there 
       are any */
    while (j < n2)
    {
        v[k++] = R[j++];
    }
    return inv;
}

unsigned long long int invCount(vector<int> v, int l, int r) /*                | 6, 5, 4, 3, 2, 1 |                 */
{                                                            /*               l=0      m=2       r=5                */
    unsigned long long int invC = 0;
    if (l < r)                    /*           | 6, 5, 4 |         | 3, 2, 1 |           */
    {                             /*          l=0  m=1  r=2       l=3  m=4  r=5          */
        int m = l + (r - l) / 2;  /*        | 6, 5 |            | 3, 2 |                 */
        invC = invCount(v, l, m); /*       l=0 m=0 r=1         l=3 m=3 r=4               */
        invC += invCount(v, m + 1, r);

        invC += invCountMerge(v, l, m, r);
    }
    return invC;
}   

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, a;
        cin >> n;
        int size = n;
        vector<int> v;
        while (n--)
        {
            cin >> a;
            v.push_back(a);
        }

        cout << invCount(v, 0, size - 1) << endl;
    }

    system("pause");
    return 0;
}