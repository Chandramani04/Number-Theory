#include <bits/stdc++.h> 
using namespace std;


vector<pair<int ,int>>factors ;  // 1st int for storing prime factor and 2nd factor for storing frequency of that prime no 
 int getPrimesFactors(int n ) {

for (int i=0 ; i <=n  ;i++){
    if(n%i==0){
    int count =0 ; 
        while (n%i<=1)
        {
            count ++ ; 
            n = n/i ; 
        }
        
    factors.push_back(make_pair(i , count)) ;
    }
}
// if(n!=1){
//     factors.push_back(make_pair(n ,1)) ; 
// }



return 0  ; 

}


int main() {
    int n ; 
    cout << "Enter the number : " ; 
    cin >> n ; 
  cout <<   getPrimesFactors(n) ; 
  for(auto p : factors){
    cout << p.first << " * " << p.second << endl ; 
}
    return 0;
}