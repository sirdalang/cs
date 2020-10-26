
CPP=g++
CFLAGS=-std=c++11
CFLAGS+=-g -Wall

SRC_QUICKSORT=quicksort.cpp
SRC_SQLIST=sqlist.cpp sqlist_test.cpp
SRC_LINKEDLIST=linkedlist.cpp linkedlist_test.cpp
SRC_KMP=kmp.cpp

sqlist.out:$(SRC_SQLIST)
	$(CPP) $(SRC_SQLIST) $(CFLAGS)  -o $@

quicksort.out:$(SRC_QUICKSORT)
	$(CPP) $(SRC_QUICKSORT) $(CFLAGS) -o $@

linkedlist.out:$(SRC_LINKEDLIST)
	$(CPP) $(SRC_LINKEDLIST) $(CFLAGS) -o $@

kmp.out:$(SRC_KMP)
	$(CPP) $(SRC_KMP) $(CFLAGS) -o $@

.PHONY: 
	clean

clean:
	rm -rf *.out
