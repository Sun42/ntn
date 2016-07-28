/*
** display_bloc.c for ntn in /u/all/roth_s/cu/public/rush
** 
** Made by sebastien roth
** Login   <roth_s@epitech.net>
** 
** Started on  Sat Dec  6 14:45:50 2008 sebastien roth
** Last update Sun Dec  7 21:59:22 2008 christophe sundas
*/

#include "my.h"
#include "ntn.h"

/*
** flag 0 => on display les unites
*/
void	display_bloc(char *str, t_list **my_list)
{
  int	flag;

  flag = 0;
  if (my_strlen(str) == 3)
    {
      display_centaine(str, my_list);
      str++;
    }
  if (my_strlen(str) == 2)
    {
      flag = display_dizaine(str, my_list);
      str++;
    }
  if (my_strlen(str) == 1)
    {
      if (flag == 0)
	display_unit(str, my_list);
      str++;
    }
}
