CFLAGS = -std=c++11 -g

TARGET = ttt

all: $(TARGET)

$(TARGET): 
	$(CXX) $(CFLAGS) -o $(TARGET) src/main.cpp

clean:
	$(RM) $(TARGET)
