# -g 可调试
TARGET = main
CFILES = main.c \
sequentialSearch.c \
orderTableSearch.c \
common_8.c
$(TARGET): $(CFILES) | Makefile
	gcc -g -Wall -o $@ $(CFILES) -lm
clean:
	rm -f *.o $(TARGET)