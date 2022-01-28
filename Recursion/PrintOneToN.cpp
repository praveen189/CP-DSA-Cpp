#include<iostream>
using namespace std;

void solve(int n){
    // base case
    if(n == 1){
        cout<<1<<" ";
        return;
        
    }
    solve(n-1);
    cout<<n<<" ";
    // hypothesis 
return ;
}

int main(){

    // print 1 to n using recursion 
    int n;
    cout<<"Enter n: ";
    cin>>n;

    solve(n); // recursion fun cal.

    return 0;
}