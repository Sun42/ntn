/*
** generic_list.c for ls in /u/all/sundas_c/cu/rendu/unix/projet/my_ls
** 
** Made by christophe sundas
** Login   <sundas_c@epitech.net>
** 
** Started on  Thu Nov 13 20:05:17 2008 christophe sundas
** Last update Sun Dec  7 22:21:09 2008 christophe sundas
*/

#include <stdlib.h>
#include "my.h"
#include "ntn.h"

/*
** free the list! :)
*/
void		my_free_list(t_list **begin)
{
  t_list	*tmp;
 
  while (*begin)
    {
      tmp = (*begin)->next;
      free((*begin)->data);
      free(*begin);
      *begin = tmp;
    }
}

void	my_display_list(t_list *list)
{
  while (list != 0)
    {
      my_putstr(list->data);
      list = list->next;
    }
}

void		my_put_in_list2(t_list **begin, char *data)
{
  t_list	*new_elem;

  if ((new_elem = malloc(sizeof(*new_elem))) == NULL)
    exit(-1);
  new_elem->next = *begin;
  new_elem->data = my_strdup(data);
  *begin = new_elem;
}
