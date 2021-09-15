#ifndef SO_LONG
#define SO_LONG
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include "mlx.h"
#include "libft.h"


typedef struct s_map
{
    char    **map;
    int     success;
    int     nb_lines;
    char    *error_message;
} t_map;


void read_map(char *file_path, t_map* result);
int is_valid_map_char(char *line);
int check_walls(t_map map);
int check_char(t_map map, char c);
int check_map(t_map *map);
void free_map(t_map map);
t_map new_map(void);

#endif