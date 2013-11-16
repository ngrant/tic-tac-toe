CC = g++

CFLAGS = -std=c++11 -g

TARGET = ttt

all: $(TARGET)

$(TARGET): 
	$(CC) $(CFLAGS) -o $(TARGET) src/main.cpp

clean:
	$(RM) $(TARGET)
