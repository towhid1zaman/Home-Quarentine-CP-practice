
// </> : towhid1zaman

#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
typedef vector<int> vi;typedef vector<ll> vll;
#define fill(a) memset(a, 0, sizeof (a))
#define all(v) (v).begin(),(v).end()
#define sp(k) cout<<setprecision(k)<<fixed;
#define rep(i,a) for(int i=0; i<a;i++)
#define rep1(i,a,b) for(int i=(a);i<=(b);++i)
#define irep(i,b,a) for(int i=(b);i>=(a);--i)
#define minv(v) *min_element(all(v))
#define maxv(v) *max_element(all(v))
#define unq(v) sort(all(v)),(v).erase(unique((v).begin(),(v).end()),(v).end())
#define _ios ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define sqr(a) ((a)*(a))
#define sz(a) int(a.size())
#define ff first
#define ss second
#define pb push_back

const double pi = acos(-1.0);
const int mod = 1000000007; // (int)1e9+7
const int maxn = 1e6+5;

int divi[maxn];
vi vv[12];
void sieve(){
    for(int i = 2; i<maxn; i++){
        if(divi[i]==0){
            for(int j = i; j<maxn; j+=i){
                divi[j]++;
            }
        }
    }

    for(int i = 1; i<maxn; i++){
        vv[divi[i]].pb(i);
    }
}
int main(){
        _ios;

        sieve();
        int T; cin >> T;
        while(T--){
            int l,r,n; cin >> l >> r >> n;
            cout<<upper_bound(vv[n].begin(),vv[n].end(),r) - lower_bound(vv[n].begin(),vv[n].end(),l)<<endl;
        }

return 0;
}

/*
    ei problem e bolche , a theke b er moddhe jader exactly n ta distict prime factor
    ache tader songkha ber korte hobe.

    approach:
    amra prothome sob gula number er factor ber kore , oi gula vector e rekhe
    binary search kore amra ans ber korte parbo.

*/

