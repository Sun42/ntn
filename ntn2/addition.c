/*
** addition.c for bistro in /u/all/sundas_c/cu/rendu/piscine/bistro/version0911
** 
** Made by christophe sundas
** Login   <sundas_c@epitech.net>
** 
** Started on  Mon Nov  3 21:53:38 2008 christophe sundas
** Last update Sun Dec  7 21:28:45 2008 christophe sundas
*/

#include <stdlib.h>
#include "my.h"
#include "bistromathique.h"

char	*addition(char *base, char *expr1, char *expr2)
{
  my_revstr(expr1);
  my_revstr(expr2);

  if (my_strlen(expr1) >= my_strlen(expr2))
    {
      return (add(base, expr1, expr2));
    }
  else
    return (add(base, expr2, expr1));
}

char	*add(char *base, char *expr1, char *expr2)
{
  char	*strfin;
  int	retenu;
  int	i;
  int	res;
  
  if ((strfin = malloc(sizeof(*strfin) * (my_strlen(expr1) + 2))) == NULL)
    exit(-1);
  i = 0;
  retenu = 0;
  while (expr1[i] != '\0')
    {
      res = (indice_in_base(base, expr1[i]) + if_exist_expr2(base, expr2, i) + retenu);
      check_retenu(base, &res, &retenu);
      strfin[i] = base[res];
      i = i + 1;
    }
  check_ending_zero(base, retenu, &i, strfin);
  if (retenu == 1)
    {
      strfin[i] = base[retenu];
      i = i + 1;
    }
  strfin[i] = '\0';
  my_revstr(strfin);
  return (strfin);
}

void	check_ending_zero(char *base, int retenu, int *i, char *stringfinale)
{
  if (retenu == 0)
    {
      while ((*i > 1) && (indice_in_base(base, stringfinale[*i - 1]) == 0))
        {
          *i = *i - 1;
        }
    }
}

int	if_exist_expr2(char *base,char *expr2, int i)
{
  if (i < my_strlen(expr2))
    return (indice_in_base(base, expr2[i]));
  return (0);
}

void	check_retenu(char *base, int *res, int *retenu)
{
  if (*res >= my_strlen(base))
    {
      *retenu = 1;
      *res = *res - my_strlen(base);
    }
  else
    {
      *retenu = 0;
    }
}
