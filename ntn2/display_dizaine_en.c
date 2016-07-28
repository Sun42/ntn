/*
** display_dizaine.c for ntn in /u/all/roth_s/cu/public/rush
** 
** Made by sebastien roth
** Login   <roth_s@epitech.net>
** 
** Started on  Sat Dec  6 14:49:48 2008 sebastien roth
** Last update Sun Dec  7 03:46:16 2008 sebastien roth
*/

#include "my.h"
#include "ntn.h"

int	display_sep_dizaine_en(char *str, t_list **my_list)
{
  if (*(str + 1) == '0')
    return (1);
  my_put_in_list2(my_list, "-");
  return (0);
}

int	display_dizaine_en(char *str, t_list **my_list)
{
  if (*str == '0' && (*(str + 1) == '0'))
    return (1);
  if (*str == '0' && (*str + 1) != '0')
    return (0);
  if (*str == '1')
    {
      my_put_in_list2(my_list, tab_dizaine_en[*str - '0']);
      if (*str != '1')
	display_sep_dizaine_en(str, my_list);
      my_put_in_list2(my_list, tab_unit_en[*(str + 1) - '0' + 10]);
      return (1);
    }
  if (*str >= '2')
    my_put_in_list2(my_list, tab_dizaine_en[*str - '0']);
  return (display_sep_dizaine_en(str, my_list));
}
