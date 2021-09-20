#include "so_long.h"

int start(t_map map)
{
    int width;
    int height;
    t_data data;

    data.map = &map;
    data.game = malloc(sizeof(t_game));
    width = map.nb_col * BLOCK_SIZE;
    height = map.nb_lines * BLOCK_SIZE;
    data.mlx = mlx_init();
    if (data.mlx == NULL)
        return (-1);
    data.window = mlx_new_window(data.mlx, width, height, "So Long");
    data.image = mlx_new_image(data.mlx, width, height);
    data.image_addr = mlx_get_data_addr(data.image, &data.bits_per_pixel, &data.size_line, &data.endian);
    mlx_key_hook(data.window, on_key_press, &data);
    mlx_hook(data.window, 33, 1L << 17, &close_window, &data);
    draw_map(data);
    init_game(&data);
    mlx_put_image_to_window(data.mlx, data.window, data.image, 0, 0);
    mlx_loop(data.mlx);
    free(data.game);
    return (1);
}

int main(int argc, char **argv)
{
    t_map map;
    int i;

    i = 0;
    if (argc != 2)
        return (1);
    map = new_map();
    read_map(argv[1], &map);
    if (map.success == 0)
    {
        printf("%s\n", map.error_message);
        return (0);
    }

    if (check_map(&map) == -1)
    {
        printf("%s\n", map.error_message);
        return (0);
    }
    while (i < map.nb_lines)
    {
        printf("%s\n", map.map[i++]);
    }
    if (start(map) == -1)
        printf("Unable to stat mlx");

    free_map(map);
}