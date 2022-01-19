#include<iostream>
#include<vector>

using namespace std;

void findAns(vector<int> a,vector<int> b){

    int n1 = a.size();
    int n2 = b.size();

    vector<int> res;

    for(int i = 0; i<n1; i++){
        for(int j = 0; j<n2; j++){
            if(a[i] == b[j]){
                res.push_back(a[i]);
                break;
            }
        }
    }

    for(int i = 0; i<res.size(); i++){
        cout<<res[i]<<" ";
    }

}

int main(){

    vector<int> a = {1, 2, 3, 3, 4, 5, 6};
    vector<int> b = {3, 3, 5};

    findAns(a,b);
    return 0;
}