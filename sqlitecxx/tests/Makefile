CC = g++

CFLAGS  = -g -Wall -I `pwd`../src
TARGET = assignment_integer

all: $(TARGET)

$(TARGET): $(TARGET).cc
	@$(CC) $(CFLAGS) -o $(TARGET) $(TARGET).cc -lgtest -lpthread

clean:
	$(RM) $(TARGET)
