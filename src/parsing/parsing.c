/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phkevin <phkevin@42luxembourg.lu>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 09:32:11 by phkevin           #+#    #+#             */
/*   Updated: 2024/08/29 13:20:37 by phkevin          ###   Luxembour.lu      */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"




static t_cmdc	*ls_newcmd(char **cmd, int refcmd)
{
	t_cmdc *cmdct;

	cmdct = (t_cmdc *)malloc(sizeof(t_cmdc));
	if (!cmdct)
		return (NULL);
	cmdct->cmd_arg = cmd[refcmd];
	cmdct->cmd = cmd[refcmd];
	cmdct->args = cmd[refcmd];
	return (cmdct);
}

static void	ft_lstadd_backkk(t_cmdc **ls, t_cmdc *lt)
{
	t_cmdc	*lsladd;
	//printf("%s\n", lt->cmd_arg);
	if (ls == NULL || lt == NULL)
		return ;
	if (*ls == NULL)
	{
		*ls = lt;
		return ;
	}
	lsladd = *ls;
	while (lsladd->next != NULL)
		lsladd = lsladd->next;
	lsladd->next = lt;
}


/*static int	ft_lstsizee(t_cmdc *lst)
{
	int		i;
	t_cmdc	*tmp;

	tmp = lst;
	i = 0;
	while (tmp)
	{
		tmp = tmp->next;
		i++;
	}
	return (i);
}*/

void	ft_parse(char *str)
{
	t_cmdm *cmdm;
	t_cmdc **cmdc;
	t_cmdc *cmdct;
	char	**cmd;
	int		i;

	cmdm = (t_cmdm *)ft_calloc(1, sizeof(t_cmdm));
	if (!cmdm)
		return ;
	cmdm->nb_cmd = ft_getnbcmd(str);
	cmd = (char **)malloc((cmdm->nb_cmd + 1) * sizeof (char *));
	if (!cmd)
		return ;
	cmd = ft_splitpars(str, '|');
	
	

	
	cmdc = (t_cmdc **)ft_calloc((cmdm->nb_cmd + 1), sizeof(t_cmdc));
	if (!cmdc)
		return ;
	
	i = 0;
	while (cmd[i] != NULL)
	{
		printf("%s\n", cmd[i]);
		cmdct = ls_newcmd(cmd, i);
		//printf("%s\n", cmdct->cmd_arg);
		if (!cmdct)
			return ;
		ft_lstadd_backkk(cmdc, cmdct);
		i++;
	}


	//printf("%d\n", ft_lstsizee(*cmdc));






	//printf("%s\n", cmdc->cmd_arg);
	//printf("%s\n", cmdc->cmd);
	//printf("%s\n", cmdc->args);
	/*while (cmdc)
	{
		printf("%s\n", cmdc->cmd);
		cmdc++;
	}*/
	
	
	//printf("nb cmd = %d\n", );
}