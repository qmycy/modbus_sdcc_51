#ifndef _MODBUS_H_
#define _MODBUS_H_

#define SLAVE_ID 0x01

#define MB_READY 0
#define MB_RECV 1
#define MB_ANSWER 2
#define MB_SEND 3

#ifndef _UINT8_T
#define _UINT8_T
typedef unsigned char uint8_t;
typedef unsigned int uint16_t;
typedef int int16_t;
#endif

typedef union{
	uint8_t bytes[2];
	uint16_t value;
}MODBUS_INT_TYPEDEF;

typedef struct {
	uint8_t rx[32];
	uint8_t tx[32];
	uint8_t rx_len;
	uint8_t tx_len;
	uint8_t mb_state;
	uint16_t regs[16];
	uint8_t coils[16];
	uint16_t us1;
	uint16_t us2;
} MODBUS_DEV_TYPEDEF;



void mb_poll(void);

#endif
