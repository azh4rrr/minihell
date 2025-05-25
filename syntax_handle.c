/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   syntax_handle.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azmakhlo <azmakhlo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/25 17:50:24 by azmakhlo          #+#    #+#             */
/*   Updated: 2025/05/25 20:52:02 by azmakhlo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	handle_quotes(char *line)
{
	int		i;
	char	qt;
	int		fl;

	i = 0;
	fl = 1;
	while (line[i])
	{
		if (line[i] == '"' || line[i] == '\'')
		{
			qt = line[i];
			i = i + 1;
			while (line[i] != qt && line[i])
				i++;
			if (line[i] != qt)
				fl = 0;
			i++;
		}
		else
			i++;
	}
	if (fl == 0)
		return (1);
	return (0);
}

int	redire_check(char *line)
{
	if (!ft_strncmp(line, ">>", 2) || !ft_strncmp(line, "<<", 2))
		return (0);
	else if (!ft_strncmp(line, "<", 1) || !ft_strncmp(line, ">", 1))
		return (0);
	return (1);
}

int	handle_redir(char *line)
{
	int		i;
	// char	rd;
	char	**cmd;

	i = 0;
	cmd = tokenize_with_redirections(line);
	while (cmd[i])
	{
		if(!redire_check(cmd[i]) && !cmd[i + 1])
			return (printf("minishell: syntax error near unexpected token `newline'\n"),
				free_cmd_array(cmd), 1);
		if (!redire_check(cmd[i]) && !redire_check(cmd[i + 1]))
			return (printf("minishell: syntax error near unexpected token `%s'\n", cmd[i + 1]),
				free_cmd_array(cmd), 1);
		i++;
	}
	return (0);
}

int	syntax_error(char *line)
{
	if (handle_quotes(line))
		return (printf("minishell: quoting error\n"), 1);
	if (handle_redir(line))
		return (1);
	return(0);
}