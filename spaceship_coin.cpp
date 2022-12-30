#include<iostream>
using namespace std;
#define inf 1e9

int ans,arr[12][7];

void recur (int arr[10][5], int i, int j,int boomused ,int row, int coins){

    if(i<0 || j<0 || j>=5){
        ans = max(ans,coins);
        return ;
    }

    if(arr[i][j] == 1 || arr[i][j] == 0){
        int new_coins = coins;
        if(arr[i][j] == 1){
            new_coins++;
        }
        if(boomused) row--;
        recur(arr,i-1,j-1,boomused,row,new_coins);
        recur(arr,i-1,j,boomused,row,new_coins);
        recur(arr,i-1,j+1,boomused,row,new_coins);

    }
    else if(arr[i][j]==2){
        if(boomused ){
            if(row<=0){
                ans = max(ans,coins);
                return;
            }
            else{
                row--;
                recur(arr,i-1,j-1,boomused,row,coins);
                recur(arr,i-1,j,boomused,row,coins);
                recur(arr,i-1,j+1,boomused,row,coins);
            }
        }
        else{
            boomused = 1;
            row = 4;
                recur(arr,i-1,j-1,boomused,row,coins);
                recur(arr,i-1,j,boomused,row,coins);
                recur(arr,i-1,j+1,boomused,row,coins);

            }



    }
}
int main(){
    int t;
    cin>>t;
    for(int i = 1; i<=t; i++){
        int n;
        cin>>n;
        int arr[n][5];

        for(int i=0; i<n; i++){
            for(int j = 0; j<5; j++){
                cin>>arr[i][j];
            }
        }

        ans = 0;

        bool boomused = 0;
        int row =0,coins = 0;

        recur(arr,n-1,1,boomused,row,coins);
        recur(arr,n-1,2,boomused,row,coins);
        recur(arr,n-1,3,boomused,row,coins);
        cout << "#" << i << " " << ans << "\n";



    }

}
