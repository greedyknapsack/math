#include <stdio.h>
#include<stdlib.h>

int comp(const void *a,const void *b)
{
    int * t1=(int*)a;
    int * t2=(int*)b;
    
    return -t2[1]+t1[1];
}
 
void printMaxActivities(int n,int job[n][2])
{
    int i=0, j;
 
    printf("Following activities are selected with the starting and ending times:\n");
    qsort(job,n,sizeof(job[0]),comp);
    printf("%d - %d\n",job[i][0],job[i][1]);
    for (j = 1; j < n; j++) {
        
        if (job[j][0] >= job[i][1]) {
            printf("%d - %d\n", job[j][0],job[j][1]);
            i = j;
        }
    }
}
 
// Driver code
int main()
{
    /*
    int n; 
    printf("Enter number of jobs");
    scanf("%d",&n);
    int j[n][2];
    printf("Enter the satrting and finishing time in sequential order:\n");
    for(int i=0; i<n;i++)
        scanf("%d%d",&j[i][0],&j[i][1]);
    
    */

    int n=6;
    int j[][2]={{1,2},{3,4},{0,6},{5,7},{8,9},{5,9}};

    printMaxActivities(n,j);
    return 0;
}