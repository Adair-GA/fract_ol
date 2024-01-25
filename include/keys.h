/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adair <adair@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 22:58:38 by adair             #+#    #+#             */
/*   Updated: 2024/01/25 12:01:51 by adair            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef KEYS_H
# ifdef __APPLE__
#  define ESC 53
#  define LEFT_ARR 123
#  define RIGHT_ARR 124
#  define DOWN_ARR 125
#  define UP_ARR 126

# elif __unix
#  define ESC 0xFF1B
#  define LEFT_ARR 0xFF51
#  define RIGHT_ARR 0xFF53
#  define DOWN_ARR 0xFF54
#  define UP_ARR 0xFF52
#  define UPP_R 0x0052
#  define LOW_R 0x0072

# endif
#endif
