class Solution {
  public:
  
    void merge(vector<int>&arr,int l,int r,int mid){
        vector<int>temp;
        
        int left = l;
        int right = mid+1;
        while(left<=mid && right <= r){
            if(arr[left] < arr[right]){
                temp.push_back(arr[left]);
                left++;
            }
            else{
                temp.push_back(arr[right]);
                right++;
            }
        }
        while(left<=mid){
            temp.push_back(arr[left]);
            left++;
        }
        
        while(right<=r){
            temp.push_back(arr[right]);
            right++;
        }
        
        for(int i = l;i<=r;i++){
            arr[i] = temp[i-l];
        }
    }
    
    void mS(vector<int>&arr,int l,int r){
        if(l>=r)return;
        
        int mid = (l+r)/2;
        
        mS(arr,l,mid);
        mS(arr,mid+1,r);
        merge(arr,l,r,mid);
    }
    
    void mergeSort(vector<int>& arr, int l, int r) {
        // code here
        mS(arr,l,r);
    }
};