#include "../inc/cub3d.h"

//NO ./path_to_the_north_texture
//        SO ./path_to_the_south_texture
//        WE ./path_to_the_west_texture
//        EA ./path_to_the_east_texture
//        F 220,100,0
//C 225,30,0
//{"1111111111111111111111111",
//"1000000000110000000000001",
//"1011000001110000000000001",
//"1001000000000000000000001",
//"111111111011000001110000000000001",
//"100000000011000001110111111111111",
//"11110111111111011100000010001",
//"11110111111111011101010010001",
//"11000000110101011100000010001",
//"10000000000000001100000010001",
//"10000000000000001101010010001",
//"11000001110101011111011110N0111",
//"11110111 1110101 101111010001",
//"11111111 1111111 111111111111"}

int	main(int argc, char **argv)
{
    char **map;
    t_data data;
    t_raycast rc;

    (void)argv;
    (void)argc;

    map = malloc(sizeof (char*) * 14);
    map[0] = "1111111111111111111111111";
    map[1] = "1000000000110000000000001";
    map[2] = "1011000001110000000000001";
    map[3] = "100100000000000000000000111111111";
    map[4] = "111111111011000001110000000000001";
    map[5] = "100000000011000001110111111111111";
    map[6] = "11110111111111011100000010001";
    map[7] = "11110111111111011101010010001";
    map[8] = "11000000110101011100000010001";
    map[9] = "10000000000000001100000010001";
    map[10] = "10000000000000001101010010001";
    map[11] = "11000001110101011111011110N0111";
    map[12] = "11110111 1110101 101111010001";
    map[13] = "11111111 1111111 111111111111";

    ft_init(&rc);
    data.map = map;
    data.ceiling = 2552030;
    data.floor = 338238976;
    data.no = malloc(sizeof (char) * 21);
    data.no = "./textures/eagle.xpm";
    data.so = malloc(sizeof (char) * 22);
    data.so = "./textures/greystone.xpm";
    data.we = malloc(sizeof (char) * 19);
    data.we = "./textures/red.xpm";
    data.ea = malloc(sizeof (char) * 27);
    data.ea = "./textures/purplestone.xpm";
    rc.rx = 2147483647;
    rc.ry = 2147483647;
    rc.i = 1;
    rc.nblines = 14;
    rc.sizeline = 33;
    rc.config = data;
    rc.depart = 'S';
    rc.dx = 5;
    rc.dy = 13;
    rc.screenx = 0;
    rc.screeny = 0;
    ft_mlx(&rc);
}