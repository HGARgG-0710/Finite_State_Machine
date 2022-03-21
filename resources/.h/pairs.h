#ifndef PAIRS
#define PAIRS

typedef struct
{
    char **keys;
    int **values;
} KeyValue;

typedef struct
{
    char **keys;
    char **values;
} CharKeyValue;

typedef union
{
    CharKeyValue char_kv;
    KeyValue num_kv;
} key_value;

typedef union
{
    const int integer;
    const char *string;
} value;

#endif