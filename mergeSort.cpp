#include <bits/stdc++.h>
using namespace std;

void MERGE(int A[], int low, int mid, int high)
{
    int h = low;
    int i = low;
    int j = mid + 1;
    int B[1000];
    while (h <= mid and j <= high)
    {
        if (A[h] <= A[j])
        {
            B[i] = A[h];
            h++;
        }
        else
        {
            B[i] = A[j];
            j++;
        }
        i++;
    }
    if (h > mid)
    {
        for (int k = j; k <= high; k++)
        {
            B[i] = A[k];
            i++;
        }
    }
    else
    {
        for (int k = h; k <= mid; k++)
        {
            B[i] = A[k];
            i++;
        }
    }
    for (int j = low; j <= high; j++)
    {
        A[j] = B[j];
    }
}
void mergesort(int A[], int low, int high)
{
    if (low < high)
    {
        int mid = (low + high) / 2;
        mergesort(A, low, mid);
        mergesort(A, mid + 1, high);
        MERGE(A, low, mid, high);
    }
}

int main()
{
    ofstream outf;
    ifstream inf;
    clock_t c1, c2;
    double tt;
    int n;
    c1 = clock();
    cout << "Enter no.of elements in the array: ";
    cin >> n;
    int a[n];
    outf.open("merge_input.txt");
    for (int i = 0; i < n; i++)
    {
        outf << rand() % 2000 << " ";
    }
    outf.close();
    inf.open("merge_input.txt");
    for (int i = 0; i < n; i++)
    {
        inf >> a[i];
    }
    inf.close();
    cout << "\nBefore Sorting:\n";
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
    mergesort(a, 0, n - 1);
    cout << "\nAfter Sorting:\n";
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
    outf.open("merge_output.txt");
    for (int i = 1; i <= n; i++)
    {
        outf << a[i] << " ";
    }
    outf.close();
    c2 = clock();
    tt = (double)(c2 - c1) / CLOCKS_PER_SEC;
    cout << "\nMerge sort execution Time: " << tt << " seconds\n";
    return 0;
}
