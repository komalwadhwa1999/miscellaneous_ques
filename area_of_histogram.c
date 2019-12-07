#include<stdio.h>

int largestRectangleArea(int a[],int n)
{
    int curr=0;
    int area=0;
    int stack[n];
    int top=-1;
    int tp;
    int i=0;
    
    while(i<n)
    {
        if(top==-1 || a[stack[top]]<=a[i])
        stack[++top]=i++;     //push()
        
        else
        {
            tp=stack[top--];        //pop()
            curr=a[tp]*(top==-1?i:i-stack[top]-1);
            
            if(curr>area)
            area=curr;
        }
        
    }
    while(top==-1)
    {
        tp=stack[top--];
        curr=a[tp]*(top==-1?i:i-stack[top]-1);
        
        if(curr<area)
        area=curr;
    }
    return area;
}

int main() 
{ 
    int hist[] = {6, 2, 5, 4, 5, 1, 6}; 
    int n = sizeof(hist)/sizeof(hist[0]); 
    int x = largestRectangleArea(hist, n); 
    printf("area of histogram = %d",x);
    return 0; 
} 
