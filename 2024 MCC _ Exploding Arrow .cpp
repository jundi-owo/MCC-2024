// Source: https://usaco.guide/general/io

#include <bits/stdc++.h>
using namespace std;

#define lint long long int

lint n;
vector<lint> a;

int low_bin(lint l, lint r, function<bool(lint)> f){
	while(l < r){
		lint mid = l + (r - l)/2;
		if(f(mid)) r = mid;
		else l = mid + 1;
    }
  return l;
}

bool check(vector<lint> &rea){
	for(int i=0;i<n;i++){
		if(rea[i]>0) return false;
	}
	return true;
}

int main() {
	lint m,k;
	cin>>n>>m>>k;
	a.resize(n);
	for(int i=0;i<n;i++){
		cin>>a[i];
	}

	lint result = low_bin(0, 1e9, [&](lint x){
		vector<lint> rea=a;
		lint ind=0;
		lint rek=k;
		lint re=-1;
		while(rek--){
			cout<<ind<<" ";
			for(lint i=ind;i<n;i++){
				lint d=(m*x)-(i-ind)*(i-ind);
				if(d>0) rea[i]-=d;
			}
			for(int i=0;i<n;i++){
				if(rea[i]>0) {
					ind=i;
					break;
				}
			}
		}
		return (check(rea));
	});

	cout<<endl<<result<<endl;

	// vector<lint> rea=a;
	// 	lint ind=0;
	// 	lint rek=k;
	// 	lint re=-1;
	// 	lint x=172009;
	// 	while(rek--){
	// 		for(lint i=ind;i<n;i++){
	// 			lint d=(m*x)-(i-ind)*(i-ind);
	// 			if(d>0) rea[i]-=d;
	// 			if(rea[i]<=0) re=max(re,i+1);
	// 		}
	// 		if(re!=-1) ind=re;
	// 	}
		
	// 	if(check(rea))cout<<"yes";
	// 	else cout<<"NO";

}
