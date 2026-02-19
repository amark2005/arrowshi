#include <raylib.h>
#include <cmath>

void movetowards(Vector2 &position, Vector2 target, float speed);

int main(){
    InitWindow(800, 800, "Ball");
    SetTargetFPS(24);
    
    Vector2 ballpuci = {400, 400};
    int ballspeed = 10;
    Vector2 target = {700, 700};
    
    bool movingToTarget = false;

    while(WindowShouldClose() == false){
        Vector2 balldir = {0.0f, 0.0f};
        
        // Event handling
        if(IsKeyDown(KEY_W)) balldir.y = -1.0f;
        if(IsKeyDown(KEY_S)) balldir.y = 1.0f;
        if(IsKeyDown(KEY_A)) balldir.x = -1.0f;
        if(IsKeyDown(KEY_D)) balldir.x = 1.0f;
        
        if(IsKeyPressed(KEY_SPACE)){
            movingToTarget = true;
        }

        if (balldir.x != 0.0f || balldir.y != 0.0f) {
            movingToTarget = false;
        }

        // Auto Drive
        if (movingToTarget) {
            // Checks distance to avoid over shooting
            float dx = target.x - ballpuci.x;
            float dy = target.y - ballpuci.y;
            float distance = sqrt(dx*dx + dy*dy);

            if (distance <= ballspeed) {
                ballpuci = target; 
                movingToTarget = false; 
            } else {
                movetowards(ballpuci, target, ballspeed);
            }
        } else {
            // Standard manual movement
            ballpuci.x += balldir.x * ballspeed;
            ballpuci.y += balldir.y * ballspeed;
        }

        // Wall Coliision
        if(ballpuci.x >= GetScreenWidth() - 30) ballpuci.x = GetScreenWidth() - 30;
        if(ballpuci.x <= 30) ballpuci.x = 30;
        if(ballpuci.y >= GetScreenHeight() - 30) ballpuci.y = GetScreenHeight() - 30;
        if(ballpuci.y <= 30) ballpuci.y = 30;
        
        // Drawing Here
        BeginDrawing();
        ClearBackground(GREEN);
        DrawRectangle(700, 700, 10, 10, BLACK);
        DrawCircleV(ballpuci, 30, WHITE);
        EndDrawing();
    }
    
    CloseWindow();
    return 0;
}

void movetowards(Vector2 &position, Vector2 target, float speed){
    Vector2 direction;
    direction.x = target.x - position.x;
    direction.y = target.y - position.y;
    float length = sqrt(direction.x*direction.x + direction.y*direction.y);
    if(length != 0){
        direction.x /= length;
        direction.y /= length;
    }
    position.x += direction.x * speed;
    position.y += direction.y * speed;
}