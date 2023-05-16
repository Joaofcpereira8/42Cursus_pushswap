# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jofilipe <jofilipe@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/23 15:03:56 by jofilipe          #+#    #+#              #
#    Updated: 2023/03/24 12:10:34 by jofilipe         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap.a

CC = cc -g
CFLAGS = -Wall -Wextra -Werror -g
RM = rm -rf

LIBFT = libft/libft.a

SRCS = mandatory/main.c \
		mandatory/utils.c \
		mandatory/utils2.c \
		mandatory/utils3.c \
		mandatory/utils4.c \
		mandatory/sorts.c \
		mandatory/sort_main.c \
		mandatory/checkers.c \
		mandatory/operations1.c \
		mandatory/operations2.c \


OBJS = $(SRCS:%.c=%.o)

all: $(NAME)

$(LIBFT):
	@$(MAKE) -C ./libft

$(NAME): $(OBJS) $(LIBFT)
	@$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -o push_swap

clean:
	@$(MAKE) clean -C ./libft
	@$(RM) $(OBJS)

fclean: clean
	@$(MAKE) fclean -C ./libft
	@$(RM) $(NAME) push_swap

re: fclean all
