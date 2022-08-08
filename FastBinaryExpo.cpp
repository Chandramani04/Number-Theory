#include <bits/stdc++.h> 
using namespace std;
#define ll long long 

/*  find a^b code:
ll binaryexopnentiation(ll a, ll b ){

    ll result = 1 ; 
    while(b>0){
        if(b&1==1){
             result = result * a   ; 
        }
    a = a*a ; 
   b = b>>1 ; 

    }
    return result ;
 } 
 */


// find (a^b)%m code:
 ll binaryexopnentiation(ll a, ll b , ll m ){

    ll result = 1 ; 
    while(b>0){
        if(b&1==1){
             result = (result * a) % m  ; 
        }
    a = (a*a)%m ; 
   b = b>>1 ; 

    }
    return result ;
 }

int main() {
    cout << binaryexopnentiation(5,3,100) ; 
    return 0;
}