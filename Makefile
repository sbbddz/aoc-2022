all: day1 day1pt2

day1pt2: day1pt2.c
	$(CC) $^ -o $@

day1: day1.c
	$(CC) $^ -o $@
