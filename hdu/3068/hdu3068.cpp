#include<string.h>
#include<stdio.h>
char c[110001],ch[220002];
int rad[220002];

int min(int o,int p)
{
    if (o<p) {return o;}
    return p;
}

int main()
{
    while (scanf("%s",c)!=EOF)
    {
        int ans;
        if (strlen(c)==0) {break;}
        int len=strlen(c);
        for (int i=0;i<len;i++)
        {
            ch[i*2]='#';
            ch[i*2+1]=c[i];
        }
        ch[len*2]='#';
        ans=0;
        memset(rad,0,sizeof(rad));
        int i=0,j=0;
        len=len*2+1;
        while (i<len)
        {
            while ((i-j>=0)&&(i+j<len)&&(ch[i-j]==ch[i+j])) j++;
            rad[i]=j;
            if (rad[i]>ans) {ans=rad[i];}
            int k=1;
            while ((k<rad[i])&&(rad[i-k]!=rad[i]-k))
            {
                rad[i+k]=min(rad[i-k],rad[i]-k);
                if (rad[i+k]>ans) {ans=rad[i+k];}
                k++;
            }
            i+=k;
            j-=k;if (j<0) {j=0;}
        }
        ans--;
        printf("%d\n",ans);
        memset(c,0,sizeof(c));
        //gets(c);
    }
    return 0;
}
