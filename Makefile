#
# define some Makefile variables for the compiler and compiler flags
# to use Makefile variables later in the Makefile: $()
#
#  -g    adds debugging information to the executable file
#  -Wall turns on most, but not all, compiler warnings
#
# for C++ define  CC = g++
#
CC = g++
LINKER   = $(CC) -o
rm = rm -rf
TARGET = runner
DEBUG = -g
LFLAGS = -Wall $(DEBUG) -I. -lm
CFLAGS = -Wall -c $(DEBUG)
SRCDIR = src
OBJDIR = obj
BINDIR = bin

SOURCES  := $(wildcard $(SRCDIR)/*.cpp)
INCLUDES := $(wildcard $(SRCDIR)/*.h)
OBJECTS  := $(SOURCES:$(SRCDIR)/%.cpp=$(OBJDIR)/%.o)

$(BINDIR)/$(TARGET): $(OBJECTS)
	    @$(LINKER) $@ $(LFLAGS) $(OBJECTS)
	        @echo "Linking complete!"

$(OBJECTS): $(OBJDIR)/%.o : $(SRCDIR)/%.cpp
	    @$(CC) $(CFLAGS) $< -o $@
	        @echo "Compiled "$<" successfully!"

.PHONEY: clean
clean:
	    @$(rm) $(OBJECTS)
	        @echo "Cleanup complete!"

.PHONEY: remove
remove: clean
	    @$(rm) $(BINDIR)/$(TARGET)
	        @echo "Executable removed!"

