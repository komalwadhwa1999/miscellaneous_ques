#include <stdio.h>
int solve(int A[3][5], int n11, int n12) {
    int i, j, k = 2, time = 0, changes = 0, fresh = 0;
    do
    {
        changes = 0;
        for(i = 0, fresh = 0; i < n11; i++)
        {
            for(j = 0; j < n12; j++)
            {
                if(A[i][j] == k)
                {    
                    if(j+1 < n12 && A[i][j+1] == 1)
                    {
                        A[i][j+1] = k+1;
                        changes++;
                    }
                    if(j-1 >= 0 && A[i][j-1] == 1)
                    {
                        A[i][j-1] = k+1;
                        changes++;
                    }
                    if(i+1 < n11 && A[i+1][j] == 1)
                    {
                        A[i+1][j] = k+1;
                        changes++;
                    }
                    if(i-1 >= 0 && A[i-1][j] == 1)
                    {
                        A[i-1][j] = k+1;
                        changes++;
                    }
                }
                else if(A[i][j] == 1)
                {
                    fresh++;
                }
            }
        }
        if(changes != 0)
        {
            time++;
        }
        k++;
    } while(changes != 0);
    
    if(changes == 0 && fresh != 0)
    {
        return -1;
    }
    else
    {
        return time;
    }
}


int main()
{
    int r,c;
    scanf("%d %d",&r,&c);
    int a[r][c];
    int i,j;
    for(i=0;i<r;i++)
    {
        for(j=0;j<c;j++)
        {
            scanf("%d",&a[i][j]);
        }
    }
   // int a[3][5]={{2,1,0,2,1},{1,0,1,2,1},{1,0,0,2,1}};
    int x=solve(a,r,c);
    if(x==-1)
    printf("all oranges cannot be rotten");
    else
    printf("time required=%d",x);

    return 0;
}
