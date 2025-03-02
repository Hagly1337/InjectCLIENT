void AddColorPicker(const char* name, ImVec4& color, bool prd = false, bool* rainbow = nullptr, bool* pulse = nullptr, bool* dark = nullptr) {
    ImGuiColorEditFlags misc_flags = ImGuiColorEditFlags_AlphaPreview;
    static ImVec4 backup_color;
    bool open_popup = ImGui::ColorButton((std::string(name) + std::string(("##3b"))).c_str(), color, misc_flags);
    if (open_popup) {
        ImGui::OpenPopup(name);
        backup_color = color;
    }
    if (ImGui::BeginPopup(name)) {
        ImGui::Spacing();
        ImGui::Text(("%s"), std::string(name).c_str());
        ImGui::Separator();
        ImGui::ColorPicker4(("##picker"), (float*)&color, misc_flags | ImGuiColorEditFlags_NoSidePreview | ImGuiColorEditFlags_NoSmallPreview | ImGuiColorEditFlags_AlphaBar);
        ImGui::SameLine();
        ImGui::BeginGroup();
        ImGui::Text(("%s"), std::string(("Current")).c_str());
        ImGui::ColorButton(("##current"), color, ImGuiColorEditFlags_NoPicker | ImGuiColorEditFlags_AlphaPreviewHalf, ImVec2(60, 40));
        ImGui::Text(("%s"), std::string(("Previous")).c_str());
        if (ImGui::ColorButton(("##previous"), backup_color, ImGuiColorEditFlags_NoPicker | ImGuiColorEditFlags_AlphaPreviewHalf, ImVec2(60, 40)))color = backup_color;
        ImGui::EndGroup();
        if (prd) {
            if (rainbow) ImGui::Checkbox(("rainbow"), rainbow);
            if (pulse) ImGui::Checkbox(("pulse"), pulse);
            if (dark) ImGui::Checkbox(("dark"), dark);
        }
        ImGui::Spacing();
        ImGui::EndPopup();
    }
}


//AIM
bool Aimbot_enable;
bool Drawfov;
int Aimbot_fov;

//ESP
namespace colors {
    namespace esp {
        namespace grenade {
            float circlecolor[] = {0,0,0,1};
            float linecolor[] = {1,1,1,1};
        }
        namespace player {
            float HpColor[] = {1,1,1};
            float fillColor[]={1,1,1};
            float fill_value = 150;
            float boxColor[] = {1,1,1};
            float armorColor[] = {1,1,1};
            float skeletonColor[] = {1,1,1};
        }
    }
}
float hpcolor1[] = { 1,0,0 };
float hpcolor2[] = { 1,0,0 };
float armorcolor1[] = { 1,0,0 };
float armorcolor2[] = { 1,0,0 };

namespace esp{
    namespace grenade{
        bool enable;
        bool circle;
        bool name;
        bool outoffov;
    }
    namespace player {
        bool enable;
        bool box;
		bool preview;
        bool fill;
        bool fooots;
        bool health;
        bool name;
        bool dist;
        bool armor;
        bool line;
        const char* hptype[] = {"Default","Gradient"};
        const char* armortypes[] = {"Default","Gradient"};
        int healthtype;
        int armortype;
        bool skeleton;
        bool money;
        float glow;
        bool weapon;
		
    }
    namespace weapon{
        bool enable;
    }
}


//FUNCTIONS
static bool infammo;
static bool wallshot;
static bool norecoil;
static bool firerate;


bool hopbool;
float hop_val = 0.0f;

//OTHER
bool crosshair;
