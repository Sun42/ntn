/*
** affine_list.c for ntn in /u/all/sundas_c/cu/public/ntn/ntn2
** 
** Made by christophe sundas
** Login   <sundas_c@epitech.net>
** 
** Started on  Sun Dec  7 02:55:13 2008 christophe sundas
** Last update Sun Dec  7 21:32:05 2008 christophe sundas
*/

#include <stdlib.h>
#include "my.h"
#include "ntn.h"

/*
**  Affine la liste en gerant certaine exceptions FR
*/
void	affine_list(t_list **my_list)
{
  affine_mille(my_list);
  affine_cents(my_list);
  affine_unit_val(my_list);
  epur_list(my_list);
}

/*
** remove les " " en trop en fin de liste
** gere le cas " 1000" useless
*/
void		epur_list(t_list **my_list)
{
  int		size;
  int		zero;
  char		*tmp;
  t_list	*begin;
  
  zero = 0;
  size = my_list_size(*my_list) - 1;
  while (my_strcmp(find_at(my_list, size), " ") == 0)
    {
      *my_list = remove_at(my_list , size, &zero);
      size--;
    }
  if (my_list_size(*my_list) == 1)
    if (my_strcmp(find_at(my_list, size), " mille") == 0)
      {
	begin = *my_list;
	tmp = begin->data;
	begin->data = my_strdup("mille");
	free(tmp);
      }
}

/*
** Retourne la data de la liste chainee a un indice donne
*/
char	*find_at(t_list **my_list, int indice)
{
  int		i;
  t_list	*begin;
  
  begin = *my_list;
  i= 0 ;
  if (indice < 0)
    return (NULL);
  else
    {
      while (i < indice)
	{
	  begin = begin->next;
	  i++;
	}
      return (begin->data);
    }
}

/*
** return vrai si la chaine en param est un multiplicateur de 100
** soit si elle fait partie du tableau des unites 
*/
int	is_multiplicate(char *num)
{
  int	i;
  
  i = 0;
  if (num == NULL)
    return (0);
  while (tab_unit[i] != 0)
    {
      if (my_strcmp(tab_unit[i], num) == 0)
	return (1);
      i++;
    }
  return (0);
}
