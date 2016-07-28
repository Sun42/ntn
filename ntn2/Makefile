##
## Makefile for ntn in /u/all/sundas_c/public/ntn/ntn2
## 
## Made by sebastien roth
## Login   <roth_s@epitech.net>
## 
## Started on  Sun Dec  7 00:33:07 2008 sebastien roth
## Last update Sun Dec  7 21:54:51 2008 christophe sundas
##

NAME	=	ntn
SRC	=	main.c \
		display_tranches.c\
		display_tranches_en.c \
		display_tranches_vocfr.c \
		display_bloc.c \
		display_bloc_en.c \
		display_bloc_vocfr.c \
		display_unit.c \
		display_dizaine.c \
		display_centaine.c \
		display_unit_en.c \
		display_dizaine_en.c \
		display_centaine_en.c \
		display_unit_vocfr.c \
		display_dizaine_vocfr.c \
		display_centaine_vocfr.c \
		my_display_list_with_opt.c \
		check_valid.c \
		is_num.c \
		tab_nbr.c \
		tab_nbr_en.c \
		tab_nbr_vocfr.c \
		options.c \
		generic_list.c \
		epur_zero.c \
		affine_list.c \
		affine_cents.c \
		player.c \
		upper.c \
		affine_unit_val.c \
		affine_unit_val2.c \
		affine_mille.c \
		eval_expr.c \
		utils.c \
		utils2.c \
		utils3.c \
		utils4.c \
		utils_cleanstr.c \
		parenthesis_mode.c \
		format_expr.c \
		operations.c \
		operations2.c \
		addition.c \
		soustraction.c \
		multiplication.c \
		division.c \
		modulo.c
CC	=	gcc
OBJ	=	$(SRC:.c=.o)
TMP	= 	$(OBJ:.c=.c~)
CFLAGS	+=	-ansi -pedantic -W -Wall -I. 
LIB	=	-L. -lmy_`uname -m`-`uname -s`
RM	=	rm -f

$(NAME) : $(OBJ) 
	$(CC) -o $(NAME) $(OBJ) $(LIB)

all : $(NAME)

clean : 
	$(RM) $(OBJ)

fclean : clean
	$(RM) $(TMP)
	$(RM) $(NAME)

re: fclean all
