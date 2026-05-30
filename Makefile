CC = cc
CFLAGS = 

SERVER = server
CLIENT = client

SRC_SER = src/server.c
SRC_CLI = src/client.c

OBJ_SER = $(SRC_SER:.c=.o)
OBJ_CLI = $(SRC_CLI:.c=.o)

PRINTF = ft_printf/libftprintf.a

all: $(PRINTF) $(SERVER) $(CLIENT)

$(PRINTF):
	$(MAKE) -C ft_printf

$(SERVER): $(OBJ_SER) $(PRINTF)
	$(CC) $(CFLAGS) $(OBJ_SER) $(PRINTF) -o $(SERVER)

$(CLIENT): $(OBJ_CLI) $(PRINTF)
	$(CC) $(CFLAGS) $(OBJ_CLI) $(PRINTF) -o $(CLIENT)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(MAKE) -C ft_printf clean
	rm -f $(OBJ_SER) $(OBJ_CLI)

fclean: clean
	$(MAKE) -C ft_printf fclean
	rm -f $(SERVER) $(CLIENT)

re: fclean all

.PHONY: all clean fclean re