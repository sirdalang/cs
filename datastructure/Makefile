
CPP=g++
CFLAGS=-std=c++11
CFLAGS+=-g 

SRC_SQLIST=sqlist.cpp sqlist_test.cpp

SRC_QUICKSORT=quicksort.cpp

sqlist.out:$(SRC_SQLIST)
	$(CPP) $(SRC_SQLIST) $(CFLAGS)  -o $@

quicksort.out:$(SRC_QUICKSORT)
	$(CPP) $(SRC_QUICKSORT) $(CFLAGS) -o $@

.PHONY: 
	clean

clean:
	rm -rf *.out
