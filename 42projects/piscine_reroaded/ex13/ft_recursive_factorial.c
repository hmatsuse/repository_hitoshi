/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recursive_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmatsuse <hmatsuse@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/08 00:30:48 by hmatsuse          #+#    #+#             */
/*   Updated: 2020/04/08 00:30:48 by hmatsuse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int     ft_recursive_factorial(int nb)
{
    if (nb < 0)
        return (0);
    if (nb == 0)
        return (1);
    else    
        return (nb * ft_recursive_factorial(nb - 1));
}
