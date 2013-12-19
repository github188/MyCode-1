/*
MUST write the answer in the original memory position for array A.
*/
class Solution {
public:
    int removeDuplicates(int A[], int n) {
        int m=0;
        if (n==0) return 0;
        for (int i=0;i<n;i++)
        {
            int j=i;
            while ((i+1<n)&&(A[i+1]==A[i])) i++;
            if (i!=j) m+=2; else m++;
        }
        int k=0;
        for (int i=0;i<n;i++)
        {
            int j=i;
            while ((i+1<n)&&(A[i+1]==A[i])) i++;
            if (i!=j) {A[k]=A[k+1]=A[j];k+=2;} else A[k++]=A[j];
        }
        //free(A+m);
        return m;
    }
};