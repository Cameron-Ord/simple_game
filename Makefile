# Makefile for a C++ project with SDL2

# Compiler
CXX := g++

# Compiler flags
CXXFLAGS := -std=c++11 -Wall

# SDL2 flags
SDL2_FLAGS := $(shell sdl2-config --cflags --libs --)
SDL_IMAGE_FLAGS := -lSDL2_image
# Source files
SRCDIR := src
SOURCES := $(wildcard $(SRCDIR)/*.cpp)

# Header files
INCDIR := include
HEADERS := $(wildcard $(INCDIR)/*.hpp)

# Object files
OBJDIR := obj
OBJECTS := $(patsubst $(SRCDIR)/%.cpp,$(OBJDIR)/%.o,$(SOURCES))

# Executable
BINDIR := bin
EXECUTABLE := $(BINDIR)/myprogram

# Main target
all: $(EXECUTABLE)

# Rule to build the executable
$(EXECUTABLE): $(OBJECTS)
	$(CXX) $(CXXFLAGS) -o $@ $^ $(SDL2_FLAGS) $(SDL_IMAGE_FLAGS)

# Rule to build object files
$(OBJDIR)/%.o: $(SRCDIR)/%.cpp $(HEADERS)
	$(CXX) $(CXXFLAGS) -I$(INCDIR) -c -o $@ $<

# Create directories if they don't exist
$(shell mkdir -p $(OBJDIR) $(BINDIR))

# Clean rule
clean:
	rm -rf $(OBJDIR) $(BINDIR)

# PHONY targets
.PHONY: all clean
