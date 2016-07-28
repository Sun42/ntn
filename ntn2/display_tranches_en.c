/*
** display_tranches_en.c for ntn in /u/all/sundas_c/public/ntn/ntn2
** 
** Made by sebastien roth
** Login   <roth_s@epitech.net>
** 
** Started on  Sun Dec  7 02:17:26 2008 sebastien roth
** Last update Sun Dec  7 22:05:47 2008 christophe sundas
*/

#include <stdlib.h>
#include <stdio.h>
#include "my.h"
#include "ntn.h"

/*
** parse la string complete
*/
t_list		*display_tranches_en(char *str)
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
      my_put_in_list2(&my_list, tab_min[ENG]);
      str++;
    }
  while (*str)
    {
      if (flag_spc == 1)
	my_put_in_list2(&my_list, " ");
      cpt = nb_to_take(str);
      mk_bloc(str, tab_str, cpt);
      display_bloc_en(tab_str, &my_list);
      display_unit_val_en(str, &my_list);
      if (!flag_spc)
	flag_spc = 1;
      str += cpt;
    }
  return (my_list);
}

/*
** affiche les unite de valeur en focntion de la len str
*/
void	display_unit_val_en(char *str, t_list **my_list)
{
  int	i;

  if (str[0] == '0' && str[1] == '0' && str[2] == '0')
    return ;
  if ((i = my_strlen(str)) > 3 && i <= 6)
    my_put_in_list2(my_list, " thousand");
  if (i > 6 && i <= 9)
    my_put_in_list2(my_list, " million");
  if (i > 9)
    my_put_in_list2(my_list, " billion");
}
