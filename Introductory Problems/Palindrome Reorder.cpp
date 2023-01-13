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
    string s; cin >> s;
    vi freq(26,0);
    int len = s.length();
    vector<char> final(len);
    for (auto i: s)
    {
        freq[int(i) - int('A')]++;
    }
    int count = 0, pos = 0, flag = 0;
    rep(i,0,26) 
        if (freq[i] % 2) 
        {
            flag = i;
            count++;
            if (count > 1)
            {
                cout << "NO SOLUTION" << endl;
                return;
            }
        }

    rep(i,0,26)        
        rep(j,0,freq[i]/2)
        {
            final[pos] = char(i+'A');
            final[len - pos - 1] = char(i+'A');
            pos++;
        }
    if (len % 2) final[len/2] = char(flag+'A');
    for (auto i: final) cout << i;
    cout << endl;
}

int main() 
{
    ios::sync_with_stdio(0); // To increase input-output speed
    cin.tie(0);
    // tc
    solve();
}