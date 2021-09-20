#include<bits/stdc++.h>

using namespace std;

#define ll long long 
#define endl "\n" 

int main(){

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	ll t;
	cin >> t;
	for(ll tt = 1; tt <= t; tt++){
		ll n, m, a, b;
		cin >> n >> m >> a >> b;

		vector<vector<int>> ans(n, vector<int> (m,1000));

		for(ll i = 1; i < n; i++){
			ans[i][0] = 1;
			ans[i][m-1] = 1;
		}

		for(ll j = 0; j < m; j++)
			ans[n-1][j] = 1;

		ans[0][0] = a-(m+n-2);
		ans[0][m-1] = b-(m+n-2);

		if(ans[0][0] < 1 || ans[0][m-1] < 1){
			cout<<"Case #"<<tt<<": Impossible"<<endl;
			continue;
		}
		cout<<"Case #"<<tt<<": Possible"<<endl;
		for(auto row:  ans){
			for(auto col: row)
				cout<<col<<" ";
			cout<<endl;
		}
	}


}