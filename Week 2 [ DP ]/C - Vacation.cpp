
// </> : towhid1zaman

#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
typedef vector<int> vi;typedef vector<ll> vll;
#define fill(a,b) memset(a, b, sizeof (a))
#define all(v) (v).begin(),(v).end()
#define sp(k) cout<<setprecision(k)<<fixed;
#define rep(i,a) for(int i=0; i<a;i++)
#define rep1(i,a,b) for(int i=(a);i<=(b);++i)
#define irep(i,b,a) for(int i=(b);i>=(a);--i)
#define minv(v) *min_element(all(v))
#define maxv(v) *max_element(all(v))
#define unq(v) sort(all(v)),(v).erase(unique(all(v)),(v).end())
#define _ios ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define sqr(a) ((a)*(a))
#define sz(a) int(a.size())
#define ff first
#define ss second
#define pb push_back

const double pi = acos(-1.0);
const int mod = 1000000007; // (int)1e9+7
const int maxn = 2000100;

int main(){
        _ios;

        int n; cin >> n;
        vi dp(3);
        for(int day = 0 ; day < n; day++){
            vi abc(3);
            vi NewDp(3,0);
            for(int i = 0; i<3; i++){
                cin >> abc[i];
            }
            for(int i = 0; i<3; i++){
                for(int j = 0; j<3; j++){
                    if(i!=j){
                        NewDp[j] = max(NewDp[j], dp[i]+abc[j]);
                    }
                }
            }
            //cout<<maxv(NewDp)<<endl;
            dp  = NewDp;
        }

        cout<<maxv(dp)<<endl;
return 0;
}

/*





*/

