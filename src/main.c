
#include "mlx.h"
#include <stdio.h>

int main()
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
}