#pragma once

#include <cstdint>

namespace DMV_NAMESPACE {

// cupti's timestamps are platform specific. This function convert the raw
// cupti timestamp to time since unix epoch. So that on different platform,
// correction can work correctly.
uint64_t unixEpochTimestamp(uint64_t ts);

} // namespace DMV_NAMESPACE
