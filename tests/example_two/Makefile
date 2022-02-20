example_two: example_two.cpp
	g++ -ggdb $@.cpp -lbfd -lcoronium -o $@
	echo "int main() { return 42; }" | gcc -xc - -o testfile
clean:
	rm example_two

