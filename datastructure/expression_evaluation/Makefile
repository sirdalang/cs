
CPP=g++
CFLAGS=-std=c++11
CFLAGS+=-g -Wall

TARGET=expeva.out

SRC=exprcalc.cpp expritem.cpp main.cpp
HEAD=exprcalc.h expritem.h public.h

$(TARGET):$(SRC) $(HEAD)
	$(CPP) $(SRC) $(CFLAGS) -o $@

.PHONY:
	clean

clean:
	rm -rf $(TARGET)