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
char	*ft_rand_str_alpnum(int size);

int main(int argc, char *argv[])
{
	char c;
	int fd;
	char *filename;
	char *fileNparts[2];
	size_t sizeFparts[3];

	c = 'a';
	fd = 3;
	if (argc == 3)
	{
		fd = ft_atoi(argv[1]);
		c = argv[2][0];
	}
	if (fd > 2)
	{
		fileNparts[0] = "/tmp/fdtmp_";
		fileNparts[1] = ft_rand_str_alpnum(5);
		sizeFparts[0] = ft_strlen(fileNparts[0]);
		sizeFparts[1] = ft_strlen(fileNparts[1]);
		filename = malloc((sizeFparts[0] + sizeFparts[1] + 1) * sizeof(char));
		ft_bzero(filename, sizeFparts[0] + sizeFparts[1] + 1);
		sizeFparts[2] = ft_strlcpy(filename, fileNparts[0], sizeFparts[0]);
		if (sizeFparts[0] != sizeFparts[2])
		{
			printf("Error: size fileNparts[0] --- %ld vs %ld",
				   sizeFparts[0],
				   sizeFparts[2]);
			return (1);
		}
		sizeFparts[2] = ft_strlcat(filename, fileNparts[1], sizeFparts[0] + sizeFparts[1] + 10);
		if (sizeFparts[0] + sizeFparts[1] != sizeFparts[2] + 1)
		{
			printf("Error: size fileNparts[1] --- %ld vs %ld",
				   sizeFparts[0] + sizeFparts[1],
				   sizeFparts[2] + 1);
			return (1);
		}
		printf("%s\n",filename);
		printf("----\nfd [%d], c[%c]\n---\n", fd, c);
		free(filename);
	}
	
	ft_putchar_fd(c, 1);
    return (0);
}

