// Copyright The OpenTelemetry Authors
// SPDX-License-Identifier: Apache-2.0

#pragma once

#ifdef ENABLE_LOGS_PREVIEW

#  include <memory>
#  include <vector>

#  include "opentelemetry/version.h"

OPENTELEMETRY_BEGIN_NAMESPACE
namespace sdk
{
namespace logs
{
class LogRecordProcessor;

/**
 * Factory class for MultiLogRecordProcessor.
 */
class OPENTELEMETRY_EXPORT MultiLogRecordProcessorFactory
{
public:
  static std::unique_ptr<LogRecordProcessor> Create(
      std::vector<std::unique_ptr<LogRecordProcessor>> &&processors);
};

}  // namespace logs
}  // namespace sdk

OPENTELEMETRY_END_NAMESPACE
#endif
