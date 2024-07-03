class Solution {
public:
#define ll long long
    const ll Radix_1 = 26;
    const ll MOD_1 = 1000000007;
    const ll Radix_2 = 27;
    const ll MOD_2 = 1000000033;

    pair<int,int> hashpair(string s,ll m){
        ll hash1 = 0, hash2 = 0;
        ll factor1 = 1, factor2 = 1;
        
        for(ll i = m-1;i>=0;i--){
            hash1+= ((s[i]-'a')*factor1)%MOD_1;
            factor1 = (Radix_1*factor1) % MOD_1;
            hash2+= ((s[i]-'a')*factor2)%MOD_2;
            factor2 = (Radix_2*factor2) % MOD_2;
        }
        return {hash1 % MOD_1, hash2 % MOD_2};
    }
    int strStr(string haystack, string needle) {
        ll n = haystack.length(),m = needle.length();
        if(n<m) return -1;

        ll MAX_WEIGHT_1 = 1 , MAX_WEIGHT_2 = 1;
        for(ll int i = 0; i<m; i++){
             MAX_WEIGHT_1 =( MAX_WEIGHT_1 * Radix_1 )% MOD_1;
             MAX_WEIGHT_2 =( MAX_WEIGHT_2 * Radix_2 )% MOD_2;
        }

        pair<ll,ll> hashneedle = hashpair(needle,m);
        pair<ll,ll> hashHay = {0,0};

        for(int i = 0;i<=n-m;i++){
            if(i==0){
                hashHay = hashpair(haystack,m);
            }
            else{
                hashHay.first = ((hashHay.first * Radix_1)% MOD_1 
                -((haystack[i-1]-'a')*MAX_WEIGHT_1)% MOD_1 
                +(haystack[i-1+m]-'a')+MOD_1) % MOD_1;
                hashHay.second = ((hashHay.second * Radix_2)% MOD_2 
                -((haystack[i-1]-'a')*MAX_WEIGHT_2)% MOD_2 
                +(haystack[i-1+m]-'a')+MOD_2) % MOD_2;

            }
            if(hashHay.first==hashneedle.first && hashHay.second==hashneedle.second) return i;
        }
        return -1;
    }
};
