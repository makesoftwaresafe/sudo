/* Generated by the protocol buffer compiler.  DO NOT EDIT! */
/* Generated from: intercept.proto */

#ifndef PROTOBUF_C_intercept_2eproto__INCLUDED
#define PROTOBUF_C_intercept_2eproto__INCLUDED

#include <protobuf-c/protobuf-c.h>

PROTOBUF_C__BEGIN_DECLS

#if PROTOBUF_C_VERSION_NUMBER < 1003000
# error This file was generated by a newer version of protoc-c which is incompatible with your libprotobuf-c headers. Please update your headers.
#elif 1003003 < PROTOBUF_C_MIN_COMPILER_VERSION
# error This file was generated by an older version of protoc-c which is incompatible with your libprotobuf-c headers. Please regenerate this file with a newer version of protoc-c.
#endif


typedef struct _InterceptRequest InterceptRequest;
typedef struct _ClientHello ClientHello;
typedef struct _HelloResponse HelloResponse;
typedef struct _PolicyCheckRequest PolicyCheckRequest;
typedef struct _PolicyAcceptMessage PolicyAcceptMessage;
typedef struct _PolicyRejectMessage PolicyRejectMessage;
typedef struct _PolicyErrorMessage PolicyErrorMessage;
typedef struct _InterceptResponse InterceptResponse;


/* --- enums --- */


/* --- messages --- */

typedef enum {
  INTERCEPT_REQUEST__TYPE__NOT_SET = 0,
  INTERCEPT_REQUEST__TYPE_POLICY_CHECK_REQ = 1,
  INTERCEPT_REQUEST__TYPE_HELLO = 2
    PROTOBUF_C__FORCE_ENUM_TO_BE_INT_SIZE(INTERCEPT_REQUEST__TYPE)
} InterceptRequest__TypeCase;

/*
 * Intercept message from sudo_intercept.so.  Messages on the
 * wire are prefixed with a 32-bit size in network byte order.
 */
struct  _InterceptRequest
{
  ProtobufCMessage base;
  InterceptRequest__TypeCase type_case;
  union {
    PolicyCheckRequest *policy_check_req;
    ClientHello *hello;
  } u;
};
#define INTERCEPT_REQUEST__INIT \
 { PROTOBUF_C_MESSAGE_INIT (&intercept_request__descriptor) \
    , INTERCEPT_REQUEST__TYPE__NOT_SET, {0} }


/*
 * Hello message from sudo_intercept.so to main sudo process.
 * Sudo sends back the secret and localhost port number.
 */
struct  _ClientHello
{
  ProtobufCMessage base;
  int32_t pid;
};
#define CLIENT_HELLO__INIT \
 { PROTOBUF_C_MESSAGE_INIT (&client_hello__descriptor) \
    , 0 }


/*
 * Sudo response to a ClientHello from sudo_intercept.so.
 * The client uses the port number and secret to connect back to sudo.
 */
struct  _HelloResponse
{
  ProtobufCMessage base;
  uint64_t secret;
  int32_t portno;
};
#define HELLO_RESPONSE__INIT \
 { PROTOBUF_C_MESSAGE_INIT (&hello_response__descriptor) \
    , 0, 0 }


/*
 * Policy check request from sudo_intercept.so.
 * Must include the correct secret value.
 * Note that the plugin API only currently supports passing
 * the new environment in to the open() function.
 */
struct  _PolicyCheckRequest
{
  ProtobufCMessage base;
  char *command;
  size_t n_argv;
  char **argv;
  size_t n_envp;
  char **envp;
  int32_t intercept_fd;
  uint64_t secret;
};
#define POLICY_CHECK_REQUEST__INIT \
 { PROTOBUF_C_MESSAGE_INIT (&policy_check_request__descriptor) \
    , (char *)protobuf_c_empty_string, 0,NULL, 0,NULL, 0, 0 }


struct  _PolicyAcceptMessage
{
  ProtobufCMessage base;
  char *run_command;
  size_t n_run_argv;
  char **run_argv;
  size_t n_run_envp;
  char **run_envp;
};
#define POLICY_ACCEPT_MESSAGE__INIT \
 { PROTOBUF_C_MESSAGE_INIT (&policy_accept_message__descriptor) \
    , (char *)protobuf_c_empty_string, 0,NULL, 0,NULL }


struct  _PolicyRejectMessage
{
  ProtobufCMessage base;
  char *reject_message;
};
#define POLICY_REJECT_MESSAGE__INIT \
 { PROTOBUF_C_MESSAGE_INIT (&policy_reject_message__descriptor) \
    , (char *)protobuf_c_empty_string }


struct  _PolicyErrorMessage
{
  ProtobufCMessage base;
  char *error_message;
};
#define POLICY_ERROR_MESSAGE__INIT \
 { PROTOBUF_C_MESSAGE_INIT (&policy_error_message__descriptor) \
    , (char *)protobuf_c_empty_string }


typedef enum {
  INTERCEPT_RESPONSE__TYPE__NOT_SET = 0,
  INTERCEPT_RESPONSE__TYPE_HELLO_RESP = 1,
  INTERCEPT_RESPONSE__TYPE_ACCEPT_MSG = 2,
  INTERCEPT_RESPONSE__TYPE_REJECT_MSG = 3,
  INTERCEPT_RESPONSE__TYPE_ERROR_MSG = 4
    PROTOBUF_C__FORCE_ENUM_TO_BE_INT_SIZE(INTERCEPT_RESPONSE__TYPE)
} InterceptResponse__TypeCase;

/*
 * Response sent back to sudo_intercept.so.
 */
struct  _InterceptResponse
{
  ProtobufCMessage base;
  InterceptResponse__TypeCase type_case;
  union {
    HelloResponse *hello_resp;
    PolicyAcceptMessage *accept_msg;
    PolicyRejectMessage *reject_msg;
    PolicyErrorMessage *error_msg;
  } u;
};
#define INTERCEPT_RESPONSE__INIT \
 { PROTOBUF_C_MESSAGE_INIT (&intercept_response__descriptor) \
    , INTERCEPT_RESPONSE__TYPE__NOT_SET, {0} }


/* InterceptRequest methods */
void   intercept_request__init
                     (InterceptRequest         *message);
size_t intercept_request__get_packed_size
                     (const InterceptRequest   *message);
size_t intercept_request__pack
                     (const InterceptRequest   *message,
                      uint8_t             *out);
size_t intercept_request__pack_to_buffer
                     (const InterceptRequest   *message,
                      ProtobufCBuffer     *buffer);
InterceptRequest *
       intercept_request__unpack
                     (ProtobufCAllocator  *allocator,
                      size_t               len,
                      const uint8_t       *data);
void   intercept_request__free_unpacked
                     (InterceptRequest *message,
                      ProtobufCAllocator *allocator);
/* ClientHello methods */
void   client_hello__init
                     (ClientHello         *message);
size_t client_hello__get_packed_size
                     (const ClientHello   *message);
size_t client_hello__pack
                     (const ClientHello   *message,
                      uint8_t             *out);
size_t client_hello__pack_to_buffer
                     (const ClientHello   *message,
                      ProtobufCBuffer     *buffer);
ClientHello *
       client_hello__unpack
                     (ProtobufCAllocator  *allocator,
                      size_t               len,
                      const uint8_t       *data);
void   client_hello__free_unpacked
                     (ClientHello *message,
                      ProtobufCAllocator *allocator);
/* HelloResponse methods */
void   hello_response__init
                     (HelloResponse         *message);
size_t hello_response__get_packed_size
                     (const HelloResponse   *message);
size_t hello_response__pack
                     (const HelloResponse   *message,
                      uint8_t             *out);
size_t hello_response__pack_to_buffer
                     (const HelloResponse   *message,
                      ProtobufCBuffer     *buffer);
HelloResponse *
       hello_response__unpack
                     (ProtobufCAllocator  *allocator,
                      size_t               len,
                      const uint8_t       *data);
void   hello_response__free_unpacked
                     (HelloResponse *message,
                      ProtobufCAllocator *allocator);
/* PolicyCheckRequest methods */
void   policy_check_request__init
                     (PolicyCheckRequest         *message);
size_t policy_check_request__get_packed_size
                     (const PolicyCheckRequest   *message);
size_t policy_check_request__pack
                     (const PolicyCheckRequest   *message,
                      uint8_t             *out);
size_t policy_check_request__pack_to_buffer
                     (const PolicyCheckRequest   *message,
                      ProtobufCBuffer     *buffer);
PolicyCheckRequest *
       policy_check_request__unpack
                     (ProtobufCAllocator  *allocator,
                      size_t               len,
                      const uint8_t       *data);
void   policy_check_request__free_unpacked
                     (PolicyCheckRequest *message,
                      ProtobufCAllocator *allocator);
/* PolicyAcceptMessage methods */
void   policy_accept_message__init
                     (PolicyAcceptMessage         *message);
size_t policy_accept_message__get_packed_size
                     (const PolicyAcceptMessage   *message);
size_t policy_accept_message__pack
                     (const PolicyAcceptMessage   *message,
                      uint8_t             *out);
size_t policy_accept_message__pack_to_buffer
                     (const PolicyAcceptMessage   *message,
                      ProtobufCBuffer     *buffer);
PolicyAcceptMessage *
       policy_accept_message__unpack
                     (ProtobufCAllocator  *allocator,
                      size_t               len,
                      const uint8_t       *data);
void   policy_accept_message__free_unpacked
                     (PolicyAcceptMessage *message,
                      ProtobufCAllocator *allocator);
/* PolicyRejectMessage methods */
void   policy_reject_message__init
                     (PolicyRejectMessage         *message);
size_t policy_reject_message__get_packed_size
                     (const PolicyRejectMessage   *message);
size_t policy_reject_message__pack
                     (const PolicyRejectMessage   *message,
                      uint8_t             *out);
size_t policy_reject_message__pack_to_buffer
                     (const PolicyRejectMessage   *message,
                      ProtobufCBuffer     *buffer);
PolicyRejectMessage *
       policy_reject_message__unpack
                     (ProtobufCAllocator  *allocator,
                      size_t               len,
                      const uint8_t       *data);
void   policy_reject_message__free_unpacked
                     (PolicyRejectMessage *message,
                      ProtobufCAllocator *allocator);
/* PolicyErrorMessage methods */
void   policy_error_message__init
                     (PolicyErrorMessage         *message);
size_t policy_error_message__get_packed_size
                     (const PolicyErrorMessage   *message);
size_t policy_error_message__pack
                     (const PolicyErrorMessage   *message,
                      uint8_t             *out);
size_t policy_error_message__pack_to_buffer
                     (const PolicyErrorMessage   *message,
                      ProtobufCBuffer     *buffer);
PolicyErrorMessage *
       policy_error_message__unpack
                     (ProtobufCAllocator  *allocator,
                      size_t               len,
                      const uint8_t       *data);
void   policy_error_message__free_unpacked
                     (PolicyErrorMessage *message,
                      ProtobufCAllocator *allocator);
/* InterceptResponse methods */
void   intercept_response__init
                     (InterceptResponse         *message);
size_t intercept_response__get_packed_size
                     (const InterceptResponse   *message);
size_t intercept_response__pack
                     (const InterceptResponse   *message,
                      uint8_t             *out);
size_t intercept_response__pack_to_buffer
                     (const InterceptResponse   *message,
                      ProtobufCBuffer     *buffer);
InterceptResponse *
       intercept_response__unpack
                     (ProtobufCAllocator  *allocator,
                      size_t               len,
                      const uint8_t       *data);
void   intercept_response__free_unpacked
                     (InterceptResponse *message,
                      ProtobufCAllocator *allocator);
/* --- per-message closures --- */

typedef void (*InterceptRequest_Closure)
                 (const InterceptRequest *message,
                  void *closure_data);
typedef void (*ClientHello_Closure)
                 (const ClientHello *message,
                  void *closure_data);
typedef void (*HelloResponse_Closure)
                 (const HelloResponse *message,
                  void *closure_data);
typedef void (*PolicyCheckRequest_Closure)
                 (const PolicyCheckRequest *message,
                  void *closure_data);
typedef void (*PolicyAcceptMessage_Closure)
                 (const PolicyAcceptMessage *message,
                  void *closure_data);
typedef void (*PolicyRejectMessage_Closure)
                 (const PolicyRejectMessage *message,
                  void *closure_data);
typedef void (*PolicyErrorMessage_Closure)
                 (const PolicyErrorMessage *message,
                  void *closure_data);
typedef void (*InterceptResponse_Closure)
                 (const InterceptResponse *message,
                  void *closure_data);

/* --- services --- */


/* --- descriptors --- */

extern const ProtobufCMessageDescriptor intercept_request__descriptor;
extern const ProtobufCMessageDescriptor client_hello__descriptor;
extern const ProtobufCMessageDescriptor hello_response__descriptor;
extern const ProtobufCMessageDescriptor policy_check_request__descriptor;
extern const ProtobufCMessageDescriptor policy_accept_message__descriptor;
extern const ProtobufCMessageDescriptor policy_reject_message__descriptor;
extern const ProtobufCMessageDescriptor policy_error_message__descriptor;
extern const ProtobufCMessageDescriptor intercept_response__descriptor;

PROTOBUF_C__END_DECLS


#endif  /* PROTOBUF_C_intercept_2eproto__INCLUDED */