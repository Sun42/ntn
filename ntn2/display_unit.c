/*
** display_unit.c for ntn in /u/all/roth_s/cu/public/rush
** 
** Made by sebastien roth
** Login   <roth_s@epitech.net>
** 
** Started on  Sat Dec  6 14:49:18 2008 sebastien roth
** Last update Sun Dec  7 01:24:12 2008 christophe sundas
*/

#include "my.h"
#include "ntn.h"

void	display_unit(char *str, t_list **my_list)
{
  if (my_strlen(str) == 1)
    my_put_in_list2(my_list, tab_unit[*str - '0']);
}
