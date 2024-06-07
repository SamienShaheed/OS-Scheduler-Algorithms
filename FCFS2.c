// First Come First Serve Scheduling Algorithm

#include<stdio.h>

// Function to find the waiting time for all processes
void waitingTime(float processes[], int n, float bt[], float wt[])
{
    // Waiting time for the first process is 0
    wt[0] = 0;
   
    // Calculating waiting time
    for (int  i = 1; i < n ; i++)
    {
        wt[i] = bt[i-1] + wt[i-1];
    }
}

// Function to calculate turnaround time
void turnAroundTime(float processes[], int n, float bt[], float wt[], float tat[])
{
    // Calculating turnaround time by adding waiting time and burst time
    for (int  i = 0; i < n ; i++)
    {
       tat[i] = bt[i] + wt[i];
    }
}

// Function to calculate average time
void avgTime(float processes[], int n, float bt[])
{
    float wt[n], tat[n], total_wt = 0, total_tat = 0;
   
    // Function to find waiting time of all processes
    waitingTime(processes, n, bt, wt);
   
    // Function to find turn around time for all processes
    turnAroundTime(processes, n, bt, wt, tat);
   
    // Display processes along with all details
    printf("Process ID | Burst Time | Waiting Time | Turn Around Time\n");
   
    // Calculate total waiting time and total turn around time
    for (int i=0; i<n; i++)
    {
        total_wt = total_wt + wt[i];
        total_tat = total_tat + tat[i];

        printf("    %.2f\t\t%.2f\t\t%.2f\t\t%.2f\n", (i+1), bt[i], wt[i], tat[i]);
    }
    
    float s=(float)total_wt / (float)n;
    float t=(float)total_tat / (float)n;
    printf("Average waiting time = %.2f",s);
    printf("\n");
    printf("Average turn around time = %.2f ",t);
}
   
int main()
{
    int n = 0;

    printf("Enter the number of processes:\n");
    scanf("%d", &n);
    float processes[n];
   
    //Burst time of all processes
    float burst_time[n];

    for(int i=0; i<n; i++)
    {
        printf("Input burst time for process %d:", i);
        scanf("%f", &burst_time[i]);
    }

    avgTime(processes, n,  burst_time);
    return 0;
}