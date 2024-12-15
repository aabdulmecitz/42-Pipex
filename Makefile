NAME			= pipex
NAME_BONUS		= pipex_bonus

GREEN			= \033[0;32m
RED				= \033[0;31m
RESET			= \033[0m

LIBFT 			= lib/libft/libft.a

CC 				= cc

STANDARD_FLAGS 	= -Wall -Werror -Wextra

VALGRIND		= @valgrind --leak-check=full --show-leak-kinds=all \
--track-origins=yes --quiet --tool=memcheck --keep-debuginfo=yes

REMOVE 			= rm -f

SRCS_DIR		= ./src/

SRCS 			= $(addprefix $(SRCS_DIR),\
				error_msg.c pipex.c utils.c)

BONUS_SRC		= $(addprefix $(SRCS_DIR),\
				error_msg.c pipex_bonus.c utils.c)

all:			${NAME} ${LIBFT} 
all_bonus:		${NAME_BONUS} ${LIBFT} 

${NAME}: 		
				${CC} ${SRCS} ${LIBFT} -g -o ${NAME}
				@echo "$(NAME): $(GREEN)$(NAME) was compiled.$(RESET)"
				@echo

${NAME_BONUS}: 		
				${CC} ${BONUS_SRC} ${LIBFT} -g -o ${NAME_BONUS}
				@echo "$(NAME_BONUS): $(GREEN)$(NAME_BONUS) was compiled.$(RESET)"
				@echo

${LIBFT}:
				@echo
				make bonus -C lib/libft

clean:
				make clean -C lib/libft
				@echo

fclean:
				${REMOVE} ${NAME} ${NAME_BONUS}
				@echo "${NAME}: ${RED}${NAME} and ${NAME_BONUS} were deleted${RESET}"
				@echo
push:
	git add .
	git commit -m "commit"
	git push

re:				fclean all

re_bonus:		fclean all_bonus

compile_libs:
	@make -sC lib/libft
	@make clean -sC lib/libft


update:
	git submodule update --init --recursive --remote

run:			re
				./${NAME} txt1.txt "ls -l" "wc -l" txt2.txt

run_bonus:		re_bonus
				./${NAME_BONUS} txt1.txt "ls -l"  "grep *.txt"  "wc -l" txt2.txt

run_bonus_here_doc:		re_bonus
				./${NAME_BONUS} txt1.txt here_doc LIMITER "ls -l"  "grep *.txt"  "wc -l" txt2.txt

run_bonus:		re_bonus
				./${NAME_BONUS} txt1.txt "ls -l"  "grep *.txt"  "wc -l" txt2.txt

valgrind: $(NAME)
	$(VALGRIND) ./${NAME}


.PHONY:			all clean fclean re rebonus valgrind run run_bonus makefile
