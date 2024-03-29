/*
//=============================================================================
//
// Purpose: Bluetooth device interface for ESP32
//
// $NoKeywords: $
//=============================================================================
*/

/*
// bdi.h
*/

/*
=================
last modified: 2024/2/25
=================
*/


#ifndef __BDI__
#define __BDI__

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdint.h>
#include "mockdata_t.h"

typedef unsigned char byte;

typedef struct
{
    int baud_rate;
} bdi_port_t;

/*
ESP 32 start advertising
*/

/* The order to call these functions:  1.bdi_port_init 2.bdi_begin_advertising 3.bdi_send_packet*/
void bdi_port_init(bdi_port_t state_init);
void bdi_port_init_default(void);
void bdi_begin_advertising(void);
/*void bdi_write_bytes(const byte *data, int len);*/
/*void bdi_write_byte(byte data);*/
void bdi_send_packet(mockdata_t *data);

/*
=================
bdi_read_bytes

Not implemented
=================
*/

/* void bdi_read_bytes(byte *data, int len); */

/*
=================
bdi_shutdown

Not implemented
=================
*/

/* int bdi_shutdown(); */

#ifdef __cplusplus
}
#endif


#endif  /*__BDI__*/
