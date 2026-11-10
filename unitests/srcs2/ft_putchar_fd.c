/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marisous <marisous@student.42lisb...>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/01 18:09:04 by marisous          #+#    #+#             */
/*   Updated: 2026/11/01 18:09:04 by marisous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <fcntl.h>
#include <stdio.h>
#include <time.h>

char	*ft_rand_str_alpnum(int size);
char	*ft_set_filename(void);

char	*ft_set_filename(void)
{
	char	*filename;
	char	*file_nparts[2];
	size_t	size_fparts[3];
	size_t	filenamesize;

	file_nparts[0] = "/tmp/fd_";
	file_nparts[1] = ft_rand_str_alpnum(5);
	size_fparts[0] = ft_strlen(file_nparts[0]);
	size_fparts[1] = ft_strlen(file_nparts[1]);
	filenamesize = size_fparts[0] + size_fparts[1];
	filename = malloc((filenamesize + 1) * sizeof(char));
	ft_bzero(filename, filenamesize + 1);
	size_fparts[2] = ft_strlcpy(filename, file_nparts[0], size_fparts[0] + 1);
	if (size_fparts[0] != size_fparts[2])
	{
		printf("Error: size file_nparts[0] --- %ld vs %ld",
			size_fparts[0],
			size_fparts[2]);
		return (NULL);
	}
	size_fparts[2] = ft_strlcat(filename, file_nparts[1], filenamesize + 11);
	if (size_fparts[0] + size_fparts[1] != size_fparts[2])
	{
		printf("Error: size file_nparts[1] --- %ld vs %ld",
			size_fparts[0] + size_fparts[1],
			size_fparts[2]);
		return (NULL);
	}
	free(file_nparts[1]);
	return (filename);
}

int	main(int argc, char *argv[])
{
	char	c;
	int		fd;
	char	*filename;

	srand(time(0));
	c = 'a';
	fd = 5;
	if (argc >= 3)
	{
		fd = ft_atoi(argv[1]);
		c = argv[2][0];
	}
	if (fd > 2)
	{
		filename = ft_set_filename();
		printf("%s", filename);
		fd = open(filename, O_WRONLY | O_CREAT, S_IRWXU);
		free(filename);
	}
	ft_putchar_fd(c, fd);
	if (fd > 2)
		close(fd);
	return (0);
}
