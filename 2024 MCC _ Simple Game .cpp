#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second
#define lint long long int

bool cmp(pair<int,int> a,pair<int,int> b){
	if(a.se==b.se) return a.fi>b.fi;
	return a.se>b.se;
}

bool cmp2(int a,int b){
	return a>b;
}

int main() {
	int n;
	cin>>n;
	vector<pair<int,int>> a(n);
	for(int i=0;i<n;i++){
		cin>>a[i].fi>>a[i].se;
	}
	sort(a.begin(),a.end(),cmp);

	vector<int> resum(n);
	lint suma=0;
	lint sumb=0;

	for(int i=0;i<n;i++){
		resum[i]=a[i].fi+a[i].se;
	}
	sort(resum.begin(),resum.end(),cmp2);
	// for(int i=0;i<n;i++){
	// 	cout<<resum[i]<<" ";
	// }
	//cout<<endl;

	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			if(resum[i]==a[j].se+a[j].fi){
				if(i%2==0) suma+=a[j].fi;
				if(i%2==1) sumb+=a[j].se;
				a[j].fi=0; a[j].se=0;
				break;
			}
		}
	}
	cout<<suma-sumb;
}