#include <stdio.h>
#include <stdlib.h>
void knapsack(int B,int n,int w[],int c[]);
int main()
{
 int B,n,i,j;
 printf("Enter value of n:");
 scanf("%d",&n);
 printf("Enter value of B:");
 scanf("%d",&B);
 int w[n],c[n];
 for(i=0;i<n;i++)
   {
     scanf("%d",&w[i]);
   }

 for(j=0;j<n;j++)
   {
     scanf("%d",&c[j]);
   }
 printf("INPUT DONE\n");
 knapsack(B,n,w,c);
 return 0;
}

void knapsack(int B,int n,int w[],int c[])
{
 int V[n+1][B+1],W[n+1][B+1],i,j,k;
 int COUNT[n+1][B+1][n];
 for(i=0;i<=n;i++)
 {
   for(j=0;j<=B;j++)
     {
       for(k=0;k<n;k++)
         {
           COUNT[i][j][k] = 0;
         }
     }
 }

 for(i=0;i<=n;i++)
    {
       V[i][0] = 0;//0th column = 0,i.e. when capacity is 0,ans is 0
       W[i][0] = 0;
    }
 for(j=0;j<=B;j++)
    {
       V[0][j] = 0;//0th row = 0,i.e. when no. of weights is 0,ans is 0
       W[0][j] = 0;
    }
 
 for(i=1;i<=n;i++)
   {
     for(j=1;j<=B;j++)
       {
          if(w[i-1] > j)//If the ith weight itself > knap cap,then ans excludes ith wt.
            {
               V[i][j] = V[i-1][j];
               W[i][j] = W[i-1][j];
               for(k=0;k<n;k++)
                   COUNT[i][j][k] = COUNT[i-1][j][k]; 
            }
          else
            {
              if(V[i-1][j] > (c[i-1] + V[i][j-w[i-1]]))
                {
                   V[i][j] = V[i-1][j];
                   W[i][j] = W[i-1][j];
                   for(k=0;k<n;k++)
                        COUNT[i][j][k] = COUNT[i-1][j][k];
                }
              else
                { 
                   V[i][j] = (c[i-1] + V[i][j-w[i-1]]);
                   W[i][j] = (w[i-1] + W[i][j-w[i-1]]);
                   COUNT[i][j][i-1]++;
                   for(k=0;k<n;k++)
                        COUNT[i][j][k] += COUNT[i][j - w[i-1]][k];
                    
                }
            }
       }
   }
 printf("Maximum Cost: %d\n",V[n][B]);
 printf("Weight: %d\n",W[n][B]);
 printf("Counts: "); 
 for(i=0;i<n;i++)
     printf("%d ",COUNT[n-1][B][i]);
 printf("\n");
}//End of knapsack()
         
