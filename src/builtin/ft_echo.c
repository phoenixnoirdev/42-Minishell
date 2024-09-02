/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phkevin <phkevin@42luxembourg.lu>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 09:55:36 by nfordoxc          #+#    #+#             */
/*   Updated: 2024/09/02 15:02:34 by phkevin          ###   Luxembour.lu      */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

static int	ft_get_opt(char *line)
{
	int		index;

	index = 0;
	while (line[++index] == 'n')
		;
	if (line[index] == 0)
		return (1);
	return (0);
}

int	ft_echo(t_cmdc *data, t_env *env)
{
	//char 	var;
	char	**array;
	int		opt;
	int		index;

	(void)env;
	opt = 0;
	array = ft_split(data->cmd, ' ');
	if (!array[1])
	{
		data->code_child = 0;
		ft_putendl_fd("", 1);
		return (0);
	}
	index = 1;
	if (array[index][0] == '-')
		opt = ft_get_opt(array[index]);
	if (opt)
	{
		while (array[++index])
		{
			/*if (array[index][0] == '$')
			{
				var = ft_get_env_value(env, array[index]);
				printf("%s\n", var);
				free(var);
			}
			else*/
				ft_putstr_fd(array[index], 1);
			if (array[index + 1])
				ft_putchar_fd(' ', 1);
		}
	}
	else
	{
		while (array[index])
		{
			ft_putstr_fd(array[index], 1);
			ft_putchar_fd(' ', 1);
			index++;
		}
		ft_putchar_fd('\n', 1);
	}
	ft_free_array(array);
	return (0);
}
