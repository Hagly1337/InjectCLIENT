#include "Unity/Vector3.h"
uintptr_t il2cpp_base;

//ESP
std::vector<uintptr_t>get_player_list()
{
 
 std::vector<uintptr_t>null_vec;
 
 uintptr_t playermanager_getinstance = *(uintptr_t*)(il2cpp_base+85199632);
 uintptr_t playermanager_il2cppclass = *(uintptr_t*)(playermanager_getinstance+0x20);
 uintptr_t playermanager_staticfields = *(uintptr_t*)(playermanager_il2cppclass+0xB8);
 uintptr_t playermanager_instance = *(uintptr_t*)(playermanager_staticfields+0x0);
 
 if (playermanager_instance) 
 {
  auto entities = *(monoDictionary<int,uintptr_t>**)(playermanager_instance+0x28);
  return entities->getValues();
 }
 else
  return null_vec;
}

uintptr_t get_local_player()
{
 uintptr_t playermanager_getinstance = *(uintptr_t*)(il2cpp_base+85199632);
 uintptr_t playermanager_il2cppclass = *(uintptr_t*)(playermanager_getinstance+0x20);
 uintptr_t playermanager_staticfields = *(uintptr_t*)(playermanager_il2cppclass+0xB8);
 uintptr_t playermanager_instance = *(uintptr_t*)(playermanager_staticfields+0x0);
 auto local_player = *(uintptr_t*)(playermanager_instance+0x70);
 return local_player;
}

uintptr_t get_photon(uintptr_t player)
{
	return *(uintptr_t*)(player+0x138); // 0.32.0
}

uintptr_t get_aim(uintptr_t player) 
{
	return *(uintptr_t*) ((uint64_t) player + 0x60); // 0.32.0
}

uint8_t get_team(uintptr_t player)
{
	return *(uint8_t*)(player + 0x59); // 0.32.0
}

Vector3 (*get_position)(uintptr_t);
Vector3 (*Wts)(uintptr_t,Vector3);

uintptr_t (*get_transform)(uintptr_t);
uintptr_t (*get_camera)();
uintptr_t (*get_bipedmap)(uintptr_t);

uintptr_t (*MainController_Instance)();

int (*GetMoney)(uintptr_t);
int (*GetArmor)(uintptr_t);
int (*GetHealth)(uintptr_t);

void (*SetHealth)(uintptr_t, int);

bool (*GameManager$$Game)();

monoString* Getname(uintptr_t player){
    return *(monoString**)(player + 0x20);
}


void fire() {
	if (firerate) {
	if (get_local_player()==NULL) return;
		auto localPlayer = get_local_player();
	  
        auto WeaponryController = *(uintptr_t*)((uintptr_t)localPlayer + oxorany(0x68));
        if (WeaponryController != NULL)
        {
            auto WeaponController = *(uintptr_t*)( WeaponryController + oxorany(0x98));
            if (WeaponController != NULL)
            {
    
                auto WeaponParametrs = *(uintptr_t*)(WeaponController + oxorany(0xA0));
    
                auto weaponid = *(int*)(WeaponParametrs + oxorany(0x18));
    
                if (weaponid < 70)
                {
						WriteSafeFloat((uint64_t)(WeaponController + oxorany(0xF0)), 0);
						}
				   }
		      }
	     }
    }


void render_functions() {
	if(hopbool) {
		if (get_local_player()==NULL) return;
		auto localPlayer = get_local_player();
		
		void* movementController = *(void **)((uint64_t)localPlayer + 0x78);
		if(movementController) {
			void* translationParameters = *(void* *)((uint64_t) movementController + 0xA8);
			if(translationParameters) {
				void* jumpParameters = *(void **)((uint64_t) translationParameters + 0x50);
				if(jumpParameters) {
					*(float *)((uint64_t) jumpParameters + 0x10) = (float) hop_val;
					*(float *)((uint64_t) jumpParameters + 0x60) = (float) hop_val;
				}
			}
		}
	}
	if (norecoil) {
	if (get_local_player()==NULL) return;
		auto localPlayer = get_local_player();
	  
        auto WeaponryController = *(uintptr_t*)((uintptr_t)localPlayer + oxorany(0x68));
        if (WeaponryController != NULL)
        {
            auto WeaponController = *(uintptr_t*)( WeaponryController + oxorany(0x98));
            if (WeaponController != NULL)
            {
    
                auto WeaponParametrs = *(uintptr_t*)(WeaponController + oxorany(0xA0));
    
                auto weaponid = *(int*)(WeaponParametrs + oxorany(0x18));
    
                if (weaponid < 70)
                {
				
			    void* recoilControl = *(void**)((uint64_t) WeaponController + oxorany(0x148));
                void *gunparameterssss = *(void **) ((uint64_t) WeaponController + oxorany(0x150));
                void* recoilparam = *(void**)((uint64_t) gunparameterssss + oxorany(0x130));
                if (recoilControl && recoilparam)
				  {   
				  *(float*)((uint64_t) recoilControl + oxorany(0x10)) = 0.0f;                              
				  *(float*)((uint64_t) recoilControl + oxorany(0x14)) = 0.0f;                                  
				  *(float*)((uint64_t) recoilControl + oxorany(0x18)) = 0.0f;                                 
				  *(Vector2*)((uint64_t) recoilControl + oxorany(0x1C)) = Vector2(0,0);                               
				  *(Vector2*)((uint64_t) recoilControl + oxorany(0x24)) = Vector2(0,0);                            
				  *(float*)((uint64_t) recoilControl + oxorany(0x2C)) = 0;                       
				  *(Vector2*)((uint64_t) recoilControl +oxorany(0x30)) = Vector2(0,0);                           
				  *(float*)((uint64_t) recoilControl + oxorany(0x38)) = 0;                                  
				  *(float*)((uint64_t) recoilControl + oxorany(0x70)) = 0;                                 								
				  WriteSafeFloat((uint64_t) recoilControl + oxorany(0x58), 0);                                  
				  WriteSafeFloat((uint64_t) recoilControl + oxorany(0x60), 0);                                  
				  WriteSafeFloat((uint64_t) recoilControl + oxorany(0x68), 0);               
                  *(float*)((uint64_t) recoilparam + oxorany(0x38)) = 0.0f;
                  *(float*)((uint64_t) recoilparam + oxorany(0x48)) = 0.0f;
                  *(float*)((uint64_t) recoilparam + oxorany(0x4C)) = 0.0f;
                  *(float*)((uint64_t) recoilparam + oxorany(0x50)) = 0.0f;
                  *(float*)((uint64_t) recoilparam + oxorany(0x54)) = 0.0f;                    
				  }
                }
            }
        }                  
	}
}



ImVec2 world2screen_i(Vector3 pos) {
    auto cam = get_camera();
    if (!cam) return {0,0};

    Vector3 worldPoint = Wts(cam,pos);

    return {worldPoint.x,glHeight - worldPoint.y};
}

ImVec2 world2screen_c(Vector3 pos, bool &checker) {
    auto cam = get_camera();
    if (!cam) return {0,0};

    Vector3 worldPoint = Wts(cam,pos);

    checker = worldPoint.z > 1;
    return ImVec2(worldPoint.x,glHeight - worldPoint.y);
}


 float NormalizeAngle (float angle){
    while (angle>360)
        angle -= 360;
    while (angle<0)
        angle += 360;
    return angle;
}

Vector3 NormalizeAngles (Vector3 angles){
    angles.x = NormalizeAngle (angles.x);
    angles.y= NormalizeAngle (angles.y);
    angles.z = NormalizeAngle (angles.z);
    return angles;
}

Vector3 ToEulerRad(Quaternion q1){
    float Rad2Deg2 = 360.0f / (M_PI * 2.0f);

    float sqw = q1.w * q1.w;
    float sqx = q1.x * q1.x;
    float sqy = q1.y * q1.y;
    float sqz = q1.z * q1.x;
    float unit = sqx + sqy + sqz + sqw;
    float test = q1.x * q1.w - q1.y * q1.z;
    Vector3 v;

    if (test>0.4995f*unit) {
        v.y = 2.0f * atan2f (q1.y, q1.x);
        v.x = M_PI / 2.0f;
        v.z = 0;
        return NormalizeAngles(v * Rad2Deg2);
    }
    if (test<-0.4995f*unit) {
        v.y = -2.0f * atan2f (q1.y, q1.x);
        v.x = -M_PI / 2.0f;
        v.z = 0;
        return NormalizeAngles (v * Rad2Deg2);
    }
    Quaternion q(q1.w, q1.z, q1.x, q1.y);
    v.y = atan2f (2.0f * q.x * q.w + 2.0f * q.y * q.z, 1 - 2.0f * (q.z * q.z + q.w * q.w)); // YaW
    v.x = asinf (2.0f * (q.x * q.z - q.w * q.y));
    v.z = atan2f (2.0f * q.x * q.y + 2.0f * q.x * q.w, 1 - 2.0f * (q.y * q.y + q.z * q.z)); // roll
    return NormalizeAngles (v * Rad2Deg2);
}

float X1, Y1, Z1;
float get_3D_Distance(float Self_x, float Self_y, float Self_z, float Object_x, float Object_y, float Object_z)
{
    float x, y, z;
    x = Self_x - Object_x;
    y = Self_y - Object_y;
    z = Self_z - Object_z;
    return (float)(sqrt(x * x + y * y + z * z));
}


bool if_fov(ImVec2 vec1, ImVec2 vec2, int radius) {
    if ((pow(vec1.x - vec2.x, 2) + pow(vec1.y - vec2.y, 2)) <= pow(radius, 2)) {
        return true;
    }
    else {
        return false;
    }
}

void render_aimbot(){

	if (Drawfov) {
    ImGui::GetBackgroundDrawList()->AddCircle({ImGui::GetIO().DisplaySize.x / 2,ImGui::GetIO().DisplaySize.y / 2}, Aimbot_fov, ImColor(255,0,0));
    }
	
    auto localPlayer = get_local_player();
    if (localPlayer == NULL) return;

    int localTeam = get_team(localPlayer);

    for (const auto & player : get_player_list())
    {
        if (player == NULL) continue;
		
	    if (get_camera() == NULL) continue;

        auto pl = player;

        int playerTeam = get_team(pl);

        if (playerTeam == localTeam) continue;
      
        uintptr_t aiming = *(uintptr_t*) ((uint64_t) localPlayer + 0x60);

        if (aiming == NULL) continue;

        uintptr_t aimingData = *(uintptr_t*) ((uint64_t) aiming + 0x90);

        if (aimingData == NULL) continue;

        auto BipedMap = get_bipedmap(player);

        auto current_bone = *(uintptr_t*)((uintptr_t)BipedMap + 0x20);

        if (current_bone == NULL) continue;

        auto Pc = *(uintptr_t*)((uint64_t)player+0x48);

        auto isvisible = *(bool*)(Pc + 0x30);

        if (!isvisible) continue;

        auto BonePosScr = world2screen_i(get_position(current_bone));

        if (!if_fov(ImVec2(ImGui::GetIO().DisplaySize.x / 2,ImGui::GetIO().DisplaySize.y / 2), BonePosScr, Aimbot_fov)) continue;

        Quaternion Qrot = Quaternion::LookRotation(get_position(current_bone) - get_position(get_transform(get_camera())));
    
        Vector3 rot = ToEulerRad(Qrot);

        if (rot.x >= 275.0f) rot.x -= 360.0f;
        if (rot.x <= -275.0f) rot.x += 360.0f;

        *(Vector3 *) ((uint64_t) aimingData + 0x18) = rot;
        *(Vector3 *) ((uint64_t) aimingData + 0x24) = rot;
		}
}

Vector2 ImV_to_UV(ImVec2 v) {
    return Vector2(v.x,v.y);
};
ImVec2 UV_to_ImV(Vector2 v) {
    return ImVec2(v.x,v.y);
};

/*uintptr_t GetBones(uintptr_t p) {
    return *(uintptr_t*) ((uint64_t) p + 0x18);
}*/
/*Vector3 GetPlayerHead(uintptr_t player) {
    return get_position(*(uintptr_t*) ((uint64_t) get_bipedmap(player) + 0x20));
}
Vector3 GetPlayerNeck(uintptr_t player) {
    return get_position(*(uintptr_t*) ((uint64_t) get_bipedmap(player) + 0x28));
}
Vector3 GetPlayerHip(uintptr_t player) {
    return get_position(*(uintptr_t*) ((uint64_t) get_bipedmap(player) + 0x80));
}
Vector3 GetPlayerleftLowerArm(uintptr_t player) {
    return get_position(*(uintptr_t*) ((uint64_t) get_bipedmap(player) + 0x60));
}
Vector3 GetPlayerLeftHand(uintptr_t player) {
    return get_position(*(uintptr_t*) ((uint64_t) get_bipedmap(player) + 0x68));
}
Vector3 GetPlayerRightHand(uintptr_t player) {
    return get_position(*(uintptr_t*) ((uint64_t) get_bipedmap(player) + 0x80));
}
Vector3 GetPlayerleftUpperArm(uintptr_t player) {
    return get_position(*(uintptr_t*) ((uint64_t) get_bipedmap(player) + 0x58));
}
Vector3 GetPlayerrightLowerArm(uintptr_t player) {
    return get_position(*(uintptr_t*) ((uint64_t) get_bipedmap(player) + 0x78));
}
Vector3 GetPlayerrightUpperArm(uintptr_t player) {
    return get_position(*(uintptr_t*) ((uint64_t) get_bipedmap(player) + 0x70));
}
Vector3 GetPlayerleftLowerLeg(uintptr_t player) {
    return get_position(*(uintptr_t*) ((uint64_t) get_bipedmap(player) + 0x30));
}
Vector3 GetPlayerleftUpperLeg(uintptr_t player) {
    return get_position(*(uintptr_t*) ((uint64_t) get_bipedmap(player) + 0x40));
}
Vector3 GetPlayerrightLowerLeg(uintptr_t player) {
    return get_position(*(uintptr_t*) ((uint64_t) get_bipedmap(player) + 0x48));
}
Vector3 GetPlayerrightUpperLeg(uintptr_t player) {
    return get_position(*(uintptr_t*) ((uint64_t) get_bipedmap(player) + 0x28));
}


uintptr_t get_head(uintptr_t player) {
    return *(uintptr_t*)((uint64_t) get_bipedmap(player) + 0x20);
}*/

inline float lerp(float a, float b, float f) {
    return clamp<float>(a + f * (b - a),a > b ? b : a,a > b ? a : b);
}
