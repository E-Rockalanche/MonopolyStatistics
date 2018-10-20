TARGET := MonopolyStats.exe

SRCDIR := ./src
INCDIR := ./inc
OBJDIR := ./obj

CXX := g++
CFLAGS := -Wall -Wextra -std=c++11 
LFLAGS := -static

MAKE_OBJ = $(CXX) -c $(CFLAGS) $< -o $@ -I$(INCDIR)
MAKE_EXE = $(CXX) $(LFLAGS) $^ -o $@

SOURCES := $(wildcard $(SRCDIR)/*.cpp)
OBJECTS := $(patsubst $(SRCDIR)/%.cpp, $(OBJDIR)/%.o, $(SOURCES))

$(TARGET):	$(OBJECTS)
	$(MAKE_EXE)

$(OBJDIR)/%.o: $(SRCDIR)/%.cpp
	$(MAKE_OBJ)

clean:
	del $(OBJDIR)/%.o