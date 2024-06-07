#include<stdio.h>

struct process {

    char name;
    float arrival_Time;
	float burst_Time;
	float waiting_Time;
	float turnaround_Time;
	float remaining_Time;
	float completion_Time;

} RR[10],FCFS[10]; // Two queues for MLFQ Scheduling

int no_Of_Processes;

void sortByArrivalTime() {
	struct process temp;
	int i,j;

	for(i=0 ; i<no_Of_Processes ; i++) {
		for(j=i+1 ; j<no_Of_Processes ; j++) {
			if(RR[i].arrival_Time>RR[j].arrival_Time) {
				temp = RR[i];
				RR[i] = RR[j];
				RR[j] = temp;
			}
		}
	}
}

int main() {
	int i, j, time_Quantum, k=0 , r=0 , time=0 , flag=0;
	float avgTAT=0, avgWT=0;
	char c;

	printf("Enter no of processes:");
	scanf("%d",&no_Of_Processes);

	for(i=0 , c='A'; i<no_Of_Processes ; i++ , c++) {
		RR[i].name = c;

		printf("Enter the arrival time and burst time of process %c: ", RR[i].name);
		scanf("%f%f", &RR[i].arrival_Time , &RR[i].burst_Time);

		RR[i].remaining_Time = RR[i].burst_Time;/*save burst time in remaining time for each process*/
	}

	printf("\nEnter Time Quantum:");
	scanf("%d", &time_Quantum);

	sortByArrivalTime();
	time = RR[0].arrival_Time;

	printf("\nProcess in first queue following RR with time quantum = %d", time_Quantum);
	printf("\nProcess ID | Burst Time | Waiting Time | Turn Around Time\n");

	// First Queue is Round Robin
	for(i=0 ; i<no_Of_Processes ; i++) {
		if(RR[i].remaining_Time <= time_Quantum) {

			time += RR[i].remaining_Time;/*from arrival time of first process to completion of this process*/

			RR[i].remaining_Time = 0;
			RR[i].waiting_Time = time - RR[i].arrival_Time - RR[i].burst_Time;/*amount of time process has been waiting in the first queue*/
			RR[i].turnaround_Time = time - RR[i].arrival_Time;/*amount of time to execute the process*/

			avgTAT += RR[i].turnaround_Time;
			avgWT += RR[i].waiting_Time;

			printf("%d\t\t%.2f\t\t%.2f\t\t%.2f\n",i+1,RR[i].burst_Time,RR[i].waiting_Time,RR[i].turnaround_Time);

		} else/*process moves to queue 2 with qt=8*/ {
			FCFS[r].arrival_Time = time;

			time += time_Quantum;

			RR[i].remaining_Time -= time_Quantum;
			FCFS[r].burst_Time = RR[i].remaining_Time;
			FCFS[r].remaining_Time = FCFS[r].burst_Time;
			FCFS[r].name = RR[i].name;
			
			r++;
			flag = 2;
		}
	}

	// Second Queue is First Come First
	if(flag==2) {
		printf("\n\nProcess in second queue following FCFS\n");
	}
	

	for(i=0 ; i<r ; i++) {
		if(i==0)
			FCFS[i].completion_Time = FCFS[i].burst_Time + time - time_Quantum;
		else
			FCFS[i].completion_Time = FCFS[i-1].completion_Time + FCFS[i].burst_Time;
	}

	for(i=0 ; i<r ; i++) {
		FCFS[i].turnaround_Time = FCFS[i].completion_Time;
		FCFS[i].waiting_Time = FCFS[i].turnaround_Time - FCFS[i].burst_Time;

		avgTAT += FCFS[i].turnaround_Time;
		avgWT += FCFS[i].waiting_Time;

		printf("%d\t\t%.2f\t\t%.2f\t\t%.2f\n", i+1 , FCFS[i].burst_Time , FCFS[i].waiting_Time , FCFS[i].turnaround_Time);
	}

	printf("\nAverage Turnaround Time: %.2f", avgTAT/no_Of_Processes);
	printf("\nAverage Waiting Time: %.2f", avgWT/no_Of_Processes);
}