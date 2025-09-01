class Solution {
  public:
    long long merge(vector<int> &arr, int l, int m, int r) {
        long long cnt = 0;
        int i = l, j = m + 1;
        vector<int> temp;

        while(i <= m && j <= r) {
            if(arr[i] <= arr[j]) {
                temp.push_back(arr[i++]);
            } else {
                temp.push_back(arr[j++]);
                cnt += (m - i + 1); // inversion count
            }
        }

        while(i <= m) temp.push_back(arr[i++]);
        while(j <= r) temp.push_back(arr[j++]);

        for(int k = l; k <= r; k++) arr[k] = temp[k - l];

        return cnt;
    }

    long long mergeSort(vector<int> &arr, int l, int r) {
        if(l >= r) return 0;
        int m = (l + r) / 2;
        long long cnt = 0;
        cnt += mergeSort(arr, l, m);
        cnt += mergeSort(arr, m + 1, r);
        cnt += merge(arr, l, m, r);
        return cnt;
    }

    long long inversionCount(vector<int> &arr) {
        return mergeSort(arr, 0, arr.size() - 1);
    }
};
