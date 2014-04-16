/*
** my_putnbr.c for 42sh in /home/gysc0/rendu/PSU_2013_minishell2
**
** Made by Zackary Beaugelin
** Login   <beauge_z@epitech.net>
**
** Started on  Mon Apr  7 20:12:45 2014 Zackary Beaugelin
** Last update Mon Apr  7 20:13:02 2014 Zackary Beaugelin
*/

#include <unistd.h>

void	my_putchar(char c)
{
  write(1, &c, 1);
}

void	my_putnbr(int nb)
{
  int	neg;

  neg = 0;
  if (nb < 0)
    {
      my_putchar('-');
      if (nb == -2147483648)
	{
	  neg = -1;
	  nb = nb + 1;
	}
      nb = nb * -1;
    }
  if (nb >= 10)
    my_putnbr(nb /10);
  if (neg == -1)
    {
      neg = 0;
      my_putchar(nb % 10 + '1');
    }
  else
    my_putchar(nb % 10 + '0');
}
