#include <bits/stdc++.h>
using namespace std;

#define lint long long int 
lint MOD = 998244353;

lint haha(string str,int loop){
	vector<int> a;
	int re;
	for(int i=0;i<str.length();i++){
		a.push_back(int(str[i])-48);
	}
	while(loop--){
		lint s=a.size();
		lint cnt=s*2-1-s;
		while(cnt--){
			a.push_back(0);
		}
		vector<int> aa=a;
		for(int i=1;i<s;i++){
			a[i*2]=aa[i];
		}
		for(int i=1;i<a.size();i+=2){
			if(a[i+1]==a[i-1]) a[i]=0;
			else a[i]=1;
		}

	}
    lint cnt=0;
    for(int i=0;i<a.size()-1;i++){
        if(a[i]==a[i+1]){
            cnt++;
        }
    }
    return cnt;
}

vector<string> getSubsets(string &str) {
    vector<string> result;
    int n = str.length();

    for (int i = 0; i < n; i++) {
        string current = "";
        for (int j = i; j < n; j++) { 
            current += str[j];
            result.push_back(current);
        }
    }
    return result;
}

int main() {
    lint n,loop;
    cin>>n>>loop;
    string input; 
    cin >> input;

    lint sum = 0;

    vector<string> subsets = getSubsets(input);
    lint prew;
    string psubset;
    sort(subsets.begin(),subsets.end());

    for (const string &subset : subsets) {
        if(subset==psubset) {
            sum+=prew;
            continue;
        }
        prew=haha(subset,loop);
        psubset=subset;
        sum+=prew;
    }

    cout << sum << endl;
    return 0;
}