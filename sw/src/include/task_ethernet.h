#ifndef TASK_ETHERNET_H_
#define TASK_ETHERNET_H_

#include "mac_address.h"

#include <cstdbool>

bool create_task_ethernet(const Eui48MacAddress& mac_addr);

#endif  // TASK_ETHERNET_H_
