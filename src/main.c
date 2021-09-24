#include "so_long.h"

int start(t_map map)
{
    int width;
    int height;
    t_data data;

    data.map = &map;
    data.game = malloc(sizeof(t_game));
    data.mlx = mlx_init();
    set_block_size(&data);
    width = map.nb_col * data.map->block_sizex;
    height = map.nb_lines * data.map->block_sizey;
    if (data.mlx == NULL)
        return (-1);
    data.window = mlx_new_window(data.mlx, width, height, "So Long");
    data.image = mlx_new_image(data.mlx, width, height);
    data.image_addr = mlx_get_data_addr(data.image, &data.bits_per_pixel, &data.size_line, &data.endian);
    mlx_key_hook(data.window, on_key_press, &data);
    mlx_hook(data.window, 33, 1L << 17, &close_window, &data);
    mlx_hook(data.window, 15, 1L << 16, &refresh_window, &data);
    mlx_key_hook(data.window, on_key_press, &data);
    draw_map(data);
    init_game(&data);
    mlx_put_image_to_window(data.mlx, data.window, data.image, 0, 0);
    mlx_loop(data.mlx);

    printf("end loop");
    return (1);
}

int main(int argc, char **argv)
{
    t_map map;
    int i;

    i = 0;
    if (argc == 2)
    {
        map = new_map();
        read_map(argv[1], &map);
        if (map.success == 0 || check_map(&map) == -1)
        {
            free_map(map);
            printf("%s\n", map.error_message);
            return (0);
        }
        if (start(map) == -1)
            printf("Unable to stat mlx");
    }
}