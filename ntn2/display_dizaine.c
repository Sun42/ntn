/*
** display_dizaine.c for ntn in /u/all/roth_s/cu/public/rush
** 
** Made by sebastien roth
** Login   <roth_s@epitech.net>
** 
** Started on  Sat Dec  6 14:49:48 2008 sebastien roth
** Last update Sun Dec  7 02:59:46 2008 sebastien roth
*/

#include "my.h"
#include "ntn.h"

int	display_sep(char *str, t_list **my_list)
{
  if ((*str != '8') && (*(str + 1) == '0'))
    {
      if (*str == '7' || *str == '9')
	my_put_in_list2(my_list, " ");
      return (1);
    }
  if ((*str == '8') && (*(str + 1) == '0'))
    {
      my_put_in_list2(my_list, "s");
      return (1);
    }
  if (*(str + 1) == '1' && (*str != '8') && (*str != '9'))
    my_put_in_list2(my_list, " et ");
  else
    my_put_in_list2(my_list, "-");
  return (0);
}

int	display_dizaine(char *str, t_list **my_list)
{
  if (*str == '0' && (*(str + 1) == '0'))
    return (1);
  if (*str == '0')
    return (0);
  if (*str == '1' || *str == '7' || *str == '9')
    {
      my_put_in_list2(my_list, tab_dizaine[*str - '0']);
      if (*str != '1')
	display_sep(str, my_list);
      my_put_in_list2(my_list, tab_unit[*(str + 1) - '0' + 10]);
      return (1);
    }
  if (((*str >= '2') && (*str <= '6')) || (*str == '8'))
    my_put_in_list2(my_list, tab_dizaine[*str - '0']);
  return (display_sep(str, my_list));
}
