/*
** epur_zero.c for ntn in /u/all/sundas_c/cu/public/ntn/ntn2
** 
** Made by christophe sundas
** Login   <sundas_c@epitech.net>
** 
** Started on  Sat Dec  6 22:57:34 2008 christophe sundas
** Last update Sun Dec  7 01:03:25 2008 christophe sundas
*/

#include "my.h"
#include "ntn.h"

char	*epur_zero(char *str)
{
  int	i;

  i = 0;
  while (str[i] && str[i] == '0' && str[i + 1])
    i++;
  return (str + i);
}
