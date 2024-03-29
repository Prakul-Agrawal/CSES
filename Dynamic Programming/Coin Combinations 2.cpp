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
// dp[i] represents number of ways to make sum i
// It is similar to Coin Combinations 1, but we have to take care of the order
// Hence, we iterate over the coins first and then the sums
// This ensures that the sum is made in the order of the coins that were given
// -------------------------------------------------------------------------- //

void solve(){
    int n,x;
    cin >> n >> x;
    vi c(n);
    rep(i,0,n) cin >> c[i];

    vi dp(x+1);
    dp[0] = 1;
    rep(j,0,n)
        rep(i,1,x+1)        
            if (i - c[j] >= 0) {
                dp[i] += dp[i-c[j]];
                dp[i] %= MOD;
            }
    cout << dp[x] << endl;
}

int main() 
{
    ios::sync_with_stdio(0); // To increase input-output speed
    cin.tie(0);
    // tc
    solve();
}