CC = cc
CFLAGS = 

SERVER = server
CLIENT = client

SRC_SER = src/server.c src/utils.c
SRC_CLI = src/client.c src/utils.c

OBJ_SER = $(SRC_SER:.c=.o)
OBJ_CLI = $(SRC_CLI:.c=.o)


all: $(SERVER) $(CLIENT)

$(SERVER): $(OBJ_SER)
	$(CC) $(CFLAGS) $(OBJ_SER) -o $(SERVER)

$(CLIENT): $(OBJ_CLI)
	$(CC) $(CFLAGS) $(OBJ_CLI) -o $(CLIENT)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ_SER) $(OBJ_CLI)

fclean: clean
	rm -f $(SERVER) $(CLIENT)

re: fclean all

.PHONY: clean