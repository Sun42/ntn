/*
** affine_unit_val.c for ntn.h in /u/all/sundas_c/cu/public/ntn/ntn2
** 
** Made by christophe sundas
** Login   <sundas_c@epitech.net>
** 
** Started on  Sun Dec  7 05:09:08 2008 christophe sundas
** Last update Sun Dec  7 21:46:43 2008 christophe sundas
*/

#include <stdlib.h>
#include "my.h"
#include "ntn.h"

/*
** Ajoute les eventuels s a millard ou millions
*/
void		affine_unit_val(t_list **my_list)
{
  t_list	*begin;
  int		cpt;
  int		flag;
  int		is_plur;
  char		*tmp;

  cpt = 0;
  begin = *my_list;
  while (begin != 0)
    {
      is_plur = is_plurial(find_at(my_list, cpt - 1));
      flag = is_unitval_variable(begin->data);
      if (is_plur && flag)
	{
	  tmp = begin->data;
	  begin->data = my_strdup(tab_unit_vals[flag - 1]);
	  free(tmp);
	  is_plur = 0;
	  flag = 0;
	}
      begin = begin->next;
      cpt++;
    }
}

int	is_plurial(char *str)
{
  if (str == NULL)
    return (0);
  if (is_in_tabunit_val(str) == 1)
    return (1);
  if (is_in_tabunit(str) == 1)
    return (1);
  if (is_in_tab_dizaine(str) == 1)
    return (1);
  return (0);
}

/*
** vrai si le char en param == million ou millard 2 si million 1 si milliards 
*/
int	is_unitval_variable(char *str)
{
  while (*str == ' ')
    str++;
  if (my_strcmp(str, tab_unit_val[0]) == 0)
    return (1);
  if (my_strcmp(str, tab_unit_val[1]) == 0)
    return (2);
  return (0);
}
