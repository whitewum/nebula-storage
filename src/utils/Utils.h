/* Copyright (c) 2020 vesoft inc. All rights reserved.
 *
 * This source code is licensed under Apache 2.0 License,
 * attached with Common Clause Condition 1.0, found in the LICENSES directory.
 */

#ifndef UTILS_UTILS_H_
#define UTILS_UTILS_H_

#include "common/base/Base.h"

namespace nebula {
class Utils final {
public:
    // Calculate the admin service address based on the storage service address
    static HostAddr getAdminAddrFromStoreAddr(HostAddr storeAddr) {
        if (storeAddr == HostAddr("", 0)) {
            return storeAddr;
        }
        return HostAddr(storeAddr.host, storeAddr.port - 1);
    }

    static HostAddr getStoreAddrFromAdminAddr(HostAddr adminAddr) {
        if (adminAddr == HostAddr("", 0)) {
            return adminAddr;
        }
        return HostAddr(adminAddr.host, adminAddr.port + 1);
    }
};
}  // namespace nebula
#endif  // UTILS_UTILS_H_
