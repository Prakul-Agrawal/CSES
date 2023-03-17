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
    int n;
    cin >> n;
    string grid[n];
    vvi dp(n, vi(n));
    dp[n-1][n-1] = 1;
    rep(i,0,n) cin >> grid[i];
    for (int i = 2*n - 2; i >= 0; i--)
        rep(j,0,i+1)
        {
            if (j < n - 1 && i-j < n && grid[j+1][i-j] == '.') {
                dp[j][i-j] += dp[j+1][i-j];
                dp[j][i-j] %= MOD;
            }
            if (i-j < n - 1 && j < n && grid[j][i-j+1] == '.') {
                dp[j][i-j] += dp[j][i-j+1];
                dp[j][i-j] %= MOD;
            }
        }
    cout << (grid[0][0] == '*' ? 0 : dp[0][0]) << endl;
}

int main() 
{
    ios::sync_with_stdio(0); // To increase input-output speed
    cin.tie(0);
    // tc
    solve();
}