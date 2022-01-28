#include<iostream>
using namespace std;

void solve(int n){
    if(n == 1){
        cout<<1<<" ";
        return;
    }

    cout<<n<<" ";
    solve(n-1);

    return;

}

int main(){
    // print n to 1
    int n;
    cout<<"Enter n: ";
    cin>>n;

    solve(n);

    return 0;
}