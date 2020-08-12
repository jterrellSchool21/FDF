/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jterrell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/04 17:25:15 by jterrell          #+#    #+#             */
/*   Updated: 2020/08/04 12:59:18 by whool199         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char			*ft_strcat(char *destination, const char *append)
{
	int i;
	int j;

	i = 0;
	while (destination[i] != '\0')
		i++;
	j = 0;
	while (append[j] != '\0')
	{
		destination[i + j] = append[j];
		j++;
	}
	destination[i + j] = '\0';
	return (destination);
}
