void GenerateSnow(int count, ImVec2 screenSize);
void RenderSnow(ImDrawList* drawList, ImVec2 screenSize);
#include "MenuCustoms.h"

std::vector<Snowflake> snowflakes;

void GenerateSnow(int count, ImVec2 screenSize) {
    for (int i = 0; i < count; i++) {
        snowflakes.push_back({
            ImVec2(rand() % (int)screenSize.x, rand() % (int)screenSize.y),
            1.0f + (rand() % 100) / 50.0f,
            2.0f + (rand() % 10) / 5.0f
        });
    }
}

void RenderSnow(ImDrawList* drawList, ImVec2 screenSize) {
    for (auto& flake : snowflakes) {
        flake.pos.y += flake.speed;
        flake.pos.x += sin(ImGui::GetTime() + flake.pos.y * 0.01f);

        if (flake.pos.y > screenSize.y) {
            flake.pos.y = 0;
            flake.pos.x = rand() % (int)screenSize.x;
        }

        drawList->AddCircleFilled(flake.pos, flake.size, IM_COL32(255, 255, 255, 200));
    }
}
