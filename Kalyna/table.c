#include "table.h"


u8int S0[16][16]={
    {0xA8, 0x43, 0x5F, 0x06, 0x6B, 0x75, 0x6C, 0x59, 0x71, 0xDF, 0x87, 0x95, 0x17, 0xF0, 0xD8, 0x09},
    {0x6D, 0xF3, 0x1D, 0xCB, 0xC9, 0x4D, 0x2C, 0xAF, 0x79, 0xE0, 0x97, 0xFD, 0x6F, 0x4B, 0x45, 0x39},
    {0x3E, 0xDD, 0xA3, 0x4F, 0xB4, 0xB6, 0x9A, 0x0E, 0x1F, 0xBF, 0x15, 0xE1, 0x49, 0xD2, 0x93, 0xC6},
    {0x92, 0x72, 0x9E, 0x61, 0xD1, 0x63, 0xFA, 0xEE, 0xF4, 0x19, 0xD5, 0xAD, 0x58, 0xA4, 0xBB, 0xA1},
    {0xDC, 0xF2, 0x83, 0x37, 0x42, 0xE4, 0x7A, 0x32, 0x9C, 0xCC, 0xAB, 0x4A, 0x8F, 0x6E, 0x04, 0x27},
    {0x2E, 0xE7, 0xE2, 0x5A, 0x96, 0x16, 0x23, 0x2B, 0xC2, 0x65, 0x66, 0x0F, 0xBC, 0xA9, 0x47, 0x41},
    {0x34, 0x48, 0xFC, 0xB7, 0x6A, 0x88, 0xA5, 0x53, 0x86, 0xF9, 0x5B, 0xDB, 0x38, 0x7B, 0xC3, 0x1E},
    {0x22, 0x33, 0x24, 0x28, 0x36, 0xC7, 0xB2, 0x3B, 0x8E, 0x77, 0xBA, 0xF5, 0x14, 0x9F, 0x08, 0x55},
    {0x9B, 0x4C, 0xFE, 0x60, 0x5C, 0xDA, 0x18, 0x46, 0xCD, 0x7D, 0x21, 0xB0, 0x3F, 0x1B, 0x89, 0xFF}, 
    {0xEB, 0x84, 0x69, 0x3A, 0x9D, 0xD7, 0xD3, 0x70, 0x67, 0x40, 0xB5, 0xDE, 0x5D, 0x30, 0x91, 0xB1},
    {0x78, 0x11, 0x01, 0xE5, 0x00, 0x68, 0x98, 0xA0, 0xC5, 0x02, 0xA6, 0x74, 0x2D, 0x0B, 0xA2, 0x76},
    {0xB3, 0xBE, 0xCE, 0xBD, 0xAE, 0xE9, 0x8A, 0x31, 0x1C, 0xEC, 0xF1, 0x99, 0x94, 0xAA, 0xF6, 0x26},
    {0x2F, 0xEF, 0xE8, 0x8C, 0x35, 0x03, 0xD4, 0x7F, 0xFB, 0x05, 0xC1, 0x5E, 0x90, 0x20, 0x3D, 0x82},
    {0xF7, 0xEA, 0x0A, 0x0D, 0x7E, 0xF8, 0x50, 0x1A, 0xC4, 0x07, 0x57, 0xB8, 0x3C, 0x62, 0xE3, 0xC8},
    {0xAC, 0x52, 0x64, 0x10, 0xD0, 0xD9, 0x13, 0x0C, 0x12, 0x29, 0x51, 0xB9, 0xCF, 0xD6, 0x73, 0x8D},
    {0x81, 0x54, 0xC0, 0xED, 0x4E, 0x44, 0xA7, 0x2A, 0x85, 0x25, 0xE6, 0xCA, 0x7C, 0x8B, 0x56, 0x80}
};

u8int S1[16][16]={
    {0xCE, 0xBB, 0xEB, 0x92, 0xEA, 0xCB, 0x13, 0xC1, 0xE9, 0x3A, 0xD6, 0xB2, 0xD2, 0x90, 0x17, 0xF8},
    {0x42, 0x15, 0x56, 0xB4, 0x65, 0x1C, 0x88, 0x43, 0xC5, 0x5C, 0x36, 0xBA, 0xF5, 0x57, 0x67, 0x8D},
    {0x31, 0xF6, 0x64, 0x58, 0x9E, 0xF4, 0x22, 0xAA, 0x75, 0x0F, 0x02, 0xB1, 0xDF, 0x6D, 0x73, 0x4D},
    {0x7C, 0x26, 0x2E, 0xF7, 0x08, 0x5D, 0x44, 0x3E, 0x9F, 0x14, 0xC8, 0xAE, 0x54, 0x10, 0xD8, 0xBC},
    {0x1A, 0x6B, 0x69, 0xF3, 0xBD, 0x33, 0xAB, 0xFA, 0xD1, 0x9B, 0x68, 0x4E, 0x16, 0x95, 0x91, 0xEE},
    {0x4C, 0x63, 0x8E, 0x5B, 0xCC, 0x3C, 0x19, 0xA1, 0x81, 0x49, 0x7B, 0xD9, 0x6F, 0x37, 0x60, 0xCA},
    {0xE7, 0x2B, 0x48, 0xFD, 0x96, 0x45, 0xFC, 0x41, 0x12, 0x0D, 0x79, 0xE5, 0x89, 0x8C, 0xE3, 0x20},
    {0x30, 0xDC, 0xB7, 0x6C, 0x4A, 0xB5, 0x3F, 0x97, 0xD4, 0x62, 0x2D, 0x06, 0xA4, 0xA5, 0x83, 0x5F},
    {0x2A, 0xDA, 0xC9, 0x00, 0x7E, 0xA2, 0x55, 0xBF, 0x11, 0xD5, 0x9C, 0xCF, 0x0E, 0x0A, 0x3D, 0x51},
    {0x7D, 0x93, 0x1B, 0xFE, 0xC4, 0x47, 0x09, 0x86, 0x0B, 0x8F, 0x9D, 0x6A, 0x07, 0xB9, 0xB0, 0x98},
    {0x18, 0x32, 0x71, 0x4B, 0xEF, 0x3B, 0x70, 0xA0, 0xE4, 0x40, 0xFF, 0xC3, 0xA9, 0xE6, 0x78, 0xF9},
    {0x8B, 0x46, 0x80, 0x1E, 0x38, 0xE1, 0xB8, 0xA8, 0xE0, 0x0C, 0x23, 0x76, 0x1D, 0x25, 0x24, 0x05},
    {0xF1, 0x6E, 0x94, 0x28, 0x9A, 0x84, 0xE8, 0xA3, 0x4F, 0x77, 0xD3, 0x85, 0xE2, 0x52, 0xF2, 0x82},
    {0x50, 0x7A, 0x2F, 0x74, 0x53, 0xB3, 0x61, 0xAF, 0x39, 0x35, 0xDE, 0xCD, 0x1F, 0x99, 0xAC, 0xAD},
    {0x72, 0x2C, 0xDD, 0xD0, 0x87, 0xBE, 0x5E, 0xA6, 0xEC, 0x04, 0xC6, 0x03, 0x34, 0xFB, 0xDB, 0x59},
    {0xB6, 0xC2, 0x01, 0xF0, 0x5A, 0xED, 0xA7, 0x66, 0x21, 0x7F, 0x8A, 0x27, 0xC7, 0xC0, 0x29, 0xD7}
};

u8int S2[16][16]={
    {0x93, 0xD9, 0x9A, 0xB5, 0x98, 0x22, 0x45, 0xFC, 0xBA, 0x6A, 0xDF, 0x02, 0x9F, 0xDC, 0x51, 0x59},
    {0x4A, 0x17, 0x2B, 0xC2, 0x94, 0xF4, 0xBB, 0xA3, 0x62, 0xE4, 0x71, 0xD4, 0xCD, 0x70, 0x16, 0xE1},
    {0x49, 0x3C, 0xC0, 0xD8, 0x5C, 0x9B, 0xAD, 0x85, 0x53, 0xA1, 0x7A, 0xC8, 0x2D, 0xE0, 0xD1, 0x72},
    {0xA6, 0x2C, 0xC4, 0xE3, 0x76, 0x78, 0xB7, 0xB4, 0x09, 0x3B, 0x0E, 0x41, 0x4C, 0xDE, 0xB2, 0x90},
    {0x25, 0xA5, 0xD7, 0x03, 0x11, 0x00, 0xC3, 0x2E, 0x92, 0xEF, 0x4E, 0x12, 0x9D, 0x7D, 0xCB, 0x35},
    {0x10, 0xD5, 0x4F, 0x9E, 0x4D, 0xA9, 0x55, 0xC6, 0xD0, 0x7B, 0x18, 0x97, 0xD3, 0x36, 0xE6, 0x48},
    {0x56, 0x81, 0x8F, 0x77, 0xCC, 0x9C, 0xB9, 0xE2, 0xAC, 0xB8, 0x2F, 0x15, 0xA4, 0x7C, 0xDA, 0x38},
    {0x1E, 0x0B, 0x05, 0xD6, 0x14, 0x6E, 0x6C, 0x7E, 0x66, 0xFD, 0xB1, 0xE5, 0x60, 0xAF, 0x5E, 0x33},
    {0x87, 0xC9, 0xF0, 0x5D, 0x6D, 0x3F, 0x88, 0x8D, 0xC7, 0xF7, 0x1D, 0xE9, 0xEC, 0xED, 0x80, 0x29},
    {0x27, 0xCF, 0x99, 0xA8, 0x50, 0x0F, 0x37, 0x24, 0x28, 0x30, 0x95, 0xD2, 0x3E, 0x5B, 0x40, 0x83},
    {0xB3, 0x69, 0x57, 0x1F, 0x07, 0x1C, 0x8A, 0xBC, 0x20, 0xEB, 0xCE, 0x8E, 0xAB, 0xEE, 0x31, 0xA2},
    {0x73, 0xF9, 0xCA, 0x3A, 0x1A, 0xFB, 0x0D, 0xC1, 0xFE, 0xFA, 0xF2, 0x6F, 0xBD, 0x96, 0xDD, 0x43},
    {0x52, 0xB6, 0x08, 0xF3, 0xAE, 0xBE, 0x19, 0x89, 0x32, 0x26, 0xB0, 0xEA, 0x4B, 0x64, 0x84, 0x82},
    {0x6B, 0xF5, 0x79, 0xBF, 0x01, 0x5F, 0x75, 0x63, 0x1B, 0x23, 0x3D, 0x68, 0x2A, 0x65, 0xE8, 0x91},
    {0xF6, 0xFF, 0x13, 0x58, 0xF1, 0x47, 0x0A, 0x7F, 0xC5, 0xA7, 0xE7, 0x61, 0x5A, 0x06, 0x46, 0x44},
    {0x42, 0x04, 0xA0, 0xDB, 0x39, 0x86, 0x54, 0xAA, 0x8C, 0x34, 0x21, 0x8B, 0xF8, 0x0C, 0x74, 0x67}
};

u8int S3[16][16]={
    {0x68, 0x8D, 0xCA, 0x4D, 0x73, 0x4B, 0x4E, 0x2A, 0xD4, 0x52, 0x26, 0xB3, 0x54, 0x1E, 0x19, 0x1F},
    {0x22, 0x03, 0x46, 0x3D, 0x2D, 0x4A, 0x53, 0x83, 0x13, 0x8A, 0xB7, 0xD5, 0x25, 0x79, 0xF5, 0xBD},
    {0x58, 0x2F, 0x0D, 0x02, 0xED, 0x51, 0x9E, 0x11, 0xF2, 0x3E, 0x55, 0x5E, 0xD1, 0x16, 0x3C, 0x66},
    {0x70, 0x5D, 0xF3, 0x45, 0x40, 0xCC, 0xE8, 0x94, 0x56, 0x08, 0xCE, 0x1A, 0x3A, 0xD2, 0xE1, 0xDF},
    {0xB5, 0x38, 0x6E, 0x0E, 0xE5, 0xF4, 0xF9, 0x86, 0xE9, 0x4F, 0xD6, 0x85, 0x23, 0xCF, 0x32, 0x99},
    {0x31, 0x14, 0xAE, 0xEE, 0xC8, 0x48, 0xD3, 0x30, 0xA1, 0x92, 0x41, 0xB1, 0x18, 0xC4, 0x2C, 0x71},
    {0x72, 0x44, 0x15, 0xFD, 0x37, 0xBE, 0x5F, 0xAA, 0x9B, 0x88, 0xD8, 0xAB, 0x89, 0x9C, 0xFA, 0x60},
    {0xEA, 0xBC, 0x62, 0x0C, 0x24, 0xA6, 0xA8, 0xEC, 0x67, 0x20, 0xDB, 0x7C, 0x28, 0xDD, 0xAC, 0x5B},
    {0x34, 0x7E, 0x10, 0xF1, 0x7B, 0x8F, 0x63, 0xA0, 0x05, 0x9A, 0x43, 0x77, 0x21, 0xBF, 0x27, 0x09},
    {0xC3, 0x9F, 0xB6, 0xD7, 0x29, 0xC2, 0xEB, 0xC0, 0xA4, 0x8B, 0x8C, 0x1D, 0xFB, 0xFF, 0xC1, 0xB2},
    {0x97, 0x2E, 0xF8, 0x65, 0xF6, 0x75, 0x07, 0x04, 0x49, 0x33, 0xE4, 0xD9, 0xB9, 0xD0, 0x42, 0xC7},
    {0x6C, 0x90, 0x00, 0x8E, 0x6F, 0x50, 0x01, 0xC5, 0xDA, 0x47, 0x3F, 0xCD, 0x69, 0xA2, 0xE2, 0x7A},
    {0xA7, 0xC6, 0x93, 0x0F, 0x0A, 0x06, 0xE6, 0x2B, 0x96, 0xA3, 0x1C, 0xAF, 0x6A, 0x12, 0x84, 0x39},
    {0xE7, 0xB0, 0x82, 0xF7, 0xFE, 0x9D, 0x87, 0x5C, 0x81, 0x35, 0xDE, 0xB4, 0xA5, 0xFC, 0x80, 0xEF},
    {0xCB, 0xBB, 0x6B, 0x76, 0xBA, 0x5A, 0x7D, 0x78, 0x0B, 0x95, 0xE3, 0xAD, 0x74, 0x98, 0x3B, 0x36},
    {0x64, 0x6D, 0xDC, 0xF0, 0x59, 0xA9, 0x4C, 0x17, 0x7F, 0x91, 0xB8, 0xC9, 0x57, 0x1B, 0xE0, 0x61}
};

u8int mix_table[8][8]={//0x75^0xbb^0x
    {0x01, 0x01, 0x05, 0x01, 0x08, 0x06, 0x07, 0x04},
    {0x04, 0x01, 0x01, 0x05, 0x01, 0x08, 0x06, 0x07},
    {0x07, 0x04, 0x01, 0x01, 0x05, 0x01, 0x08, 0x06},
    {0x06, 0x07, 0x04, 0x01, 0x01, 0x05, 0x01, 0x08},
    {0x08, 0x06, 0x07, 0x04, 0x01, 0x01, 0x05, 0x01},
    {0x01, 0x08, 0x06, 0x07, 0x04, 0x01, 0x01, 0x05},
    {0x05, 0x01, 0x08, 0x06, 0x07, 0x04, 0x01, 0x01},
    {0x01, 0x05, 0x01, 0x08, 0x06, 0x07, 0x04, 0x01},
};

u8int inv_mix_table[8][8]={
    {0xAD, 0x95, 0x76, 0xA8, 0x2F, 0x49, 0xD7, 0xCA},
    {0xCA, 0xAD, 0x95, 0x76, 0xA8, 0x2F, 0x49, 0xD7},
    {0xD7, 0xCA, 0xAD, 0x95, 0x76, 0xA8, 0x2F, 0x49},
    {0x49, 0xD7, 0xCA, 0xAD, 0x95, 0x76, 0xA8, 0x2F},
    {0x2F, 0x49, 0xD7, 0xCA, 0xAD, 0x95, 0x76, 0xA8},
    {0xA8, 0x2F, 0x49, 0xD7, 0xCA, 0xAD, 0x95, 0x76},
    {0x76, 0xA8, 0x2F, 0x49, 0xD7, 0xCA, 0xAD, 0x95},
    {0x95, 0x76, 0xA8, 0x2F, 0x49, 0xD7, 0xCA, 0xAD}
};


u8int inv_S0[16][16]=
{
    {0xa4, 0xa2, 0xa9, 0xc5, 0x4e, 0xc9, 0x03, 0xd9, 0x7e, 0x0f, 0xd2, 0xad, 0xe7, 0xd3, 0x27, 0x5b}, 
    {0xe3, 0xa1, 0xe8, 0xe6, 0x7c, 0x2a, 0x55, 0x0c, 0x86, 0x39, 0xd7, 0x8d, 0xb8, 0x12, 0x6f, 0x28}, 
    {0xcd, 0x8a, 0x70, 0x56, 0x72, 0xf9, 0xbf, 0x4f, 0x73, 0xe9, 0xf7, 0x57, 0x16, 0xac, 0x50, 0xc0}, 
    {0x9d, 0xb7, 0x47, 0x71, 0x60, 0xc4, 0x74, 0x43, 0x6c, 0x1f, 0x93, 0x77, 0xdc, 0xce, 0x20, 0x8c}, 
    {0x99, 0x5f, 0x44, 0x01, 0xf5, 0x1e, 0x87, 0x5e, 0x61, 0x2c, 0x4b, 0x1d, 0x81, 0x15, 0xf4, 0x23}, 
    {0xd6, 0xea, 0xe1, 0x67, 0xf1, 0x7f, 0xfe, 0xda, 0x3c, 0x07, 0x53, 0x6a, 0x84, 0x9c, 0xcb, 0x02}, 
    {0x83, 0x33, 0xdd, 0x35, 0xe2, 0x59, 0x5a, 0x98, 0xa5, 0x92, 0x64, 0x04, 0x06, 0x10, 0x4d, 0x1c}, 
    {0x97, 0x08, 0x31, 0xee, 0xab, 0x05, 0xaf, 0x79, 0xa0, 0x18, 0x46, 0x6d, 0xfc, 0x89, 0xd4, 0xc7}, 
    {0xff, 0xf0, 0xcf, 0x42, 0x91, 0xf8, 0x68, 0x0a, 0x65, 0x8e, 0xb6, 0xfd, 0xc3, 0xef, 0x78, 0x4c}, 
    {0xcc, 0x9e, 0x30, 0x2e, 0xbc, 0x0b, 0x54, 0x1a, 0xa6, 0xbb, 0x26, 0x80, 0x48, 0x94, 0x32, 0x7d}, 
    {0xa7, 0x3f, 0xae, 0x22, 0x3d, 0x66, 0xaa, 0xf6, 0x00, 0x5d, 0xbd, 0x4a, 0xe0, 0x3b, 0xb4, 0x17}, 
    {0x8b, 0x9f, 0x76, 0xb0, 0x24, 0x9a, 0x25, 0x63, 0xdb, 0xeb, 0x7a, 0x3e, 0x5c, 0xb3, 0xb1, 0x29}, 
    {0xf2, 0xca, 0x58, 0x6e, 0xd8, 0xa8, 0x2f, 0x75, 0xdf, 0x14, 0xfb, 0x13, 0x49, 0x88, 0xb2, 0xec}, 
    {0xe4, 0x34, 0x2d, 0x96, 0xc6, 0x3a, 0xed, 0x95, 0x0e, 0xe5, 0x85, 0x6b, 0x40, 0x21, 0x9b, 0x09}, 
    {0x19, 0x2b, 0x52, 0xde, 0x45, 0xa3, 0xfa, 0x51, 0xc2, 0xb5, 0xd1, 0x90, 0xb9, 0xf3, 0x37, 0xc1}, 
    {0x0d, 0xba, 0x41, 0x11, 0x38, 0x7b, 0xbe, 0xd0, 0xd5, 0x69, 0x36, 0xc8, 0x62, 0x1b, 0x82, 0x8f}
};

u8int inv_S1[16][16]=
{
    {0x83, 0xf2, 0x2a, 0xeb, 0xe9, 0xbf, 0x7b, 0x9c, 0x34, 0x96, 0x8d, 0x98, 0xb9, 0x69, 0x8c, 0x29}, 
    {0x3d, 0x88, 0x68, 0x06, 0x39, 0x11, 0x4c, 0x0e, 0xa0, 0x56, 0x40, 0x92, 0x15, 0xbc, 0xb3, 0xdc}, 
    {0x6f, 0xf8, 0x26, 0xba, 0xbe, 0xbd, 0x31, 0xfb, 0xc3, 0xfe, 0x80, 0x61, 0xe1, 0x7a, 0x32, 0xd2}, 
    {0x70, 0x20, 0xa1, 0x45, 0xec, 0xd9, 0x1a, 0x5d, 0xb4, 0xd8, 0x09, 0xa5, 0x55, 0x8e, 0x37, 0x76}, 
    {0xa9, 0x67, 0x10, 0x17, 0x36, 0x65, 0xb1, 0x95, 0x62, 0x59, 0x74, 0xa3, 0x50, 0x2f, 0x4b, 0xc8}, 
    {0xd0, 0x8f, 0xcd, 0xd4, 0x3c, 0x86, 0x12, 0x1d, 0x23, 0xef, 0xf4, 0x53, 0x19, 0x35, 0xe6, 0x7f}, 
    {0x5e, 0xd6, 0x79, 0x51, 0x22, 0x14, 0xf7, 0x1e, 0x4a, 0x42, 0x9b, 0x41, 0x73, 0x2d, 0xc1, 0x5c}, 
    {0xa6, 0xa2, 0xe0, 0x2e, 0xd3, 0x28, 0xbb, 0xc9, 0xae, 0x6a, 0xd1, 0x5a, 0x30, 0x90, 0x84, 0xf9}, 
    {0xb2, 0x58, 0xcf, 0x7e, 0xc5, 0xcb, 0x97, 0xe4, 0x16, 0x6c, 0xfa, 0xb0, 0x6d, 0x1f, 0x52, 0x99}, 
    {0x0d, 0x4e, 0x03, 0x91, 0xc2, 0x4d, 0x64, 0x77, 0x9f, 0xdd, 0xc4, 0x49, 0x8a, 0x9a, 0x24, 0x38}, 
    {0xa7, 0x57, 0x85, 0xc7, 0x7c, 0x7d, 0xe7, 0xf6, 0xb7, 0xac, 0x27, 0x46, 0xde, 0xdf, 0x3b, 0xd7}, 
    {0x9e, 0x2b, 0x0b, 0xd5, 0x13, 0x75, 0xf0, 0x72, 0xb6, 0x9d, 0x1b, 0x01, 0x3f, 0x44, 0xe5, 0x87}, 
    {0xfd, 0x07, 0xf1, 0xab, 0x94, 0x18, 0xea, 0xfc, 0x3a, 0x82, 0x5f, 0x05, 0x54, 0xdb, 0x00, 0x8b}, 
    {0xe3, 0x48, 0x0c, 0xca, 0x78, 0x89, 0x0a, 0xff, 0x3e, 0x5b, 0x81, 0xee, 0x71, 0xe2, 0xda, 0x2c}, 
    {0xb8, 0xb5, 0xcc, 0x6e, 0xa8, 0x6b, 0xad, 0x60, 0xc6, 0x08, 0x04, 0x02, 0xe8, 0xf5, 0x4f, 0xa4}, 
    {0xf3, 0xc0, 0xce, 0x43, 0x25, 0x1c, 0x21, 0x33, 0x0f, 0xaf, 0x47, 0xed, 0x66, 0x63, 0x93, 0xaa}
};

u8int inv_S2[16][16]=
{
    {0x45, 0xd4, 0x0b, 0x43, 0xf1, 0x72, 0xed, 0xa4, 0xc2, 0x38, 0xe6, 0x71, 0xfd, 0xb6, 0x3a, 0x95}, 
    {0x50, 0x44, 0x4b, 0xe2, 0x74, 0x6b, 0x1e, 0x11, 0x5a, 0xc6, 0xb4, 0xd8, 0xa5, 0x8a, 0x70, 0xa3}, 
    {0xa8, 0xfa, 0x05, 0xd9, 0x97, 0x40, 0xc9, 0x90, 0x98, 0x8f, 0xdc, 0x12, 0x31, 0x2c, 0x47, 0x6a}, 
    {0x99, 0xae, 0xc8, 0x7f, 0xf9, 0x4f, 0x5d, 0x96, 0x6f, 0xf4, 0xb3, 0x39, 0x21, 0xda, 0x9c, 0x85}, 
    {0x9e, 0x3b, 0xf0, 0xbf, 0xef, 0x06, 0xee, 0xe5, 0x5f, 0x20, 0x10, 0xcc, 0x3c, 0x54, 0x4a, 0x52}, 
    {0x94, 0x0e, 0xc0, 0x28, 0xf6, 0x56, 0x60, 0xa2, 0xe3, 0x0f, 0xec, 0x9d, 0x24, 0x83, 0x7e, 0xd5}, 
    {0x7c, 0xeb, 0x18, 0xd7, 0xcd, 0xdd, 0x78, 0xff, 0xdb, 0xa1, 0x09, 0xd0, 0x76, 0x84, 0x75, 0xbb}, 
    {0x1d, 0x1a, 0x2f, 0xb0, 0xfe, 0xd6, 0x34, 0x63, 0x35, 0xd2, 0x2a, 0x59, 0x6d, 0x4d, 0x77, 0xe7}, 
    {0x8e, 0x61, 0xcf, 0x9f, 0xce, 0x27, 0xf5, 0x80, 0x86, 0xc7, 0xa6, 0xfb, 0xf8, 0x87, 0xab, 0x62}, 
    {0x3f, 0xdf, 0x48, 0x00, 0x14, 0x9a, 0xbd, 0x5b, 0x04, 0x92, 0x02, 0x25, 0x65, 0x4c, 0x53, 0x0c}, 
    {0xf2, 0x29, 0xaf, 0x17, 0x6c, 0x41, 0x30, 0xe9, 0x93, 0x55, 0xf7, 0xac, 0x68, 0x26, 0xc4, 0x7d}, 
    {0xca, 0x7a, 0x3e, 0xa0, 0x37, 0x03, 0xc1, 0x36, 0x69, 0x66, 0x08, 0x16, 0xa7, 0xbc, 0xc5, 0xd3}, 
    {0x22, 0xb7, 0x13, 0x46, 0x32, 0xe8, 0x57, 0x88, 0x2b, 0x81, 0xb2, 0x4e, 0x64, 0x1c, 0xaa, 0x91}, 
    {0x58, 0x2e, 0x9b, 0x5c, 0x1b, 0x51, 0x73, 0x42, 0x23, 0x01, 0x6e, 0xf3, 0x0d, 0xbe, 0x3d, 0x0a}, 
    {0x2d, 0x1f, 0x67, 0x33, 0x19, 0x7b, 0x5e, 0xea, 0xde, 0x8b, 0xcb, 0xa9, 0x8c, 0x8d, 0xad, 0x49}, 
    {0x82, 0xe4, 0xba, 0xc3, 0x15, 0xd1, 0xe0, 0x89, 0xfc, 0xb1, 0xb9, 0xb5, 0x07, 0x79, 0xb8, 0xe1}
};

u8int inv_S3[16][16]=
{
    {0xb2, 0xb6, 0x23, 0x11, 0xa7, 0x88, 0xc5, 0xa6, 0x39, 0x8f, 0xc4, 0xe8, 0x73, 0x22, 0x43, 0xc3}, 
    {0x82, 0x27, 0xcd, 0x18, 0x51, 0x62, 0x2d, 0xf7, 0x5c, 0x0e, 0x3b, 0xfd, 0xca, 0x9b, 0x0d, 0x0f}, 
    {0x79, 0x8c, 0x10, 0x4c, 0x74, 0x1c, 0x0a, 0x8e, 0x7c, 0x94, 0x07, 0xc7, 0x5e, 0x14, 0xa1, 0x21}, 
    {0x57, 0x50, 0x4e, 0xa9, 0x80, 0xd9, 0xef, 0x64, 0x41, 0xcf, 0x3c, 0xee, 0x2e, 0x13, 0x29, 0xba}, 
    {0x34, 0x5a, 0xae, 0x8a, 0x61, 0x33, 0x12, 0xb9, 0x55, 0xa8, 0x15, 0x05, 0xf6, 0x03, 0x06, 0x49}, 
    {0xb5, 0x25, 0x09, 0x16, 0x0c, 0x2a, 0x38, 0xfc, 0x20, 0xf4, 0xe5, 0x7f, 0xd7, 0x31, 0x2b, 0x66}, 
    {0x6f, 0xff, 0x72, 0x86, 0xf0, 0xa3, 0x2f, 0x78, 0x00, 0xbc, 0xcc, 0xe2, 0xb0, 0xf1, 0x42, 0xb4}, 
    {0x30, 0x5f, 0x60, 0x04, 0xec, 0xa5, 0xe3, 0x8b, 0xe7, 0x1d, 0xbf, 0x84, 0x7b, 0xe6, 0x81, 0xf8}, 
    {0xde, 0xd8, 0xd2, 0x17, 0xce, 0x4b, 0x47, 0xd6, 0x69, 0x6c, 0x19, 0x99, 0x9a, 0x01, 0xb3, 0x85}, 
    {0xb1, 0xf9, 0x59, 0xc2, 0x37, 0xe9, 0xc8, 0xa0, 0xed, 0x4f, 0x89, 0x68, 0x6d, 0xd5, 0x26, 0x91}, 
    {0x87, 0x58, 0xbd, 0xc9, 0x98, 0xdc, 0x75, 0xc0, 0x76, 0xf5, 0x67, 0x6b, 0x7e, 0xeb, 0x52, 0xcb}, 
    {0xd1, 0x5b, 0x9f, 0x0b, 0xdb, 0x40, 0x92, 0x1a, 0xfa, 0xac, 0xe4, 0xe1, 0x71, 0x1f, 0x65, 0x8d}, 
    {0x97, 0x9e, 0x95, 0x90, 0x5d, 0xb7, 0xc1, 0xaf, 0x54, 0xfb, 0x02, 0xe0, 0x35, 0xbb, 0x3a, 0x4d}, 
    {0xad, 0x2c, 0x3d, 0x56, 0x08, 0x1b, 0x4a, 0x93, 0x6a, 0xab, 0xb8, 0x7a, 0xf2, 0x7d, 0xda, 0x3f}, 
    {0xfe, 0x3e, 0xbe, 0xea, 0xaa, 0x44, 0xc6, 0xd0, 0x36, 0x48, 0x70, 0x96, 0x77, 0x24, 0x53, 0xdf}, 
    {0xf3, 0x83, 0x28, 0x32, 0x45, 0x1e, 0xa4, 0xd3, 0xa2, 0x46, 0x6e, 0x9c, 0xdd, 0x63, 0xd4, 0x9d}
};

 