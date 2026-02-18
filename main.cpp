#include<raylib.h>
int main(){
  InitWindow(800, 800,"Ball");
  SetTargetFPS(24);
  int ballx=400;
  int bally=400;
  
  //game loop
  while(WindowShouldClose() == false){
    //1. event handling here
    if(IsKeyDown(KEY_W)){bally-=5;}
    if(IsKeyDown(KEY_S)){bally+=5;}
    if(IsKeyDown(KEY_A)){ballx-=5;}
    if(IsKeyDown(KEY_D)){ballx+=5;}

    //2. position update here


    //3. Drawing here
    BeginDrawing();
    ClearBackground(GREEN);
    DrawCircle(ballx,bally,30,WHITE);
    EndDrawing();
  }
  CloseWindow();
  return 0;
}