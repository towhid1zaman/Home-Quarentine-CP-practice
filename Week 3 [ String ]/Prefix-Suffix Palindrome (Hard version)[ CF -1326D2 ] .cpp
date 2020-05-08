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

int phi[maxn];
int  kmp_prefix_function(string s){
    int n = s.size();
    int index = 0;
    phi[0]=0;
    for(int i = 1; i<n; i++){
        while(index>0 and s[index] !=s[i]){
            index = phi[index-1];
        }
        if(s[i] == s[index]){
            index++;
        }
        phi[i] = index;
    }
    return phi[n-1];
}


int largest_pref_palin(string s){
    s = s+"?";
    string t = s;
    reverse(all(t));
    s+=t;
    return kmp_prefix_function(s);
}

int main(){
        _ios;

        int T; cin >> T;
        while(T--){
            string s; cin >> s;
            int n = sz(s);

            int l = 0;
            for(int i = 0,j= n-1;i<j; i++,j--){
                if(s[i]==s[j]){
                    l++;
                }
                else{
                    break;
                }
            }

            //remaining   s[l......n-l-1]
            string rem = s.substr(l,n-2*l);
            string ans = s.substr(0,l);

            //if remaining exist

            if(rem.size()){
                int l_pref = largest_pref_palin(rem);
                reverse(all(rem));
                int l_suf = largest_pref_palin(rem);

                if(l_pref>l_suf){
                    reverse(all(rem));
                    ans+=rem.substr(0,l_pref);
                }
                else{
                    //no need to reverse, cause its already reversed
                    ans+=rem.substr(0,l_suf);
                }
            }

            ans+= s.substr(n-l, l);
            cout<<ans<<endl;
        }


return 0;
}
 
