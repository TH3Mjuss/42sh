/*
** my_epur_str.c for my_epur_str.c in /home/jussea_m
** 
** Made by jussea_m@epitech.eu
** Login   <jussea_m@epitech.net>
** 
** Started on  Tue May 13 14:50:34 2014 jussea_m@epitech.eu
** Last update Tue May 13 14:57:41 2014 jussea_m@epitech.eu
*/

char            *my_epur_str(char *str)
{
  int           i;
  int           j;
  
  i = -1;
  j = 0;
  if (!str)
    return (0);
  while (str[i] != '\0')
    {
      if (str[i] != ' ' && str[i] != '\t')
	{
	  str[j] = str[i];
	  j++;
	  if (str[i + 1] == ' ' || str[i + 1] == '\t')
	    {
	      str[j] = ' ';
	      j++;
	    }
	}
      i++;
    }
  str[j] = '\0';
  if (str[j - 1] == ' ')
    str[j - 1] = '\0';
  return (str);
}
