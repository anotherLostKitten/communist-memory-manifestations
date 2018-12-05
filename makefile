runner: marks.o
	gcc marks.o -o runner
marks.o: marks.c
	gcc -c marks.c
run: runner
	./runner
clean:
	rm *.o *~* *.out runner \#*\#
