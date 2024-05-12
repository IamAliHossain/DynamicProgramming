#include<bits/stdc++.h>
using namespace std;

void recursion(int cnt){
    if(cnt > 5){
        return ;
    }
    recursion(cnt+1);
    cout << cnt << endl;
}

int main(){
    
    recursion(1);
    return 0;
}