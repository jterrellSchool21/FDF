/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jterrell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/03 17:27:31 by jterrell          #+#    #+#             */
/*   Updated: 2020/08/04 12:59:18 by whool199         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *destination, const void *source, size_t n)
{
	unsigned char		*ptr;
	const unsigned char	*ptr2;

	if (!destination && !source)
		return (0);
	ptr = (unsigned char*)destination;
	ptr2 = (unsigned char*)source;
	while (n-- > 0)
		*(ptr++) = *(ptr2++);
	return (destination);
}
