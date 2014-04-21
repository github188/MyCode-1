class Solution {
public:
    int canCompleteCircuit(vector<int> &gas, vector<int> &cost) {
        vector<int> a;a.clear();
        int n=gas.size();
        for (int i=0;i<n;i++) a.push_back(gas[i]-cost[i]);
        for (int i=0;i<n;i++) a.push_back(a[i]);
        vector<int> b;b.clear();b.push_back(a[0]);
        for (int i=1;i<n+n;i++) b.push_back(a[i]+b[i-1]);
        vector<pair<int,int> > c;c.clear();
        for (int i=0;i<n+n;i++) c.push_back(make_pair<int,int>(0,1e9));
        int t=1;c[0].first=0;c[0].second=b[0];
        for (int i=1;i<n;i++)
        {
            while ((t>0)&&(c[t-1].second>b[i])) t--;
            c[t].first=i;
            c[t++].second=b[i];
        }
        if (c[0].second>=0) return 0;
        int h=0;
        for (int i=1;i<n;i++)
        {
            if (c[h].first<i) h++;
            while ((t>h)&&(c[t-1].second>b[n-1+i])) t--;
            c[t].first=n+i-1;
            c[t].second=b[n-1+i];
            t++;
            if (c[h].second>=b[i-1]) return i;
        }
        return -1;
    }
};