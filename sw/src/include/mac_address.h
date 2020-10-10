#ifndef MAC_ADDRESS_H_
#define MAC_ADDRESS_H_

#include "conf_eth.h"

#include <array>
#include <cstdbool>

struct Eui48MacAddress
{
    using MacAddress_t = std::array<uint8_t, 6U>;

    constexpr Eui48MacAddress() noexcept :
        value{
            ETHERNET_CONF_ETHADDR0, ETHERNET_CONF_ETHADDR1, ETHERNET_CONF_ETHADDR2,
            ETHERNET_CONF_ETHADDR3, ETHERNET_CONF_ETHADDR4, ETHERNET_CONF_ETHADDR5},
        unique{false}
    {
    }

    constexpr Eui48MacAddress(const MacAddress_t& new_mac) noexcept :
        value{new_mac},
        unique{false}
    {
    }

    constexpr uint8_t& operator[](uint8_t idx) noexcept
    {
        return value[idx];
    }

    constexpr const uint8_t& operator[](uint8_t idx) const noexcept
    {
        return value[idx];
    }

    constexpr uint8_t size() noexcept
    {
        return value.size();
    }

    MacAddress_t value;
    bool unique;
};

#endif  // MAC_ADDRESS_H_
