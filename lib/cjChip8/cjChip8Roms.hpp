#include <Arduino.h>

// array size is 697
const byte test_3[] PROGMEM  = {
  0x12, 0x08, 0xa4, 0x65, 0xda, 0xb4, 0x00, 0xee, 0x00, 0xe0, 0x68, 0x32, 0x6b, 0x1a, 0xa4, 0xb1, 
  0xd8, 0xb4, 0x68, 0x3a, 0xa4, 0xb5, 0xd8, 0xb4, 0x68, 0x02, 0x69, 0x06, 0x6a, 0x0b, 0x6b, 0x01, 
  0x65, 0x2a, 0x66, 0x2b, 0xa4, 0x75, 0xd8, 0xb4, 0xa4, 0xad, 0xd9, 0xb4, 0xa4, 0x65, 0x36, 0x2b, 
  0xa4, 0x61, 0xda, 0xb4, 0x6b, 0x06, 0xa4, 0x79, 0xd8, 0xb4, 0xa4, 0xad, 0xd9, 0xb4, 0xa4, 0x61, 
  0x45, 0x2a, 0xa4, 0x65, 0xda, 0xb4, 0x6b, 0x0b, 0xa4, 0x7d, 0xd8, 0xb4, 0xa4, 0xad, 0xd9, 0xb4, 
  0xa4, 0x61, 0x55, 0x60, 0xa4, 0x65, 0xda, 0xb4, 0x6b, 0x10, 0xa4, 0x85, 0xd8, 0xb4, 0xa4, 0xad, 
  0xd9, 0xb4, 0xa4, 0x61, 0x76, 0xff, 0x46, 0x2a, 0xa4, 0x65, 0xda, 0xb4, 0x7b, 0x05, 0xa4, 0x8d, 
  0xd8, 0xb4, 0xa4, 0xad, 0xd9, 0xb4, 0xa4, 0x61, 0x95, 0x60, 0xa4, 0x65, 0xda, 0xb4, 0x7b, 0x05, 
  0xa4, 0x6d, 0xd8, 0xb4, 0xa4, 0xad, 0xd9, 0xb4, 0xa4, 0x65, 0x12, 0x8e, 0xa4, 0x61, 0xda, 0xb4, 
  0x68, 0x12, 0x69, 0x16, 0x6a, 0x1b, 0x6b, 0x01, 0xa4, 0x71, 0xd8, 0xb4, 0xa4, 0xad, 0xd9, 0xb4, 
  0x22, 0x02, 0x7b, 0x05, 0xa4, 0x69, 0xd8, 0xb4, 0xa4, 0xa1, 0xd9, 0xb4, 0xa4, 0x65, 0xda, 0xb4, 
  0x7b, 0x05, 0xa4, 0x89, 0xd8, 0xb4, 0xa4, 0x69, 0xd9, 0xb4, 0xa4, 0x61, 0x65, 0x2a, 0x67, 0x00, 
  0x87, 0x50, 0x47, 0x2a, 0xa4, 0x65, 0xda, 0xb4, 0x7b, 0x05, 0xa4, 0x89, 0xd8, 0xb4, 0xa4, 0x6d, 
  0xd9, 0xb4, 0xa4, 0x61, 0x66, 0x0b, 0x67, 0x2a, 0x87, 0x61, 0x47, 0x2b, 0xa4, 0x65, 0xda, 0xb4, 
  0x7b, 0x05, 0xa4, 0x89, 0xd8, 0xb4, 0xa4, 0x71, 0xd9, 0xb4, 0xa4, 0x61, 0x66, 0x78, 0x67, 0x1f, 
  0x87, 0x62, 0x47, 0x18, 0xa4, 0x65, 0xda, 0xb4, 0x7b, 0x05, 0xa4, 0x89, 0xd8, 0xb4, 0xa4, 0x75, 
  0xd9, 0xb4, 0xa4, 0x61, 0x66, 0x78, 0x67, 0x1f, 0x87, 0x63, 0x47, 0x67, 0xa4, 0x65, 0xda, 0xb4, 
  0x68, 0x22, 0x69, 0x26, 0x6a, 0x2b, 0x6b, 0x01, 0xa4, 0x89, 0xd8, 0xb4, 0xa4, 0x79, 0xd9, 0xb4, 
  0xa4, 0x61, 0x66, 0x8c, 0x67, 0x8c, 0x87, 0x64, 0x47, 0x18, 0xa4, 0x65, 0xda, 0xb4, 0x7b, 0x05, 
  0xa4, 0x89, 0xd8, 0xb4, 0xa4, 0x7d, 0xd9, 0xb4, 0xa4, 0x61, 0x66, 0x8c, 0x67, 0x78, 0x87, 0x65, 
  0x47, 0xec, 0xa4, 0x65, 0xda, 0xb4, 0x7b, 0x05, 0xa4, 0x89, 0xd8, 0xb4, 0xa4, 0x85, 0xd9, 0xb4, 
  0xa4, 0x61, 0x66, 0x78, 0x67, 0x8c, 0x87, 0x67, 0x47, 0xec, 0xa4, 0x65, 0xda, 0xb4, 0x7b, 0x05, 
  0xa4, 0x89, 0xd8, 0xb4, 0xa4, 0x81, 0xd9, 0xb4, 0xa4, 0x61, 0x66, 0x0f, 0x86, 0x66, 0x46, 0x07, 
  0xa4, 0x65, 0xda, 0xb4, 0x7b, 0x05, 0xa4, 0x89, 0xd8, 0xb4, 0xa4, 0xa1, 0xd9, 0xb4, 0xa4, 0x61, 
  0x66, 0xe0, 0x86, 0x6e, 0x46, 0xc0, 0xa4, 0x65, 0xda, 0xb4, 0x7b, 0x05, 0xa4, 0xa5, 0xd8, 0xb4, 
  0xa4, 0x81, 0xd9, 0xb4, 0xa4, 0x5e, 0xf1, 0x65, 0xa4, 0x65, 0x30, 0xaa, 0xa4, 0x61, 0x31, 0x55, 
  0xa4, 0x61, 0xda, 0xb4, 0x68, 0x32, 0x69, 0x36, 0x6a, 0x3b, 0x6b, 0x01, 0xa4, 0xa5, 0xd8, 0xb4, 
  0xa4, 0x7d, 0xd9, 0xb4, 0xa4, 0x5e, 0x60, 0x00, 0x61, 0x30, 0xf1, 0x55, 0xa4, 0x5e, 0xf0, 0x65, 
  0x81, 0x00, 0xa4, 0x5f, 0xf0, 0x65, 0xa4, 0x65, 0x30, 0x30, 0xa4, 0x61, 0x31, 0x00, 0xa4, 0x61, 
  0xda, 0xb4, 0x7b, 0x05, 0xa4, 0xa5, 0xd8, 0xb4, 0xa4, 0x75, 0xd9, 0xb4, 0xa4, 0x5e, 0x66, 0x89, 
  0xf6, 0x33, 0xf2, 0x65, 0xa4, 0x65, 0x30, 0x01, 0xa4, 0x61, 0x31, 0x03, 0xa4, 0x61, 0x32, 0x07, 
  0xa4, 0x61, 0xda, 0xb4, 0x7b, 0x05, 0xa4, 0xa5, 0xd8, 0xb4, 0xa4, 0xa1, 0xd9, 0xb4, 0xa4, 0x61, 
  0x66, 0x04, 0xf6, 0x1e, 0xda, 0xb4, 0x7b, 0x05, 0xa4, 0xa9, 0xd8, 0xb4, 0xa4, 0xad, 0xd9, 0xb4, 
  0xa4, 0x65, 0x66, 0xff, 0x76, 0x0a, 0x36, 0x09, 0xa4, 0x61, 0x86, 0x66, 0x36, 0x04, 0xa4, 0x61, 
  0x66, 0xff, 0x60, 0x0a, 0x86, 0x04, 0x36, 0x09, 0xa4, 0x61, 0x86, 0x66, 0x36, 0x04, 0xa4, 0x61, 
  0x66, 0xff, 0x86, 0x6e, 0x86, 0x66, 0x36, 0x7f, 0xa4, 0x61, 0x86, 0x66, 0x86, 0x6e, 0x36, 0x7e, 
  0xa4, 0x61, 0x66, 0x05, 0x76, 0xf6, 0x36, 0xfb, 0xa4, 0x61, 0x66, 0x05, 0x86, 0x05, 0x36, 0xfb, 
  0xa4, 0x61, 0x66, 0x05, 0x80, 0x67, 0x30, 0xfb, 0xa4, 0x61, 0xda, 0xb4, 0x14, 0x5c, 0xaa, 0x55, 
  0x00, 0x00, 0xa0, 0x40, 0xa0, 0x00, 0xa0, 0xc0, 0x80, 0xe0, 0xa0, 0xa0, 0xe0, 0xc0, 0x40, 0x40, 
  0xe0, 0xe0, 0x20, 0xc0, 0xe0, 0xe0, 0x60, 0x20, 0xe0, 0xa0, 0xe0, 0x20, 0x20, 0xe0, 0xc0, 0x20, 
  0xc0, 0x60, 0x80, 0xe0, 0xe0, 0xe0, 0x20, 0x40, 0x40, 0xe0, 0xe0, 0xa0, 0xe0, 0xe0, 0xe0, 0x20, 
  0xc0, 0x40, 0xa0, 0xe0, 0xa0, 0xc0, 0xe0, 0xa0, 0xe0, 0xe0, 0x80, 0x80, 0xe0, 0xc0, 0xa0, 0xa0, 
  0xc0, 0xe0, 0xc0, 0x80, 0xe0, 0xe0, 0x80, 0xc0, 0x80, 0x00, 0xa0, 0xa0, 0x40, 0xa0, 0x40, 0xa0, 
  0xa0, 0x0a, 0xae, 0xa2, 0x42, 0x10, 0x30, 0x10, 0xb8
};

// array size is 132
const byte test_2[] PROGMEM  = {
  0x00, 0xe0, 0xa2, 0x2a, 0x60, 0x0c, 0x61, 0x08, 0xd0, 0x1f, 0x70, 0x09, 0xa2, 0x39, 0xd0, 0x1f, 
  0xa2, 0x48, 0x70, 0x08, 0xd0, 0x1f, 0x70, 0x04, 0xa2, 0x57, 0xd0, 0x1f, 0x70, 0x08, 0xa2, 0x66, 
  0xd0, 0x1f, 0x70, 0x08, 0xa2, 0x75, 0xd0, 0x1f, 0x12, 0x28, 0xff, 0x00, 0xff, 0x00, 0x3c, 0x00, 
  0x3c, 0x00, 0x3c, 0x00, 0x3c, 0x00, 0xff, 0x00, 0xff, 0xff, 0x00, 0xff, 0x00, 0x38, 0x00, 0x3f, 
  0x00, 0x3f, 0x00, 0x38, 0x00, 0xff, 0x00, 0xff, 0x80, 0x00, 0xe0, 0x00, 0xe0, 0x00, 0x80, 0x00, 
  0x80, 0x00, 0xe0, 0x00, 0xe0, 0x00, 0x80, 0xf8, 0x00, 0xfc, 0x00, 0x3e, 0x00, 0x3f, 0x00, 0x3b, 
  0x00, 0x39, 0x00, 0xf8, 0x00, 0xf8, 0x03, 0x00, 0x07, 0x00, 0x0f, 0x00, 0xbf, 0x00, 0xfb, 0x00, 
  0xf3, 0x00, 0xe3, 0x00, 0x43, 0xe5, 0x05, 0xe2, 0x00, 0x85, 0x07, 0x81, 0x01, 0x80, 0x02, 0x80, 
  0x02, 0xe6, 0x02, 0xe7
};

// array size is 260
const byte test_1[] PROGMEM  = {
  0x00, 0xe0, 0x61, 0x01, 0x60, 0x08, 0xa2, 0x50, 0xd0, 0x1f, 0x60, 0x10, 0xa2, 0x5f, 0xd0, 0x1f, 
  0x60, 0x18, 0xa2, 0x6e, 0xd0, 0x1f, 0x60, 0x20, 0xa2, 0x7d, 0xd0, 0x1f, 0x60, 0x28, 0xa2, 0x8c, 
  0xd0, 0x1f, 0x60, 0x30, 0xa2, 0x9b, 0xd0, 0x1f, 0x61, 0x10, 0x60, 0x08, 0xa2, 0xaa, 0xd0, 0x1f, 
  0x60, 0x10, 0xa2, 0xb9, 0xd0, 0x1f, 0x60, 0x18, 0xa2, 0xc8, 0xd0, 0x1f, 0x60, 0x20, 0xa2, 0xd7, 
  0xd0, 0x1f, 0x60, 0x28, 0xa2, 0xe6, 0xd0, 0x1f, 0x60, 0x30, 0xa2, 0xf5, 0xd0, 0x1f, 0x12, 0x4e, 
  0x0f, 0x02, 0x02, 0x02, 0x02, 0x02, 0x00, 0x00, 0x1f, 0x3f, 0x71, 0xe0, 0xe5, 0xe0, 0xe8, 0xa0, 
  0x0d, 0x2a, 0x28, 0x28, 0x28, 0x00, 0x00, 0x18, 0xb8, 0xb8, 0x38, 0x38, 0x3f, 0xbf, 0x00, 0x19, 
  0xa5, 0xbd, 0xa1, 0x9d, 0x00, 0x00, 0x0c, 0x1d, 0x1d, 0x01, 0x0d, 0x1d, 0x9d, 0x01, 0xc7, 0x29, 
  0x29, 0x29, 0x27, 0x00, 0x00, 0xf8, 0xfc, 0xce, 0xc6, 0xc6, 0xc6, 0xc6, 0x00, 0x49, 0x4a, 0x49, 
  0x48, 0x3b, 0x00, 0x00, 0x00, 0x01, 0x03, 0x03, 0x03, 0x01, 0xf0, 0x30, 0x90, 0x00, 0x00, 0x80, 
  0x00, 0x00, 0x00, 0xfe, 0xc7, 0x83, 0x83, 0x83, 0xc6, 0xfc, 0xe7, 0xe0, 0xe0, 0xe0, 0xe0, 0x71, 
  0x3f, 0x1f, 0x00, 0x00, 0x07, 0x02, 0x02, 0x02, 0x02, 0x39, 0x38, 0x38, 0x38, 0x38, 0xb8, 0xb8, 
  0x38, 0x00, 0x00, 0x31, 0x4a, 0x79, 0x40, 0x3b, 0xdd, 0xdd, 0xdd, 0xdd, 0xdd, 0xdd, 0xdd, 0xdd, 
  0x00, 0x00, 0xa0, 0x38, 0x20, 0xa0, 0x18, 0xce, 0xfc, 0xf8, 0xc0, 0xd4, 0xdc, 0xc4, 0xc5, 0x00, 
  0x00, 0x30, 0x44, 0x24, 0x14, 0x63, 0xf1, 0x03, 0x07, 0x07, 0x27, 0x67, 0x23, 0x71, 0x00, 0x00, 
  0x28, 0x8e, 0xa8, 0xa8, 0xa6, 0xce, 0x87, 0x03, 0x03, 0x03, 0x87, 0xfe, 0xfc, 0x00, 0x00, 0x60, 
  0x90, 0xf0, 0x80, 0x70
};

// array size is 85
const byte minimalGame[] PROGMEM  = {
  0x00, 0xe0, 0x22, 0x14, 0x22, 0x1a, 0x22, 0x1a, 0x22, 0x20, 0x22, 0x1a, 0x60, 0x01, 0xf0, 0x15, 
  0x22, 0x42, 0x12, 0x06, 0x63, 0x20, 0x64, 0x19, 0x00, 0xee, 0xa2, 0x4a, 0xd3, 0x46, 0x00, 0xee, 
  0x60, 0x08, 0xe0, 0x9e, 0x12, 0x28, 0x74, 0x01, 0x60, 0x02, 0xe0, 0x9e, 0x12, 0x30, 0x74, 0xff, 
  0x60, 0x04, 0xe0, 0x9e, 0x12, 0x38, 0x73, 0xff, 0x60, 0x06, 0xe0, 0x9e, 0x12, 0x40, 0x73, 0x01, 
  0x00, 0xee, 0xf0, 0x07, 0x30, 0x00, 0x12, 0x42, 0x00, 0xee, 0x3c, 0x18, 0xff, 0x18, 0x24, 0xe7, 
  0x7e, 0xff, 0x99, 0xe7, 0x3c
};

// array size is 340
const byte snake[] PROGMEM  = {
  0x6c, 0x01, 0x6d, 0x02, 0x00, 0xe0, 0x62, 0x20, 0x63, 0x10, 0x65, 0x03, 0x64, 0x00, 0xa3, 0x45, 
  0x6e, 0x08, 0x60, 0x00, 0x61, 0x00, 0x22, 0x20, 0x60, 0x30, 0x61, 0x00, 0x22, 0x20, 0x12, 0x3c, 
  0xd0, 0x1f, 0x70, 0x08, 0xd0, 0x1f, 0x80, 0xe5, 0x71, 0x0f, 0xd0, 0x1f, 0x70, 0x08, 0xd0, 0x1f, 
  0x80, 0xe5, 0x71, 0x0f, 0xd0, 0x12, 0x70, 0x08, 0xd0, 0x12, 0x00, 0xee, 0x80, 0x20, 0x81, 0x30, 
  0x6e, 0x00, 0x66, 0x00, 0xa4, 0xff, 0xf6, 0x1e, 0xf1, 0x55, 0xa3, 0x44, 0xd0, 0x11, 0x80, 0xc5, 
  0x7e, 0x01, 0x76, 0x02, 0x3e, 0x03, 0x12, 0x44, 0x66, 0x00, 0x22, 0xee, 0xa3, 0x44, 0xd7, 0x81, 
  0x6a, 0x03, 0x44, 0x10, 0x12, 0x6c, 0x6e, 0x06, 0xee, 0xa1, 0x64, 0x00, 0x44, 0x18, 0x12, 0x76, 
  0x6e, 0x08, 0xee, 0xa1, 0x64, 0x08, 0x44, 0x00, 0x12, 0x80, 0x6e, 0x04, 0xee, 0xa1, 0x64, 0x10, 
  0x44, 0x08, 0x12, 0x8a, 0x6e, 0x02, 0xee, 0xa1, 0x64, 0x18, 0x80, 0x40, 0xb2, 0x8e, 0x42, 0x3f, 
  0x13, 0x08, 0x72, 0x01, 0x12, 0xac, 0x43, 0x1f, 0x13, 0x08, 0x73, 0x01, 0x12, 0xac, 0x42, 0x00, 
  0x13, 0x08, 0x82, 0xc5, 0x12, 0xac, 0x43, 0x00, 0x13, 0x08, 0x83, 0xc5, 0xa3, 0x44, 0xd7, 0x81, 
  0x69, 0x00, 0x52, 0x70, 0x12, 0xd2, 0x53, 0x80, 0x12, 0xd2, 0x22, 0xf6, 0x75, 0x01, 0x69, 0x01, 
  0x6e, 0x0a, 0xfe, 0x18, 0x22, 0xee, 0x45, 0x0d, 0x12, 0xd0, 0x45, 0x17, 0x12, 0xd0, 0x12, 0xd2, 
  0x8a, 0xc5, 0x86, 0xd5, 0xa4, 0xff, 0xf6, 0x1e, 0x80, 0x20, 0x81, 0x30, 0xf1, 0x55, 0x22, 0xf6, 
  0xd2, 0x31, 0x4f, 0x01, 0x13, 0x08, 0xd7, 0x81, 0xfa, 0x15, 0x23, 0x36, 0x12, 0x62, 0xc7, 0x1f, 
  0x77, 0x10, 0xc8, 0x1f, 0x00, 0xee, 0x8e, 0x50, 0x8e, 0xe4, 0x8e, 0x64, 0xa4, 0xff, 0xfe, 0x1e, 
  0xf1, 0x65, 0xa3, 0x44, 0xd0, 0x11, 0x00, 0xee, 0x6e, 0x1e, 0xfe, 0x18, 0x6e, 0x3c, 0xfe, 0x15, 
  0x23, 0x36, 0x00, 0xe0, 0x6e, 0x03, 0x85, 0xe5, 0xa5, 0x00, 0xf5, 0x33, 0xf2, 0x65, 0x63, 0x18, 
  0x64, 0x0d, 0xf0, 0x29, 0xd3, 0x45, 0x73, 0x05, 0xf1, 0x29, 0xd3, 0x45, 0x73, 0x05, 0xf2, 0x29, 
  0xd3, 0x45, 0x6e, 0x0f, 0x13, 0x3e, 0xfe, 0x07, 0x3e, 0x00, 0x13, 0x36, 0x00, 0xee, 0xee, 0x9e, 
  0x13, 0x3e, 0x12, 0x04, 0x80, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
  0xff, 0xff, 0xff, 0xff
};

// array size is 164
const byte chip8Picture[] PROGMEM  = {
  0x00, 0xe0, 0xa2, 0x48, 0x60, 0x00, 0x61, 0x1e, 0x62, 0x00, 0xd2, 0x02, 0xd2, 0x12, 0x72, 0x08, 
  0x32, 0x40, 0x12, 0x0a, 0x60, 0x00, 0x61, 0x3e, 0x62, 0x02, 0xa2, 0x4a, 0xd0, 0x2e, 0xd1, 0x2e, 
  0x72, 0x0e, 0xd0, 0x2e, 0xd1, 0x2e, 0xa2, 0x58, 0x60, 0x0b, 0x61, 0x08, 0xd0, 0x1f, 0x70, 0x0a, 
  0xa2, 0x67, 0xd0, 0x1f, 0x70, 0x0a, 0xa2, 0x76, 0xd0, 0x1f, 0x70, 0x03, 0xa2, 0x85, 0xd0, 0x1f, 
  0x70, 0x0a, 0xa2, 0x94, 0xd0, 0x1f, 0x12, 0x46, 0xff, 0xff, 0xc0, 0xc0, 0xc0, 0xc0, 0xc0, 0xc0, 
  0xc0, 0xc0, 0xc0, 0xc0, 0xc0, 0xc0, 0xc0, 0xc0, 0xff, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 
  0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0xff, 0x81, 0x81, 0x81, 0x81, 0x81, 0x81, 0x81, 0xff, 0x81, 
  0x81, 0x81, 0x81, 0x81, 0x81, 0x81, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 
  0x80, 0x80, 0x80, 0x80, 0x80, 0xff, 0x81, 0x81, 0x81, 0x81, 0x81, 0x81, 0xff, 0x80, 0x80, 0x80, 
  0x80, 0x80, 0x80, 0x80, 0xff, 0x81, 0x81, 0x81, 0x81, 0x81, 0x81, 0xff, 0x81, 0x81, 0x81, 0x81, 
  0x81, 0x81, 0xff, 0xff
};

// array size is 288
const byte submarine[] PROGMEM  = {
  0xa2, 0xcd, 0x69, 0x38, 0x6a, 0x1e, 0xd9, 0xa2, 0xa2, 0xd0, 0x6b, 0x00, 0x6c, 0x1a, 0xdb, 0xc2, 
  0xa2, 0xd4, 0x64, 0x3c, 0x66, 0x06, 0xd4, 0x63, 0x67, 0x00, 0x68, 0x19, 0x22, 0xa2, 0x22, 0xac, 
  0x48, 0x00, 0x12, 0xd8, 0x65, 0x09, 0xa2, 0xd7, 0x63, 0x00, 0x6d, 0x05, 0xed, 0xa1, 0x63, 0x01, 
  0x8e, 0x40, 0xed, 0xa1, 0xde, 0x51, 0x12, 0x3c, 0xed, 0xa1, 0x22, 0xd8, 0xa2, 0xd4, 0xd4, 0x63, 
  0x12, 0x42, 0x74, 0xff, 0xd4, 0x63, 0xa2, 0xd0, 0xdb, 0xc2, 0xcd, 0x04, 0x8b, 0xd4, 0xdb, 0xc2, 
  0x3f, 0x00, 0x12, 0x92, 0xa2, 0xcd, 0xd9, 0xa2, 0xcd, 0x07, 0x4d, 0x00, 0x79, 0x03, 0x79, 0xfd, 
  0xd9, 0xa2, 0x3f, 0x00, 0x12, 0x8c, 0x43, 0x00, 0x12, 0x2a, 0xa2, 0xd7, 0xde, 0x51, 0x45, 0x1f, 
  0x12, 0x86, 0x75, 0x02, 0xf3, 0x18, 0xde, 0x51, 0x3f, 0x01, 0x12, 0x3c, 0x6d, 0x1f, 0x8d, 0x52, 
  0x4d, 0x1f, 0x12, 0x8c, 0x12, 0x92, 0x22, 0xac, 0x78, 0xff, 0x12, 0x1e, 0x22, 0xa2, 0x77, 0x05, 
  0x12, 0x96, 0x22, 0xa2, 0x77, 0x0a, 0x22, 0xa2, 0x6d, 0x03, 0xfd, 0x18, 0xa2, 0xd7, 0xde, 0x51, 
  0x12, 0x86, 0xa2, 0xf8, 0xf7, 0x33, 0x63, 0x00, 0x22, 0xb6, 0x00, 0xee, 0xa2, 0xf8, 0xf8, 0x33, 
  0x63, 0x32, 0x22, 0xb6, 0x00, 0xee, 0x6d, 0x00, 0xf2, 0x65, 0xf0, 0x29, 0xd3, 0xd5, 0x73, 0x05, 
  0xf1, 0x29, 0xd3, 0xd5, 0x73, 0x05, 0xf2, 0x29, 0xd3, 0xd5, 0x00, 0xee, 0x01, 0x08, 0x7f, 0x7c, 
  0x08, 0x3e, 0x60, 0x08, 0x18, 0x3c, 0xff, 0x08, 0xa3, 0x00, 0x63, 0x11, 0x6d, 0x0b, 0xd3, 0xd5, 
  0xa3, 0x05, 0x63, 0x19, 0xd3, 0xd5, 0xa3, 0x0a, 0x63, 0x23, 0xd3, 0xd5, 0xa3, 0x0f, 0x63, 0x2b, 
  0xd3, 0xd5, 0x63, 0x00, 0x12, 0xf4, 0x6d, 0x0b, 0x00, 0x01, 0x04, 0x00, 0x00, 0xee, 0x00, 0x01, 
  0xee, 0x8a, 0x8a, 0xaa, 0xee, 0xef, 0xa5, 0xa5, 0xa5, 0xef, 0x7a, 0x2a, 0x3b, 0x29, 0x79, 0xba, 
  0xa2, 0xb2, 0x20, 0x3a, 0x34, 0x3a, 0x3c, 0xd6, 0x54, 0x1c, 0x0c, 0x40, 0x9e, 0x25, 0x68, 0x0c
};

// array size is 382
const byte tron[] PROGMEM  = {
  0x00, 0xe0, 0xa3, 0x4c, 0x63, 0x12, 0x64, 0x0b, 0xd3, 0x49, 0x73, 0x08, 0xa3, 0x55, 0xd3, 0x49, 
  0x73, 0x08, 0xa3, 0x5e, 0xd3, 0x49, 0x73, 0x08, 0xa3, 0x67, 0xd3, 0x49, 0x63, 0x00, 0x64, 0x00, 
  0x60, 0x0f, 0xe0, 0xa1, 0x12, 0x2e, 0x60, 0x0b, 0xe0, 0xa1, 0x12, 0x34, 0x12, 0x20, 0x65, 0x01, 
  0x00, 0xe0, 0x12, 0x60, 0x65, 0x02, 0x00, 0xe0, 0x60, 0x00, 0x61, 0x00, 0x62, 0x1f, 0xa3, 0x4c, 
  0xd0, 0x11, 0xd0, 0x21, 0x70, 0x08, 0x40, 0x40, 0x12, 0x4c, 0x12, 0x40, 0x60, 0x01, 0x61, 0x00, 
  0x62, 0x3f, 0xa3, 0x70, 0xd1, 0x0a, 0xd2, 0x0a, 0x70, 0x0a, 0x40, 0x1f, 0x12, 0x60, 0x12, 0x54, 
  0xa3, 0x70, 0x6c, 0x20, 0x6b, 0x0f, 0x6a, 0x1f, 0x6d, 0x0f, 0x66, 0xff, 0x67, 0x00, 0x68, 0x01, 
  0x69, 0x00, 0xda, 0xb1, 0xdc, 0xd1, 0x60, 0x00, 0xe0, 0x9e, 0x12, 0x78, 0x60, 0x0a, 0xf0, 0x18, 
  0x60, 0x01, 0xe0, 0xa1, 0x22, 0xfc, 0x70, 0x03, 0xe0, 0xa1, 0x23, 0x06, 0x70, 0x03, 0xe0, 0xa1, 
  0x23, 0x10, 0x70, 0x03, 0xe0, 0xa1, 0x23, 0x1a, 0x60, 0x03, 0xe0, 0xa1, 0x23, 0x24, 0x70, 0x09, 
  0xe0, 0xa1, 0x23, 0x2e, 0x70, 0xfd, 0xe0, 0xa1, 0x23, 0x38, 0x70, 0x05, 0xe0, 0xa1, 0x23, 0x42, 
  0x8a, 0x64, 0x8c, 0x84, 0x8b, 0x74, 0x8d, 0x94, 0xda, 0xb1, 0x4f, 0x01, 0x12, 0xd0, 0xdc, 0xd1, 
  0x4f, 0x01, 0x12, 0xda, 0x60, 0x02, 0xf0, 0x15, 0xf0, 0x07, 0x30, 0x00, 0x12, 0xc8, 0x12, 0x80, 
  0x00, 0xe0, 0x74, 0x01, 0x44, 0x0a, 0x64, 0x00, 0x12, 0xe2, 0x00, 0xe0, 0x73, 0x01, 0x43, 0x0a, 
  0x63, 0x00, 0x60, 0x0a, 0xf0, 0x18, 0xf3, 0x29, 0x60, 0x19, 0x61, 0x0d, 0xd0, 0x15, 0xa3, 0x7a, 
  0x70, 0x06, 0xd0, 0x14, 0xf4, 0x29, 0x70, 0x05, 0xd0, 0x15, 0x12, 0x20, 0x47, 0x01, 0x00, 0xee, 
  0x66, 0x00, 0x67, 0xff, 0x00, 0xee, 0x47, 0xff, 0x00, 0xee, 0x66, 0x00, 0x67, 0x01, 0x00, 0xee, 
  0x49, 0x01, 0x00, 0xee, 0x68, 0x00, 0x69, 0xff, 0x00, 0xee, 0x49, 0xff, 0x00, 0xee, 0x68, 0x00, 
  0x69, 0x01, 0x00, 0xee, 0x46, 0x01, 0x00, 0xee, 0x66, 0xff, 0x67, 0x00, 0x00, 0xee, 0x46, 0xff, 
  0x00, 0xee, 0x66, 0x01, 0x67, 0x00, 0x00, 0xee, 0x48, 0x01, 0x00, 0xee, 0x68, 0xff, 0x69, 0x00, 
  0x00, 0xee, 0x48, 0xff, 0x00, 0xee, 0x68, 0x01, 0x69, 0x00, 0x00, 0xee, 0xff, 0x80, 0xbe, 0x88, 
  0x88, 0x88, 0x88, 0x80, 0xff, 0xff, 0x00, 0xfb, 0x8a, 0xfa, 0x92, 0x8b, 0x00, 0xff, 0xff, 0x00, 
  0xe8, 0x2c, 0x2a, 0x29, 0xe8, 0x00, 0xff, 0xe0, 0x20, 0xa0, 0xa0, 0xa0, 0xa0, 0xa0, 0x20, 0xe0, 
  0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x00, 0x40, 0x00, 0x40
};

// array size is 180
const byte missile[] PROGMEM  = {
  0x12, 0x19, 0x4d, 0x49, 0x53, 0x53, 0x49, 0x4c, 0x45, 0x20, 0x62, 0x79, 0x20, 0x44, 0x61, 0x76, 
  0x69, 0x64, 0x20, 0x57, 0x49, 0x4e, 0x54, 0x45, 0x52, 0x6c, 0x0c, 0x60, 0x00, 0x61, 0x00, 0x65, 
  0x08, 0x66, 0x0a, 0x67, 0x00, 0x6e, 0x01, 0xa2, 0xad, 0xd0, 0x14, 0x70, 0x08, 0x30, 0x40, 0x12, 
  0x29, 0x60, 0x00, 0x61, 0x1c, 0xa2, 0xb0, 0xd0, 0x14, 0xa2, 0xb0, 0xd0, 0x14, 0x3e, 0x01, 0x12, 
  0x49, 0x70, 0x04, 0x40, 0x38, 0x6e, 0x00, 0x12, 0x4f, 0x70, 0xfc, 0x40, 0x00, 0x6e, 0x01, 0xd0, 
  0x14, 0xfc, 0x15, 0xfb, 0x07, 0x3b, 0x00, 0x12, 0x53, 0x62, 0x08, 0xe2, 0x9e, 0x12, 0x95, 0x3c, 
  0x00, 0x7c, 0xfe, 0x63, 0x1b, 0x82, 0x00, 0xa2, 0xb0, 0xd2, 0x31, 0x64, 0x00, 0xd2, 0x31, 0x73, 
  0xff, 0xd2, 0x31, 0x3f, 0x00, 0x64, 0x01, 0x33, 0x03, 0x12, 0x6d, 0xd2, 0x31, 0x34, 0x01, 0x12, 
  0x91, 0x77, 0x05, 0x75, 0xff, 0x82, 0x00, 0x63, 0x00, 0xa2, 0xad, 0xd2, 0x34, 0x45, 0x00, 0x12, 
  0x97, 0x76, 0xff, 0x36, 0x00, 0x12, 0x39, 0xa2, 0xb4, 0xf7, 0x33, 0xf2, 0x65, 0x63, 0x1b, 0x64, 
  0x0d, 0xf1, 0x29, 0xd3, 0x45, 0x73, 0x05, 0xf2, 0x29, 0xd3, 0x45, 0x12, 0xab, 0x10, 0x38, 0x38, 
  0x10, 0x38, 0x7c, 0xfe
};

// array size is 286
const byte brickBrixHack[] PROGMEM  = {
  0x6e, 0x05, 0x65, 0x00, 0x6b, 0x06, 0x6a, 0x00, 0xa3, 0x0c, 0xda, 0xb1, 0x7a, 0x04, 0x3a, 0x40, 
  0x12, 0x08, 0x7b, 0x01, 0x3b, 0x12, 0x12, 0x06, 0x6c, 0x20, 0x6d, 0x1f, 0xa3, 0x10, 0xdc, 0xd1, 
  0x22, 0xf6, 0x60, 0x00, 0x61, 0x00, 0xa3, 0x12, 0xd0, 0x11, 0x70, 0x08, 0xa3, 0x0e, 0xd0, 0x11, 
  0x60, 0x40, 0xf0, 0x15, 0xf0, 0x07, 0x30, 0x00, 0x12, 0x34, 0xc6, 0x0f, 0x67, 0x1e, 0x68, 0x01, 
  0x69, 0xff, 0xa3, 0x0e, 0xd6, 0x71, 0xa3, 0x10, 0xdc, 0xd1, 0x60, 0x04, 0xe0, 0xa1, 0x7c, 0xfe, 
  0x60, 0x06, 0xe0, 0xa1, 0x7c, 0x02, 0x60, 0x3f, 0x8c, 0x02, 0xdc, 0xd1, 0xa3, 0x0e, 0xd6, 0x71, 
  0x86, 0x84, 0x87, 0x94, 0x60, 0x3f, 0x86, 0x02, 0x61, 0x1f, 0x87, 0x12, 0x47, 0x1f, 0x12, 0xac, 
  0x46, 0x00, 0x68, 0x01, 0x46, 0x3f, 0x68, 0xff, 0x47, 0x00, 0x69, 0x01, 0xd6, 0x71, 0x3f, 0x01, 
  0x12, 0xaa, 0x47, 0x1f, 0x12, 0xaa, 0x60, 0x05, 0x80, 0x75, 0x3f, 0x00, 0x12, 0xaa, 0x60, 0x01, 
  0xf0, 0x18, 0x80, 0x60, 0x61, 0xfc, 0x80, 0x12, 0xa3, 0x0c, 0xd0, 0x71, 0x60, 0xfe, 0x89, 0x03, 
  0x22, 0xf6, 0x75, 0x01, 0x22, 0xf6, 0x45, 0xc0, 0x13, 0x18, 0x12, 0x46, 0x69, 0xff, 0x80, 0x60, 
  0x80, 0xc5, 0x3f, 0x01, 0x12, 0xca, 0x61, 0x02, 0x80, 0x15, 0x3f, 0x01, 0x12, 0xe0, 0x80, 0x15, 
  0x3f, 0x01, 0x12, 0xee, 0x80, 0x15, 0x3f, 0x01, 0x12, 0xe8, 0x60, 0x20, 0xf0, 0x18, 0xa3, 0x0e, 
  0x7e, 0xff, 0x80, 0xe0, 0x80, 0x04, 0x61, 0x00, 0xd0, 0x11, 0x3e, 0x00, 0x12, 0x30, 0x12, 0xde, 
  0x78, 0xff, 0x48, 0xfe, 0x68, 0xff, 0x12, 0xee, 0x78, 0x01, 0x48, 0x02, 0x68, 0x01, 0x60, 0x04, 
  0xf0, 0x18, 0x69, 0xff, 0x12, 0x70, 0xa3, 0x14, 0xf5, 0x33, 0xf2, 0x65, 0xf1, 0x29, 0x63, 0x37, 
  0x64, 0x00, 0xd3, 0x45, 0x73, 0x05, 0xf2, 0x29, 0xd3, 0x45, 0x00, 0xee, 0xf0, 0x00, 0x80, 0x00, 
  0xfc, 0x00, 0xaa, 0x00, 0x00, 0x00, 0x00, 0x00, 0x6e, 0x05, 0x00, 0xe0, 0x12, 0x04
};

// array size is 256
const byte life[] PROGMEM  = {
  0x12, 0x84, 0x70, 0x04, 0x40, 0x40, 0x71, 0x04, 0x40, 0x40, 0x60, 0x00, 0x31, 0x20, 0x12, 0xba, 
  0xa2, 0x38, 0xfe, 0x1e, 0x61, 0xfc, 0xf1, 0x55, 0x6e, 0x00, 0xa2, 0x38, 0xfe, 0x1e, 0xf1, 0x65, 
  0xa2, 0x80, 0xd0, 0x13, 0x7e, 0x02, 0x31, 0xfc, 0x12, 0x1a, 0xd0, 0x13, 0x12, 0xb2, 0xa2, 0x38, 
  0xfe, 0x1e, 0xf1, 0x55, 0x7e, 0x02, 0x12, 0x02, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0xe0, 0xa0, 0xe0, 0x80, 0xf1, 0x0a, 0x41, 0x0f, 0x12, 0xb0, 0x6a, 0x08, 0x8a, 0x12, 0x4a, 0x00, 
  0x12, 0x96, 0xfa, 0x18, 0x12, 0x84, 0x81, 0x14, 0x81, 0x14, 0xf0, 0x0a, 0x80, 0x04, 0x80, 0x04, 
  0xa2, 0x80, 0xd0, 0x13, 0x12, 0x84, 0x6f, 0x00, 0xd0, 0x11, 0x8c, 0xf4, 0xd0, 0x11, 0x00, 0xee, 
  0xf2, 0x0a, 0x60, 0x00, 0x61, 0x00, 0x6e, 0x00, 0x72, 0xff, 0x42, 0x00, 0x12, 0x84, 0x6c, 0x00, 
  0xa2, 0x83, 0xd0, 0x11, 0x84, 0xf0, 0xd0, 0x11, 0x70, 0xfc, 0x22, 0xa6, 0x71, 0x04, 0x22, 0xa6, 
  0x70, 0x04, 0x22, 0xa6, 0x70, 0x04, 0x22, 0xa6, 0x71, 0xfc, 0x22, 0xa6, 0x71, 0xfc, 0x22, 0xa6, 
  0x70, 0xfc, 0x22, 0xa6, 0x70, 0xfc, 0x22, 0xa6, 0x70, 0x04, 0x71, 0x04, 0x4c, 0x02, 0x12, 0x02, 
  0x4c, 0x03, 0x12, 0xfa, 0x34, 0x01, 0x12, 0x02, 0x12, 0x2e, 0x34, 0x01, 0x12, 0x2e, 0x12, 0x02
};

// array size is 264
const byte pong[] PROGMEM  = {
  0x22, 0xf6, 0x6b, 0x0c, 0x6c, 0x3f, 0x6d, 0x0c, 0xa2, 0xea, 0xda, 0xb6, 0xdc, 0xd6, 0x6e, 0x00, 
  0x22, 0xd4, 0x66, 0x03, 0x68, 0x02, 0x60, 0x60, 0xf0, 0x15, 0xf0, 0x07, 0x30, 0x00, 0x12, 0x1a, 
  0xc7, 0x17, 0x77, 0x08, 0x69, 0xff, 0xa2, 0xf0, 0xd6, 0x71, 0xa2, 0xea, 0xda, 0xb6, 0xdc, 0xd6, 
  0x60, 0x01, 0xe0, 0xa1, 0x7b, 0xfe, 0x60, 0x04, 0xe0, 0xa1, 0x7b, 0x02, 0x60, 0x1f, 0x8b, 0x02, 
  0xda, 0xb6, 0x60, 0x0c, 0xe0, 0xa1, 0x7d, 0xfe, 0x60, 0x0d, 0xe0, 0xa1, 0x7d, 0x02, 0x60, 0x1f, 
  0x8d, 0x02, 0xdc, 0xd6, 0xa2, 0xf0, 0xd6, 0x71, 0x86, 0x84, 0x87, 0x94, 0x60, 0x3f, 0x86, 0x02, 
  0x61, 0x1f, 0x87, 0x12, 0x46, 0x00, 0x12, 0x78, 0x46, 0x3f, 0x12, 0x82, 0x47, 0x1f, 0x69, 0xff, 
  0x47, 0x00, 0x69, 0x01, 0xd6, 0x71, 0x12, 0x2a, 0x68, 0x02, 0x63, 0x01, 0x80, 0x70, 0x80, 0xb5, 
  0x12, 0x8a, 0x68, 0xfe, 0x63, 0x0a, 0x80, 0x70, 0x80, 0xd5, 0x3f, 0x01, 0x12, 0xa2, 0x61, 0x02, 
  0x80, 0x15, 0x3f, 0x01, 0x12, 0xba, 0x80, 0x15, 0x3f, 0x01, 0x12, 0xc8, 0x80, 0x15, 0x3f, 0x01, 
  0x12, 0xc2, 0x60, 0x20, 0xf0, 0x18, 0x22, 0xd4, 0x8e, 0x34, 0x22, 0xd4, 0x66, 0x3e, 0x33, 0x01, 
  0x66, 0x03, 0x68, 0xfe, 0x33, 0x01, 0x68, 0x02, 0x12, 0x16, 0x79, 0xff, 0x49, 0xfe, 0x69, 0xff, 
  0x12, 0xc8, 0x79, 0x01, 0x49, 0x02, 0x69, 0x01, 0x60, 0x04, 0xf0, 0x18, 0x76, 0x01, 0x46, 0x40, 
  0x76, 0xfe, 0x12, 0x6c, 0xa2, 0xf2, 0xfe, 0x33, 0xf2, 0x65, 0xf1, 0x29, 0x64, 0x14, 0x65, 0x00, 
  0xd4, 0x55, 0x74, 0x15, 0xf2, 0x29, 0xd4, 0x55, 0x00, 0xee, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 
  0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x6b, 0x20, 0x6c, 0x00, 0xa2, 0xea, 0xdb, 0xc1, 0x7c, 0x01, 
  0x3c, 0x20, 0x12, 0xfc, 0x6a, 0x00, 0x00, 0xee
};

// array size is 38
const byte maze[] PROGMEM  = {
  0x60, 0x00, 0x61, 0x00, 0xa2, 0x22, 0xc2, 0x01, 0x32, 0x01, 0xa2, 0x1e, 0xd0, 0x14, 0x70, 0x04, 
  0x30, 0x40, 0x12, 0x04, 0x60, 0x00, 0x71, 0x04, 0x31, 0x20, 0x12, 0x04, 0x12, 0x1c, 0x80, 0x40, 
  0x20, 0x10, 0x20, 0x40, 0x80, 0x10
};

// array size is 114
const byte keypadTest[] PROGMEM  = {
  0x12, 0x4e, 0x08, 0x19, 0x01, 0x01, 0x08, 0x01, 0x0f, 0x01, 0x01, 0x09, 0x08, 0x09, 0x0f, 0x09, 
  0x01, 0x11, 0x08, 0x11, 0x0f, 0x11, 0x01, 0x19, 0x0f, 0x19, 0x16, 0x01, 0x16, 0x09, 0x16, 0x11, 
  0x16, 0x19, 0xfc, 0xfc, 0xfc, 0xfc, 0xfc, 0xfc, 0xfc, 0x00, 0xa2, 0x02, 0x82, 0x0e, 0xf2, 0x1e, 
  0x82, 0x06, 0xf1, 0x65, 0x00, 0xee, 0xa2, 0x02, 0x82, 0x0e, 0xf2, 0x1e, 0x82, 0x06, 0xf1, 0x55, 
  0x00, 0xee, 0x6f, 0x10, 0xff, 0x15, 0xff, 0x07, 0x3f, 0x00, 0x12, 0x46, 0x00, 0xee, 0x00, 0xe0, 
  0x62, 0x00, 0x22, 0x2a, 0xf2, 0x29, 0xd0, 0x15, 0x70, 0xff, 0x71, 0xff, 0x22, 0x36, 0x72, 0x01, 
  0x32, 0x10, 0x12, 0x52, 0xf2, 0x0a, 0x22, 0x2a, 0xa2, 0x22, 0xd0, 0x17, 0x22, 0x42, 0xd0, 0x17, 
  0x12, 0x64
};


// array size is 494 TOO BIG :(
const byte tetris[] PROGMEM  = {
  0xa2, 0xb4, 0x23, 0xe6, 0x22, 0xb6, 0x70, 0x01, 0xd0, 0x11, 0x30, 0x25, 0x12, 0x06, 0x71, 0xff, 
  0xd0, 0x11, 0x60, 0x1a, 0xd0, 0x11, 0x60, 0x25, 0x31, 0x00, 0x12, 0x0e, 0xc4, 0x70, 0x44, 0x70, 
  0x12, 0x1c, 0xc3, 0x03, 0x60, 0x1e, 0x61, 0x03, 0x22, 0x5c, 0xf5, 0x15, 0xd0, 0x14, 0x3f, 0x01, 
  0x12, 0x3c, 0xd0, 0x14, 0x71, 0xff, 0xd0, 0x14, 0x23, 0x40, 0x12, 0x1c, 0xe7, 0xa1, 0x22, 0x72, 
  0xe8, 0xa1, 0x22, 0x84, 0xe9, 0xa1, 0x22, 0x96, 0xe2, 0x9e, 0x12, 0x50, 0x66, 0x00, 0xf6, 0x15, 
  0xf6, 0x07, 0x36, 0x00, 0x12, 0x3c, 0xd0, 0x14, 0x71, 0x01, 0x12, 0x2a, 0xa2, 0xc4, 0xf4, 0x1e, 
  0x66, 0x00, 0x43, 0x01, 0x66, 0x04, 0x43, 0x02, 0x66, 0x08, 0x43, 0x03, 0x66, 0x0c, 0xf6, 0x1e, 
  0x00, 0xee, 0xd0, 0x14, 0x70, 0xff, 0x23, 0x34, 0x3f, 0x01, 0x00, 0xee, 0xd0, 0x14, 0x70, 0x01, 
  0x23, 0x34, 0x00, 0xee, 0xd0, 0x14, 0x70, 0x01, 0x23, 0x34, 0x3f, 0x01, 0x00, 0xee, 0xd0, 0x14, 
  0x70, 0xff, 0x23, 0x34, 0x00, 0xee, 0xd0, 0x14, 0x73, 0x01, 0x43, 0x04, 0x63, 0x00, 0x22, 0x5c, 
  0x23, 0x34, 0x3f, 0x01, 0x00, 0xee, 0xd0, 0x14, 0x73, 0xff, 0x43, 0xff, 0x63, 0x03, 0x22, 0x5c, 
  0x23, 0x34, 0x00, 0xee, 0x80, 0x00, 0x67, 0x05, 0x68, 0x06, 0x69, 0x04, 0x61, 0x1f, 0x65, 0x10, 
  0x62, 0x07, 0x00, 0xee, 0x40, 0xe0, 0x00, 0x00, 0x40, 0xc0, 0x40, 0x00, 0x00, 0xe0, 0x40, 0x00, 
  0x40, 0x60, 0x40, 0x00, 0x40, 0x40, 0x60, 0x00, 0x20, 0xe0, 0x00, 0x00, 0xc0, 0x40, 0x40, 0x00, 
  0x00, 0xe0, 0x80, 0x00, 0x40, 0x40, 0xc0, 0x00, 0x00, 0xe0, 0x20, 0x00, 0x60, 0x40, 0x40, 0x00, 
  0x80, 0xe0, 0x00, 0x00, 0x40, 0xc0, 0x80, 0x00, 0xc0, 0x60, 0x00, 0x00, 0x40, 0xc0, 0x80, 0x00, 
  0xc0, 0x60, 0x00, 0x00, 0x80, 0xc0, 0x40, 0x00, 0x00, 0x60, 0xc0, 0x00, 0x80, 0xc0, 0x40, 0x00, 
  0x00, 0x60, 0xc0, 0x00, 0xc0, 0xc0, 0x00, 0x00, 0xc0, 0xc0, 0x00, 0x00, 0xc0, 0xc0, 0x00, 0x00, 
  0xc0, 0xc0, 0x00, 0x00, 0x40, 0x40, 0x40, 0x40, 0x00, 0xf0, 0x00, 0x00, 0x40, 0x40, 0x40, 0x40, 
  0x00, 0xf0, 0x00, 0x00, 0xd0, 0x14, 0x66, 0x35, 0x76, 0xff, 0x36, 0x00, 0x13, 0x38, 0x00, 0xee, 
  0xa2, 0xb4, 0x8c, 0x10, 0x3c, 0x1e, 0x7c, 0x01, 0x3c, 0x1e, 0x7c, 0x01, 0x3c, 0x1e, 0x7c, 0x01, 
  0x23, 0x5e, 0x4b, 0x0a, 0x23, 0x72, 0x91, 0xc0, 0x00, 0xee, 0x71, 0x01, 0x13, 0x50, 0x60, 0x1b, 
  0x6b, 0x00, 0xd0, 0x11, 0x3f, 0x00, 0x7b, 0x01, 0xd0, 0x11, 0x70, 0x01, 0x30, 0x25, 0x13, 0x62, 
  0x00, 0xee, 0x60, 0x1b, 0xd0, 0x11, 0x70, 0x01, 0x30, 0x25, 0x13, 0x74, 0x8e, 0x10, 0x8d, 0xe0, 
  0x7e, 0xff, 0x60, 0x1b, 0x6b, 0x00, 0xd0, 0xe1, 0x3f, 0x00, 0x13, 0x90, 0xd0, 0xe1, 0x13, 0x94, 
  0xd0, 0xd1, 0x7b, 0x01, 0x70, 0x01, 0x30, 0x25, 0x13, 0x86, 0x4b, 0x00, 0x13, 0xa6, 0x7d, 0xff, 
  0x7e, 0xff, 0x3d, 0x01, 0x13, 0x82, 0x23, 0xc0, 0x3f, 0x01, 0x23, 0xc0, 0x7a, 0x01, 0x23, 0xc0, 
  0x80, 0xa0, 0x6d, 0x07, 0x80, 0xd2, 0x40, 0x04, 0x75, 0xfe, 0x45, 0x02, 0x65, 0x04, 0x00, 0xee, 
  0xa7, 0x00, 0xf2, 0x55, 0xa8, 0x04, 0xfa, 0x33, 0xf2, 0x65, 0xf0, 0x29, 0x6d, 0x32, 0x6e, 0x00, 
  0xdd, 0xe5, 0x7d, 0x05, 0xf1, 0x29, 0xdd, 0xe5, 0x7d, 0x05, 0xf2, 0x29, 0xdd, 0xe5, 0xa7, 0x00, 
  0xf2, 0x65, 0xa2, 0xb4, 0x00, 0xee, 0x6a, 0x00, 0x60, 0x19, 0x00, 0xee, 0x37, 0x23
};
