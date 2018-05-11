Name  : Keawa Rozet
Date  : 4-20-18
Class : CSC415
Project 5 - Threadracer Part 1

Compile Instructions:
---------------------

Use the Makefile to compile the project:
make -f Makefile

Run Instructions:
-----------------

Then type the following command to execute the program:
./threadracer

Project Description:
--------------------

This project now executes each set of increments one thread at a time.
The mutex gets created and then locks after a thread has begun incrementing, then unlocks after it is done.
This process allows for all the threads to increment the global variable without interfering with each other.

Example Execution:
------------------
> make -f Makefile
gcc -I -Wall pthread_race.c -o threadracer -lpthread
> ./threadracer
This is Thread #1	inc: 1
This is Thread #1	inc: 2
This is Thread #1	inc: 3
This is Thread #1	inc: 4
This is Thread #1	inc: 5
This is Thread #1	inc: 6
This is Thread #1	inc: 7
This is Thread #1	inc: 8
This is Thread #1	inc: 9
This is Thread #1	inc: 10
This is Thread #2	inc: 11
This is Thread #2	inc: 12
This is Thread #2	inc: 13
This is Thread #2	inc: 14
This is Thread #2	inc: 15
This is Thread #2	inc: 16
This is Thread #2	inc: 17
This is Thread #2	inc: 18
This is Thread #2	inc: 19
This is Thread #2	inc: 20
This is Thread #3	inc: 21
This is Thread #3	inc: 22
This is Thread #3	inc: 23
This is Thread #3	inc: 24
This is Thread #3	inc: 25
This is Thread #3	inc: 26
This is Thread #3	inc: 27
This is Thread #3	inc: 28
This is Thread #3	inc: 29
This is Thread #3	inc: 30
This is Thread #4	inc: 31
This is Thread #4	inc: 32
This is Thread #4	inc: 33
This is Thread #4	inc: 34
This is Thread #4	inc: 35
This is Thread #4	inc: 36
This is Thread #4	inc: 37
This is Thread #4	inc: 38
This is Thread #4	inc: 39
This is Thread #4	inc: 40
This is Thread #5	inc: 41
This is Thread #5	inc: 42
This is Thread #5	inc: 43
This is Thread #5	inc: 44
This is Thread #5	inc: 45
This is Thread #5	inc: 46
This is Thread #5	inc: 47
This is Thread #5	inc: 48
This is Thread #5	inc: 49
This is Thread #5	inc: 50
This is Thread #6	inc: 51
This is Thread #6	inc: 52
This is Thread #6	inc: 53
This is Thread #6	inc: 54
This is Thread #6	inc: 55
This is Thread #6	inc: 56
This is Thread #6	inc: 57
This is Thread #6	inc: 58
This is Thread #6	inc: 59
This is Thread #6	inc: 60
This is Thread #7	inc: 61
This is Thread #7	inc: 62
This is Thread #7	inc: 63
This is Thread #7	inc: 64
This is Thread #7	inc: 65
This is Thread #7	inc: 66
This is Thread #7	inc: 67
This is Thread #7	inc: 68
This is Thread #7	inc: 69
This is Thread #7	inc: 70
This is Thread #8	inc: 71
This is Thread #8	inc: 72
This is Thread #8	inc: 73
This is Thread #8	inc: 74
This is Thread #8	inc: 75
This is Thread #8	inc: 76
This is Thread #8	inc: 77
This is Thread #8	inc: 78
This is Thread #8	inc: 79
This is Thread #8	inc: 80
This is Thread #9	inc: 81
This is Thread #9	inc: 82
This is Thread #9	inc: 83
This is Thread #9	inc: 84
This is Thread #9	inc: 85
This is Thread #9	inc: 86
This is Thread #9	inc: 87
This is Thread #9	inc: 88
This is Thread #9	inc: 89
This is Thread #9	inc: 90
This is Thread #10	inc: 91
This is Thread #10	inc: 92
This is Thread #10	inc: 93
This is Thread #10	inc: 94
This is Thread #10	inc: 95
This is Thread #10	inc: 96
This is Thread #10	inc: 97
This is Thread #10	inc: 98
This is Thread #10	inc: 99
This is Thread #10	inc: 100
