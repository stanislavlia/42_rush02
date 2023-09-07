/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_input.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntanajar <ntanajar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/25 15:18:25 by ntanajar          #+#    #+#             */
/*   Updated: 2023/06/26 11:28:59 by ntanajar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush02.h"

// Count the char you want to looking for in a string
int	count_strchar(char *str, char c)
{
	int	count;

	count = 0;
	while (*str)
	{
		if (*str == c)
			count++;
		str++;
	}
	return (count);
}

// Count numerical alphabet
int	count_digit(char *str)
{
	int	count;

	count = 0;
	while (*str)
	{
		if ((*str >= '0' && *str <= '9'))
			count++;
		str++;
	}
	return (count);
}

// Check if there's odd number of '-' that will cause an unsigned int to error
// Error if number of digit in input is 0
// And check if the string contain only charracters allowed by atoi
int	validate_input(char *input)
{
	if ((count_strchar(input, '-') % 2 == 1) || count_digit(input) == 0)
		return (0);
	while (*input)
	{
		if ((*input < '0' || *input > '9') && (*input < 9 || *input > 13)
			&& (*input != 32 && *input != '-' && *input != '+'))
			return (0);
		input++;
	}
	return (1);
}

// void	ft_putchar(char c)
// {
// 	write(1, &c, 1);
// }

// void	ft_putnbr(unsigned int nbr)
// {
// 	if (nbr > 9)
// 	{
// 		ft_putnbr(nbr / 10);
// 		ft_putnbr(nbr % 10);
// 	}
// 	else
// 	{
// 		ft_putchar(nbr + '0');
// 	}
// }

// TEST OUR CODE 

// int	main(int argc, char *argv[])
// {
// 	unsigned int		number;

// 	if (validate_input(argv[1]))
// 	{
// 		number = ft_atoi(argv[1]);
// 		ft_putnbr(number);
// 	}
// 	else
// 	{
// 		ft_putstr("Error\n");
// 		return (1);
// 	}
// 	return (0);
// }
