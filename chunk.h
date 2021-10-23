#ifndef clox_chunk_h
#define clox_chunk_h

#include "common.h"
#include "value.h"


typedef enum {
    OP_RETURN,
    OP_CONSTANT,

    OP_NEGATE,
    OP_ADD,
    OP_SUBTRACT,
    OP_MULTIPLY,
    OP_DIVIDE,

    OP_NIL,
    OP_TRUE,
    OP_FALSE,

    OP_NOT,

    OP_EQUAL,
    OP_GREATER,
    OP_LESS,

    OP_PRINT,
    OP_POP,

    OP_DEFINE_GLOBAL,
    OP_GET_GLOBAL,

    OP_SET_GLOBAL,
    OP_GET_LOCAL,
    OP_SET_LOCAL,

    OP_JUMP_IF_FALSE,
    OP_JUMP,
    OP_LOOP,

    OP_CALL,
    OP_CLOSURE,

    OP_GET_UPVALUE,
    OP_SET_UPVALUE,
    OP_CLOSE_UPVALUE,
    OP_CLASS,

    OP_SET_PROPERTY,
    OP_GET_PROPERTY
} OpCode;

typedef struct {
    uint8_t* code;
    int count;
    int capacity;
    ValueArray constants;
    int* lines;
} Chunk;


void initChunk(Chunk* chunk);
void writeChunk(Chunk* chunk, uint8_t byte, int line);
int addConstant(Chunk* chunk, Value value);
void freeChunk(Chunk* chunk);

#endif // clox_chunk_h
