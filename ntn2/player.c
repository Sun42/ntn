/*
** player.c for ntn in /u/all/sundas_c/public/ntn/ntn2
** 
** Made by sebastien roth
** Login   <roth_s@epitech.net>
** 
** Started on  Sun Dec  7 05:28:09 2008 sebastien roth
** Last update Sun Dec  7 22:58:22 2008 sebastien roth
*/

#include <sys/wait.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include "my.h"

int	my_execlp(char *file, char *arg, char *arg2)
{
  int	i;

  if ((i = execlp(file, arg, arg2, 0) == -1))
    {
      my_putstr("Erreur execlp \n");
      exit(-1);
    }
    return (i);
}

void	player(char *str)
{
  pid_t	child;
  int	statut;
  char	*tmp;

  tmp = my_strdup("numbers/");
  my_strcat(tmp, str);
  if ((child = fork()) == 0)
    my_execlp("mplayer", "mplayer", tmp);
  if (child == -1)
    {
      exit(-1);
    }
  if (waitpid(child, &statut, 0) == -1)
    {
      exit(-1);
    }
  free(tmp);
}
