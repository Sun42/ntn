NAME = ntn
SRC = 	main.c \
	valid.c \
	tab.c
CC = gcc
OBJ = $(SRC:.c=.o)
TMP = $(OBJ:.c=.c~)
CFLAGS += -ansi -pedantic -W -Wall -I. 
LIB = -L. -lmy_printf -lmy -lncurses -ltermcap
RM = rm -f

$(NAME) : $(OBJ) 
	$(CC) -o $(NAME) $(OBJ) $(LIB)

all : $(NAME)

clean : 
	$(RM) $(OBJ)

fclean : clean
	$(RM) $(TMP)
	$(RM) $(NAME)

re: fclean all


