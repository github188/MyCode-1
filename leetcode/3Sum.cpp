/*
DFS. Attention to the special cases like 3 numbers are the same.
*/

class Solution {
public:
    void pushAns(vector<vector<int> > *Ans,int a,int b,int c)
    {
        vector<int> tmp;tmp.clear();
        tmp.push_back(a);
        tmp.push_back(b);
        tmp.push_back(c);
        Ans->push_back(tmp);
    }
    vector<vector<int> > threeSum(vector<int> &num) {
        sort(num.begin(),num.end());
        int n=num.size();
        int i,j,k;
        i=0;
        vector<vector<int> > Ans;
        Ans.clear();
        while (i<n-2)
        {
            int i1=i;
            while ((i<n)&&(num[i+1]==num[i])) i++;
            if (i-i1>=2)
            {
                if (num[i1]==0) pushAns(&Ans,0,0,0);
            }
            if (i-i1>=1) i--;
            j=i+1;k=n-1;
            while (j<n)
            {
                int j1=j;
                while ((j<n)&&(num[j+1]==num[j])) j++;
                if (j-j1>=1)
                {
                    if (num[i]+num[j1]+num[j1]==0) pushAns(&Ans,num[i],num[j1],num[j1]);
                }
                while ((k>j)&&(num[i]+num[j]+num[k-1]>=0)) k--;
                if (k<=j) break;
                if (num[i]+num[j]+num[k]==0) pushAns(&Ans,num[i],num[j],num[k]);
                while ((j<n-1)&&(num[j+1]==num[j])) j++;
                j++;
            }
            while ((i<n-2)&&(num[i+1]==num[i])) i++;
            i++;
        }
        return Ans;
    }
};