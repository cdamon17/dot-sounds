#include <MeggyJrSimple.h>
// global variables go here
int xcoord = 0;
int ycoord = 0;
int C3x = 4; // help from Brennan Brown for making multiple
int C3y = 5; // points work
int A3x = 2;
int A3y = 3;

void setup()
{
  MeggyJrSimpleSetup();
  Serial.begin(9600); // code to show the points of variables
}




void loop() // loop code that goes through loop
{
  shift();
  DrawPx(C3x,C3y,Violet);
  DrawPx(A3x,A3y,Green);
  DrawPx(xcoord,ycoord,Blue); // draw dot
  dotsound(); // make sounds from dots
  DisplaySlate();
  delay(150);
  ClearSlate();
}


void shift() // taken from Maze_Game of Brennan Brown
{
  CheckButtonsDown();
  if (Button_Right)
    {
      if (xcoord < 7)
      xcoord = xcoord + 1; // indented because belongs to inner if statement;
                           //  could also say xcoord++
      if (xcoord == 7)
        Tone_Start (ToneC3,100);
    }
    
  if (Button_Left)
    {
      if (xcoord > 0)
      xcoord = xcoord - 1;
      if (xcoord == 0)
      Tone_Start (ToneC3,100);
    }
    
  if (Button_Up)
    {
      if (ycoord < 7)
      ycoord = ycoord + 1;
      if (ycoord == 7)
      Tone_Start (ToneC3,100); // play error sound when go off screen
    }
    
   if (Button_Down)
    {
      if (ycoord > 0)
      ycoord = ycoord - 1;
      if (ycoord == 0)
      Tone_Start (ToneC3,100); // play error sound when go off screen
    }
}

void dotsound() // simple code to make dots create sound
{
 CheckButtonsDown();
 if (Button_A)
 {
   if (ReadPx(C3x,C3y) == Blue)
   {
     Tone_Start (ToneC3,300);
   }
   DrawPx(0,0,15); // line to check that comand is going thorugh

 
 if (ReadPx(A3x,A3y) == Blue)
   {
     Tone_Start (ToneA3,300);
   }
   DrawPx(0,0,15); // line to check that comand is going thorugh
 }
}
