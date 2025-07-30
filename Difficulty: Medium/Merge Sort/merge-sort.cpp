class Solution {
public:
    void merge(vector<int>& arr, int l, int mid, int r) {
        vector<int> temp;
        int left = l;
        int right = mid + 1;

        while (left <= mid && right <= r) {
            if (arr[left] <= arr[right]) {
                temp.push_back(arr[left++]);
            } else {
                temp.push_back(arr[right++]);
            }
        }

        while (left <= mid) {
            temp.push_back(arr[left++]);
        }

        while (right <= r) {
            temp.push_back(arr[right++]);
        }

        for (int i = l; i <= r; ++i) {
            arr[i] = temp[i - l];
        }
    }

    void qs(vector<int>& arr, int l, int r) {
        if (l >= r) return;

        int mid = (l + r) / 2;
        qs(arr, l, mid);
        qs(arr, mid + 1, r);
        merge(arr, l, mid, r);
    }

    void mergeSort(vector<int>& arr, int l, int r) {
        qs(arr, l, r);
    }
};
