#include<stdio.h>
#include<map>
#include<string.h>
#include<iostream>
#include<stdlib.h>
#include<algorithm>
using namespace std;

struct str
{
       double x,y;
};

map<string,int> dict;
double a[2000];
int num,tt,k;
char s[50000];
int b[50000];
bool buf0;
str buf;

bool cmp1(str a,str b)   // and
{
     if (a.y*(1.0-b.x)<b.y*(1.0-a.x)) {return true;}
     return false;
}

bool cmp2(str a,str b)   // or
{
     if (a.y*b.x<b.y*a.x) {return true;}
     return false;
}

str work(int o,int p)
{
    str ans;ans.x=ans.y=0;
    str c[1001];
    int num=0;
    
    if (buf0)
    {
      c[num]=buf;
      buf0=false;
      num++;
    }
    while ((k<=b[0])&&(b[k]!=-2))
    {
          if (b[k]==-5)
          {
             int u=p;
             while ((k<=b[0])&&(b[k]==-5)) {u=(u^1);k++;}
             if (b[k]!=-1)
             {
                if (u==1)
                {
                  c[num].x=a[b[k]];
                  c[num].y=1;
                  num++;
                } else
                {
                  c[num].x=1-a[b[k]];
                  c[num].y=1;
                  num++;
                }
             } else
             {
                k++;   
                c[num]=work(0,u);
                num++;
             }
          } else
          if (b[k]==-1)
          {
             k++;
             c[num]=work(0,p);
             num++;
          } else
          if (b[k]==-3)
          {
             if (o!=1) {          
             buf0=true;
             num--;
             buf=c[num];
             c[num]=work(1,p);
             num++;}
          } else
          if (b[k]==-4)
          {
             if (o==1) {break;}
          } else
          {
             if (p==1)
             {
                c[num].x=a[b[k]];
                c[num].y=1;
                num++;
             } else
             {
                c[num].x=1-a[b[k]];
                c[num].y=1;
                num++;
             }
          }
          k++;
    }
    
    if (num==1) {return c[0];}
    if ((o^p)==0) 
    {
      sort(c,c+num,cmp1);
      ans.x=1;ans.y=0;
      double sum=0;
      for (int i=0;i<num;i++)
      {
          sum=sum+c[i].y;
          double u=sum*ans.x;
          if (i!=num-1) {u=u*(1-c[i].x);}
          ans.y+=u;
          ans.x=ans.x*c[i].x;
      }
    } else
    {
      sort(c,c+num,cmp2);
      ans.x=1;ans.y=0;
      double sum=0;
      for (int i=0;i<num;i++)
      {
          sum=sum+c[i].y;
          double u=sum*ans.x;
          if (i!=num-1) {u=u*c[i].x;}
          ans.y+=u;
          ans.x=ans.x*(1-c[i].x);
      }
      ans.x=1-ans.x;
    }
    return ans;
}

int main()
{
    scanf("%d",&tt);
          gets(s);
    while (tt>0)
    {
          tt--;gets(s);
          b[0]=0;
          dict.clear();
          num=0;
          int h,len;
          h=0;len=strlen(s);while ((h<len)&&(s[h]==' ')) {h++;}
          while (h<len)
          {
                string st="";
                while ((h<len)&&(s[h]!=' ')&&(s[h]!='(')&&(s[h]!=')'))
                {
                      st=st+s[h];
                      h++;
                }
                if (st=="")
                {
                   st+=s[h];
                } else {if ((s[h]==')')||(s[h]=='(')) {h--;} }
                
                if ((st.length()==1)&&(st[0]=='(')) {b[0]++;b[b[0]]=-1;} else
                if ((st.length()==1)&&(st[0]==')')) {b[0]++;b[b[0]]=-2;} else
                if ((st.length()==3)&&(st[0]=='a')&&(st[1]=='n')&&(st[2]=='d')) {b[0]++;b[b[0]]=-3;} else
                if ((st.length()==2)&&(st[0]=='o')&&(st[1]=='r')) {b[0]++;b[b[0]]=-4;} else
                if ((st.length()==3)&&(st[0]=='n')&&(st[1]=='o')&&(st[2]=='t')) {b[0]++;b[b[0]]=-5;}
                else
                {
                    dict.insert(pair<string,int>(st,num));
                    b[0]++;
                    b[b[0]]=num;
                    num++;
                }
                h++;
                while ((h<len)&&(s[h]==' ')) {h++;}
          }
          
          for (int i=0;i<num;i++)
          {
              string st;
              cin>>st;
              map<string,int>::iterator it=dict.find(st);
              //cin>>a[it->second];
              scanf("%lf",&a[it->second]);
          gets(s);
          }
          k=1;buf0=false;
          str tmp=work(0,1);
          printf("%.6f\n",tmp.y);
    }
    return 0;
}
