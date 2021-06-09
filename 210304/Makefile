all: struct1

# struct1 is a "target" and struct1.cpp is a "dependency"
struct1: struct1.cpp
	# recipe describing how to build
	g++ -o $@ $<

clean:
	rm -f struct1