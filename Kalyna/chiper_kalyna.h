 
#include "table.h"
#include <stdlib.h>

#pragma once

#define KEY_128 0x01
#define KEY_256 0x02
#define KEY_512 0x03

#define BLOCK_128 0x10
#define BLOCK_256 0x20
#define BLOCK_512 0x30

#define MODE_B128_K128 BLOCK_128 && KEY_128
#define MODE_B128_K256 BLOCK_128 && KEY_256
#define MODE_B256_K256 BLOCK_256 && KEY_256
#define MODE_B256_K512 BLOCK_256 && KEY_512
#define MODE_B512_K512 BLOCK_512 && KEY_512

extern u8int shift_array_128[8];
extern u8int shift_array_256[8];
extern u8int shift_array_512[8];



typedef struct _chiper_kalyna{
    u8int Nk;
    u8int Nb;
    u8int Nr;
}chiper_kalyna;

//TODO Invalid add round key

void add_round_key_kalyna(u8int* state,u8int* round_key,chiper_kalyna* mode);
void xor_rount_key_kalyna(u8int* state,u8int* round_key,chiper_kalyna* mode);
void s_boxes_kalyna(u8int* state,chiper_kalyna* mode);
void shift_rows_kalyna(u8int* state,chiper_kalyna* mode);
void mix_columns_kalyna(u8int* state,chiper_kalyna* mode);

u8int* encrypt_kalyna(u8int* data,u8int** round_key,chiper_kalyna* mode);

void sub_round_key_kalyna(u8int* state,u8int* round_key,chiper_kalyna* mode);
void inv_s_boxes_kalyna(u8int* state,chiper_kalyna* mode);
void inv_shift_rows_kalyna(u8int* state,chiper_kalyna* mode);
void inv_mix_columns_kalyna(u8int* state,chiper_kalyna* mode);

u8int* decrypt_kalyna(u8int* data,u8int** round_key,chiper_kalyna* mode);


//TODO mayde bugs
u8int* key_expansion_ksigma_kalyna(u8int* key,chiper_kalyna* mode);
u8int** key_expansion_kalyna(u8int* key,u8int* ksigma,chiper_kalyna* mode);
void  key_expansion_odd_kalyna(u8int** round_key,chiper_kalyna* mode);

void shift_left_kalyna(u8int* tmp,chiper_kalyna* mode);
void rotate(u8int* data,chiper_kalyna* mode);
void rotate_left(u8int* key,u8int val,chiper_kalyna* mode);
