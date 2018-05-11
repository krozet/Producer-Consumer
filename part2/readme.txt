Name  : Keawa Rozet
Date  : 4-20-2018
Class : CSC415
Project 5 – Consumer Producer Problem


Compile Instruction:
--------------------

Use the Makefile to compile the project:
make -f Makefile


Run Instruction:
----------------

Then type the following command to execute the program:
./pandc 7 5 3 15 1 1


Project Description:
--------------------

This Consumer Producer project uses multithreading techniques to have a specific amount of producers produce a specific number of items.
Then, it uses a specific amount of consumers to consume all of the items produced. Each producer and consumer are created on their own thread and then are instructed to share information to produce and consumer.

To control the process of consuming/producing, mutex and semaphores have been implemented.
The semaphores are used to communicate between the producer and consumer threads to allow the other thread to consume when an item has been produced, and visa versa.
Next, the mutex is called to limit only one producer/consumer to produce/consume at a time.

The method for storing data that I decided to use was a Queue.
Using a Queue made the most sense since it allowed me to store the items produced and items consumed into their respective arrays in an order which let me easily compare them.
For example, a producer creates an item, enqueue’s that item, and stores that value in a separate array. The consumer dequeue’s the queue and receives the items in the order in which they were enqueue’d. It then takes that item and stores it in a separate array as well.

The amount of time required to complete all the threads is calculated by subtracting the start time from the end time.
Then both items consumed and items produced arrays are printed to show the order in which items were produced and consumed.
