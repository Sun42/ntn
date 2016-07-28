/*
** display_dizaine.c for ntn in /u/all/roth_s/cu/public/rush
** 
** Made by sebastien roth
** Login   <roth_s@epitech.net>
** 
** Started on  Sat Dec  6 14:49:48 2008 sebastien roth
** Last update Sun Dec  7 16:56:22 2008 sebastien roth
*/

#include "my.h"
#include "ntn.h"

int	display_sep_vocfr(char *str)
{
  if ((*str != '8') && (*(str + 1) == '0'))
    {
      return (1);
    }
  if ((*str == '8') && (*(str + 1) == '0'))
    {
      return (1);
    }
  return (0);
}

int	display_dizaine_vocfr(char *str)
{
  if (*str == '0' && (*(str + 1) == '0'))
    return (1);
  if (*str == '0')
    return (0);
  if (*str == '1' || *str == '7' || *str == '9')
    {
      player(tab_dizaine_vocfr[*str - '0']);
      player(tab_unit_vocfr[*(str + 1) - '0' + 10]);
      return (1);
    }
  if (((*str >= '2') && (*str <= '6')) || (*str == '8'))
    player(tab_dizaine_vocfr[*str - '0']);
  return (display_sep_vocfr(str));
}
