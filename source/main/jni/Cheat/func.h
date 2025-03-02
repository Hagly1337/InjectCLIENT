void wall() {
	if (wallshot) {
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

                    auto gunparameters = *(uintptr_t*) ((uint64_t) WeaponController + oxorany(0x150));

                    WriteSafeInt((uint64_t) gunparameters + oxorany(0x258), 999999999);
                                             
					}
            }
    }
	}
}

void ammo() {
	if (infammo) {
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
                    *(short*)(WeaponController + oxorany(0x110)) = 5;
                    *(short*)(WeaponController + oxorany(0x108)) = 5;
                }
            }
        }
    }
	}


void SetXp() {
	auto localPlayer = get_local_player();
	if (localPlayer == NULL) return;
	

	//if(sethe && isAllocated(localPlayerPhoton)) SetHealth(localPlayerPhoton, sethealthVal);
}
