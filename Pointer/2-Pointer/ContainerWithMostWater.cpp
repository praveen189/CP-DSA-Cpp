// Container With Most Water
int Solution::maxArea(vector<int> &v) {

    int n = v.size();

    int i = 0;
    int j = n-1;
    
    int maxArea = INT_MIN;

    while(i<=j){
        int height = min(v[i], v[j]);
        int width = (j-i);

        int currentArea = height * width;
        
        maxArea = max(maxArea, currentArea);

        if(v[i] < v[j]){
            i++;
        }else{
            j--;
        }
    }
    return maxArea;

}

