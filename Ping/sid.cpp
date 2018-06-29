#include <allegro.h> // You must include the Allegro Header file
/* Timer stuff */
volatile long speed_counter = 0; // A long integer which will store the value of the
                                             // speed counter.

void increment_speed_counter() // A function to increment the speed counter
{
  speed_counter++; // This will just increment the speed counter by one.
}
END_OF_FUNCTION(increment_speed_counter); // Make sure you tell it that it's the end of the
                                                                 // function

int main(int argc, char *argv[])
{
  allegro_init(); // Initialize Allegro
  install_keyboard(); // Initialize keyboard routines
  install_timer(); // Initialize the timer routines

  LOCK_VARIABLE(speed_counter);                 // Used to set the timer which regulates the game's
  LOCK_FUNCTION(increment_speed_counter); // speed.
  install_int_ex(increment_speed_counter, BPS_TO_TIMER(60)); // Set our BPS

  set_color_depth(16); // Set the color depth

  set_gfx_mode(GFX_AUTODETECT, 640,480,0,0); // Change our graphics mode to 640x480
  BITMAP *frame1 = load_bitmap("frame1.bmp", NULL); // Declare a bitmap and Load our picture in one single statement
BITMAP *frame2 = load_bitmap("frame2.bmp", NULL);
BITMAP *frame3 = load_bitmap("frame3.bmp", NULL);
BITMAP *buffer = create_bitmap(640, 480); // Declare and create a bitmap in a single statement
/* Declare some integers for later use */
int my_pic_x = 0;// Holds our pictures X coorinate
int my_pic_y = 0;// Holds our picture's Y coordinate
int frame_counter = 0; // A counter for which frame to draw
while(!key[KEY_ESC])//If the user hits escape, quit the program
{
while(speed_counter > 0)
{
  if(key[KEY_RIGHT]) // If the user hits the right key, change the picture's X coordinate
  {
    my_pic_x ++; // Moving right so up the X coordinate by 1
  }
  else if(key[KEY_LEFT]) // Ditto' - only for left key
  {
    my_pic_x --; // Moving left, so lower the X coordinate by 1
  }
  else if(key[KEY_UP]) // If the user hits the up key, change the picture's Y coordinate
  {
    my_pic_y --; // Moving up, so lower the Y coordinate by 1
  }
  else if(key[KEY_DOWN]) // Ditto' - only for down
  {
    my_pic_y ++; // Moving down, so up the Y coordinate by 1
  }

  speed_counter --;
  frame_counter ++;
  if(frame_counter > 240) // 60 * 4 = 240 (When frame counter = 60, 1 second has passed)
{
  frame_counter = 0;
}
} //Closing bracket for the while(speed_counter > 0) statment
// In the first second, draw the first frame
if(frame_counter < 60) // Less than a full second
{
  draw_sprite(buffer, frame1, my_pic_x, my_pic_y); // Draw the first frame
}
else if(frame_counter >= 60 && frame_counter < 120) // Between 1 and 2 seconds
{
  draw_sprite(buffer, frame2, my_pic_x, my_pic_y); // Draw the second frame
}
else if(frame_counter >= 120 && frame_counter < 180) // If we are between 2 and 3 seconds
{
  draw_sprite(buffer, frame1, my_pic_x, my_pic_y); // Draw the first frame again,
                                                                        // to acheive better effect
}
else // If we are over 3 seconds
{
  draw_sprite(buffer, frame3, my_pic_x, my_pic_y); // Draw the last frame.
}
blit(buffer, screen, 0,0,0,0,640,480); // Draw the buffer to the screen
  clear_bitmap(buffer);
}
destroy_bitmap(frame1);//Release the bitmap data
destroy_bitmap(frame2);//Release the bitmap data
destroy_bitmap(frame3);//Release the bitmap data
destroy_bitmap(buffer);//Release the bitmap data
return 0; // Exit with no errors
}
END_OF_MAIN() // This must be called right after the closing bracket of your MAIN function.
                      // It is Allegro specific.
