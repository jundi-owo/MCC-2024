// Source: https://usaco.guide/general/io

#include <bits/stdc++.h>
using namespace std;

#define lint long long int

int main() {
	int t;
	cin>>t;
	while(t--){
		lint n,m,a,b;
		cin>>n>>m>>a>>b;
		if((n<a && n<b)||(m<a && m<b)||(a>n && a>m)||(b>n && b>m)) cout<<"NO"<<endl;
		else if(n==a || m==b || n==b || m==a) cout<<"YES"<<endl;
		else cout<<"NO"<<endl;
	}
}
