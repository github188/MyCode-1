#include<stdio.h>

int a,b,x1,y1,x2,y2;

int abs(int o)
{
    if (o<0) o=-o;return o;
}

int main()
{
    scanf("%d%d%d%d%d%d",&a,&b,&x1,&y1,&x2,&y2);
    int u=(x1+y1)/(2*a),v=(x2+y2)/(2*a);
    int ans1=abs(u-v);long long r=x1+y1,s=x2+y2;
    if (r*s<0) {ans1++;}
    u=(x1-y1)/(2*b);v=(x2-y2)/(2*b);
    int ans2=abs(u-v);
    r=x1-y1;s=x2-y2;
    if (r*s<0) {ans2++;}
    int ans=ans1;if (ans2>ans) {ans=ans2;}
    printf("%d\n",ans);

    return 0;
}
