example_one: example_one.cpp
	g++ -ggdb $@.cpp `pkg-config --cflags --libs coronium` -o $@
testfile:
	echo "int main() { return 42; }" | gcc -xc - -o testfile
clean:
	rm example_one
