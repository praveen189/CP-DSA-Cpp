// Diffik/ 2-pointer
int Solution::diffPossible(vector<int> &a, int b) {
    int n = a.size();

    int i = 0;
    int j = 1;

    while(i<n && j<n){
        if((i != j ) &&(a[j] - a[i] == b)){
            return 1;
        }
        else if(a[j] - a[i] < b){
            j++;
        }
        else{
            i++;
        }
    }
    return 0; // if not found


}