ll euclidGCD(ll a, ll b){
    if(b==0) return a;
    return euclidGCD(b, a%b);
}

/*
(a^b)%M
a is very large => take a%M
if M is very large => use modular multiplication
if b is very large => take b modular (M-1) (considering M is prime_)
*/

void calcPrimeFact(unordered_map<int,int> primeFact, int n){ // O(sqrt(n))
    for(ll i=2; i*i<=n; i++){
        while(n%i==0){
            n/=i;
            primeFact[i]++;
        }
    }
    if(n>1) primeFact[n]++;
}

void sieve(){
    for(int i=2;i<n;i++){
        if(isPrime[i]){

            lp[i]=hp[i]=i; //calc highest prime and lowerst prime

            for(int j=2*i; j<n; i+=i){
                isPrime[j]=0;

                hp[j]=i;
                if(lp[j]==0) lp[j]=i;

            }
        }
    }
}

void calcPrimeFact(unordered_map<int,int> primeFact, int n){ // O(log(n))
    while(n>1){
        int pf=hp[n];
        while(num%pf==0){
            n/=pf;
            primeFact[pf]++;
        }
    }
}