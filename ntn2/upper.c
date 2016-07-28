/*
** upper.c for ntn in /u/all/roth_s/cu/public/rush
** 
** Made by sebastien roth
** Login   <roth_s@epitech.net>
** 
** Started on  Sat Dec  6 15:21:53 2008 sebastien roth
** Last update Sun Dec  7 20:38:34 2008 sebastien roth
*/

char	char_to_upper(char c)
{
  if (c >= 'a' && c <= 'z')
    return (c - 32);
  return (c);
}

char	*str_to_upper(char *str)
{
  int	i;

  i = 0;
  while (str[i] != '\0')
    {
      str[i] = char_to_upper(str[i]);
      i++;
    }
  return (str);
}

char	*str_altern_upper(char *str, int begin, int freq)
{
  int	i;
  int	flag;

  i = begin;
  flag = 0;
  while (str[i] != '\0')
    {
      if (flag % freq == 0)
	str[i] = char_to_upper(str[i]);
      flag++;
      i++;
    }
  return (str);
}
