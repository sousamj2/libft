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
char	*ft_set_filename();

char	*ft_set_filename()
{
	char *filename;
	char *fileNparts[2];
	size_t sizeFparts[3];
	size_t filenamesize;

	fileNparts[0] = "/tmp/fd_";
	fileNparts[1] = ft_rand_str_alpnum(5);
	sizeFparts[0] = ft_strlen(fileNparts[0]);
	sizeFparts[1] = ft_strlen(fileNparts[1]);
	filenamesize = sizeFparts[0] + sizeFparts[1];
	filename = malloc((filenamesize + 1) * sizeof(char));
	ft_bzero(filename, filenamesize + 1);
	sizeFparts[2] = ft_strlcpy(filename, fileNparts[0], sizeFparts[0] + 1);
	if (sizeFparts[0] != sizeFparts[2])
	{
		printf("Error: size fileNparts[0] --- %ld vs %ld",
			   sizeFparts[0],
			   sizeFparts[2]);
		return (NULL);
	}
	sizeFparts[2] = ft_strlcat(filename, fileNparts[1], filenamesize + 11);
	if (sizeFparts[0] + sizeFparts[1] != sizeFparts[2])
	{
		printf("Error: size fileNparts[1] --- %ld vs %ld",
			   sizeFparts[0] + sizeFparts[1],
			   sizeFparts[2]);
		return (NULL);
	}
	free(fileNparts[1]);
	return (filename);
}

int main(int argc, char *argv[])
{
	int nbr;
	int fd;
	char *filename;
	srand(time(0));

	nbr = 500;
	fd = 5;
	if (argc >= 3)
	{
		fd = ft_atoi(argv[1]);
		nbr = ft_atoi(argv[2]);
	}
	if (fd > 2)
	{
		filename = ft_set_filename();
		printf("%s", filename);
		fd = open(filename, O_WRONLY|O_CREAT, S_IRWXU);
		free(filename);
	}
	ft_putnbr_fd(nbr, fd);
	if (fd > 2)
		close(fd);
    return (0);
}
