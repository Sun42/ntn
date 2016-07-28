/*
** display_tranches.c for ntn in /u/all/sundas_c/cu/public/ntn/ntn2
** 
** Made by christophe sundas
** Login   <sundas_c@epitech.net>
** 
** Started on  Sat Dec  6 21:51:58 2008 christophe sundas
** Last update Sun Dec  7 22:06:33 2008 christophe sundas
*/

#include <stdlib.h>
#include <stdio.h>
#include "my.h"
#include "ntn.h"

/*
** parse la string complete
*/
t_list		*display_tranches_vocfr(char *str)
{
  int		cpt;
  char		tab_str[4];
  int		flag_spc;
  t_list	*my_list;	

  my_list = 0;
  flag_spc = 0;
  cpt = 0;
  if (*str == '-')
    {
      player("moins.wav");
      str++;
    }
  while (*str)
    {
      if (flag_spc == 1)
	my_put_in_list2(&my_list, " ");
      cpt = nb_to_take(str);
      mk_bloc(str, tab_str, cpt);
      display_bloc_vocfr(tab_str);
      display_unit_val_vocfr(str);
      if (!flag_spc)
	flag_spc = 1;
      str += cpt;
    }
  return (my_list);
}

/*
** affiche les unite de valeur en focntion de la len str
*/
void	display_unit_val_vocfr(char *str)
{
  int	i;

  if (str[0] == '0' && str[1] == '0' && str[2] == '0')
    return ;
  if ((i = my_strlen(str)) > 3 && i <= 6)
    player("1000.wav");
  if (i > 6 && i <= 9)
    player("million.wav");
  if (i > 9)
    player("milliard.wav");
}
