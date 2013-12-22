/*
Brute_force.
*/
class Solution {
public:
    void work(vector<vector<int> >* Ans,vector<int>* subset,vector<vector<int> >* Num,int lev)
    {
        if (lev>=Num->size())
        {
            Ans->push_back(*subset);
            return;
        }
        work(Ans,subset,Num,lev+1);
        for (int i=0;i<(*Num)[lev][1];i++)
        {
            subset->push_back((*Num)[lev][0]);
            work(Ans,subset,Num,lev+1);
        }
        for (int i=0;i<(*Num)[lev][1];i++) subset->pop_back();
    }

    vector<vector<int> > subsetsWithDup(vector<int> &S) {
        sort(S.begin(),S.end());
        vector<vector<int> > Ans;Ans.clear();
        vector<vector<int> > Num;Num.clear();
        vector<int> subset;subset.clear();
        if (S.size()==0)
        {
            Ans.push_back(subset);
            return Ans;
        }
        int n=S.size(),i=0,j=0;
        while (i<n)
        {
            Num.push_back(subset);
            Num[j].push_back(S[i]);
            Num[j].push_back(1);
            while ((i+1<n)&&(S[i]==S[i+1])) {Num[j][1]++;i++;}
            i++;j++;
        }
        work(&Ans,&subset,&Num,0);
        return Ans;
    }
};
