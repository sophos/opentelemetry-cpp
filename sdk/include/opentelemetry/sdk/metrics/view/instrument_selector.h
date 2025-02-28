// Copyright The OpenTelemetry Authors
// SPDX-License-Identifier: Apache-2.0

#pragma once

#include <memory>

#include "opentelemetry/nostd/string_view.h"
#include "opentelemetry/sdk/metrics/instruments.h"
#include "opentelemetry/sdk/metrics/view/predicate_factory.h"
#include "opentelemetry/version.h"

OPENTELEMETRY_BEGIN_NAMESPACE
namespace sdk
{
namespace metrics
{
class InstrumentSelector
{
public:
  InstrumentSelector(opentelemetry::sdk::metrics::InstrumentType instrument_type,
                     opentelemetry::nostd::string_view name)
      : name_filter_{PredicateFactory::GetPredicate(name, PredicateType::kPattern)},
        instrument_type_{instrument_type}
  {}

  // Returns name filter predicate. This shouldn't be deleted
  const opentelemetry::sdk::metrics::Predicate *GetNameFilter() const { return name_filter_.get(); }

  // Returns instrument filter.
  InstrumentType GetInstrumentType() { return instrument_type_; }

private:
  std::unique_ptr<opentelemetry::sdk::metrics::Predicate> name_filter_;
  opentelemetry::sdk::metrics::InstrumentType instrument_type_;
};
}  // namespace metrics
}  // namespace sdk
OPENTELEMETRY_END_NAMESPACE
