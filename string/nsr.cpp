#include<iostream>
#include<vector>
#include<stack>
#include<bits/stdc++.h>

using namespace std;
vector<int> NSRFun(vector<int> a, int n){
    // in right case we have to reverse the actual vector.
    vector<int> ans;
    stack<int> s;
    int def = n; // default value if smaller to right is not found.

    for (int  i = n-1; i >=0; i--)
    {
        if(s.size() == 0){
            // stack is empty.
            ans.push_back(def);
        }
        else if(s.size() > 0 && s.top() < a[i]){
            ans.push_back(s.top());
        }
        else if(s.size() > 0 && s.top() >= a[i]){
            // we have to pop the stack 
            while (s.size() > 0 && s.top() >= a[i])
            {
                s.pop();
            }
            
            if(s.size() == 0){
                ans.push_back(def);
            }
            else if(s.top() < a[i]){
                ans.push_back(s.top());
            }
            
        }
        s.push(a[i]);
    }
    reverse(ans.begin(), ans.end());

    return ans;
}

vector<int> NSLFun(vector<int> a, int n){
    stack<int> s;
    vector<int> ans;

    for(int i = 0; i<n; i++){
        if(s.size() == 0){
            // it means stack is empty.
            ans.push_back(-1);
        }
        else if(s.size() >0 && s.top() < a[i]){
            ans.push_back(s.top());
        }
        else if(s.size() > 0 && s.top() >= a[i]){
            // we have to pop the large ele.
            // till we get stack as empty means -1;
            // or we get ele smaller to it
            while (s.size() >0 && s.top() >= a[i])
            {
                s.pop();
            }
            // two case for breaking the loop
            if(s.size() == 0){
                ans.push_back(-1);
            }
            else if(s.top()<a[i]){
                ans.push_back(s.top());
            }
            
        }
        s.push(a[i]);
    }
    return ans;

}


int main(){

    // vector<int> v = {4,5,2,10,8};
    vector<int> v = {1,5,4,3};
    int n = v.size();

    vector<int> NSL = NSLFun(v, n);
    for(int i = 0; i<NSL.size(); i++){
        cout<<NSL[i]<<" ";
    }
    cout<<endl;


    vector<int> NSR = NSRFun(v, n);
    for(int i = 0; i<NSR.size(); i++){
        cout<<NSR[i]<<" ";
    }

    vector<int> width;
    for(int i = 0; i<NSL.size(); i++){
        int val = (NSR[i]-NSL[i]-2);
        width.push_back(val);
    }
    
    cout<<endl;
    for(int i = 0; i<width.size(); i++){
        cout<<width[i]<<" ";
    }
    cout<<endl;

    vector<int> area;
    for(int i = 0; i<NSL.size(); i++){
        area.push_back(width[i]*v[i]);
    }

   /* cout<<endl;
    for(int i = 0; i<area.size(); i++){
        cout<<area[i]<<" ";
    }
    cout<<endl;
*/

    return 0;
   
}