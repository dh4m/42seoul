/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_signal.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dham <dham@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/09 13:47:04 by dham              #+#    #+#             */
/*   Updated: 2022/11/10 21:40:15 by dham             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SIGNAL_H
# define FT_SIGNAL_H

void	ft_readline_signal_set(void);
void	ft_excute_signal_set(void);
void	ft_default_signal_set(void);

void	readline_proc(int sig);
void	heredoc_proc(int sig);
int		empty_event(void);

#endif