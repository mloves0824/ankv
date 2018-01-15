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
#include "im.login.pb.h"
#include <brpc/server.h>


// Your implementation of im::login::IMLoginService
// Notice that implementing brpc::Describable grants the ability to put
// additional information in /status.
namespace antalk {
namespace apigw {

class IMLoginServiceImpl : public im::login::IMLoginService {
public:
	IMLoginServiceImpl() {};
	virtual ~IMLoginServiceImpl() {};
	virtual void IMLogin(google::protobuf::RpcController* cntl_base,
		const im::login::IMLoginReq* request,
		im::login::IMLoginRes* response,
		google::protobuf::Closure* done) {
		// This object helps you to call done->Run() in RAII style. If you need
		// to process the request asynchronously, pass done_guard.release().
		brpc::ClosureGuard done_guard(done);

		brpc::Controller* cntl =
			static_cast<brpc::Controller*>(cntl_base);

		// The purpose of following logs is to help you to understand
		// how clients interact with servers more intuitively. You should 
		// remove these logs in performance-sensitive servers.
		LOG(INFO) << "Received request[log_id=" << cntl->log_id()
			<< "] from " << cntl->remote_side()
			<< " to " << cntl->local_side()
			//<< ": " << request->message()
			<< " (attached=" << cntl->request_attachment() << ")";

		// Fill response.
		response->set_result_code(im::base::REFUSE_REASON_NONE);

		// You can compress the response by setting Controller, but be aware
		// that compression may be costly, evaluate before turning on.
		// cntl->set_response_compress_type(brpc::COMPRESS_TYPE_GZIP);

		//if (FLAGS_echo_attachment) {
			// Set attachment which is wired to network directly instead of
			// being serialized into protobuf messages.
			//cntl->response_attachment().append(cntl->request_attachment());
		//}
	}
};

}  // namespace example
}
