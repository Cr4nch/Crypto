#pragma once

#define u8int unsigned char
#define u16int unsigned short
#define u64int unsigned long


typedef struct _lrr{
  u64int* registr;
  u16int* r;
  int n;
  u64int hb;
}lrr;

u8int step_lrr(lrr* reg);




