#include <bits/stdc++.h>
#define FAST ios_base::sync_with_stdio(false); cin.tie(NULL);cout.tie(NULL)
#define endl "\n"
#define rep(i, a, b) for(auto i = a; i < b; ++i)
#define REP(i, a, b) for(auto i = a; i <= b; ++i)
#define pii pair<int, int>
#define all(v) (v).begin(), (v).end() 
#define pb push_back
#define INF 987654321

using namespace std;
typedef long long ll;
typedef unsigned long long ull;

int n, m;
vector<int> money;

bool check(int x){
    int sum = 0;
    int cnt = 0;

    rep(i, 0, n){
        if (sum + money[i] <= x){
            sum += money[i];
        }
        else{
            if(money[i] > x) return false;
            cnt ++;
            sum = money[i];
        }
    }
    return cnt < m;
}

int main(){
    FAST;
#ifndef ONLINE_JUDGE
    clock_t start = clock();
    // freopen("input.txt", "r", stdin);
#endif
    cin >> n >> m;
    money.resize(n);
    for(auto& mon : money) cin >> mon;

    int lo = 0;
    int hi = 10e9;

    while(lo + 1 < hi){
        int mid = (lo + hi) >> 1;
        if(!check(mid)){
            lo = mid;
        }
        else{
            hi = mid;
        }
    }
    cout << hi << endl;
    // cout << "hi: " << hi << endl;
    // cout << "lo: " << lo << endl;

#ifndef ONLINE_JUDGE
    cout << endl << "elapsed time: " << static_cast<double>(clock() - start) / CLOCKS_PER_SEC << "ms" << endl;
#endif
    return 0;
}