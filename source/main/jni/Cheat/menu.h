void render_menu() {
    
    

     // Ватермарк в верхнем левом углу  
    ImGui::SetNextWindowPos(ImVec2(10, 10), ImGuiCond_Always);  
    ImGui::SetNextWindowBgAlpha(0.4f); // Прозрачность фона  
    ImGui::Begin("Watermark", nullptr, ImGuiWindowFlags_NoTitleBar | ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoMove);  
    ImGui::TextColored(ImVec4(1, 0, 0, 1), "t.me/injectClient");  
    ImGui::Text("Version: 0.32.2");  
    ImGui::Text("FPS: %.1f", ImGui::GetIO().Framerate);  
    ImGui::End();  

   const char* chtoetoblyat = "Mod by t.me/injectclient | AKA ultra eblan mods!";
const char* poshelnax = "If another menu appeared here, know this person is a leecher!";
const char* BLYAAAAAAAAA = "x64 version | arm64-v8a [FREE Version]";  
int IDINAXOISUKAAAA = 29;

ImGui::GetForegroundDrawList()->AddText(ImGui::GetFont(), IDINAXOISUKAAAA, 
    {glWidth / 2 - ImGui::CalcTextSize(chtoetoblyat).x / 2, 150}, 
    ImColor(255,255,255), chtoetoblyat);

ImGui::GetForegroundDrawList()->AddText(ImGui::GetFont(), IDINAXOISUKAAAA, 
    {glWidth / 2 - ImGui::CalcTextSize(poshelnax).x / 2, 170}, 
    ImColor(255,255,255), poshelnax);

ImGui::GetForegroundDrawList()->AddText(ImGui::GetFont(), IDINAXOISUKAAAA, 
    {glWidth / 2 - ImGui::CalcTextSize(BLYAAAAAAAAA).x / 2, 190}, 
    ImColor(255,255,255), BLYAAAAAAAAA);

    // Основное меню (Теперь двигается)  
   ImGui::Begin(oxorany("InjectClient(Test Bypass)"));
	if(ImGui::CollapsingHeader(OBFUSCATE("VISUAl"))){
		
		ImGui::Text(oxorany("ESP"));
        ImGui::Checkbox(oxorany("Esp"), &esp::player::enable);
		ImGui::Checkbox(oxorany("Box"), &esp::player::box);
		ImGui::SameLine();
		ImGui::ColorEdit3(oxorany("BoxColor"), colors::esp::player::boxColor,ImGuiColorEditFlags_NoInputs);
		ImGui::Checkbox(oxorany("Fill"), &esp::player::fill);
		ImGui::Checkbox(oxorany("Health"), &esp::player::health);
		ImGui::Checkbox(oxorany("Name"), &esp::player::name);
		ImGui::Checkbox(oxorany("Money"), &esp::player::money);
		ImGui::Checkbox(oxorany("Distance"), &esp::player::dist);
		ImGui::Checkbox(oxorany("Armor"), &esp::player::armor);
		ImGui::Checkbox(oxorany("Weapon"), &esp::player::weapon);
	    ImGui::Combo(oxorany("Armor Type"), &esp::player::armortype, esp::player::armortypes, IM_ARRAYSIZE(esp::player::armortypes));
		switch (esp::player::armortype){
			case 0:
				ImGui::ColorEdit3(oxorany("Armor Color"), colors::esp::player::armorColor,ImGuiColorEditFlags_NoInputs);
			break;
			case 1:
				ImGui::ColorEdit3(oxorany("Armor Color1"), armorcolor2,ImGuiColorEditFlags_NoInputs);
				ImGui::ColorEdit3(oxorany("Armot Color2"), armorcolor1,ImGuiColorEditFlags_NoInputs);
			break;
		}
    	ImGui::Combo(oxorany("Health Type"), &esp::player::healthtype, esp::player::hptype, IM_ARRAYSIZE(esp::player::hptype));
		switch (esp::player::healthtype){
			case 0:
				ImGui::ColorEdit3(oxorany("Health Color"), colors::esp::player::HpColor,ImGuiColorEditFlags_NoInputs);
				break;
			case 1:
				ImGui::ColorEdit3(oxorany("Hp Color1"), hpcolor1,ImGuiColorEditFlags_NoInputs);
				ImGui::ColorEdit3(oxorany("Hp Color2"), hpcolor2,ImGuiColorEditFlags_NoInputs);
			break;
		}
    	ImGui::SliderFloat(oxorany("Glow Size"), &esp::player::glow,0,30);
		//ImGui::ColorEdit4(oxorany("Skeleton Color"),colors::esp::player::skeletonColor,ImGuiColorEditFlags_NoInputs);
		ImGui::SliderFloat(oxorany("Fill Value"), &colors::esp::player::fill_value,0,255);
		ImGui::Separator();
		ImGui::Text(oxorany("CHAMS"));
		ImGui::Checkbox(oxorany("Textures fix"), &texFix);                          
		ImGui::Checkbox(oxorany("Transparent mode"), &opacityChams);                          
		ImGui::Checkbox(oxorany("Textured"), &texturedChams);                          
		ImGui::SameLine();                           
		AddColorPicker(oxorany("Visible"), *(ImVec4 *) &visibleTexturedChamsColor, true, &visibleTexturedChamsRainbow, &visibleTexturedChamsPulse);                         
		ImGui::SameLine();                           
		AddColorPicker(oxorany("Invisible"), *(ImVec4 *) &invisibleTexturedChamsColor, true, &invisibleTexturedChamsRainbow, &invisibleTexturedChamsPulse);                          
		ImGui::Checkbox(oxorany("Wireframe"), &wireframeChams);                            
		ImGui::SameLine();                          
		AddColorPicker(oxorany("WF Color"), *(ImVec4 *) &wireframeChamsColor, true, &wireframeChamsRainbow, &wireframeChamsPulse);                           
		if (wireframeChams) {                              
		ImGui::Checkbox(oxorany("Wallhack##wireframe"), &wireframeWallhackChams);                            
		ImGui::SliderFloat(oxorany("Width##wireframe"), &wireframeWidthChams, 1, 5, oxorany("%.1f"));                           
		}						
		ImGui::Checkbox(oxorany("Shading"), &shadingChams);                      
		ImGui::SameLine();                          
		AddColorPicker(oxorany("SH Color"), *(ImVec4 *) &shadingChamsColor);                           
		if (shadingChams) {                              
		ImGui::Checkbox(oxorany("Wallhack##shading"), &shadingWallhackChams);                          
	    }                       
		ImGui::Checkbox(oxorany("Outline"), &outlineChams);                           
		ImGui::SameLine();                           
		AddColorPicker(oxorany("OU Color"), *(ImVec4 *) &outlineChamsColor, true, &outlineChamsRainbow, &outlineChamsPulse);                         
		if (outlineChams) {                               
		ImGui::Checkbox(oxorany("Wallhack##outline"), &outlineWallhackChams);                              
	    ImGui::SliderFloat(oxorany("Width##outline"), &outlineWidthChams, 1, 5, oxorany("%.1f"));                        
		}                           
		ImGui::Checkbox(oxorany("Glow"), &glowChams);                           
		ImGui::SameLine();                           
		AddColorPicker(oxorany("GL Color"), *(ImVec4 *) &glowChamsColor, true, &glowChamsRainbow, &glowChamsPulse);                       
		ImGui::Checkbox(oxorany("World color##wc"), &nightmode);                        
		ImGui::SameLine();                    
		AddColorPicker(oxorany("Color"), *(ImVec4 *) &worldChamsColor, true, &worldChamsRainbow);
	}
       
	if(ImGui::CollapsingHeader(oxorany("AIM"))){
	ImGui::Checkbox(oxorany("Enable Aimbot"), &Aimbot_enable);
	ImGui::Checkbox(oxorany("Enable fov"), &Drawfov);
	ImGui::SliderInt(oxorany("Fov Value"), &Aimbot_fov,0,360);
	}
		
	if(ImGui::CollapsingHeader(oxorany("MISC"))){
	ImGui::Checkbox(oxorany("Infinity Ammo"), &infammo);
	ImGui::Checkbox(oxorany("Fire Rate"), &firerate);
	ImGui::Checkbox(oxorany("No Recoil"), &norecoil);
	ImGui::Checkbox(oxorany("Wallshot"), &wallshot); 
	bool speedHackEnabled = false; // Флаг включения Speed Hack


	ImGui::Separator();
	ImGui::Checkbox(oxorany("Bunnyhop"), &hopbool);
    ImGui::SliderFloat(oxorany("Bunnyhop Val"), &hop_val, 0.0f, 10.0f);
	
	ImGui::Separator();
    ImGui::Text(oxorany("Crosshair"));
    ImGui::Checkbox(oxorany("Enable##hair"), &crosshair);
	}
	

		 
		}




