// C program for the above approach
 
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
 
// A structure to represent a job
typedef struct Job {
   
    int dead; // Deadline of job
    int profit; // Profit if job is over before or on
                // deadline
} Job;
 
// This function is used for sorting all jobs according to
// profit
int compare(const void* a, const void* b)
{
    Job* temp1 = (Job*)a;
    Job* temp2 = (Job*)b;
    return (temp2->profit - temp1->profit);
}
 
// Find minimum between two numbers.
int min(int num1, int num2)
{
    return (num1 > num2) ? num2 : num1;
}
 
// Returns maximum profit from jobs
void printJobScheduling(Job arr[], int n)
{
    
    qsort(arr, n, sizeof(Job), compare);
 
    int result[n]; 
    bool slot[n]; 
 
    
    for (int i = 0; i < n; i++)
        slot[i] = false;
 
    
    for (int i = 0; i < n; i++) {
       
        
        for (int j = min(n, arr[i].dead) - 1; j >= 0; j--) {
           
            
            if (slot[j] == false) {
                result[j] = i; 
                slot[j] = true; 
                break;
            }
        }
    }
 
    
    for (int i = 0; i < n; i++)
        if (slot[i])
            printf("%d - %d\n", arr[result[i]].profit,arr[result[i]].dead);
}
 

int main()
{/*
    int n; 
    printf("Enter number of jobs");
    scanf("%d",&n);
    Job arr[n];
    printf("Enter the profit and finishing time in sequential order:");
    for(int i=0; i<n;i++)
        scanf("%d%d",&arr[i].profit,&arr[i].dead);*/
    Job arr[] = { {  2, 100 },
                  {  1, 19 },
                  {  2, 27 },
                  { 1, 25 },
                  {  3, 15 } };
    int n = sizeof(arr) / sizeof(arr[0]);
    printf(
        "Following is maximum profit sequence of jobs: \n");
    
    
    printJobScheduling(arr, n);
    return 0;
}