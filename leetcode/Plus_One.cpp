/*
From high to low digits.
*/
class Solution {
public:
    void reverse(vector<int> *digits)
    {
        int n=digits->size();
        for (int i=0;i<n/2;i++)
        {
            int tmp=(*digits)[i];
            (*digits)[i]=(*digits)[n-1-i];
            (*digits)[n-1-i]=tmp;
        }
    }
    vector<int> plusOne(vector<int> &digits) {
        reverse(&digits);
        int n=digits.size();
        int symbol=1;
        if (digits[n-1]<0) {symbol=-1;digits[n-1]*=-1;}
        digits[0]+=symbol;
        for (int i=0;i<n;i++)
        {
            if (digits[i]>9)
            {
                digits[i]-=10;
                if (i+1>=n) digits.push_back(1);
                else digits[i+1]++;
            }
            if (digits[i]<0)
            {
                digits[i]+=10;
                digits[i+1]--;
            }
        }
        while ((digits[digits.size()-1]==0)&&(digits.size()>1)) digits.pop_back();
        digits[digits.size()-1]*=symbol;
        reverse(&digits);
        return digits;
    }
};