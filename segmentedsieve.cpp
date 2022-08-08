
/* Segmented sieve is used for finding primes numbers between range of m and  n ; 


steps ::
 1.  make normal  sieve of eranthiosis of size root n  and store primes in vector v; 
 2.  will divide the numbers  within range range m to n by  primes which are (stored in vec v)
     and mark them false  if the numbers are divisible 
*/
#include <bits/stdc++.h> 
using namespace std;
const int N=  100000 ; 
std::vector<int>Primes;

void sieve(){
bool arr[100000]  ; 
arr[0] = arr[1] = 0 ; 
for(int i=2 ; i*i<=N ; i++){
   arr[i] = 1 ; 
}
   for (int i = 2 ; i<=N ; i++){
      if(arr[i]==1){
         Primes.push_back(i) ;
         for(int j= i*i ; j<=N; j+=i){
            arr[j]= 0 ; 
         }
      }
   }
}

int main(){ 
  

   sieve() ; 
  // lets take input 

  int t ; 
  cin >> t ; 
  
  while(t--){
 int m , n ;
   cin >> m >> n ; 

   bool segment[n-m+1] ;
   for(int i = 0 ; i< (n-m+1) ; i++){
      segment[i] = 1 ; 
   }

   // iterating over primes vector  :

   for(auto x : Primes){
    /*in sieve function we are allocating 0 to those numbers which are multiple of prime
     and storing that prime in prime vector , so while interating vectore 
     we should only consider those elements from vectore whose square is less than n; */
      if(x*x > n){
         break ; 
      }

     /* how to find multiple of p that is closed to a number m : say p =2; m = 99 ; 
the formula is =  (m/p)*p   (99/2)*2 = 98 
since no's are upto range of N= 10^9 , we can't make sieve of that range 
so we will create sieve of root N  ie. 10^5 ; 
its also give that n-m <= 10^5 ; */

      int start = (m/x)*x ;

      // if x falls in range of m and n  ; 
      if ( x >=m and x <= n){
         start = x*2 ;
      }

// marking all multiples of x in the range m to n as false ; 
      for (int i = start ; i<= n ; i+=x){
         segment[i-m]= 0 ; 
      }

// printing all primes numbers :
      for (int i =  m ; i<= n ; i++ ) {
         if (segment[i-m]==1 and i!= 1 ){
            cout << i << endl ; 
         }
      }
      cout << endl ; 

   }
   
  }

  
  return 0; 
}