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

// ------------------------------ Explanation ------------------------------ //
// dp[i] represents number of ways to make sum i using a die
// Since the die only shows 1, 2, 3, 4, 5, 6, we can make sum i using 
// sum i - 1, i - 2, i - 3, i - 4, i - 5, i - 6
// Hence, dp[i] = dp[i-1] + dp[i-2] + dp[i-3] + dp[i-4] + dp[i-5] + dp[i-6]
// -------------------------------------------------------------------------- //

void solve(){
    int n;
    cin >> n;

    vi dp(n+1);
    dp[0] = 1;
    rep(i,1,n+1)
        rep(j,1,7)
            if (i - j >= 0) {
                dp[i] += dp[i-j];
                dp[i] %= MOD;
            }
    cout << dp[n] << endl;
}

int main() 
{
    ios::sync_with_stdio(0); // To increase input-output speed
    cin.tie(0);
    // tc
    solve();
}