// Copyright (c) 2013, Facebook, Inc.  All rights reserved.
// This source code is licensed under the BSD-style license found in the
// LICENSE file in the root directory of this source tree. An additional grant
// of patent rights can be found in the PATENTS file in the same directory.
//

#include "rocksdb/thread_status.h"
#include "util/thread_operation.h"

namespace rocksdb {

#if ROCKSDB_USING_THREAD_STATUS
const std::string& ThreadStatus::GetOperationName(
    ThreadStatus::OperationType op_type) {
  return global_operation_table[op_type].name;
}

const std::string& ThreadStatus::GetStateName(
    ThreadStatus::StateType state_type) {
  return global_state_table[state_type].name;
}

#else

const std::string& ThreadStatus::GetOperationName(
    ThreadStatus::OperationType op_type) {
  static std::string dummy_str = "";
  return dummy_str;
}

const std::string& ThreadStatus::GetStateName(
    ThreadStatus::StateType state_type) {
  static std::string dummy_str = "";
  return dummy_str;
}

#endif  // ROCKSDB_USING_THREAD_STATUS
}  // namespace rocksdb
