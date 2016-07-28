/*
** display_centaine_vocfr.c for ntn in /u/all/roth_s/cu/public/rush
** 
** Made by sebastien roth
** Login   <roth_s@epitech.net>
** 
** Started on  Sat Dec  6 14:50:28 2008 sebastien roth
** Last update Sun Dec  7 16:55:31 2008 sebastien roth
*/

#include "my.h"
#include "ntn.h"

void	display_centaine_vocfr(char *str)
{
  if ((*str) == '0')
    return ;
  if (*str == '1')
    {
      player(tab_unit_val_vocfr[3]);
    }
  if (*str > '1')
    {
      player(tab_unit_vocfr[*str - '0']);
      player(tab_unit_val_vocfr[3]);
    }
}
