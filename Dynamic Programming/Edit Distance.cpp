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
    string a,b;
    cin>>a>>b;
    int n = sz(a), m = sz(b);
    int dp[n+1][m+1];
    rep(i,0,n+1) dp[i][0] = i;
    rep(i,0,m+1) dp[0][i] = i;
    rep(i,1,n+1){
        rep(j,1,m+1){
            dp[i][j] = min(dp[i-1][j] + 1, dp[i][j-1] + 1);
            dp[i][j] = min(dp[i-1][j-1] + (a[i-1] != b[j-1]), dp[i][j]);
        }
    }
    cout << dp[n][m] << endl;
}

int main() 
{
    ios::sync_with_stdio(0); // To increase input-output speed
    cin.tie(0);
    // tc
    solve();
}