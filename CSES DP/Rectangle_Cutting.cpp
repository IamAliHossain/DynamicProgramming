#include<bits/stdc++.h>
using namespace std;

int main(){
    int a, b ;
    cin >> a >> b ;
    vector<vector<int>> dp(a+1, vector<int> (b+1, 1e9));
    // dp state
    // dp[i][j] --> for i lenght and j width , min number of possible rectangle
    //  that can be cutted into two parts
    
    // base case
    // dp[i][j] = 0 if i == j

    for(int i=1; i<=a; i++){
        for(int j=1; j<=b; j++){
            // transition
            if(i == j){
                dp[i][j] = 0;
                continue;
            }
            // horizontal cuts
            for(int h = 1; h<=i-1; h++){
                dp[i][j] = min(dp[i][j], (dp[h][j] + dp[i-h][j] + 1) );
            }
            // vertical cuts
            for(int v = 1; v<=j-1; v++){
                dp[i][j] = min(dp[i][j], (dp[i][v] + dp[i][j-v] + 1) );
            }   
        }
    }
    // final subproblem 
    cout << dp[a][b] << endl;
}