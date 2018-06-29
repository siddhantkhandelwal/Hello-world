#include<iostream>
#include <allegro.h>
#include <cstdlib>
#include <time.h>
#include<conio.h>
int ball_x = 320, ball_y = 240, ball_tempX = 320, ball_tempY = 240, p1_x = 20, p1_y = 210, p1_tempX = 20, p1_tempY = 210, p2_x = 620, p2_y = 210, p2_tempX = 620, p2_tempY = 210;

time_t secs;    //The seconds on the system clock will be stored here
                //this will be used as the seed for srand()

int dir;     //This will keep track of the circles direction
            //1= up and left, 2 = down and left, 3 = up and right, 4 = down and right

BITMAP *buffer; //This will be our temporary bitmap for double buffering

void moveBall(){
    ball_tempX = ball_x;
    ball_tempY = ball_y;

    if (dir == 1 && ball_x > 5 && ball_y > 5){

         if( ball_x == p1_x + 15 && ball_y >= p1_y && ball_y <= p1_y + 60){
                  dir = rand()% 2 + 3;
         }else{
                 --ball_x;
                 --ball_y;
         }

    } else if (dir == 2 && ball_x > 5 && ball_y < 475){

         if( ball_x == p1_x + 15 && ball_y >= p1_y && ball_y <= p1_y + 60){
                  dir = rand()% 2 + 3;
         }else{
                 --ball_x;
                 ++ball_y;
         }

    } else if (dir == 3 && ball_x < 635 && ball_y > 5){

         if( ball_x + 5 == p2_x && ball_y >= p2_y && ball_y <= p2_y + 60){
                  dir = rand()% 2 + 1;
         }else{
                 ++ball_x;
                 --ball_y;
         }

    } else if (dir == 4 && ball_x < 635 && ball_y < 475){

         if( ball_x + 5 == p2_x && ball_y >= p2_y && ball_y <= p2_y + 60){
                  dir = rand()% 2 + 1;
         }else{
                 ++ball_x;
                 ++ball_y;
         }

    } else {

        if (dir == 1 || dir == 3)    ++dir;
        else if (dir == 2 || dir == 4)    --dir;

    }

    acquire_screen();
    circlefill ( buffer, ball_tempX, ball_tempY, 5, makecol( 255,255, 255));
    circlefill ( buffer, ball_x, ball_y, 5, makecol( 140, 0, 149));
    draw_sprite( screen, buffer, 0, 0);
    release_screen();

    rest(2);

}

void p1Move(){

    p1_tempY = p1_y;

    if( key[KEY_W] && p1_y > 0){

        --p1_y;

    } else if( key[KEY_S] && p1_y < 420){

        ++p1_y;

    }

    acquire_screen();
    rectfill( buffer, p1_tempX, p1_tempY, p1_tempX + 10, p1_tempY + 60, makecol (255,255,255));
    rectfill( buffer, p1_x, p1_y, p1_x + 10, p1_y + 60, makecol (0, 130, 153));
    release_screen();

}

void p2Move(){

    p2_tempY = p2_y;

    if( key[KEY_UP] && p2_y > 0){

        --p2_y;

    } else if( key[KEY_DOWN] && p2_y < 420){

        ++p2_y;

    }

    acquire_screen();
    rectfill( buffer, p2_tempX, p2_tempY, p2_tempX + 10, p2_tempY + 60, makecol (255,255,255));
    rectfill( buffer, p2_x, p2_y, p2_x + 10, p2_y + 60, makecol ( 220, 87, 46));
    release_screen();

}

void startNew(){

    clear_keybuf();
    readkey();
    clear_to_color( buffer, makecol( 255, 255, 255));

    ball_x = 320;
    ball_y = 240;

    p1_x = 20;
    p1_y = 210;

    p2_x = 620;
    p2_y = 210;

}

void checkWin(){

    if ( ball_x < p1_x){
        textout_ex( screen, font, "Joker Wins!!", 320, 240, makecol( 255, 0, 0), makecol( 255, 255, 255));
        buffer = load_bitmap("jokwins.bmp", NULL);
        rest(5000);
        blit(buffer, screen, 0,0,0,0,640,480);
        rest(2000);
        startNew();
    } else if ( ball_x > p2_x){
        textout_ex( screen, font, "Deathstroke Wins!", 320, 240, makecol( 255, 0, 0), makecol( 255, 255, 255));
        buffer = load_bitmap("deathwins.bmp", NULL);
        rest(5000);
        blit(buffer, screen, 0,0,0,0,640,480);
        rest(2000);
        startNew();
    }

}

void setupGame(){

    acquire_screen();
    buffer = load_bitmap("back.bmp", NULL);
    blit(buffer, screen, 0,0,0,0,640,480);
    rectfill( buffer, p1_x, p1_y, p1_x + 10, p1_y + 60, makecol ( 0, 0, 255));
    rectfill( buffer, p2_x, p2_y, p2_x + 10, p2_y + 60, makecol ( 0, 0, 255));
    circlefill ( buffer, ball_x, ball_y, 5, makecol( 128, 255, 0));
    draw_sprite( screen, buffer, 0, 0);
    release_screen();

    time(&secs);
    srand( (unsigned int)secs);
    dir = rand() % 4 + 1;

}

int main(){



    allegro_init();
    install_keyboard();
    set_color_depth(32);
    set_gfx_mode( GFX_AUTODETECT, 640, 480, 0, 0);
    buffer = create_bitmap( 640, 480);
    clear_to_color(screen, makecol(255, 255, 255));
    buffer = load_bitmap("pic1.bmp", NULL);
    blit(buffer, screen, 0,0,0,0,640,480);
    rest(2000);
    buffer = load_bitmap("pong.bmp", NULL);
    blit(buffer, screen, 0,0,0,0,640,480);
    rest(3000);
    buffer = load_bitmap("jok.bmp", NULL);
    blit(buffer, screen, 0,0,0,0,640,480);
    rest(3000);
    buffer = load_bitmap("joker.bmp", NULL);
    blit(buffer, screen, 0,0,0,0,640,480);
    rest(5000);
    buffer = load_bitmap("death.bmp", NULL);
    blit(buffer, screen, 0,0,0,0,640,480);
    rest(3000);
    buffer = load_bitmap("deathstroke.bmp", NULL);
    blit(buffer, screen, 0,0,0,0,640,480);
    rest(5000);
    buffer = load_bitmap("jokdeath.bmp", NULL);
    blit(buffer, screen, 0,0,0,0,640,480);
    rest(5000);
    setupGame();

    while( !key[KEY_ESC]){

        p1Move();
        p2Move();
        moveBall();
        checkWin();

    }

    return 0;

}
END_OF_MAIN();
