/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phkevin <phkevin@42luxembourg.lu>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 15:41:47 by nfordoxc          #+#    #+#             */
/*   Updated: 2024/08/30 15:52:57 by phkevin          ###   Luxembour.lu      */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

int main(int argc, char **argv, char **envp)
{
	char		*line;
	//t_cmdc		data;
	t_env		*env;
	//t_cmd		*cmd;

	(void)argc;
	(void)argv;
	signal(SIGINT, handle_signal);
    signal(SIGQUIT, SIG_IGN);
	ft_init_env(&env, envp);
	//data.code_child = -1;
	while (1)
	{
		line = readline(TERM_NAME"$ ");
		if (ft_strlen(line))
			add_history(line);
		//cmd = ft_parse(line);
		ft_parse(line, &env);
		//data.cmd = ft_strdup(line);
		free(line);
		//ft_builtin(&data, &env);
		//ft_parse_line(&data);
		/* faire un fork et executer cmd dans le fils */
		/* attendre le process fils et enregistrer le code retour */
		//free(data.cmd);
	}
	//free(data.cmd);
}
