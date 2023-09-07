/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_dict_to_struct.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntanajar <ntanajar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/25 14:37:50 by sliashko          #+#    #+#             */
/*   Updated: 2023/06/26 15:52:43 by ntanajar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush02.h"

//The function counts how many lines in text
int	count_lines(char *content)
{
	int	c;

	c = 0;
	while (*content != '\0')
	{
		if (*content == '\n')
			c++;
		content++;
	}
	return (c);
}

//Takes pointer to beginning of line
//and returns instance of num:word pair
t_num_word	make_pair(char *line)
{
	t_num_word		pair;

	pair.num = ft_atoi(line);
	pair.word = get_word(line);
	return (pair);
}

//Creates array of stucture
// and reads the content of file
// filling the array with struct instances
t_num_word	*get_dict_strcts(char *content)
{
	int			i;
	int			n_lines;
	t_num_word	*dict;

	n_lines = count_lines(content);
	dict = (t_num_word *) malloc(sizeof(t_num_word) * n_lines);
	i = 0;
	while (i < n_lines)
	{
		while (*content == '\n')
			content++;
		dict[i] = make_pair(content);
		i++;
		while (*content != '\n' && *content != '\0')
		{
			content++;
		}
		while (*content == '\n')
			content++;
	}
	return (dict);
}

/*
int	main()
{
	char		*content;
	t_num_word	*dict;

	content = get_content("numbers.dict");
	dict = get_dict_strcts(content);
	printf("el #1:  num = %u ; word = %s\n", dict[31].num, dict[31].word);
}
*/
