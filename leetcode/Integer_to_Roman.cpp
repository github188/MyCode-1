class Solution {
public:
    string intToRoman(int num) {
        string Ans="";
        while (num>=1000) {Ans+="M";num-=1000;}
        if (num>=100)
        {
            int m=num/100;
            num%=100;
            if (m==9) {Ans+="CM";} else{
            if (m>=5) Ans+="D",m-=5;
            if (m==4) Ans+="CD"; else
            if (m==3) Ans+="CCC"; else
            if (m==2) Ans+="CC"; else
            if (m==1) Ans+="C"; }
        }
        if (num>=10)
        {
            int m=num/10;
            num%=10;
            if (m==9) {Ans+="XC";} else{
            if (m>=5) Ans+="L",m-=5;
            if (m==4) Ans+="XL"; else
            if (m==3) Ans+="XXX"; else
            if (m==2) Ans+="XX"; else
            if (m==1) Ans+="X"; }
        }
        if (num>=1)
        {
            int m=num;
            if (m==9) Ans+="IX"; else {
            if (m>=5) Ans+="V",m-=5;
            if (m==4) Ans+="IV"; else
            if (m==3) Ans+="III"; else
            if (m==2) Ans+="II"; else
            if (m==1) Ans+="I"; }
        }
        return Ans;
    }
};
