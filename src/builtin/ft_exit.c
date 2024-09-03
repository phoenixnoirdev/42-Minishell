/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phkevin <phkevin@42luxembourg.lu>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 10:24:40 by nfordoxc          #+#    #+#             */
/*   Updated: 2024/08/30 15:50:00 by phkevin          ###   Luxembour.lu      */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

/*
 * <cat>minishell</cat>
 *
 * <summary>
 * 	void	ft_free_data(t_data *data)
 * </summary>
 *
 * <description>
 * 	ft_free_data free all pointer on struct data.
 * 	variable.
 * </description>
 *
 * <param type="t_data *" name="data">data struct</param>
 *
 * <return>
 * 	void.
 * </return>
 *
 */

void	ft_free_data(t_cmdc **data)
{
	t_cmdc *tmp;

	while (*data)
	{
		tmp = (*data)->next;
		if ((*data)->cmd)
			free((*data)->cmd);
		free(*data);
		*data = tmp;
	}
}

/*
 * <cat>minishell</cat>
 *
 * <summary>
 * 	int	ft_exit(t_data *data, t_env **env)
 * </summary>
 *
 * <description>
 * 	ft_exit clear all history command and free all struct and linked list.
 * 	variable.
 * </description>
 *
 * <param type="t_data *" name="data">data struct</param>
 * <param type="t_env **" name="env">linked list env</param>
 *
 * <return>
 * 	0 if success or 1 if error.
 * </return>
 *
 */

int	ft_exit(t_cmdc *data, t_env **env)
{
	rl_clear_history();
	ft_free_data(&data);
	ft_free_env(*env);
	exit(EXIT_SUCCESS);
}
