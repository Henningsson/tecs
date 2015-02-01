SHELL    = /bin/sh
CXX      = g++
IDIR     = ./include
SDIR     = ./src
OBJDIR   = ./obj
CPPFLAGS = -std=c++0x -I$(IDIR)
LDFLAGS  = -lsfml-graphics -lsfml-window -lsfml-system

TARGET  = engine_demo
SOURCES = $(shell echo src/*.cpp)
HEADERS = $(shell echo include/*.h)
OBJECTS = $(SOURCES:.cpp=.o)


all: $(TARGET)

$(TARGET): $(OBJECTS)
	$(CXX) -o $(TARGET) $(OBJECTS) $(LDFLAGS)

clean:
	-rm $(OBJECTS) $(TARGET)
