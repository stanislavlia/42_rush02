/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush02.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntanajar <ntanajar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/25 13:11:41 by sliashko          #+#    #+#             */
/*   Updated: 2023/06/26 13:44:56 by ntanajar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RUSH02_H
# define RUSH02_H

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>

# define MAX_UNSIGNED_INT 4294967295

typedef struct pair
{
	unsigned int		num;
	char				*word;
}	t_num_word;

unsigned int	str_to_num(char *str);
void			ft_putstr(char *str);
unsigned int	ft_atoi(char *str);
int				validate_input(char *input);
int				count_strchar(char *str, char c);
char			*get_word(char *line);
char			*get_content(char *path);
t_num_word		*get_dict_strcts(char *content);
void			ft_num_to_word(unsigned int number, t_num_word *dict);
int				ft_strcmp(char *s1, char *s2);
unsigned int	ft_get_tens(unsigned int nb);
unsigned int	ft_get_mult(unsigned int nb);

#endif
