# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: njung <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/03/20 14:10:08 by njung             #+#    #+#              #
#    Updated: 2025/03/27 10:46:50 by njung            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME        = philosophers

CC            = cc
CFLAGS        = -Wall -Wextra -Werror -pthread
RM            = rm -f

INCLUDES    = -I./include

SRCS_DIR    = srcs/
SRCS        = main.c parsing.c parsing2.c utils.c init.c 
SRCS_PATH    = $(addprefix $(SRCS_DIR), $(SRCS))

OBJS        = $(SRCS_PATH:.c=.o)

all:        $(NAME)

$(NAME):    $(OBJS)
			$(CC) $(CFLAGS) $(OBJS) $(INCLUDES) -o $(NAME)
			@echo "$(NAME) created!"

%.o:        %.c
			$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
			$(RM) $(OBJS)
			@echo "Objects removed!"

fclean:		clean
			$(RM) $(NAME)
			@echo "$(NAME) removed!"

re:            fclean all

.PHONY:        all clean fclean re