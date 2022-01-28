#include<iostream>
#include<vector>

using namespace std;

void insert(vector<int> &v, int temp){
    if(v.size() == 0  || v[v.size() -1] <= temp){
        v.push_back(temp);
        return;
    }

    // if above if cond does not hits then we have to insert in between the sorted array.
    int temp1 = v[v.size()-1];
    v.pop_back();

    // now we have to inset in n-1 sorted array.
    insert(v, temp);

    v.push_back(temp1); // as temp1 is the largest 
    
    return;
}

void sortRecur(vector<int> &v){

    // bc
    if(v.size() == 1){
        // one ele is always sorted, increasing, decreasing...
        return;
    }
   

    // sore the last ele then in the sorted n-1 array try to put it at correst place.
    // hypo
    int temp = v[v.size()-1];
    v.pop_back();

    sortRecur(v); // n-1 will be sort now.

    // induction 
    // now we have to insert temp at correct place.
    insert(v, temp);

return;
}
int main(){
    // sort an array using recursion.

    vector<int> v = {0,-1,5,1,2};
    sortRecur(v);

    // print().
    for(int i = 0; i<v.size(); i++){
        cout<<v[i]<<" ";
    }

}