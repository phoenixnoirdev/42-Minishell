/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phkevin <phkevin@42luxembourg.lu>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 09:32:11 by phkevin           #+#    #+#             */
/*   Updated: 2024/08/30 16:28:45 by phkevin          ###   Luxembour.lu      */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

static t_cmdc	**initlist(int nbcmd, char **strs, t_cmdc **cmdc)
{
	t_cmdc *cmdct;
	int		i;

	i = 0;
	cmdc = (t_cmdc **)ft_calloc((nbcmd + 1), sizeof(t_cmdc));
	if (!cmdc)
		return (NULL);
	while (strs[i] != NULL)
	{
		cmdct = ls_newcmd(strs, i);
		if (!cmdct)
			return (NULL);
		ft_lstadd_backkk(cmdc, cmdct);
		i++;
	}
	free (strs);
	return (cmdc);
}

static void	ft_sendcmd(t_cmdc **cmdc, t_env **env)
{
	t_cmdc	*tmp;

	tmp = *cmdc;
	while (tmp)
	{
		ft_builtin(tmp, env);
		tmp = tmp->next;
	}
}

void	ft_parse(char *str, t_env **env)
{
	t_cmdm *cmdm;
	t_cmdc **cmdc;
	char	**strs;

	cmdc = NULL;
	cmdm = (t_cmdm *)ft_calloc(1, sizeof(t_cmdm));
	if (!cmdm)
		return ;
	cmdm->nb_cmd = ft_getnbcmd(str);
	strs = (char **)malloc((cmdm->nb_cmd + 1) * sizeof (char *));
	//strs = ft_splitpars(str, '|');
	if (!strs)
		return ;
	strs = ft_splitpars(str, '|');
	cmdc = initlist(cmdm->nb_cmd, strs, cmdc);
	//ft_lstread(*cmdc);
	ft_sendcmd(cmdc, env);
	//free(strs);
}
