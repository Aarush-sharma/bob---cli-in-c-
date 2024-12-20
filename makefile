CC = g++
SRCS = $(wildcard src/*.cpp)
OBJS = $(patsubst %.cpp, %.o, $(SRCS))
TARGET = spike

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(OBJS) -o $@

%.o: src/%.cpp src/%.h
	$(CC) -c $< -o $@

clean:
	rm -f $(TARGET) $(OBJS)