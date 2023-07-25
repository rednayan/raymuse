#include <raylib.h>
#include <stdio.h>

void callback(void *bufferData, unsigned int frames) {
  (void)bufferData;
  printf("callback(frames = %u)\n", frames);
}

int main(void) {
  InitWindow(800, 400, "raymuse");
  InitAudioDevice();
  SetTargetFPS(60);

  Music music = LoadMusicStream("../test-music.mp3");
  PlayMusicStream(music);

  while (!WindowShouldClose()) {
    UpdateMusicStream(music);
    AttachAudioStreamProcessor(music.stream, callback);

    if (IsKeyDown(KEY_SPACE)) {
      if (IsMusicStreamPlaying(music)) {
        PauseMusicStream(music);
      } else {
        ResumeMusicStream(music);
      }
    }

    BeginDrawing();
    ClearBackground(WHITE);
    EndDrawing();
  }
  return 0;
}