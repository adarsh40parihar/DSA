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
/*--------------Inheritance-----------------------------------------------------------------------------------------------------------------------*/
/*
class Person{
public:
    string name;
    int age;
   
    Person(string name, int age){
        this->name = name;
        this->age = age;
    }

//    Person(){
//         cout<<"Parent constructor\n";
//  }

};

class student: public Person{   //public -> Mode of Inheritance
public:
    string rollno;
    // calling parametrized constructor of Person
    student(string name, int age,string rollno) : Person(name,age){
        cout<<"Child constructor\n";
        this->rollno = rollno;
    }
    void getinfo(){
        cout<<"name : "<<name<<endl;
        cout<<"age : "<<age<<endl;
        cout<<"rollno : "<<rollno<<endl;
    }
};
*/

// <--------------------Multi level Inheritance----------------->
/*
class Person{
public:
    string name;
    int age;

};

class student: public Person{   //public -> Mode of Inheritance
public:
    string rollno;
};

class Gradstudent: public student{   //public -> Mode of Inheritance
public:
    string researchArea;
    void getinfo(){
        cout<<"name : "<<name<<endl;
        cout<<"age : "<<age<<endl;
        cout<<"rollno : "<<rollno<<endl;
        cout<<"researchArea : "<<researchArea<<endl;
    }
};
*/

// <--------------------Multiple Inheritance----------------->
/*
class student{   //public -> Mode of Inheritance
public:
    string name;
    int age;
    string rollno;
};

class Teacher{
public:
    string subject;
    double salary;
};

class TA : public student, public Teacher{
public:
    string researchArea;
    void getinfo(){
        cout<<"name : "<<name<<endl;
        cout<<"age : "<<age<<endl;
        cout<<"rollno : "<<rollno<<endl;
        cout<<"researchArea : "<<researchArea<<endl;
    }
};
*/

// <--------------------Hierarchial Inheritance----------------->


void adarsh_parihar(){   	//use int
/*   student s1;
    s1.name = "adarsh";
    s1.rollno = "22JE0040";
    s1.age = 19;
    s1.getinfo();

    student s1("Adarsh",19,"22JE0040");
*/

// <--------------------Multi level Inheritance----------------->
/*   Gradstudent s1;
    s1.name = "Tony Stark";
    s1.researchArea = "ML";
    s1.age = 40;
    s1.rollno = "125887155";
    s1.getinfo();
*/

// <--------------------Multiple Inheritance----------------->
/*  TA s1;
    s1.name = "Tony Stark";
    s1.researchArea = "ML";
    s1.age = 40;
    s1.rollno = "125887155";
    s1.getinfo();
*/    

// <--------------------Hierarchial Inheritance----------------->

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