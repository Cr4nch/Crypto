#include <stdlib.h>
#include <string.h>
#pragma once

#define u8int unsigned char


u8int* expancse(u8int* data);
void   ip_func(u8int* data);
void   ip1_func(u8int* data);
void   p_func(u8int* data);
void   xor_key(u8int* data,u8int* key);
u8int* s_blocks(u8int* data);
void f(u8int* data,u8int* key);
void feistel_round(u8int* data,u8int* r_key);
void inv_feistel_round(u8int* data,u8int* r_key);

u8int* des_encrypt(u8int* data,u8int** keys);
u8int* des_decrypt(u8int* data,u8int** keys);


u8int** gen_keys(u8int* key);

#define BYTE_TO_BINARY_PATTERN "%c%c%c%c%c%c%c%c"
#define BYTE_TO_BINARY(byte)  \
  (byte & 0x80 ? '1' : '0'), \
  (byte & 0x40 ? '1' : '0'), \
  (byte & 0x20 ? '1' : '0'), \
  (byte & 0x10 ? '1' : '0'), \
  (byte & 0x08 ? '1' : '0'), \
  (byte & 0x04 ? '1' : '0'), \
  (byte & 0x02 ? '1' : '0'), \
  (byte & 0x01 ? '1' : '0') 
