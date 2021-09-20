#include<bits/stdc++.h>

using namespace std;

#define ll long long 
#define endl "\n" 

bool isVowel(char x){
	return x == 'A' || x == 'E' || x  == 'I' || x == 'O' || x == 'U';
}

int main(){

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	ll t;
	cin >> t;

	for(ll tt = 1; tt <= t; tt++){
		string s;
		cin >> s;

		ll minMoves = INT_MAX-1;
		ll moves = 0;

		for(char x = 'A'; x <= 'Z'; x++){
			moves = 0;
			for(auto ch: s){
				if(ch != x){
					if((isVowel(ch) && isVowel(x)) || (!isVowel(ch) && !isVowel(x))){
						moves += 2;
					}

					else
						moves++;
				}
			}
			minMoves = min(minMoves, moves);
		}

		cout<<"Case #"<<tt<<": "<<minMoves<<endl;
	}




}