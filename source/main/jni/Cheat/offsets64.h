void init_hooks() {
	GetHealth = (int(*)(uintptr_t))(il2cpp_base + 0x26D0D18);
    GetArmor = (int(*)(uintptr_t))(il2cpp_base + 0x26D0D18); 
	GetMoney = (int(*)(uintptr_t))(il2cpp_base + 0x25C4480);
	Wts = (Vector3(*)(uintptr_t,Vector3))(il2cpp_base + 0x498AA04);
	MainController_Instance = (uintptr_t(*)())(il2cpp_base + oxorany(0x24D8538)); //public static MainController
	//GameManager$$Game = (bool (*)())(il2cpp_base + oxorany(0x2892384)); //public static bool (class GameManager)
	SetHealth = (void (*)(uintptr_t, int))(il2cpp_base + oxorany(0x251FCE0));
	get_position = (Vector3(*)(uintptr_t))(il2cpp_base + 0x49C4530); 
	get_transform = (uintptr_t(*)(uintptr_t))(il2cpp_base + 0x49B7F74);
    get_camera = (uintptr_t(*)())(il2cpp_base + 0x498AD80);
	get_bipedmap = (uintptr_t(*)(uintptr_t))(il2cpp_base + 0x27049F0); //public BipedMap
	#define OFFSET_INVENTORY_ITEM_ID 0xB0
	
}
