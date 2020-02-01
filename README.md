# Vehicle Control Module

A communication gateway and power distribution for motorsports, serving as the main electronic hub of the vehicle.

## Goals
  - Completely open-source HW and SW.  Should be a platform that anybody can hack, extend, and make their own.
  - Common parts, readily available for Digikey, Mouser, etc.  Datasheets are available without NDA.
  - Shoot for OEM level reliability and robustness, without going full ASIL alphabet soup.

## Vision
  - Controlling a circuit should be as simple as writing some logic `(engine_temp_c > 70.0f) && (vehicle_speed_mps < 5.0f)`.
  - No need for traditional fuses, relays as something like a slow-blow fuse can be done in software.
  - Plug into the vehicle using standard ethernet to debug/reconfigure/reflash.
  - Foundation for support datalogging, telemetry, and HMI.

## Hardware
Based on the Microchip [ATSAMV71Q21](https://www.microchip.com/wwwproducts/en/ATSAMV71Q21).
* (2) CAN-FD channels via [TLE9250](https://www.infineon.com/cms/en/product/transceivers/automotive-transceiver/automotive-can-transceivers/tle9250xsj/).
* (3) 100BASE-T1 channels via [TJA1100](https://www.nxp.com/products/interfaces/ethernet-/automotive-ethernet-phy-transceivers/ieee-100base-t1-compliant-automotive-ethernet-phy-transceiver:TJA1100HN).
* (1) 100BASE-TX channel via [KSZ8061MNX](https://www.microchip.com/wwwproducts/en/KSZ8061) to support debug with a laptop.
* (18) High Side drivers via [BTS50015-1TAD](https://www.infineon.com/cms/en/product/power/smart-low-side-high-side-switches/automotive-smart-high-side-switch-profet/power-profet/bts50015-1tad/).
* (2) RS-232 serial channels to connect GPS receivers and legacy IMUs.
* (8) Digital Inputs.

## Prerequisites
### MacOS
```
brew tap osx-cross/arm
brew install arm-gcc-bin

brew install cmake
```


## Building
```
# Jump into the sw directory, create a build dir, and then jump into that.
cd sw
mkdir build
cd build

# Run CMake specifying the toolchain file.
cmake -D CMAKE_TOOLCHAIN_FILE=../cmake/arm-none-eabi.cmake ..

# Build!
make
```
