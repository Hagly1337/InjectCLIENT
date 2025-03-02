struct SafeBool {
    int key;
    int enc_value;

    bool get() {
        return (enc_value ^ key) == 1;
    }
};

void WriteSafeBool(uintptr_t ptr, int value) {
    auto curVal = *reinterpret_cast<SafeBool*>(ptr);

    SafeBool newVal;

    newVal.key = curVal.key;
    newVal.enc_value = value ^ curVal.key;

    memcpy(reinterpret_cast<void*>(ptr), &newVal, sizeof(SafeBool));
}

struct SafeInt {
    int key;
    int enc_value;

    bool get() {
        return enc_value ^ key;
    }
};

void WriteSafeInt(uintptr_t ptr, int value) {
    auto curVal = *reinterpret_cast<SafeInt*>(ptr);

    SafeInt newVal;

    newVal.key = curVal.key;
    newVal.enc_value = value ^ curVal.key;

    memcpy(reinterpret_cast<void*>(ptr), &newVal, sizeof(SafeInt));
}

struct SafeFloat
{
    int key;
    int enc_value;

    union fi
    {
        float f;
        int i;
    };

    float get()
    {
        fi v;
        v.i = (enc_value ^ key);
        return v.f;
    }
};

void WriteSafeFloat(uintptr_t ptr, float value)
{
    auto curVal = *reinterpret_cast<SafeFloat*>(ptr);

    SafeFloat::fi eVal;
    eVal.f = value;

    SafeFloat newVal;
    newVal.key = curVal.key;
    newVal.enc_value = eVal.i ^ curVal.key;

    memcpy(reinterpret_cast<void*>(ptr), &newVal, sizeof(SafeFloat));
}

