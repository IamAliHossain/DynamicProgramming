
#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N = 1e5+5;
vector<ll> dp(N, -1);
ll ar[N][4];

/*This recursion will return TLE verdict to get rid of TLE use DP */

ll performance(int day, int last){
    if(day == 0){
        ll mx = 0;
        for(int task=0; task<3; task++){
            if(task != last){
                mx = max(mx, ar[0][task]);
            }
        }
        return mx;
    }
    ll mx = 0, take = 0;
    for(int task=0; task<3; task++){
        if(task != last){
            take = ar[day][task] + performance(day-1, task);
        }
        mx = max(mx, take);
    }
    return mx;
}

/* Top Down Approach (Memoization) */

vector<vector<int>> dp1(N, vector<int> (4, -1));

ll performance1(int day, int last){
    if(day == 0){
        ll mx = 0;
        for(int task = 0; task<3; task++){
            if(task != last){
                mx = max(mx, ar[0][task]);
            }
        }
        return dp1[0][last] = mx;
    }
    if(dp1[day][last] != -1){
        return dp1[day][last];
    }
    ll mx = 0;
    for(int task = 0; task<3; task++){
        if(task != last){
            ll take = ar[day][task] + performance1(day-1, task);
            mx = max(mx, take);
        }
    }

    return dp1[day][last] = mx ;
}

/*Bottom Up Approach (Tabulation) */


int performance2(int n){
    vector<vector<int>> dp2(n, vector<int>(4, 0));
    
    dp2[0][0] = max(ar[0][1], ar[0][2]);
    dp2[0][1] = max(ar[0][0], ar[0][2]);
    dp2[0][2] = max(ar[0][0], ar[0][1]);
    dp2[0][3] = max({ar[0][0], ar[0][1], ar[0][2]});

    for(int day=1; day<n; day++){
        for(int last=0; last<4; last ++){ 
            dp2[day][last] = 0;
            for(int task = 0; task<3; task++){
                if(task != last){
                    int take = ar[day][task] + dp2[day-1][task];
                    dp2[day][last] = max(dp2[day][last], take);
                }
            }
        }
    }
    return dp2[n-1][3];
}

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n; cin >> n;
    for(int i=0; i<n; i++){
        for(int j=0; j<3; j++){
            cin>> ar[i][j];
        }
    }
    // cout << performance(n-1, 3) << endl;
    // cout << performance1(n-1, 3) << endl;
    cout << performance2(n) << endl;

}