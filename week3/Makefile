CC=gcc
COMPILE=$(CC)

w3_task1: w3_task1.o
	$(COMPILE) w3_task1.o -o $@

w3_task2: w3_task2.o
	$(COMPILE) w3_task2.o -o $@

w3_task3: w3_task3.o
	$(COMPILE) w3_task3.o -o $@

w3_task4: w3_task4.o
	$(COMPILE) w3_task4.o -o $@

w3_task5: w3_task5.o
	$(COMPILE) w3_task5.o -o $@

all: w3_task1 w3_task2 w3_task3 w3_task4 w3_task5

clean:
	rm -f *.o w3_task1 w3_task2 w3_task3 w3_task4 w3_task5
