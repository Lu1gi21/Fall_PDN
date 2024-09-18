run-test-coverage: build
	./prog infile.txt outfile.txt
	./prog 
	./prog infile.txt
	gcov prog.c

run-test-leak: build
	valgrind --tool=memcheck --leak-check=yes --show-reachable=yes --num-callers=20 --track-fds=yes ./prog infile.txt outfile.txt
	valgrind --tool=memcheck --leak-check=yes --show-reachable=yes --num-callers=20 --track-fds=yes ./prog
	valgrind --tool=memcheck --leak-check=yes --show-reachable=yes --num-callers=20 --track-fds=yes ./prog infile.txt 

build: clean
	gcc -fprofile-arcs -ftest-coverage -g prog.c -lm -o prog
	
clean:
	rm -f *~
	rm -f example
	rm -f *.gcda *.gcno *.gcov