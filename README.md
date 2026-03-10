[![Review Assignment Due Date](https://classroom.github.com/assets/deadline-readme-button-22041afd0340ce965d47ae6ef1cefeee28c7c493a6346c4f15d667ab976d596c.svg)](https://classroom.github.com/a/RNso7oRw)
# Non-Preemptive Priority CPU Scheduling (C)

## 📌 Objective
Implement the **Non-Preemptive Priority CPU Scheduling** algorithm in C.

- A lower priority value indicates a higher priority.
- Once a process starts execution, it runs until completion.
- CPU always selects the highest-priority process among the arrived processes.

---

## 📥 Input Format

n
PID1 AT1 BT1 PR1
PID2 AT2 BT2 PR2
...
PIDn ATn BTn PRn


Where:

- **n**  → Number of processes  
- **PID** → Process ID (string)  
- **AT**  → Arrival Time  
- **BT**  → Burst Time  
- **PR**  → Priority  

---

## 📤 Output Format

The program prints:

1. Waiting Time for each process  
2. Turnaround Time for each process  
3. Average Waiting Time  
4. Average Turnaround Time  

---

## ⚙️ Scheduling Rules

1. Only processes that have arrived are eligible for execution.
2. The process with the **highest priority** (lowest PR value) is selected.
3. If priorities are equal:
   - Process with earlier arrival time is selected.
4. The algorithm is **non-preemptive**:
   - A running process completes before the next one starts.

---

## ▶️ Compilation & Execution

```bash
gcc priority.c -o priority
./priority

To run with input file:

./priority < input1.txt
🧪 Sample Input
5
P1 2 6 3
P2 5 2 1
P3 1 8 4
P4 0 3 2
P5 4 4 2
✅ Sample Output
Waiting Time:
P1 5
P2 2
P3 14
P4 0
P5 1
Turnaround Time:
P1 11
P2 4
P3 22
P4 3
P5 5
Average Waiting Time: 4.40
Average Turnaround Time: 9.00
