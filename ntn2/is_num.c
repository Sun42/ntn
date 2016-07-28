/*
** is_num.c for ntn in /u/all/roth_s/cu/public/rush
** 
** Made by sebastien roth
** Login   <roth_s@epitech.net>
** 
** Started on  Sat Dec  6 14:52:38 2008 sebastien roth
** Last update Sat Dec  6 14:52:50 2008 sebastien roth
*/

int	is_num(char c)
{
  if ((c >= '0') && (c <= '9'))
    return (1);
  return (0);
}
