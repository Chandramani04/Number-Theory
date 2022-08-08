/* extended euclid algorithm is used for finding value of x,y in euations like
 A.x + B.y = gcd(A,B)     ,  refer notes 
 18.x+ 30.y = gcd(18,30)  find x,y ?
*/

#include <bits/stdc++.h> 
using namespace std;

int  gcd(int a, int b){
    // code to find gcd
    // base case
    if(b==0){
        return a;
    }
    //recursive case 
    return gcd(b,a%b) ;     // gcd(a,b)= gcd(b,a&b)    <--- Eculide Algorithm 
}
// code to find lcm 
int lcm(int a,int b){
    return a*b/gcd(a,b) ;     // hcf*lcm = a*b
}

// creating global variables
int x,y, GCD ; 

void  ExtendedEuclidMethod(int a , int b){

    // base case 
    if(b==0){   
        x = 1 ;   // all 3 resutlts are already derived in notes 
        y = 0 ; 
        GCD = a ; 
        return ;
    }

    // recursive case 
     ExtendedEuclidMethod(b,a%b) ;    
    /*  remember following result
    current x = previous y ;    (x = y1)
    current y = previous x - [current a/ current b]* previous y ;  (y = x1 - [a/b]*y1) 
`   */
   int currentX = y ;
   int currentY = x-(a/b)*y ; 

   // since we already calculated current x  and y  
   x = currentX ; 
   y = currentY ;

    // job done 

}

int main() {
cout << gcd(18,30) << endl ;
cout << lcm(18,30) << endl ; 
    
  ExtendedEuclidMethod(18,30) ;
  cout << x  << " , " << y ; // prints 2 and -1  
/* lets check x=2 , y=-1 satisfy the eqn 18x+ 30y = gcd(18,30) 
    18 *2 + 30 * (-1) = gcd(18,30) ;
    36- 30 = 6 ; 
    LHS = RHS  ; 
*/

    return 0;
}