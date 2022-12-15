/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: huaydin <huaydin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 00:02:12 by huaydin           #+#    #+#             */
/*   Updated: 2022/12/12 00:02:12 by huaydin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

static void	ft_free2(void *tmp)
{
	if (tmp)
		free(tmp);
}

void	ft_free(t_main *main)
{
	ft_free2(main->img->coin);
	ft_free2(main->img->wall);
	ft_free2(main->img->way);
	ft_free2(main->img->exit);
	ft_free2(main->img->ple);
	ft_free2(main->img->pr);
	ft_free2(main->img->pu);
	ft_free2(main->img->pd);
	ft_free2(main->img);
	ft_free2(main->map->map);
	ft_free2(main->map);
	ft_free2(main->win);
	ft_free2(main->mlx);

}

static int	ft_sizeofn(long m)
{
	int	i;

	i = 1;
	if (m < 0)
		i++;
	while (m > 9 || m < -9)
	{
		if (m < 0)
			m = -m;
		m = m / 10;
		i++;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	char	*ptr;
	int		len;
	long	nlong;

	nlong = (long)n;
	len = ft_sizeofn(nlong);
	ptr = ft_calloc(len + 1, sizeof(char));
	if (!ptr)
		return (NULL);
	ptr[len] = '\0';
	if (n == 0)
		ptr[0] = '0';
	if (nlong < 0)
	{
		ptr[0] = '-';
		nlong = -nlong;
	}
	while (len-- >= 0 && nlong > 0 && ptr[len] != '-')
	{
		ptr[len] = nlong % 10 + '0';
		nlong = nlong / 10;
	}
	return (ptr);
}

size_t	ft_strlen(const char *s)
{
	size_t	length;

	length = 0;
	while (s[length])
		length++;
	return (length);
}

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	while ((*s1 || *s2) && (n > 0))
	{
		if (*s1 != *s2)
			return ((unsigned char)*s1 - (unsigned char)*s2);
		n--;
		s1++;
		s2++;
	}
	return (0);
}

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char	*ptr;

	ptr = (unsigned char *)s;
	while (n--)
	{
		ptr[n] = (unsigned char)c;
	}
	return (s);
}

void	*ft_calloc(size_t nmemb, size_t size)
{
	unsigned char	*ptr;

	ptr = (unsigned char *)malloc(nmemb * size);
	if (ptr)
		ft_memset(ptr, 0, nmemb * size);
	return (ptr);
}