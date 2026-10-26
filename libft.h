/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marisous <marisous@student.42lisb...>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/25 15:36:15 by marisous          #+#    #+#             */
/*   Updated: 2026/10/26 19:28:50 by marisous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

typedef long unsigned int	t_size_t;

int			ft_isalpha(int c);
int			ft_isdigit(int c);
int			ft_isalnum(int c);
int			ft_isascii(int c);
int			ft_isprint(int c);
void		*ft_memset(void *s, int c, t_size_t n);
void		ft_bzero(void *s, t_size_t n);
t_size_t	ft_strlen(const char *s);
void		*ft_memcpy(void *dest, const void *src, t_size_t n);
void		*ft_memmove(void *dest, const void *src, t_size_t n);

#endif
