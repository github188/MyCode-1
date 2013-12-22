/*
Be careful for the special case, and int divide int.
*/
/**
 * Definition for a point.
 * struct Point {
 *     int x;
 *     int y;
 *     Point() : x(0), y(0) {}
 *     Point(int a, int b) : x(a), y(b) {}
 * };
 */
class Solution {
public:
    int maxPoints(vector<Point> &points) {
        int n=points.size();
        if (n<3) return n;
        int ans=2;
        for (int i=0;i<n-1;i++)
        {
            int num=1;
            vector<double> pointK;pointK.clear();
            for (int j=i+1;j<n;j++)
            {
                if (points[j].x==points[i].x)
                {
                    if (points[j].y==points[i].y) num++; else pointK.push_back(1e8);
                } else pointK.push_back((double)(points[j].y-points[i].y)/(double)(points[j].x-points[i].x));
            }
            sort(pointK.begin(),pointK.end());
            int m=pointK.size();
            ans=ans>num?ans:num;
            for (int i=0;i<m;i++)
            {
                int tmp=1;
                while ((i+1<m)&&(pointK[i+1]-pointK[i]<1e-5)) tmp++,i++;
                ans=ans>num+tmp?ans:num+tmp;
            }
        }
        return ans;
    }
};
