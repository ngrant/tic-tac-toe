CC = g++

CFLAGS = -std=c++11 -g

TARGET = ttt

all: $(TARGET)

$(TARGET): $(TARGET).cpp
	$(CC) $(CFLAGS) -o $(TARGET) main.cpp

clean:
	$(RM) $(TARGET)
