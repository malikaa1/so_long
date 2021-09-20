#ifndef SO_LONG
#define SO_LONG
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include "mlx.h"
#include "libft.h"

#define BLOCK_SIZE 50
#define WHITE 0x00FFFFFF
#define BROWN 0x00a85e32
#define BLACK 0x00000000
#define RED 0x00f00020
#define BLUE 0x000080ff

typedef struct s_map
{
    char **map;
    int success;
    int nb_lines;
    int nb_col;
    char *error_message;
} t_map;

typedef struct s_point
{
    int x;
    int y;

} t_point;
typedef struct s_game
{
    t_point position;
    int moves;

} t_game;

typedef struct s_data
{
    void *image;
    char *image_addr;
    int bits_per_pixel;
    int size_line;
    int endian;
    void *mlx;
    void *window;

    t_game *game;
    t_map *map;

} t_data;

void read_map(char *file_path, t_map *result);
int is_valid_map_char(char *line);
int check_walls(t_map map);
int check_char(t_map map, char c);
int check_map(t_map *map);
void free_map(t_map map);
t_map new_map(void);

t_point find_position(t_map map);
void init_game(t_data *data);
char find_at(t_map map, t_point point);

void draw_pixel(t_point point, int color, t_data *data);
void draw_block(t_point point, int color, t_data *data);
void draw_map(t_data data);
void close_window(t_data *data);
void on_key_press(int code, t_data *data);
void move_down(t_data *data);
void move_right(t_data *data);
void move_left(t_data *data, t_point next_position);
#endif