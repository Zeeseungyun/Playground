// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: Chat.proto

#ifndef GOOGLE_PROTOBUF_INCLUDED_Chat_2eproto
#define GOOGLE_PROTOBUF_INCLUDED_Chat_2eproto

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
// @@protoc_insertion_point(includes)
#include <google/protobuf/port_def.inc>
#define PROTOBUF_INTERNAL_EXPORT_Chat_2eproto
PROTOBUF_NAMESPACE_OPEN
namespace internal {
class AnyMetadata;
}  // namespace internal
PROTOBUF_NAMESPACE_CLOSE

// Internal implementation detail -- do not use these members.
struct TableStruct_Chat_2eproto {
  static const ::PROTOBUF_NAMESPACE_ID::internal::ParseTableField entries[]
    PROTOBUF_SECTION_VARIABLE(protodesc_cold);
  static const ::PROTOBUF_NAMESPACE_ID::internal::AuxiliaryParseTableField aux[]
    PROTOBUF_SECTION_VARIABLE(protodesc_cold);
  static const ::PROTOBUF_NAMESPACE_ID::internal::ParseTable schema[2]
    PROTOBUF_SECTION_VARIABLE(protodesc_cold);
  static const ::PROTOBUF_NAMESPACE_ID::internal::FieldMetadata field_metadata[];
  static const ::PROTOBUF_NAMESPACE_ID::internal::SerializationTable serialization_table[];
  static const ::PROTOBUF_NAMESPACE_ID::uint32 offsets[];
};
extern const ::PROTOBUF_NAMESPACE_ID::internal::DescriptorTable descriptor_table_Chat_2eproto;
namespace Zee {
namespace Proto {
namespace Chat {
class Speak;
struct SpeakDefaultTypeInternal;
extern SpeakDefaultTypeInternal _Speak_default_instance_;
class Speak1;
struct Speak1DefaultTypeInternal;
extern Speak1DefaultTypeInternal _Speak1_default_instance_;
}  // namespace Chat
}  // namespace Proto
}  // namespace Zee
PROTOBUF_NAMESPACE_OPEN
template<> ::Zee::Proto::Chat::Speak* Arena::CreateMaybeMessage<::Zee::Proto::Chat::Speak>(Arena*);
template<> ::Zee::Proto::Chat::Speak1* Arena::CreateMaybeMessage<::Zee::Proto::Chat::Speak1>(Arena*);
PROTOBUF_NAMESPACE_CLOSE
namespace Zee {
namespace Proto {
namespace Chat {

enum ReturnCode : int {
  RC_SUCCESS = 0,
  ReturnCode_INT_MIN_SENTINEL_DO_NOT_USE_ = std::numeric_limits<::PROTOBUF_NAMESPACE_ID::int32>::min(),
  ReturnCode_INT_MAX_SENTINEL_DO_NOT_USE_ = std::numeric_limits<::PROTOBUF_NAMESPACE_ID::int32>::max()
};
bool ReturnCode_IsValid(int value);
constexpr ReturnCode ReturnCode_MIN = RC_SUCCESS;
constexpr ReturnCode ReturnCode_MAX = RC_SUCCESS;
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

class Speak1 final :
    public ::PROTOBUF_NAMESPACE_ID::Message /* @@protoc_insertion_point(class_definition:Zee.Proto.Chat.Speak1) */ {
 public:
  inline Speak1() : Speak1(nullptr) {}
  ~Speak1() override;
  explicit constexpr Speak1(::PROTOBUF_NAMESPACE_ID::internal::ConstantInitialized);

  Speak1(const Speak1& from);
  Speak1(Speak1&& from) noexcept
    : Speak1() {
    *this = ::std::move(from);
  }

  inline Speak1& operator=(const Speak1& from) {
    CopyFrom(from);
    return *this;
  }
  inline Speak1& operator=(Speak1&& from) noexcept {
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
  static const Speak1& default_instance() {
    return *internal_default_instance();
  }
  static inline const Speak1* internal_default_instance() {
    return reinterpret_cast<const Speak1*>(
               &_Speak1_default_instance_);
  }
  static constexpr int kIndexInFileMessages =
    0;

  friend void swap(Speak1& a, Speak1& b) {
    a.Swap(&b);
  }
  inline void Swap(Speak1* other) {
    if (other == this) return;
    if (GetOwningArena() == other->GetOwningArena()) {
      InternalSwap(other);
    } else {
      ::PROTOBUF_NAMESPACE_ID::internal::GenericSwap(this, other);
    }
  }
  void UnsafeArenaSwap(Speak1* other) {
    if (other == this) return;
    GOOGLE_DCHECK(GetOwningArena() == other->GetOwningArena());
    InternalSwap(other);
  }

  // implements Message ----------------------------------------------

  inline Speak1* New() const final {
    return new Speak1();
  }

  Speak1* New(::PROTOBUF_NAMESPACE_ID::Arena* arena) const final {
    return CreateMaybeMessage<Speak1>(arena);
  }
  using ::PROTOBUF_NAMESPACE_ID::Message::CopyFrom;
  void CopyFrom(const Speak1& from);
  using ::PROTOBUF_NAMESPACE_ID::Message::MergeFrom;
  void MergeFrom(const Speak1& from);
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
  void InternalSwap(Speak1* other);
  friend class ::PROTOBUF_NAMESPACE_ID::internal::AnyMetadata;
  static ::PROTOBUF_NAMESPACE_ID::StringPiece FullMessageName() {
    return "Zee.Proto.Chat.Speak1";
  }
  protected:
  explicit Speak1(::PROTOBUF_NAMESPACE_ID::Arena* arena,
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
    kIdFieldNumber = 3,
    kContentFieldNumber = 4,
    kSpeak12FieldNumber = 5,
    kUIDFieldNumber = 2,
    kRCFieldNumber = 1,
  };
  // string Id = 3;
  void clear_id();
  const std::string& id() const;
  template <typename ArgT0 = const std::string&, typename... ArgT>
  void set_id(ArgT0&& arg0, ArgT... args);
  std::string* mutable_id();
  PROTOBUF_MUST_USE_RESULT std::string* release_id();
  void set_allocated_id(std::string* id);
  private:
  const std::string& _internal_id() const;
  inline PROTOBUF_ALWAYS_INLINE void _internal_set_id(const std::string& value);
  std::string* _internal_mutable_id();
  public:

  // string Content = 4;
  void clear_content();
  const std::string& content() const;
  template <typename ArgT0 = const std::string&, typename... ArgT>
  void set_content(ArgT0&& arg0, ArgT... args);
  std::string* mutable_content();
  PROTOBUF_MUST_USE_RESULT std::string* release_content();
  void set_allocated_content(std::string* content);
  private:
  const std::string& _internal_content() const;
  inline PROTOBUF_ALWAYS_INLINE void _internal_set_content(const std::string& value);
  std::string* _internal_mutable_content();
  public:

  // .Zee.Proto.Chat.Speak Speak12 = 5;
  bool has_speak12() const;
  private:
  bool _internal_has_speak12() const;
  public:
  void clear_speak12();
  const ::Zee::Proto::Chat::Speak& speak12() const;
  PROTOBUF_MUST_USE_RESULT ::Zee::Proto::Chat::Speak* release_speak12();
  ::Zee::Proto::Chat::Speak* mutable_speak12();
  void set_allocated_speak12(::Zee::Proto::Chat::Speak* speak12);
  private:
  const ::Zee::Proto::Chat::Speak& _internal_speak12() const;
  ::Zee::Proto::Chat::Speak* _internal_mutable_speak12();
  public:
  void unsafe_arena_set_allocated_speak12(
      ::Zee::Proto::Chat::Speak* speak12);
  ::Zee::Proto::Chat::Speak* unsafe_arena_release_speak12();

  // int64 UID = 2;
  void clear_uid();
  ::PROTOBUF_NAMESPACE_ID::int64 uid() const;
  void set_uid(::PROTOBUF_NAMESPACE_ID::int64 value);
  private:
  ::PROTOBUF_NAMESPACE_ID::int64 _internal_uid() const;
  void _internal_set_uid(::PROTOBUF_NAMESPACE_ID::int64 value);
  public:

  // .Zee.Proto.Chat.ReturnCode RC = 1;
  void clear_rc();
  ::Zee::Proto::Chat::ReturnCode rc() const;
  void set_rc(::Zee::Proto::Chat::ReturnCode value);
  private:
  ::Zee::Proto::Chat::ReturnCode _internal_rc() const;
  void _internal_set_rc(::Zee::Proto::Chat::ReturnCode value);
  public:

  // @@protoc_insertion_point(class_scope:Zee.Proto.Chat.Speak1)
 private:
  class _Internal;

  template <typename T> friend class ::PROTOBUF_NAMESPACE_ID::Arena::InternalHelper;
  typedef void InternalArenaConstructable_;
  typedef void DestructorSkippable_;
  ::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr id_;
  ::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr content_;
  ::Zee::Proto::Chat::Speak* speak12_;
  ::PROTOBUF_NAMESPACE_ID::int64 uid_;
  int rc_;
  mutable ::PROTOBUF_NAMESPACE_ID::internal::CachedSize _cached_size_;
  friend struct ::TableStruct_Chat_2eproto;
};
// -------------------------------------------------------------------

class Speak final :
    public ::PROTOBUF_NAMESPACE_ID::Message /* @@protoc_insertion_point(class_definition:Zee.Proto.Chat.Speak) */ {
 public:
  inline Speak() : Speak(nullptr) {}
  ~Speak() override;
  explicit constexpr Speak(::PROTOBUF_NAMESPACE_ID::internal::ConstantInitialized);

  Speak(const Speak& from);
  Speak(Speak&& from) noexcept
    : Speak() {
    *this = ::std::move(from);
  }

  inline Speak& operator=(const Speak& from) {
    CopyFrom(from);
    return *this;
  }
  inline Speak& operator=(Speak&& from) noexcept {
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
  static const Speak& default_instance() {
    return *internal_default_instance();
  }
  static inline const Speak* internal_default_instance() {
    return reinterpret_cast<const Speak*>(
               &_Speak_default_instance_);
  }
  static constexpr int kIndexInFileMessages =
    1;

  friend void swap(Speak& a, Speak& b) {
    a.Swap(&b);
  }
  inline void Swap(Speak* other) {
    if (other == this) return;
    if (GetOwningArena() == other->GetOwningArena()) {
      InternalSwap(other);
    } else {
      ::PROTOBUF_NAMESPACE_ID::internal::GenericSwap(this, other);
    }
  }
  void UnsafeArenaSwap(Speak* other) {
    if (other == this) return;
    GOOGLE_DCHECK(GetOwningArena() == other->GetOwningArena());
    InternalSwap(other);
  }

  // implements Message ----------------------------------------------

  inline Speak* New() const final {
    return new Speak();
  }

  Speak* New(::PROTOBUF_NAMESPACE_ID::Arena* arena) const final {
    return CreateMaybeMessage<Speak>(arena);
  }
  using ::PROTOBUF_NAMESPACE_ID::Message::CopyFrom;
  void CopyFrom(const Speak& from);
  using ::PROTOBUF_NAMESPACE_ID::Message::MergeFrom;
  void MergeFrom(const Speak& from);
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
  void InternalSwap(Speak* other);
  friend class ::PROTOBUF_NAMESPACE_ID::internal::AnyMetadata;
  static ::PROTOBUF_NAMESPACE_ID::StringPiece FullMessageName() {
    return "Zee.Proto.Chat.Speak";
  }
  protected:
  explicit Speak(::PROTOBUF_NAMESPACE_ID::Arena* arena,
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
    kContentsFieldNumber = 5,
    kIdFieldNumber = 3,
    kContentFieldNumber = 4,
    kUIDFieldNumber = 2,
    kRCFieldNumber = 1,
  };
  // repeated string Contents = 5;
  int contents_size() const;
  private:
  int _internal_contents_size() const;
  public:
  void clear_contents();
  const std::string& contents(int index) const;
  std::string* mutable_contents(int index);
  void set_contents(int index, const std::string& value);
  void set_contents(int index, std::string&& value);
  void set_contents(int index, const char* value);
  void set_contents(int index, const char* value, size_t size);
  std::string* add_contents();
  void add_contents(const std::string& value);
  void add_contents(std::string&& value);
  void add_contents(const char* value);
  void add_contents(const char* value, size_t size);
  const ::PROTOBUF_NAMESPACE_ID::RepeatedPtrField<std::string>& contents() const;
  ::PROTOBUF_NAMESPACE_ID::RepeatedPtrField<std::string>* mutable_contents();
  private:
  const std::string& _internal_contents(int index) const;
  std::string* _internal_add_contents();
  public:

  // string Id = 3;
  void clear_id();
  const std::string& id() const;
  template <typename ArgT0 = const std::string&, typename... ArgT>
  void set_id(ArgT0&& arg0, ArgT... args);
  std::string* mutable_id();
  PROTOBUF_MUST_USE_RESULT std::string* release_id();
  void set_allocated_id(std::string* id);
  private:
  const std::string& _internal_id() const;
  inline PROTOBUF_ALWAYS_INLINE void _internal_set_id(const std::string& value);
  std::string* _internal_mutable_id();
  public:

  // string Content = 4;
  void clear_content();
  const std::string& content() const;
  template <typename ArgT0 = const std::string&, typename... ArgT>
  void set_content(ArgT0&& arg0, ArgT... args);
  std::string* mutable_content();
  PROTOBUF_MUST_USE_RESULT std::string* release_content();
  void set_allocated_content(std::string* content);
  private:
  const std::string& _internal_content() const;
  inline PROTOBUF_ALWAYS_INLINE void _internal_set_content(const std::string& value);
  std::string* _internal_mutable_content();
  public:

  // int64 UID = 2;
  void clear_uid();
  ::PROTOBUF_NAMESPACE_ID::int64 uid() const;
  void set_uid(::PROTOBUF_NAMESPACE_ID::int64 value);
  private:
  ::PROTOBUF_NAMESPACE_ID::int64 _internal_uid() const;
  void _internal_set_uid(::PROTOBUF_NAMESPACE_ID::int64 value);
  public:

  // .Zee.Proto.Chat.ReturnCode RC = 1;
  void clear_rc();
  ::Zee::Proto::Chat::ReturnCode rc() const;
  void set_rc(::Zee::Proto::Chat::ReturnCode value);
  private:
  ::Zee::Proto::Chat::ReturnCode _internal_rc() const;
  void _internal_set_rc(::Zee::Proto::Chat::ReturnCode value);
  public:

  // @@protoc_insertion_point(class_scope:Zee.Proto.Chat.Speak)
 private:
  class _Internal;

  template <typename T> friend class ::PROTOBUF_NAMESPACE_ID::Arena::InternalHelper;
  typedef void InternalArenaConstructable_;
  typedef void DestructorSkippable_;
  ::PROTOBUF_NAMESPACE_ID::RepeatedPtrField<std::string> contents_;
  ::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr id_;
  ::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr content_;
  ::PROTOBUF_NAMESPACE_ID::int64 uid_;
  int rc_;
  mutable ::PROTOBUF_NAMESPACE_ID::internal::CachedSize _cached_size_;
  friend struct ::TableStruct_Chat_2eproto;
};
// ===================================================================


// ===================================================================

#ifdef __GNUC__
  #pragma GCC diagnostic push
  #pragma GCC diagnostic ignored "-Wstrict-aliasing"
#endif  // __GNUC__
// Speak1

// .Zee.Proto.Chat.ReturnCode RC = 1;
inline void Speak1::clear_rc() {
  rc_ = 0;
}
inline ::Zee::Proto::Chat::ReturnCode Speak1::_internal_rc() const {
  return static_cast< ::Zee::Proto::Chat::ReturnCode >(rc_);
}
inline ::Zee::Proto::Chat::ReturnCode Speak1::rc() const {
  // @@protoc_insertion_point(field_get:Zee.Proto.Chat.Speak1.RC)
  return _internal_rc();
}
inline void Speak1::_internal_set_rc(::Zee::Proto::Chat::ReturnCode value) {
  
  rc_ = value;
}
inline void Speak1::set_rc(::Zee::Proto::Chat::ReturnCode value) {
  _internal_set_rc(value);
  // @@protoc_insertion_point(field_set:Zee.Proto.Chat.Speak1.RC)
}

// int64 UID = 2;
inline void Speak1::clear_uid() {
  uid_ = int64_t{0};
}
inline ::PROTOBUF_NAMESPACE_ID::int64 Speak1::_internal_uid() const {
  return uid_;
}
inline ::PROTOBUF_NAMESPACE_ID::int64 Speak1::uid() const {
  // @@protoc_insertion_point(field_get:Zee.Proto.Chat.Speak1.UID)
  return _internal_uid();
}
inline void Speak1::_internal_set_uid(::PROTOBUF_NAMESPACE_ID::int64 value) {
  
  uid_ = value;
}
inline void Speak1::set_uid(::PROTOBUF_NAMESPACE_ID::int64 value) {
  _internal_set_uid(value);
  // @@protoc_insertion_point(field_set:Zee.Proto.Chat.Speak1.UID)
}

// string Id = 3;
inline void Speak1::clear_id() {
  id_.ClearToEmpty();
}
inline const std::string& Speak1::id() const {
  // @@protoc_insertion_point(field_get:Zee.Proto.Chat.Speak1.Id)
  return _internal_id();
}
template <typename ArgT0, typename... ArgT>
inline PROTOBUF_ALWAYS_INLINE
void Speak1::set_id(ArgT0&& arg0, ArgT... args) {
 
 id_.Set(::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr::EmptyDefault{}, static_cast<ArgT0 &&>(arg0), args..., GetArenaForAllocation());
  // @@protoc_insertion_point(field_set:Zee.Proto.Chat.Speak1.Id)
}
inline std::string* Speak1::mutable_id() {
  std::string* _s = _internal_mutable_id();
  // @@protoc_insertion_point(field_mutable:Zee.Proto.Chat.Speak1.Id)
  return _s;
}
inline const std::string& Speak1::_internal_id() const {
  return id_.Get();
}
inline void Speak1::_internal_set_id(const std::string& value) {
  
  id_.Set(::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr::EmptyDefault{}, value, GetArenaForAllocation());
}
inline std::string* Speak1::_internal_mutable_id() {
  
  return id_.Mutable(::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr::EmptyDefault{}, GetArenaForAllocation());
}
inline std::string* Speak1::release_id() {
  // @@protoc_insertion_point(field_release:Zee.Proto.Chat.Speak1.Id)
  return id_.Release(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), GetArenaForAllocation());
}
inline void Speak1::set_allocated_id(std::string* id) {
  if (id != nullptr) {
    
  } else {
    
  }
  id_.SetAllocated(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), id,
      GetArenaForAllocation());
  // @@protoc_insertion_point(field_set_allocated:Zee.Proto.Chat.Speak1.Id)
}

// string Content = 4;
inline void Speak1::clear_content() {
  content_.ClearToEmpty();
}
inline const std::string& Speak1::content() const {
  // @@protoc_insertion_point(field_get:Zee.Proto.Chat.Speak1.Content)
  return _internal_content();
}
template <typename ArgT0, typename... ArgT>
inline PROTOBUF_ALWAYS_INLINE
void Speak1::set_content(ArgT0&& arg0, ArgT... args) {
 
 content_.Set(::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr::EmptyDefault{}, static_cast<ArgT0 &&>(arg0), args..., GetArenaForAllocation());
  // @@protoc_insertion_point(field_set:Zee.Proto.Chat.Speak1.Content)
}
inline std::string* Speak1::mutable_content() {
  std::string* _s = _internal_mutable_content();
  // @@protoc_insertion_point(field_mutable:Zee.Proto.Chat.Speak1.Content)
  return _s;
}
inline const std::string& Speak1::_internal_content() const {
  return content_.Get();
}
inline void Speak1::_internal_set_content(const std::string& value) {
  
  content_.Set(::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr::EmptyDefault{}, value, GetArenaForAllocation());
}
inline std::string* Speak1::_internal_mutable_content() {
  
  return content_.Mutable(::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr::EmptyDefault{}, GetArenaForAllocation());
}
inline std::string* Speak1::release_content() {
  // @@protoc_insertion_point(field_release:Zee.Proto.Chat.Speak1.Content)
  return content_.Release(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), GetArenaForAllocation());
}
inline void Speak1::set_allocated_content(std::string* content) {
  if (content != nullptr) {
    
  } else {
    
  }
  content_.SetAllocated(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), content,
      GetArenaForAllocation());
  // @@protoc_insertion_point(field_set_allocated:Zee.Proto.Chat.Speak1.Content)
}

// .Zee.Proto.Chat.Speak Speak12 = 5;
inline bool Speak1::_internal_has_speak12() const {
  return this != internal_default_instance() && speak12_ != nullptr;
}
inline bool Speak1::has_speak12() const {
  return _internal_has_speak12();
}
inline void Speak1::clear_speak12() {
  if (GetArenaForAllocation() == nullptr && speak12_ != nullptr) {
    delete speak12_;
  }
  speak12_ = nullptr;
}
inline const ::Zee::Proto::Chat::Speak& Speak1::_internal_speak12() const {
  const ::Zee::Proto::Chat::Speak* p = speak12_;
  return p != nullptr ? *p : reinterpret_cast<const ::Zee::Proto::Chat::Speak&>(
      ::Zee::Proto::Chat::_Speak_default_instance_);
}
inline const ::Zee::Proto::Chat::Speak& Speak1::speak12() const {
  // @@protoc_insertion_point(field_get:Zee.Proto.Chat.Speak1.Speak12)
  return _internal_speak12();
}
inline void Speak1::unsafe_arena_set_allocated_speak12(
    ::Zee::Proto::Chat::Speak* speak12) {
  if (GetArenaForAllocation() == nullptr) {
    delete reinterpret_cast<::PROTOBUF_NAMESPACE_ID::MessageLite*>(speak12_);
  }
  speak12_ = speak12;
  if (speak12) {
    
  } else {
    
  }
  // @@protoc_insertion_point(field_unsafe_arena_set_allocated:Zee.Proto.Chat.Speak1.Speak12)
}
inline ::Zee::Proto::Chat::Speak* Speak1::release_speak12() {
  
  ::Zee::Proto::Chat::Speak* temp = speak12_;
  speak12_ = nullptr;
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
inline ::Zee::Proto::Chat::Speak* Speak1::unsafe_arena_release_speak12() {
  // @@protoc_insertion_point(field_release:Zee.Proto.Chat.Speak1.Speak12)
  
  ::Zee::Proto::Chat::Speak* temp = speak12_;
  speak12_ = nullptr;
  return temp;
}
inline ::Zee::Proto::Chat::Speak* Speak1::_internal_mutable_speak12() {
  
  if (speak12_ == nullptr) {
    auto* p = CreateMaybeMessage<::Zee::Proto::Chat::Speak>(GetArenaForAllocation());
    speak12_ = p;
  }
  return speak12_;
}
inline ::Zee::Proto::Chat::Speak* Speak1::mutable_speak12() {
  ::Zee::Proto::Chat::Speak* _msg = _internal_mutable_speak12();
  // @@protoc_insertion_point(field_mutable:Zee.Proto.Chat.Speak1.Speak12)
  return _msg;
}
inline void Speak1::set_allocated_speak12(::Zee::Proto::Chat::Speak* speak12) {
  ::PROTOBUF_NAMESPACE_ID::Arena* message_arena = GetArenaForAllocation();
  if (message_arena == nullptr) {
    delete speak12_;
  }
  if (speak12) {
    ::PROTOBUF_NAMESPACE_ID::Arena* submessage_arena =
        ::PROTOBUF_NAMESPACE_ID::Arena::InternalHelper<::Zee::Proto::Chat::Speak>::GetOwningArena(speak12);
    if (message_arena != submessage_arena) {
      speak12 = ::PROTOBUF_NAMESPACE_ID::internal::GetOwnedMessage(
          message_arena, speak12, submessage_arena);
    }
    
  } else {
    
  }
  speak12_ = speak12;
  // @@protoc_insertion_point(field_set_allocated:Zee.Proto.Chat.Speak1.Speak12)
}

// -------------------------------------------------------------------

// Speak

// .Zee.Proto.Chat.ReturnCode RC = 1;
inline void Speak::clear_rc() {
  rc_ = 0;
}
inline ::Zee::Proto::Chat::ReturnCode Speak::_internal_rc() const {
  return static_cast< ::Zee::Proto::Chat::ReturnCode >(rc_);
}
inline ::Zee::Proto::Chat::ReturnCode Speak::rc() const {
  // @@protoc_insertion_point(field_get:Zee.Proto.Chat.Speak.RC)
  return _internal_rc();
}
inline void Speak::_internal_set_rc(::Zee::Proto::Chat::ReturnCode value) {
  
  rc_ = value;
}
inline void Speak::set_rc(::Zee::Proto::Chat::ReturnCode value) {
  _internal_set_rc(value);
  // @@protoc_insertion_point(field_set:Zee.Proto.Chat.Speak.RC)
}

// int64 UID = 2;
inline void Speak::clear_uid() {
  uid_ = int64_t{0};
}
inline ::PROTOBUF_NAMESPACE_ID::int64 Speak::_internal_uid() const {
  return uid_;
}
inline ::PROTOBUF_NAMESPACE_ID::int64 Speak::uid() const {
  // @@protoc_insertion_point(field_get:Zee.Proto.Chat.Speak.UID)
  return _internal_uid();
}
inline void Speak::_internal_set_uid(::PROTOBUF_NAMESPACE_ID::int64 value) {
  
  uid_ = value;
}
inline void Speak::set_uid(::PROTOBUF_NAMESPACE_ID::int64 value) {
  _internal_set_uid(value);
  // @@protoc_insertion_point(field_set:Zee.Proto.Chat.Speak.UID)
}

// string Id = 3;
inline void Speak::clear_id() {
  id_.ClearToEmpty();
}
inline const std::string& Speak::id() const {
  // @@protoc_insertion_point(field_get:Zee.Proto.Chat.Speak.Id)
  return _internal_id();
}
template <typename ArgT0, typename... ArgT>
inline PROTOBUF_ALWAYS_INLINE
void Speak::set_id(ArgT0&& arg0, ArgT... args) {
 
 id_.Set(::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr::EmptyDefault{}, static_cast<ArgT0 &&>(arg0), args..., GetArenaForAllocation());
  // @@protoc_insertion_point(field_set:Zee.Proto.Chat.Speak.Id)
}
inline std::string* Speak::mutable_id() {
  std::string* _s = _internal_mutable_id();
  // @@protoc_insertion_point(field_mutable:Zee.Proto.Chat.Speak.Id)
  return _s;
}
inline const std::string& Speak::_internal_id() const {
  return id_.Get();
}
inline void Speak::_internal_set_id(const std::string& value) {
  
  id_.Set(::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr::EmptyDefault{}, value, GetArenaForAllocation());
}
inline std::string* Speak::_internal_mutable_id() {
  
  return id_.Mutable(::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr::EmptyDefault{}, GetArenaForAllocation());
}
inline std::string* Speak::release_id() {
  // @@protoc_insertion_point(field_release:Zee.Proto.Chat.Speak.Id)
  return id_.Release(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), GetArenaForAllocation());
}
inline void Speak::set_allocated_id(std::string* id) {
  if (id != nullptr) {
    
  } else {
    
  }
  id_.SetAllocated(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), id,
      GetArenaForAllocation());
  // @@protoc_insertion_point(field_set_allocated:Zee.Proto.Chat.Speak.Id)
}

// string Content = 4;
inline void Speak::clear_content() {
  content_.ClearToEmpty();
}
inline const std::string& Speak::content() const {
  // @@protoc_insertion_point(field_get:Zee.Proto.Chat.Speak.Content)
  return _internal_content();
}
template <typename ArgT0, typename... ArgT>
inline PROTOBUF_ALWAYS_INLINE
void Speak::set_content(ArgT0&& arg0, ArgT... args) {
 
 content_.Set(::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr::EmptyDefault{}, static_cast<ArgT0 &&>(arg0), args..., GetArenaForAllocation());
  // @@protoc_insertion_point(field_set:Zee.Proto.Chat.Speak.Content)
}
inline std::string* Speak::mutable_content() {
  std::string* _s = _internal_mutable_content();
  // @@protoc_insertion_point(field_mutable:Zee.Proto.Chat.Speak.Content)
  return _s;
}
inline const std::string& Speak::_internal_content() const {
  return content_.Get();
}
inline void Speak::_internal_set_content(const std::string& value) {
  
  content_.Set(::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr::EmptyDefault{}, value, GetArenaForAllocation());
}
inline std::string* Speak::_internal_mutable_content() {
  
  return content_.Mutable(::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr::EmptyDefault{}, GetArenaForAllocation());
}
inline std::string* Speak::release_content() {
  // @@protoc_insertion_point(field_release:Zee.Proto.Chat.Speak.Content)
  return content_.Release(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), GetArenaForAllocation());
}
inline void Speak::set_allocated_content(std::string* content) {
  if (content != nullptr) {
    
  } else {
    
  }
  content_.SetAllocated(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), content,
      GetArenaForAllocation());
  // @@protoc_insertion_point(field_set_allocated:Zee.Proto.Chat.Speak.Content)
}

// repeated string Contents = 5;
inline int Speak::_internal_contents_size() const {
  return contents_.size();
}
inline int Speak::contents_size() const {
  return _internal_contents_size();
}
inline void Speak::clear_contents() {
  contents_.Clear();
}
inline std::string* Speak::add_contents() {
  std::string* _s = _internal_add_contents();
  // @@protoc_insertion_point(field_add_mutable:Zee.Proto.Chat.Speak.Contents)
  return _s;
}
inline const std::string& Speak::_internal_contents(int index) const {
  return contents_.Get(index);
}
inline const std::string& Speak::contents(int index) const {
  // @@protoc_insertion_point(field_get:Zee.Proto.Chat.Speak.Contents)
  return _internal_contents(index);
}
inline std::string* Speak::mutable_contents(int index) {
  // @@protoc_insertion_point(field_mutable:Zee.Proto.Chat.Speak.Contents)
  return contents_.Mutable(index);
}
inline void Speak::set_contents(int index, const std::string& value) {
  contents_.Mutable(index)->assign(value);
  // @@protoc_insertion_point(field_set:Zee.Proto.Chat.Speak.Contents)
}
inline void Speak::set_contents(int index, std::string&& value) {
  contents_.Mutable(index)->assign(std::move(value));
  // @@protoc_insertion_point(field_set:Zee.Proto.Chat.Speak.Contents)
}
inline void Speak::set_contents(int index, const char* value) {
  GOOGLE_DCHECK(value != nullptr);
  contents_.Mutable(index)->assign(value);
  // @@protoc_insertion_point(field_set_char:Zee.Proto.Chat.Speak.Contents)
}
inline void Speak::set_contents(int index, const char* value, size_t size) {
  contents_.Mutable(index)->assign(
    reinterpret_cast<const char*>(value), size);
  // @@protoc_insertion_point(field_set_pointer:Zee.Proto.Chat.Speak.Contents)
}
inline std::string* Speak::_internal_add_contents() {
  return contents_.Add();
}
inline void Speak::add_contents(const std::string& value) {
  contents_.Add()->assign(value);
  // @@protoc_insertion_point(field_add:Zee.Proto.Chat.Speak.Contents)
}
inline void Speak::add_contents(std::string&& value) {
  contents_.Add(std::move(value));
  // @@protoc_insertion_point(field_add:Zee.Proto.Chat.Speak.Contents)
}
inline void Speak::add_contents(const char* value) {
  GOOGLE_DCHECK(value != nullptr);
  contents_.Add()->assign(value);
  // @@protoc_insertion_point(field_add_char:Zee.Proto.Chat.Speak.Contents)
}
inline void Speak::add_contents(const char* value, size_t size) {
  contents_.Add()->assign(reinterpret_cast<const char*>(value), size);
  // @@protoc_insertion_point(field_add_pointer:Zee.Proto.Chat.Speak.Contents)
}
inline const ::PROTOBUF_NAMESPACE_ID::RepeatedPtrField<std::string>&
Speak::contents() const {
  // @@protoc_insertion_point(field_list:Zee.Proto.Chat.Speak.Contents)
  return contents_;
}
inline ::PROTOBUF_NAMESPACE_ID::RepeatedPtrField<std::string>*
Speak::mutable_contents() {
  // @@protoc_insertion_point(field_mutable_list:Zee.Proto.Chat.Speak.Contents)
  return &contents_;
}

#ifdef __GNUC__
  #pragma GCC diagnostic pop
#endif  // __GNUC__
// -------------------------------------------------------------------


// @@protoc_insertion_point(namespace_scope)

}  // namespace Chat
}  // namespace Proto
}  // namespace Zee

PROTOBUF_NAMESPACE_OPEN

template <> struct is_proto_enum< ::Zee::Proto::Chat::ReturnCode> : ::std::true_type {};
template <>
inline const EnumDescriptor* GetEnumDescriptor< ::Zee::Proto::Chat::ReturnCode>() {
  return ::Zee::Proto::Chat::ReturnCode_descriptor();
}

PROTOBUF_NAMESPACE_CLOSE

// @@protoc_insertion_point(global_scope)

#include <google/protobuf/port_undef.inc>
#endif  // GOOGLE_PROTOBUF_INCLUDED_GOOGLE_PROTOBUF_INCLUDED_Chat_2eproto
