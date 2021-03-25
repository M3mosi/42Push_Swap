NAME	=	push_swap
NAME_C	=	checker
CC		=	gcc #-pedantic -g
FT_DIR	=	libft
FT_LNK	=	-L ${FT_DIR} -lft
CFLAGS	=	-Wall -Wextra -Werror	
RM		=	rm -f
SRCS	=	pushswap.c \
			swap.c \
			swap2.c \
			swap3.c \
			algorithm.c \
			final_algo_start.c \
			final_algo.c \
			final_algo_utils.c \
			parsing.c \
			calcolo_distanza.c \
			final_algo_bis.c \
			final_algo_tris.c \
			parsing2.c \
			ricorsione.c \
			ricorsione2.c \
			rev_lis_cmp.c \

OBJ		=	$(SRCS:.c=.o)

%.o 	:	%.c
			@$(CC) $(CFLAGS) -c $< -o $@

$(NAME)	:	$(OBJ)
			@echo "MAKE START"
			@make -C ${FT_DIR}
			@$(CC) $(CFLAGS) -I $(FT_DIR) $(OBJ) $(FT_LNK) -o $(NAME) 
			@echo "DONE"

$(NAME_C):	$(NAME)
			@make -C checker_folder
			@mv checker_folder/checker ./

all		:	$(NAME)

clean	:
			@echo "DELETE START"
			@$(RM) *.txt
			@$(RM) $(OBJ)
			@make clean -C $(FT_DIR)
			@make clean -C checker_folder

fclean	:	clean
			@$(RM) $(NAME)
			@$(RM) $(NAME_C)
			@make fclean -C $(FT_DIR)
			@make fclean -C checker_folder

re		:	fclean all

run		:	$(NAME) $(NAME_C)
			@./test.sh $(filter-out $@,$(MAKECMDGOALS))

runv	:	$(NAME) $(NAME_C)
			@./testv.sh $(filter-out $@,$(MAKECMDGOALS))

push	:	fclean
			git add .
			git commit -m "$(filter-out $@,$(MAKECMDGOALS))"
			git push

.PHONY		:	all clean fclean re run
