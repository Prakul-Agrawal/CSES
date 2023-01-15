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

char grid[8][8];
int Count = 0;
bool diag1[15] = {0}, diag2[15] = {0}, col[8] = {0};

void check(int r)
{
    if (r == 8)
    {
        Count++;
        return;
    }

    rep(c,0,8)
    {
        if (grid[r][c] == '.' && diag1[r+c] == 0 && diag2[7+r-c] == 0 && col[c] == 0)
        {
            diag1[r+c] = diag2[7+r-c] = col[c] = 1;
            check(r+1);
            diag1[r+c] = diag2[7+r-c] = col[c] = 0;
        }
    }
}

void solve(){
    
    rep(i,0,8) rep(j,0,8) cin >> grid[i][j];
    check(0);
    cout << Count << endl;
}

int main() 
{
    ios::sync_with_stdio(0); // To increase input-output speed
    cin.tie(0);
    // tc
    solve();
}