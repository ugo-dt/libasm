# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ugdaniel <ugdaniel@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/05/03 12:55:59 by ugdaniel          #+#    #+#              #
#    Updated: 2021/05/07 13:07:55 by ugdaniel         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= libasm.a

SRCS		=	ft_strlen.s ft_strcpy.s ft_strcmp.s ft_write.s ft_read.s ft_strdup.s
SRCS_BONUS	= 	$(SRCS) ft_list_size.s
OBJS		=	$(SRCS:.s=.o)
OBJS_BONUS	=	$(SRCS_BONUS:.s=.o)

CC = nasm -felf64

.s.o:
	$(CC) $< -o $(<:.s=.o)

$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)

all: $(NAME)

bonus: fclean $(OBJS) $(OBJS_BONUS)
	ar rcs $(NAME) $(OBJ) $(OBJS_BONUS)

clean:
	rm -rf $(OBJS) $(OBJS_BONUS)

fclean: clean
	rm -rf $(NAME)

re: fclean all