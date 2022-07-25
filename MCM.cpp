#include<iostream>
#include<limits.h>
using namespace std;
int no_steps=0;
int ind[4][4];
int matrixOrder(int p[],int n)
{
	int m[n][n],i,j,k,l;
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			ind[i][j]=-1;
		}
	}
	for(i=0;i<n;i++)
	{
		m[i][i]=0;
	}
	for(l=2;l<n;l++)
	{
		for(i=1;i<n-l+1;i++)
		{
			j=i+l-1;
			m[i][j]=INT_MAX;
			for(k=i;k<j;k++)
			{
				no_steps++;
				int c=m[i][k]+m[k+1][j]+p[i-1]*p[k]*p[j];
				if(c<m[i][j])
				{
					m[i][j]=c;
					ind[i][j]=k;
				}
				
			}
		}
	}
	return m[1][n-1];
}
void printparents(int i,int j)
{

	if(i==j)
		cout<<"A"<<i;
		else
		{
			cout<<"(";
			printparents(i,ind[i][j]);
			printparents(ind[i][j]+1,j);
			cout<<")";
			
		}
	
}
int main()
{
	int p[]={40,20,30,10,30};
	int n=sizeof(p)/sizeof(p[0]);
	int cost=matrixOrder(p,n);
	cout<<"\n min cost: "<<cost;
	cout<<"\n num of steps: "<<no_steps;
	cout<<"\n optimal parenthesisation: ";
	printparents(1,n-1);
	
	
}
