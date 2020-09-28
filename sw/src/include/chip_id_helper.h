#ifndef CHIP_ID_HELPER_H_
#define CHIP_ID_HELPER_H_

#include "chipid.h"

#include <cstdint>

#include <array>
#include <cstdint>

// From ASF's chipid_example.c
struct chipidtype_t
{
    // Identifier
    uint32_t id;

    // Type
    const char* str;
};

// Embedded Processors support list.
constexpr uint8_t kChipIdEprocSize = 8U;
constexpr std::array<chipidtype_t, kChipIdEprocSize> kChipIdEprocMap = {{
    // identifier       description
    {0x0,               "Cortex-M7"},
    {0x1,               "ARM946ES"},
    {0x2,               "ARM7TDMI"},
    {0x3,               "Cortex-M3"},
    {0x4,               "ARM920T"},
    {0x5,               "ARM926EJS"},
    {0x6,               "Cortex-A5"},
    {0x7,               "Cortex-M4"}
}};

constexpr const char* get_chip_id_embedded_processor_type_str(uint32_t eproc_id)
{
    const char* ret = "unknown";

    for (const auto& eproc : kChipIdEprocMap)
    {
        if (eproc.id == eproc_id)
        {
            ret = eproc.str;
            break;
        }
    }

    return ret;
}

// 1st Non-Volatile Program Memories support list.
constexpr uint8_t kChipIdNvpSizeSize = 16U;
constexpr std::array<chipidtype_t, kChipIdNvpSizeSize> kChipIdNvpSize = {{
    // identifier       description
    {0x0,               "None"},
    {0x1,               "8K bytes"},
    {0x2,               "16K bytes"},
    {0x3,               "32K bytes"},
    {0x4,               "Reserved"},
    {0x5,               "64K bytes"},
    {0x6,               "Reserved"},
    {0x7,               "128K bytes"},
    {0x8,               "Reserved"},
    {0x9,               "256K bytes"},
    {0xA,               "512K bytes"},
    {0xB,               "Reserved"},
    {0xC,               "1024K bytes"},
    {0xD,               "Reserved"},
    {0xE,               "2048K bytes"},
    {0xF,               "Reserved"}
}};

constexpr const char* get_chip_id_nvm_size_str(uint32_t nvp_size)
{
    const char* ret = "unknown";

    for (const auto& nvp : kChipIdNvpSize)
    {
        if (nvp.id == nvp_size)
        {
            ret = nvp.str;
            break;
        }
    }

    return ret;
}

// 2nd Non-Volatile Program Memories support list.
constexpr uint8_t kChipIdNvpSize2Size = 16U;
constexpr std::array<chipidtype_t, kChipIdNvpSize2Size> kChipIdNvpSize2 = {{
    // identifier       description
    {0x0,               "None"},
    {0x1,               "8K bytes"},
    {0x2,               "16K bytes"},
    {0x3,               "32K bytes"},
    {0x4,               "Reserved"},
    {0x5,               "64K bytes"},
    {0x6,               "Reserved"},
    {0x7,               "128K bytes"},
    {0x8,               "Reserved"},
    {0x9,               "256K bytes"},
    {0xA,               "512K bytes"},
    {0xB,               "Reserved"},
    {0xC,               "1024K bytes"},
    {0xD,               "Reserved"},
    {0xE,               "2048K bytes"},
    {0xF,               "Reserved"}
}};

constexpr const char* get_chip_id_nvm2_size_str(uint32_t nvp2_size)
{
    const char* ret = "unknown";

    for (const auto& nvp2 : kChipIdNvpSize2)
    {
        if (nvp2.id == nvp2_size)
        {
            ret = nvp2.str;
            break;
        }
    }

    return ret;
}

// SRAMs support list.
constexpr uint8_t kChipIdSramSizeSize = 16U;
constexpr std::array<chipidtype_t, kChipIdSramSizeSize> kChipIdSramSize = {{
    // identifier       description
    {0x0,               "48K bytes"},
    {0x1,               "192K bytes"},
    {0x2,               "384K bytes"},
    {0x3,               "6K bytes"},
    {0x4,               "112K bytes"},
    {0x5,               "4K bytes"},
    {0x6,               "80K bytes"},
    {0x7,               "160K bytes"},
    {0x8,               "8K bytes"},
    {0x9,               "16K bytes"},
    {0xA,               "32K bytes"},
    {0xB,               "64K bytes"},
    {0xC,               "128K bytes"},
    {0xD,               "256K bytes"},
    {0xE,               "96K bytes"},
    {0xF,               "512K bytes"}
}};

constexpr const char* get_chip_id_sram_size_str(uint32_t sram_size)
{
    const char* ret = "unknown";

    for (const auto& sram : kChipIdSramSize)
    {
        if (sram.id == sram_size)
        {
            ret = sram.str;
            break;
        }
    }

    return ret;
}

// Architectures support list.
constexpr uint8_t kChipIdArchSize = 47U;
constexpr std::array<chipidtype_t, kChipIdArchSize> kChipIdArch = {{
    // identifier       description
    {0x10,              "ATSAME70 Series"},
    {0x11,              "ATSAMS70 Series"},
    {0x12,              "ATSAMV71 Series"},
    {0x13,              "ATSAMV70 Series"},
    {0x19,              "AT91SAM9xx Series"},
    {0x29,              "AT91SAM9XExx Series"},
    {0x34,              "AT91x34 series"},
    {0x37,              "CAP7 Series"},
    {0x39,              "CAP9 Series"},
    {0x3B,              "CAP11 Series"},
    {0x3C,              "SAM4E Series"},
    {0x40,              "AT91x40 Series"},
    {0x42,              "AT91x42 Series"},
    {0x43,              "AT91SAMG51 Series"},
    {0x44,              "AT91SAMG55 Series(49-lead version)"},
    {0x45,              "AT91SAMG55 Series(64-lead version)"},
    {0x46,              "AT91SAMG55 Series(100-lead version)"},
    {0x47,              "AT91SAMG53/SAMG54 Series"},
    {0x55,              "AT91x55 Series"},
    {0x60,              "AT91SAM7Axx Series"},
    {0x61,              "AT91SAM7AQxx Series"},
    {0x63,              "AT91x63 Series"},
    {0x64,              "SAM4CxC Series"},
    {0x70,              "AT91SAM7Sxx Series"},
    {0x71,              "AT91SAM7XCxx Series"},
    {0x72,              "AT91SAM7SExx Series"},
    {0x73,              "AT91SAM7Lxx Series"},
    {0x75,              "AT91SAM7Xxx Series"},
    {0x76,              "AT91SAM7SLxx Series"},
    {0x80,              "ATSAM3UxC Series"},
    {0x81,              "ATSAM3UxE Series"},
    {0x83,              "ATSAM3A/SAM4A xC Series"},
    {0x84,              "ATSAM3X/SAM4X xC Series"},
    {0x85,              "ATSAM3X/SAM4X xE Series"},
    {0x86,              "ATSAM3X/SAM4X xG Series"},
    {0x88,              "ATSAM3S/SAM4S xA Series"},
    {0x89,              "ATSAM3S/SAM4S xB Series"},
    {0x8A,              "ATSAM3S/SAM4S xC Series"},
    {0x92,              "AT91x92 Series"},
    {0x93,              "ATSAM3NxA/SAM4NxA Series"},
    {0x94,              "ATSAM3NxB/SAM4NxB Series"},
    {0x95,              "ATSAM3NxC/SAM4NxC Series"},
    {0x98,              "ATSAM3SD/SAM4SD xA Series"},
    {0x99,              "ATSAM3SD/SAM4SD xB Series"},
    {0x9A,              "ATSAM3SD/SAM4SD xC Series"},
    {0xA5,              "ATSAM5A Series"},
    {0xF0,              "AT75Cxx Series"}
}};

constexpr const char* get_chip_id_arch_str(uint32_t arch)
{
    const char* ret = "unknown";

    for (const auto& a : kChipIdArch)
    {
        if (a.id == arch)
        {
            ret = a.str;
            break;
        }
    }

    return ret;
}

// ROMs support list.
constexpr uint8_t kChipIdNvpTypeSize = 5U;
constexpr std::array<chipidtype_t, kChipIdNvpTypeSize> kChipIdNvpType = {{
    // identifier       description
    {0x0,               "ROM"},
    {0x1,               "ROMless or on-chip Flash"},
    {0x4,               "SRAM emulating ROM"},
    {0x2,               "Embedded Flash Memory"},
    {0x3,               "ROM and Embedded Flash Memory"}
}};

constexpr const char* get_chip_id_nvp_type_str(uint32_t nvp_type)
{
    const char* ret = "unknown";

    for (const auto& nvp : kChipIdNvpType)
    {
        if (nvp.id == nvp_type)
        {
            ret = nvp.str;
            break;
        }
    }

    return ret;
}

#endif  // CHIP_ID_HELPER_H_
