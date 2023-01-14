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

void create(string s, int (&freq)[26], int const &length)
{
    if (s.length() == length) 
    {
        cout << s << endl;
        return;
    }
    rep(i,0,26)
    {
        if (freq[i])
        {
            freq[i]--;
            create(s+char('a'+i), freq, length);
            freq[i]++;
        }
    }
} 

void solve(){

    // could use next_permutation()

    string s; cin >> s;
    int fact[9], freq[26] = {0};

    fact[0] = 1;
    rep(i,1,9) fact[i] = fact[i-1] * i;

    for(auto &x: s) freq[x - 'a']++;

    int k = fact[s.length()];
    rep(i,0,26) k /= fact[freq[i]];
    cout << k << endl;

    create("", freq, s.length());    
}

int main() 
{
    ios::sync_with_stdio(0); // To increase input-output speed
    cin.tie(0);
    // tc
    solve();
}