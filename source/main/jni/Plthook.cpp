#include <list>
#include <vector>
#include <string.h>
#include <pthread.h>
#include <thread>
#include <cstring>
#include <jni.h>
#include <unistd.h>
#include <fstream>
#include <iostream>
#include <dlfcn.h>
#include <EGL/egl.h>
#include <GLES2/gl2.h>
#include <EGL/egl.h>
#include <imgui.h>
#include <imgui_impl_opengl3.h>
#include "Includes/Logger.h"
#include "Includes/obfuscate.h"
#include "Includes/Utils.h"
#include "Includes/MAPSTOOLS.H"
#include "Includes/oxorany.h"
#include "Includes/oxorany.cpp"
#include "Includes/oxorany_include.h"



#include "imgui.h"
#include "MenuCustoms.h"
#define IMGUI_DEFINE_MATH_OPERATORS
#include "imgui_internal.h"
#include "backends/imgui_impl_opengl3.h"
#include "backends/imgui_impl_android.h"
#define targetLibName OBFUSCATE("libil2cpp.so")

#include "KittyMemory/MemoryPatch.h"
#include "includes/Dobby/dobby.h"

#define hook_d(name, type, ...) \
type (*old##name)(__VA_ARGS__); \
type hook##name(__VA_ARGS__)

int glHeight, glWidth;
bool setup;

;

ImFont* pixel;
ImFont* weapon;
ImFont* SkeetNormal;
ImFont* SkeetSmall;

#include <libgen.h>
#include <fcntl.h>
#include <inttypes.h>
#include <jni.h>
#include <unistd.h>
#include <sys/mman.h>
#include <dirent.h>
#include <map>

#include "font/Font.h"

#include "font/Verdana.h"
#include "font/weapon.h"

#include "autoaddr.h"
#include "Plthook/plthook.h"

#include "Unity/Quaternion.h"
#include "Unity/Vector3.h"
#include "Unity/Quaternion.h"
#include "Unity/Vector2.h"
#include "Unity/Rect.h"
#include "Unity/monoString.h"

#include "Cheat/write.h"
#include "Cheat/bools.h"
#include "Cheat/hooks.h"
#include "Cheat/opengl.h"
#include "Cheat/esp.h"
#include "Cheat/func.h"
#include "Cheat/menu.h"
#include "Cheat/offsets64.h"
#include "Cheat/bypass.hpp"




void SetupImgui() {
    // Setup Dear ImGui context
    IMGUI_CHECKVERSION();
    ImGui::CreateContext();
    ImGuiIO& io = ImGui::GetIO();
	io.DisplaySize = ImVec2((float)glWidth, (float)glHeight);
   // ImGui::StyleColorsLight();
    ImGui_ImplOpenGL3_Init("#version 100");
    ImGui::GetStyle().ScaleAllSizes(4.0f);

    // We load the default font with increased size to improve readability on many devices with "high" DPI.
    ImFontConfig font_cfg;
    font_cfg.SizePixels = 28.0f;
    font_cfg.GlyphRanges = io.Fonts->GetGlyphRangesCyrillic();
    io.Fonts->AddFontFromMemoryTTF(&Verdana, sizeof Verdana, 30.0f, &font_cfg);
    pixel = io.Fonts->AddFontFromMemoryTTF(&Verdana, sizeof Verdana, 18.0f, &font_cfg);
	weapon = io.Fonts->AddFontFromMemoryTTF(&weapon1, sizeof weapon1, 28.0f, NULL);
    io.FontGlobalScale = 1.0f;
}
void TextCentered(std::string text) {
    auto windowWidth = ImGui::GetWindowSize().x;
    auto textWidth   = ImGui::CalcTextSize(text.c_str()).x;
    ImGui::SetCursorPosX((windowWidth - textWidth) * 0.5f);
    ImGui::Text(text.c_str());
}

#define HOOKAF(ret, func, ...) \
    ret (*orig##func)(__VA_ARGS__); \
    ret my##func(__VA_ARGS__)

HOOKAF(void, Input, void *thiz, void *ex_ab, void *ex_ac) {
    origInput(thiz, ex_ab, ex_ac);
    ImGui_ImplAndroid_HandleInputEvent((AInputEvent *)thiz);
    return;
}
	
EGLBoolean (*old_eglSwapBuffers)(EGLDisplay dpy, EGLSurface surface);
EGLBoolean hook_eglSwapBuffers(EGLDisplay dpy, EGLSurface surface) {
    eglQuerySurface(dpy, surface, EGL_WIDTH, &glWidth);
    eglQuerySurface(dpy, surface, EGL_HEIGHT, &glHeight);
   
    if (!setup) {
        SetupImgui();
        setup = true;
    }
    ImGui_ImplOpenGL3_NewFrame();
    ImGui::NewFrame();

    render_esp();
    render_menu();
	render_functions();
	render_crosshair();
	fire();
	wall();
	ammo();
	
	ImGui::End();
	if (Aimbot_enable){
        render_aimbot();
    }
	        
    ImGui::EndFrame();
	// Проверяем размер экрана
ImVec2 screenSize = ImGui::GetIO().DisplaySize;
static bool snowInitialized = false;
if (!snowInitialized) {
    GenerateSnow(100, screenSize);
    snowInitialized = true;
}

// Отрисовка снега
ImDrawList* drawList = ImGui::GetBackgroundDrawList();
RenderSnow(drawList, screenSize);

// Тут уже был твой код:
ImGui::Render();
ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
ImGui::Render();
ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
    ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());


    return old_eglSwapBuffers(dpy, surface);
}

void *cheat(void *) {
system(oxorany("echo 0 > /proc/sys/kernel/randomize_va_space"));
    do {
    sleep(oxorany(1));
    } while (!isLibraryLoaded(oxorany("libil2cpp.so")));
    plthook_t *plthook;
	if (plthook_open(&plthook, "lib/arm64/libunity.so") == 0) {
	plthook_replace(plthook, "eglSwapBuffers", (void *)hook_eglSwapBuffers, (void **)&old_eglSwapBuffers);
	plthook_close(plthook);
    }
	void *addr = dlsym(dlopen("lib/arm64/libunity.so", RTLD_LAZY), (oxorany("eglSwapBuffers")));
	DobbyHook(addr, (void*)hook_eglSwapBuffers, (void**)&old_eglSwapBuffers);
	dlclose(dlopen("libinject", RTLD_NOW || RTLD_GLOBAL));
	setShader(oxorany("_Metallic"));
    mlovinit();
    LogShaders();
	Wallhack();
    init_hooks();
    return NULL;
}
void *imgui_go(void *) {
    il2cpp_base = findLibrary(oxorany("libil2cpp.so"));
    plthook_t *plthook;
	if (plthook_open(&plthook, "lib/arm64/libunity.so") == 0) {
	plthook_replace(plthook, "eglSwapBuffers", (void *)hook_eglSwapBuffers, (void **)&old_eglSwapBuffers);
	plthook_close(plthook);
    }
	void *addr = dlsym(dlopen("lib/arm64/libunity.so", RTLD_LAZY), (oxorany("eglSwapBuffers")));
	DobbyHook(addr, (void*)hook_eglSwapBuffers, (void**)&old_eglSwapBuffers);

    pthread_t hacks;
    pthread_create(&hacks, NULL, cheat, NULL);
    return 0;
}

__attribute__((constructor))
void lib_main() {
    // Create a new thread so it does not block the main thread, means the game would not freeze
	void *sym_input = DobbySymbolResolver((oxorany("/system/lib/libinput.so")), (oxorany("_ZN7android13InputConsumer21initializeMotionEventEPNS_11MotionEventEPKNS_12InputMessageE")));
    if (NULL != sym_input) {
        DobbyHook((void *)sym_input, (void *) myInput, (void **)&origInput);
    }
    pthread_t ptid;
    pthread_create(&ptid, NULL, imgui_go, NULL);

}

