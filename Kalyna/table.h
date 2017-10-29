

#define DEBUG

#pragma once

#define u8int unsigned char 
#define u64int unsigned long long

extern u8int S0[16][16];
extern u8int S1[16][16];
extern u8int S2[16][16];
extern u8int S3[16][16];

extern u8int inv_S0[16][16];
extern u8int inv_S1[16][16];
extern u8int inv_S2[16][16];
extern u8int inv_S3[16][16];

extern u8int mix_table[8][8];
extern u8int inv_mix_table[8][8];
