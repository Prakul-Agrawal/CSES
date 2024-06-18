//
// Created by Prakul Agrawal on 6/18/24.
//

#include <bits/stdc++.h>

using namespace std;

#define MOD 1000000007
#define INF 1e18
typedef long long ll;
// typedef int ll;
typedef long double ldb;
typedef pair<int, int> pii;
typedef pair <ll, ll> pll;
typedef pair<ll, int> pli;
typedef pair<int, ll> pil;
typedef vector<int> vi;
typedef vector <ll> vl;
typedef vector <vi> vvi;
typedef vector <vl> vvl;
typedef vector <pii> vpii;
typedef vector <pll> vpll;
typedef vector <pli> vpli;
typedef vector <pil> vpil;
typedef vector <vpii> vvpii;
typedef vector <vpll> vvpll;
typedef vector <vpli> vvpli;
typedef vector <vpil> vvpil;
#define ff first
#define ss second
#define pb push_back
#define endl '\n'
#define all(s) s.begin(), s.end()
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define sz(x) (int)(x).size()
#define tc int t; cin>>t; while(t--)
#define printcase int t; cin>>t; for(int i=1;i<=t;i++){cout<<"Case #"<<i<<": ";solve();}
#define max_heap(x) priority_queue<x>
#define min_heap(x) priority_queue<x, vector<x>, greater<x>>

ll count(ll x) {
    if (x < 0){
        return 0;
    }
    vi num(20, 0);
    for (int i = 0; i < 20; i++) {
        num[i] = x % 10;
        x /= 10;
    }
    reverse(all(num));
    vector<vector<vvl>> dp(20, vector<vvl>(2, vvl(10, vl(2, 0))));
    rep(i,0,10) {
        dp[19][1][i][0] = 1;
        dp[19][1][i][1] = 1;
    }
    rep(i,0,num[19]+1) {
        dp[19][0][i][0] = 1;
        dp[19][0][i][1] = 1;
    }
    for(int pos = 18; pos >= 0; pos--){
        for(int smaller = 1; smaller >= 0; smaller--){
            rep(curr,0,10){
                if (!smaller && curr > num[pos]){
                    break;
                }
                rep(next,0,10){
                    if (curr != 0 && curr == next){
                        continue;
                    }
                    if (smaller){
                        if (curr != 0){
                            dp[pos][1][curr][1] += dp[pos+1][1][next][1];
                        }
                        else if (next != 0){
                            dp[pos][1][0][1] += dp[pos+1][1][next][1];
                        }
                        if (curr != 0) {
                            dp[pos][1][curr][0] += dp[pos+1][1][next][1];
                        }
                        else {
                            dp[pos][1][0][0] += dp[pos+1][1][next][0];
                        }
                    }
                    else {
                        if (curr == num[pos]) {
                            if (next > num[pos + 1]) {
                                break;
                            }
                            if (curr != 0) {
                                dp[pos][0][curr][1] += dp[pos + 1][0][next][1];
                            } else if (next != 0) {
                                dp[pos][0][0][1] += dp[pos + 1][0][next][1];
                            }
                            if (curr != 0) {
                                dp[pos][0][curr][0] += dp[pos + 1][0][next][1];
                            } else {
                                dp[pos][0][0][0] += dp[pos + 1][0][next][0];
                            }
                        }
                        else {
                            if (curr != 0) {
                                dp[pos][0][curr][1] += dp[pos + 1][1][next][1];
                            }
                            else if (next != 0) {
                                dp[pos][0][0][1] += dp[pos + 1][1][next][1];
                            }
                            if (curr != 0) {
                                dp[pos][0][curr][0] += dp[pos + 1][1][next][1];
                            } else {
                                dp[pos][0][0][0] += dp[pos + 1][1][next][0];
                            }
                        }
                    }
                }
            }
        }
    }
    return dp[0][0][0][0];
}

void solve() {
    ll a, b;
    cin >> a >> b;
    cout << count(b) - count(a-1) << endl;
}

int main() {
    ios::sync_with_stdio(0); // To increase input-output speed
    cin.tie(0);
    // printcase
    solve();
}