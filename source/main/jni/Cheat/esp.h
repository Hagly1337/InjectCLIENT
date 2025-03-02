

void DrawRectGlow(ImVec2 start, ImVec2 end, ImVec4 col,int gsize) {
    for (int i = 0; i < gsize; i++) {
        ImGui::GetBackgroundDrawList()->AddRectFilled(ImVec2(start.x - i, start.y - i), ImVec2(end.x + i, end.y + i), ImGui::GetColorU32(ImVec4(col.x, col.y, col.z, col.w * (1.0f / (float)gsize) * (((float)(gsize - i)) / (float)gsize))));
    }
    ImGui::GetBackgroundDrawList()->AddRectFilled(start, end, ImGui::GetColorU32(col));
}

void DrawRectGlow1(ImVec2 start, ImVec2 end, ImVec4 col, ImVec4 col1, int gsize) {
    for (int i = 0; i < gsize; i++) {
        ImGui::GetBackgroundDrawList()->AddRectFilledMultiColor(ImVec2(start.x - i, start.y - i), ImVec2(end.x + i, end.y + i), ImGui::GetColorU32(ImVec4(col.x, col.y, col.z, col.w * (1.0f / (float)gsize) * (((float)(gsize - i)) / (float)gsize))), ImGui::GetColorU32(ImVec4(col.x, col.y, col.z, col.w * (1.0f / (float)gsize) * (((float)(gsize - i)) / (float)gsize))), ImGui::GetColorU32(ImVec4(col1.x, col1.y, col1.z, col1.w * (1.0f / (float)gsize) * (((float)(gsize - i)) / (float)gsize))), ImGui::GetColorU32(ImVec4(col1.x, col1.y, col1.z, col1.w * (1.0f / (float)gsize) * (((float)(gsize - i)) / (float)gsize))));
    }
    ImGui::GetBackgroundDrawList()->AddRectFilledMultiColor(start, end, ImGui::GetColorU32(col), ImGui::GetColorU32(col), ImGui::GetColorU32(col1), ImGui::GetColorU32(col1));
}
void DrawRectGlow2(ImVec2 start, ImVec2 end, ImVec4 col, ImVec4 col1, int gsize) {
    for (int i = 0; i < gsize; i++) {
        ImGui::GetBackgroundDrawList()->AddRectFilledMultiColor(ImVec2(start.x - i, start.y - i), ImVec2(end.x + i, end.y + i), ImGui::GetColorU32(ImVec4(col1.x, col1.y, col1.z, col1.w * (1.0f / (float)gsize) * (((float)(gsize - i)) / (float)gsize))), ImGui::GetColorU32(ImVec4(col.x, col.y, col.z, col.w * (1.0f / (float)gsize) * (((float)(gsize - i)) / (float)gsize))), ImGui::GetColorU32(ImVec4(col.x, col.y, col.z, col.w * (1.0f / (float)gsize) * (((float)(gsize - i)) / (float)gsize))), ImGui::GetColorU32(ImVec4(col1.x, col1.y, col1.z, col1.w * (1.0f / (float)gsize) * (((float)(gsize - i)) / (float)gsize))));
    }
    ImGui::GetBackgroundDrawList()->AddRectFilledMultiColor(start, end, ImGui::GetColorU32(col1), ImGui::GetColorU32(col), ImGui::GetColorU32(col), ImGui::GetColorU32(col1));
}

std::map<int, std::string> weaptofont = {
        {1, OBFUSCATE("b")},
        {2, OBFUSCATE("b")},
        {11, OBFUSCATE("A")},
        {12, OBFUSCATE("B")},
        {13, OBFUSCATE("C")},
        {16, OBFUSCATE("E")},
        {17, OBFUSCATE("F")},
        {49, OBFUSCATE("Q")},
        {15, OBFUSCATE("G")},
        {32, OBFUSCATE("M")},
        {34, OBFUSCATE("O")},
        {35, OBFUSCATE("P")},
        {36, OBFUSCATE("N")},
        {37, OBFUSCATE("L")},
        {43, OBFUSCATE("U")},
        {44, OBFUSCATE("S")},
        {45, OBFUSCATE("V")},
        {46, OBFUSCATE("T")},
        {47, OBFUSCATE("W")},
        {48, OBFUSCATE("R")},
        {51, OBFUSCATE("Y")},
        {52, OBFUSCATE("X")},
        {62, OBFUSCATE("I")},
        {70, OBFUSCATE("b")},
        {71, OBFUSCATE("c")},
        {72, OBFUSCATE("d")},
        {73, OBFUSCATE("e")},
        {75, OBFUSCATE("f")},
        {77, OBFUSCATE("g")},
        {78, OBFUSCATE("i")},
        {91, OBFUSCATE("p")},
        {92, OBFUSCATE("n")},
        {93, OBFUSCATE("o")},
        {100, OBFUSCATE("a")},
        {69, OBFUSCATE("I")},
        {74, OBFUSCATE("b")},
        {99, OBFUSCATE("p")},
        {79, OBFUSCATE("h")},
        {42, OBFUSCATE("b")},
        {81, OBFUSCATE("l")},
        {82, OBFUSCATE("k")},
        {53, OBFUSCATE("Z")},
        {63, OBFUSCATE("H")}
};

monoString*GetPlayerWeapon(uintptr_t a) {
    auto w1 = *(void **) ((uint64_t) a + 0x68);
    if (w1) {
        auto w2 = *(void **) ((uint64_t) w1 + 0x98);
        if (w2) {
            auto w3 = *(void **) ((uint64_t) w2 + 0xA0);
            if (w3) {
                auto w4 = *(monoString**) ((uint64_t) w3 + 0x20);
                if (w4) return w4;
            }
        }
    }
}
int get_weaponid(uintptr_t a) {
        auto w1 = *(void **) ((uint64_t) a + 0x68);
        if (w1) {
            auto w2 = *(void **) ((uint64_t) w1 + 0x98);
            if (w2) {
                auto w3 = *(void **) ((uint64_t) w2 + 0xA0);
                if (w3) {
                    auto w4 = *(int *) ((uint64_t) w3 + 0x18);
                    if (w4) return w4;
                }
            }
        }
    }

void render_esp() {
		if (esp::player::enable)
	{
	auto localPlayer = get_local_player();
    if (localPlayer == NULL) return;

    int localTeam = get_team(localPlayer);

    for (const auto & player : get_player_list())
    {
        if (player == NULL) continue;

        auto pl = player;

        int playerTeam = get_team(pl);

        if (playerTeam != localTeam) {
		
		Vector3 posup = get_position(get_transform(pl)) + Vector3(0, 1.9f, 0);
		
		Vector3 posdown = get_position(get_transform(pl));
										Vector3 posuponscr = Wts(get_camera(),posup);
										Vector3 posdownonscr = Wts(get_camera(),posdown);
										float height = posuponscr.y-posdownonscr.y;
										float width = height / 2;
										auto render = ImGui::GetBackgroundDrawList();
										ImVec2 DrawTo = ImVec2(posuponscr.x, (glHeight - posuponscr.y));
				
										auto weap = GetPlayerWeapon(pl);
                						std::string weaps = "null";
                						if (weap) weaps = weap->get_string();
                						std::transform(weaps.begin(), weaps.end(), weaps.begin(), ::tolower);
										std::string wpn = weaps;
				
				
										if(posuponscr.z > 1.0f){
											
										if(esp::player::weapon){
												int wid = get_weaponid(pl);
												std::string weapng = weaptofont[wid];	
												int h = GetArmor(get_photon(pl));
												if(!esp::player::armor||h==0){
													ImGui::PushFont(pixel);
													render->AddText(ImVec2((posuponscr.x-ImGui::CalcTextSize(wpn.c_str()).x/2)-1,(glHeight-posdownonscr.y)+1), ImGui::ColorConvertFloat4ToU32(ImVec4(0, 0, 0, 1)), wpn.c_str());
													render->AddText(ImVec2((posuponscr.x-ImGui::CalcTextSize(wpn.c_str()).x/2)-1,(glHeight-posdownonscr.y)-1), ImGui::ColorConvertFloat4ToU32(ImVec4(0, 0, 0, 1)), wpn.c_str());
		   											render->AddText(ImVec2((posuponscr.x-ImGui::CalcTextSize(wpn.c_str()).x/2)+1,(glHeight-posdownonscr.y)+1), ImGui::ColorConvertFloat4ToU32(ImVec4(0, 0, 0, 1)), wpn.c_str());
		   											render->AddText(ImVec2((posuponscr.x-ImGui::CalcTextSize(wpn.c_str()).x/2)+1,(glHeight-posdownonscr.y)-1), ImGui::ColorConvertFloat4ToU32(ImVec4(0, 0, 0, 1)), wpn.c_str());
					    							render->AddText(ImVec2(posuponscr.x-ImGui::CalcTextSize(wpn.c_str()).x/2,glHeight-posdownonscr.y), ImGui::ColorConvertFloat4ToU32(ImVec4(1, 1, 1, 1)), wpn.c_str());
													ImGui::PopFont();
							
													ImGui::PushFont(weapon);
													render->AddText(ImVec2((posuponscr.x-ImGui::CalcTextSize(weapng.c_str()).x/2),(glHeight-posdownonscr.y+ImGui::CalcTextSize(weapng.c_str()).y/2)+1), ImGui::ColorConvertFloat4ToU32(ImVec4(0, 0, 0, 1)), weapng.c_str());
													render->AddText(ImVec2((posuponscr.x-ImGui::CalcTextSize(weapng.c_str()).x/2)-1,(glHeight-posdownonscr.y+ImGui::CalcTextSize(weapng.c_str()).y/2)-1), ImGui::ColorConvertFloat4ToU32(ImVec4(0, 0, 0, 1)), weapng.c_str());
		   											render->AddText(ImVec2((posuponscr.x-ImGui::CalcTextSize(weapng.c_str()).x/2)+1,(glHeight-posdownonscr.y+ImGui::CalcTextSize(weapng.c_str()).y/2)+1), ImGui::ColorConvertFloat4ToU32(ImVec4(0, 0, 0, 1)), weapng.c_str());
		   											render->AddText(ImVec2((posuponscr.x-ImGui::CalcTextSize(weapng.c_str()).x/2)+1,(glHeight-posdownonscr.y+ImGui::CalcTextSize(weapng.c_str()).y/2)-1), ImGui::ColorConvertFloat4ToU32(ImVec4(0, 0, 0, 1)), weapng.c_str());
					    							render->AddText(ImVec2(posuponscr.x-ImGui::CalcTextSize(weapng.c_str()).x/2,glHeight-posdownonscr.y+ImGui::CalcTextSize(weapng.c_str()).y/2), ImGui::ColorConvertFloat4ToU32(ImVec4(1, 1, 1, 1)), weapng.c_str());
													ImGui::PopFont();
							
												} else {
													ImGui::PushFont(pixel);
													render->AddText(ImVec2((posuponscr.x-ImGui::CalcTextSize(wpn.c_str()).x/2)-1,(glHeight-posdownonscr.y)+8), ImGui::ColorConvertFloat4ToU32(ImVec4(0, 0, 0, 1)), wpn.c_str());
													render->AddText(ImVec2((posuponscr.x-ImGui::CalcTextSize(wpn.c_str()).x/2)-1,(glHeight-posdownonscr.y)+10), ImGui::ColorConvertFloat4ToU32(ImVec4(0, 0, 0, 1)), wpn.c_str());
		   											render->AddText(ImVec2((posuponscr.x-ImGui::CalcTextSize(wpn.c_str()).x/2)+1,(glHeight-posdownonscr.y)+8), ImGui::ColorConvertFloat4ToU32(ImVec4(0, 0, 0, 1)), wpn.c_str());
		   											render->AddText(ImVec2((posuponscr.x-ImGui::CalcTextSize(wpn.c_str()).x/2)+1,(glHeight-posdownonscr.y)+10), ImGui::ColorConvertFloat4ToU32(ImVec4(0, 0, 0, 1)), wpn.c_str());
					    							render->AddText(ImVec2(posuponscr.x-ImGui::CalcTextSize(wpn.c_str()).x/2,glHeight-posdownonscr.y+9), ImGui::ColorConvertFloat4ToU32(ImVec4(1, 1, 1, 1)), wpn.c_str());
													ImGui::PopFont();
							
													ImGui::PushFont(weapon);
													render->AddText(ImVec2((posuponscr.x-ImGui::CalcTextSize(weapng.c_str()).x/2)-1,(glHeight-posdownonscr.y+9+ImGui::CalcTextSize(weapng.c_str()).y/2)+1), ImGui::ColorConvertFloat4ToU32(ImVec4(0, 0, 0, 1)), weapng.c_str());
													render->AddText(ImVec2((posuponscr.x-ImGui::CalcTextSize(weapng.c_str()).x/2)-1,(glHeight-posdownonscr.y+9+ImGui::CalcTextSize(weapng.c_str()).y/2)-1), ImGui::ColorConvertFloat4ToU32(ImVec4(0, 0, 0, 1)), weapng.c_str());
		   											render->AddText(ImVec2((posuponscr.x-ImGui::CalcTextSize(weapng.c_str()).x/2)+1,(glHeight-posdownonscr.y+9+ImGui::CalcTextSize(weapng.c_str()).y/2)+1), ImGui::ColorConvertFloat4ToU32(ImVec4(0, 0, 0, 1)), weapng.c_str());
		   											render->AddText(ImVec2((posuponscr.x-ImGui::CalcTextSize(weapng.c_str()).x/2)+1,(glHeight-posdownonscr.y+9+ImGui::CalcTextSize(weapng.c_str()).y/2)-1), ImGui::ColorConvertFloat4ToU32(ImVec4(0, 0, 0, 1)), weapng.c_str());
					    							render->AddText(ImVec2(posuponscr.x-ImGui::CalcTextSize(weapng.c_str()).x/2,glHeight-posdownonscr.y+9+ImGui::CalcTextSize(weapng.c_str()).y/2), ImGui::ColorConvertFloat4ToU32(ImVec4(1, 1, 1, 1)), weapng.c_str());
													ImGui::PopFont();
							
												}
											}
											if(esp::player::fill)
												render->AddRectFilled(ImVec2(posuponscr.x - (width/2),glHeight-posuponscr.y),ImVec2(posuponscr.x+(width/2),glHeight-posuponscr.y+height),ImColor(colors::esp::player::boxColor[0],colors::esp::player::boxColor[1],colors::esp::player::boxColor[2],colors::esp::player::fill_value/255));
											if(esp::player::box){
												render->AddRect(ImVec2(posuponscr.x - (width/2),glHeight-posuponscr.y),ImVec2(posuponscr.x+(width/2),glHeight-posuponscr.y+height),ImColor(0,0,0),0,0,3.5f);
												render->AddRect(ImVec2(posuponscr.x - (width/2),glHeight-posuponscr.y),ImVec2(posuponscr.x+(width/2),glHeight-posuponscr.y+height),ImColor(colors::esp::player::boxColor[0],colors::esp::player::boxColor[1],colors::esp::player::boxColor[2]),0,0,1.5f);
											}
											if(esp::player::health){
						
												float health = GetHealth(get_photon(pl));
                    							int h = ((int) health);
                    							int x = DrawTo.x - width/2 - 10;
                   								int y = DrawTo.y;
                    							auto Render = render;
												if(esp::player::healthtype==0) {
													Render->AddRectFilled(ImVec2(x, y - 1),ImVec2(x + 6, y + 1 + height),ImColor(0, 0, 0, 200));
													DrawRectGlow(ImVec2(x + 1,y +height -(height *(health /100))),ImVec2(x + 5,y +height),ImVec4(colors::esp::player::HpColor[0],colors::esp::player::HpColor[1],colors::esp::player::HpColor[2],1),(int)esp::player::glow);
												}
												if(esp::player::healthtype==1) {
													Render->AddRectFilled(ImVec2(x, y - 1),ImVec2(x + 6, y + 1 + height),ImColor(0, 0, 0, 200));
													DrawRectGlow1(ImVec2(x + 1,y +height -(height *(health/100))),ImVec2(x + 5,y +height), ImVec4(hpcolor1[0], hpcolor1[1], hpcolor1[2], 1.0f), ImVec4(hpcolor2[0], hpcolor2[1], hpcolor2[2], 1.0f),(int)esp::player::glow);
												}
												if(h <100){
													ImGui::PushFont(pixel);
				   									render->AddText(ImVec2((x+3)-ImGui::CalcTextSize(std::to_string(h).c_str()).x/2,y-9 +height -(height *(health /100))), ImGui::ColorConvertFloat4ToU32(ImVec4(0,0,0, 1)), std::to_string(h).c_str());		  
													render->AddText(ImVec2((x+3)-ImGui::CalcTextSize(std::to_string(h).c_str()).x/2,y -7+height -(height *(health /100))), ImGui::ColorConvertFloat4ToU32(ImVec4(0,0,0, 1)), std::to_string(h).c_str());		  
													render->AddText(ImVec2((x+5)-ImGui::CalcTextSize(std::to_string(h).c_str()).x/2,y-9 +height -(height *(health /100))), ImGui::ColorConvertFloat4ToU32(ImVec4(0,0,0, 1)), std::to_string(h).c_str());		  
													render->AddText(ImVec2((x+5)-ImGui::CalcTextSize(std::to_string(h).c_str()).x/2,y -7+height -(height *(health /100))), ImGui::ColorConvertFloat4ToU32(ImVec4(0,0,0, 1)), std::to_string(h).c_str());		
													render->AddText(ImVec2((x+4)-ImGui::CalcTextSize(std::to_string(h).c_str()).x/2,y-8+height -(height *(health /100))), ImGui::ColorConvertFloat4ToU32(ImVec4(1,1,1, 1)), std::to_string(h).c_str());
													ImGui::PopFont();
												}
											}
											if(esp::player::name){
												monoString *isPlayerName = Getname(get_photon(pl));
												ImGui::PushFont(pixel);					
												render->AddText(ImVec2((posuponscr.x-ImGui::CalcTextSize(isPlayerName->get_string().c_str()).x/2)+1.8f,(glHeight-posuponscr.y- 20)+1.8f), ImGui::ColorConvertFloat4ToU32(ImVec4(0,0,0, 1)), isPlayerName->get_string().c_str());
												render->AddText(ImVec2((posuponscr.x-ImGui::CalcTextSize(isPlayerName->get_string().c_str()).x/2),glHeight-posuponscr.y- 20), ImGui::ColorConvertFloat4ToU32(ImVec4(1,1,1, 1)), isPlayerName->get_string().c_str());
												ImGui::PopFont();
											}
											if(esp::player::money){
												int mon = GetMoney(get_photon(pl));
												ImGui::PushFont(pixel);
				   								render->AddText(ImVec2((posuponscr.x+5+width/2)-1,(glHeight-posuponscr.y+12)+1), ImGui::ColorConvertFloat4ToU32(ImVec4(0,0,0, 1)), (std::to_string(mon)+"$").c_str());
												render->AddText(ImVec2((posuponscr.x+5+width/2)-1,(glHeight-posuponscr.y+12)-1), ImGui::ColorConvertFloat4ToU32(ImVec4(0,0,0, 1)), (std::to_string(mon)+"$").c_str());
												render->AddText(ImVec2((posuponscr.x+5+width/2)+1,(glHeight-posuponscr.y+12)+1), ImGui::ColorConvertFloat4ToU32(ImVec4(0,0,0, 1)), (std::to_string(mon)+"$").c_str());
												render->AddText(ImVec2((posuponscr.x+5+width/2)+1,(glHeight-posuponscr.y+12)-1), ImGui::ColorConvertFloat4ToU32(ImVec4(0,0,0, 1)), (std::to_string(mon)+"$").c_str());
												render->AddText(ImVec2(posuponscr.x+5+width/2,glHeight-posuponscr.y+12), ImGui::ColorConvertFloat4ToU32(ImVec4(1,1,1, 1)), (std::to_string(mon)+"$").c_str());
												ImGui::PopFont();
											}
											if(esp::player::dist){
												Vector3 mypos = get_position(get_transform(get_camera()));
				   								int DistanceTo=get_3D_Distance(mypos.x, mypos.y, mypos.z, posup.x, posup.y, posup.z);
												ImGui::PushFont(pixel);
				   								render->AddText(ImVec2((posuponscr.x+5+width/2)-1,(glHeight-posuponscr.y-2)+1), ImGui::ColorConvertFloat4ToU32(ImVec4(0,0,0, 1)), (std::to_string(DistanceTo)+"M").c_str());
												render->AddText(ImVec2((posuponscr.x+5+width/2)-1,(glHeight-posuponscr.y-2)-1), ImGui::ColorConvertFloat4ToU32(ImVec4(0,0,0, 1)), (std::to_string(DistanceTo)+"M").c_str());
												render->AddText(ImVec2((posuponscr.x+5+width/2)+1,(glHeight-posuponscr.y-2)+1), ImGui::ColorConvertFloat4ToU32(ImVec4(0,0,0, 1)), (std::to_string(DistanceTo)+"M").c_str());
												render->AddText(ImVec2((posuponscr.x+5+width/2)+1,(glHeight-posuponscr.y-2)-1), ImGui::ColorConvertFloat4ToU32(ImVec4(0,0,0, 1)), (std::to_string(DistanceTo)+"M").c_str());
												render->AddText(ImVec2(posuponscr.x+5+width/2,glHeight-posuponscr.y-2), ImGui::ColorConvertFloat4ToU32(ImVec4(1,1,1, 1)), (std::to_string(DistanceTo)+"M").c_str());
												ImGui::PopFont();
											}
											if(esp::player::armor){
												int h = GetArmor(get_photon(pl));
												if(h>0){
													if(esp::player::armortype==0){
														render->AddRectFilled(ImVec2(posuponscr.x-1 - width / 2, glHeight - posdownonscr.y+3), ImVec2(posuponscr.x+1 + width / 2, glHeight - posdownonscr.y+9), ImGui::ColorConvertFloat4ToU32(ImVec4(0,0,0, 1.0f)));
														DrawRectGlow(ImVec2(posuponscr.x - width / 2, glHeight - posdownonscr.y + 4), ImVec2((posuponscr.x - float(width / 2) + float(width * (h / 100.f))), glHeight - posdownonscr.y + 8), ImVec4(colors::esp::player::armorColor[0],colors::esp::player::armorColor[1],colors::esp::player::armorColor[2],1), (int)esp::player::glow);
														if(h<100){
															ImGui::PushFont(pixel);
				   											render->AddText(ImVec2((posuponscr.x -11- float(width / 2) + float(width * (h / 100.f)))-1,(glHeight - posdownonscr.y + 7-ImGui::CalcTextSize(std::to_string(h).c_str()).y/2)+1), ImGui::ColorConvertFloat4ToU32(ImVec4(0,0,0, 1)), std::to_string(h).c_str());
															render->AddText(ImVec2((posuponscr.x-11 - float(width / 2) + float(width * (h / 100.f)))-1,(glHeight - posdownonscr.y + 7-ImGui::CalcTextSize(std::to_string(h).c_str()).y/2)-1), ImGui::ColorConvertFloat4ToU32(ImVec4(0,0,0, 1)), std::to_string(h).c_str());
															render->AddText(ImVec2((posuponscr.x-11 - float(width / 2) + float(width * (h / 100.f)))+1,(glHeight - posdownonscr.y + 7-ImGui::CalcTextSize(std::to_string(h).c_str()).y/2)+1), ImGui::ColorConvertFloat4ToU32(ImVec4(0,0,0, 1)), std::to_string(h).c_str());
															render->AddText(ImVec2((posuponscr.x-11 - float(width / 2) + float(width * (h / 100.f)))+1,(glHeight - posdownonscr.y + 7-ImGui::CalcTextSize(std::to_string(h).c_str()).y/2)-1), ImGui::ColorConvertFloat4ToU32(ImVec4(0,0,0, 1)),std::to_string(h).c_str());
															render->AddText(ImVec2((posuponscr.x -11- float(width / 2) + float(width * (h / 100.f))),glHeight - posdownonscr.y + 7-ImGui::CalcTextSize(std::to_string(h).c_str()).y/2), ImGui::ColorConvertFloat4ToU32(ImVec4(1,1,1, 1)), std::to_string(h).c_str());
															ImGui::PopFont();
														}
													}
													if(esp::player::armortype == 1){
														render->AddRectFilled(ImVec2(posuponscr.x-1 - width / 2, glHeight - posdownonscr.y+3), ImVec2(posuponscr.x+1 + width / 2, glHeight - posdownonscr.y+9), ImGui::ColorConvertFloat4ToU32(ImVec4(0,0,0, 1.0f)));
        												DrawRectGlow2(ImVec2(posuponscr.x - width / 2, glHeight - posdownonscr.y + 4), ImVec2((posuponscr.x - float(width / 2) + float(width * (h / 100.f))), glHeight - posdownonscr.y + 8),  ImVec4(armorcolor1[0], armorcolor1[1], armorcolor1[2], 1.0f), ImVec4(armorcolor2[0], armorcolor2[1], armorcolor2[2], 1.0f),(int)esp::player::glow);
														if(h<100){
															ImGui::PushFont(pixel);
				   											render->AddText(ImVec2((posuponscr.x -11- float(width / 2) + float(width * (h / 100.f)))-1,(glHeight - posdownonscr.y + 6-ImGui::CalcTextSize(std::to_string(h).c_str()).y/2)+1), ImGui::ColorConvertFloat4ToU32(ImVec4(0,0,0, 1)), std::to_string(h).c_str());
															render->AddText(ImVec2((posuponscr.x -11- float(width / 2) + float(width * (h / 100.f)))-1,(glHeight - posdownonscr.y + 6-ImGui::CalcTextSize(std::to_string(h).c_str()).y/2)-1), ImGui::ColorConvertFloat4ToU32(ImVec4(0,0,0, 1)), std::to_string(h).c_str());
															render->AddText(ImVec2((posuponscr.x -11- float(width / 2) + float(width * (h / 100.f)))+1,(glHeight - posdownonscr.y + 6-ImGui::CalcTextSize(std::to_string(h).c_str()).y/2)+1), ImGui::ColorConvertFloat4ToU32(ImVec4(0,0,0, 1)), std::to_string(h).c_str());
															render->AddText(ImVec2((posuponscr.x -11- float(width / 2) + float(width * (h / 100.f)))+1,(glHeight - posdownonscr.y + 6-ImGui::CalcTextSize(std::to_string(h).c_str()).y/2)-1), ImGui::ColorConvertFloat4ToU32(ImVec4(0,0,0, 1)),std::to_string(h).c_str());
															render->AddText(ImVec2((posuponscr.x -11- float(width / 2) + float(width * (h / 100.f))),glHeight - posdownonscr.y + 6-ImGui::CalcTextSize(std::to_string(h).c_str()).y/2), ImGui::ColorConvertFloat4ToU32(ImVec4(1,1,1, 1)), std::to_string(h).c_str());
															ImGui::PopFont();
														}
													}
												}
											}
										}
									}
								}
							}
                          }
						
void render_crosshair() {
	if (crosshair) {
    ImGuiIO& io = ImGui::GetIO(); // Получаем данные о дисплее
    ImVec2 center(io.DisplaySize.x / 2, io.DisplaySize.y / 2); // Центр экрана

    ImDrawList* draw_list = ImGui::GetBackgroundDrawList(); // Список для отрисовки

    float lineLength = 25.0f;   // Длина линий прицела
    float lineThickness = 2.0f; // Толщина линий
    ImU32 lineColor = IM_COL32(255, 255, 255, 255); // Цвет линий (красный)

    // Отрисовка горизонтальной линии
    draw_list->AddLine(
        ImVec2(center.x - lineLength / 2, center.y),
        ImVec2(center.x + lineLength / 2, center.y),
        lineColor,
        lineThickness
    );

    // Отрисовка вертикальной линии
    draw_list->AddLine(
        ImVec2(center.x, center.y - lineLength / 2),
        ImVec2(center.x, center.y + lineLength / 2),
        lineColor,
        lineThickness
    );
	}
}

