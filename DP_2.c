#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int issolvable(int A[],int B[],int n,int T,int fl[]);
void printsoln(int A[],int B[],int fl[],int n);
int main()
{
  int n,T; 
  printf("Enter value of n:");
  scanf("%d",&n);
  int A[n],B[n],i,j;
  for(i=0;i<n;i++)
      scanf("%d",&A[i]);
  for(i=0;i<n;i++)
      scanf("%d",&B[i]);
  printf("Enter T:");
  scanf("%d",&T);
  int fl[2*n];
  for(i=0;i<2*n;i++)
      fl[i] = 0;
  if(issolvable(A,B,n,T,fl))
     printsoln(A,B,fl,n);
  else
     return 0;
  return 0;
}

int issolvable(int A[],int B[],int n,int T,int fl[])
{
  int V[2*n+1][T+1],i,j,C[2*n];
  j=0;
  for(i=0;i<n;i++)
      C[j++] = A[i];
  for(i=0;i<n;i++)
      C[j++] = B[i];
  for(i=0;i<=2*n;i++)
      V[i][0] = 0;
  for(j=0;j<=T;j++)
      V[0][j] = 0;

  for(i=0;i<=2*n;i++)
     {
       for(j=0;j<=T;j++)
         {
           if(abs(V[i-1][j] - j) < abs((C[i-1] + V[i-1][j - C[i-1]]) - j))
               V[i][j] = V[i-1][j];
           else
                V[i][j] = (C[i-1] + V[i-1][j - C[i-1]]);
         }
     }
  i = 2*n;
  j=T;
  while(V[i][j] != 0)
  {
    if(V[i][j] == V[i-1][j])
        i--;
    else
       {
        fl[i-1] = 1;
        j -= C[i-1];
        i--;
       }
  }
  if(T == V[2*n][T])
     {
        printf("Solution exists\n");
        return 1;
     }
  printf("Solution doesnt exist\n");
  return 0;
}


void printsoln(int A[],int B[],int fl[],int n)
{
  int i,j,sum1=0,sum2=0;
  printf("A: ");
  for(i=0;i<n;i++)
     {      
       if(fl[i] == 1)
         {
          printf("%d ",A[i]);
          sum1 += A[i];
         }
       else
          printf("  ");
     }
  printf("\n");
  printf("B: ");
  for(j=n;j<2*n;j++)
     {
       if(fl[j] == 1)
         {
           printf("%d ",B[j-n]);
           sum2 += B[j-n];
         }
       else
          printf("  ");
     }
  printf("\n");
  printf("Sum1 = %d, Sum2 = %d\n",sum1,sum2);
}
         
  





