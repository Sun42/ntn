/*
** display_centaine.c for ntn in /u/all/roth_s/cu/public/rush
** 
** Made by sebastien roth
** Login   <roth_s@epitech.net>
** 
** Started on  Sat Dec  6 14:50:28 2008 sebastien roth
** Last update Sun Dec  7 22:02:27 2008 christophe sundas
*/

#include "my.h"
#include "ntn.h"

void	display_centaine_en(char *str, t_list **my_list)
{
  if ((*str) == '0')
    return ;
  my_put_in_list2(my_list, tab_unit_en[*str - '0']);
  my_put_in_list2(my_list, " ");
  my_put_in_list2(my_list, tab_unit_val_en[3]);
  if ((*(str + 1) != '0') || (*(str + 2) != '0'))
    my_put_in_list2(my_list, " and ");
}
