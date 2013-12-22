/*
KMP.
*/
class Solution {
public:
    char *strStr(char *haystack, char *needle) {
        int m=strlen(haystack),n=strlen(needle);
        if (m<n) return NULL;
        if (n==0) return haystack;
        int *pre=(int*)malloc(n*sizeof(int));
        pre[0]=-1;
        int j=-1;
        for (int i=1;i<n;i++)
        {
            while ((j!=-1)&&(needle[j+1]!=needle[i])) j=pre[j];
            if (needle[j+1]==needle[i]) pre[i]=++j;
            else pre[i]=-1;
        }
        j=-1;
        for (int i=0;i<m;i++)
        {
            while ((j!=-1)&&(needle[j+1]!=haystack[i])) j=pre[j];
            if (needle[j+1]==haystack[i]) j++;
            if (j==n-1) return haystack+i+1-n;
        }
        return NULL;
    }
};
