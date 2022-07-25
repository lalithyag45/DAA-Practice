#include <iostream>
#include <fstream>
#include <time.h>
#include <stdlib.h>
#include <limits.h>
#include <algorithm>
using namespace std;
#define ll long long
ll inf = INT_MAX;
ll maxsum_bruteforce(ll a[] ,ll n){
	ll cur_sum= 0;
	ll max_sum = 0;
	for(int i=0; i<n;i++){
		cur_sum =0;
		for(int j=i;j<n;j++){
			cur_sum += a[j];
			max_sum = max(max_sum ,cur_sum);
		}
	}
	return max_sum;
}
ll max_crossing(ll a[], ll low ,ll mid , ll high){
	ll leftsum = INT_MIN;
	ll sum = 0;
	for(ll i = mid ; i>=low ;i--){
		sum+=a[i];
		if(sum>leftsum){
			leftsum= sum;
		}
	}
	ll rightsum = INT_MIN;
	sum=0;
	for(ll j=mid+1;j<=high ; j++){
		sum+=a[j];
		if(sum>rightsum){
			rightsum = sum;
		}
	}
	return leftsum + rightsum;
}
ll maxsum_dandc(ll a[] , ll low , ll high){
	if(low == high){
		return a[low];
	}
	else{
		ll mid = (low + high)/2;
		ll leftsum = maxsum_dandc(a, low,mid);
		ll rightsum = maxsum_dandc(a,mid+1,high);
		ll crosssum = max_crossing(a,low,mid,high); 
		ll ans = max(leftsum , rightsum);
		ans = max(ans , crosssum);
		return ans;
	}
}


int main(){
	ofstream outf;
	ifstream inf;
	clock_t start,end;
	double ebrut , edc;
	ll n;
	cout<<"enter n value:  ";
	cin>>n;
	ll a[100005];
	srand((long int)clock());
	outf.open("maxsum_input.txt");
	for(ll i=0;i<n;i++){
		ll k = (rand()%2000) - 500;
		outf<<k<<"\t";
	}
	outf.close();
	inf.open("maxsum_input.txt");
	for(int i=0;i<n;i++){
		inf>>a[i];
	}
	inf.close();
	cout<<"Generated Array"<<endl;
	for(int i=0;i<n;i++){
		cout<<a[i]<<" ";
	}
	cout<<endl;
	
	start = clock();
	ll ans1 = maxsum_bruteforce(a,n);
	cout<<"max sum subarray:"<<ans1<<endl;
	end = clock();
	ebrut = (double)(end -start)/CLOCKS_PER_SEC;
	
	start = clock();
	ll ans2 = maxsum_dandc(a,0,n-1);
	cout<<"max sum subarray:"<<ans2<<endl;      
	end = clock();
	edc = (double)(end -start)/CLOCKS_PER_SEC;
	
	cout<<"execution time for bruteforce approach:"<<ebrut<<endl;
	cout<<"execution time for DandC approach:"<<edc<<endl;
	return 0;
}
