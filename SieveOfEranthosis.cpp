
/* ----------------------------------------------------------------------------------------*/
// find primes numbers upto given number n 

 #include <bits/stdc++.h> 
using namespace std;

// we can create sieve only upto 10^7 
int findprimes(int n){

bool sieve[n+1] ; // making all number prime 
for (int i=0 ; i<n ; i++){
  sieve[i] = true ; 
}
// making 0 and 1 not prime
sieve[0] = false ;  
sieve[1]= false ; 
for (int i = 2; i*i <=n; i++) // loop from 2  to root n 
{  
  for (int j=i*i; j<=n; j+=i) // making multiples of i false , initiated from i^2 to reduce TC 
  {
    sieve[j] = false ;   
  }
}
int count =0 ; 
for(int i=0 ; i<=n ;i++){  // counting no of primes  
  if (sieve[i]){
    count ++ ;
  }
}
return count  ; 
}

int main() {
int n ; 
cin >> n ;
int nPrimes = findprimes(n) ;
cout << nPrimes << endl ;  
  return 0;
} 

// Primes between range of numbers
/*----------------------------------------------------------------------------*/
/* find no of primes between  range a and b  for given n queries 
now we can't call findprimes function for every query bcz that gives TLE 
so we have to precumpute the primes no's upto a range   and 
we will use prefix sum concept to find no of primes between the range a &b ; */
#include <bits/stdc++.h> 
using namespace std;



void findprime(long long p[]){

for(long long  i=3 ; i< 100000 ;i+=2){
  p[i]= 1 ; // making all odd no primes  bcz all even no are already not prime
}
 // special case 
 p[2]= 1 ;
 p[0] = p[1] = 0 ; 

 for (long long i = 3 ; i<=100000 ; i+=2){
  if(p[i]==1){
    for (long long j = i*i ;j <= 100000 ; j+=i){   // making multiples not prime
      p[j]= 0 ;  
    }
  }
 }
 
}

int main(){ 
     long long   p[100000] = {0} ;
  findprime(p) ; 
long long csum[100000] = {0} ;    // using prefix sum concept by maintaing an array
  for(long long  i = 1; i<=100000;i++){
    csum[i]= csum[i-1] + p[i] ; 
  }

  int query ;
  cout << "Enter No Of Queries : " << endl ;  
  cin >> query ; 
int a , b; 
  while (query--)
  cout << "Enter No's : " ; 
  cin >> a >> b ;
 cout <<   csum[b] - csum[a-1] << endl ;

  return 0; 
}