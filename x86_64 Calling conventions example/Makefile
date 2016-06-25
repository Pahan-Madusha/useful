%.o:%.s
	$(CC) $(CFLAGS) -c $? -o $@

%:%.java
	javac $?
	java $@

all: main

main: main.o test.o
	gcc $? -o main


clean: 
	rm -f main *.o *~


