// Source: https://usaco.guide/general/io

#include <bits/stdc++.h>
using namespace std;

#define lint long long int

long long MOD=1e9+7;

bool cmp(lint a,lint b){
	return a>b;
}

int main() {
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		vector<lint> a(n);
		for(int i=0;i<n;i++){
			cin>>a[i];
		}
		sort(a.begin(),a.end(),cmp);
		if(n==1){
			a[0]%=MOD;
			cout<<a[0]<<endl;
		}
		else{
		lint sum=a[0]*2+a[1];
		sum%=MOD;
		for(int i=2;i<n;i++){
			sum=sum*2+a[i];
			sum%=MOD;
		}
		cout<<sum<<endl;
		}
	}
}
