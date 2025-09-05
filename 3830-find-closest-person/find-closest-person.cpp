class Solution {
public:
    int findClosest(int x, int y, int z) {
        int zx=abs(x-z);
        int yz=abs(y-z);

        if(zx==yz)return 0;
        else if(zx<yz)return 1;
        else return 2;
        
    }
};