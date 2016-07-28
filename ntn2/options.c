/*
** args.c for ntn in /u/all/roth_s/public/rush
** 
** Made by christophe sundas
** Login   <sundas_c@epitech.net>
** 
** Started on  Sat Dec  6 18:13:28 2008 christophe sundas
** Last update Sun Dec  7 22:29:29 2008 christophe sundas
*/

#include <stdio.h>
#include <stdlib.h>
#include "my.h"
#include "ntn.h"

void	my_aff_tabopt(int tabopt[5])
{
  int	i;

  i = 0;
  my_putstr("my_aff_tabopt \n");
 while (i < 5)
    {
      printf("TABOPT[%i]: %i \n", i, tabopt[i]);
      i++;
    }
 my_putstr("end my aff opt \n");
}

/*
** rempli le tableau doption
*/
int	check_option(int ac, char **av, int tabopt[5])
{
  int	i;

  tabopt[BIG_M] = 0;
  tabopt[BIG_A] = 0;
  tabopt[LITTLE_A] = 0;
  tabopt[LANG] = FR;
  tabopt[4] = 0;
  i = 1;
  while ((i < ac) && (is_option(av[i], tabopt)))
    {
      i = i + 1;
    }
  return (i);
}

/*
** verifie si un argument est uen option
*/
int	is_option(char *str, int tabopt[5])
{
  int	i;

  i = 0;
  if (str[0] != '-')
    return (0);
  i++;
  if (is_anumber(str + 1))
    return (0);
  while (str[i])
    {
      if (!is_valid_option(str[i]))
        exit (-1);
      if (str[i] == 'M')
        tabopt[BIG_M] = 1;
      if (str[i] == 'A')
        tabopt[BIG_A] = 1;
      if (str[i] == 'a')
        tabopt[LITTLE_A] = 1;
      if (str[i] == 'V')
	tabopt[LANG] = VOCAL;
      if (str[i] == 'e' && str[i + 1] == 'n')
	tabopt[LANG] = ENG;
      i++;
    }
  return (1);
}
/*
** verifie si loption est valide
*/
int	is_valid_option(char c)
{
  if (c == 'M')
    return (1);
  if (c == 'A')
    return (1);
  if (c == 'a')
    return (1);
  if (c == 'V')
    return (1);
  if (c == 'e')
    return (1);
  if (c == 'n')
    return (1);
  if ((c >= '0') && (c <= '9'))
    return (0);
  my_putstr_error("Err illegal option :");
  my_putchar(c);
  my_putchar('\n');
  exit(-1);
  return (0);
}

/*
**
** -M -c -A -a -en -R -V
*/
int	is_anumber(char *str)
{
  int	flag;

  flag = 0;
  while (*str)
    {
      if (*str >= '0' && *str <= '9')
	flag = 1;
      else
	return (0);
      str++;
    }
  return (flag);
}
