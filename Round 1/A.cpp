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
		ll n, ans = 0;
		string s;
		cin >> n >> s;

		char first;
		bool seen = 0;
		for(ll i = 0; i < n; i++){
			if(!seen && s[i] != 'F')
				first = s[i], seen = 1;

			if(s[i] != 'F' && s[i] != first){
				ans++;
				first = s[i];
			}

		}

		cout<<"Case #"<<tt<<": "<<ans<<endl;
	}


}