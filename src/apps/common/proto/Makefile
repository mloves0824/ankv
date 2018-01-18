PROTOC = protoc
PROTOC_EXTRA_ARGS = 

.PHONY:all
all: node_svr.pb.cc  

.PHONY:clean
clean:
	@echo "Cleaning"
	@rm -rf %.pb.cc %.pb.h



%.pb.cc %.pb.h:%.proto
	@echo "Generating $@"
	@$(PROTOC) --cpp_out=. --proto_path=. $(PROTOC_EXTRA_ARGS) $<
