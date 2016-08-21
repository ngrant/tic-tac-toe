TARGET = ttt

all: $(TARGET)

$(TARGET): 
	$(CXX) $(CXXFLAGS) -o $(TARGET) src/main.cpp

clean:
	$(RM) $(TARGET)
