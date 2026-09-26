class Solution {
public:
    int countKthRoots(int l, int r, int k) {
        double low=pow(l,1.0/k);
        double high=pow(r,1.0/k);
        
        return floor(high + 1e-9) - ceil(low - 1e-9) + 1;
    }
};