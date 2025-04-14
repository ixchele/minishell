/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihajji <ihajji@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 10:28:22 by ihajji            #+#    #+#             */
/*   Updated: 2025/04/14 10:28:22 by ihajji           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H

typedef enum e_token_type
{
	T_WORD,
	T_PIPE,
	T_REDIR_IN,
	T_REDIR_OUT,
	T_REDIR_APPEN,
	T_HEREDOC,
	T_DBL_QTE_STR,
	T_SNGL_QTE_STR,
	T_OPEN_PAREN,
	T_CLOSE_PAREN,
	T_LOGICAL_AND,
	T_LOGICAL_OR,
}	t_token_type;

#endif // !PARSING_H
