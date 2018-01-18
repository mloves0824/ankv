// Copyright (c) 2015 Antalk, Inc.
// 
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
// 
//     http://www.apache.org/licenses/LICENSE-2.0
// 
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

// Author: chenbang (chenbang@antalk.com)
// Date: $time$

#include <gflags/gflags.h>
#include <brpc/server.h>
#include "node_svr.pb.h"


// Your implementation of InfoServerService
// Notice that implementing brpc::Describable grants the ability to put
// additional information in /status.
namespace ankv {
namespace node {

class InfoServerServiceImpl : public InfoServerService {
public:
	InfoServerServiceImpl() {};
	virtual ~InfoServerServiceImpl() {};
	virtual void InfoServer(google::protobuf::RpcController* cntl_base,
							const InfoServerReq* request,
							InfoServerResp* response,
							google::protobuf::Closure* done);
};

}  // namespace example
}
