clang:
	clang++ main.cpp -o main
gpp:
	g++ main.cpp -o main-gpp
run:
	./main
rungpp:
	./main-gpp
clean:
	rm -rf main-gpp main
