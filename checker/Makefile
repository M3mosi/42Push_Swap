NAME	=	checker
CC		=	gcc #-pedantic -g
FT_DIR	=	../libft
FT_LNK	=	-L ${FT_DIR} -lft
#CFLAGS	=	-Wall -Wextra -Werror	
RM		=	rm -f
SRCS	=	checker.c \
			../swap.c \
			../swap2.c \
			../swap3.c \
			../algorithm.c \
			../final_algo_start.c \
			../final_algo.c \
			../final_algo_utils.c \
			../parsing.c \
			../calcolo_distanza.c \

OBJ		=	$(SRCS:.c=.o)

%.o 	:	%.c
			$(CC) $(CFLAGS) -c $< -o $@

$(NAME)	:	$(OBJ)
			make -C ${FT_DIR}
			$(CC) $(CFLAGS) -I $(FT_DIR) $(OBJ) $(FT_LNK) -o $(NAME) 

all		:	$(NAME)

clean	:
			$(RM) *.txt
			$(RM) $(OBJ)
			make clean -C $(FT_DIR)

fclean	:	clean
			$(RM) $(NAME)
			make fclean -C $(FT_DIR)

re		:	fclean all

run		:	$(NAME)
			./$(NAME)

.PHONY		:	all clean fclean re run
