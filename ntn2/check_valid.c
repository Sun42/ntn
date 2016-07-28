/*
** checl_valid.c for ntn in /u/all/roth_s/cu/public/rush
** 
** Made by sebastien roth
** Login   <roth_s@epitech.net>
** 
** Started on  Sat Dec  6 14:53:16 2008 sebastien roth
** Last update Sun Dec  7 21:58:18 2008 christophe sundas
*/

#include <stdlib.h>
#include "my.h"
#include "ntn.h"
#include "bistromathique.h"

char	*parse_op(char *str)
{
  char	*epured;
  char	*res;
  
  epured = epur_zero(str);
  if (check_valid0(epured) == 0)
    {
      my_putstr_error("Chaine invalide\n");
      exit(-1);
    }
  res = eval_expr("0123456789", "()+-*/%", epured, my_strlen(epured));
  if (is_integer(res) == 0)
    {
      my_putstr_error("Chaine invalide\n");
      exit(-1);
    }
  return (res);
}

/*
** check si superieur a un int
*/
int	is_integer(char *str)
{
  int	len;
  
  if (*str == '-')
    str++;
  if (*str == '\0')
    exit(0);
  len = my_strlen(str);
  if (len <= 10)
    return (1);
  else
    return (0);
}

/*
** check valid avant le parsing et calcul
*/
int	check_valid0(char *str)
{
  while (*str)
    {
      if ((*str != '-') && (!(is_num(*str))))
	return(0);
      str++;
    }
  return (1);
}

/*
** chekc valid apres le parsing + calcul effectue
*/
int	check_valid(char *str)
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
