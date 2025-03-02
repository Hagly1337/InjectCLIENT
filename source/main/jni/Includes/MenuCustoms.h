namespace Alacrium {
    int N = 500;
    int lineMaxDist = 1000;
    ImColor lineCol = { 255, 255, 255, 255 };
    float lineThickness = 2.0f;
    void setupPoints(std::vector<std::pair<ImVec2, ImVec2>>& n) {
        ImVec2 screenSize(ImGui::GetIO().DisplaySize);
        for (auto& p : n)
            p.second = p.first = ImVec2(rand() % (int)screenSize.x, rand() % (int)screenSize.y);
    }
    float length(ImVec2 x) { return x.x * x.x + x.y * x.y; }
    void FX(ImDrawList* d, ImVec2 b)
    {
        static std::vector<std::pair<ImVec2, ImVec2>> points(N);
        static auto once = (setupPoints(points), true);
        float Dist;
        for (auto& p : points) {
         //   Dist = sqrt(length(p.first - p.second));
          //  if (Dist > 0) p.first += (p.second - p.first) / Dist;
            if (Dist < 4) p.second = ImVec2(rand() % (int)b.x, rand() % (int)b.y);
        }
        for (int i = 0; i < N; i++) {
            for (int j = i + 1; j < N; j++) {
            //    Dist = length(points[i].first - points[j].first);
                if (Dist < lineMaxDist) d->AddLine(points[i].first, points[j].first, lineCol, lineThickness);
            }
        }
    }

    void TextShadow(const char* v) {
        auto cur = ImGui::GetCursorPos();
     //   ImGui::SetCursorPos(cur - ImVec2(0,2));
        ImGui::PushStyleColor(ImGuiCol_Text, ImVec4(0,0,0,1));
        ImGui::Text(v);
        ImGui::PopStyleColor();
    //  ImGui::SetCursorPos(cur+ImVec2(2,0));
        ImGui::Text(v);
    }

    void DrawLineGlowW(ImVec2 start,ImVec2 end,ImColor col,float size, int gsize) {
        ImGui::GetBackgroundDrawList()->AddLine(start,end,col,size);
        for(int i = 0; i < gsize; i++) {
            ImGui::GetBackgroundDrawList()->AddLine(start,end,ImColor(col.Value.x,col.Value.y,col.Value.z,col.Value.w * (1.0f / (float)gsize) * (((float)(gsize - i))/(float)gsize)),size + i);
        }
    }

    void DrawLineGlow(ImVec2 start,ImVec2 end,ImVec4 col,float size, int gsize) {
        ImGui::GetBackgroundDrawList()->AddLine(start,end,ImGui::GetColorU32(col),size);
        for(int i = 0; i < gsize; i++) {
            ImGui::GetBackgroundDrawList()->AddLine(start,end,ImGui::GetColorU32(ImVec4(col.x,col.y,col.z,col.w * (1.0f / (float)gsize) * (((float)(gsize - i))/(float)gsize))),size + i);
        }
    }
/*
    void ColorPicker(const char *name, ImVec4 &color) {
        static ImVec4 backup_color;

        bool open_popup = ImGui::ColorButton((std::string(name) + std::string("##3b")).c_str(),
                                             color);
        //open_popup |= ImGui::Button("Palette");
        if (open_popup) {
            ImGui::OpenPopup(name);
            backup_color = color;
        }
        if (ImGui::BeginPopup(name)) {
            ImGui::Spacing();
            ImGui::Text("Select Color");
            ImGui::Separator();
            ImGui::ColorPicker4("##picker", (float *) &color, ImGuiColorEditFlags_NoSidePreview |
                                                              ImGuiColorEditFlags_NoSmallPreview);
            ImGui::SameLine();

            ImGui::BeginGroup(); // Lock X position
            ImGui::Text("Current");
            ImGui::ColorButton("##current", color,
                               ImGuiColorEditFlags_NoPicker | ImGuiColorEditFlags_AlphaPreviewHalf,
                               ImVec2(60, 40));
            ImGui::Text("Previous");
            if (ImGui::ColorButton("##previous", backup_color, ImGuiColorEditFlags_NoPicker |
                                                               ImGuiColorEditFlags_AlphaPreviewHalf,
                                   ImVec2(60, 40))) {
                color = backup_color;
            }
            ImGui::EndGroup();
            ImGui::EndPopup();
        }
    }

    void AddColorPicker(const char* name, ImVec4 &color, bool prd = false, bool* rainbow = nullptr, bool* pulse = nullptr, bool* dark = nullptr) {
        ImGuiColorEditFlags misc_flags = ImGuiColorEditFlags_AlphaPreview;
        static ImVec4 backup_color;
        bool open_popup = ImGui::ColorButton((std::string(name) + std::string(_("##3b"))).c_str(), color, misc_flags);
        if (open_popup) {
            ImGui::OpenPopup(name);
            backup_color = color;
        }
        if (ImGui::BeginPopup(name)) {
            ImGui::Text(_("%s"), std::string(name).c_str());
            ImGui::Separator();
            ImGui::ColorPicker4(_("##picker"), (float *) &color,misc_flags | ImGuiColorEditFlags_NoSidePreview | ImGuiColorEditFlags_NoSmallPreview | ImGuiColorEditFlags_AlphaBar);
            ImGui::SameLine();
            ImGui::BeginGroup();
            ImGui::Text(_("%s"),std::string(_("Current")).c_str());
            ImGui::ColorButton(_("##current"), color,ImGuiColorEditFlags_NoPicker | ImGuiColorEditFlags_AlphaPreviewHalf,ImVec2(60, 40));
            ImGui::Text(_("%s"),std::string(_("Previous")).c_str());
            if (ImGui::ColorButton(_("##previous"), backup_color,ImGuiColorEditFlags_NoPicker | ImGuiColorEditFlags_AlphaPreviewHalf,ImVec2(60, 40)))color = backup_color;
            ImGui::EndGroup();
            if (prd) {
                if (rainbow) ImGui::Checkbox(_("rainbow"), rainbow);
                if (pulse) ImGui::Checkbox(_("pulse"), pulse);
                if (dark) ImGui::Checkbox(_("dark"), dark);
            }
            ImGui::EndPopup();
        }
    }
*/
    const std::string currentDateTime() {
        time_t     now = time(0);
        struct tm  tstruct;
        char       buft[80];
        tstruct = *localtime(&now);
        strftime(buft, sizeof(buft), "%X", &tstruct);

        return buft;
    }

    static void HelpMarker(const char* desc)
    {
        ImGui::TextDisabled("(?)");
        if (ImGui::IsItemHovered())
        {
            ImGui::BeginTooltip();
            ImGui::PushTextWrapPos(ImGui::GetFontSize() * 35.0f);
            ImGui::TextUnformatted(desc);
            ImGui::PopTextWrapPos();
            ImGui::EndTooltip();
        }
    }

    float toasttimer = 0;
    float toastmaxtime = 0;
    const char* toasttext = 0;

    void Toast(const char *text, int length = 1) {
        Alacrium::toasttext = text;
        Alacrium::toasttimer = length;
        Alacrium::toastmaxtime = length;
    }

    void RenderToast() {
        ImGuiIO &io = ImGui::GetIO();
        if (toasttimer <= 0) return;
        toasttimer -= io.DeltaTime;
        float alpha;
        if (toasttimer >= 0.1f && toasttimer <= toastmaxtime - 0.1f) alpha = 1;
        if (toasttimer < 0.1f) alpha = toasttimer * 10;
        if (toasttimer > toastmaxtime - 0.1f) alpha = (toastmaxtime - toasttimer) * 10;

        ImGui::GetForegroundDrawList()->AddRectFilled(ImVec2(io.DisplaySize.x / 2 - ImGui::CalcTextSize(toasttext).x/2 - 20, io.DisplaySize.y * 0.8 - ImGui::CalcTextSize(toasttext).y/2 - 20 - alpha * 5),
                                                      ImVec2(io.DisplaySize.x / 2 + ImGui::CalcTextSize(toasttext).x/2 + 20, io.DisplaySize.y * 0.8 + ImGui::CalcTextSize(toasttext).y/2 + 20 - alpha * 5),
                                                      ImColor(0.1f,0.1f,0.1f,alpha), 5.0f);

        ImGui::GetForegroundDrawList()->AddText(ImVec2(io.DisplaySize.x / 2 - ImGui::CalcTextSize(toasttext).x/2, io.DisplaySize.y * 0.8 - ImGui::CalcTextSize(toasttext).y/2 - alpha * 5),
                                                ImColor(1.0f,1.0f,1.0f,alpha), toasttext);
    }

    void TextCentered(std::string text) {
        auto windowWidth = ImGui::GetWindowSize().x;
        auto textWidth = ImGui::CalcTextSize(text.c_str()).x;
        ImGui::SetCursorPosX((windowWidth - textWidth) * 0.5f);
        ImGui::Text(text.c_str());
    }



    void MultiCombo(const char* label, bool combos[], const char* items[], int items_count)
    {

        std::vector<std::string> vec;
        static std::string preview;
        for (int i = 0, j = 0; i < items_count; i++)
        {
            if (combos[i])
            {
                vec.push_back(items[i]);
                if (j > 2)
                    preview = vec.at(0) + ", " + vec.at(1) + ", " + vec.at(2) + ", ...";
                else if (j)
                    preview += ", " + (std::string)items[i];
                else
                    preview = items[i];

                j++;
            }
        }
        if (ImGui::BeginCombo(label, preview.c_str())) {
            for (int i = 0; i < items_count; i++) {
                ImGui::Selectable(items[i], &combos[i], ImGuiSelectableFlags_DontClosePopups);
            }
            ImGui::EndCombo();
        }
        preview = "None";
    }


} //namespace Alacrium (ex. MenuCustoms)

void DrawLineGlow(ImVec2 start, ImVec2 end, ImVec4 col, float size, int gsize) {    ImGui::GetForegroundDrawList()->AddLine(start, end, ImGui::GetColorU32(col), size);
    for (int i = 0; i < gsize; i++) {        ImGui::GetForegroundDrawList()->AddLine(start, end, ImGui::GetColorU32(ImVec4(col.x, col.y, col.z, col.w * (1.0f / (float)gsize) * (((float)(gsize - i)) / (float)gsize))), size + i);
    }
}     
