CC = gcc
CFLAGS = -Wall -g -O3
LDFLAGS =
SRC_DIR = src
BIN_DIR = bin
HDR_DIR = include
LIB_DIR = lib

# Source, header, and object files
SRC   = $(wildcard $(SRC_DIR)/*.c)
HDR   = $(wildcard $(HDR_DIR)/*.h)
OBJ   = $(addprefix $(BIN_DIR)/, $(notdir $(SRC:.c=.o)))

# Target file
TARGET = $(LIB_DIR)/lib.so

.PHONY: all clean

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CC) -shared -o $@ $^ $(LDFLAGS)

# Rule to compile any C file in the "src" directory into the "bin" directory
$(BIN_DIR)/%.o: $(SRC_DIR)/%.c
	$(CC) $(CFLAGS) -I$(HDR_DIR) -c -o $@ $<

clean:
	rm -f $(BIN_DIR)/*.o $(TARGET)
