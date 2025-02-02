#pragma warning (disable : 4125)
// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: Data/DataCharacter.proto

#include "DataCharacter.pb.h"

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
constexpr Character::Character(
  ::PROTOBUF_NAMESPACE_ID::internal::ConstantInitialized)
  : name_(&::PROTOBUF_NAMESPACE_ID::internal::fixed_address_empty_string)
  , uid_(int64_t{0})
  , user_(int64_t{0})
  , id_(0)
  , slot_(0){}
struct CharacterDefaultTypeInternal {
  constexpr CharacterDefaultTypeInternal()
    : _instance(::PROTOBUF_NAMESPACE_ID::internal::ConstantInitialized{}) {}
  ~CharacterDefaultTypeInternal() {}
  union {
    Character _instance;
  };
};
PROTOBUF_ATTRIBUTE_NO_DESTROY PROTOBUF_CONSTINIT CharacterDefaultTypeInternal _Character_default_instance_;
}  // namespace Data
}  // namespace Proto
}  // namespace Zee
static ::PROTOBUF_NAMESPACE_ID::Metadata file_level_metadata_Data_2fDataCharacter_2eproto[1];
static constexpr ::PROTOBUF_NAMESPACE_ID::EnumDescriptor const** file_level_enum_descriptors_Data_2fDataCharacter_2eproto = nullptr;
static constexpr ::PROTOBUF_NAMESPACE_ID::ServiceDescriptor const** file_level_service_descriptors_Data_2fDataCharacter_2eproto = nullptr;

const ::PROTOBUF_NAMESPACE_ID::uint32 TableStruct_Data_2fDataCharacter_2eproto::offsets[] PROTOBUF_SECTION_VARIABLE(protodesc_cold) = {
  ~0u,  // no _has_bits_
  PROTOBUF_FIELD_OFFSET(::Zee::Proto::Data::Character, _internal_metadata_),
  ~0u,  // no _extensions_
  ~0u,  // no _oneof_case_
  ~0u,  // no _weak_field_map_
  ~0u,  // no _inlined_string_donated_
  PROTOBUF_FIELD_OFFSET(::Zee::Proto::Data::Character, uid_),
  PROTOBUF_FIELD_OFFSET(::Zee::Proto::Data::Character, user_),
  PROTOBUF_FIELD_OFFSET(::Zee::Proto::Data::Character, id_),
  PROTOBUF_FIELD_OFFSET(::Zee::Proto::Data::Character, slot_),
  PROTOBUF_FIELD_OFFSET(::Zee::Proto::Data::Character, name_),
};
static const ::PROTOBUF_NAMESPACE_ID::internal::MigrationSchema schemas[] PROTOBUF_SECTION_VARIABLE(protodesc_cold) = {
  { 0, -1, -1, sizeof(::Zee::Proto::Data::Character)},
};

static ::PROTOBUF_NAMESPACE_ID::Message const * const file_default_instances[] = {
  reinterpret_cast<const ::PROTOBUF_NAMESPACE_ID::Message*>(&::Zee::Proto::Data::_Character_default_instance_),
};

const char descriptor_table_protodef_Data_2fDataCharacter_2eproto[] PROTOBUF_SECTION_VARIABLE(protodesc_cold) =
  "\n\030Data/DataCharacter.proto\022\016Zee.Proto.Da"
  "ta\"N\n\tCharacter\022\013\n\003UID\030\001 \001(\003\022\014\n\004User\030\002 \001"
  "(\003\022\n\n\002Id\030\003 \001(\005\022\014\n\004Slot\030\004 \001(\005\022\014\n\004Name\030\005 \001"
  "(\tb\006proto3"
  ;
static ::PROTOBUF_NAMESPACE_ID::internal::once_flag descriptor_table_Data_2fDataCharacter_2eproto_once;
const ::PROTOBUF_NAMESPACE_ID::internal::DescriptorTable descriptor_table_Data_2fDataCharacter_2eproto = {
  false, false, 130, descriptor_table_protodef_Data_2fDataCharacter_2eproto, "Data/DataCharacter.proto", 
  &descriptor_table_Data_2fDataCharacter_2eproto_once, nullptr, 0, 1,
  schemas, file_default_instances, TableStruct_Data_2fDataCharacter_2eproto::offsets,
  file_level_metadata_Data_2fDataCharacter_2eproto, file_level_enum_descriptors_Data_2fDataCharacter_2eproto, file_level_service_descriptors_Data_2fDataCharacter_2eproto,
};
PROTOBUF_ATTRIBUTE_WEAK const ::PROTOBUF_NAMESPACE_ID::internal::DescriptorTable* descriptor_table_Data_2fDataCharacter_2eproto_getter() {
  return &descriptor_table_Data_2fDataCharacter_2eproto;
}

// Force running AddDescriptors() at dynamic initialization time.
PROTOBUF_ATTRIBUTE_INIT_PRIORITY static ::PROTOBUF_NAMESPACE_ID::internal::AddDescriptorsRunner dynamic_init_dummy_Data_2fDataCharacter_2eproto(&descriptor_table_Data_2fDataCharacter_2eproto);
namespace Zee {
namespace Proto {
namespace Data {

// ===================================================================

class Character::_Internal {
 public:
};

Character::Character(::PROTOBUF_NAMESPACE_ID::Arena* arena,
                         bool is_message_owned)
  : ::PROTOBUF_NAMESPACE_ID::Message(arena, is_message_owned) {
  SharedCtor();
  if (!is_message_owned) {
    RegisterArenaDtor(arena);
  }
  // @@protoc_insertion_point(arena_constructor:Zee.Proto.Data.Character)
}
Character::Character(const Character& from)
  : ::PROTOBUF_NAMESPACE_ID::Message() {
  _internal_metadata_.MergeFrom<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(from._internal_metadata_);
  name_.UnsafeSetDefault(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
  if (!from._internal_name().empty()) {
    name_.Set(::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr::EmptyDefault{}, from._internal_name(), 
      GetArenaForAllocation());
  }
  ::memcpy(&uid_, &from.uid_,
    static_cast<size_t>(reinterpret_cast<char*>(&slot_) -
    reinterpret_cast<char*>(&uid_)) + sizeof(slot_));
  // @@protoc_insertion_point(copy_constructor:Zee.Proto.Data.Character)
}

void Character::SharedCtor() {
name_.UnsafeSetDefault(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
::memset(reinterpret_cast<char*>(this) + static_cast<size_t>(
    reinterpret_cast<char*>(&uid_) - reinterpret_cast<char*>(this)),
    0, static_cast<size_t>(reinterpret_cast<char*>(&slot_) -
    reinterpret_cast<char*>(&uid_)) + sizeof(slot_));
}

Character::~Character() {
  // @@protoc_insertion_point(destructor:Zee.Proto.Data.Character)
  if (GetArenaForAllocation() != nullptr) return;
  SharedDtor();
  _internal_metadata_.Delete<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>();
}

inline void Character::SharedDtor() {
  GOOGLE_DCHECK(GetArenaForAllocation() == nullptr);
  name_.DestroyNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
}

void Character::ArenaDtor(void* object) {
  Character* _this = reinterpret_cast< Character* >(object);
  (void)_this;
}
void Character::RegisterArenaDtor(::PROTOBUF_NAMESPACE_ID::Arena*) {
}
void Character::SetCachedSize(int size) const {
  _cached_size_.Set(size);
}

void Character::Clear() {
// @@protoc_insertion_point(message_clear_start:Zee.Proto.Data.Character)
  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  name_.ClearToEmpty();
  ::memset(&uid_, 0, static_cast<size_t>(
      reinterpret_cast<char*>(&slot_) -
      reinterpret_cast<char*>(&uid_)) + sizeof(slot_));
  _internal_metadata_.Clear<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>();
}

const char* Character::_InternalParse(const char* ptr, ::PROTOBUF_NAMESPACE_ID::internal::ParseContext* ctx) {
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
      // int64 User = 2;
      case 2:
        if (PROTOBUF_PREDICT_TRUE(static_cast<::PROTOBUF_NAMESPACE_ID::uint8>(tag) == 16)) {
          user_ = ::PROTOBUF_NAMESPACE_ID::internal::ReadVarint64(&ptr);
          CHK_(ptr);
        } else
          goto handle_unusual;
        continue;
      // int32 Id = 3;
      case 3:
        if (PROTOBUF_PREDICT_TRUE(static_cast<::PROTOBUF_NAMESPACE_ID::uint8>(tag) == 24)) {
          id_ = ::PROTOBUF_NAMESPACE_ID::internal::ReadVarint64(&ptr);
          CHK_(ptr);
        } else
          goto handle_unusual;
        continue;
      // int32 Slot = 4;
      case 4:
        if (PROTOBUF_PREDICT_TRUE(static_cast<::PROTOBUF_NAMESPACE_ID::uint8>(tag) == 32)) {
          slot_ = ::PROTOBUF_NAMESPACE_ID::internal::ReadVarint64(&ptr);
          CHK_(ptr);
        } else
          goto handle_unusual;
        continue;
      // string Name = 5;
      case 5:
        if (PROTOBUF_PREDICT_TRUE(static_cast<::PROTOBUF_NAMESPACE_ID::uint8>(tag) == 42)) {
          auto str = _internal_mutable_name();
          ptr = ::PROTOBUF_NAMESPACE_ID::internal::InlineGreedyStringParser(str, ptr, ctx);
          CHK_(::PROTOBUF_NAMESPACE_ID::internal::VerifyUTF8(str, "Zee.Proto.Data.Character.Name"));
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

::PROTOBUF_NAMESPACE_ID::uint8* Character::_InternalSerialize(
    ::PROTOBUF_NAMESPACE_ID::uint8* target, ::PROTOBUF_NAMESPACE_ID::io::EpsCopyOutputStream* stream) const {
  // @@protoc_insertion_point(serialize_to_array_start:Zee.Proto.Data.Character)
  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  // int64 UID = 1;
  if (this->_internal_uid() != 0) {
    target = stream->EnsureSpace(target);
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::WriteInt64ToArray(1, this->_internal_uid(), target);
  }

  // int64 User = 2;
  if (this->_internal_user() != 0) {
    target = stream->EnsureSpace(target);
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::WriteInt64ToArray(2, this->_internal_user(), target);
  }

  // int32 Id = 3;
  if (this->_internal_id() != 0) {
    target = stream->EnsureSpace(target);
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::WriteInt32ToArray(3, this->_internal_id(), target);
  }

  // int32 Slot = 4;
  if (this->_internal_slot() != 0) {
    target = stream->EnsureSpace(target);
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::WriteInt32ToArray(4, this->_internal_slot(), target);
  }

  // string Name = 5;
  if (!this->_internal_name().empty()) {
    ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::VerifyUtf8String(
      this->_internal_name().data(), static_cast<int>(this->_internal_name().length()),
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::SERIALIZE,
      "Zee.Proto.Data.Character.Name");
    target = stream->WriteStringMaybeAliased(
        5, this->_internal_name(), target);
  }

  if (PROTOBUF_PREDICT_FALSE(_internal_metadata_.have_unknown_fields())) {
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormat::InternalSerializeUnknownFieldsToArray(
        _internal_metadata_.unknown_fields<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(::PROTOBUF_NAMESPACE_ID::UnknownFieldSet::default_instance), target, stream);
  }
  // @@protoc_insertion_point(serialize_to_array_end:Zee.Proto.Data.Character)
  return target;
}

size_t Character::ByteSizeLong() const {
// @@protoc_insertion_point(message_byte_size_start:Zee.Proto.Data.Character)
  size_t total_size = 0;

  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  // string Name = 5;
  if (!this->_internal_name().empty()) {
    total_size += 1 +
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::StringSize(
        this->_internal_name());
  }

  // int64 UID = 1;
  if (this->_internal_uid() != 0) {
    total_size += ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::Int64SizePlusOne(this->_internal_uid());
  }

  // int64 User = 2;
  if (this->_internal_user() != 0) {
    total_size += ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::Int64SizePlusOne(this->_internal_user());
  }

  // int32 Id = 3;
  if (this->_internal_id() != 0) {
    total_size += ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::Int32SizePlusOne(this->_internal_id());
  }

  // int32 Slot = 4;
  if (this->_internal_slot() != 0) {
    total_size += ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::Int32SizePlusOne(this->_internal_slot());
  }

  return MaybeComputeUnknownFieldsSize(total_size, &_cached_size_);
}

const ::PROTOBUF_NAMESPACE_ID::Message::ClassData Character::_class_data_ = {
    ::PROTOBUF_NAMESPACE_ID::Message::CopyWithSizeCheck,
    Character::MergeImpl
};
const ::PROTOBUF_NAMESPACE_ID::Message::ClassData*Character::GetClassData() const { return &_class_data_; }

void Character::MergeImpl(::PROTOBUF_NAMESPACE_ID::Message* to,
                      const ::PROTOBUF_NAMESPACE_ID::Message& from) {
  static_cast<Character *>(to)->MergeFrom(
      static_cast<const Character &>(from));
}


void Character::MergeFrom(const Character& from) {
// @@protoc_insertion_point(class_specific_merge_from_start:Zee.Proto.Data.Character)
  GOOGLE_DCHECK_NE(&from, this);
  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  if (!from._internal_name().empty()) {
    _internal_set_name(from._internal_name());
  }
  if (from._internal_uid() != 0) {
    _internal_set_uid(from._internal_uid());
  }
  if (from._internal_user() != 0) {
    _internal_set_user(from._internal_user());
  }
  if (from._internal_id() != 0) {
    _internal_set_id(from._internal_id());
  }
  if (from._internal_slot() != 0) {
    _internal_set_slot(from._internal_slot());
  }
  _internal_metadata_.MergeFrom<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(from._internal_metadata_);
}

void Character::CopyFrom(const Character& from) {
// @@protoc_insertion_point(class_specific_copy_from_start:Zee.Proto.Data.Character)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool Character::IsInitialized() const {
  return true;
}

void Character::InternalSwap(Character* other) {
  using std::swap;
  auto* lhs_arena = GetArenaForAllocation();
  auto* rhs_arena = other->GetArenaForAllocation();
  _internal_metadata_.InternalSwap(&other->_internal_metadata_);
  ::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr::InternalSwap(
      &::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(),
      &name_, lhs_arena,
      &other->name_, rhs_arena
  );
  ::PROTOBUF_NAMESPACE_ID::internal::memswap<
      PROTOBUF_FIELD_OFFSET(Character, slot_)
      + sizeof(Character::slot_)
      - PROTOBUF_FIELD_OFFSET(Character, uid_)>(
          reinterpret_cast<char*>(&uid_),
          reinterpret_cast<char*>(&other->uid_));
}

::PROTOBUF_NAMESPACE_ID::Metadata Character::GetMetadata() const {
  return ::PROTOBUF_NAMESPACE_ID::internal::AssignDescriptors(
      &descriptor_table_Data_2fDataCharacter_2eproto_getter, &descriptor_table_Data_2fDataCharacter_2eproto_once,
      file_level_metadata_Data_2fDataCharacter_2eproto[0]);
}

// @@protoc_insertion_point(namespace_scope)
}  // namespace Data
}  // namespace Proto
}  // namespace Zee
PROTOBUF_NAMESPACE_OPEN
template<> PROTOBUF_NOINLINE ::Zee::Proto::Data::Character* Arena::CreateMaybeMessage< ::Zee::Proto::Data::Character >(Arena* arena) {
  return Arena::CreateMessageInternal< ::Zee::Proto::Data::Character >(arena);
}
PROTOBUF_NAMESPACE_CLOSE

// @@protoc_insertion_point(global_scope)
#include <google/protobuf/port_undef.inc>

