//
// Created by Елена Адабашева on 23.06.2024.
//

#ifndef URANIUM_ZYGISK_MODULE_MAPSTOOLS_H
#define URANIUM_ZYGISK_MODULE_MAPSTOOLS_H

#include <stdint.h>
#include <stdio.h>
#include <vector>
#include <string>
#include <libgen.h>
#include "inttypes.h"
#include <elf.h>
bool validateElf(uintptr_t address) {
    Elf64_Ehdr* elfHeader = reinterpret_cast<Elf64_Ehdr*>(address);

    if (elfHeader->e_ident[EI_MAG0] == ELFMAG0 &&
        elfHeader->e_ident[EI_MAG1] == ELFMAG1 &&
        elfHeader->e_ident[EI_MAG2] == ELFMAG2 &&
        elfHeader->e_ident[EI_MAG3] == ELFMAG3) {
        return true;
    }

    return false;
}
typedef int Prot;
enum Prot_ {
    Prot_NONE = 0,
    Prot_READ = 1 << 1,
    Prot_WRITE = 1 << 2,
    Prot_EXEC = 1 << 3,
    Prot_PRIV = 1 << 4,
};

struct PMap {
    unsigned long long startAddress;
    unsigned long long endAddress;
    unsigned long long offset;
    std::string dev;
    unsigned long inode;
    std::string pathname;
    size_t length;
    Prot perms;
};

inline Prot parsePerms(const char* perms_str) {
    Prot perms = Prot_NONE;
    if (perms_str[0] == 'r') {
        perms |= Prot_READ;
    }
    if (perms_str[1] == 'w') {
        perms |= Prot_WRITE;
    }
    if (perms_str[2] == 'x') {
        perms |= Prot_EXEC;
    }
    if (perms_str[3] == 'p') {
        perms |= Prot_PRIV;
    }
    return perms;
}

class Memory {
public:
    static std::vector<PMap> GetMaps(const char *name);
};

std::vector<PMap> Memory::GetMaps(const char *name) {
    std::vector<PMap> fMaps;
    char filePath[128]{0};
    char line[512]{0};
    sprintf(filePath, "/proc/self/maps");
    FILE *fp = fopen(filePath, "r");
    if (!fp) return fMaps;
    while (fgets(line, sizeof(line), fp))
    {
        PMap map;

        char perms[5] = {0}, dev[11] = {0}, pathname[256] = {0};

        sscanf(line, "%llx-%llx %s %llx %s %lu %s",
               &map.startAddress, &map.endAddress,
               perms, &map.offset, dev, &map.inode, pathname);

        if (strstr(pathname, name)) {
            auto p = parsePerms(perms);
            if ((p & Prot_READ) && (p & Prot_PRIV)) {
                map.length = map.endAddress - map.startAddress;
                map.dev = dev;
                map.pathname = pathname;
                map.perms = p;
                fMaps.push_back(map);
            }
        }
    }
    fclose(fp);
    return fMaps;
}


uintptr_t GetBase(const char *lib_name) {
    uintptr_t base = 0;
    char map[128];
    char line[512];
    sprintf(map, "/proc/self/maps");
    FILE *f = fopen(map, "rt");
    if (!f) return base;
    while (fgets(line, sizeof line, f)) {
        uintptr_t tmpBase;
        uintptr_t tmpEnd;
        char tmpName[256];
        char tmpPerms[5];
        if (sscanf(line, "%" PRIXPTR "-%" PRIXPTR " %4s %*s %*s %*s %s", &tmpBase, &tmpEnd, tmpPerms, tmpName) > 0) {
            if (!strcmp(basename(tmpName), lib_name)) {
                auto perms = parsePerms(tmpPerms);
                if ((perms & Prot_READ) && (perms & Prot_PRIV) && validateElf(tmpBase)) {
                    base = tmpBase;
                }
            }
        }
    }
    fclose(f);
    return base;
}

uintptr_t getAbsoluteAddress(uintptr_t address){
    return GetBase("libil2cpp.so") + address;
}

#endif //URANIUM_ZYGISK_MODULE_MAPSTOOLS_H
