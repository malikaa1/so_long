#include "so_long.h"

int main(int argc, char **argv)
{
    t_map map;
    int i;

    i = 0;
    if (argc != 2)
        return (1);
    map = new_map();
    read_map(argv[1], &map);
    if (check_map(&map) == -1)
    {
        printf("%s\n", map.error_message);
        return (0);
    }
    while (i < map.nb_lines)
    {
        printf("%s\n", map.map[i++]);
    }
    free_map(map);
}
/*int main()
{
    int width = 300, height = 300;

    void *mlx = mlx_init();
    void *image = mlx_new_image(mlx, width, height);
    int bits_per_pixel;
    int size_line;
    int endian;
    int color = 0x00FFFFFF;

    char *addr = mlx_get_data_addr(image, &bits_per_pixel, &size_line, &endian);
    printf("endian = %d\n", endian);

    for (int y = 0; y < height; y++)
    {
        for (int x = 0; x < width; x++)
        {
            char *pixel = addr + (y * size_line) + (x * (bits_per_pixel / 8));
            *(unsigned int *)pixel = color;
        }
    }

    void *window = mlx_new_window(mlx, width, height, "So Long");

    mlx_put_image_to_window(mlx, window, image, 0, 0);

    mlx_loop(mlx);

    return 0;
}*/