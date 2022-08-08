#include <bits/stdc++.h> 
using namespace std;
/* advantage of  sieve created by bitset :
it store 8 time less space than normal integer sieve ,
which allows us to store more prime numbers in our sieve */ 
// we can create sieve only upto 10^7 


const int n = 10000000 ; 
 bitset<10000000> b ;  // creating an array of bits  using bitset function 
 vector<int > v ;  // to store the no which are primes 

 void BitSieve( ){    // crating a bit sieve  
 // making whole bitset prime first 
  b.set() ;  // .set() function set all bits as 1  

// special case :
 b[0] = b[1] = 0 ; 

 for (long long  i=2 ; i<= n ; i++){
  if(b[i]){
    v.push_back(i) ; // storing numbers which are prime  
    for(long long j = i*i ; j<=n ; j+=i ){
      b[j] = 0 ; 
    }

  }

 }

 }

int main() {

 BitSieve() ;
 for(int i =0 ; i<=10 ; i++){
  cout << v[i] << " : "  ; // printing first 10 prime numbers  
 } 
  return 0;
}