/*
** display_unit_vocfr.c for ntn in /u/all/roth_s/cu/public/rush
** 
** Made by sebastien roth
** Login   <roth_s@epitech.net>
** 
** Started on  Sat Dec  6 14:49:18 2008 sebastien roth
** Last update Sun Dec  7 16:56:37 2008 sebastien roth
*/

#include "my.h"
#include "ntn.h"

void	display_unit_vocfr(char *str)
{
  if (my_strlen(str) == 1)
    player(tab_unit_vocfr[*str - '0']);
}
