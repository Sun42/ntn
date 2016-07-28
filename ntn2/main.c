/*
** main.c for ntn in /u/all/sundas_c/cu/rendu/unix/projet/ntn
** 
** Made by christophe sundas
** Login   <sundas_c@epitech.net>
** 
** Started on  Fri Dec  5 20:34:43 2008 christophe sundas
** Last update Sun Dec  7 22:22:31 2008 christophe sundas
*/

#include "my.h"
#include "my_printf.h"
#include "ntn.h"

int	main(int ac , char **av)
{
  if (ac > 1)
    ntn(ac, av);
  my_putchar('\n');
  return (0);
}

void		ntn(int ac, char **av)
{
  int		tabopt[5];
  int		i;
  char		*parsed;
  
  i = check_option(ac, av, tabopt);
  if (check_valid0(av[i]) == 0)
    {
      my_putstr_error("Chaine invalide"); 
      exit(-1);
    }
  parsed = parse_op(av[i]);
  if (check_valid(parsed) == 0)
    my_putstr_error("Chaine invalide");
  else
    {
      if (tabopt[LANG] == ENG)
	eng_mode(parsed, tabopt);
      if (tabopt[LANG] == VOCAL)
	vocal_mode(parsed, tabopt);
      if (tabopt[LANG] == FR)
	fr_mode(parsed, tabopt); 
    }
  free(parsed);
}

void		vocal_mode(char *str, int tabopt[])
{
  t_list	*list;

  list = display_tranches_vocfr(epur_zero(str));
  my_free_list(&list);
}

void		eng_mode(char *str, int tabopt[])
{
  t_list	*list;

  list = display_tranches_en(epur_zero(str));
  my_rev_list(&list);
  if (tabopt[BIG_M] == 1 || tabopt[BIG_A] == 1 || tabopt[LITTLE_A] == 1)
    my_display_list_with_opt(list, tabopt);
  else
    my_display_list(list);
  my_free_list(&list);
}

void		fr_mode(char *str , int tabopt[])
{
  t_list	*list;
 
  
  list = display_tranches(epur_zero(str));
  my_rev_list(&list);
  affine_list(&list);
  if (tabopt[BIG_M] == 1 || tabopt[BIG_A] == 1 || tabopt[LITTLE_A] == 1)
    my_display_list_with_opt(list, tabopt);
  else
    my_display_list(list);
  my_free_list(&list);
}
