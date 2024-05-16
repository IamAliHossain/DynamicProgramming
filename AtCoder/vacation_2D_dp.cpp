
#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N = 1e5+5;
vector<ll> dp(N, -1);
int ar[N][3];

ll performance(int day, int last){
    if(day == 0){
        ll mx = 0, take = 0;
        for(int i=0; i<3; i++){
            if(i != last){
                take = ar[day][i] + performance(day-1, i);
            }
        }
        return max(mx, take);
    }
    ll mx = 0, take = 0;
    for(int i=0; i<3; i++){
        if(i != last){
            take = ar[day][i] + performance(day-1, i);
        }
    }
    return max(mx, take);
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
    cout << performance(n-1, 3) << endl;

}