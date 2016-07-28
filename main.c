/*
** main.c for ntn in /u/all/sundas_c/cu/rendu/unix/projet/ntn
** 
** Made by christophe sundas
** Login   <sundas_c@epitech.net>
** 
** Started on  Fri Dec  5 20:34:43 2008 christophe sundas
** Last update Sat Dec  6 03:49:06 2008 christophe sundas
*/

#include "ntn.h"
#include "my.h"
#include "my_printf.h"


int	main(int ac , char **av)
{
 
  if (ac > 1)
    ntn(ac, av);
  my_putchar('\n');
  return (0);
}

void	ntn(int ac, char **av)
{
  if (check_valid(av[1]) == 0)
    {
      my_putstr_error("Chaine invalide");
    }
  else
    {
      display_bloc(av[1]);
    }
}

/*
** display par bloc de trois
*/
void	display_bloc(char *str)
{
  if (my_strlen(str) == 3)
    {
      display_centaine(str);
      str++;
    }
  else if (my_strlen(str) == 2)
    {
      display_dixaine(str);
      str++;
    }
  else if (my_strlen(str) == 1)
    {
      display_unit(str);
      str++;
    }
}

void	display_unit(char *str)
{
  if (my_strlen(str) == 2)
    {
      my_putstr("Pas encore");
    }
  if (my_strlen(str) == 1)
    {
      my_putstr(tab_unit[*str - '0']);
    }
}

void	display_dixaine(char *str)
{
  if (*str == '0')
    return ;
  if (*str == '1')
    {
      /* my_putstr(tab_unit[*str - '0' + 11]);*/
    }
  if ((*str >= '2') && (*str <= '8'))
    {
      my_putstr(tab_dixaine[*str - '0']);
      my_putchar('-');
    }
  if (*str == '9')
    my_putstr(tab_dixaine[*str - '0']);
}

void	display_centaine(char *str)
{
  if ((*str) == '0')
    return ;
  if (*str == '1')
    {
      my_putstr(CENT);
    }
  if (*str > '1')
    {
      my_putstr(tab_unit[*str - '0']);
      my_putstr(" ");
      my_putstr(CENT);
      display_plural_cent(str);
    }
  my_putstr(" ");
}

void	display_plural_cent(char *str)
{
  if (*(str + 1) == '0' && *(str + 2) == '0')
    my_putchar('s');
}
