// Source: https://usaco.guide/general/io

#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second

// int main() {
// 	ios::sync_with_stdio(0);
// 	cin.tie(0);
// 	int n,m;
// 	cin>>n>>m;
// 	vector<int> g(n);
// 	int mx=0;
// 	for(int i=0;i<n;i++){
// 		cin>>g[i];
// 		mx=max(mx,g[i]);
// 	}
// 	vector<int> ans(n,0);
// 	for(int i=1;i<=mx;i++){
// 		for(int j=0;j<n;j++){
// 			if(m<=0)break;
// 			if(g[j]==i){
// 				ans[j]=1;
// 				m--;
// 			}
// 		}
// 	}
// 	for(int i=0;i<n;i++){
// 		cout<<ans[i]<<" ";
// 	}
// }

int main(){
	int n,m;
	cin>>n>>m;
	vector<pair<int,int>> g(n);
	vector<int> re(n);
	int mx=0;
	for(int i=0;i<n;i++){
		cin>>g[i].fi;
		re[i]=g[i].fi;
		mx=max(mx,g[i].fi);
		g[i].se=0;
	}
	sort(g.begin(),g.end());

	int ind=0;
	while(m--){
		g[ind++].se=1;
	}

	for(int i=0;i<n;i++){
		//cout<<re[i]<<endl;
		for(int j=0;j<n;j++){
			if(re[i]==g[j].fi){
				cout<<g[j].se<<" ";
				g[j].fi=-1;
				break;
			}
		}
	}
}
