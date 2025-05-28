#include "../minishell.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int	is_redir_char(char c)
{
	return (c == '>' || c == '<');
}

int	handle_quotes(char *line)
{
	int		i;
	char	qt;
	int		fl;

	i = 0;
	fl = 1;
	while (line[i] && i < strlen(line))
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

char	**tokenize_with_redirections_2(char *cmd_str)
{
	char	**tokens;
	char	*temp_cmd;
	int		i;
	int		j;

	temp_cmd = (char *)malloc(sizeof(char) * (ft_strlen(cmd_str) * 3 + 1));
	if (!temp_cmd)
		return (NULL);
	i = 0;
	j = 0;
	while (cmd_str[i])
	{
		if (is_redir_char(cmd_str[i]))
		{
			if (i > 0 && cmd_str[i - 1] != ' ')
				temp_cmd[j++] = ' ';
			temp_cmd[j++] = cmd_str[i++];
			if (cmd_str[i] && is_redir_char(cmd_str[i])
				&& cmd_str[i] == cmd_str[i - 1]) // s>>>|<<<|>>>  //s >>
				temp_cmd[j++] = cmd_str[i++];
			if (cmd_str[i] && cmd_str[i] != ' ')
				temp_cmd[j++] = ' ';
		}
		else
			temp_cmd[j++] = cmd_str[i++];
	}
	temp_cmd[j] = '\0';
	printf("%s", temp_cmd);
	tokens = ft_split(temp_cmd, ' ');
	free(temp_cmd);
	return (tokens);
}

int	main(void)
{
	int i = 0;
	char **cmd;
	char *line = "ls | > ls < as > > >>> ";
	cmd = tokenize_with_redirections(line);

	while (cmd[i])
	{
		printf("cmd[%d]: %s\n", i, cmd[i]);
		i++;
	}
}