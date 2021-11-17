# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mmateo-t <mmateo-t@student.42madrid>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/06/24 16:04:19 by user42            #+#    #+#              #
#    Updated: 2021/11/17 10:19:53 by mmateo-t         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#AUTHOR mmateo-t
#USAGE

#make          #compile all binary
#make clean		#remove all binaries
#make fclean		#remove all binaries and executable

SRCS_DIR:= srcs/
SRCS := $(wildcard $(SRCS_DIR)*.c)
OBJS := $(SRCS:%.c=%.o)
NAME:= philo
CC:= cc
CFLAGS:= -Wall -Werror -Wextra
THREADF:= -pthread
RM :=	rm -rvf
DEBUG_FLAG:= -g

all:	$(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(THREADF) $(OBJS) -o $(NAME)

$(%.o): $(%.c)
		$(CC) -c $^ -o $@
		@echo "Creating objects"

clean:
		@echo "Removing objects"
		$(RM) $(OBJS)

fclean:
		make clean
		$(RM) $(NAME)
msg:

re:
	make fclean all
	@echo "All files has been deleted and recompiled"

.PHONY: clean fclean all re objects msg
