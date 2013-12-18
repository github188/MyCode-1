/*
Sort the vector. Maintain the leftest and rightest line which higher than current one.
*/
struct Point1
{
    int x,y;
    bool operator<(const Point1 b) const
    {
        return (y<b.y);
    }
};

class Solution {
public:
    int maxArea(vector<int> &height) {
        set<int> used;used.clear();
        vector<Point1> poi;poi.clear();
        int n=height.size();
        for (int i=0;i<n;i++)
        {
            Point1 tmp;tmp.x=i+1;tmp.y=height[i];
            poi.push_back(tmp);
        }
        sort(poi.begin(),poi.end());
        int l=1,r=n,ans=0;
        for (int i=0;i<n;i++)
        {
            ans=ans>(poi[i].y)*(poi[i].x-l)?ans:(poi[i].y)*(poi[i].x-l);
            ans=ans>(poi[i].y)*(r-poi[i].x)?ans:(poi[i].y)*(r-poi[i].x);
            used.insert(poi[i].x);
            while (used.find(l)!=used.end()) l++;
            while (used.find(r)!=used.end()) r--;
        }
        return ans;
    }
};