class Problem1175 {
public:
    int mod = 1e9 + 7;
    int numPrimeArrangements(int n) {
        int primes = 0;
        for (int i = 2; i <= n; i++){
            if (isprime(i)) primes++;
        }
        return factorial(primes) * factorial(n-primes) % mod;
    }
    bool isprime(int n){
        for (int i = n/2; i >= 2; i--){
            if (n % i == 0) return false;
        }
        return true;
    }
    long factorial(int n){
        long res = 1;
        for (int i = 2; i <= n; i++){ res *= i; res %= mod;}
        return res;
    }
};