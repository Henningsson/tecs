SHELL    = /bin/sh
CXX      = g++
IDIR     = ./include
SDIR     = ./src
OBJDIR   = ./obj
CPPFLAGS = -std=c++0x -I$(IDIR) -Wall -Werror -fPIC

TARGET  = libtecs.so
SOURCES = $(shell echo src/*.cpp)
HEADERS = $(shell echo include/*.h)
OBJECTS = $(SOURCES:.cpp=.o)


all: $(TARGET)

$(TARGET): $(OBJECTS)
	$(CXX) -shared $(OBJECTS) -o $(TARGET)


install:
	cp $(TARGET) /usr/local/lib
	mkdir -p /usr/include/tecs
	cp ./include/*.hpp /usr/include/tecs/

clean:
	-rm $(OBJECTS) $(TARGET)
