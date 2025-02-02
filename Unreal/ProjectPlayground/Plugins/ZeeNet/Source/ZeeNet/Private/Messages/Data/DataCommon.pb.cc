#pragma warning (disable : 4125)
// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: Data/DataCommon.proto

#include "DataCommon.pb.h"

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
namespace Data {
constexpr Vector::Vector(
  ::PROTOBUF_NAMESPACE_ID::internal::ConstantInitialized)
  : x_(0)
  , y_(0)
  , z_(0){}
struct VectorDefaultTypeInternal {
  constexpr VectorDefaultTypeInternal()
    : _instance(::PROTOBUF_NAMESPACE_ID::internal::ConstantInitialized{}) {}
  ~VectorDefaultTypeInternal() {}
  union {
    Vector _instance;
  };
};
PROTOBUF_ATTRIBUTE_NO_DESTROY PROTOBUF_CONSTINIT VectorDefaultTypeInternal _Vector_default_instance_;
constexpr Rotator::Rotator(
  ::PROTOBUF_NAMESPACE_ID::internal::ConstantInitialized)
  : pitch_(0)
  , yaw_(0)
  , roll_(0){}
struct RotatorDefaultTypeInternal {
  constexpr RotatorDefaultTypeInternal()
    : _instance(::PROTOBUF_NAMESPACE_ID::internal::ConstantInitialized{}) {}
  ~RotatorDefaultTypeInternal() {}
  union {
    Rotator _instance;
  };
};
PROTOBUF_ATTRIBUTE_NO_DESTROY PROTOBUF_CONSTINIT RotatorDefaultTypeInternal _Rotator_default_instance_;
constexpr Position::Position(
  ::PROTOBUF_NAMESPACE_ID::internal::ConstantInitialized)
  : mapname_(&::PROTOBUF_NAMESPACE_ID::internal::fixed_address_empty_string)
  , pos_(nullptr)
  , rot_(nullptr)
  , uid_(int64_t{0}){}
struct PositionDefaultTypeInternal {
  constexpr PositionDefaultTypeInternal()
    : _instance(::PROTOBUF_NAMESPACE_ID::internal::ConstantInitialized{}) {}
  ~PositionDefaultTypeInternal() {}
  union {
    Position _instance;
  };
};
PROTOBUF_ATTRIBUTE_NO_DESTROY PROTOBUF_CONSTINIT PositionDefaultTypeInternal _Position_default_instance_;
}  // namespace Data
}  // namespace Proto
}  // namespace Zee
static ::PROTOBUF_NAMESPACE_ID::Metadata file_level_metadata_Data_2fDataCommon_2eproto[3];
static constexpr ::PROTOBUF_NAMESPACE_ID::EnumDescriptor const** file_level_enum_descriptors_Data_2fDataCommon_2eproto = nullptr;
static constexpr ::PROTOBUF_NAMESPACE_ID::ServiceDescriptor const** file_level_service_descriptors_Data_2fDataCommon_2eproto = nullptr;

const ::PROTOBUF_NAMESPACE_ID::uint32 TableStruct_Data_2fDataCommon_2eproto::offsets[] PROTOBUF_SECTION_VARIABLE(protodesc_cold) = {
  ~0u,  // no _has_bits_
  PROTOBUF_FIELD_OFFSET(::Zee::Proto::Data::Vector, _internal_metadata_),
  ~0u,  // no _extensions_
  ~0u,  // no _oneof_case_
  ~0u,  // no _weak_field_map_
  ~0u,  // no _inlined_string_donated_
  PROTOBUF_FIELD_OFFSET(::Zee::Proto::Data::Vector, x_),
  PROTOBUF_FIELD_OFFSET(::Zee::Proto::Data::Vector, y_),
  PROTOBUF_FIELD_OFFSET(::Zee::Proto::Data::Vector, z_),
  ~0u,  // no _has_bits_
  PROTOBUF_FIELD_OFFSET(::Zee::Proto::Data::Rotator, _internal_metadata_),
  ~0u,  // no _extensions_
  ~0u,  // no _oneof_case_
  ~0u,  // no _weak_field_map_
  ~0u,  // no _inlined_string_donated_
  PROTOBUF_FIELD_OFFSET(::Zee::Proto::Data::Rotator, pitch_),
  PROTOBUF_FIELD_OFFSET(::Zee::Proto::Data::Rotator, yaw_),
  PROTOBUF_FIELD_OFFSET(::Zee::Proto::Data::Rotator, roll_),
  ~0u,  // no _has_bits_
  PROTOBUF_FIELD_OFFSET(::Zee::Proto::Data::Position, _internal_metadata_),
  ~0u,  // no _extensions_
  ~0u,  // no _oneof_case_
  ~0u,  // no _weak_field_map_
  ~0u,  // no _inlined_string_donated_
  PROTOBUF_FIELD_OFFSET(::Zee::Proto::Data::Position, uid_),
  PROTOBUF_FIELD_OFFSET(::Zee::Proto::Data::Position, mapname_),
  PROTOBUF_FIELD_OFFSET(::Zee::Proto::Data::Position, pos_),
  PROTOBUF_FIELD_OFFSET(::Zee::Proto::Data::Position, rot_),
};
static const ::PROTOBUF_NAMESPACE_ID::internal::MigrationSchema schemas[] PROTOBUF_SECTION_VARIABLE(protodesc_cold) = {
  { 0, -1, -1, sizeof(::Zee::Proto::Data::Vector)},
  { 9, -1, -1, sizeof(::Zee::Proto::Data::Rotator)},
  { 18, -1, -1, sizeof(::Zee::Proto::Data::Position)},
};

static ::PROTOBUF_NAMESPACE_ID::Message const * const file_default_instances[] = {
  reinterpret_cast<const ::PROTOBUF_NAMESPACE_ID::Message*>(&::Zee::Proto::Data::_Vector_default_instance_),
  reinterpret_cast<const ::PROTOBUF_NAMESPACE_ID::Message*>(&::Zee::Proto::Data::_Rotator_default_instance_),
  reinterpret_cast<const ::PROTOBUF_NAMESPACE_ID::Message*>(&::Zee::Proto::Data::_Position_default_instance_),
};

const char descriptor_table_protodef_Data_2fDataCommon_2eproto[] PROTOBUF_SECTION_VARIABLE(protodesc_cold) =
  "\n\025Data/DataCommon.proto\022\016Zee.Proto.Data\""
  ")\n\006Vector\022\t\n\001X\030\001 \001(\002\022\t\n\001Y\030\002 \001(\002\022\t\n\001Z\030\003 \001"
  "(\002\"3\n\007Rotator\022\r\n\005Pitch\030\001 \001(\002\022\013\n\003Yaw\030\002 \001("
  "\002\022\014\n\004Roll\030\003 \001(\002\"s\n\010Position\022\013\n\003UID\030\001 \001(\003"
  "\022\017\n\007MapName\030\002 \001(\t\022#\n\003Pos\030\003 \001(\0132\026.Zee.Pro"
  "to.Data.Vector\022$\n\003Rot\030\004 \001(\0132\027.Zee.Proto."
  "Data.Rotatorb\006proto3"
  ;
static ::PROTOBUF_NAMESPACE_ID::internal::once_flag descriptor_table_Data_2fDataCommon_2eproto_once;
const ::PROTOBUF_NAMESPACE_ID::internal::DescriptorTable descriptor_table_Data_2fDataCommon_2eproto = {
  false, false, 260, descriptor_table_protodef_Data_2fDataCommon_2eproto, "Data/DataCommon.proto", 
  &descriptor_table_Data_2fDataCommon_2eproto_once, nullptr, 0, 3,
  schemas, file_default_instances, TableStruct_Data_2fDataCommon_2eproto::offsets,
  file_level_metadata_Data_2fDataCommon_2eproto, file_level_enum_descriptors_Data_2fDataCommon_2eproto, file_level_service_descriptors_Data_2fDataCommon_2eproto,
};
PROTOBUF_ATTRIBUTE_WEAK const ::PROTOBUF_NAMESPACE_ID::internal::DescriptorTable* descriptor_table_Data_2fDataCommon_2eproto_getter() {
  return &descriptor_table_Data_2fDataCommon_2eproto;
}

// Force running AddDescriptors() at dynamic initialization time.
PROTOBUF_ATTRIBUTE_INIT_PRIORITY static ::PROTOBUF_NAMESPACE_ID::internal::AddDescriptorsRunner dynamic_init_dummy_Data_2fDataCommon_2eproto(&descriptor_table_Data_2fDataCommon_2eproto);
namespace Zee {
namespace Proto {
namespace Data {

// ===================================================================

class Vector::_Internal {
 public:
};

Vector::Vector(::PROTOBUF_NAMESPACE_ID::Arena* arena,
                         bool is_message_owned)
  : ::PROTOBUF_NAMESPACE_ID::Message(arena, is_message_owned) {
  SharedCtor();
  if (!is_message_owned) {
    RegisterArenaDtor(arena);
  }
  // @@protoc_insertion_point(arena_constructor:Zee.Proto.Data.Vector)
}
Vector::Vector(const Vector& from)
  : ::PROTOBUF_NAMESPACE_ID::Message() {
  _internal_metadata_.MergeFrom<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(from._internal_metadata_);
  ::memcpy(&x_, &from.x_,
    static_cast<size_t>(reinterpret_cast<char*>(&z_) -
    reinterpret_cast<char*>(&x_)) + sizeof(z_));
  // @@protoc_insertion_point(copy_constructor:Zee.Proto.Data.Vector)
}

void Vector::SharedCtor() {
::memset(reinterpret_cast<char*>(this) + static_cast<size_t>(
    reinterpret_cast<char*>(&x_) - reinterpret_cast<char*>(this)),
    0, static_cast<size_t>(reinterpret_cast<char*>(&z_) -
    reinterpret_cast<char*>(&x_)) + sizeof(z_));
}

Vector::~Vector() {
  // @@protoc_insertion_point(destructor:Zee.Proto.Data.Vector)
  if (GetArenaForAllocation() != nullptr) return;
  SharedDtor();
  _internal_metadata_.Delete<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>();
}

inline void Vector::SharedDtor() {
  GOOGLE_DCHECK(GetArenaForAllocation() == nullptr);
}

void Vector::ArenaDtor(void* object) {
  Vector* _this = reinterpret_cast< Vector* >(object);
  (void)_this;
}
void Vector::RegisterArenaDtor(::PROTOBUF_NAMESPACE_ID::Arena*) {
}
void Vector::SetCachedSize(int size) const {
  _cached_size_.Set(size);
}

void Vector::Clear() {
// @@protoc_insertion_point(message_clear_start:Zee.Proto.Data.Vector)
  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  ::memset(&x_, 0, static_cast<size_t>(
      reinterpret_cast<char*>(&z_) -
      reinterpret_cast<char*>(&x_)) + sizeof(z_));
  _internal_metadata_.Clear<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>();
}

const char* Vector::_InternalParse(const char* ptr, ::PROTOBUF_NAMESPACE_ID::internal::ParseContext* ctx) {
#define CHK_(x) if (PROTOBUF_PREDICT_FALSE(!(x))) goto failure
  while (!ctx->Done(&ptr)) {
    ::PROTOBUF_NAMESPACE_ID::uint32 tag;
    ptr = ::PROTOBUF_NAMESPACE_ID::internal::ReadTag(ptr, &tag);
    switch (tag >> 3) {
      // float X = 1;
      case 1:
        if (PROTOBUF_PREDICT_TRUE(static_cast<::PROTOBUF_NAMESPACE_ID::uint8>(tag) == 13)) {
          x_ = ::PROTOBUF_NAMESPACE_ID::internal::UnalignedLoad<float>(ptr);
          ptr += sizeof(float);
        } else
          goto handle_unusual;
        continue;
      // float Y = 2;
      case 2:
        if (PROTOBUF_PREDICT_TRUE(static_cast<::PROTOBUF_NAMESPACE_ID::uint8>(tag) == 21)) {
          y_ = ::PROTOBUF_NAMESPACE_ID::internal::UnalignedLoad<float>(ptr);
          ptr += sizeof(float);
        } else
          goto handle_unusual;
        continue;
      // float Z = 3;
      case 3:
        if (PROTOBUF_PREDICT_TRUE(static_cast<::PROTOBUF_NAMESPACE_ID::uint8>(tag) == 29)) {
          z_ = ::PROTOBUF_NAMESPACE_ID::internal::UnalignedLoad<float>(ptr);
          ptr += sizeof(float);
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

::PROTOBUF_NAMESPACE_ID::uint8* Vector::_InternalSerialize(
    ::PROTOBUF_NAMESPACE_ID::uint8* target, ::PROTOBUF_NAMESPACE_ID::io::EpsCopyOutputStream* stream) const {
  // @@protoc_insertion_point(serialize_to_array_start:Zee.Proto.Data.Vector)
  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  // float X = 1;
  if (!(this->_internal_x() <= 0 && this->_internal_x() >= 0)) {
    target = stream->EnsureSpace(target);
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::WriteFloatToArray(1, this->_internal_x(), target);
  }

  // float Y = 2;
  if (!(this->_internal_y() <= 0 && this->_internal_y() >= 0)) {
    target = stream->EnsureSpace(target);
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::WriteFloatToArray(2, this->_internal_y(), target);
  }

  // float Z = 3;
  if (!(this->_internal_z() <= 0 && this->_internal_z() >= 0)) {
    target = stream->EnsureSpace(target);
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::WriteFloatToArray(3, this->_internal_z(), target);
  }

  if (PROTOBUF_PREDICT_FALSE(_internal_metadata_.have_unknown_fields())) {
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormat::InternalSerializeUnknownFieldsToArray(
        _internal_metadata_.unknown_fields<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(::PROTOBUF_NAMESPACE_ID::UnknownFieldSet::default_instance), target, stream);
  }
  // @@protoc_insertion_point(serialize_to_array_end:Zee.Proto.Data.Vector)
  return target;
}

size_t Vector::ByteSizeLong() const {
// @@protoc_insertion_point(message_byte_size_start:Zee.Proto.Data.Vector)
  size_t total_size = 0;

  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  // float X = 1;
  if (!(this->_internal_x() <= 0 && this->_internal_x() >= 0)) {
    total_size += 1 + 4;
  }

  // float Y = 2;
  if (!(this->_internal_y() <= 0 && this->_internal_y() >= 0)) {
    total_size += 1 + 4;
  }

  // float Z = 3;
  if (!(this->_internal_z() <= 0 && this->_internal_z() >= 0)) {
    total_size += 1 + 4;
  }

  return MaybeComputeUnknownFieldsSize(total_size, &_cached_size_);
}

const ::PROTOBUF_NAMESPACE_ID::Message::ClassData Vector::_class_data_ = {
    ::PROTOBUF_NAMESPACE_ID::Message::CopyWithSizeCheck,
    Vector::MergeImpl
};
const ::PROTOBUF_NAMESPACE_ID::Message::ClassData*Vector::GetClassData() const { return &_class_data_; }

void Vector::MergeImpl(::PROTOBUF_NAMESPACE_ID::Message* to,
                      const ::PROTOBUF_NAMESPACE_ID::Message& from) {
  static_cast<Vector *>(to)->MergeFrom(
      static_cast<const Vector &>(from));
}


void Vector::MergeFrom(const Vector& from) {
// @@protoc_insertion_point(class_specific_merge_from_start:Zee.Proto.Data.Vector)
  GOOGLE_DCHECK_NE(&from, this);
  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  if (!(from._internal_x() <= 0 && from._internal_x() >= 0)) {
    _internal_set_x(from._internal_x());
  }
  if (!(from._internal_y() <= 0 && from._internal_y() >= 0)) {
    _internal_set_y(from._internal_y());
  }
  if (!(from._internal_z() <= 0 && from._internal_z() >= 0)) {
    _internal_set_z(from._internal_z());
  }
  _internal_metadata_.MergeFrom<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(from._internal_metadata_);
}

void Vector::CopyFrom(const Vector& from) {
// @@protoc_insertion_point(class_specific_copy_from_start:Zee.Proto.Data.Vector)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool Vector::IsInitialized() const {
  return true;
}

void Vector::InternalSwap(Vector* other) {
  using std::swap;
  _internal_metadata_.InternalSwap(&other->_internal_metadata_);
  ::PROTOBUF_NAMESPACE_ID::internal::memswap<
      PROTOBUF_FIELD_OFFSET(Vector, z_)
      + sizeof(Vector::z_)
      - PROTOBUF_FIELD_OFFSET(Vector, x_)>(
          reinterpret_cast<char*>(&x_),
          reinterpret_cast<char*>(&other->x_));
}

::PROTOBUF_NAMESPACE_ID::Metadata Vector::GetMetadata() const {
  return ::PROTOBUF_NAMESPACE_ID::internal::AssignDescriptors(
      &descriptor_table_Data_2fDataCommon_2eproto_getter, &descriptor_table_Data_2fDataCommon_2eproto_once,
      file_level_metadata_Data_2fDataCommon_2eproto[0]);
}

// ===================================================================

class Rotator::_Internal {
 public:
};

Rotator::Rotator(::PROTOBUF_NAMESPACE_ID::Arena* arena,
                         bool is_message_owned)
  : ::PROTOBUF_NAMESPACE_ID::Message(arena, is_message_owned) {
  SharedCtor();
  if (!is_message_owned) {
    RegisterArenaDtor(arena);
  }
  // @@protoc_insertion_point(arena_constructor:Zee.Proto.Data.Rotator)
}
Rotator::Rotator(const Rotator& from)
  : ::PROTOBUF_NAMESPACE_ID::Message() {
  _internal_metadata_.MergeFrom<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(from._internal_metadata_);
  ::memcpy(&pitch_, &from.pitch_,
    static_cast<size_t>(reinterpret_cast<char*>(&roll_) -
    reinterpret_cast<char*>(&pitch_)) + sizeof(roll_));
  // @@protoc_insertion_point(copy_constructor:Zee.Proto.Data.Rotator)
}

void Rotator::SharedCtor() {
::memset(reinterpret_cast<char*>(this) + static_cast<size_t>(
    reinterpret_cast<char*>(&pitch_) - reinterpret_cast<char*>(this)),
    0, static_cast<size_t>(reinterpret_cast<char*>(&roll_) -
    reinterpret_cast<char*>(&pitch_)) + sizeof(roll_));
}

Rotator::~Rotator() {
  // @@protoc_insertion_point(destructor:Zee.Proto.Data.Rotator)
  if (GetArenaForAllocation() != nullptr) return;
  SharedDtor();
  _internal_metadata_.Delete<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>();
}

inline void Rotator::SharedDtor() {
  GOOGLE_DCHECK(GetArenaForAllocation() == nullptr);
}

void Rotator::ArenaDtor(void* object) {
  Rotator* _this = reinterpret_cast< Rotator* >(object);
  (void)_this;
}
void Rotator::RegisterArenaDtor(::PROTOBUF_NAMESPACE_ID::Arena*) {
}
void Rotator::SetCachedSize(int size) const {
  _cached_size_.Set(size);
}

void Rotator::Clear() {
// @@protoc_insertion_point(message_clear_start:Zee.Proto.Data.Rotator)
  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  ::memset(&pitch_, 0, static_cast<size_t>(
      reinterpret_cast<char*>(&roll_) -
      reinterpret_cast<char*>(&pitch_)) + sizeof(roll_));
  _internal_metadata_.Clear<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>();
}

const char* Rotator::_InternalParse(const char* ptr, ::PROTOBUF_NAMESPACE_ID::internal::ParseContext* ctx) {
#define CHK_(x) if (PROTOBUF_PREDICT_FALSE(!(x))) goto failure
  while (!ctx->Done(&ptr)) {
    ::PROTOBUF_NAMESPACE_ID::uint32 tag;
    ptr = ::PROTOBUF_NAMESPACE_ID::internal::ReadTag(ptr, &tag);
    switch (tag >> 3) {
      // float Pitch = 1;
      case 1:
        if (PROTOBUF_PREDICT_TRUE(static_cast<::PROTOBUF_NAMESPACE_ID::uint8>(tag) == 13)) {
          pitch_ = ::PROTOBUF_NAMESPACE_ID::internal::UnalignedLoad<float>(ptr);
          ptr += sizeof(float);
        } else
          goto handle_unusual;
        continue;
      // float Yaw = 2;
      case 2:
        if (PROTOBUF_PREDICT_TRUE(static_cast<::PROTOBUF_NAMESPACE_ID::uint8>(tag) == 21)) {
          yaw_ = ::PROTOBUF_NAMESPACE_ID::internal::UnalignedLoad<float>(ptr);
          ptr += sizeof(float);
        } else
          goto handle_unusual;
        continue;
      // float Roll = 3;
      case 3:
        if (PROTOBUF_PREDICT_TRUE(static_cast<::PROTOBUF_NAMESPACE_ID::uint8>(tag) == 29)) {
          roll_ = ::PROTOBUF_NAMESPACE_ID::internal::UnalignedLoad<float>(ptr);
          ptr += sizeof(float);
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

::PROTOBUF_NAMESPACE_ID::uint8* Rotator::_InternalSerialize(
    ::PROTOBUF_NAMESPACE_ID::uint8* target, ::PROTOBUF_NAMESPACE_ID::io::EpsCopyOutputStream* stream) const {
  // @@protoc_insertion_point(serialize_to_array_start:Zee.Proto.Data.Rotator)
  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  // float Pitch = 1;
  if (!(this->_internal_pitch() <= 0 && this->_internal_pitch() >= 0)) {
    target = stream->EnsureSpace(target);
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::WriteFloatToArray(1, this->_internal_pitch(), target);
  }

  // float Yaw = 2;
  if (!(this->_internal_yaw() <= 0 && this->_internal_yaw() >= 0)) {
    target = stream->EnsureSpace(target);
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::WriteFloatToArray(2, this->_internal_yaw(), target);
  }

  // float Roll = 3;
  if (!(this->_internal_roll() <= 0 && this->_internal_roll() >= 0)) {
    target = stream->EnsureSpace(target);
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::WriteFloatToArray(3, this->_internal_roll(), target);
  }

  if (PROTOBUF_PREDICT_FALSE(_internal_metadata_.have_unknown_fields())) {
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormat::InternalSerializeUnknownFieldsToArray(
        _internal_metadata_.unknown_fields<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(::PROTOBUF_NAMESPACE_ID::UnknownFieldSet::default_instance), target, stream);
  }
  // @@protoc_insertion_point(serialize_to_array_end:Zee.Proto.Data.Rotator)
  return target;
}

size_t Rotator::ByteSizeLong() const {
// @@protoc_insertion_point(message_byte_size_start:Zee.Proto.Data.Rotator)
  size_t total_size = 0;

  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  // float Pitch = 1;
  if (!(this->_internal_pitch() <= 0 && this->_internal_pitch() >= 0)) {
    total_size += 1 + 4;
  }

  // float Yaw = 2;
  if (!(this->_internal_yaw() <= 0 && this->_internal_yaw() >= 0)) {
    total_size += 1 + 4;
  }

  // float Roll = 3;
  if (!(this->_internal_roll() <= 0 && this->_internal_roll() >= 0)) {
    total_size += 1 + 4;
  }

  return MaybeComputeUnknownFieldsSize(total_size, &_cached_size_);
}

const ::PROTOBUF_NAMESPACE_ID::Message::ClassData Rotator::_class_data_ = {
    ::PROTOBUF_NAMESPACE_ID::Message::CopyWithSizeCheck,
    Rotator::MergeImpl
};
const ::PROTOBUF_NAMESPACE_ID::Message::ClassData*Rotator::GetClassData() const { return &_class_data_; }

void Rotator::MergeImpl(::PROTOBUF_NAMESPACE_ID::Message* to,
                      const ::PROTOBUF_NAMESPACE_ID::Message& from) {
  static_cast<Rotator *>(to)->MergeFrom(
      static_cast<const Rotator &>(from));
}


void Rotator::MergeFrom(const Rotator& from) {
// @@protoc_insertion_point(class_specific_merge_from_start:Zee.Proto.Data.Rotator)
  GOOGLE_DCHECK_NE(&from, this);
  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  if (!(from._internal_pitch() <= 0 && from._internal_pitch() >= 0)) {
    _internal_set_pitch(from._internal_pitch());
  }
  if (!(from._internal_yaw() <= 0 && from._internal_yaw() >= 0)) {
    _internal_set_yaw(from._internal_yaw());
  }
  if (!(from._internal_roll() <= 0 && from._internal_roll() >= 0)) {
    _internal_set_roll(from._internal_roll());
  }
  _internal_metadata_.MergeFrom<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(from._internal_metadata_);
}

void Rotator::CopyFrom(const Rotator& from) {
// @@protoc_insertion_point(class_specific_copy_from_start:Zee.Proto.Data.Rotator)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool Rotator::IsInitialized() const {
  return true;
}

void Rotator::InternalSwap(Rotator* other) {
  using std::swap;
  _internal_metadata_.InternalSwap(&other->_internal_metadata_);
  ::PROTOBUF_NAMESPACE_ID::internal::memswap<
      PROTOBUF_FIELD_OFFSET(Rotator, roll_)
      + sizeof(Rotator::roll_)
      - PROTOBUF_FIELD_OFFSET(Rotator, pitch_)>(
          reinterpret_cast<char*>(&pitch_),
          reinterpret_cast<char*>(&other->pitch_));
}

::PROTOBUF_NAMESPACE_ID::Metadata Rotator::GetMetadata() const {
  return ::PROTOBUF_NAMESPACE_ID::internal::AssignDescriptors(
      &descriptor_table_Data_2fDataCommon_2eproto_getter, &descriptor_table_Data_2fDataCommon_2eproto_once,
      file_level_metadata_Data_2fDataCommon_2eproto[1]);
}

// ===================================================================

class Position::_Internal {
 public:
  static const ::Zee::Proto::Data::Vector& pos(const Position* msg);
  static const ::Zee::Proto::Data::Rotator& rot(const Position* msg);
};

const ::Zee::Proto::Data::Vector&
Position::_Internal::pos(const Position* msg) {
  return *msg->pos_;
}
const ::Zee::Proto::Data::Rotator&
Position::_Internal::rot(const Position* msg) {
  return *msg->rot_;
}
Position::Position(::PROTOBUF_NAMESPACE_ID::Arena* arena,
                         bool is_message_owned)
  : ::PROTOBUF_NAMESPACE_ID::Message(arena, is_message_owned) {
  SharedCtor();
  if (!is_message_owned) {
    RegisterArenaDtor(arena);
  }
  // @@protoc_insertion_point(arena_constructor:Zee.Proto.Data.Position)
}
Position::Position(const Position& from)
  : ::PROTOBUF_NAMESPACE_ID::Message() {
  _internal_metadata_.MergeFrom<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(from._internal_metadata_);
  mapname_.UnsafeSetDefault(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
  if (!from._internal_mapname().empty()) {
    mapname_.Set(::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr::EmptyDefault{}, from._internal_mapname(), 
      GetArenaForAllocation());
  }
  if (from._internal_has_pos()) {
    pos_ = new ::Zee::Proto::Data::Vector(*from.pos_);
  } else {
    pos_ = nullptr;
  }
  if (from._internal_has_rot()) {
    rot_ = new ::Zee::Proto::Data::Rotator(*from.rot_);
  } else {
    rot_ = nullptr;
  }
  uid_ = from.uid_;
  // @@protoc_insertion_point(copy_constructor:Zee.Proto.Data.Position)
}

void Position::SharedCtor() {
mapname_.UnsafeSetDefault(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
::memset(reinterpret_cast<char*>(this) + static_cast<size_t>(
    reinterpret_cast<char*>(&pos_) - reinterpret_cast<char*>(this)),
    0, static_cast<size_t>(reinterpret_cast<char*>(&uid_) -
    reinterpret_cast<char*>(&pos_)) + sizeof(uid_));
}

Position::~Position() {
  // @@protoc_insertion_point(destructor:Zee.Proto.Data.Position)
  if (GetArenaForAllocation() != nullptr) return;
  SharedDtor();
  _internal_metadata_.Delete<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>();
}

inline void Position::SharedDtor() {
  GOOGLE_DCHECK(GetArenaForAllocation() == nullptr);
  mapname_.DestroyNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
  if (this != internal_default_instance()) delete pos_;
  if (this != internal_default_instance()) delete rot_;
}

void Position::ArenaDtor(void* object) {
  Position* _this = reinterpret_cast< Position* >(object);
  (void)_this;
}
void Position::RegisterArenaDtor(::PROTOBUF_NAMESPACE_ID::Arena*) {
}
void Position::SetCachedSize(int size) const {
  _cached_size_.Set(size);
}

void Position::Clear() {
// @@protoc_insertion_point(message_clear_start:Zee.Proto.Data.Position)
  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  mapname_.ClearToEmpty();
  if (GetArenaForAllocation() == nullptr && pos_ != nullptr) {
    delete pos_;
  }
  pos_ = nullptr;
  if (GetArenaForAllocation() == nullptr && rot_ != nullptr) {
    delete rot_;
  }
  rot_ = nullptr;
  uid_ = int64_t{0};
  _internal_metadata_.Clear<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>();
}

const char* Position::_InternalParse(const char* ptr, ::PROTOBUF_NAMESPACE_ID::internal::ParseContext* ctx) {
#define CHK_(x) if (PROTOBUF_PREDICT_FALSE(!(x))) goto failure
  while (!ctx->Done(&ptr)) {
    ::PROTOBUF_NAMESPACE_ID::uint32 tag;
    ptr = ::PROTOBUF_NAMESPACE_ID::internal::ReadTag(ptr, &tag);
    switch (tag >> 3) {
      // int64 UID = 1;
      case 1:
        if (PROTOBUF_PREDICT_TRUE(static_cast<::PROTOBUF_NAMESPACE_ID::uint8>(tag) == 8)) {
          uid_ = ::PROTOBUF_NAMESPACE_ID::internal::ReadVarint64(&ptr);
          CHK_(ptr);
        } else
          goto handle_unusual;
        continue;
      // string MapName = 2;
      case 2:
        if (PROTOBUF_PREDICT_TRUE(static_cast<::PROTOBUF_NAMESPACE_ID::uint8>(tag) == 18)) {
          auto str = _internal_mutable_mapname();
          ptr = ::PROTOBUF_NAMESPACE_ID::internal::InlineGreedyStringParser(str, ptr, ctx);
          CHK_(::PROTOBUF_NAMESPACE_ID::internal::VerifyUTF8(str, "Zee.Proto.Data.Position.MapName"));
          CHK_(ptr);
        } else
          goto handle_unusual;
        continue;
      // .Zee.Proto.Data.Vector Pos = 3;
      case 3:
        if (PROTOBUF_PREDICT_TRUE(static_cast<::PROTOBUF_NAMESPACE_ID::uint8>(tag) == 26)) {
          ptr = ctx->ParseMessage(_internal_mutable_pos(), ptr);
          CHK_(ptr);
        } else
          goto handle_unusual;
        continue;
      // .Zee.Proto.Data.Rotator Rot = 4;
      case 4:
        if (PROTOBUF_PREDICT_TRUE(static_cast<::PROTOBUF_NAMESPACE_ID::uint8>(tag) == 34)) {
          ptr = ctx->ParseMessage(_internal_mutable_rot(), ptr);
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

::PROTOBUF_NAMESPACE_ID::uint8* Position::_InternalSerialize(
    ::PROTOBUF_NAMESPACE_ID::uint8* target, ::PROTOBUF_NAMESPACE_ID::io::EpsCopyOutputStream* stream) const {
  // @@protoc_insertion_point(serialize_to_array_start:Zee.Proto.Data.Position)
  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  // int64 UID = 1;
  if (this->_internal_uid() != 0) {
    target = stream->EnsureSpace(target);
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::WriteInt64ToArray(1, this->_internal_uid(), target);
  }

  // string MapName = 2;
  if (!this->_internal_mapname().empty()) {
    ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::VerifyUtf8String(
      this->_internal_mapname().data(), static_cast<int>(this->_internal_mapname().length()),
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::SERIALIZE,
      "Zee.Proto.Data.Position.MapName");
    target = stream->WriteStringMaybeAliased(
        2, this->_internal_mapname(), target);
  }

  // .Zee.Proto.Data.Vector Pos = 3;
  if (this->_internal_has_pos()) {
    target = stream->EnsureSpace(target);
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::
      InternalWriteMessage(
        3, _Internal::pos(this), target, stream);
  }

  // .Zee.Proto.Data.Rotator Rot = 4;
  if (this->_internal_has_rot()) {
    target = stream->EnsureSpace(target);
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::
      InternalWriteMessage(
        4, _Internal::rot(this), target, stream);
  }

  if (PROTOBUF_PREDICT_FALSE(_internal_metadata_.have_unknown_fields())) {
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormat::InternalSerializeUnknownFieldsToArray(
        _internal_metadata_.unknown_fields<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(::PROTOBUF_NAMESPACE_ID::UnknownFieldSet::default_instance), target, stream);
  }
  // @@protoc_insertion_point(serialize_to_array_end:Zee.Proto.Data.Position)
  return target;
}

size_t Position::ByteSizeLong() const {
// @@protoc_insertion_point(message_byte_size_start:Zee.Proto.Data.Position)
  size_t total_size = 0;

  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  // string MapName = 2;
  if (!this->_internal_mapname().empty()) {
    total_size += 1 +
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::StringSize(
        this->_internal_mapname());
  }

  // .Zee.Proto.Data.Vector Pos = 3;
  if (this->_internal_has_pos()) {
    total_size += 1 +
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::MessageSize(
        *pos_);
  }

  // .Zee.Proto.Data.Rotator Rot = 4;
  if (this->_internal_has_rot()) {
    total_size += 1 +
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::MessageSize(
        *rot_);
  }

  // int64 UID = 1;
  if (this->_internal_uid() != 0) {
    total_size += ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::Int64SizePlusOne(this->_internal_uid());
  }

  return MaybeComputeUnknownFieldsSize(total_size, &_cached_size_);
}

const ::PROTOBUF_NAMESPACE_ID::Message::ClassData Position::_class_data_ = {
    ::PROTOBUF_NAMESPACE_ID::Message::CopyWithSizeCheck,
    Position::MergeImpl
};
const ::PROTOBUF_NAMESPACE_ID::Message::ClassData*Position::GetClassData() const { return &_class_data_; }

void Position::MergeImpl(::PROTOBUF_NAMESPACE_ID::Message* to,
                      const ::PROTOBUF_NAMESPACE_ID::Message& from) {
  static_cast<Position *>(to)->MergeFrom(
      static_cast<const Position &>(from));
}


void Position::MergeFrom(const Position& from) {
// @@protoc_insertion_point(class_specific_merge_from_start:Zee.Proto.Data.Position)
  GOOGLE_DCHECK_NE(&from, this);
  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  if (!from._internal_mapname().empty()) {
    _internal_set_mapname(from._internal_mapname());
  }
  if (from._internal_has_pos()) {
    _internal_mutable_pos()->::Zee::Proto::Data::Vector::MergeFrom(from._internal_pos());
  }
  if (from._internal_has_rot()) {
    _internal_mutable_rot()->::Zee::Proto::Data::Rotator::MergeFrom(from._internal_rot());
  }
  if (from._internal_uid() != 0) {
    _internal_set_uid(from._internal_uid());
  }
  _internal_metadata_.MergeFrom<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(from._internal_metadata_);
}

void Position::CopyFrom(const Position& from) {
// @@protoc_insertion_point(class_specific_copy_from_start:Zee.Proto.Data.Position)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool Position::IsInitialized() const {
  return true;
}

void Position::InternalSwap(Position* other) {
  using std::swap;
  auto* lhs_arena = GetArenaForAllocation();
  auto* rhs_arena = other->GetArenaForAllocation();
  _internal_metadata_.InternalSwap(&other->_internal_metadata_);
  ::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr::InternalSwap(
      &::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(),
      &mapname_, lhs_arena,
      &other->mapname_, rhs_arena
  );
  ::PROTOBUF_NAMESPACE_ID::internal::memswap<
      PROTOBUF_FIELD_OFFSET(Position, uid_)
      + sizeof(Position::uid_)
      - PROTOBUF_FIELD_OFFSET(Position, pos_)>(
          reinterpret_cast<char*>(&pos_),
          reinterpret_cast<char*>(&other->pos_));
}

::PROTOBUF_NAMESPACE_ID::Metadata Position::GetMetadata() const {
  return ::PROTOBUF_NAMESPACE_ID::internal::AssignDescriptors(
      &descriptor_table_Data_2fDataCommon_2eproto_getter, &descriptor_table_Data_2fDataCommon_2eproto_once,
      file_level_metadata_Data_2fDataCommon_2eproto[2]);
}

// @@protoc_insertion_point(namespace_scope)
}  // namespace Data
}  // namespace Proto
}  // namespace Zee
PROTOBUF_NAMESPACE_OPEN
template<> PROTOBUF_NOINLINE ::Zee::Proto::Data::Vector* Arena::CreateMaybeMessage< ::Zee::Proto::Data::Vector >(Arena* arena) {
  return Arena::CreateMessageInternal< ::Zee::Proto::Data::Vector >(arena);
}
template<> PROTOBUF_NOINLINE ::Zee::Proto::Data::Rotator* Arena::CreateMaybeMessage< ::Zee::Proto::Data::Rotator >(Arena* arena) {
  return Arena::CreateMessageInternal< ::Zee::Proto::Data::Rotator >(arena);
}
template<> PROTOBUF_NOINLINE ::Zee::Proto::Data::Position* Arena::CreateMaybeMessage< ::Zee::Proto::Data::Position >(Arena* arena) {
  return Arena::CreateMessageInternal< ::Zee::Proto::Data::Position >(arena);
}
PROTOBUF_NAMESPACE_CLOSE

// @@protoc_insertion_point(global_scope)
#include <google/protobuf/port_undef.inc>

