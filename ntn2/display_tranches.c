/*
** display_tranches.c for ntn in /u/all/sundas_c/cu/public/ntn/ntn2
** 
** Made by christophe sundas
** Login   <sundas_c@epitech.net>
** 
** Started on  Sat Dec  6 21:51:58 2008 christophe sundas
** Last update Sun Dec  7 22:04:58 2008 christophe sundas
*/

#include <stdlib.h>
#include <stdio.h>
#include "my.h"
#include "ntn.h"

/*
** parse la string complete
*/
t_list		*display_tranches(char *str)
{
  int		cpt;
  char		tab_str[4];
  int		flag_spc;
  t_list	*my_list;	

  my_list = 0;
  flag_spc = 0;
  cpt = 0;
  if (*str == '-')
    {
      my_put_in_list2(&my_list, tab_min[FR]);
      str++;
    }
  while (*str)
    {
      if (flag_spc == 1)
	my_put_in_list2(&my_list, " ");
      cpt = nb_to_take(str);
      mk_bloc(str, tab_str, cpt);
      display_bloc(tab_str, &my_list);
      display_unit_val(str, &my_list);
      if (!flag_spc)
	flag_spc = 1;
      str += cpt;
    }
  return (my_list);
}

/*
** retourne le nombre de char a prendre pour un bloc
*/
int	nb_to_take(char *str)
{
  int	len;
  int	mod;

  len = my_strlen(str);
  mod = (len % 3);
  if (mod == 0)
    {
      return (3);
    }
  else
    {
      return (mod);
    }
}

/*
** cree la string bloc pour display_bloc
*/
void	mk_bloc(char *str, char tabstr[4], int blocsize)
{
  int	i;

  i = 0;
  tabstr[0] = 0;
  tabstr[1] = 0;
  tabstr[2] = 0;
  tabstr[3] = 0;

  while (i < blocsize)
    {
      tabstr[i] = str[i];
      i++;
    }
  tabstr[i] = '\0';
}

/*
** affiche les unite de valeur en focntion de la len str
*/
void	display_unit_val(char *str, t_list **my_list)
{
  int	i;

  if (str[0] == '0' && str[1] == '0' && str[2] == '0')
    return ;
  if ((i = my_strlen(str)) > 3 && i <= 6)
    {
      my_put_in_list2(my_list, " mille");
    }
  if (i > 6 && i <= 9)
    {
      my_put_in_list2(my_list, " million");
    }
  if (i > 9)
    {
      my_put_in_list2(my_list, " milliard");
    }
}
