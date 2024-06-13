#pragma warning (disable : 4125)
// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: Authentication.proto

#include "Authentication.pb.h"

#include <algorithm>

#include <google/protobuf/io/coded_stream.h>
#include <google/protobuf/extension_set.h>
#include <google/protobuf/wire_format_lite.h>
#include <google/protobuf/descriptor.h>
#include <google/protobuf/generated_message_reflection.h>
#include <google/protobuf/reflection_ops.h>
#include <google/protobuf/wire_format.h>
// @@protoc_insertion_point(includes)
#include <google/protobuf/port_def.inc>

PROTOBUF_PRAGMA_INIT_SEG
namespace Zee {
namespace Proto {
namespace Authentication {
constexpr Login::Login(
  ::PROTOBUF_NAMESPACE_ID::internal::ConstantInitialized)
  : id_(&::PROTOBUF_NAMESPACE_ID::internal::fixed_address_empty_string)
  , uid_(int64_t{0})
  , rc_(0)
{}
struct LoginDefaultTypeInternal {
  constexpr LoginDefaultTypeInternal()
    : _instance(::PROTOBUF_NAMESPACE_ID::internal::ConstantInitialized{}) {}
  ~LoginDefaultTypeInternal() {}
  union {
    Login _instance;
  };
};
PROTOBUF_ATTRIBUTE_NO_DESTROY PROTOBUF_CONSTINIT LoginDefaultTypeInternal _Login_default_instance_;
constexpr Logout::Logout(
  ::PROTOBUF_NAMESPACE_ID::internal::ConstantInitialized)
  : id_(&::PROTOBUF_NAMESPACE_ID::internal::fixed_address_empty_string)
  , uid_(int64_t{0})
  , rc_(0)
{}
struct LogoutDefaultTypeInternal {
  constexpr LogoutDefaultTypeInternal()
    : _instance(::PROTOBUF_NAMESPACE_ID::internal::ConstantInitialized{}) {}
  ~LogoutDefaultTypeInternal() {}
  union {
    Logout _instance;
  };
};
PROTOBUF_ATTRIBUTE_NO_DESTROY PROTOBUF_CONSTINIT LogoutDefaultTypeInternal _Logout_default_instance_;
}  // namespace Authentication
}  // namespace Proto
}  // namespace Zee
static ::PROTOBUF_NAMESPACE_ID::Metadata file_level_metadata_Authentication_2eproto[2];
static const ::PROTOBUF_NAMESPACE_ID::EnumDescriptor* file_level_enum_descriptors_Authentication_2eproto[1];
static constexpr ::PROTOBUF_NAMESPACE_ID::ServiceDescriptor const** file_level_service_descriptors_Authentication_2eproto = nullptr;

const ::PROTOBUF_NAMESPACE_ID::uint32 TableStruct_Authentication_2eproto::offsets[] PROTOBUF_SECTION_VARIABLE(protodesc_cold) = {
  ~0u,  // no _has_bits_
  PROTOBUF_FIELD_OFFSET(::Zee::Proto::Authentication::Login, _internal_metadata_),
  ~0u,  // no _extensions_
  ~0u,  // no _oneof_case_
  ~0u,  // no _weak_field_map_
  ~0u,  // no _inlined_string_donated_
  PROTOBUF_FIELD_OFFSET(::Zee::Proto::Authentication::Login, rc_),
  PROTOBUF_FIELD_OFFSET(::Zee::Proto::Authentication::Login, id_),
  PROTOBUF_FIELD_OFFSET(::Zee::Proto::Authentication::Login, uid_),
  ~0u,  // no _has_bits_
  PROTOBUF_FIELD_OFFSET(::Zee::Proto::Authentication::Logout, _internal_metadata_),
  ~0u,  // no _extensions_
  ~0u,  // no _oneof_case_
  ~0u,  // no _weak_field_map_
  ~0u,  // no _inlined_string_donated_
  PROTOBUF_FIELD_OFFSET(::Zee::Proto::Authentication::Logout, rc_),
  PROTOBUF_FIELD_OFFSET(::Zee::Proto::Authentication::Logout, id_),
  PROTOBUF_FIELD_OFFSET(::Zee::Proto::Authentication::Logout, uid_),
};
static const ::PROTOBUF_NAMESPACE_ID::internal::MigrationSchema schemas[] PROTOBUF_SECTION_VARIABLE(protodesc_cold) = {
  { 0, -1, -1, sizeof(::Zee::Proto::Authentication::Login)},
  { 9, -1, -1, sizeof(::Zee::Proto::Authentication::Logout)},
};

static ::PROTOBUF_NAMESPACE_ID::Message const * const file_default_instances[] = {
  reinterpret_cast<const ::PROTOBUF_NAMESPACE_ID::Message*>(&::Zee::Proto::Authentication::_Login_default_instance_),
  reinterpret_cast<const ::PROTOBUF_NAMESPACE_ID::Message*>(&::Zee::Proto::Authentication::_Logout_default_instance_),
};

const char descriptor_table_protodef_Authentication_2eproto[] PROTOBUF_SECTION_VARIABLE(protodesc_cold) =
  "\n\024Authentication.proto\022\030Zee.Proto.Authen"
  "tication\"R\n\005Login\0220\n\002RC\030\001 \001(\0162$.Zee.Prot"
  "o.Authentication.ReturnCode\022\n\n\002Id\030\002 \001(\t\022"
  "\013\n\003UID\030\003 \001(\003\"S\n\006Logout\0220\n\002RC\030\001 \001(\0162$.Zee"
  ".Proto.Authentication.ReturnCode\022\n\n\002Id\030\002"
  " \001(\t\022\013\n\003UID\030\003 \001(\003*X\n\nReturnCode\022\017\n\013RC_SU"
  "CCESSS\020\000\022\033\n\027RC_FAILED_ALREADY_LOGIN\020\001\022\034\n"
  "\030RC_FAILED_ALREADY_LOGOUT\020\002b\006proto3"
  ;
static ::PROTOBUF_NAMESPACE_ID::internal::once_flag descriptor_table_Authentication_2eproto_once;
const ::PROTOBUF_NAMESPACE_ID::internal::DescriptorTable descriptor_table_Authentication_2eproto = {
  false, false, 315, descriptor_table_protodef_Authentication_2eproto, "Authentication.proto", 
  &descriptor_table_Authentication_2eproto_once, nullptr, 0, 2,
  schemas, file_default_instances, TableStruct_Authentication_2eproto::offsets,
  file_level_metadata_Authentication_2eproto, file_level_enum_descriptors_Authentication_2eproto, file_level_service_descriptors_Authentication_2eproto,
};
PROTOBUF_ATTRIBUTE_WEAK const ::PROTOBUF_NAMESPACE_ID::internal::DescriptorTable* descriptor_table_Authentication_2eproto_getter() {
  return &descriptor_table_Authentication_2eproto;
}

// Force running AddDescriptors() at dynamic initialization time.
PROTOBUF_ATTRIBUTE_INIT_PRIORITY static ::PROTOBUF_NAMESPACE_ID::internal::AddDescriptorsRunner dynamic_init_dummy_Authentication_2eproto(&descriptor_table_Authentication_2eproto);
namespace Zee {
namespace Proto {
namespace Authentication {
const ::PROTOBUF_NAMESPACE_ID::EnumDescriptor* ReturnCode_descriptor() {
  ::PROTOBUF_NAMESPACE_ID::internal::AssignDescriptors(&descriptor_table_Authentication_2eproto);
  return file_level_enum_descriptors_Authentication_2eproto[0];
}
bool ReturnCode_IsValid(int value) {
  switch (value) {
    case 0:
    case 1:
    case 2:
      return true;
    default:
      return false;
  }
}


// ===================================================================

class Login::_Internal {
 public:
};

Login::Login(::PROTOBUF_NAMESPACE_ID::Arena* arena,
                         bool is_message_owned)
  : ::PROTOBUF_NAMESPACE_ID::Message(arena, is_message_owned) {
  SharedCtor();
  if (!is_message_owned) {
    RegisterArenaDtor(arena);
  }
  // @@protoc_insertion_point(arena_constructor:Zee.Proto.Authentication.Login)
}
Login::Login(const Login& from)
  : ::PROTOBUF_NAMESPACE_ID::Message() {
  _internal_metadata_.MergeFrom<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(from._internal_metadata_);
  id_.UnsafeSetDefault(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
  if (!from._internal_id().empty()) {
    id_.Set(::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr::EmptyDefault{}, from._internal_id(), 
      GetArenaForAllocation());
  }
  ::memcpy(&uid_, &from.uid_,
    static_cast<size_t>(reinterpret_cast<char*>(&rc_) -
    reinterpret_cast<char*>(&uid_)) + sizeof(rc_));
  // @@protoc_insertion_point(copy_constructor:Zee.Proto.Authentication.Login)
}

void Login::SharedCtor() {
id_.UnsafeSetDefault(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
::memset(reinterpret_cast<char*>(this) + static_cast<size_t>(
    reinterpret_cast<char*>(&uid_) - reinterpret_cast<char*>(this)),
    0, static_cast<size_t>(reinterpret_cast<char*>(&rc_) -
    reinterpret_cast<char*>(&uid_)) + sizeof(rc_));
}

Login::~Login() {
  // @@protoc_insertion_point(destructor:Zee.Proto.Authentication.Login)
  if (GetArenaForAllocation() != nullptr) return;
  SharedDtor();
  _internal_metadata_.Delete<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>();
}

inline void Login::SharedDtor() {
  GOOGLE_DCHECK(GetArenaForAllocation() == nullptr);
  id_.DestroyNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
}

void Login::ArenaDtor(void* object) {
  Login* _this = reinterpret_cast< Login* >(object);
  (void)_this;
}
void Login::RegisterArenaDtor(::PROTOBUF_NAMESPACE_ID::Arena*) {
}
void Login::SetCachedSize(int size) const {
  _cached_size_.Set(size);
}

void Login::Clear() {
// @@protoc_insertion_point(message_clear_start:Zee.Proto.Authentication.Login)
  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  id_.ClearToEmpty();
  ::memset(&uid_, 0, static_cast<size_t>(
      reinterpret_cast<char*>(&rc_) -
      reinterpret_cast<char*>(&uid_)) + sizeof(rc_));
  _internal_metadata_.Clear<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>();
}

const char* Login::_InternalParse(const char* ptr, ::PROTOBUF_NAMESPACE_ID::internal::ParseContext* ctx) {
#define CHK_(x) if (PROTOBUF_PREDICT_FALSE(!(x))) goto failure
  while (!ctx->Done(&ptr)) {
    ::PROTOBUF_NAMESPACE_ID::uint32 tag;
    ptr = ::PROTOBUF_NAMESPACE_ID::internal::ReadTag(ptr, &tag);
    switch (tag >> 3) {
      // .Zee.Proto.Authentication.ReturnCode RC = 1;
      case 1:
        if (PROTOBUF_PREDICT_TRUE(static_cast<::PROTOBUF_NAMESPACE_ID::uint8>(tag) == 8)) {
          ::PROTOBUF_NAMESPACE_ID::uint64 val = ::PROTOBUF_NAMESPACE_ID::internal::ReadVarint64(&ptr);
          CHK_(ptr);
          _internal_set_rc(static_cast<::Zee::Proto::Authentication::ReturnCode>(val));
        } else
          goto handle_unusual;
        continue;
      // string Id = 2;
      case 2:
        if (PROTOBUF_PREDICT_TRUE(static_cast<::PROTOBUF_NAMESPACE_ID::uint8>(tag) == 18)) {
          auto str = _internal_mutable_id();
          ptr = ::PROTOBUF_NAMESPACE_ID::internal::InlineGreedyStringParser(str, ptr, ctx);
          CHK_(::PROTOBUF_NAMESPACE_ID::internal::VerifyUTF8(str, "Zee.Proto.Authentication.Login.Id"));
          CHK_(ptr);
        } else
          goto handle_unusual;
        continue;
      // int64 UID = 3;
      case 3:
        if (PROTOBUF_PREDICT_TRUE(static_cast<::PROTOBUF_NAMESPACE_ID::uint8>(tag) == 24)) {
          uid_ = ::PROTOBUF_NAMESPACE_ID::internal::ReadVarint64(&ptr);
          CHK_(ptr);
        } else
          goto handle_unusual;
        continue;
      default:
        goto handle_unusual;
    }  // switch
  handle_unusual:
    if ((tag == 0) || ((tag & 7) == 4)) {
      CHK_(ptr);
      ctx->SetLastTag(tag);
      goto message_done;
    }
    ptr = UnknownFieldParse(
        tag,
        _internal_metadata_.mutable_unknown_fields<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(),
        ptr, ctx);
    CHK_(ptr != nullptr);
  }  // while
message_done:
  return ptr;
failure:
  ptr = nullptr;
  goto message_done;
#undef CHK_
}

::PROTOBUF_NAMESPACE_ID::uint8* Login::_InternalSerialize(
    ::PROTOBUF_NAMESPACE_ID::uint8* target, ::PROTOBUF_NAMESPACE_ID::io::EpsCopyOutputStream* stream) const {
  // @@protoc_insertion_point(serialize_to_array_start:Zee.Proto.Authentication.Login)
  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  // .Zee.Proto.Authentication.ReturnCode RC = 1;
  if (this->_internal_rc() != 0) {
    target = stream->EnsureSpace(target);
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::WriteEnumToArray(
      1, this->_internal_rc(), target);
  }

  // string Id = 2;
  if (!this->_internal_id().empty()) {
    ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::VerifyUtf8String(
      this->_internal_id().data(), static_cast<int>(this->_internal_id().length()),
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::SERIALIZE,
      "Zee.Proto.Authentication.Login.Id");
    target = stream->WriteStringMaybeAliased(
        2, this->_internal_id(), target);
  }

  // int64 UID = 3;
  if (this->_internal_uid() != 0) {
    target = stream->EnsureSpace(target);
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::WriteInt64ToArray(3, this->_internal_uid(), target);
  }

  if (PROTOBUF_PREDICT_FALSE(_internal_metadata_.have_unknown_fields())) {
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormat::InternalSerializeUnknownFieldsToArray(
        _internal_metadata_.unknown_fields<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(::PROTOBUF_NAMESPACE_ID::UnknownFieldSet::default_instance), target, stream);
  }
  // @@protoc_insertion_point(serialize_to_array_end:Zee.Proto.Authentication.Login)
  return target;
}

size_t Login::ByteSizeLong() const {
// @@protoc_insertion_point(message_byte_size_start:Zee.Proto.Authentication.Login)
  size_t total_size = 0;

  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  // string Id = 2;
  if (!this->_internal_id().empty()) {
    total_size += 1 +
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::StringSize(
        this->_internal_id());
  }

  // int64 UID = 3;
  if (this->_internal_uid() != 0) {
    total_size += ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::Int64SizePlusOne(this->_internal_uid());
  }

  // .Zee.Proto.Authentication.ReturnCode RC = 1;
  if (this->_internal_rc() != 0) {
    total_size += 1 +
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::EnumSize(this->_internal_rc());
  }

  return MaybeComputeUnknownFieldsSize(total_size, &_cached_size_);
}

const ::PROTOBUF_NAMESPACE_ID::Message::ClassData Login::_class_data_ = {
    ::PROTOBUF_NAMESPACE_ID::Message::CopyWithSizeCheck,
    Login::MergeImpl
};
const ::PROTOBUF_NAMESPACE_ID::Message::ClassData*Login::GetClassData() const { return &_class_data_; }

void Login::MergeImpl(::PROTOBUF_NAMESPACE_ID::Message* to,
                      const ::PROTOBUF_NAMESPACE_ID::Message& from) {
  static_cast<Login *>(to)->MergeFrom(
      static_cast<const Login &>(from));
}


void Login::MergeFrom(const Login& from) {
// @@protoc_insertion_point(class_specific_merge_from_start:Zee.Proto.Authentication.Login)
  GOOGLE_DCHECK_NE(&from, this);
  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  if (!from._internal_id().empty()) {
    _internal_set_id(from._internal_id());
  }
  if (from._internal_uid() != 0) {
    _internal_set_uid(from._internal_uid());
  }
  if (from._internal_rc() != 0) {
    _internal_set_rc(from._internal_rc());
  }
  _internal_metadata_.MergeFrom<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(from._internal_metadata_);
}

void Login::CopyFrom(const Login& from) {
// @@protoc_insertion_point(class_specific_copy_from_start:Zee.Proto.Authentication.Login)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool Login::IsInitialized() const {
  return true;
}

void Login::InternalSwap(Login* other) {
  using std::swap;
  auto* lhs_arena = GetArenaForAllocation();
  auto* rhs_arena = other->GetArenaForAllocation();
  _internal_metadata_.InternalSwap(&other->_internal_metadata_);
  ::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr::InternalSwap(
      &::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(),
      &id_, lhs_arena,
      &other->id_, rhs_arena
  );
  ::PROTOBUF_NAMESPACE_ID::internal::memswap<
      PROTOBUF_FIELD_OFFSET(Login, rc_)
      + sizeof(Login::rc_)
      - PROTOBUF_FIELD_OFFSET(Login, uid_)>(
          reinterpret_cast<char*>(&uid_),
          reinterpret_cast<char*>(&other->uid_));
}

::PROTOBUF_NAMESPACE_ID::Metadata Login::GetMetadata() const {
  return ::PROTOBUF_NAMESPACE_ID::internal::AssignDescriptors(
      &descriptor_table_Authentication_2eproto_getter, &descriptor_table_Authentication_2eproto_once,
      file_level_metadata_Authentication_2eproto[0]);
}

// ===================================================================

class Logout::_Internal {
 public:
};

Logout::Logout(::PROTOBUF_NAMESPACE_ID::Arena* arena,
                         bool is_message_owned)
  : ::PROTOBUF_NAMESPACE_ID::Message(arena, is_message_owned) {
  SharedCtor();
  if (!is_message_owned) {
    RegisterArenaDtor(arena);
  }
  // @@protoc_insertion_point(arena_constructor:Zee.Proto.Authentication.Logout)
}
Logout::Logout(const Logout& from)
  : ::PROTOBUF_NAMESPACE_ID::Message() {
  _internal_metadata_.MergeFrom<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(from._internal_metadata_);
  id_.UnsafeSetDefault(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
  if (!from._internal_id().empty()) {
    id_.Set(::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr::EmptyDefault{}, from._internal_id(), 
      GetArenaForAllocation());
  }
  ::memcpy(&uid_, &from.uid_,
    static_cast<size_t>(reinterpret_cast<char*>(&rc_) -
    reinterpret_cast<char*>(&uid_)) + sizeof(rc_));
  // @@protoc_insertion_point(copy_constructor:Zee.Proto.Authentication.Logout)
}

void Logout::SharedCtor() {
id_.UnsafeSetDefault(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
::memset(reinterpret_cast<char*>(this) + static_cast<size_t>(
    reinterpret_cast<char*>(&uid_) - reinterpret_cast<char*>(this)),
    0, static_cast<size_t>(reinterpret_cast<char*>(&rc_) -
    reinterpret_cast<char*>(&uid_)) + sizeof(rc_));
}

Logout::~Logout() {
  // @@protoc_insertion_point(destructor:Zee.Proto.Authentication.Logout)
  if (GetArenaForAllocation() != nullptr) return;
  SharedDtor();
  _internal_metadata_.Delete<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>();
}

inline void Logout::SharedDtor() {
  GOOGLE_DCHECK(GetArenaForAllocation() == nullptr);
  id_.DestroyNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
}

void Logout::ArenaDtor(void* object) {
  Logout* _this = reinterpret_cast< Logout* >(object);
  (void)_this;
}
void Logout::RegisterArenaDtor(::PROTOBUF_NAMESPACE_ID::Arena*) {
}
void Logout::SetCachedSize(int size) const {
  _cached_size_.Set(size);
}

void Logout::Clear() {
// @@protoc_insertion_point(message_clear_start:Zee.Proto.Authentication.Logout)
  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  id_.ClearToEmpty();
  ::memset(&uid_, 0, static_cast<size_t>(
      reinterpret_cast<char*>(&rc_) -
      reinterpret_cast<char*>(&uid_)) + sizeof(rc_));
  _internal_metadata_.Clear<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>();
}

const char* Logout::_InternalParse(const char* ptr, ::PROTOBUF_NAMESPACE_ID::internal::ParseContext* ctx) {
#define CHK_(x) if (PROTOBUF_PREDICT_FALSE(!(x))) goto failure
  while (!ctx->Done(&ptr)) {
    ::PROTOBUF_NAMESPACE_ID::uint32 tag;
    ptr = ::PROTOBUF_NAMESPACE_ID::internal::ReadTag(ptr, &tag);
    switch (tag >> 3) {
      // .Zee.Proto.Authentication.ReturnCode RC = 1;
      case 1:
        if (PROTOBUF_PREDICT_TRUE(static_cast<::PROTOBUF_NAMESPACE_ID::uint8>(tag) == 8)) {
          ::PROTOBUF_NAMESPACE_ID::uint64 val = ::PROTOBUF_NAMESPACE_ID::internal::ReadVarint64(&ptr);
          CHK_(ptr);
          _internal_set_rc(static_cast<::Zee::Proto::Authentication::ReturnCode>(val));
        } else
          goto handle_unusual;
        continue;
      // string Id = 2;
      case 2:
        if (PROTOBUF_PREDICT_TRUE(static_cast<::PROTOBUF_NAMESPACE_ID::uint8>(tag) == 18)) {
          auto str = _internal_mutable_id();
          ptr = ::PROTOBUF_NAMESPACE_ID::internal::InlineGreedyStringParser(str, ptr, ctx);
          CHK_(::PROTOBUF_NAMESPACE_ID::internal::VerifyUTF8(str, "Zee.Proto.Authentication.Logout.Id"));
          CHK_(ptr);
        } else
          goto handle_unusual;
        continue;
      // int64 UID = 3;
      case 3:
        if (PROTOBUF_PREDICT_TRUE(static_cast<::PROTOBUF_NAMESPACE_ID::uint8>(tag) == 24)) {
          uid_ = ::PROTOBUF_NAMESPACE_ID::internal::ReadVarint64(&ptr);
          CHK_(ptr);
        } else
          goto handle_unusual;
        continue;
      default:
        goto handle_unusual;
    }  // switch
  handle_unusual:
    if ((tag == 0) || ((tag & 7) == 4)) {
      CHK_(ptr);
      ctx->SetLastTag(tag);
      goto message_done;
    }
    ptr = UnknownFieldParse(
        tag,
        _internal_metadata_.mutable_unknown_fields<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(),
        ptr, ctx);
    CHK_(ptr != nullptr);
  }  // while
message_done:
  return ptr;
failure:
  ptr = nullptr;
  goto message_done;
#undef CHK_
}

::PROTOBUF_NAMESPACE_ID::uint8* Logout::_InternalSerialize(
    ::PROTOBUF_NAMESPACE_ID::uint8* target, ::PROTOBUF_NAMESPACE_ID::io::EpsCopyOutputStream* stream) const {
  // @@protoc_insertion_point(serialize_to_array_start:Zee.Proto.Authentication.Logout)
  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  // .Zee.Proto.Authentication.ReturnCode RC = 1;
  if (this->_internal_rc() != 0) {
    target = stream->EnsureSpace(target);
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::WriteEnumToArray(
      1, this->_internal_rc(), target);
  }

  // string Id = 2;
  if (!this->_internal_id().empty()) {
    ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::VerifyUtf8String(
      this->_internal_id().data(), static_cast<int>(this->_internal_id().length()),
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::SERIALIZE,
      "Zee.Proto.Authentication.Logout.Id");
    target = stream->WriteStringMaybeAliased(
        2, this->_internal_id(), target);
  }

  // int64 UID = 3;
  if (this->_internal_uid() != 0) {
    target = stream->EnsureSpace(target);
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::WriteInt64ToArray(3, this->_internal_uid(), target);
  }

  if (PROTOBUF_PREDICT_FALSE(_internal_metadata_.have_unknown_fields())) {
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormat::InternalSerializeUnknownFieldsToArray(
        _internal_metadata_.unknown_fields<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(::PROTOBUF_NAMESPACE_ID::UnknownFieldSet::default_instance), target, stream);
  }
  // @@protoc_insertion_point(serialize_to_array_end:Zee.Proto.Authentication.Logout)
  return target;
}

size_t Logout::ByteSizeLong() const {
// @@protoc_insertion_point(message_byte_size_start:Zee.Proto.Authentication.Logout)
  size_t total_size = 0;

  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  // string Id = 2;
  if (!this->_internal_id().empty()) {
    total_size += 1 +
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::StringSize(
        this->_internal_id());
  }

  // int64 UID = 3;
  if (this->_internal_uid() != 0) {
    total_size += ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::Int64SizePlusOne(this->_internal_uid());
  }

  // .Zee.Proto.Authentication.ReturnCode RC = 1;
  if (this->_internal_rc() != 0) {
    total_size += 1 +
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::EnumSize(this->_internal_rc());
  }

  return MaybeComputeUnknownFieldsSize(total_size, &_cached_size_);
}

const ::PROTOBUF_NAMESPACE_ID::Message::ClassData Logout::_class_data_ = {
    ::PROTOBUF_NAMESPACE_ID::Message::CopyWithSizeCheck,
    Logout::MergeImpl
};
const ::PROTOBUF_NAMESPACE_ID::Message::ClassData*Logout::GetClassData() const { return &_class_data_; }

void Logout::MergeImpl(::PROTOBUF_NAMESPACE_ID::Message* to,
                      const ::PROTOBUF_NAMESPACE_ID::Message& from) {
  static_cast<Logout *>(to)->MergeFrom(
      static_cast<const Logout &>(from));
}


void Logout::MergeFrom(const Logout& from) {
// @@protoc_insertion_point(class_specific_merge_from_start:Zee.Proto.Authentication.Logout)
  GOOGLE_DCHECK_NE(&from, this);
  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  if (!from._internal_id().empty()) {
    _internal_set_id(from._internal_id());
  }
  if (from._internal_uid() != 0) {
    _internal_set_uid(from._internal_uid());
  }
  if (from._internal_rc() != 0) {
    _internal_set_rc(from._internal_rc());
  }
  _internal_metadata_.MergeFrom<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(from._internal_metadata_);
}

void Logout::CopyFrom(const Logout& from) {
// @@protoc_insertion_point(class_specific_copy_from_start:Zee.Proto.Authentication.Logout)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool Logout::IsInitialized() const {
  return true;
}

void Logout::InternalSwap(Logout* other) {
  using std::swap;
  auto* lhs_arena = GetArenaForAllocation();
  auto* rhs_arena = other->GetArenaForAllocation();
  _internal_metadata_.InternalSwap(&other->_internal_metadata_);
  ::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr::InternalSwap(
      &::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(),
      &id_, lhs_arena,
      &other->id_, rhs_arena
  );
  ::PROTOBUF_NAMESPACE_ID::internal::memswap<
      PROTOBUF_FIELD_OFFSET(Logout, rc_)
      + sizeof(Logout::rc_)
      - PROTOBUF_FIELD_OFFSET(Logout, uid_)>(
          reinterpret_cast<char*>(&uid_),
          reinterpret_cast<char*>(&other->uid_));
}

::PROTOBUF_NAMESPACE_ID::Metadata Logout::GetMetadata() const {
  return ::PROTOBUF_NAMESPACE_ID::internal::AssignDescriptors(
      &descriptor_table_Authentication_2eproto_getter, &descriptor_table_Authentication_2eproto_once,
      file_level_metadata_Authentication_2eproto[1]);
}

// @@protoc_insertion_point(namespace_scope)
}  // namespace Authentication
}  // namespace Proto
}  // namespace Zee
PROTOBUF_NAMESPACE_OPEN
template<> PROTOBUF_NOINLINE ::Zee::Proto::Authentication::Login* Arena::CreateMaybeMessage< ::Zee::Proto::Authentication::Login >(Arena* arena) {
  return Arena::CreateMessageInternal< ::Zee::Proto::Authentication::Login >(arena);
}
template<> PROTOBUF_NOINLINE ::Zee::Proto::Authentication::Logout* Arena::CreateMaybeMessage< ::Zee::Proto::Authentication::Logout >(Arena* arena) {
  return Arena::CreateMessageInternal< ::Zee::Proto::Authentication::Logout >(arena);
}
PROTOBUF_NAMESPACE_CLOSE

// @@protoc_insertion_point(global_scope)
#include <google/protobuf/port_undef.inc>

