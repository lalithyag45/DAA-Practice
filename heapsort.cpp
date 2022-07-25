#include<bits/stdc++.h>
#include<iostream>
#include<fstream>
#include<time.h>
#include<stdlib.h>

using namespace std;
#define ll long long

void adjust(ll a[],ll i,ll n)
{
ll j=2*i;
ll temp=a[i];
while(j<n)
{
if(j<n && a[j]<a[j+1])
{
j=j+1;
}
else if(temp>=a[j])
break;
a[j/2]=a[j];
j=2*j;
}
a[j/2]=temp;
}
void heapify(ll a[], ll n)
{
for(ll i=floor(n/2);i>=0;i--)
{
adjust(a,i,n);
}
}
void heapSort(ll a[], ll n)
{
   ll temp;
   heapify(a, n);
   for (ll i = n-1; i >=1; i--) 
   {

    temp = a[i];
    a[i] = a[0];
    a[0] = temp;
    adjust(a,0,i-1);
   }
}

int main()
{
    ofstream outf;
    ifstream inf;
    clock_t c1,c2;
    double tt;
    ll n;
    cout << "Enter number of elements :";
    cin >> n;
    ll a[100000];
    outf.open("HeapSort.txt");
    for (ll i = 0; i < n; i++)
    {
    //ll k=(rand()%2000)-500;
    outf<<rand()<<" ";
}
outf.close();
inf.open("HeapSort.txt");
for (ll i = 0; i < n; i++)
    {
    inf>>a[i];
}
inf.close();
    printf("\n\nBefore sorting array elements are - \n\n");
    for (ll i = 0; i < n; i++)
    {
    cout<<a[i]<<" ";
}
c1=clock();
heapSort(a,n);
    printf("\n\nAfter sorting array elements are - \n\n");
    for (ll i = 0; i < n; i++)
    {
    cout<<a[i]<<" ";
}
    c2=clock();
    tt=(double)(c2-c1)/CLOCKS_PER_SEC;
    cout<<"\n\nExecution time for heap sort: "<<tt<<endl;
    return 0;
}

