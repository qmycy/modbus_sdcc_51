#include "stc15w404as.h"
#include "modbus.h"




typedef unsigned char BYTE;
typedef unsigned int WORD;

#define FOSC 11059200L          //????
#define BAUD 115200             //?????

#define NONE_PARITY     0       //???
#define ODD_PARITY      1       //???
#define EVEN_PARITY     2       //???
#define MARK_PARITY     3       //????
#define SPACE_PARITY    4       //????

#define PARITYBIT NONE_PARITY   //?????

#define S1_S0 0x40              //P_SW1.6
#define S1_S1 0x80              //P_SW1.7

__pdata volatile MODBUS_DEV_TYPEDEF mb_t;
volatile unsigned char mb_frame_timeout=0;
__bit busy;
unsigned char ticks=0;
void SendData(BYTE dat);
void SendString(char *s);

void main()
{
	unsigned char i;
    P0M0 = 0x00;
    P0M1 = 0x00;
    P1M0 = 0x00;
    P1M1 = 0x00;
    P2M0 = 0x00;
    P2M1 = 0x00;
    P3M0 = 0x00;
    P3M1 = 0x00;
    P4M0 = 0x00;
    P4M1 = 0x00;
    P5M0 = 0x00;
    P5M1 = 0x00;
    P6M0 = 0x00;
    P6M1 = 0x00;
    P7M0 = 0x00;
    P7M1 = 0x00;

    ACC = P_SW1;
    ACC &= ~(S1_S0 | S1_S1);    //S1_S0=0 S1_S1=0
    P_SW1 = ACC;                //(P3.0/RxD, P3.1/TxD)
    
//  ACC = P_SW1;
//  ACC &= ~(S1_S0 | S1_S1);    //S1_S0=1 S1_S1=0
//  ACC |= S1_S0;               //(P3.6/RxD_2, P3.7/TxD_2)
//  P_SW1 = ACC;  
//  
//  ACC = P_SW1;
//  ACC &= ~(S1_S0 | S1_S1);    //S1_S0=0 S1_S1=1
//  ACC |= S1_S1;               //(P1.6/RxD_3, P1.7/TxD_3)
//  P_SW1 = ACC;  

#if (PARITYBIT == NONE_PARITY)
    SCON = 0x50;                //8??????
#elif (PARITYBIT == ODD_PARITY) || (PARITYBIT == EVEN_PARITY) || (PARITYBIT == MARK_PARITY)
    SCON = 0xda;                //9??????,??????1
#elif (PARITYBIT == SPACE_PARITY)
    SCON = 0xd2;                //9??????,??????0
#endif

    T2L = (uint8_t)(65536 - (FOSC/4/BAUD));   //????????
    T2H = (uint8_t)((65536 - (FOSC/4/BAUD))>>8);
    AUXR = 0x14;                //T2?1T??, ??????2
    AUXR |= 0x01;               //?????2???1???????
    ES = 1;   
		
			AUXR &= 0x7F;		//?????12T??
	TMOD &= 0xF0;		//???????
	TL0 = 0x66;		//??????
	TH0 = 0xfc;		//??????
	TF0 = 0;		//??TF0??
	TR0 = 1;		//???0????	
	ET0=1;	
    EA = 1;
		mb_t.mb_state=MB_READY;
		for(i=0;i<16;i++)
		{
			mb_t.regs[i]=i;
		}
		for(i=0;i<16;i++)
		{
			mb_t.coils[i]=i;
		}
		while(1)
		{
			mb_poll();
		};
}

/*----------------------------
UART ??????
-----------------------------*/
void Uart() __interrupt (4)
{
    if (RI)
    {
        RI = 0;                 //??RI?
			if(mb_t.mb_state==MB_READY) {mb_t.rx_len=0;mb_t.rx[mb_t.rx_len]=SBUF;mb_t.rx_len+=1;mb_t.mb_state=MB_RECV;}
			else if(mb_t.mb_state==MB_RECV) {mb_t.rx[mb_t.rx_len]=SBUF;mb_t.rx_len+=1;}
			mb_frame_timeout=0;
    }
    if (TI)
    {
        TI = 0;                 //??TI?
        busy = 0;               //????
    }
}

/*----------------------------
??????
----------------------------*/
void SendData(BYTE dat)
{
    while (busy);               //???????????
    ACC = dat;                  //?????P (PSW.0)
    if (P)                      //??P??????
    {
#if (PARITYBIT == ODD_PARITY)
        TB8 = 0;                //??????0
#elif (PARITYBIT == EVEN_PARITY)
        TB8 = 1;                //??????1
#endif
    }
    else
    {
#if (PARITYBIT == ODD_PARITY)
        TB8 = 1;                //??????1
#elif (PARITYBIT == EVEN_PARITY)
        TB8 = 0;                //??????0
#endif
    }
    busy = 1;
    SBUF = ACC;                 //????UART?????
}


void tm0_isr() __interrupt (1)
{
	ticks++;
	switch(mb_t.mb_state)
	{
		case MB_READY:
			mb_frame_timeout=0;
			break;
		case MB_RECV:
			if(++mb_frame_timeout>3) mb_t.mb_state=MB_ANSWER;
			break;
		default:
			break;
	}
}
