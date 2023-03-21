# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gkhaishb <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/20 20:46:10 by gkhaishb          #+#    #+#              #
#    Updated: 2023/03/20 20:46:12 by gkhaishb         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# ###################COMMAND#############################
CC=cc
CFLAGS= -g -Wall -Wextra -Werror
RM = rm -f

# ###################PATH#############################
SRC_DIR = src
INCLUDE_DIR = include


SRCS_SE_bonus = server_bonus.c
SRCS_CL_bonus = client_bonus.c
OBJS_CL_bonus = $(SRCS_CL_bonus:.c=.o)
OBJS_SE_bonus = $(SRCS_SE_bonus:.c=.o)
SRCS_SE = server.c
SRCS_CL = client.c
OBJS_SE = $(SRCS_SE:.c=.o)
OBJS_CL = $(SRCS_CL:.c=.o)
SERVER = server
CLIENT = client
SERVER_BONUS = server_bonus
CLIENT_BONUS = client_bonus

# ################COLOR##############################
COLOR='\033[0;32m'
NC='\033[0m' # No Color
RE= '\033[0;34m'
RED='\033[0;31m'
# ###################################################
all: $(SERVER) $(CLIENT)


$(SERVER) : $(OBJS_SE)
	@ echo "Create "${RED}"SERVER"${NC}
	@ $(CC) $(CFLAGS) $(OBJS_SE) -o $(SERVER)

$(SERVER_BONUS) : $(OBJS_SE_bonus)
	@ echo "Create "${RED}"SERVER_BONUS"${NC}
	@ $(CC) $(CFLAGS) $(OBJS_SE_bonus) -o $(SERVER_BONUS)

$(CLIENT) : $(OBJS_CL)
	@ echo "Create "${RED}"CLIENT"${NC}
	@ $(CC) $(CFLAGS) $(OBJS_CL) -o $(CLIENT)
	
$(CLIENT_BONUS) : $(OBJS_CL_bonus)
	@ echo "Create "${RED}"CLIENT_BONUS"${NC}
	@ $(CC) $(CFLAGS) $(OBJS_CL_bonus) -o $(CLIENT_BONUS)

bonus: $(SERVER_BONUS) $(CLIENT_BONUS)
	
obj/%.o: %.c
	@ echo ${RE}"Making the $(notdir $@)"${NC}
	@ $(CC) $(CFLAGS) -c $< -o $@

clean : 
	@ rm -rf $(OBJS_SE) $(OBJS_CL) $(OBJS_CL_bonus) $(OBJS_SE_bonus)
	
fclean : clean
	@ rm -rf $(CLIENT) $(SERVER) $(SERVER_BONUS) $(CLIENT_BONUS)
	
re: fclean
	@ make all

.PHONY:			all clean fclean re bonus