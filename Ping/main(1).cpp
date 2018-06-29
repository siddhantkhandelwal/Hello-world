#include<allegro.h>
#include<process.h>
int main()
{
    allegro_init();
    install_keyboard();
    set_color_depth(32);
    set_gfx_mode(GFX_AUTODETECT, 1024, 768, 0,0);
    BITMAP*creed=NULL;
    BITMAP*buffer=NULL;
    buffer=create_bitmap(1024,768);
    acquire_screen();
    clear_to_color(screen, makecol(255, 255, 255));
    creed = load_bitmap("pic1.bmp", NULL);
    blit(creed, screen, 0,0,0,0,1024,768);
    rest(2000);
    clear_to_color(screen, makecol(255,255,255));
    creed = load_bitmap("pic2.bmp", NULL);
    blit(creed, screen, 0,0,0,0,1024,768);
    rest(5000);
    creed = load_bitmap("pic3.bmp", NULL);
    blit(creed, screen, 0,0,0,0,1024,768);
    rest(8000);
    creed = load_bitmap("joker.bmp", NULL);
    blit(creed, screen, 0,0,0,0,1024,768);
    rest(8000);
    creed = load_bitmap("deathstroke.bmp", NULL);
    blit(creed, screen, 0,0,0,0,1024,768);
    destroy_bitmap(creed);
    readkey();
    return 0;
}
END_OF_MAIN();
