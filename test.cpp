#include <iostream>
#include <bits/stdc++.h>
#include <vector>
#include<string>
#include <set>

using namespace std;
const int MAX = 1000001;


///////////////////////////////// STL Part /////////////////////////////////////////

/* Vectors */
void initialize_vector(int size,int val){
    // vector of zeros
    vector<int> v(size);
    v[0] = 10;
    v.push_back(50); // create new array

    vector<int> v1 = {1,2,3,4};
    vector<int> v2(v1); // call the copy constructor

    vector<int> v3(size,val);

    v3.swap(v);
    
}

void vec_helping_functions(){
    vector<int> v;
    v.push_back(10);
    v.push_back(20);
    v.push_back(30);
    v.pop_back();
    int ten = v.front();
    int size = v.size();
    int capacity = v.capacity();
    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i] << endl;
    }
}

void vec_iterator(){
    vector<int> v = {1,2,3,4};
    vector<int>::iterator it = v.begin();

    cout << *it;
    it++;
    cout << *it;

    vector<int>::iterator it2 = v.end()-1;

    cout << *it;
    it--;
    cout << *it;


    // vector<int>::iterator it3 = v.begin();
    vector<int>::reverse_iterator it3 = v.rbegin();
    for(;it != v.end();it++){
        cout << *it << endl;
    }

    auto it4 = v.begin();
    for (; it4 != v.end(); it4++)
    {
        cout << *it << endl;
    }
}

void vec_insertion_deletion(int position,int val){
    vector<int> v = {50, 60, 70};
    v.insert(v.begin()+position-1,val); // from beginning
    v.insert(v.end()-position,val); // from last
    v.emplace(v.begin()+position-1,val); // from beginning
    v.emplace(v.end()-position,val); // from last
    v.erase(v.begin()+1); // delete second position
    v.erase(v.begin()+1, v.end());
    v.resize(5);
    v.shrink_to_fit();
}

bool greater_than_three(int val){
    return val > 3;
}

void vec_operation(){
    vector<int> v = {50, 60, 70};
    auto pair = minmax(v.begin(),v.end());
    cout << *pair.first << endl; // min
    cout << *pair.second << endl; // max

    auto it = min_element(v.begin(), v.end());
    sort(v.begin(), it); // sort(start_pointer, end_pointer)

    // vector must be sorted
    sort(v.begin(),v.end());
    auto it = find_if(v.begin(), v.end(), greater_than_three);
}

void printandtake_vector(){
    vector<int> v;
    copy(istream_iterator<int>(cin), istream_iterator<int>(),back_inserter(v));
    copy(v.begin(), v.end(), ostream_iterator<int>(cout, " "));
}

//// Complexity:
// Add --> Back --> O(1)
// Delete --> Back --> O(1)
// Add --> Any Where --> O(N)
// Delete --> Any Where --> O(N)
// Access --> [] - at() --> O(1)
// Search --> find() --> O(log N)

/* End of Vectors */

/* Sets */
void init_set(){
    // sorted and unique elements
    set<int> s {2, 1, 0, 5, 5};

    s.insert(6); // log(N)

    for (auto s:s){
        cout << s << endl;
    }
}

void set_string(){
    // insert in O(1)
    set<string> s;
    auto it = s.begin();

    s.emplace_hint(it, "ahmed");
    it = s.emplace_hint(it, "belal"); 
    it = s.emplace_hint(it, "Khaled"); 
    it = s.emplace_hint(it, "Ali"); 
    it = s.emplace_hint(it, "yazan");

    for (auto s: s){
        cout << s << endl;
    } 

    auto it = s.find("ahmed");
    s.erase(it); // erase an element
    s.erase(it, s.end());

    // erase specific range
    set<int> s1 {10, 20, 30, 40, 50, 60};
    auto itlow = s1.lower_bound(30);
    auto itup = s1.upper_bound(60);
    s1.erase(itlow, itup);
}

void set_compare(){
    set<int> s {10, 20, 30, 40, 50, 60};
    auto com = s.key_comp();
    auto it = s.begin();
    int c = 70;
    for(; com(*it,c); it++){
        cout << *it << endl;
    }
}

void check_existance_set(){
    set<int> s1 {10, 20, 30, 40, 50, 60};
    s1.count(20);
}

void utilies(){
    set<int> s {10, 20, 30, 40, 50, 60};
    auto it = s.equal_range(40);
    cout << *it.first << endl; // print 40
    cout << *it.second << endl;

}

/* End of Sets */

/* MAP */

/* END OF MAP */
///////////////////////////////// STL Part /////////////////////////////////////////

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
