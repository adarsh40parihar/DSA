#include<bits/stdc++.h>
using namespace std;

#define fastIO ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);cout.precision(numeric_limits<double>::max_digits10);
#define int long long
#define ld long double
#define pb push_back
#define all(x) (x).begin(),(x).end()
#define rall(x) (x).rbegin(),(x).rend()
#define mii map<int, int>
#define pii pair<int, int>
#define vi vector<int>
#define vvi vector<vi>
#define ff first
#define take(v,n) for(int i=0;i<n;i++) cin>>v[i];
#define ss second
#define endl "\n"
#define f(i,x,y) for(int i=x; i<y; i++)
#define setbitsll(n)  __builtin_popcountll(n)
#define setbits(n)  __builtin_popcount(n)

#define yn(f) f?cout<<"YES"<<endl:cout<<"NO"<<endl
#define dbg(x) cout<<#x<<"=" << x << "\n"
const int M=1000000007;

int lcm(int a, int b){int g=__gcd(a, b); return a/g*b;}

int fact(int n){n%=M; if(n<=1) return 1; return n*fact(n-1)%M;}

int powm(int x,int n){
    x%=M;
    if(n==0)return 1; if(n==1)return x;
    int p= powm(x*x,n/2);
    if(n%2) return p*x%M; return p;
}

int mod_div(int p, int q){ return p*powm(q,M-2)%M;}

int bitsize(int n){if(n==0) return 0; return 1+bitsize(n>>1);}

const double eps = 0.000001;

const int N=1e6+2;
vi isPrime, primes;
void sieve(){
    isPrime.assign(N+1,1);
    isPrime[0]=0; isPrime[1]=0;
    for(int i=2; i*i<=N; i++) if(isPrime[i]) for(int j=i*i; j<=N; j+=i) isPrime[j]=0;
    f(i,2,N+1) if(isPrime[i]) primes.pb(i);
}
/*-------------------------------------------------------------------------------------------------------------------------------------*/

// <---------------Operator Overloading---------->
class Complex{
public:
    int real,img;
    Complex()  
    {
        //For answer initialization there should me one default constructor.
    }
    Complex(int real,int img){
        this->real = real;
        this->img = img;
    }
    Complex operator +(Complex &C){
        Complex ans;
        ans.real = real +  C.real;  //we can use this or we can't.
        ans.img  = this->img + C.img;
        return ans;
    }

    void display(){
        cout<<real<<" + i"<<img<<endl;
    }

};
void adarsh_parihar(){   	//use int
    Complex c1(3,4);
    Complex c2(4,6);
    Complex c3 = c1 + c2;  // c1.fun(c2) you can imagine like this.
    c3.display();

}

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t=1;
    // cin>>t;
    f(i,1,t+1){
        //cout<<"Case #"<<i<<": ";
         adarsh_parihar();
    }
    return 0;
}