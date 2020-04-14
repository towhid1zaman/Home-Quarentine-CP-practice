
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
const int maxn = 2000100;

int v(int n, int p){
    int cnt = 0;
    while(n%p==0){
        n/=p;
        cnt++;
    }
    return cnt;
}
int vfact(int n, int p){
    int cnt = 0;
    while(n){
        cnt+=n/p;
        n/=p;
    }
    return cnt;
}

int main(){
        //_ios;

        int T; cin >> T;
        int cs = 1;
        while(T--){
            int n,r,p,q;
            cin >> n >> r >> p >> q;
            int p2 = vfact(n,2)  - vfact(r,2) - vfact(n-r,2) + v(p,2)*q;
            int p5 = vfact(n,5)  - vfact(r,5) - vfact(n-r,5) + v(p,5)*q;
            cout<<"Case "<<cs++<<": "<<min(p2,p5)<<endl;
        }

return 0;
}

/*

    er agee amra [ LightOJ - 1035 ] theke Legendre's Formula dekhe aschi,
    oi formula tai ekhane kaj korbe

    ei problem e amaderke ber korte hobe,nCr * pq te koto gula trailing zero ache
    trailing zero means seshe koita zero ache.
    let N = 120 , so N er trailing zero 1 ta.


    so, prothome amra dekhi ekta number er trailing number kivabe ber korte hoi,

    ekta number er moddhe 10 er power joto trailing zero thik toto tai.

    let 120 = 10^1 * 12
    so 10 er power 1 means trailing zero 1

    ekhn ei 10 ke amra likhte pari, 10 = (2*5)

    kono number e 5 er power jodi thake 5 ta, and 2 er power thake 3 ta , tahole
    kintu amra 10 banaite pari min(5,2) er power diye, karon 2 er theke 5 beshi hoile
    othoba 5 er theke 2 beshi hoile kintu amar lav nai, karon amra sekhan theke extra 2 or 5
    diye 10 banaite parbo na.

    so , amra Legendre's Formula theke V(N!,2) and V(N!,5) er power ber kore oitar minimum
    nibo.

    ekhn nCr er hisab ta amra kivabe korbo ?

    ncr = n!/(r! * (n-r)!)

    ekhn n! er hisab ta ber kore okhan theke r! and (n-r)! er hisab ta bad(-) dilei amra amader ans
    peye jabo.


    ekhn p^q er hisab ta kivabe korbo!
    simply jotokkhon 2or5 diye vag jai, vag kore  ans ber korbo, then power sathe ans gun kore
    dibo,

    seshe ncr and p^q er result sum(+) kore dibo,thats set.


*/
