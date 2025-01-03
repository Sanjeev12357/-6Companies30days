class Solution {
public:
    bool checkOverlap(int radius, int xCenter, int yCenter, int x1, int y1, int x2, int y2) {
        int nx=max(x1,min(x2,xCenter));
        int ny=max(y1,min(y2,yCenter));

        int dx=nx-xCenter;
        int dy=ny-yCenter;
        return pow(dx,2)+pow(dy,2) <= pow(radius,2);
    }
};