
#ifndef clox_vm_h
#define clox_vm_h

#include "chunk.h"
#include "value.h"
#include "table.h"
#include "object.h"


#define FRAMES_MAX 64
#define STACK_MAX (FRAMES_MAX * UINT8_COUNT)

typedef struct {
    ObjClosure* closure;
    uint8_t* ip;
    Value* slots;
} CallFrame;

typedef struct {
    CallFrame frames[FRAMES_MAX];
    int frameCount;
    Value stack[STACK_MAX];
    Value* stackTop;
    Table globals;
    Table strings;
    Obj* objects;
    ObjUpValue* openUpValues;
    int grayCount;
    int grayCapacity;
    Obj** grayStack;

    size_t bytesAllocated;
    size_t nextGC;

    ObjString* initString;
} VM;

typedef enum {
    INTERPRET_OK,
    INTERPRET_COMPILE_ERROR,
    INTERPRET_RUNTIME_ERROR
} InterpretResult;

extern VM vm;

void initVM();
void freeVM();
InterpretResult interpret(const char* source);
void push(Value value);
Value pop();

static bool call_r(ObjClosure* closure, int argCount);
static bool callValue(Value callee, int argCount);
static ObjUpValue* captureUpValue(Value* local);
static void closeUpValues(Value* last);
static void defineMethod(ObjString* name);
static bool bindMethod(ObjClass* klass, ObjString* name);
static bool invoke(ObjString* name, int argCount);

#endif // clox_vm_h
