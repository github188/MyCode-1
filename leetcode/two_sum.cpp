/*
Sorting and scanning.
*/
struct num
{
    int x,y;
    bool operator<(const num b) const
    {
        return x<b.x;
    }
};
class Solution {
public:
    vector<int> twoSum(vector<int> &numbers, int target) {
        int n=numbers.size();
        vector<int> ans;ans.clear();
        vector<num> numbers1;numbers1.clear();
        for (int i=0;i<n;i++)
        {
            num tmp;tmp.x=numbers[i];tmp.y=i+1;
            numbers1.push_back(tmp);
        }
        sort(numbers1.begin(),numbers1.end());
        int head=-1,tail=numbers1.size()-1;
        while (true)
        {
            head++;
            while (numbers1[head].x+numbers1[tail].x>target) tail--;
            if (numbers1[head].x+numbers1[tail].x==target)
            {
                ans.push_back(numbers1[head].y);
                ans.push_back(numbers1[tail].y);
                if (ans[0]>ans[1]) 
                {
                    int tmp=ans[0];ans[0]=ans[1];ans[1]=tmp;
                }
                return ans;
            }
        }
    }
};