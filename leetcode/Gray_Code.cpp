/*
00,01,11,10, the digit after current can reverse directly.
*/

class Solution {
public:
    void Work(vector<int> *Ans,int num,int digit)
    {
        if (digit<0) {Ans->push_back(num);return;}
        Work(Ans,num,digit-2);
        int m=Ans->size();
        for (int i=m-1;i>=0;i--) Ans->push_back((*Ans)[i]+(1<<digit));
        for (int i=0;i<m;i++) Ans->push_back((*Ans)[i]+(1<<(digit+1))+(1<<digit));
        for (int i=m-1;i>=0;i--) Ans->push_back((*Ans)[i]+(1<<(digit+1)));
        
    }
    
    vector<int> grayCode(int n) {
        bool odd=false;int k=0;
        if (n&1) {odd=true;n--;k=n;}
        vector<int> Ans;Ans.clear();
        Work(&Ans,0,n-2);
        if (odd)
        {
            int m=Ans.size();
            for (int i=m-1;i>=0;i--)
            {
                Ans.push_back(Ans[i]+(1<<k));
            }
        }
        return Ans;
    }
};