# Project 5 – Producer Consumer Problem
Name  : Keawa Rozet
Date  : 4-20-2018
Class : CSC415

# Compile Instruction:
Use the Makefile to compile the project:
make -f Makefile

# Run Instruction:
Then type the following command to execute the program:
./pandc 7 5 3 15 1 1

# Project Description:

This Consumer Producer project uses multithreading techniques to have a specific amount of producers produce a specific number of items. Then, it uses a specific amount of consumers to consume all of the items produced. Each producer and consumer are created on their own thread and then are instructed to share information to produce and consumer.

To control the process of consuming/producing, mutex and semaphores have been implemented. The semaphores are used to communicate between the producer and consumer threads to allow the other thread to consume when an item has been produced, and visa versa. Next, the mutex is called to limit only one producer/consumer to produce/consume at a time.

The method for storing data that I decided to use was a Queue. Using a Queue made the most sense since it allowed me to store the items produced and items consumed into their respective arrays in an order which let me easily compare them. For example, a producer creates an item, enqueue&#39;s that item, and stores that value in a separate array. The consumer dequeue&#39;s the queue and receives the items in the order in which they were enqueue&#39;d. It then takes that item and stores it in a separate array as well.

The amount of time required to complete all the threads is calculated by subtracting the start time from the end time. Then both items consumed and items produced arrays are printed to show the order in which items were produced and consumed.

# Example Execution:
```
> ./pandc 7 5 3 15 1 1
N = 7   P = 5   C = 3   X = 15   Ptime = 1   Ctime = 1
Current Time: Fri May 11 11:00:15 2018

	1 was produced by producer->	1
Producer Thread Joined: 1
	2 was produced by producer->	1
	3 was produced by producer->	1
	1 was consumed by consumer->	3
	4 was produced by producer->	1
	5 was produced by producer->	2
	2 was consumed by consumer->	1
	3 was consumed by consumer->	1
	4 was consumed by consumer->	2
	6 was produced by producer->	4
	7 was produced by producer->	4
	5 was consumed by consumer->	2
	8 was produced by producer->	4
	6 was consumed by consumer->	2
	9 was produced by producer->	2
	10 was produced by producer->	5
	7 was consumed by consumer->	1
	8 was consumed by consumer->	1
	11 was produced by producer->	1
	9 was consumed by consumer->	1
	12 was produced by producer->	1
	10 was consumed by consumer->	1
	11 was consumed by consumer->	3
	13 was produced by producer->	2
	14 was produced by producer->	2
	12 was consumed by consumer->	3
	15 was produced by producer->	2
	13 was consumed by consumer->	2
	16 was produced by producer->	2
	14 was consumed by consumer->	2
	15 was consumed by consumer->	1
	17 was produced by producer->	3
	18 was produced by producer->	3
	16 was consumed by consumer->	3
	19 was produced by producer->	1
	20 was produced by producer->	5
	21 was produced by producer->	2
	17 was consumed by consumer->	2
	18 was consumed by consumer->	2
	19 was consumed by consumer->	2
	22 was produced by producer->	3
	20 was consumed by consumer->	3
	23 was produced by producer->	4
	24 was produced by producer->	1
	21 was consumed by consumer->	1
	22 was consumed by consumer->	1
	25 was produced by producer->	1
	23 was consumed by consumer->	2
	26 was produced by producer->	3
	24 was consumed by consumer->	3
	27 was produced by producer->	5
	25 was consumed by consumer->	3
	28 was produced by producer->	5
	26 was consumed by consumer->	1
	29 was produced by producer->	1
	27 was consumed by consumer->	1
	30 was produced by producer->	3
	31 was produced by producer->	4
	32 was produced by producer->	2
	28 was consumed by consumer->	3
	33 was produced by producer->	5
	29 was consumed by consumer->	2
	34 was produced by producer->	1
	30 was consumed by consumer->	1
	31 was consumed by consumer->	1
	32 was consumed by consumer->	1
	35 was produced by producer->	4
	33 was consumed by consumer->	2
	36 was produced by producer->	2
	34 was consumed by consumer->	3
	37 was produced by producer->	3
	38 was produced by producer->	5
	39 was produced by producer->	1
	35 was consumed by consumer->	1
	40 was produced by producer->	4
	36 was consumed by consumer->	2
	37 was consumed by consumer->	2
	38 was consumed by consumer->	2
	39 was consumed by consumer->	1
	41 was produced by producer->	3
	42 was produced by producer->	3
	43 was produced by producer->	5
	44 was produced by producer->	1
	40 was consumed by consumer->	3
	41 was consumed by consumer->	3
	42 was consumed by consumer->	3
	45 was produced by producer->	2
	43 was consumed by consumer->	3
	46 was produced by producer->	3
	44 was consumed by consumer->	3
	47 was produced by producer->	3
	48 was produced by producer->	5
	49 was produced by producer->	1
	45 was consumed by consumer->	1
	46 was consumed by consumer->	1
	47 was consumed by consumer->	1
	48 was consumed by consumer->	2
	49 was consumed by consumer->	3
	50 was produced by producer->	2
	51 was produced by producer->	2
	52 was produced by producer->	2
	53 was produced by producer->	5
	54 was produced by producer->	1
	55 was produced by producer->	3
Producer Thread Joined: 2
	50 was consumed by consumer->	1
	51 was consumed by consumer->	1
	52 was consumed by consumer->	1
	53 was consumed by consumer->	1
	56 was produced by producer->	2
	57 was produced by producer->	4
	54 was consumed by consumer->	2
	55 was consumed by consumer->	2
	56 was consumed by consumer->	3
	58 was produced by producer->	3
	59 was produced by producer->	3
	60 was produced by producer->	3
	61 was produced by producer->	5
	62 was produced by producer->	4
	63 was produced by producer->	2
	57 was consumed by consumer->	2
Producer Thread Joined: 3
	58 was consumed by consumer->	2
	59 was consumed by consumer->	2
	60 was consumed by consumer->	3
	61 was consumed by consumer->	3
	62 was consumed by consumer->	1
	64 was produced by producer->	5
	65 was produced by producer->	5
	66 was produced by producer->	5
	67 was produced by producer->	5
	63 was consumed by consumer->	3
	68 was produced by producer->	4
	64 was consumed by consumer->	1
	65 was consumed by consumer->	2
	66 was consumed by consumer->	2
	67 was consumed by consumer->	2
	69 was produced by producer->	5
	70 was produced by producer->	4
	71 was produced by producer->	4
	72 was produced by producer->	4
	73 was produced by producer->	4
	74 was produced by producer->	3
	68 was consumed by consumer->	3
Producer Thread Joined: 4
	69 was consumed by consumer->	3
	70 was consumed by consumer->	3
	71 was consumed by consumer->	3
	72 was consumed by consumer->	3
	73 was consumed by consumer->	3
	75 was produced by producer->	4
	74 was consumed by consumer->	2
Producer Thread Joined: 5
Consumer Thread Joined: 1
Consumer Thread Joined: 2
	75 was consumed by consumer->	2
Consumer Thread Joined: 3

Current Time: Fri May 11 11:02:45 2018

---------------------------------
Producer Buffer	| Consumer Buffer
---------------------------------
1		| 1
2		| 2
3		| 3
4		| 4
5		| 5
6		| 6
7		| 7
8		| 8
9		| 9
10		| 10
11		| 11
12		| 12
13		| 13
14		| 14
15		| 15
16		| 16
17		| 17
18		| 18
19		| 19
20		| 20
21		| 21
22		| 22
23		| 23
24		| 24
25		| 25
26		| 26
27		| 27
28		| 28
29		| 29
30		| 30
31		| 31
32		| 32
33		| 33
34		| 34
35		| 35
36		| 36
37		| 37
38		| 38
39		| 39
40		| 40
41		| 41
42		| 42
43		| 43
44		| 44
45		| 45
46		| 46
47		| 47
48		| 48
49		| 49
50		| 50
51		| 51
52		| 52
53		| 53
54		| 54
55		| 55
56		| 56
57		| 57
58		| 58
59		| 59
60		| 60
61		| 61
62		| 62
63		| 63
64		| 64
65		| 65
66		| 66
67		| 67
68		| 68
69		| 69
70		| 70
71		| 71
72		| 72
73		| 73
74		| 74
75		| 75

Total Runtime: 150 seconds.
```
