.POSIX:
.SUFFIXES:
.PHONY: clean all

# C Compiler, use cc symlink by default
CC			= cc
CFLAGS 		= -std=c99 -Wall

# Basic Macros
BIN		= msdecomp
OBJ		= msdecomp.o
SRC		= $(OBJ:%.o=%.c)
DEP		= $(OBJ:%.o=%.d)

all: $(BIN)

$(BIN): $(DEP) $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(BIN)

# Suffix-rules
.SUFFIXES: .d .c
.c.d:
	$(CC) -MM $< -o $@
.SUFFIXES: .c .o
.c.o:
	$(CC) $(CFLAGS) -c $<

clean:
	rm -fr $(BIN)
	rm -fr $(OBJ)
	rm -fr $(DEP)

# Make on BSD requires this for some reason
-include $(DEP)