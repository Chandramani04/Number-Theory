#include <bits/stdc++.h> 
using namespace std;


// creating normal sieve of erantheosis 
vector<int>storeprimes ; 
void  Primesieve(int n) {
    bool arr[n] = {0} ;
    arr[2]= 1 ;  // marking 2 as prime 
    for(int i= 3 ; i<=n ; i+=2 ){
        arr[i] = 1 ; // marking all odd no primes 
    }

    storeprimes.push_back(2) ;
    for(int i=3  ;i<= n ; i++){
        if(arr[i]){
            storeprimes.push_back(i) ;
            for(int j = i*i ;j<=n ; j+=i){
                arr[j]=0 ;
            }
        }
    }
}


//  creating a function which return prime factores 
vector<int> factorisation(vector<int> &storeprimes , int n ){

    vector<int>storefactors ;
    storefactors.clear() ;   // creating an empty vector

    int i=0 ; 
    int p = storeprimes[0] ;

    while(p*p <=n){          // optimized approach of cheching upto root n 
        if(n%p==0){
            storefactors.push_back(p); // noraml primes factor.  code  
            while(n%p==0){        
                n = n/p ; 
            }
        }
        i++ ;
        p = storeprimes[i] ; 
    }
    if(n!=1){
        storefactors.push_back(n) ;    // when number is already prime
    }

    return storefactors ; 
}



int main() {
    int n ; 
    cin >> n; 
    Primesieve(n) ;    // calling seive of eranthiosis function 
    factorisation(storeprimes, n) ;  // calling vector function which return primes 
  vector<int> v =   factorisation(storeprimes, n) ;  
    for(auto x : v){
        cout << x << " " ;    // printing all vectors 
    }
    

    return 0;
}