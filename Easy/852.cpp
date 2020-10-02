int peakIndexInMountainArray(vector<int>& arr) {
    int l = 0, h = arr.size() - 1;
    
    int mid;
    while (l < h) { 
        mid = (l+h)/2;
        if (arr[mid] > arr[mid+1] && arr[mid] > arr[mid-1]) return mid;
        
        if (arr[mid+1] > arr[mid]) {
            l = mid + 1;
        } else {
            h = mid;
        }
    }
    return l;
}
