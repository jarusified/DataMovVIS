#pragma once

#include <list>
#include <memory>

#include "CuptiActivityBuffer.h"
#include "libdmv.h"

namespace libdmv {

struct ActivityBuffers {
  std::list<std::unique_ptr<libdmv::CpuTraceBuffer>> cpu;
  std::unique_ptr<CuptiActivityBufferMap> gpu;

  // Add a wrapper object to the underlying struct stored in the buffer
  template <class T> const ITraceActivity &addActivityWrapper(const T &act) {
    wrappers_.push_back(std::make_unique<T>(act));
    return *wrappers_.back().get();
  }

private:
  std::vector<std::unique_ptr<const ITraceActivity>> wrappers_;
};

} // namespace libdmv
