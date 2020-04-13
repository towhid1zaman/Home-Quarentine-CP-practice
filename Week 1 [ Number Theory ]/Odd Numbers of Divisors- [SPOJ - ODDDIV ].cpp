
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
const int maxn = 100100;

vll oddDiv[maxn];
void preCal(){
    for(ll i = 1; i<=maxn; i++){
        ll x = i*i; //x hoche purno borgo songkha
        ll y = i; // y hoche x er sqrt(x) , amra y ke prime factorization korbo
        ll nod = 1;
        for(ll j = 2; j*j<=y; j++){
            ll cnt = 0;
            while(y%j==0){
               y/=j;
               cnt++;
            }
            if(cnt) nod = nod*(2*cnt+1);
        }
        /*last e ekta  prime factor thake, jodi oitar power 1 hoi tahole oitake square 
        korle 2 hoi, then tar sathe 1 jog, means ,jodi 2 thake, tahole 2^1 = 1*2 +1 =3 */
        if(y>1) nod = nod*3;  
        oddDiv[nod].push_back(x);
    }
}

ll Query(ll left, ll right, ll n){
        return (upper_bound(oddDiv[n].begin(),oddDiv[n].end(),right))-(lower_bound(oddDiv[n].begin(),oddDiv[n].end(),left));
}

int main(){
        _ios;

        preCal();
        int T; cin >> T;
        while(T--){
            ll k, low, high; cin >> k >> low >> high;
            cout<<Query(low,high,k)<<endl;
        }

return 0;
}
/*
    ei problem bolche amake k,low,high deya thakbe
    jekhane,
    k = odd divisor songkha
    low and high = number er range

    amaderke ber korte hobe low theke high er moddhe koto gula number ache
    jader divisor songkha k er soman

    observation: jehetu odd divisor ber korte bolche, so jader divisor songkha odd amra
    sudhu tader e hisab korbo

    Approach:

        let N is a number ,
        ekhn N er divisor gula amra prime factor er maddhome likhte pari,

        N = p1^(e1) * p2^(e2) * p3^(e3).....pk^(ek)
        ekhane , p = prime factor, and e = power of prime factor

        ekhn  ekhan theke amra divisor songkha ber korbo kivabe!! seta hocche,

        D(N) = (e1+1)*(e2+1)*....(ek+1)

        mane hocche , prime factor er power er sathe 1 sum(+) kore segula
        multiplication(*) kore dilei amra number of divisor peye jabo.

        let N = 60
        divisors of 60 = 1,2,3,4,5,6,10,12,15,20,30,60 = total 12

        writen as prime factor, 60 = 2^2* 3^1* 5^1

        so as we know,
        D(N) = (e1+1)*(e2+1)*....(ek+1)
                = (2+1)*(1+1)*(1+1)
                =3*2*2
                =12

        ekhn dekhi eka number er divisor er songkha kokhn odd hobe !!
        seta hocche jokhn ekta number purno borgo hobe.

        1 -> 1
        4 -> 3
        9 -> 3
        eivabe joto gula purno borgo songkha ache tader divisor songkha hocche odd number

        No amader constraint deya ache 10^10 ta, jeta kokhono solveable na.

        tahole amra bujhte parchi, ekta number er sqrt(N) er prime divisor ber kore take square
        kore dilei amra amader odd divisor peye jabo
        so, 10^10 porjonto amader purno borgo songkha ache 10^5 ta . so amra khub sohoje 10^5
        porjonto precalculation kore nile khub sohoje eta solve kora jabe.

        jemon,
        144 = 2^4 * 3^2
               = (2^2 *3)^2 //amra ekhn power theke 2 common nite pari

        so, 144 = sqrt(144) = 12
        and, 12 =  (2^2*3)
        etake amra square korlei 144 peye jabo


        so amra root ke means 12 ke prime factorization korbo
        then, D(N) = (e1+1)*(e2+1)*....(ek+1) er maddhome divisor songkha ber korbo
*/
