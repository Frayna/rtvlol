/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aviau <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/01 08:22:24 by aviau             #+#    #+#             */
/*   Updated: 2016/12/05 07:31:25 by aviau            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef KEY_H
# define KEY_H

# ifdef _APPLE_
#  define LEFT key == 123
#  define RIGHT key == 124
#  define DOWN key == 125
#  define UP key == 126
#  define P_UP key == 116
#  define P_DOWN key == 121
#  define KP_0 key == 82
#  define KP_1 key == 83
#  define KP_2 key == 84
#  define KP_3 key == 85
#  define KP_4 key == 86
#  define KP_5 key == 87
#  define KP_6 key == 88
#  define KP_7 key == 89
#  define KP_8 key == 91
#  define KP_9 key == 92
#  define KP_P key == 69
#  define KP_M key == 78
#  define KP_F key == 67
#  define KP_D key == 75
#  define SPACE key == 49
#  define ESC key == 53
#  define NUM_1 key == 18
#  define NUM_2 key == 19
#  define NUM_3 key == 20
#  define NUM_4 key == 21
#  define NUM_5 key == 23
#  define NUM_6 key == 22
#  define NUM_7 key == 26
#  define NUM_8 key == 28
#  define NUM_9 key == 25
#  define NUM_0 key == 29
#  define KEY_R key == 15
#  define KEY_G key == 5
#  define KEY_B key == 11
#  define KEY_C key == 8
#  define CTRL (key == 256  || key == 269)
#  define SHIFT (key == 257  || key == 258)
# else
#  define LEFT   key == 65361
#  define RIGHT  key == 65363
#  define DOWN   key == 65364
#  define UP     key == 65362
#  define P_UP	 key == 65365
#  define P_DOWN key == 65366
#  define K_J    key == 106
#  define K_M    key == 109
#  define K_C    key == 99
#  define K_L    key == 108
#  define K_R    key == 114
#  define KP_0   key == 65438
#  define KP_1   key == 65436
#  define KP_2   key == 65433
#  define KP_3   key == 65435
#  define KP_4   key == 65430
#  define KP_5   key == 65437
#  define KP_6   key == 65432
#  define KP_7   key == 65429
#  define KP_8   key == 65431
#  define KP_9   key == 65434
#  define KP_P   key == 65451
#  define KP_M   key == 65453
#  define KP_F   key == 65450
#  define KP_D   key == 65455
#  define SPACE  key == 32
#  define ESC    key == 65307
#  endif

# define ROT_XP 0x00000001
# define ROT_XM 0x00000002
# define ROT_YP 0x00000004
# define ROT_YM 0x00000008
# define ROT_ZP 0x00000010
# define ROT_ZM 0x00000020
# define POS_XP 0x00000040
# define POS_XM 0x00000080
# define POS_YP 0x00000100
# define POS_YM 0x00000200
# define POS_ZP 0x00000400
# define POS_ZM 0x00000800
# define SCALEP 0x00001000
# define SCALEM 0x00002000
# define FVIEWP 0x00004000
# define FVIEWM 0x00008000
# define CO_RED 0x00010000
# define CO_GRE 0x00020000
# define CO_BLU 0x00040000
# define PSHIFT 0x00080000
# define P_CTRL 0x00100000

# define REDRAW 0x10000000

#endif
