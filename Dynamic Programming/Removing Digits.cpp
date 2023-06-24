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
// dp[i] represents minimum number of steps required to reach 0 from i
// For each number, we subtract each digit from original number and check if the
// number of steps required to reach 0 is less than the current value of dp[i]
// -------------------------------------------------------------------------- //

void solve(){
    int n,temp,digit;
    string s;
    cin >> n;
    vi dp(n+1);
    rep(i,1,n+1)
    {
        dp[i] = MOD;
        temp = i;
        while(temp) {
            digit = temp % 10;
            temp /= 10;
            dp[i] = min(dp[i], dp[i-digit] + 1);
        }
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