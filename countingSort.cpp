#include<iostream>
#include<fstream>
#include<time.h>
#include<stdlib.h>
using namespace std;  
  
int getMax(int a[], int n) 
{  
   int max = a[0];  
   for(int i = 1; i<n; i++)
    {  
      if(a[i] > max)  
         max = a[i];  
   }  
   return max; 
}  
  
void countSort(int a[], int n) 
{  
   int output[n+1];  
   int max = getMax(a, n);  
   int count[max+1];
  
  
  for (int i = 0; i <= max; ++i)   
  {  
    count[i] = 0;
  }  
    
  for (int i = 0; i < n; i++)  
  {  
    count[a[i]]++;  
  }  
  
   for(int i = 1; i<=max; i++)   
      count[i] += count[i-1]; 
   
  for (int i = n - 1; i >= 0; i--) {  
    output[count[a[i]]-1] = a[i];  
    count[a[i]]--;  
}  
  
   for(int i = 0; i<n; i++) {  
      a[i] = output[i];  
   }  
}  
 
  
int main(){
	ofstream outf;
	ifstream inf;
	clock_t start,end;
	double etime;
    int n;
    
    cout<<"Enter no.of elements in the array: ";
    cin>>n;
    int a[n];
    srand((long int)clock());
    outf.open("countsort_input.txt");
    for(int i = 0 ; i<n ; i++){
    	outf<<rand()%500<<"\t";
	}
    outf.close();
    inf.open("countsort_input.txt");
    for(int i=0 ; i<n;i++){
    	inf>>a[i];
	}
    inf.close();    
    cout<<"\nBefore Sorting:\n";
	for(int i=0;i<n;i++){
		cout<<a[i]<<"\t";
	}
	start = clock();
    countSort(a,n);
    end=clock();
    cout<<"\nAfter Sorting:\n";
	for(int i=0;i<n;i++){
		cout<<a[i]<<"\t";
	}
    outf.open("countsort_output.txt");
	for(int i=1;i<=n;i++){
		outf<<a[i]<<"\t";
	}
	outf.close();

	etime=(double)(end-start)/CLOCKS_PER_SEC;
	cout<<"\nExecution Time: "<<etime<<" seconds\n";
    return 0;
}


