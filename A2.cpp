#include<bits/stdc++.h>

using namespace std;

#define ll long long 
#define endl "\n" 

unordered_set<char> possibleLetter;
unordered_map<char, vector<char>> convertsTo;


int cost(char initialLetter, char finalLetter){

	// cout<<"Inside cost function "<<endl;
	// cout<<"Convert "<<initialLetter<<" to "<<finalLetter<<endl;


	unordered_set<char> currentPath;
	queue<char> q;
	q.push(initialLetter);
	currentPath.insert(initialLetter);
	ll moves = 0;
	ll minMoves = INT_MAX-1;
	while(!q.empty()){
		int sz = q.size();
		moves++;
		for(int i = 0; i < sz; i++){
			initialLetter = q.front();
			q.pop();
			for(auto pathLetter: convertsTo[initialLetter]){
				if(!currentPath.count(pathLetter)){
					currentPath.insert(pathLetter);
					q.push(pathLetter);

					if(pathLetter == finalLetter){
						return moves;
					}
				}
			}
		}
	}

	return minMoves;

}


int main(){

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	ll t;
	cin >> t;

	for(ll tt = 1; tt <= t; tt++){


		possibleLetter.clear();
		convertsTo.clear();
		// dp.clear();
		// dp.resize(26,vector<int> (26,-1));

		string s;
		cin >> s;

		ll k;
		cin >> k;

		while(k--){
			string temp;
			cin >> temp;

			possibleLetter.insert(temp[1]);
			convertsTo[temp[0]].push_back(temp[1]);
			// dp[temp[0]-'A'][temp[1]-'A'] = 1;

		}


		char org = s[0];
		bool check = true;
		for(int i = 1; i < s.length(); i++){
			if(s[i] != org){
				check = false;
				break;
			}
		}

		if(check){
			cout<<"Case #"<<tt<<": "<<0<<endl;
			continue;
		}


		ll minMoves = INT_MAX-1;
		ll moves = 0;
		string resultingString = "";

		for(auto it = possibleLetter.begin(); it != possibleLetter.end(); it++){
			char finalLetter = *it;
			moves = 0;

			// cout<<"Convert final string to "<<finalLetter<<endl;
			for(auto initialLetter: s){
				// cout<<"Convert "<<initialLetter<<" to "<<finalLetter<<endl;
				if(initialLetter != finalLetter)
					moves += cost(initialLetter, finalLetter);			
				// cout<<"current moves "<<moves<<endl;
				
			}
			// cout<<"Total moves "<<moves<<endl;
			if(moves < minMoves){
				minMoves = moves;
				resultingString = finalLetter;
			}
		}

		minMoves = minMoves == INT_MAX-1 ? -1: minMoves;
		cout<<"Case #"<<tt<<": "<<minMoves<<endl;
		cout<<resultingString;
	}
}


//or

// #include<bits/stdc++.h>

// using namespace std;

// #define ll long long 
// #define endl "\n" 

// int cost(char initialLetter, char finalLetter, unordered_set<char> &currentPath, vector<vector<int>> &dp, unordered_map<char, vector<char>> &convertsTo){


// 	if(initialLetter == finalLetter){
// 		return dp[initialLetter-'A'][finalLetter-'A'] = 0;
// 	}

// 	if(find(convertsTo[initialLetter].begin(),convertsTo[initialLetter].end(), finalLetter) != convertsTo[initialLetter].end()){
// 		return dp[initialLetter-'A'][finalLetter-'A'] = 1;
// 	}

// 	if(dp[initialLetter-'A'][finalLetter-'A'] != -1){
// 		return dp[initialLetter-'A'][finalLetter-'A'];
// 	}

// 	if(currentPath.count(initialLetter)){
// 		return INT_MAX-1;
// 	}

// 	currentPath.insert(initialLetter);

// 	ll moves = 0;
// 	ll minMoves = INT_MAX-1;
// 	for(auto pathLetter: convertsTo[initialLetter]){
// 		moves = 1 + cost(pathLetter, finalLetter, currentPath, dp, convertsTo);
// 		minMoves = min(minMoves, moves);
// 	}

// 	currentPath.erase(initialLetter);
// 	return dp[initialLetter-'A'][finalLetter-'A'] = minMoves;
// }


// int main(){

// 	ios_base::sync_with_stdio(false);
// 	cin.tie(NULL);

// 	ll t;
// 	cin >> t;

// 	for(ll tt = 1; tt <= t; tt++){

// 		unordered_set<char> possibleLetter;
// 		unordered_map<char, vector<char>> convertsTo;

// 		string s;
// 		cin >> s;

// 		ll k;
// 		cin >> k;

// 		while(k--){
// 			string temp;
// 			cin >> temp;

// 			possibleLetter.insert(temp[1]);
// 			convertsTo[temp[0]].push_back(temp[1]);

// 		}


// 		char org = s[0];
// 		bool check = true;
// 		for(int i = 1; i < s.length(); i++){
// 			if(s[i] != org){
// 				check = false;
// 				break;
// 			}
// 		}

// 		if(check){
// 			cout<<"Case #"<<tt<<": "<<0<<endl;
// 			continue;
// 		}


// 		ll minMoves = INT_MAX-1;
// 		ll moves = 0;

// 		string resultingString = "";

// 		for(auto it = possibleLetter.begin(); it != possibleLetter.end(); it++){

// 			unordered_set<char> currentPath;
// 			char finalLetter = *it;
// 			moves = 0;

// 			for(auto initialLetter: s){
// 				//Need new dp array for each letter for min path
// 				vector<vector<int>> dp(26,vector<int> (26,-1));
				

// 				if(initialLetter != finalLetter)
// 					moves += cost(initialLetter, finalLetter, currentPath, dp, convertsTo);			
				
// 			}
// 			// cout<<"Total moves "<<moves<<endl;

// 			if(moves < minMoves){
// 				minMoves = moves;
// 				resultingString = finalLetter;
// 			}
// 		}

// 		minMoves = minMoves == INT_MAX-1 ? -1: minMoves;
// 		cout<<"Case #"<<tt<<": "<<minMoves<<endl;
// 	}
// }