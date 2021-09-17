#ifndef SO_LONG
#define SO_LONG
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include "mlx.h"
#include "libft.h"

#define BLOCK_SIZE 50

typedef struct s_map
{
    char **map;
    int success;
    int nb_lines;
    int nb_col;
    char *error_message;
} t_map;

typedef struct s_data
{
    void *image;
    char *image_addr;
    int bits_per_pixel;
    int size_line;
    int endian;

} t_data;

void read_map(char *file_path, t_map *result);
int is_valid_map_char(char *line);
int check_walls(t_map map);
int check_char(t_map map, char c);
int check_map(t_map *map);
void free_map(t_map map);
t_map new_map(void);


void draw_pixel(int x, int y,int color, t_data* data);
void draw_block(int x, int y, int color, t_data *data);

#endif