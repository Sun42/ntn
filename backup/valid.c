/*
** valid.c for ntn in /u/all/sundas_c/cu/public/ntn
** 
** Made by christophe sundas
** Login   <sundas_c@epitech.net>
** 
** Started on  Sat Dec  6 00:14:26 2008 christophe sundas
** Last update Sat Dec  6 03:29:57 2008 christophe sundas
*/

#include "my.h"
#include "my_printf.h"
#include "ntn.h"

int     check_valid(char *str)
{
  if ((*str != '-') && (!(is_num(*str))))
    return(0);
  str++;
  while (*str)
    {
      if (!(is_num(*str)))
        return (0);
      str++;
    }
  return (1);
}

int     is_num(char c)
{
  if ((c >= '0') && (c <= '9'))
    return (1);
  return (0);
}
