#include <bits/stdc++.h>
using namespace std;

#define MOD 1000000007
typedef long long ll;
typedef long double ldb;
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

vvi multiply(vvi m, int e, int n){
    if (e == 1) return m;
    vvi res(n, vi(n, 0));
    vvi temp = multiply(m, e/2, n);
    rep(i, 0, n){
        rep(j, 0, n){
            rep(k, 0, n){
                res[i][j] = (res[i][j] + (int) (((ll) temp[i][k] * (ll) temp[k][j]) % MOD)) % MOD;
            }
        }
    }
    if (e % 2 == 0) return res;
    else{
        vvi temp2(n, vi(n, 0));
        rep(i, 0, n){
            rep(j, 0, n){
                rep(k, 0, n){
                    temp2[i][j] = (temp2[i][j] + (int) (((ll) res[i][k] * (ll) m[k][j]) % MOD)) % MOD;
                }
            }
        }
        return temp2;
    }
}

void solve(){
    int n, e;
    cin >> n;
    e = n - 1;
    vvi m(2, vi(2, 0));
    m[0][0] = 2, m[0][1] = 1, m[1][0] = 1, m[1][1] = 4;
    if (!e) cout << 2 << endl;
    else{
        vvi res = multiply(m, e, 2);
        int ans = (res[0][0] + res[0][1]) % MOD;
        ans = (ans + res[1][0]) % MOD;
        ans = (ans + res[1][1]) % MOD;
        cout << ans << endl;
    }
    
}
 
int main() 
{
    ios::sync_with_stdio(0); // To increase input-output speed
    cin.tie(0);
    tc
    solve();
}