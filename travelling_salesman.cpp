// Problem Link: https://www.hackerrank.com/contests/target-samsung-13-nov19/challenges/travelling-salesman-4/problem
// Idea: https://www.youtube.com/watch?v=JE0JE8ce1V0

#include <iostream>
using namespace std;
#define REP(i,a,b) for(int i=a; i<b; i++)
#define f(i,a,b) for(int i=a; i<b; i++)
#define inf 1e9
int t,n,dist[12][12], dp[1<<12][12], visited_all;

int tsp(int mask, int pos){
    if(mask == visited_all) return dist[pos][0];
    if(dp[mask][pos] != -1) return dp[mask][pos];
    int ans = inf;

    for(int i=0; i<n; +i++){
        if((mask&(1<<i))==0){
            int newans = dist[pos][i] + tsp(mask|(1<<i),i);

            ans = min(ans,newans);
        }
    }
    return dp[mask][pos] = ans;
}




int main()
{
    cin >> t;
    while(t--)
    {
        cin >> n;

        visited_all = (1<<n) - 1; /// 100000 - 000001 = 99999 >>in binary 11111 means all visited
        int p = 1<<n;
       f(i,0,p) f(j,0,n) dp[i][j] = -1;

        f(i,0,n) f(j,0,n) {
        cin>>dist[i][j];
        }
        cout << tsp(1,0) << "\n";


    }
}
