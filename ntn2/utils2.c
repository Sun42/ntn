/*
** utils2.c for bistro in /u/all/sundas_c/cu/rendu/piscine/bistro/version0911
** 
** Made by christophe sundas
** Login   <sundas_c@epitech.net>
** 
** Started on  Mon Nov  3 22:21:24 2008 christophe sundas
** Last update Sun Dec  7 22:47:02 2008 christophe sundas
*/

#include "my.h"
#include "bistromathique.h"

int	is_open_parent(char *operators, char *expr_in_tab)
{
  int	len;
  
  len = my_strlen(expr_in_tab);
  if ((expr_in_tab[0] == operators[OP_OPEN_PARENT_IDX]) && (len == 1))
    return (1);
  return (0);
}

int	is_close_parent(char *operators, char *expr_in_tab)
{
  int	len;

  len = my_strlen(expr_in_tab);
  if ((expr_in_tab[0] == operators[OP_CLOSE_PARENT_IDX]) && (len == 1))
  return (1);
return (0);
}

int	is_num2(char *base, char *operators, char *expr_in_tab)
{
  int	len;

  len = my_strlen(expr_in_tab);
  if (is_nb_pure(base, operators, expr_in_tab))
    return (1);
  if ((expr_in_tab[0] == operators[OP_NEG_IDX]) && (len > 1))
    return (1);
  return (0);
}

int	is_low_op(char *operators, char *expr_in_tab)
{
  if (is_sub_op(operators, expr_in_tab) == 1)
    return (1);
  if (is_plus_op(operators, expr_in_tab) == 1)
    return (1);
  return (0);
}
