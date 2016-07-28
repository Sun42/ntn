/*
** affine_cents.c for ntn in /u/all/sundas_c/cu/public/ntn/ntn2
** 
** Made by christophe sundas
** Login   <sundas_c@epitech.net>
** 
** Started on  Sun Dec  7 04:54:00 2008 christophe sundas
** Last update Sun Dec  7 21:31:04 2008 christophe sundas
*/

#include <stdlib.h>
#include "my.h"
#include "ntn.h"

/*
** Modifie la liste chainee, rrajoute les s a cent
*/
void		affine_cents(t_list **my_list)
{
  t_list	*begin;
  int		flag_plur;
  char		*tmp;
  int		cpt;
  int		is_mult;

  cpt = 0;
  flag_plur = 0;
  begin = *my_list;
  while (begin != 0)
    {
      is_mult = is_multiplicate(find_at(my_list, cpt - 2));
      flag_plur = (is_alone_cent(begin) && is_mult);
      if (flag_plur == 1)
        {
          tmp = begin->data;
          begin->data = my_strdup("cents");
          free(tmp);
          flag_plur = 0;
	}
      cpt++;
      begin = begin->next;
    }
}

/*
** vrai si le maillon est un "cent" sans rien derriere
*/
int	is_alone_cent(t_list *begin)
{
  if (my_strcmp(begin->data, tab_unit_val[3]) != 0)
    return (0);
  if (begin->next == 0)
    return (1);
  if (is_unitval_variable(begin->next->data) > 0)
    return (1);
  return (0);
}
