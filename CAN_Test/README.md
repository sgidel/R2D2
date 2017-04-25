# STM32 HAL CAN Example Code
- transmits DE AD BE EF FE ED every 5 seconds at id 0x123
- sending FE <b3> <b2> <b1> <b0> sets LED ON duration at id 0x125 (lsb b0)
- sending FE at id 0x125 turns led on for duration previously set
- responds with "LED ON" to either of these commands
- after timer expires "LED OFF" sent.

## Issues:
- HAL CAN Funkyness - Interrupt receive mode should be set in Receive ISR but it cant because it is not always ready and errors out.

## TODO:
- Clean up globals, most of them are unneeded.
- General formatting cleanup.
