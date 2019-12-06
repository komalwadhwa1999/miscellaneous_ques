#include<stdio.h>
int min(int a,int b)
{
    if(a<b)
    return a;
    else
    return b;
}

int max(int a,int b)
{
    if(a>b)
    return a;
    else
    return b;
}

int maxwater(int a[],int n)
{
    int i,j;
    int res=0;
    for(i=0;i<n-1;i++)
    {
        int left=a[i];
        for(j=0;j<i;j++)
        left=max(left,a[j]);
        
        int right=a[i];
        for(j=i+1;j<n;j++)
        right=max(right,a[j]);
        
        res=res+min(left,right)-a[i];
    }
    return res;
}

int main()
{
    int a[]={3,0,0,2,0,4};
    int n=sizeof(a)/sizeof(a[0]);
    int x=maxwater(a,n);
    printf("rain water trapped = %d",x);
    return 0;
}
