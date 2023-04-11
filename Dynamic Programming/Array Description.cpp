#include <bits/stdc++.h>
using namespace std;

#define MOD 1000000007
typedef long long ll;
typedef long double ldb;
//#define int ll
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<vi> vvi;
typedef vector<pii> vii;
typedef vector<vii> vvii;
#define ff first
#define ss second
#define pb push_back
#define endl '\n'
#define all(s) s.begin(), s.end()
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define sz(x) (int)(x).size()
#define tc int t; cin>>t; while(t--)
#define max_heap(x) priority_queue<x>
#define min_heap(x) priority_queue<x, vector<x>, greater<x>>

void solve(){
    int n,m;
    cin >> n >> m;
    vi x(n);
    rep(i,0,n) cin >> x[i];

    vvi dp(n, vi(m+1,0));

    if (x[0] != 0) dp[0][x[0]] = 1;
    else rep(i,1,m+1) dp[0][i] = 1;

    rep(i,1,n){
        int val = x[i];
        if (val != 0){
            dp[i][val] = dp[i-1][val];
            if (val > 1) {
                dp[i][val] += dp[i-1][val-1];
                dp[i][val] %= MOD;
            }
            if (val < m) {
                dp[i][val] += dp[i-1][val+1];
                dp[i][val] %= MOD;
            }
        }
        else{
            rep(j,2,m){
                dp[i][j] = (dp[i-1][j]);
                dp[i][j] += dp[i-1][j-1];
                dp[i][j] %= MOD;
                dp[i][j] += dp[i-1][j+1];
                dp[i][j] %= MOD;
            }
            if (m == 1) dp[i][1] = dp[i-1][1];
            else{
                dp[i][1] = (dp[i-1][1] + dp[i-1][2]) % MOD;
                dp[i][m] = (dp[i-1][m] + dp[i-1][m-1]) % MOD;
            }
        }
    }

    int total = 0;
    rep(i,1,m+1){
        total += dp[n-1][i];
        total %= MOD;
    }

    cout << total << endl;
}

int main() 
{
    ios::sync_with_stdio(0); // To increase input-output speed
    cin.tie(0);
    // tc
    solve();
}