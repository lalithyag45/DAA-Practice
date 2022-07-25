#include<bits/stdc++.h>
using namespace std;
int co=0;

int Partition(int a[],int s,int e)
{
int j;
int key=a[e];
int i=s-1;
for(j=s;j<=e;j++)
{
if(a[j]<=key){
i=i+1;
co++;
int temp=a[i];
a[i]=a[j];
a[j]=temp;
}
}
return i;
}

void quicksort(int a[],int s,int e){
if(s>=e) 
return;
int m=Partition(a,s,e);
quicksort(a,s,m-1);
quicksort(a,m+1,e);
}


int main()
{
    ofstream outf;
    ifstream inf;
    clock_t c1,c2;
    double tt;
    int n;
    cout << "Enter number of elements :";
    cin >> n;
    int a[100000];
    outf.open("QuickSort.txt");
    for (int i = 0; i < n; i++)
    {
    outf<<rand()%2000<<" ";
    }
    outf.close();
    inf.open("QuickSort.txt");
    for (int i = 0; i < n; i++)
    {
    inf>>a[i];
    }
    inf.close();
    printf("\n\nBefore sorting array elements are - \n\n");
    for (int i = 0; i < n; i++)
    {
    cout<<a[i]<<" ";
    }
    c1=clock();
    quicksort(a,0,n-1);
    printf("\n\nAfter sorting array elements are - \n\n");
    for (int i = 0; i < n; i++)
    {
    cout<<a[i]<<" ";
    }
    c2=clock();
    tt=(double)(c2-c1)/CLOCKS_PER_SEC;
    cout<<"\n\nExecution time for quick sort: "<<tt<<endl;
    cout<<"\n\n No. of comparisions: "<<co;
    return 0;
}

