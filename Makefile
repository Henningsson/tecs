SHELL    = /bin/sh
CXX      = g++
IDIR     = ./include
SDIR     = ./src
OBJDIR   = ./obj
CPPFLAGS = -std=c++0x -I$(IDIR)

TARGET  = tecs_demo
SOURCES = $(shell echo src/*.cpp)
HEADERS = $(shell echo include/*.h)
OBJECTS = $(SOURCES:.cpp=.o)


all: $(TARGET)

$(TARGET): $(OBJECTS)
	$(CXX) -o $(TARGET) $(OBJECTS)

clean:
	-rm $(OBJECTS) $(TARGET)
