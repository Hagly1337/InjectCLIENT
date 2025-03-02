#include <vector>
#include <cstdlib>
#include <cmath>
struct Snowflake {
    ImVec2 pos;
    float speed;
    float size;
};
#include "imgui.h"
#include "imgui_internal.h"
#include <vector>

// Округление углов меню
void ApplyMenuStyles() {
    ImGui::PushStyleVar(ImGuiStyleVar_WindowRounding, 15.0f);
    ImGui::PushStyleVar(ImGuiStyleVar_Alpha, 0.9f);
}

// Анимация гирлянды
struct Light {
    ImVec2 pos;
    ImVec4 color;
};

std::vector<Light> garlandLights;

void InitGarland() {
    garlandLights.clear();
    float startX = 50.0f;
    float startY = 20.0f;
    for (int i = 0; i < 10; i++) {
        ImVec4 color = (i % 2 == 0) ? ImVec4(1, 0, 0, 1) : ImVec4(0, 1, 0, 1); // Красный и зелёный
        garlandLights.push_back({ ImVec2(startX + i * 30, startY), color });
    }
}

void DrawGarland() {
    for (size_t i = 0; i < garlandLights.size(); i++) {
        ImGui::GetForegroundDrawList()->AddCircleFilled(garlandLights[i].pos, 5.0f, ImColor(garlandLights[i].color));
    }
}

// Плавное движение меню (интерполяция)
static ImVec2 menuPos = ImVec2(300, 200);
static ImVec2 targetPos = menuPos;

void UpdateMenuPosition() {
    if (ImGui::IsMouseDragging(ImGuiMouseButton_Left)) {
        targetPos = ImGui::GetMousePos();
    }
    menuPos.x += (targetPos.x - menuPos.x) * 0.1f;
    menuPos.y += (targetPos.y - menuPos.y) * 0.1f;
}

// Основная функция меню
void ShowCustomMenu() {
    ApplyMenuStyles();
    UpdateMenuPosition();
    
    ImGui::SetNextWindowPos(menuPos, ImGuiCond_Always);
    ImGui::Begin("Новогоднее меню", nullptr, ImGuiWindowFlags_NoTitleBar | ImGuiWindowFlags_NoResize);
    
    ImGui::Text("С Новым Годом!");
    ImGui::Separator();
    ImGui::Text("Ваш текст по центру");

    DrawGarland(); // Рисуем гирлянду

    ImGui::End();
    ImGui::PopStyleVar(2);
}
static std::vector<Snowflake> snowflakes;

// Генерация снежинок
void GenerateSnow(int count, ImVec2 screenSize) {
    for (int i = 0; i < count; i++) {
        snowflakes.push_back({
            ImVec2(rand() % (int)screenSize.x, rand() % (int)screenSize.y),
            1.0f + (rand() % 100) / 50.0f,
            2.0f + (rand() % 10) / 5.0f
        });
    }
}

// Отрисовка снега
void RenderSnow(ImDrawList* drawList, ImVec2 screenSize) {
    for (auto& flake : snowflakes) {
        flake.pos.y += flake.speed;
        flake.pos.x += sin(ImGui::GetTime() + flake.pos.y * 0.01f) * 0.5f;

        if (flake.pos.y > screenSize.y) {
            flake.pos.y = 0;
            flake.pos.x = rand() % (int)screenSize.x;
        }

        drawList->AddCircleFilled(flake.pos, flake.size, IM_COL32(255, 255, 255, 200));
    }
}

namespace Alacrium {
    constexpr int N = 100;  // Количество точек
    constexpr float lineMaxDist = 100.0f;
    const ImColor lineCol = ImColor(255, 255, 255, 100);
    constexpr float lineThickness = 1.5f;

    void setupPoints(std::vector<std::pair<ImVec2, ImVec2>>& points) {
        for (auto& p : points) {
            p.first = ImVec2(rand() % 500, rand() % 500);
            p.second = ImVec2(rand() % 500, rand() % 500);
        }
    }

    void FX(ImDrawList* d, ImVec2 b) {
        static std::vector<std::pair<ImVec2, ImVec2>> points(N);
        static bool initialized = false;
        if (!initialized) {
            setupPoints(points);
            initialized = true;
        }

        for (auto& p : points) {
            float distSqr = (p.first.x - p.second.x) * (p.first.x - p.second.x) +
                            (p.first.y - p.second.y) * (p.first.y - p.second.y);
            if (distSqr < 16.0f) 
                p.second = ImVec2(rand() % (int)b.x, rand() % (int)b.y);
        }

        for (int i = 0; i < N; i++) {
            for (int j = i + 1; j < N; j++) {
                float distSqr = (points[i].first.x - points[j].first.x) * (points[i].first.x - points[j].first.x) +
                                (points[i].first.y - points[j].first.y) * (points[i].first.y - points[j].first.y);
                if (distSqr < lineMaxDist * lineMaxDist) 
                    d->AddLine(points[i].first, points[j].first, lineCol, lineThickness);
            }
        }
    }

    void TextShadow(const char* text) {
        auto cur = ImGui::GetCursorPos();
		ImVec2 flake_pos; // Добавь перед использованием
flake_pos.x += sin(ImGui::GetTime() + flake_pos.y * 0.01f);
        ImGui::PushStyleColor(ImGuiCol_Text, ImVec4(0, 0, 0, 0.5f));
        ImGui::Text(text);
        ImGui::PopStyleColor();

        ImGui::SetCursorPos(cur);
        ImGui::Text(text);
    }

    void DrawLineGlow(ImVec2 start, ImVec2 end, ImVec4 col, float size, int gsize) {
        auto* drawList = ImGui::GetBackgroundDrawList();
        drawList->AddLine(start, end, ImColor(col.x, col.y, col.z, col.w), size);
        for (int i = 1; i <= gsize; i++) {
            float alpha = col.w * (1.0f - (float)i / (float)gsize);
            drawList->AddLine(start, end, ImColor(col.x, col.y, col.z, alpha), size + i);
        }
    }
}
