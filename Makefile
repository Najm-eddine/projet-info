CC = gcc
CFLAGS = -Wall -Wextra -std=c11

crashTech: main.o annees.o ages.o accidents.o
	$(CC) $(CFLAGS) main.o annees.o ages.o accidents.o -o crashTech

main.o: main.c main.h annees.h ages.h accidents.h
	$(CC) $(CFLAGS) -c main.c -o main.o

annees.o: annees.c annees.h
	$(CC) $(CFLAGS) -c annees.c -o annees.o

ages.o: ages.c ages.h
	$(CC) $(CFLAGS) -c ages.c -o ages.o

accidents.o: accidents.c accidents.h
	$(CC) $(CFLAGS) -c accidents.c -o accidents.o

.PHONY: run clean

run: crashTech
	./crashTech $(ARGS)

clean:
	rm -f *.o crashTech
