/*
** affine_mille.c for ntn.h in /u/all/sundas_c/cu/public/ntn/ntn2
** 
** Made by christophe sundas
** Login   <sundas_c@epitech.net>
** 
** Started on  Sun Dec  7 07:35:30 2008 christophe sundas
** Last update Sun Dec  7 21:34:17 2008 christophe sundas
*/

#include <stdlib.h>
#include "my.h"
#include "ntn.h"

/*
** gere le cas du un mille
*/
void		affine_mille(t_list **my_list)
{
  t_list	*begin;
  int		cpt;
  int		zero;

  zero = 0;
  cpt = 0;
  begin = *my_list;
  while (begin->next != 0)
    {
      if (are_close_un_mil(begin) && need_to_affine_mil(find_at(my_list, cpt - 2)))
        {
	  *my_list = remove_at(my_list, cpt, &zero);
	  zero = 0;
	  *my_list = remove_at(my_list, cpt - 1, &zero);
	  zero = 0;
	}
      begin = begin->next;
      cpt++;
    }
}

t_list		*remove_at(t_list **begin, int indice, int *cpt)
{
  t_list	*tmp;
  t_list	*prev;
  t_list	*save;

  tmp = *begin;
  prev = tmp;
  while (*cpt == indice)
    {
      save = (*begin)->next;
      (*begin) = save;
      *cpt = (*cpt) + 1;
    }
  while (tmp != 0)
    {
      if (*cpt == indice)
	{
          prev->next = tmp->next;
          free(tmp);
	}
      prev = ((*cpt) == (indice) ? (prev) : (tmp));
      tmp = (*tmp).next;
      *cpt = (*cpt) + 1;
    }
  return (*begin);
}


int		are_close_un_mil(t_list *begin)
{
  char		*tmp1;
  char		*tmp2;
  

  tmp1 = begin->data;
  tmp2 = begin->next->data;
  
  while (*tmp2 == ' ')
    tmp2++;
  if (my_strcmp(tmp1, tab_unit[1]) == 0)
    if (my_strcmp(tmp2, tab_unit_val[2]) == 0)
      return (1);
  return (0);
}

/*
** si milion ou milliard ou null => need to remove 'un mille'
*/
int	need_to_affine_mil(char *str)
{
  if (str == NULL)
    return (1);
  while (*str == ' ')
    str++;
  if (my_strcmp(str, tab_unit_val[0]) == 0)
    return (1);
  if (my_strcmp(str, tab_unit_val[1]) == 0)
    return (1);
  return (0);
}
