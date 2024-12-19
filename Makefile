# Makefile

# Compiler
CXX = g++

# Compiler flags
CXXFLAGS = -Ilogger

# Source files
SRCS = main.cpp EventWrapper.cpp QHsmHelper.cpp Runner.cpp ThreadedCodeExecutor.cpp Switch_resetHelper.cpp

# Object files
OBJS = $(SRCS:.cpp=.o)

# Executable
TARGET = switch

# Build rules
all: $(TARGET)

$(TARGET): $(OBJS)
	$(CXX) $(OBJS) -o $(TARGET)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) $(TARGET)

.PHONY: all clean
