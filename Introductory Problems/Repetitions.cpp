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
// Iterate through the string and keep track of the last character that was
// encountered. If the current character is the same as the last character,
// increment the length of current substring. Else, reset the length to 1, 
// update the last character and update maximum length
// -------------------------------------------------------------------------- //

void solve(){
    string s; cin >> s;
    char prev = ' ';
    int length = 0, max_len = 0;
    for (auto i: s)
    {
        if (i == prev) length++;
        else
        {
            max_len = max(max_len,length);
            length = 1;
            prev = i;
        }
    }
    max_len = max(max_len,length);
    cout << max_len << endl;
}

int main() 
{
    ios::sync_with_stdio(0); // To increase input-output speed
    cin.tie(0);
    //tc
    solve();
}