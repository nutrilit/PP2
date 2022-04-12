#include "raylib.h"
// Some Defines
#define WindowSize 800
// Types and Structures Definition
typedef struct Player{
    Rectangle model;
    Vector2 speed;
    Color color;
} Player;
// Global Variables Declaration
static const int screenWidth = WindowSize;
static const int screenHeight = WindowSize;
static bool gameOver = false;
static bool pause =  false;
static Player player1 = { 0 };
// Module Functions Declaration (local)
static void InitGame(void);         // Initialize game
static void UpdateGame(void);       // Update game (one frame)
static void DrawGame(void);         // Draw game (one frame)
static void UnloadGame(void);       // Unload game
static void UpdateDrawFrame(void);  // Update and Draw (one frame)
// Main game loop
int main(void)
{
   // Initialization
   
    InitWindow(screenWidth, screenHeight, "Tanks");

    InitGame();

    SetTargetFPS(60); // Ustawienie fps na 60
    // Main game loop
    while (!WindowShouldClose())    //  Wykryj przycisk zamykania okna lub ESC
    {
               // Update and Draw
        
        UpdateDrawFrame();
        
        }
    
    // De-Initialization
    UnloadGame();         // Unload loaded data (textures, sounds, models...)

    CloseWindow();        // Close window and OpenGL context
    
   
    return 0;
}
// Module Functions Definitions (local)
// Initialize game variables
void InitGame(void)
{
    // Initialize game variables
    pause = false;
    gameOver = false;
    // Initialize player
    player1.model.x =  200; // resp modelu(czolgu) po osi x
    player1.model.y = 50;   // resp modelu(czołgu) po osi y
    player1.model.width = 20;  // rozmiar modelu(czołgu) po osi x
    player1.model.height = 20; // rozmiar modelu(czolgu) po osi y
    player1.speed.x = 10; // predkosc moedelu(czołgu) po osi x
    player1.speed.y = 10; //predkosc moedelu(czołgu) po osi y
    player1.color = LIME; // kolor modelu(czolgu)

}
// Update game (one frame)
void UpdateGame(void)
{
    if (!gameOver)
    {
        if (IsKeyPressed('P')) pause = !pause;

        if (!pause)
        {
            // Player movement
            if (IsKeyDown(KEY_D))player1.model.x += player1.speed.x;  // poruszanie sie w prawo pod przyciskiem          
            if (IsKeyDown(KEY_A)) player1.model.x -= player1.speed.x; //poruszanie sie w lewo pod przyciskiem
            if (IsKeyDown(KEY_W)) player1.model.y -= player1.speed.y; // poruszanie sie w gore pod przyciskiem
            if (IsKeyDown(KEY_S)) player1.model.y += player1.speed.y; // poruszanie sie w dol pod przyciskiem
        
        }
    }
}
// Draw game (one frame)
void DrawGame(void)
{
    BeginDrawing(); // rysowanie rozpoczecie
 DrawFPS(WindowSize-100,WindowSize-790); // Rozmieszczenie napisu FPSów
        ClearBackground(BLACK); // KOLOR TŁA 

        if (!gameOver)
        {
            DrawRectangleRec(player1.model, player1.color);

        if (pause) DrawText("GRA ZATRZYMANA", screenWidth/2 - MeasureText("GRA ZATRZYMANA", 52)/2, screenHeight/2 - 40, 40, SKYBLUE); // zatrzymanie gry pod przyciskie "p" oraz wyswietlenie napis GAME PAUSED
        }
         
 // OGRANICZENIE graniczne
            if (player1.model.x <= 0) player1.model.x = 0; // ograniczenie w lewo 
            if (player1.model.x + player1.model.width >= screenWidth) player1.model.x = screenWidth - player1.model.width;  //ograniczenie w prawo
            if (player1.model.y <= 0) player1.model.y = 0; // ograniczenie w gore
            if (player1.model.y + player1.model.height >= screenHeight) player1.model.y = screenHeight - player1.model.height; // ograniczenie w dol
    EndDrawing(); // ZAKONCZENIE RYSOWANIA
}
// Unload game variables
void UnloadGame(void)
{
    // TODO: Unload all dynamic loaded data (textures, sounds, models...)
}
// Update and Draw (one frame)
void UpdateDrawFrame(void)
{
    UpdateGame();
    DrawGame();
}
