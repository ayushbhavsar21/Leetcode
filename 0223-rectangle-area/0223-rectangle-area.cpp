class Solution {
public:
    int computeArea(int ax1, int ay1, int ax2, int ay2, int bx1, int by1, int bx2, int by2) {
        int iy1 = max(ay1,by1) , iy2 = min(ay2,by2);
        int ix1 = max(ax1,bx1) , ix2 = min(ax2,bx2);

        int x = 0;
        if(ix1 < ix2 && iy1<iy2){
            x = (ix2 - ix1) * (iy2- iy1);
        }
        int a = (ax2 - ax1) * (ay2 - ay1);
        int b = (bx2 - bx1) * (by2 - by1);

        return a + b - x;
    }
};