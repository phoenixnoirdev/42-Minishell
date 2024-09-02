/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   listpars.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phkevin <phkevin@42luxembourg.lu>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/30 11:47:58 by phkevin           #+#    #+#             */
/*   Updated: 2024/09/02 14:58:07 by phkevin          ###   Luxembour.lu      */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

t_cmdc	*ls_newcmd(char **cmd, int refcmd)
{
	t_cmdc *cmdct;

	cmdct = (t_cmdc *)malloc(sizeof(t_cmdc));
	if (!cmdct)
		return (NULL);
	cmdct->cmd = cmd[refcmd];
	cmdct->code_child = -1;
	cmdct->next = NULL;
	return (cmdct);
}

void	ft_lstadd_backkk(t_cmdc **ls, t_cmdc *lt)
{
	t_cmdc	*lsladd;
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

int	ft_lstsizee(t_cmdc *lst)
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
}

void	ft_lstread(t_cmdc *lst)
{
	t_cmdc	*tmp;

	tmp = lst;
	while (tmp)
	{
		printf("cmd = %s\n", tmp->cmd);
		tmp = tmp->next;
	}
}