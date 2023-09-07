/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   num_to_word.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntanajar <ntanajar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/25 13:10:56 by ntanajar          #+#    #+#             */
/*   Updated: 2023/06/26 15:56:09 by ntanajar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush02.h"

// ft_get_mult - DOCUMENT
// Check the entries range between 1 billion to 100
// When it's between 100 and 20, it will returns a value of nb
// divided by 10 then times 10 to get rid of remainder and get the tens
// eg. 42 will returns 40
unsigned int	ft_get_mult(unsigned int nb)
{
	if (nb >= 1000000000)
		return (1000000000);
	else if (nb >= 1000000)
		return (1000000);
	else if (nb >= 1000)
		return (1000);
	else if (nb >= 100)
		return (100);
	else if (nb < 100 && nb >= 20)
		return ((nb / 10) * 10);
	else if (nb < 20)
		return (nb);
	else
		return (0);
}

// Why do we hard-coded these?
// Because the subject says

/* "The dictionary will always have at least the keys as in the reference 
dictionary. Their value can be modified, more entries can be added, 
but the initial keys can’t be removed." 

and

"You only need to use the initial entries (For instance,
if we add 54: fifty-four, you still have to use 50: fifty and 4: four)" */

// which means

// More entries and be added, but you still need to use the initial entries
// and initial entries can't be removed.

// So I can simply just code the initial entries.

void	hyphen_and(unsigned int multiple, unsigned int number)
{
	if ((multiple == 100 && number % 100 != 0)
		|| (multiple == 100000 && number % 100000 != 0)
		|| (multiple == 100000000 && number % 100000 != 0))
		ft_putstr(" and");
	if ((multiple == 1000 && number % 1000 != 0)
		|| (multiple == 1000000 && number % 1000000 != 0)
		|| (multiple == 1000000000 && number % 1000000 != 0))
		ft_putstr(",");
}

// ft_num_to_word - DOCUMENT
// Convert the unsigned int input to words in reference dictionary
// And add space to each words properl
void	ft_num_to_word(unsigned int number, t_num_word *dict)
{
	int				i;
	unsigned int	multiple;

	i = 0;
	multiple = ft_get_mult(number);
	if (multiple >= 100)
	{
		ft_num_to_word(number / multiple, dict);
		ft_putstr(" ");
	}
	while (dict[i].num != multiple)
		i++;
	ft_putstr(dict[i].word);
	hyphen_and(multiple, number);
	if (multiple != 0 && number % multiple != 0)
	{
		if (multiple >= 20 && multiple <= 90)
			ft_putstr("-");
		else
			ft_putstr(" ");
		ft_num_to_word(number % multiple, dict);
	}
}
