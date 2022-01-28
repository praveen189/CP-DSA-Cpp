#include<iostream>
#include<vector>
#include<stack>
#include<bits/stdc++.h>

using namespace std;
vector<int> NSRFun(vector<int> a, int n){
    // in right case we have to reverse the actual vector.
    vector<int> ans;
    stack<pair<int, int>> s;
    int psedoIndex = n; // default value if smaller to right is not found.

    // sotre the index of nearest smaller to right 

    for (int  i = n-1; i >=0; i--)
    {
        if(s.size() == 0){
            // stack is empty.
            ans.push_back(psedoIndex);
        }
        else if(s.size() > 0 && s.top().first < a[i]){
            ans.push_back(s.top().second);
        }
        else if(s.size() > 0 && s.top().first >= a[i]){
            // we have to pop the stack 
            while (s.size() > 0 && s.top().first >= a[i])
            {
                s.pop();
            }
            
            if(s.size() == 0){
                ans.push_back(psedoIndex);
            }
            else if(s.top().first < a[i]){
                ans.push_back(s.top().second);
            }
            
        }
        s.push({a[i], i});
    }
    
    reverse(ans.begin(), ans.end());

    return ans;
}


vector<int> NSLFun(vector<int> a, int n){
    stack<pair<int,int>> s;
    vector<int> ans;

    for(int i = 0; i<n; i++){
        if(s.size() == 0){
            // it means stack is empty.
            ans.push_back(-1);
        }
        else if(s.size() >0 && s.top().first < a[i]){
            ans.push_back(s.top().second);
        }

        else if(s.size() > 0 && s.top().first >= a[i]){
            // we have to pop the large ele.
            // till we get stack as empty means -1;
            // or we get ele smaller to it
            while (s.size() >0 && s.top().first >= a[i])
            {
                s.pop();
            }
            // two case for breaking the loop
            if(s.size() == 0){
                ans.push_back(-1);
            }
            else if(s.top().first < a[i]){
                ans.push_back(s.top().second);
            }
        }
        s.push({a[i],i});
    }
    return ans;

}

int main(){

    // vector<int> v = {4,5,2,10,8};
    vector<int> v = {1,5,4,3};

    
    int n = v.size();

    vector<int> nsr = NSRFun(v, n);
    for(int i = 0; i<nsr.size(); i++){
        cout<<nsr[i]<<" ";
    }
    cout<<endl;

    // nsr .. done 
    // nsl  .. done
    // width .. done
    // area.

    vector<int> nsl = NSLFun(v, n);
    for(int i = 0; i<nsl.size(); i++){
        cout<<nsl[i]<<" ";
    }
    cout<<endl;

    vector<int> width;
    for(int i = 0; i<nsl.size(); i++){
        width.push_back((nsr[i] - nsl[i] -2)*v[i]);
    }

    cout<<endl;
    for(int i = 0; i<nsl.size(); i++){
        cout<<width[i]<<" ";
    }
    cout<<endl;

    cout<<*max_element(width.begin(), width.end());
    

    
    

    return 0;
}
