#include<bits/stdc++.h>
using namespace std;

#define fastIO ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);cout.precision(numeric_limits<double>::max_digits10);
#define ll long long
#define ld long double
#define pb push_back
#define all(x) (x).begin(),(x).end()
#define rall(x) (x).rbegin(),(x).rend()
#define mii map<ll, ll>
#define pii pair<ll, ll>
#define vi vector<ll>
#define vvi vector<vi>
#define ff first
#define take(v,n) for(ll i=0;i<n;i++) cin>>v[i];
#define ss second
#define endl "\n"
#define f(i,x,y) for(ll i=x; i<y; i++)
#define setbitsll(n)  __builtin_popcountll(n)
#define setbits(n)  __builtin_popcount(n)

#define yn(f) f?cout<<"YES"<<endl:cout<<"NO"<<endl
#define dbg(x) cout<<#x<<"=" << x << "\n"
const ll M=1000000007;

ll lcm(ll a, ll b){ll g=__gcd(a, b); return a/g*b;}

ll fact(ll n){n%=M; if(n<=1) return 1; return n*fact(n-1)%M;}

ll powm(ll x,ll n){
    x%=M;
    if(n==0)return 1; if(n==1)return x;
    ll p= powm(x*x,n/2);
    if(n%2) return p*x%M; return p;
}

ll mod_div(ll p, ll q){ return p*powm(q,M-2)%M;}

ll bitsize(ll n){if(n==0) return 0; return 1+bitsize(n>>1);}

const double eps = 0.000001;

const ll N=1e6+2;
vi isPrime, primes;
void sieve(){
    isPrime.assign(N+1,1);
    isPrime[0]=0; isPrime[1]=0;
    for(ll i=2; i*i<=N; i++) if(isPrime[i]) for(ll j=i*i; j<=N; j+=i) isPrime[j]=0;
    f(i,2,N+1) if(isPrime[i]) primes.pb(i);
}
/*-------------------------------------------------------------------------------------------------------------------------------------*/
class Teacher{
private: 
    double salary; 
    string misPass;  //data hinding
public:
   
// <-----------------properties-------------->
    string name;
    string adm_no;
    string dept;


// <-----------------non parameterized constructor-------------->
    Teacher(){  //No return type;
        cout<<"Hi, I am a constructor, made by a programmer(not by compailer).\n";
        // Also We use constructor to pre intialize (And always use contructor in public:)
        dept = "Mech";
    }


/*
//    <--------------parameterized constructor--------------->
    Teacher(string n, string a,string d, double s){  
        cout<<"parameterized constructor\n";
        name = n;
        adm_no = a;
        salary = s; 
        dept = d;
    }
*/

//         <-----------this pointer------------->
    Teacher(string name, string adm_no, string dept, double salary){  
        this->name = name;
        this->adm_no = adm_no;
        this->salary = salary; 
        this->dept = dept;
    }


//    <--------------Custom Copy constructor--------------->
    Teacher(Teacher &original_Obj){  
         cout<<" <--------------custom copy constructor-------------->\n";
        this->name = original_Obj.name;
        this->adm_no = original_Obj.adm_no;
        this->salary = original_Obj.salary; 
        this->dept = original_Obj.dept;
    }


//   <-----------Methods or Member function------------->
    
    void changeDept(string newDept){
        dept = newDept;
    }
    //setter
    void setSalary(double s){
        salary = s;
    }
    //getter
    double getSalary(){
        return salary;
    }
    void getinfo(){
        cout<<"name : "<<name<<endl;
        cout<<"dept : "<<dept<<endl;
    }
};
void adarsh_parihar(){   	//use ll
/*   Teacher t1;   //constructor call
    t1.name = "Adarsh";
    t1.admission_number = "22JE0040";
    t1.dept = "Mech";
    cout<<t1.dept<<endl;

    t1.changeDept("Chemical");
    cout<<t1.dept<<endl;

    t1.setSalary(25000);
    double s = t1.getSalary();
    cout<<s<<endl;
*/
    Teacher t1("Ajit Kumar","19JE0040","Mech",20000000.00);
    // t1.getinfo();

// <--------------Copy constructor------------------->
    Teacher t2(t1);
    t2.getinfo();

    

}

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
//cout<<"Case #"<<i<<": ";
         adarsh_parihar();
    return 0;
}