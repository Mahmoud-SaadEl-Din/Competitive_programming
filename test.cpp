#include <iostream>
#include <bits/stdc++.h>
#include <vector>
#include<string>

using namespace std;
const int MAX = 1000001;


bool is_prime(int n){
    if (n < 2) return false;
    for (int i = 2; i*i < n; i++)
    {
        /* code */
        if (n%i == 0) return false;
    }
    return true;
}

vector<int> factors(int n){
    vector<int> f;
    for (int x = 2; x*x <= n; x++)
    {
        /* code */
        while (n%x == 0)
        {
            /* code */
            f.push_back(x);
            n/=x;
        }
    }
    if (n > 1) f.push_back(n);
    return f;
}

vector<int> sieve(int n){
    vector<int> sieve_vector(n,0);
    for (int x =2; x <=n; x++){
        if(sieve_vector[x]) continue;
        for (int u = 2*x; u <= n; u+=x)
        {
            /* code */
            sieve_vector[u] = x;
        }
    }
    return sieve_vector;
}

vector<short> t_prime_sieve(){
    vector<short> t_prime_vector(MAX,0);
    t_prime_vector[0] = 1;
    t_prime_vector[1] = 1;
    int limit = MAX;
    for (int x = 2; x * x <= limit; x++){
        if(t_prime_vector[x]) continue;
        for (int u = 2*x; u <= limit; u += x)
        {
            /* code */
            t_prime_vector[u] = x;
        }
        
    }
    return t_prime_vector;
}

bool is_t_prime(long u){
    vector<short> t_prime_vector = t_prime_sieve();
    long long b = floor(sqrt(u));
    if(t_prime_vector[b] == 0 && (long long)b*b == u) return true;
    else return false;
}


int gcd(int a, int b){
    if (b == 0) return a;
    return gcd(b, a%b);
}

// x^n mod m
int modpow(int x, int n, int m){
    if (n == 0) return 1%m;
    long long u = modpow(x, n/2, m);
    u = (u*u)%m;
    if (n%2 ==1) u = (u*x)%m;
    return u;
}



int main(){
    int x = 10;
    cout << is_prime(10) << endl;
}
