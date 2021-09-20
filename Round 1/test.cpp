#include <iostream>
using namespace std;

int main()
{
   int T;
   cin >> T;
   int N;
   int M;
   int A;
   int B;

   for(int i = 0; i < T; i++)
   {
       cin>>N>>M>>A>>B;

       a  < 1 + 

       if(A < N+M-1 || B < N+M-1)
       {
           cout<<"Case"<<" "<<"#"<<i+1<<":"<<" "<<"Impossible"<<endl;
           continue;
       }

       cout<<"Case"<<" "<<"#"<<i+1<<":"<<" "<<"Possible"<<endl;

       vector<vector<int>> v(N,vector<int>(M, 1));
        v[N-1][M-1] = A-(M+N-1);
        v[N-1][0] = B - (M+M-1);

       for(int j = 0; j< N; j++)
       {
           for(int k = 0; k < M; k++)
           {
               cout<<v[j][k];<<" ";
           }
           cout<<endl;
       }
       v.empty();

   }

}