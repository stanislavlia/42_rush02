/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntanajar <ntanajar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/25 16:56:34 by sliashko          #+#    #+#             */
/*   Updated: 2023/06/26 15:56:42 by ntanajar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush02.h"

char	*get_path(int argc, char *argv[])
{
	char	*path;

	if (argc == 3)
		path = argv[1];
	else if (argc == 2)
		path = "numbers.dict";
	else
	{
		path = NULL;
	}
	return (path);
}

char	*set_input(int argc, char *argv[])
{
	if (argc == 3)
		return (argv[2]);
	else if (argc == 2)
		return (argv[1]);
	return (0);
}

//Check the number
//which must be less than
// max possible unsigned int
int	check_limit(char *str)
{
	unsigned long	value;
	int				i;

	value = 0;
	i = 0;
	while ((*str >= 9 && *str <= 13) || *str == 32)
		str++;
	while (*str == '-' || *str == '+')
		str++;
	while (*str >= '0' && *str <= '9')
	{
		value = (value * 10) + (*str - '0');
		if (value > MAX_UNSIGNED_INT)
			return (0);
		str++;
	}
	return (1);
}

int	main(int argc, char *argv[])
{
	char			*path;
	t_num_word		*dict;
	char			*content;
	char			*input;

	input = set_input(argc, argv);
	path = get_path(argc, argv);
	if (path == NULL || validate_input(input) == 0 || check_limit(input) == 0)
	{
		ft_putstr("Error\n");
		return (1);
	}
	content = get_content(path);
	if (content == NULL)
	{
		ft_putstr("Dict Error\n");
		return (1);
	}
	dict = get_dict_strcts(content);
	ft_num_to_word(ft_atoi(input), dict);
	ft_putstr("\n");
	free(dict);
	free(content);
	return (0);
}
