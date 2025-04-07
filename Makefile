# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: njung <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/03/20 14:10:08 by njung             #+#    #+#              #
#    Updated: 2025/04/07 15:31:31 by njung            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME        = philo

CC            = cc
CFLAGS        = -Wall -Wextra -Werror -pthread
RM            = rm -f

INCLUDES    = -I./include

SRCS_DIR    = srcs/
SRCS        = main.c parsing.c parsing2.c utils.c init.c routine.c utils2.c routine2.c check_philos.c
SRCS_PATH    = $(addprefix $(SRCS_DIR), $(SRCS))

OBJS        = $(SRCS_PATH:.c=.o)

all:        $(NAME)

$(NAME):    $(OBJS)
			$(CC) $(CFLAGS) $(OBJS) $(INCLUDES) -o $(NAME)
			@echo "./$(NAME) is now available to use!"
			@echo "\033[1;33m"
			@echo "██████╗ ██╗  ██╗██╗██╗      ██████╗ "
			@echo "██╔══██╗██║  ██║██║██║     ██╔═══██╗"
			@echo "██████╔╝███████║██║██║     ██║   ██║"
			@echo "██╔═══╝ ██╔══██║██║██║     ██║   ██║"
			@echo "██║     ██║  ██║██║███████╗╚██████╔╝"
			@echo "╚═╝     ╚═╝  ╚═╝╚═╝╚══════╝ ╚═════╝ "
			@echo "\033[0m"

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