NAME = push_swap
Checker = checker
CC = cc
CFLAGS = -Wall -Werror -Wextra
SRC = utils/lstutils.c \
utils/lstutils2.c \
utils/ft_split.c \
utils/utils.c \
acions/actionbackend.c \
acions/actions_swap_push.c \
acions/actions_rotate.c \
acions/actions_reverse_rotate.c \
initialization/initstack.c \
push_swap.c \
sorts/sortingalgo.c \
sorts/initialsort.c \
sorts/sortingalgo_utils.c

BONUSSRC = initialization/initstack.c \
checker_src/checker.c \
utils/utils.c \
utils/ft_split.c \
utils/lstutils.c \
utils/lstutils2.c \
acions/actionbackend.c \
checker_src/actions_reverse_rotate_bonus.c \
checker_src/actions_rotate_bonus.c \
checker_src/actions_swap_push_bonus.c \
get_next_line/get_next_line_utils.c \
get_next_line/get_next_line.c

all : $(NAME)

$(NAME) : $(SRC) push_swap.h

bonus : $(Checker)

$(Checker) : $(BONUSSRC) push_swap.h get_next_line/get_next_line.h
	$(CC) $(CFLAGS) $^ -o $(Checker)

clean:
	rm -f $(NAME)

bonusclean:
	rm -f $(Checker)

fclean: clean bonusclean

re: clean all

bonusre: bonusclean bonus

fre: re bonusre 

.PHONY: all clean fclean re bonusclean bonusre fre