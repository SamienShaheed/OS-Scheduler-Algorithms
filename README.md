# OS-Scheduler-Algorithms

This project provides an in-depth analysis of various scheduling algorithms and their performance on different workloads. The focus is on First Come First Serve (FCFS), Round Robin (RR), and Multi-Level Feedback Queue (MLFQ) algorithms. This report includes source code implementations and performance evaluations based on average waiting times and turnaround times.

## Authors

- Samien Shaheed (https://github.com/SamienShaheed)
- Abdullah Marghoobul Haque (https://github.com/thexabd)
- Kanishka Aloysius Meditha Jayakody (https://github.com/kamjayakody12)

## Project Summary

The project explores and compares the efficiency of three different CPU scheduling algorithms:
1. **First Come First Serve (FCFS)**
2. **Round Robin (RR)**
3. **Multi-Level Feedback Queue (MLFQ)**

The comparison is based on three distinct workloads with varying burst times to determine which scheduler is best suited for different types of workloads. The analysis focuses on average waiting times and turnaround times to evaluate each algorithm's performance.

### Key Findings:
- **FCFS** performs best with processes that have burst times longer than the time quantum.
- **RR** is most effective for workloads with relatively short burst times when the time quantum is greater than the burst times.
- **MLFQ** shows the least average turnaround time for larger process burst times, but RR provides the shortest average waiting time.

### Influence of Time Quantum in RR:
- An increase in time quantum generally results in a decrease in average waiting time but may impact system interactivity.

### Tuning the MLFQ Scheduler:
- Implementing additional queues with increasing time quanta can optimize the MLFQ scheduler. Higher time quanta in the first queue reduce average waiting and turnaround times by retaining most processes within the Round Robin queue.

## Conclusion

The project concludes that the Round Robin algorithm generally provides the shortest average turnaround and waiting times. The MLFQ can be optimized by increasing the time quantum to keep most processes in the RR queue. Effective cycling through all jobs is ensured by RR, while MLFQ benefits from a well-tuned time quantum.
