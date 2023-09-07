/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utility_funcs.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntanajar <ntanajar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/25 13:52:12 by sliashko          #+#    #+#             */
/*   Updated: 2023/06/25 19:17:14 by ntanajar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush02.h"

//Check if character is alpha
int	is_alpha(char c)
{
	return ((c >= 65 && c <= 90) || (c >= 97 && c <= 122));
}

int	is_printable(char c)
{
	return (c >= 32 && c <= 126);
}

//Prints the given string to std output
void	ft_putstr(char *str)
{
	int		i;
	char	c;

	i = 0;
	while (str[i] != '\0' )
	{
		c = str[i];
		write(1, &c, 1);
		i++;
	}
}

//Convert numeric string into unsigned integer
unsigned int	ft_atoi(char *str)
{
	unsigned long	value;
	unsigned int	result;
	int				i;

	value = 0;
	i = 0;
	while ((*str >= 9 && *str <= 13) || *str == 32)
		str++;
	while (*str == '-' || *str == '+')
		str++;
	while ((*str >= 9 && *str <= 13) || *str == 32)
		str++;
	while (*str >= '0' && *str <= '9')
	{
		value = (value * 10) + (*str - '0');
		if (value > 4294967295)
			return (0);
		str++;
	}
	result = value;
	return (result);
}

//Extract the word in line
char	*get_word(char *line)
{
	char	*word;
	int		i;
	int		flag;

	flag = 0;
	word = (char *) malloc(sizeof(char) * 35);
	i = 0;
	while (*line != '\n' && *line != '\0')
	{
		if (is_alpha(*line))
			flag = 1;
		if ((is_printable(*line) || *line == ' ') && flag == 1)
		{
			word[i] = *line;
			i++;
		}
		line++;
	}
	word[i] = '\0';
	return (word);
}
