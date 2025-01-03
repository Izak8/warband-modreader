# Recommend to run this makefile using POSIX-compliant make utility such as
# pdpmake https://frippery.org/make/

.POSIX:
.SUFFIXES:
.PHONY: clean all

# C Compiler, use cc symlink by default
CC			= cc
CFLAGS 		= -std=c99 -Wall

# Basic Macros
BIN		= modreader
OBJ		= modreader.o context.o
SRC		= $(OBJ:%.o=%.c)
DEP		= $(OBJ:%.o=%.d)

all: $(BIN)

$(BIN): $(DEP) $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(BIN)

# Suffix rule for dependency files
.SUFFIXES: .d .c
.c.d:
	$(CC) -MM $< -o $@
# Suffix rule for objects
.SUFFIXES: .c .o
.c.o:
	$(CC) $(CFLAGS) -c $<

clean:
	rm -fr $(BIN)
	rm -fr $(OBJ)
	rm -fr $(DEP)

# FreeBSD Make seemingly does not remake on include lines for non-existent files
# The -include will ignore errors regarding non-existent files
-include $(DEP)