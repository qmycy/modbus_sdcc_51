#ifndef _STC15W404AS_H_
#define _STC15W404AS_H_
#include<8052.h>

__sfr  __at (0x84) S4CON;
__sfr  __at (0x85) S4BUF;
__sfr  __at (0x8E) AUXR;
__sfr  __at (0x8F) AUXR2;

__sfr  __at (0x91) P1M1;
__sfr  __at (0x92) P1M0;
__sfr  __at (0x93) P0M1;
__sfr  __at (0x94) P0M0;
__sfr  __at (0x95) P2M1;
__sfr  __at (0x96) P2M0;
__sfr  __at (0x97) PCON2;
__sfr  __at (0x9A) S2CON;
__sfr  __at (0x9B) S2BUF;
__sfr  __at (0x9D) P1ASF;

__sfr  __at (0xA1) BUS_SPEED;
__sfr  __at (0xA2) P_SW1;
__sfr  __at (0xA9) SADDR;
__sfr  __at (0xAA) WKTCL_CNT;
__sfr  __at (0xAB) WKTCH_CNT;
__sfr  __at (0xAC) S3CON;
__sfr  __at (0xAD) S3BUF;
__sfr  __at (0xAF) IE2;

__sfr  __at (0xB1) P3M1;
__sfr  __at (0xB2) P3M0;
__sfr  __at (0xB3) P4M1;
__sfr  __at (0xB4) P4M0;
__sfr  __at (0xB5) IP2;
__sfr  __at (0xB6) IP2H;
__sfr  __at (0xB7) IPH;

__sfr  __at (0xB9) SADEN;
__sfr  __at (0xBA) P_SW2;

__sfr  __at (0xBC) ADC_CONTR;
__sfr  __at (0xBD) ADC_RES;
__sfr  __at (0xBE) ADC_RESL;

__sfr  __at (0xC1) WDT_CONTR;
__sfr  __at (0xC2) IAP_DATA;
__sfr  __at (0xC3) IAP_ADDRH;
__sfr  __at (0xC4) IAP_ADDRL;
__sfr  __at (0xC5) IAP_CMD;
__sfr  __at (0xC6) IAP_TRIG;
__sfr  __at (0xC7) IAP_CONTR;
__sfr  __at (0xC9) P5M1;
__sfr  __at (0xCA) P5M0;
__sfr  __at (0xCB) P6M1;
__sfr  __at (0xCC) P6M0;
__sfr  __at (0xCD) SPSTAT;
__sfr  __at (0xCE) SPCTL;
__sfr  __at (0xCF) SPDAT;

__sfr  __at (0xD1) T4T3M;
__sfr  __at (0xD2) T4H;
__sfr  __at (0xD3) T4L;
__sfr  __at (0xD4) T3H;
__sfr  __at (0xD5) T3L;
__sfr  __at (0xD6) T2H;
__sfr  __at (0xD7) T2L;

__sfr  __at (0xD9) CMOD;
__sfr  __at (0xDA) CCAPM0;
__sfr  __at (0xDB) CCAPM1;
__sfr  __at (0xDC) CCAPM2;

__sfr  __at (0xE1) P7M1;
__sfr  __at (0xE2) P7M0;

__sfr  __at (0xE9) CL;
__sfr  __at (0xEA) CCAP0L;
__sfr  __at (0xEB) CCAP1L;
__sfr  __at (0xEC) CCAP2L;

__sfr  __at (0xF1) PWMCFG;
__sfr  __at (0xF2) PCA_PWM0;
__sfr  __at (0xF3) PCA_PWM1;
__sfr  __at (0xF4) PCA_PWM2;
__sfr  __at (0xF5) PWMCR;
__sfr  __at (0xF6) PWMIF;
__sfr  __at (0xF7) PWMFDCR;

__sfr  __at (0xF9) PWMCH;
__sfr  __at (0xFA) CCAP0H;
__sfr  __at (0xFB) CCAP1H;
__sfr  __at (0xFC) CCAP2H;

#endif




