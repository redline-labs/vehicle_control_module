#ifndef BOARD_H_
#define BOARD_H_

// Base Boards.
#define SAMV71_XPLAINED_ULTRA      0  // SAMV71 Xplained Ultra demo board.

#if BOARD == SAMV71_XPLAINED_ULTRA
#  include "samv71_xplained_ultra/samv71_xplained_ultra.h"
#else
#  error No known board defined
#endif

// This function initializes the board target resources
void board_init();

#endif  // BOARD_H_
