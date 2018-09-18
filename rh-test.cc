
#include <string.h>
#include <stdio.h>
#include <sys/ptrace.h>
#include <stdlib.h>



int main()
{
    char a[50],temp;
    
    int i,j,n=0,len=0,first=1,second=1,next;
    int num[50];
    int flag[]={80,95,125,116,129,135, 142, 161, 213,166,257,386, 737, 991, 1700, 2681, 4282, 6866, 11043, 17724, 28675, 46399, 75044, 121451, 196479, 317829, 514252, 832085, 	1346270, 2178321, 3524584, 5702909, 9227493,14930352, 24157851, 39088196};
    
    if (ptrace (PTRACE_TRACEME, 0, 1, 0) == -1)
    {
      printf ("S0rry, N0t H3r3!\n");
      return 1;
    }
    
    printf("Ent3r 7h3 Pa55w0rd: ");
    //gets(a);
    scanf("%[^\n]",a); 
    len=strlen(a);
    
    if(len%2==1)
    {   len=len+1;
        //printf("%d",len);
        a[len-1]=a[(len-2)/2];      
    }
    
    
    for(i=0,j=len-1;i<len/2;++i,--j)
    {
        
        temp=a[i];
        a[i]=a[j];
        a[j]=temp;
    }
    a[len]=a[len]^a[(len-2)/2];
    
   for(i=0;i<len;i++)
    {
     
     a[i]=a[i]^a[i+1];
     num[i]=a[i];
     next = first + second;
     num[i]=num[i]+next;
     first = second;
     second = next;        
    }
    
    for(i=0;i<len;i++)
    {
        if(flag[i]==num[i])
        {
            n=0;
        }
        else
        {   n=1;
            break;
        }
        
    }
    
    if(n==1)
    {
        printf ("Wr0ng Pa55w0rd! 7ry Again Please!\n");
    }
    else
    {
        printf ("G00d Job!\n");
    }
    
    return 0;
}
