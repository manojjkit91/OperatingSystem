
CC = gcc
CFLAGS = -lpthread -I.
LD_FLAGS =
DEPS = $(wildcard *.h)
OBJ = $(patsubst %.c,%.o,$(wildcard *.c))
TARGET1 = Example1.out
TARGET2 = Example2.out
TARGET3 = Example3.out
%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

all: $(TARGET1) $(TARGET2) $(TARGET3)

$(TARGET1): Example1.o
	$(CC) $(LD_FLAGS) -o $@ $^ $(CFLAGS)

$(TARGET2): Example2.o
	$(CC) $(LD_FLAGS) -o $@ $^ $(CFLAGS)

$(TARGET3): Example3.o
	$(CC) $(LD_FLAGS) -o $@ $^ $(CFLAGS)

.PHONY: clean

clean:
	rm -f $(TARGET1) $(TARGET2) $(TARGET3) *.o *~ core
