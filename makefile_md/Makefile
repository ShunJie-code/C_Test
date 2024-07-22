# version 1 目标+依赖
# hello: main.cpp printf_hello.cpp factorial.cpp
# 	g++ -o hello main.cpp printf_hello.cpp factorial.cpp

# version 2 只编译修改后的cpp文件
# CXX = g++
# TARGET = hello
# OBJ = main.o printf_hello.o factorial.o

# $(TARGET): $(OBJ)
# 	$(CXX) -o $(TARGET) $(OBJ)

# main.o: main.cpp
# 	$(CXX) -c main.cpp

# printf_hello.o: printf_hello.cpp
# 	$(CXX) -c printf_hello.cpp

# factorial.o: factorial.cpp
# 	$(CXX) -c factorial.cpp

# version 3
CXX = g++
TARGET = hello
OBJ = main.o printf_hello.o factorial.o

CXXFLAGS = -c -Wall

# @指目标 ^指所有依赖 <指第一个依赖
$(TARGET): $(OBJ)
	$(CXX) -o $@ $^

%.o: %.cpp
	$(CXX) $(CXXFLAGS) $< -o $@

clean:
	rm -f *.o $(TARGET)
