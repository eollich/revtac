CC=clang++
all: revtac

file: revtac.o
	$(CC) $^ -o $@

%.o: %.c
	$(CC) -c $^ -o $@

clean:
	rm *.o
	rm revtac
