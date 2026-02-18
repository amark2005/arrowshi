#include<raylib.h>
int main(){
  InitWindow(800, 800,"Ball");
  SetTargetFPS(24);
  int ballx=400;
  int bally=400;
  int ballspeed=10;
  //game loop
  while(WindowShouldClose() == false){
    //1. event handling here
    if(IsKeyDown(KEY_W)){bally-=ballspeed;}
    if(IsKeyDown(KEY_S)){bally+=ballspeed;}
    if(IsKeyDown(KEY_A)){ballx-=ballspeed;}
    if(IsKeyDown(KEY_D)){ballx+=ballspeed;}

    //2. position update here
    if(ballx >= GetScreenWidth()){ballx=GetScreenWidth();}
    if(ballx <= 0){ballx=0;}
    if(bally >= GetScreenHeight()){bally=GetScreenHeight();}
    if(bally <= 0){bally=0;}
    


    //3. Drawing here
    BeginDrawing();
    ClearBackground(GREEN);
    DrawCircle(ballx,bally,30,WHITE);
    EndDrawing();
  }
  CloseWindow();
  return 0;
}