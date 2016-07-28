/*
** display_list_with_opt.c for ls in /u/all/sundas_c/cu/rendu/unix/projet/ntn
** 
** Made by christophe sundas
** Login   <sundas_c@epitech.net>
** 
** Started on  Thu Nov 13 20:05:17 2008 christophe sundas
** Last update Sun Dec  7 22:24:15 2008 christophe sundas
*/

#include <stdlib.h>
#include "my.h"
#include "ntn.h"

void	my_display_list_with_opt(t_list *list, int tabopt[])
{
  while (list != 0)
    {
      if (tabopt[BIG_M] == 1)
	my_putstr(str_to_upper(list->data));
      else if (tabopt[LITTLE_A] == 1)
	my_putstr(str_altern_upper(list->data, 1, 2));
      else if (tabopt[BIG_A] == 1)
	my_putstr(str_altern_upper(list->data, 0, 2));
      list = list->next;
    }
}
