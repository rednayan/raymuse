#include <raylib.h>
#include <stdio.h>

int main(void) {
  InitWindow(800, 400, "raymuse");
  Music music = LoadMusicStream("../test-music.mp3");

  while (!WindowShouldClose()) {
    BeginDrawing();
    ClearBackground(WHITE);
    PlayMusicStream(music);
    EndDrawing();
  }
}