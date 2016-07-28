/*
** soustraction.c for bistro in /u/all/sundas_c/cu/rendu/piscine/bistro/version0911
** 
** Made by christophe sundas
** Login   <sundas_c@epitech.net>
** 
** Started on  Mon Nov  3 22:18:36 2008 christophe sundas
** Last update Sun Dec  7 22:42:20 2008 christophe sundas
*/

#include "my.h"
#include "bistromathique.h"
#include <stdlib.h>

char	*soustraction(char *base, char *operators, char *expr1, char *expr2)
{
  if (is_sup(base, expr1, expr2))
    {
      my_revstr(expr1);
      my_revstr(expr2);
      return (sub(base, operators, expr1, expr2, 0));
    }
  else
    {
      my_revstr(expr1);
      my_revstr(expr2);
      return (sub(base, operators, expr2, expr1, 1));
    }
} 

char	*sub(char *b, char *operators, char *max, char *min, int flagmin)
{
  int	i;
  char	*strfin;
  int	r;
  int	ifex;

  i = 0;
  r = 0;
  if ((strfin = malloc(sizeof(*strfin) * (my_strlen(max) + 2))) == 0)
    exit(-1);
  while (max[i] != '\0')
    {
      ifex = if_exist_exprmin(b, i, min);
      strfin[i] = calcul_res(b, indice_in_base(b, max[i]), ifex, &r);
      i = i + 1;
    }
  check_ending_zero(b, r, &i, strfin);
  check_flagmin(operators, strfin, &i, flagmin);
  strfin[i] = '\0';
  my_revstr(strfin);
  return (strfin);
}

void	check_flagmin(char *operators, char *stringfinale, int *i, int flagmin)
{
  if (flagmin == 1)
    {
      stringfinale[*i] = operators[OP_NEG_IDX];
      *i = *i + 1;
    }
}

int	if_exist_exprmin(char *base, int i, char *exprmin)
{
  if (i >= my_strlen(exprmin))
    return (0);
  else
    return (indice_in_base(base, exprmin[i]));
}

char	calcul_res(char *base, int nb1, int nb2, int *retenu)
{
  int	res;
  
  res = nb1 - (nb2 + *retenu);
  if (res < 0)
    {
      res = -res;
      res = my_strlen(base) - res;
      *retenu = 1;
    }
  else
    {
      *retenu = 0;
    }
  return (base[res]);
}
