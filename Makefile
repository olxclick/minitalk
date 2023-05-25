# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jbranco- <jbranco-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/21 15:51:17 by jbranco-          #+#    #+#              #
#    Updated: 2023/01/27 16:23:28 by jbranco-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SERVER = server.c
CLIENT = client.c
SERVER_BONUS = server_bonus.c
CLIENT_BONUS = client_bonus.c
HELPERS = helpers.c

SERVEROBJ = $(SERVER:.c=.o)
CLIENTOBJ = $(CLIENT:.c=.o)
SERVEROBJ_BONUS = $(SERVER_BONUS:.c=.o)
CLIENTOBJ_BONUS = $(CLIENT_BONUS:.c=.o)
HELPERSOBJ = $(HELPERS:.c=.o)

CC = gcc
CFLAGS = -Wall -Wextra -Werror

all: server client

server: $(SERVEROBJ) $(HELPERSOBJ)
	$(CC) $(SERVEROBJ) $(HELPERSOBJ) -o server 
	
client: $(CLIENTOBJ) $(HELPERSOBJ)
	$(CC) $(CLIENTOBJ) $(HELPERSOBJ) -o client

bonus: $(SERVEROBJ_BONUS) $(CLIENTOBJ_BONUS) $(HELPERS:.c=.o)
	$(CC) $(CLIENTOBJ_BONUS) $(HELPERSOBJ) -o client
	$(CC) $(SERVEROBJ_BONUS) $(HELPERSOBJ) -o server

clean: 
	rm $(SERVEROBJ) $(CLIENTOBJ) $(CLIENTOBJ_BONUS) $(SERVEROBJ_BONUS) $(HELPERSOBJ)

fclean: clean
	rm server client

re: fclean all
