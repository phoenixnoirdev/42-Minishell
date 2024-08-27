/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phkevin <phkevin@42luxembourg.lu>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 09:32:11 by phkevin           #+#    #+#             */
/*   Updated: 2024/08/27 15:19:23 by phkevin          ###   Luxembour.lu      */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	ft_parse(char *str)
{
	t_cmdm *cmdm;
	//t_cmd *cmdc;
	char	**cmd;

	cmdm = (t_cmdm *)ft_calloc(1, sizeof(t_cmdm));
	if (!cmdm)
		return ;
	cmdm->nb_cmd = ft_getnbcmd(str);
	cmd = (char **)malloc((cmdm->nb_cmd + 1) * sizeof (char *));
	if (!cmd)
		return ;
	cmd = ft_splitpars(str, '|');
	
	//cmdc = (t_cmd *)ft_calloc(cmdm->nb_cmd, sizeof(t_cmd));
	//if (!cmdc)
		//return ;

	int i = 0;
	while (cmd[i])
	{
		printf("%s\n", cmd[i]);
		i++;
	}
	
	//printf("nb cmd = %d\n", );
}