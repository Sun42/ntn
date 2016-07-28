/*
** bistro//evalexpr  in /u/all/sundas_c/cu/rendu/piscine/bistro
** 
** Made by christophe sundas
** Login   <sundas_c@epitech.net>
** 
** Started on  Tue Oct 21 01:27:19 2008 christophe sundas
** Last update Sun Dec  7 22:15:03 2008 christophe sundas
*/

#include <stdlib.h>
#include "my.h"
#include "bistromathique.h"

char		*eval_expr(char *base, char *operators, char *expr, int size)
{
  char		**tabexpr;
  t_list	*op;
  t_list	*nb;
  int		i;
  
  size = size;
  tabexpr = str_to_tab_string(base, expr, operators);
  op = 0;
  nb = 0;
  i = 0;
  while (tabexpr[i] != 0)
    {
      if (is_open_parent(operators, tabexpr[i]) == 1)
	my_put_in_list(&nb, parenthesis_mode(base, operators, &i, tabexpr));
      if (is_num2(base, operators, tabexpr[i]) == 1)
	my_put_in_list(&nb, tabexpr[i]);
      if (is_low_op(operators, tabexpr[i]) == 1)
	my_put_in_list(&op, tabexpr[i]);
      if (is_high_op(operators, tabexpr[i]) == 1)
	resolv(base, operators, &i, tabexpr, &op, &nb);
      i = i + 1;
    }
  return (depile_all(base, operators, op, nb));
}

void	resolv(char *base, char *ops, int *i, char **tab, t_list **op, t_list **nb)
{
  char		*expr1;
  char		*operator;
  char		*expr2;
  
  my_put_in_list(op, tab[*i]);
  *i = *i + 1;
  if (is_num2(base, ops, tab[*i]) == 1)
    my_put_in_list(nb, tab[*i]);
  if (is_open_parent(ops, tab[*i]) == 1)
    my_put_in_list(nb, parenthesis_mode(base, ops, i, tab));
  if (is_low_op(ops, tab[*i]))
    my_put_in_list(nb, check_sp_low(base, ops, i, tab));
  expr2 = (*nb)->data;
  depile(nb);
  operator = (*op)->data;
  depile(op);
  expr1 = (*nb)->data;
  depile(nb);
  my_put_in_list(nb, operations(base, ops, expr1, operator, expr2));
}

char	*check_sp_low(char *ba, char *opers, int *i, char **tabexpr)
{
  char	*tmp;
  
  if (is_plus_op(opers, tabexpr[*i]))
    {
      *i = *i + 1;
      tmp = parenthesis_mode(ba, opers, i, tabexpr);
    }
  if (is_sub_op(opers, tabexpr[*i]))
    {
      *i = *i + 1;
      tmp = ajoute_moins(ba, opers, parenthesis_mode(ba, opers, i, tabexpr));
    }
  return (clean_it_with_numbers(ba, opers, tmp));
}

char	*depile_all(char *base, char *operators, t_list *op, t_list *nb)
{
  char	*operator;
  char	*expr1;
  char	*expr2;
 
  if (my_list_size(op) > 0)
    {
      my_rev_list(&op);
      my_rev_list(&nb);
    }
  while (my_list_size(op) > 0)
    {
      operator = op->data;
      depile(&op);
      expr1 = nb->data;
      depile(&nb);
      if (my_list_size(nb) == 0)
	return (special_case_one_expr_only(base, operators, expr1, operator));
      expr2 = nb->data;
      depile(&nb);
      my_put_in_list(&nb, operations(base, operators, expr1, operator, expr2));
  }
  return (nb->data);
}

char	*special_case_one_expr_only(char *ba, char *ops, char *expr1, char *opera)
{
  char	fake_zero[2];

  fake_zero[0] = ba[0];
  fake_zero[1] = '\0';
  return (operations(ba, ops, fake_zero, opera, expr1));
}
