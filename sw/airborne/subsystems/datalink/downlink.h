/*
 * Copyright (C) 2003-2006  Pascal Brisset, Antoine Drouin
 *
 * This file is part of paparazzi.
 *
 * paparazzi is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2, or (at your option)
 * any later version.
 *
 * paparazzi is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with paparazzi; see the file COPYING.  If not, write to
 * the Free Software Foundation, 59 Temple Place - Suite 330,
 * Boston, MA 02111-1307, USA.
 *
 */

/** \file downlink.h
 *  \brief Common code for AP and FBW telemetry
 *
 */

#ifndef DOWNLINK_H
#define DOWNLINK_H

#include <inttypes.h>

#include "generated/modules.h"
#include "pprzlink/messages.h"

// FIXME tmp hack
#ifndef PPRZ
#define PPRZ 1
#endif
#ifndef XBEE
#define XBEE 2
#endif
#ifndef SUPERBITRF
#define SUPERBITRF 3
#endif
#ifndef W5100
#define W5100 4
#endif
#ifndef BLUEGIGA
#define BLUEGIGA 5
#endif

#if defined SITL && !USE_NPS
/** Software In The Loop simulation uses IVY bus directly as the transport layer */
#include "pprzlink/ivy_transport.h"
extern struct ivy_transport ivy_tp;

#else /** SITL */

#if DATALINK == PPRZ
#include "pprzlink/pprz_transport.h"
extern struct pprz_transport pprz_tp;
#endif

#include "pprzlink/pprzlog_transport.h"

#if DATALINK == XBEE
#include "pprzlink/xbee_transport.h"
extern struct xbee_transport xbee_tp;
#endif

//#include "subsystems/datalink/w5100.h"
#if DATALINK == BLUEGIGA
//#include "subsystems/datalink/bluegiga.h"
#endif
#if USE_SUPERBITRF
#include "subsystems/datalink/superbitrf.h"
#endif
#if USE_USB_SERIAL
#include "mcu_periph/usb_serial.h"
#endif
#ifdef USE_UDP
#include "mcu_periph/udp.h"
#endif
#include "mcu_periph/uart.h"

#endif /** !SITL */


#ifndef DefaultChannel
#define DefaultChannel DOWNLINK_TRANSPORT
#endif

#ifndef DefaultDevice
#define DefaultDevice DOWNLINK_DEVICE
#endif

// Init function
extern void downlink_init(void);

#endif /* DOWNLINK_H */
