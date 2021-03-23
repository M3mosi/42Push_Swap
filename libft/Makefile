# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dmalori <dmalori@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/01/18 09:44:39 by dmalori           #+#    #+#              #
#    Updated: 2021/03/23 14:30:38 by dmalori          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= libft.a

CC			= gcc

CFLAGS		= -Wall -Wextra -Werror -c

LIB			= ar -rc

RAN			= ranlib

SRCS		= 	ft_memset.c \
				ft_bzero.c \
				ft_memcpy.c \
				ft_memccpy.c \
				ft_memmove.c \
				ft_memchr.c \
				ft_memcmp.c \
				ft_strlen.c \
				ft_strlcpy.c \
				ft_strlcat.c \
				ft_strchr.c \
				ft_strrchr.c \
				ft_strnstr.c \
				ft_strncmp.c \
				ft_strcmp.c \
				ft_atoi.c \
				ft_isalpha.c \
				ft_isdigit.c \
				ft_isalnum.c \
				ft_isascii.c \
				ft_isprint.c \
				ft_toupper.c \
				ft_tolower.c \
				ft_calloc.c \
				ft_strdup.c \
				ft_substr.c \
				ft_strjoin.c \
				ft_strtrim.c \
				ft_split.c \
				ft_itoa.c \
				ft_strmapi.c \
				ft_putchar_fd.c \
				ft_putstr_fd.c \
				ft_putendl_fd.c \
				ft_putnbr_fd.c \
				ft_isspace.c \
				ft_lstnew.c \
				ft_lstadd_front.c \
				ft_lstsize.c \
				ft_lstlast.c \
				ft_lstadd_back.c \
				ft_lstdelone.c \
				ft_lstclear.c \
				ft_lstiter.c \
				ft_lstmap.c \
				ft_strncpy.c \
				ft_strndup.c \
				ft_strndupfill.c \
				ft_iscontain.c \
				ft_recalloc.c \
				ft_get_next_line.c \
				ft_atoi_abs.c \
				ft_core_digit.c \
				ft_core_minus.c \
				ft_core_point.c \
				ft_core_print.c \
				ft_core_star.c \
				ft_core_zero.c \
				ft_initflags.c \
				ft_isterminator.c \
				ft_itoa_base_unsigned_long.c \
				ft_itoa_base_unsigned.c \
				ft_itoa_base.c \
				ft_max.c \
				ft_min.c \
				ft_print_char.c \
				ft_print_decimal_neg.c \
				ft_print_decimal_unsigned.c \
				ft_print_decimal.c \
				ft_print_exa.c \
				ft_print_percent.c \
				ft_print_pointer_null.c \
				ft_print_pointer.c \
				ft_print_string.c \
				ft_print_zero.c \
				ft_printf.c \
				ft_putlchar.c \
				ft_putlstr.c \
				ft_toupperstr.c \
				ft_strnbr.c \
				ft_matrix_len.c \
				ft_free_matrix.c \
				ft_print_matrix.c \
				ft_init_array.c \
				ft_print_arrint.c \
				ft_arr_dup.c
				
OBJS		= ${SRCS:.c=.o}

RM			= rm -f

%.o:		%.c
			@${CC} ${CFLAGS} $<

$(NAME):	${OBJS}
			@echo "MAKE FTLIB"
			@${LIB} ${NAME} ${OBJS}
			@${RAN} ${NAME}
			@echo "FTLIB OK"

all:		${NAME}

clean:
			@${RM} ${OBJS}

fclean:		clean
			@echo "DELETE FTLIB"
			@${RM} ${NAME}

re:			fclean all

.PHONY:		all clean fclean re