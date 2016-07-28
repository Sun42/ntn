/*
** ntn.h for ntn in /u/all/sundas_c/cu/rendu/unix/projet/ntn
** 
** Made by christophe sundas
** Login   <sundas_c@epitech.net>
** 
** Started on  Fri Dec  5 20:50:46 2008 christophe sundas
** Last update Sat Dec  6 03:34:44 2008 christophe sundas
*/

#ifndef __NTN_H__
# define __NTN_H__

#define CENT "cent"
#define MILLE "mille"
#define MILLION "million"
#define MILLIARD "milliard"


extern char *tab_unit[];
extern char *tab_dixaine[];


void	ntn(int ac, char **av);

/*
** validation
*/
int	check_valid(char *str);
int	is_num(char c);

/*
** bloc de 3
*/
void	display_bloc(char *str);

/*
** display_cent 1 du bloc
*/
void	display_centaine(char *str);
void	display_plural_cent(char *str);

/*
**dixaine 2 du bloc
*/
void	display_dixaine(char *str);

/*
**unit 3 du bloc
*/
void	display_unit(char *str);

#endif
