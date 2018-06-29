#include <allegro.h>

BITMAP *xSprite;
BITMAP *oSprite;

int main(){

    allegro_init();
    install_keyboard();
    set_color_depth(16);
    set_gfx_mode( GFX_AUTODETECT, 640, 480, 0, 0);

    xSprite = load_bitmap( "x.bmp", NULL);

    oSprite = load_bitmap( "o.bmp", NULL);

    acquire_screen();

    line( screen, 200, 0, 200, 480, makecol( 255, 255, 255));
    line( screen, 400, 0, 400, 480, makecol( 255, 255, 255));
    line( screen, 0, 150, 680, 150, makecol( 255, 255, 255));
    line( screen, 0, 300, 680, 300, makecol( 255, 255, 255));

    draw_sprite( screen, xSprite, 0, 0);
    draw_sprite( screen, oSprite, 200, 0);
    draw_sprite( screen, xSprite, 400, 0);

    draw_sprite( screen, oSprite, 0, 150);
    draw_sprite( screen, xSprite, 200, 150);
    draw_sprite( screen, oSprite, 400, 150);

    draw_sprite( screen, oSprite, 0, 300);
    draw_sprite( screen, xSprite, 200, 300);
    draw_sprite( screen, oSprite, 400, 300);

    release_screen();

    readkey();

    return 0;

}
END_OF_MAIN();
