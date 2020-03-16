# sched_algorithm
## Program for CE155 class. Project on scheduling algorithms.

## **Algorithms implemented (implementing hehe)**
1. FCFS = First Come First Serve
2. SJF = Shortest Job First
3. SRTF = Shortest Remaining Time First (SJF preemptive)
4. P = Priority (preemptive)
5. RR ```Q``` = Round-Robin, where ```Q``` is the quantum time.
___
### For all examples assume test file is as follows:
```
2
4 SRTF
0 50 2
40 2 3
20 3 1
40 55 1
2 FCFS  
100 10 1  
0 70 1
```
### with the form:
```c++
'number of test cases' \n
'num of processes for case 1' 'algorithm 1' \n
process[1] 'arrival time' 'burst time' 'priority' \n
... \n
process[n] 'arrival time' 'burst time' 'priority' \n
'num of processes for case 2' 'algorithm 2' \n
....
```
___
## **Vectors**
### Algorithm Vector (schedAlg)
- Contains the specific scheduling algorithm (SJTF, FCFS, etc.) for the test cases.
- Starts at default index, 0.
- Given the test file, schedAlg will contain "SRTF" and "FCFS" as shown below:
``` c++
schedAlg[0] = SRTF
schedAlg[1] = FCFS
```

### Process Vector (proc)
- This vector is a 2 Dimensional Vector, or a Vector of a Vector of Integers
- The first index in proc **[i]** [j], or i, refers to the process number. 
    -   However, the first index (0) is allocated to the number of processes per test case.
    - For the example file then, ```proc[0] = {4, 4, 4}```, since the first test case has 4 as the process count.
- Index j, or the sub-vector, contains the specifications of process i.
    -   Specifically, Arrival time in ns, Burst time in ns, Priority with range [-20,20]
- Example of contents of proc with each line representing an index, therefore a vector:
``` C++
4 4 4 // 4 processes for test case 1 proc[0]
0 50 2 // proc[1]
40 2 3 // proc[2]
20 3 1 // proc[3]
40 55 1 // proc[4]
2 2 2 // 2 processes for test case 2 proc[5]
100 10 1 // proc[5 + 1]
0 70 1 // proc[5 + 2]
```
- Given this, the program should take into account the deletion of test cases that are finished in order to maintain proper referencing
    - i.e. Delete ```proc[0]``` to ```proc[4]``` after the first test case is scheduled