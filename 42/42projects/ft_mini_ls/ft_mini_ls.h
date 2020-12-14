#ifndef FT_MINI_LS_H
# define FT_MINI_LS_H

# include <stdlib.h>
# include <dirent.h>
# include <unistd.h>
# include <sys/stat.h>
# include "libft/libft.h"

typedef struct  name_time 
{
	char		*name;
	long		sec;
	time_t		nsec;
}				n_t;

#endif