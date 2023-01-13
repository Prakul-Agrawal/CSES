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
    int n; cin >> n;
    vi final(n,0),toggle(n);
    rep(i,0,n) toggle[i] = 1 << i;

    rep(i,0,1<<n)
    {
        for (auto i: final) cout << i;
        cout << endl;
        rep(j,0,n)
        {
            toggle[j]++;
            toggle[j] %= 1 << (j+1);
            if (toggle[j] == 0) final[j] = 1 - final[j];
        }

    }
}

int main() 
{
    ios::sync_with_stdio(0); // To increase input-output speed
    cin.tie(0);
    // tc
    solve();
}