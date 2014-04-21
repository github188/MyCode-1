class Solution {
public:
    void sortColors(int A[], int n) {
        int b[3];b[0]=b[1]=b[2];
        for (int i=0;i<n;i++) b[A[i]]++;
        for (int i=0;i<b[0];i++) A[i]=0;
        for (int i=b[0];i<b[0]+b[1];i++) A[i]=1;
        for (int i=b[0]+b[1];i<n;i++) A[i]=2;
    }
};