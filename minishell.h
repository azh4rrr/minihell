/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azmakhlo <azmakhlo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/10 13:23:24 by azmakhlo          #+#    #+#             */
/*   Updated: 2025/05/28 16:26:44 by azmakhlo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "libft/libft.h"
# include "readline/history.h"
# include "readline/readline.h"
# include <stdio.h>
# include <unistd.h>

typedef enum s_type
{
	D_OUTFILE,
	D_APPEND,
	D_INFILE,
	D_HERDOC
}						t_type;

typedef struct s_redirec
{
	char				*name;
	t_type				type;
	struct s_redirec	*next;
}						t_redirec;

typedef struct s_cmd
{
	char				**cmd;
	t_redirec			*redirec;
	struct s_cmd		*prev;
	struct s_cmd		*next;
}						t_cmd;

/*syntax_error.c*/

int						syntax_error(char *line);

/* utils_a.c */
int						free_cmd_array(char **cmds);
int						allocate_token(t_cmd **token, char **cmds);
int						setup_cmd_struct(t_cmd *current, char *cmd_str);
int						create_next_node(t_cmd *current, int has_next);

/* utils_b.c */
int						arg_create(t_cmd *token, char **cmds);
t_cmd					*handle_token_error(char **cmds, t_cmd *token);
t_cmd					*tokenization(char *line);
void					print_cmd_list(t_cmd *token);
void					free_cmd_node(t_cmd *node);

/* main.c */
void					free_cmd_list(t_cmd *token);
int						process_line(char *line, t_cmd **token_ptr);

/* redirection.c */
t_redirec				*create_redirec_node(char *name, t_type type);
void					add_redirec_node(t_redirec **head, t_redirec *new);
void					free_redirec_list(t_redirec *head);
int						check_redirection_type(const char *str);
void					print_redirec_list(t_redirec *head);
char					**tokenize_with_redirections(char *cmd_str);

/* parse_redir.c */
int						count_valid_tokens(char **tokens);
char					*build_cmd_string(char **tokens, int token_count);
int						add_redirections(char **tokens,
							t_redirec **redirec_list);
char					*parse_redirections(char *cmd_str,
							t_redirec **redirec_list);
int						setup_cmd_struct_with_redirection(t_cmd *current,
							char *cmd_str);
int						is_redir_char(char c);

/* doubly_linked_utils.c */
t_cmd					*get_first_cmd(t_cmd *node);

/* Color Codes */
# define COLOR_RESET "\033[0m"
# define COLOR_RED "\033[1;31m"
# define COLOR_GREEN "\033[1;32m"
# define COLOR_YELLOW "\033[1;33m"
# define COLOR_BLUE "\033[1;34m"
# define COLOR_MAGENTA "\033[1;35m"
# define COLOR_CYAN "\033[1;36m"
# define COLOR_WHITE "\033[1;37m"

#endif