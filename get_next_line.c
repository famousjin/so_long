/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elraira- <elraira-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/03 10:39:55 by elraira-          #+#    #+#             */
/*   Updated: 2021/09/05 14:05:59 by elraira-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_get_line(char *save)
{
	int		i;
	char	*copy_line;

	i = 0;
	if (!save[i])
		return (NULL);
	while (save[i] && save[i] != '\n')
		i++;
	copy_line = (char *)malloc(sizeof(char) * (i + 2));
	if (!copy_line)
		return (NULL);
	i = 0;
	while (save[i] && save[i] != '\n')
	{
		copy_line[i] = save[i];
		i++;
	}
	if (save[i] == '\n')
	{
		copy_line[i] = save[i];
		i++;
	}
	copy_line[i] = '\0';
	return (copy_line);
}

char	*ft_save(char *save)
{
	int		i;
	int		c;
	char	*new_line;

	i = 0;
	while (save[i] && save[i] != '\n')
		i++;
	if (!save[i])
	{
		free(save);
		return (NULL);
	}
	new_line = (char *)malloc(sizeof(char) * (ft_strlen(save) - i + 1));
	if (!new_line)
		return (NULL);
	i++;
	c = 0;
	while (save[i])
		new_line[c++] = save[i++];
	new_line[c] = '\0';
	free(save);
	return (new_line);
}

char	*ft_copy_buffer(int fd, char *save)
//그냥 버퍼에 저장하는 역할
{
	char	*buffer;
	int		read_bytes;

	buffer = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buffer)
		return (NULL);
	read_bytes = 1;
	while (!ft_strchr(save, '\n') && read_bytes != 0)//엔터를 찾은곳에서 멈춤
	{
		read_bytes = read(fd, buffer, BUFFER_SIZE);
		if (read_bytes == -1)
		{
			free(buffer);
			return (NULL);
		}
		buffer[read_bytes] = '\0';
		save = ft_strjoin(save, buffer);
	}
	free(buffer);
	return (save);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*save;//엔터 다음 단어부터 시작

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	save = ft_copy_buffer(fd, save);//버퍼에 자료를 저장해 놓음
	if (!save)
		return (NULL);
	line = ft_get_line(save);//실제로 출력할 라인 저장
	save = ft_save(save);//어디까지 출력했는지 static으로 save에 저장해줌
	return (line);
}
