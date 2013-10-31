#include<string.h>
#include<stdio.h>
char s[200];
int a[200],b[1000];
int q[1000][2];

int main()
{
    gets(s);a[0]=strlen(s);
    for (int i=strlen(s)-1;i>=0;i--) a[strlen(s)-i]=s[i]-'0';
    b[0]=0;
    int m=0;
    if ((a[0]==1)&&(a[1]==2))
    {
        printf("1\n0 0\n");
        return 0;
    }
    while (a[0]>0)
    {
        b[++b[0]]=(a[1]&1);
        if (b[b[0]]==1) m++;
        for (int i=1;i<=a[0];i++) {int o=a[i];if ((i+1<=a[0])&&((a[i+1]&1)==1)) {a[i+1]--;o+=10;}a[i]=o/2;}
        while ((a[0]>0)&&(a[a[0]]==0)) {a[0]--;}
    }
    int ans=2;
    q[0][0]=0;q[0][1]=0;
    q[1][0]=0;q[1][1]=1;
    int k,u;u=b[0];bool ff=false;
    if ((b[0]&1)==1) {k=1;u--;ff=true;}
    else
    {
        int l=b[b[0]]*2+b[b[0]-1];
        if (l==1) {k=0;}
        if (l==2) {k=1;}
        if (l==3) {k=2;}
        u-=2;
    }
    for (int i=u;i>0;i-=2)
    {
        if (ff) {ff=false;} else {q[ans][0]=k;q[ans++][1]=k;k=ans;}
        q[ans][0]=k;q[ans++][1]=k;k=ans;
        int l=b[i]*2+b[i-1];
        if (l!=0)
        {
            q[ans][0]=k;
            if (l==1) {q[ans++][1]=0;}
            if (l==2) {q[ans++][1]=1;}
            if (l==3) {q[ans++][1]=2;}
            k=ans;
        }
    }
    printf("%d\n",ans);
    for (int i=0;i<ans;i++) printf("%d %d\n",q[i][0],q[i][1]);
    return 0;
}
