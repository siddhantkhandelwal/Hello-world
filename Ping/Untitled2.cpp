#include<allegro.h>
int main()
{
    allegro_init();
    install_keyboard();
    set_color_depth(16);
    set_gfx_mode(GFX_AUTODETECT, 1024, 768, 0,0);
    BITMAP*creed=NULL;
    BITMAP*buffer=NULL;
    buffer=create_bitmap(1024,768);
    acquire_screen();
    clear_to_color(screen, makecol(255, 255, 255));
    creed = load_bitmap("wel.bmp", NULL);
    blit(creed, screen, 0,0,341,256,1024,768);
    rest(3000);
    clear_to_color(screen, makecol(96,169,23));
    readkey();
    return 0;
}
END_OF_MAIN();
