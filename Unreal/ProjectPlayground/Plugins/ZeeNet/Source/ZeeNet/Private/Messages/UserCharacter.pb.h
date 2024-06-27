// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: UserCharacter.proto

#ifndef GOOGLE_PROTOBUF_INCLUDED_UserCharacter_2eproto
#define GOOGLE_PROTOBUF_INCLUDED_UserCharacter_2eproto

#include <limits>
#include <string>

#include <google/protobuf/port_def.inc>
#if PROTOBUF_VERSION < 3018000
#error This file was generated by a newer version of protoc which is
#error incompatible with your Protocol Buffer headers. Please update
#error your headers.
#endif
#if 3018000 < PROTOBUF_MIN_PROTOC_VERSION
#error This file was generated by an older version of protoc which is
#error incompatible with your Protocol Buffer headers. Please
#error regenerate this file with a newer version of protoc.
#endif

#include <google/protobuf/port_undef.inc>
#include <google/protobuf/io/coded_stream.h>
#include <google/protobuf/arena.h>
#include <google/protobuf/arenastring.h>
#include <google/protobuf/generated_message_table_driven.h>
#include <google/protobuf/generated_message_util.h>
#include <google/protobuf/metadata_lite.h>
#include <google/protobuf/generated_message_reflection.h>
#include <google/protobuf/message.h>
#include <google/protobuf/repeated_field.h>  // IWYU pragma: export
#include <google/protobuf/extension_set.h>  // IWYU pragma: export
#include <google/protobuf/generated_enum_reflection.h>
#include <google/protobuf/unknown_field_set.h>
#include "Data/DataCharacter.pb.h"
// @@protoc_insertion_point(includes)
#include <google/protobuf/port_def.inc>
#define PROTOBUF_INTERNAL_EXPORT_UserCharacter_2eproto
PROTOBUF_NAMESPACE_OPEN
namespace internal {
class AnyMetadata;
}  // namespace internal
PROTOBUF_NAMESPACE_CLOSE

// Internal implementation detail -- do not use these members.
struct TableStruct_UserCharacter_2eproto {
  static const ::PROTOBUF_NAMESPACE_ID::internal::ParseTableField entries[]
    PROTOBUF_SECTION_VARIABLE(protodesc_cold);
  static const ::PROTOBUF_NAMESPACE_ID::internal::AuxiliaryParseTableField aux[]
    PROTOBUF_SECTION_VARIABLE(protodesc_cold);
  static const ::PROTOBUF_NAMESPACE_ID::internal::ParseTable schema[3]
    PROTOBUF_SECTION_VARIABLE(protodesc_cold);
  static const ::PROTOBUF_NAMESPACE_ID::internal::FieldMetadata field_metadata[];
  static const ::PROTOBUF_NAMESPACE_ID::internal::SerializationTable serialization_table[];
  static const ::PROTOBUF_NAMESPACE_ID::uint32 offsets[];
};
extern const ::PROTOBUF_NAMESPACE_ID::internal::DescriptorTable descriptor_table_UserCharacter_2eproto;
namespace Zee {
namespace Proto {
namespace UserCharacter {
class Create;
struct CreateDefaultTypeInternal;
extern CreateDefaultTypeInternal _Create_default_instance_;
class Get;
struct GetDefaultTypeInternal;
extern GetDefaultTypeInternal _Get_default_instance_;
class Select;
struct SelectDefaultTypeInternal;
extern SelectDefaultTypeInternal _Select_default_instance_;
}  // namespace UserCharacter
}  // namespace Proto
}  // namespace Zee
PROTOBUF_NAMESPACE_OPEN
template<> ::Zee::Proto::UserCharacter::Create* Arena::CreateMaybeMessage<::Zee::Proto::UserCharacter::Create>(Arena*);
template<> ::Zee::Proto::UserCharacter::Get* Arena::CreateMaybeMessage<::Zee::Proto::UserCharacter::Get>(Arena*);
template<> ::Zee::Proto::UserCharacter::Select* Arena::CreateMaybeMessage<::Zee::Proto::UserCharacter::Select>(Arena*);
PROTOBUF_NAMESPACE_CLOSE
namespace Zee {
namespace Proto {
namespace UserCharacter {

enum ReturnCode : int {
  RC_SUCCESS = 0,
  RC_FAILED_UNKNOWN = 1,
  RC_FAILED_CREATE_DUPLICATED_NAME = 2,
  ReturnCode_INT_MIN_SENTINEL_DO_NOT_USE_ = std::numeric_limits<::PROTOBUF_NAMESPACE_ID::int32>::min(),
  ReturnCode_INT_MAX_SENTINEL_DO_NOT_USE_ = std::numeric_limits<::PROTOBUF_NAMESPACE_ID::int32>::max()
};
bool ReturnCode_IsValid(int value);
constexpr ReturnCode ReturnCode_MIN = RC_SUCCESS;
constexpr ReturnCode ReturnCode_MAX = RC_FAILED_CREATE_DUPLICATED_NAME;
constexpr int ReturnCode_ARRAYSIZE = ReturnCode_MAX + 1;

const ::PROTOBUF_NAMESPACE_ID::EnumDescriptor* ReturnCode_descriptor();
template<typename T>
inline const std::string& ReturnCode_Name(T enum_t_value) {
  static_assert(::std::is_same<T, ReturnCode>::value ||
    ::std::is_integral<T>::value,
    "Incorrect type passed to function ReturnCode_Name.");
  return ::PROTOBUF_NAMESPACE_ID::internal::NameOfEnum(
    ReturnCode_descriptor(), enum_t_value);
}
inline bool ReturnCode_Parse(
    ::PROTOBUF_NAMESPACE_ID::ConstStringParam name, ReturnCode* value) {
  return ::PROTOBUF_NAMESPACE_ID::internal::ParseNamedEnum<ReturnCode>(
    ReturnCode_descriptor(), name, value);
}
// ===================================================================

class Create final :
    public ::PROTOBUF_NAMESPACE_ID::Message /* @@protoc_insertion_point(class_definition:Zee.Proto.UserCharacter.Create) */ {
 public:
  inline Create() : Create(nullptr) {}
  ~Create() override;
  explicit constexpr Create(::PROTOBUF_NAMESPACE_ID::internal::ConstantInitialized);

  Create(const Create& from);
  Create(Create&& from) noexcept
    : Create() {
    *this = ::std::move(from);
  }

  inline Create& operator=(const Create& from) {
    CopyFrom(from);
    return *this;
  }
  inline Create& operator=(Create&& from) noexcept {
    if (this == &from) return *this;
    if (GetOwningArena() == from.GetOwningArena()
  #ifdef PROTOBUF_FORCE_COPY_IN_MOVE
        && GetOwningArena() != nullptr
  #endif  // !PROTOBUF_FORCE_COPY_IN_MOVE
    ) {
      InternalSwap(&from);
    } else {
      CopyFrom(from);
    }
    return *this;
  }

  static const ::PROTOBUF_NAMESPACE_ID::Descriptor* descriptor() {
    return GetDescriptor();
  }
  static const ::PROTOBUF_NAMESPACE_ID::Descriptor* GetDescriptor() {
    return default_instance().GetMetadata().descriptor;
  }
  static const ::PROTOBUF_NAMESPACE_ID::Reflection* GetReflection() {
    return default_instance().GetMetadata().reflection;
  }
  static const Create& default_instance() {
    return *internal_default_instance();
  }
  static inline const Create* internal_default_instance() {
    return reinterpret_cast<const Create*>(
               &_Create_default_instance_);
  }
  static constexpr int kIndexInFileMessages =
    0;

  friend void swap(Create& a, Create& b) {
    a.Swap(&b);
  }
  inline void Swap(Create* other) {
    if (other == this) return;
    if (GetOwningArena() == other->GetOwningArena()) {
      InternalSwap(other);
    } else {
      ::PROTOBUF_NAMESPACE_ID::internal::GenericSwap(this, other);
    }
  }
  void UnsafeArenaSwap(Create* other) {
    if (other == this) return;
    GOOGLE_DCHECK(GetOwningArena() == other->GetOwningArena());
    InternalSwap(other);
  }

  // implements Message ----------------------------------------------

  inline Create* New() const final {
    return new Create();
  }

  Create* New(::PROTOBUF_NAMESPACE_ID::Arena* arena) const final {
    return CreateMaybeMessage<Create>(arena);
  }
  using ::PROTOBUF_NAMESPACE_ID::Message::CopyFrom;
  void CopyFrom(const Create& from);
  using ::PROTOBUF_NAMESPACE_ID::Message::MergeFrom;
  void MergeFrom(const Create& from);
  private:
  static void MergeImpl(::PROTOBUF_NAMESPACE_ID::Message* to, const ::PROTOBUF_NAMESPACE_ID::Message& from);
  public:
  PROTOBUF_ATTRIBUTE_REINITIALIZES void Clear() final;
  bool IsInitialized() const final;

  size_t ByteSizeLong() const final;
  const char* _InternalParse(const char* ptr, ::PROTOBUF_NAMESPACE_ID::internal::ParseContext* ctx) final;
  ::PROTOBUF_NAMESPACE_ID::uint8* _InternalSerialize(
      ::PROTOBUF_NAMESPACE_ID::uint8* target, ::PROTOBUF_NAMESPACE_ID::io::EpsCopyOutputStream* stream) const final;
  int GetCachedSize() const final { return _cached_size_.Get(); }

  private:
  void SharedCtor();
  void SharedDtor();
  void SetCachedSize(int size) const final;
  void InternalSwap(Create* other);
  friend class ::PROTOBUF_NAMESPACE_ID::internal::AnyMetadata;
  static ::PROTOBUF_NAMESPACE_ID::StringPiece FullMessageName() {
    return "Zee.Proto.UserCharacter.Create";
  }
  protected:
  explicit Create(::PROTOBUF_NAMESPACE_ID::Arena* arena,
                       bool is_message_owned = false);
  private:
  static void ArenaDtor(void* object);
  inline void RegisterArenaDtor(::PROTOBUF_NAMESPACE_ID::Arena* arena);
  public:

  static const ClassData _class_data_;
  const ::PROTOBUF_NAMESPACE_ID::Message::ClassData*GetClassData() const final;

  ::PROTOBUF_NAMESPACE_ID::Metadata GetMetadata() const final;

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  enum : int {
    kCharacterFieldNumber = 2,
    kRCFieldNumber = 1,
  };
  // .Zee.Proto.Data.Character Character = 2;
  bool has_character() const;
  private:
  bool _internal_has_character() const;
  public:
  void clear_character();
  const ::Zee::Proto::Data::Character& character() const;
  PROTOBUF_MUST_USE_RESULT ::Zee::Proto::Data::Character* release_character();
  ::Zee::Proto::Data::Character* mutable_character();
  void set_allocated_character(::Zee::Proto::Data::Character* character);
  private:
  const ::Zee::Proto::Data::Character& _internal_character() const;
  ::Zee::Proto::Data::Character* _internal_mutable_character();
  public:
  void unsafe_arena_set_allocated_character(
      ::Zee::Proto::Data::Character* character);
  ::Zee::Proto::Data::Character* unsafe_arena_release_character();

  // .Zee.Proto.UserCharacter.ReturnCode RC = 1;
  void clear_rc();
  ::Zee::Proto::UserCharacter::ReturnCode rc() const;
  void set_rc(::Zee::Proto::UserCharacter::ReturnCode value);
  private:
  ::Zee::Proto::UserCharacter::ReturnCode _internal_rc() const;
  void _internal_set_rc(::Zee::Proto::UserCharacter::ReturnCode value);
  public:

  // @@protoc_insertion_point(class_scope:Zee.Proto.UserCharacter.Create)
 private:
  class _Internal;

  template <typename T> friend class ::PROTOBUF_NAMESPACE_ID::Arena::InternalHelper;
  typedef void InternalArenaConstructable_;
  typedef void DestructorSkippable_;
  ::Zee::Proto::Data::Character* character_;
  int rc_;
  mutable ::PROTOBUF_NAMESPACE_ID::internal::CachedSize _cached_size_;
  friend struct ::TableStruct_UserCharacter_2eproto;
};
// -------------------------------------------------------------------

class Get final :
    public ::PROTOBUF_NAMESPACE_ID::Message /* @@protoc_insertion_point(class_definition:Zee.Proto.UserCharacter.Get) */ {
 public:
  inline Get() : Get(nullptr) {}
  ~Get() override;
  explicit constexpr Get(::PROTOBUF_NAMESPACE_ID::internal::ConstantInitialized);

  Get(const Get& from);
  Get(Get&& from) noexcept
    : Get() {
    *this = ::std::move(from);
  }

  inline Get& operator=(const Get& from) {
    CopyFrom(from);
    return *this;
  }
  inline Get& operator=(Get&& from) noexcept {
    if (this == &from) return *this;
    if (GetOwningArena() == from.GetOwningArena()
  #ifdef PROTOBUF_FORCE_COPY_IN_MOVE
        && GetOwningArena() != nullptr
  #endif  // !PROTOBUF_FORCE_COPY_IN_MOVE
    ) {
      InternalSwap(&from);
    } else {
      CopyFrom(from);
    }
    return *this;
  }

  static const ::PROTOBUF_NAMESPACE_ID::Descriptor* descriptor() {
    return GetDescriptor();
  }
  static const ::PROTOBUF_NAMESPACE_ID::Descriptor* GetDescriptor() {
    return default_instance().GetMetadata().descriptor;
  }
  static const ::PROTOBUF_NAMESPACE_ID::Reflection* GetReflection() {
    return default_instance().GetMetadata().reflection;
  }
  static const Get& default_instance() {
    return *internal_default_instance();
  }
  static inline const Get* internal_default_instance() {
    return reinterpret_cast<const Get*>(
               &_Get_default_instance_);
  }
  static constexpr int kIndexInFileMessages =
    1;

  friend void swap(Get& a, Get& b) {
    a.Swap(&b);
  }
  inline void Swap(Get* other) {
    if (other == this) return;
    if (GetOwningArena() == other->GetOwningArena()) {
      InternalSwap(other);
    } else {
      ::PROTOBUF_NAMESPACE_ID::internal::GenericSwap(this, other);
    }
  }
  void UnsafeArenaSwap(Get* other) {
    if (other == this) return;
    GOOGLE_DCHECK(GetOwningArena() == other->GetOwningArena());
    InternalSwap(other);
  }

  // implements Message ----------------------------------------------

  inline Get* New() const final {
    return new Get();
  }

  Get* New(::PROTOBUF_NAMESPACE_ID::Arena* arena) const final {
    return CreateMaybeMessage<Get>(arena);
  }
  using ::PROTOBUF_NAMESPACE_ID::Message::CopyFrom;
  void CopyFrom(const Get& from);
  using ::PROTOBUF_NAMESPACE_ID::Message::MergeFrom;
  void MergeFrom(const Get& from);
  private:
  static void MergeImpl(::PROTOBUF_NAMESPACE_ID::Message* to, const ::PROTOBUF_NAMESPACE_ID::Message& from);
  public:
  PROTOBUF_ATTRIBUTE_REINITIALIZES void Clear() final;
  bool IsInitialized() const final;

  size_t ByteSizeLong() const final;
  const char* _InternalParse(const char* ptr, ::PROTOBUF_NAMESPACE_ID::internal::ParseContext* ctx) final;
  ::PROTOBUF_NAMESPACE_ID::uint8* _InternalSerialize(
      ::PROTOBUF_NAMESPACE_ID::uint8* target, ::PROTOBUF_NAMESPACE_ID::io::EpsCopyOutputStream* stream) const final;
  int GetCachedSize() const final { return _cached_size_.Get(); }

  private:
  void SharedCtor();
  void SharedDtor();
  void SetCachedSize(int size) const final;
  void InternalSwap(Get* other);
  friend class ::PROTOBUF_NAMESPACE_ID::internal::AnyMetadata;
  static ::PROTOBUF_NAMESPACE_ID::StringPiece FullMessageName() {
    return "Zee.Proto.UserCharacter.Get";
  }
  protected:
  explicit Get(::PROTOBUF_NAMESPACE_ID::Arena* arena,
                       bool is_message_owned = false);
  private:
  static void ArenaDtor(void* object);
  inline void RegisterArenaDtor(::PROTOBUF_NAMESPACE_ID::Arena* arena);
  public:

  static const ClassData _class_data_;
  const ::PROTOBUF_NAMESPACE_ID::Message::ClassData*GetClassData() const final;

  ::PROTOBUF_NAMESPACE_ID::Metadata GetMetadata() const final;

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  enum : int {
    kCharactersFieldNumber = 3,
    kUserFieldNumber = 2,
    kRCFieldNumber = 1,
  };
  // repeated .Zee.Proto.Data.Character Characters = 3;
  int characters_size() const;
  private:
  int _internal_characters_size() const;
  public:
  void clear_characters();
  ::Zee::Proto::Data::Character* mutable_characters(int index);
  ::PROTOBUF_NAMESPACE_ID::RepeatedPtrField< ::Zee::Proto::Data::Character >*
      mutable_characters();
  private:
  const ::Zee::Proto::Data::Character& _internal_characters(int index) const;
  ::Zee::Proto::Data::Character* _internal_add_characters();
  public:
  const ::Zee::Proto::Data::Character& characters(int index) const;
  ::Zee::Proto::Data::Character* add_characters();
  const ::PROTOBUF_NAMESPACE_ID::RepeatedPtrField< ::Zee::Proto::Data::Character >&
      characters() const;

  // int64 User = 2;
  void clear_user();
  ::PROTOBUF_NAMESPACE_ID::int64 user() const;
  void set_user(::PROTOBUF_NAMESPACE_ID::int64 value);
  private:
  ::PROTOBUF_NAMESPACE_ID::int64 _internal_user() const;
  void _internal_set_user(::PROTOBUF_NAMESPACE_ID::int64 value);
  public:

  // .Zee.Proto.UserCharacter.ReturnCode RC = 1;
  void clear_rc();
  ::Zee::Proto::UserCharacter::ReturnCode rc() const;
  void set_rc(::Zee::Proto::UserCharacter::ReturnCode value);
  private:
  ::Zee::Proto::UserCharacter::ReturnCode _internal_rc() const;
  void _internal_set_rc(::Zee::Proto::UserCharacter::ReturnCode value);
  public:

  // @@protoc_insertion_point(class_scope:Zee.Proto.UserCharacter.Get)
 private:
  class _Internal;

  template <typename T> friend class ::PROTOBUF_NAMESPACE_ID::Arena::InternalHelper;
  typedef void InternalArenaConstructable_;
  typedef void DestructorSkippable_;
  ::PROTOBUF_NAMESPACE_ID::RepeatedPtrField< ::Zee::Proto::Data::Character > characters_;
  ::PROTOBUF_NAMESPACE_ID::int64 user_;
  int rc_;
  mutable ::PROTOBUF_NAMESPACE_ID::internal::CachedSize _cached_size_;
  friend struct ::TableStruct_UserCharacter_2eproto;
};
// -------------------------------------------------------------------

class Select final :
    public ::PROTOBUF_NAMESPACE_ID::Message /* @@protoc_insertion_point(class_definition:Zee.Proto.UserCharacter.Select) */ {
 public:
  inline Select() : Select(nullptr) {}
  ~Select() override;
  explicit constexpr Select(::PROTOBUF_NAMESPACE_ID::internal::ConstantInitialized);

  Select(const Select& from);
  Select(Select&& from) noexcept
    : Select() {
    *this = ::std::move(from);
  }

  inline Select& operator=(const Select& from) {
    CopyFrom(from);
    return *this;
  }
  inline Select& operator=(Select&& from) noexcept {
    if (this == &from) return *this;
    if (GetOwningArena() == from.GetOwningArena()
  #ifdef PROTOBUF_FORCE_COPY_IN_MOVE
        && GetOwningArena() != nullptr
  #endif  // !PROTOBUF_FORCE_COPY_IN_MOVE
    ) {
      InternalSwap(&from);
    } else {
      CopyFrom(from);
    }
    return *this;
  }

  static const ::PROTOBUF_NAMESPACE_ID::Descriptor* descriptor() {
    return GetDescriptor();
  }
  static const ::PROTOBUF_NAMESPACE_ID::Descriptor* GetDescriptor() {
    return default_instance().GetMetadata().descriptor;
  }
  static const ::PROTOBUF_NAMESPACE_ID::Reflection* GetReflection() {
    return default_instance().GetMetadata().reflection;
  }
  static const Select& default_instance() {
    return *internal_default_instance();
  }
  static inline const Select* internal_default_instance() {
    return reinterpret_cast<const Select*>(
               &_Select_default_instance_);
  }
  static constexpr int kIndexInFileMessages =
    2;

  friend void swap(Select& a, Select& b) {
    a.Swap(&b);
  }
  inline void Swap(Select* other) {
    if (other == this) return;
    if (GetOwningArena() == other->GetOwningArena()) {
      InternalSwap(other);
    } else {
      ::PROTOBUF_NAMESPACE_ID::internal::GenericSwap(this, other);
    }
  }
  void UnsafeArenaSwap(Select* other) {
    if (other == this) return;
    GOOGLE_DCHECK(GetOwningArena() == other->GetOwningArena());
    InternalSwap(other);
  }

  // implements Message ----------------------------------------------

  inline Select* New() const final {
    return new Select();
  }

  Select* New(::PROTOBUF_NAMESPACE_ID::Arena* arena) const final {
    return CreateMaybeMessage<Select>(arena);
  }
  using ::PROTOBUF_NAMESPACE_ID::Message::CopyFrom;
  void CopyFrom(const Select& from);
  using ::PROTOBUF_NAMESPACE_ID::Message::MergeFrom;
  void MergeFrom(const Select& from);
  private:
  static void MergeImpl(::PROTOBUF_NAMESPACE_ID::Message* to, const ::PROTOBUF_NAMESPACE_ID::Message& from);
  public:
  PROTOBUF_ATTRIBUTE_REINITIALIZES void Clear() final;
  bool IsInitialized() const final;

  size_t ByteSizeLong() const final;
  const char* _InternalParse(const char* ptr, ::PROTOBUF_NAMESPACE_ID::internal::ParseContext* ctx) final;
  ::PROTOBUF_NAMESPACE_ID::uint8* _InternalSerialize(
      ::PROTOBUF_NAMESPACE_ID::uint8* target, ::PROTOBUF_NAMESPACE_ID::io::EpsCopyOutputStream* stream) const final;
  int GetCachedSize() const final { return _cached_size_.Get(); }

  private:
  void SharedCtor();
  void SharedDtor();
  void SetCachedSize(int size) const final;
  void InternalSwap(Select* other);
  friend class ::PROTOBUF_NAMESPACE_ID::internal::AnyMetadata;
  static ::PROTOBUF_NAMESPACE_ID::StringPiece FullMessageName() {
    return "Zee.Proto.UserCharacter.Select";
  }
  protected:
  explicit Select(::PROTOBUF_NAMESPACE_ID::Arena* arena,
                       bool is_message_owned = false);
  private:
  static void ArenaDtor(void* object);
  inline void RegisterArenaDtor(::PROTOBUF_NAMESPACE_ID::Arena* arena);
  public:

  static const ClassData _class_data_;
  const ::PROTOBUF_NAMESPACE_ID::Message::ClassData*GetClassData() const final;

  ::PROTOBUF_NAMESPACE_ID::Metadata GetMetadata() const final;

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  enum : int {
    kNameFieldNumber = 4,
    kUIDFieldNumber = 2,
    kRCFieldNumber = 1,
    kIdFieldNumber = 3,
  };
  // string Name = 4;
  void clear_name();
  const std::string& name() const;
  template <typename ArgT0 = const std::string&, typename... ArgT>
  void set_name(ArgT0&& arg0, ArgT... args);
  std::string* mutable_name();
  PROTOBUF_MUST_USE_RESULT std::string* release_name();
  void set_allocated_name(std::string* name);
  private:
  const std::string& _internal_name() const;
  inline PROTOBUF_ALWAYS_INLINE void _internal_set_name(const std::string& value);
  std::string* _internal_mutable_name();
  public:

  // int64 UID = 2;
  void clear_uid();
  ::PROTOBUF_NAMESPACE_ID::int64 uid() const;
  void set_uid(::PROTOBUF_NAMESPACE_ID::int64 value);
  private:
  ::PROTOBUF_NAMESPACE_ID::int64 _internal_uid() const;
  void _internal_set_uid(::PROTOBUF_NAMESPACE_ID::int64 value);
  public:

  // .Zee.Proto.UserCharacter.ReturnCode RC = 1;
  void clear_rc();
  ::Zee::Proto::UserCharacter::ReturnCode rc() const;
  void set_rc(::Zee::Proto::UserCharacter::ReturnCode value);
  private:
  ::Zee::Proto::UserCharacter::ReturnCode _internal_rc() const;
  void _internal_set_rc(::Zee::Proto::UserCharacter::ReturnCode value);
  public:

  // int32 Id = 3;
  void clear_id();
  ::PROTOBUF_NAMESPACE_ID::int32 id() const;
  void set_id(::PROTOBUF_NAMESPACE_ID::int32 value);
  private:
  ::PROTOBUF_NAMESPACE_ID::int32 _internal_id() const;
  void _internal_set_id(::PROTOBUF_NAMESPACE_ID::int32 value);
  public:

  // @@protoc_insertion_point(class_scope:Zee.Proto.UserCharacter.Select)
 private:
  class _Internal;

  template <typename T> friend class ::PROTOBUF_NAMESPACE_ID::Arena::InternalHelper;
  typedef void InternalArenaConstructable_;
  typedef void DestructorSkippable_;
  ::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr name_;
  ::PROTOBUF_NAMESPACE_ID::int64 uid_;
  int rc_;
  ::PROTOBUF_NAMESPACE_ID::int32 id_;
  mutable ::PROTOBUF_NAMESPACE_ID::internal::CachedSize _cached_size_;
  friend struct ::TableStruct_UserCharacter_2eproto;
};
// ===================================================================


// ===================================================================

#ifdef __GNUC__
  #pragma GCC diagnostic push
  #pragma GCC diagnostic ignored "-Wstrict-aliasing"
#endif  // __GNUC__
// Create

// .Zee.Proto.UserCharacter.ReturnCode RC = 1;
inline void Create::clear_rc() {
  rc_ = 0;
}
inline ::Zee::Proto::UserCharacter::ReturnCode Create::_internal_rc() const {
  return static_cast< ::Zee::Proto::UserCharacter::ReturnCode >(rc_);
}
inline ::Zee::Proto::UserCharacter::ReturnCode Create::rc() const {
  // @@protoc_insertion_point(field_get:Zee.Proto.UserCharacter.Create.RC)
  return _internal_rc();
}
inline void Create::_internal_set_rc(::Zee::Proto::UserCharacter::ReturnCode value) {
  
  rc_ = value;
}
inline void Create::set_rc(::Zee::Proto::UserCharacter::ReturnCode value) {
  _internal_set_rc(value);
  // @@protoc_insertion_point(field_set:Zee.Proto.UserCharacter.Create.RC)
}

// .Zee.Proto.Data.Character Character = 2;
inline bool Create::_internal_has_character() const {
  return this != internal_default_instance() && character_ != nullptr;
}
inline bool Create::has_character() const {
  return _internal_has_character();
}
inline const ::Zee::Proto::Data::Character& Create::_internal_character() const {
  const ::Zee::Proto::Data::Character* p = character_;
  return p != nullptr ? *p : reinterpret_cast<const ::Zee::Proto::Data::Character&>(
      ::Zee::Proto::Data::_Character_default_instance_);
}
inline const ::Zee::Proto::Data::Character& Create::character() const {
  // @@protoc_insertion_point(field_get:Zee.Proto.UserCharacter.Create.Character)
  return _internal_character();
}
inline void Create::unsafe_arena_set_allocated_character(
    ::Zee::Proto::Data::Character* character) {
  if (GetArenaForAllocation() == nullptr) {
    delete reinterpret_cast<::PROTOBUF_NAMESPACE_ID::MessageLite*>(character_);
  }
  character_ = character;
  if (character) {
    
  } else {
    
  }
  // @@protoc_insertion_point(field_unsafe_arena_set_allocated:Zee.Proto.UserCharacter.Create.Character)
}
inline ::Zee::Proto::Data::Character* Create::release_character() {
  
  ::Zee::Proto::Data::Character* temp = character_;
  character_ = nullptr;
#ifdef PROTOBUF_FORCE_COPY_IN_RELEASE
  auto* old =  reinterpret_cast<::PROTOBUF_NAMESPACE_ID::MessageLite*>(temp);
  temp = ::PROTOBUF_NAMESPACE_ID::internal::DuplicateIfNonNull(temp);
  if (GetArenaForAllocation() == nullptr) { delete old; }
#else  // PROTOBUF_FORCE_COPY_IN_RELEASE
  if (GetArenaForAllocation() != nullptr) {
    temp = ::PROTOBUF_NAMESPACE_ID::internal::DuplicateIfNonNull(temp);
  }
#endif  // !PROTOBUF_FORCE_COPY_IN_RELEASE
  return temp;
}
inline ::Zee::Proto::Data::Character* Create::unsafe_arena_release_character() {
  // @@protoc_insertion_point(field_release:Zee.Proto.UserCharacter.Create.Character)
  
  ::Zee::Proto::Data::Character* temp = character_;
  character_ = nullptr;
  return temp;
}
inline ::Zee::Proto::Data::Character* Create::_internal_mutable_character() {
  
  if (character_ == nullptr) {
    auto* p = CreateMaybeMessage<::Zee::Proto::Data::Character>(GetArenaForAllocation());
    character_ = p;
  }
  return character_;
}
inline ::Zee::Proto::Data::Character* Create::mutable_character() {
  ::Zee::Proto::Data::Character* _msg = _internal_mutable_character();
  // @@protoc_insertion_point(field_mutable:Zee.Proto.UserCharacter.Create.Character)
  return _msg;
}
inline void Create::set_allocated_character(::Zee::Proto::Data::Character* character) {
  ::PROTOBUF_NAMESPACE_ID::Arena* message_arena = GetArenaForAllocation();
  if (message_arena == nullptr) {
    delete reinterpret_cast< ::PROTOBUF_NAMESPACE_ID::MessageLite*>(character_);
  }
  if (character) {
    ::PROTOBUF_NAMESPACE_ID::Arena* submessage_arena =
        ::PROTOBUF_NAMESPACE_ID::Arena::InternalHelper<
            ::PROTOBUF_NAMESPACE_ID::MessageLite>::GetOwningArena(
                reinterpret_cast<::PROTOBUF_NAMESPACE_ID::MessageLite*>(character));
    if (message_arena != submessage_arena) {
      character = ::PROTOBUF_NAMESPACE_ID::internal::GetOwnedMessage(
          message_arena, character, submessage_arena);
    }
    
  } else {
    
  }
  character_ = character;
  // @@protoc_insertion_point(field_set_allocated:Zee.Proto.UserCharacter.Create.Character)
}

// -------------------------------------------------------------------

// Get

// .Zee.Proto.UserCharacter.ReturnCode RC = 1;
inline void Get::clear_rc() {
  rc_ = 0;
}
inline ::Zee::Proto::UserCharacter::ReturnCode Get::_internal_rc() const {
  return static_cast< ::Zee::Proto::UserCharacter::ReturnCode >(rc_);
}
inline ::Zee::Proto::UserCharacter::ReturnCode Get::rc() const {
  // @@protoc_insertion_point(field_get:Zee.Proto.UserCharacter.Get.RC)
  return _internal_rc();
}
inline void Get::_internal_set_rc(::Zee::Proto::UserCharacter::ReturnCode value) {
  
  rc_ = value;
}
inline void Get::set_rc(::Zee::Proto::UserCharacter::ReturnCode value) {
  _internal_set_rc(value);
  // @@protoc_insertion_point(field_set:Zee.Proto.UserCharacter.Get.RC)
}

// int64 User = 2;
inline void Get::clear_user() {
  user_ = int64_t{0};
}
inline ::PROTOBUF_NAMESPACE_ID::int64 Get::_internal_user() const {
  return user_;
}
inline ::PROTOBUF_NAMESPACE_ID::int64 Get::user() const {
  // @@protoc_insertion_point(field_get:Zee.Proto.UserCharacter.Get.User)
  return _internal_user();
}
inline void Get::_internal_set_user(::PROTOBUF_NAMESPACE_ID::int64 value) {
  
  user_ = value;
}
inline void Get::set_user(::PROTOBUF_NAMESPACE_ID::int64 value) {
  _internal_set_user(value);
  // @@protoc_insertion_point(field_set:Zee.Proto.UserCharacter.Get.User)
}

// repeated .Zee.Proto.Data.Character Characters = 3;
inline int Get::_internal_characters_size() const {
  return characters_.size();
}
inline int Get::characters_size() const {
  return _internal_characters_size();
}
inline ::Zee::Proto::Data::Character* Get::mutable_characters(int index) {
  // @@protoc_insertion_point(field_mutable:Zee.Proto.UserCharacter.Get.Characters)
  return characters_.Mutable(index);
}
inline ::PROTOBUF_NAMESPACE_ID::RepeatedPtrField< ::Zee::Proto::Data::Character >*
Get::mutable_characters() {
  // @@protoc_insertion_point(field_mutable_list:Zee.Proto.UserCharacter.Get.Characters)
  return &characters_;
}
inline const ::Zee::Proto::Data::Character& Get::_internal_characters(int index) const {
  return characters_.Get(index);
}
inline const ::Zee::Proto::Data::Character& Get::characters(int index) const {
  // @@protoc_insertion_point(field_get:Zee.Proto.UserCharacter.Get.Characters)
  return _internal_characters(index);
}
inline ::Zee::Proto::Data::Character* Get::_internal_add_characters() {
  return characters_.Add();
}
inline ::Zee::Proto::Data::Character* Get::add_characters() {
  ::Zee::Proto::Data::Character* _add = _internal_add_characters();
  // @@protoc_insertion_point(field_add:Zee.Proto.UserCharacter.Get.Characters)
  return _add;
}
inline const ::PROTOBUF_NAMESPACE_ID::RepeatedPtrField< ::Zee::Proto::Data::Character >&
Get::characters() const {
  // @@protoc_insertion_point(field_list:Zee.Proto.UserCharacter.Get.Characters)
  return characters_;
}

// -------------------------------------------------------------------

// Select

// .Zee.Proto.UserCharacter.ReturnCode RC = 1;
inline void Select::clear_rc() {
  rc_ = 0;
}
inline ::Zee::Proto::UserCharacter::ReturnCode Select::_internal_rc() const {
  return static_cast< ::Zee::Proto::UserCharacter::ReturnCode >(rc_);
}
inline ::Zee::Proto::UserCharacter::ReturnCode Select::rc() const {
  // @@protoc_insertion_point(field_get:Zee.Proto.UserCharacter.Select.RC)
  return _internal_rc();
}
inline void Select::_internal_set_rc(::Zee::Proto::UserCharacter::ReturnCode value) {
  
  rc_ = value;
}
inline void Select::set_rc(::Zee::Proto::UserCharacter::ReturnCode value) {
  _internal_set_rc(value);
  // @@protoc_insertion_point(field_set:Zee.Proto.UserCharacter.Select.RC)
}

// int64 UID = 2;
inline void Select::clear_uid() {
  uid_ = int64_t{0};
}
inline ::PROTOBUF_NAMESPACE_ID::int64 Select::_internal_uid() const {
  return uid_;
}
inline ::PROTOBUF_NAMESPACE_ID::int64 Select::uid() const {
  // @@protoc_insertion_point(field_get:Zee.Proto.UserCharacter.Select.UID)
  return _internal_uid();
}
inline void Select::_internal_set_uid(::PROTOBUF_NAMESPACE_ID::int64 value) {
  
  uid_ = value;
}
inline void Select::set_uid(::PROTOBUF_NAMESPACE_ID::int64 value) {
  _internal_set_uid(value);
  // @@protoc_insertion_point(field_set:Zee.Proto.UserCharacter.Select.UID)
}

// int32 Id = 3;
inline void Select::clear_id() {
  id_ = 0;
}
inline ::PROTOBUF_NAMESPACE_ID::int32 Select::_internal_id() const {
  return id_;
}
inline ::PROTOBUF_NAMESPACE_ID::int32 Select::id() const {
  // @@protoc_insertion_point(field_get:Zee.Proto.UserCharacter.Select.Id)
  return _internal_id();
}
inline void Select::_internal_set_id(::PROTOBUF_NAMESPACE_ID::int32 value) {
  
  id_ = value;
}
inline void Select::set_id(::PROTOBUF_NAMESPACE_ID::int32 value) {
  _internal_set_id(value);
  // @@protoc_insertion_point(field_set:Zee.Proto.UserCharacter.Select.Id)
}

// string Name = 4;
inline void Select::clear_name() {
  name_.ClearToEmpty();
}
inline const std::string& Select::name() const {
  // @@protoc_insertion_point(field_get:Zee.Proto.UserCharacter.Select.Name)
  return _internal_name();
}
template <typename ArgT0, typename... ArgT>
inline PROTOBUF_ALWAYS_INLINE
void Select::set_name(ArgT0&& arg0, ArgT... args) {
 
 name_.Set(::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr::EmptyDefault{}, static_cast<ArgT0 &&>(arg0), args..., GetArenaForAllocation());
  // @@protoc_insertion_point(field_set:Zee.Proto.UserCharacter.Select.Name)
}
inline std::string* Select::mutable_name() {
  std::string* _s = _internal_mutable_name();
  // @@protoc_insertion_point(field_mutable:Zee.Proto.UserCharacter.Select.Name)
  return _s;
}
inline const std::string& Select::_internal_name() const {
  return name_.Get();
}
inline void Select::_internal_set_name(const std::string& value) {
  
  name_.Set(::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr::EmptyDefault{}, value, GetArenaForAllocation());
}
inline std::string* Select::_internal_mutable_name() {
  
  return name_.Mutable(::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr::EmptyDefault{}, GetArenaForAllocation());
}
inline std::string* Select::release_name() {
  // @@protoc_insertion_point(field_release:Zee.Proto.UserCharacter.Select.Name)
  return name_.Release(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), GetArenaForAllocation());
}
inline void Select::set_allocated_name(std::string* name) {
  if (name != nullptr) {
    
  } else {
    
  }
  name_.SetAllocated(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), name,
      GetArenaForAllocation());
  // @@protoc_insertion_point(field_set_allocated:Zee.Proto.UserCharacter.Select.Name)
}

#ifdef __GNUC__
  #pragma GCC diagnostic pop
#endif  // __GNUC__
// -------------------------------------------------------------------

// -------------------------------------------------------------------


// @@protoc_insertion_point(namespace_scope)

}  // namespace UserCharacter
}  // namespace Proto
}  // namespace Zee

PROTOBUF_NAMESPACE_OPEN

template <> struct is_proto_enum< ::Zee::Proto::UserCharacter::ReturnCode> : ::std::true_type {};
template <>
inline const EnumDescriptor* GetEnumDescriptor< ::Zee::Proto::UserCharacter::ReturnCode>() {
  return ::Zee::Proto::UserCharacter::ReturnCode_descriptor();
}

PROTOBUF_NAMESPACE_CLOSE

// @@protoc_insertion_point(global_scope)

#include <google/protobuf/port_undef.inc>
#endif  // GOOGLE_PROTOBUF_INCLUDED_GOOGLE_PROTOBUF_INCLUDED_UserCharacter_2eproto