# Compiler and flags
CXX := clang++
CXXFLAGS := -std=c++20 -Wall -Wextra -g3 -O0

# Source files
SRCS := test_sub.cpp /Users/user/data/code/bitcoin/src/util/syserror.cpp

# Output binary
TARGET := test_sub

# Build rule
$(TARGET): $(SRCS)
	$(CXX) -I/Users/user/data/code/bitcoin/src -I/Users/user/data/code/bitcoin/build/src -I/Users/user/data/code/bitcoin/src/univalue/include $(CXXFLAGS) -o $(TARGET) $(SRCS)

# Clean rule
.PHONY: clean
clean:
	rm -f $(TARGET)
