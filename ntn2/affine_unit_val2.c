/*
** affine_unit_val2.c for ntn.h in /u/all/sundas_c/cu/public/ntn/ntn2
** 
** Made by christophe sundas
** Login   <sundas_c@epitech.net>
** 
** Started on  Sun Dec  7 21:35:58 2008 christophe sundas
** Last update Sun Dec  7 21:48:25 2008 christophe sundas
*/

#include <stdlib.h>
#include "my.h"
#include "ntn.h"

int	is_in_tab_dizaine(char *str)
{
  int	i;
  int	len;

  i = 2;
  while (i < SIZEDIZAINE)
    {
      len = my_strlen(tab_dizaine[i]);
      if (my_strncmp(tab_dizaine[i], str, len) == 0)
        return (1);
      i++;
    }
  return (0);
}

int	is_in_tabunit(char *str)
{
  int	i;

  i = 2;
  while (i < SIZEUNIT)
    {
      if (my_strcmp(tab_unit[i], str) == 0)
        return (1);
      i++;
    }
  return (0);
}

int	is_in_tabunit_val(char *str)
{
  int	i;
  int	len;

  while (*str == ' ')
    str++;
  i = 0;
  while (i < SIZEUNITVAL)
    {
      len = my_strlen(tab_unit_val[i]);
      if (my_strncmp(tab_unit_val[i], str, len) == 0)
        return (1);
      i++;
    }
  return (0);
}
