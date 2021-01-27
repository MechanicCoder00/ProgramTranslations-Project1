CC	= g++
TARGET	= P1
OBJS	= testscanner.o scanner.o main.o

$(TARGET): $(OBJS)
	$(CC) -o $@ $(OBJS)

main.o: main.cpp
	$(CC) -std=c++11 -c main.cpp

scanner.o: scanner.cpp scanner.h
	$(CC) -std=c++11 -c scanner.cpp
	
testscanner.o: testscanner.cpp testscanner.h
	$(CC) -std=c++11 -c testscanner.cpp

.PHONY: clean
clean:
	/bin/rm -f *.o temp.fs19 $(TARGET)
