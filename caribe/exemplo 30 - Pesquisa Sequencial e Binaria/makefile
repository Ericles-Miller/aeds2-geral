############################# Makefile ##########################
all: 
		gcc -o seq_bin  main.c

build_all: build	build100000 build500000  build1000000 build100000000

build:
		gcc -o exe build_numbers_set.c

build100000:
		./exe 500 100000 input100000.txt

build500000:
		./exe 1000 500000 input500000.txt

build1000000:
		./exe 10000 1000000 input1000000.txt

build100000000:
		./exe 10000 100000000 input100000000.txt

clean:
		rm -rf *.o
		rm *.txt
		rm exe