// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Problem278 {
public:
    int firstBadVersion(int n) {
        int low = 1, high = n, bad = -1;
        while (low <= high){
            int mid = low + (high-low)/2;
            isBadVersion(mid) ? bad = mid, high = mid-1 : low = mid+1;
        }
        return bad;
    }
    bool isBadVersion(int n){ return true; }
};