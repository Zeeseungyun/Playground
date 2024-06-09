// Generated by the protocol buffer compiler.  DO NOT EDIT!
// NO CHECKED-IN PROTOBUF GENCODE
// source: Depth1/test2.proto
// Protobuf C++ Version: 5.27.0

#ifndef GOOGLE_PROTOBUF_INCLUDED_Depth1_2ftest2_2eproto_2epb_2eh
#define GOOGLE_PROTOBUF_INCLUDED_Depth1_2ftest2_2eproto_2epb_2eh

#include <limits>
#include <string>
#include <type_traits>
#include <utility>

#include "google/protobuf/runtime_version.h"
#if PROTOBUF_VERSION != 5027000
#error "Protobuf C++ gencode is built with an incompatible version of"
#error "Protobuf C++ headers/runtime. See"
#error "https://protobuf.dev/support/cross-version-runtime-guarantee/#cpp"
#endif
#include "google/protobuf/io/coded_stream.h"
#include "google/protobuf/arena.h"
#include "google/protobuf/arenastring.h"
#include "google/protobuf/generated_message_tctable_decl.h"
#include "google/protobuf/generated_message_util.h"
#include "google/protobuf/metadata_lite.h"
#include "google/protobuf/generated_message_reflection.h"
#include "google/protobuf/message.h"
#include "google/protobuf/repeated_field.h"  // IWYU pragma: export
#include "google/protobuf/extension_set.h"  // IWYU pragma: export
#include "google/protobuf/unknown_field_set.h"
#include "test1.pb.h"
#include "Depth1/Depth2/test3.pb.h"
// @@protoc_insertion_point(includes)

// Must be included last.
#include "google/protobuf/port_def.inc"

#define PROTOBUF_INTERNAL_EXPORT_Depth1_2ftest2_2eproto

namespace google {
namespace protobuf {
namespace internal {
class AnyMetadata;
}  // namespace internal
}  // namespace protobuf
}  // namespace google

// Internal implementation detail -- do not use these members.
struct TableStruct_Depth1_2ftest2_2eproto {
  static const ::uint32_t offsets[];
};
extern const ::google::protobuf::internal::DescriptorTable
    descriptor_table_Depth1_2ftest2_2eproto;
class Depth1Test2;
struct Depth1Test2DefaultTypeInternal;
extern Depth1Test2DefaultTypeInternal _Depth1Test2_default_instance_;
namespace google {
namespace protobuf {
}  // namespace protobuf
}  // namespace google


// ===================================================================


// -------------------------------------------------------------------

class Depth1Test2 final : public ::google::protobuf::Message
/* @@protoc_insertion_point(class_definition:Depth1Test2) */ {
 public:
  inline Depth1Test2() : Depth1Test2(nullptr) {}
  ~Depth1Test2() override;
  template <typename = void>
  explicit PROTOBUF_CONSTEXPR Depth1Test2(
      ::google::protobuf::internal::ConstantInitialized);

  inline Depth1Test2(const Depth1Test2& from) : Depth1Test2(nullptr, from) {}
  inline Depth1Test2(Depth1Test2&& from) noexcept
      : Depth1Test2(nullptr, std::move(from)) {}
  inline Depth1Test2& operator=(const Depth1Test2& from) {
    CopyFrom(from);
    return *this;
  }
  inline Depth1Test2& operator=(Depth1Test2&& from) noexcept {
    if (this == &from) return *this;
    if (GetArena() == from.GetArena()
#ifdef PROTOBUF_FORCE_COPY_IN_MOVE
        && GetArena() != nullptr
#endif  // !PROTOBUF_FORCE_COPY_IN_MOVE
    ) {
      InternalSwap(&from);
    } else {
      CopyFrom(from);
    }
    return *this;
  }

  inline const ::google::protobuf::UnknownFieldSet& unknown_fields() const
      ABSL_ATTRIBUTE_LIFETIME_BOUND {
    return _internal_metadata_.unknown_fields<::google::protobuf::UnknownFieldSet>(::google::protobuf::UnknownFieldSet::default_instance);
  }
  inline ::google::protobuf::UnknownFieldSet* mutable_unknown_fields()
      ABSL_ATTRIBUTE_LIFETIME_BOUND {
    return _internal_metadata_.mutable_unknown_fields<::google::protobuf::UnknownFieldSet>();
  }

  static const ::google::protobuf::Descriptor* descriptor() {
    return GetDescriptor();
  }
  static const ::google::protobuf::Descriptor* GetDescriptor() {
    return default_instance().GetMetadata().descriptor;
  }
  static const ::google::protobuf::Reflection* GetReflection() {
    return default_instance().GetMetadata().reflection;
  }
  static const Depth1Test2& default_instance() {
    return *internal_default_instance();
  }
  static inline const Depth1Test2* internal_default_instance() {
    return reinterpret_cast<const Depth1Test2*>(
        &_Depth1Test2_default_instance_);
  }
  static constexpr int kIndexInFileMessages = 0;
  friend void swap(Depth1Test2& a, Depth1Test2& b) { a.Swap(&b); }
  inline void Swap(Depth1Test2* other) {
    if (other == this) return;
#ifdef PROTOBUF_FORCE_COPY_IN_SWAP
    if (GetArena() != nullptr && GetArena() == other->GetArena()) {
#else   // PROTOBUF_FORCE_COPY_IN_SWAP
    if (GetArena() == other->GetArena()) {
#endif  // !PROTOBUF_FORCE_COPY_IN_SWAP
      InternalSwap(other);
    } else {
      ::google::protobuf::internal::GenericSwap(this, other);
    }
  }
  void UnsafeArenaSwap(Depth1Test2* other) {
    if (other == this) return;
    ABSL_DCHECK(GetArena() == other->GetArena());
    InternalSwap(other);
  }

  // implements Message ----------------------------------------------

  Depth1Test2* New(::google::protobuf::Arena* arena = nullptr) const final {
    return ::google::protobuf::Message::DefaultConstruct<Depth1Test2>(arena);
  }
  using ::google::protobuf::Message::CopyFrom;
  void CopyFrom(const Depth1Test2& from);
  using ::google::protobuf::Message::MergeFrom;
  void MergeFrom(const Depth1Test2& from) { Depth1Test2::MergeImpl(*this, from); }

  private:
  static void MergeImpl(
      ::google::protobuf::MessageLite& to_msg,
      const ::google::protobuf::MessageLite& from_msg);

  public:
  bool IsInitialized() const {
    return true;
  }
  ABSL_ATTRIBUTE_REINITIALIZES void Clear() final;
  ::size_t ByteSizeLong() const final;
  ::uint8_t* _InternalSerialize(
      ::uint8_t* target,
      ::google::protobuf::io::EpsCopyOutputStream* stream) const final;
  int GetCachedSize() const { return _impl_._cached_size_.Get(); }

  private:
  void SharedCtor(::google::protobuf::Arena* arena);
  void SharedDtor();
  void InternalSwap(Depth1Test2* other);
 private:
  friend class ::google::protobuf::internal::AnyMetadata;
  static ::absl::string_view FullMessageName() { return "Depth1Test2"; }

 protected:
  explicit Depth1Test2(::google::protobuf::Arena* arena);
  Depth1Test2(::google::protobuf::Arena* arena, const Depth1Test2& from);
  Depth1Test2(::google::protobuf::Arena* arena, Depth1Test2&& from) noexcept
      : Depth1Test2(arena) {
    *this = ::std::move(from);
  }
  const ::google::protobuf::Message::ClassData* GetClassData() const final;

 public:
  ::google::protobuf::Metadata GetMetadata() const;
  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------
  enum : int {
    kAFieldNumber = 1,
    kPFieldNumber = 2,
    kDT3FieldNumber = 3,
  };
  // string a = 1;
  void clear_a() ;
  const std::string& a() const;
  template <typename Arg_ = const std::string&, typename... Args_>
  void set_a(Arg_&& arg, Args_... args);
  std::string* mutable_a();
  PROTOBUF_NODISCARD std::string* release_a();
  void set_allocated_a(std::string* value);

  private:
  const std::string& _internal_a() const;
  inline PROTOBUF_ALWAYS_INLINE void _internal_set_a(
      const std::string& value);
  std::string* _internal_mutable_a();

  public:
  // .Temp1.T2.Tt4.Tt1.T12.Person p = 2;
  bool has_p() const;
  void clear_p() ;
  const ::Temp1::T2::Tt4::Tt1::T12::Person& p() const;
  PROTOBUF_NODISCARD ::Temp1::T2::Tt4::Tt1::T12::Person* release_p();
  ::Temp1::T2::Tt4::Tt1::T12::Person* mutable_p();
  void set_allocated_p(::Temp1::T2::Tt4::Tt1::T12::Person* value);
  void unsafe_arena_set_allocated_p(::Temp1::T2::Tt4::Tt1::T12::Person* value);
  ::Temp1::T2::Tt4::Tt1::T12::Person* unsafe_arena_release_p();

  private:
  const ::Temp1::T2::Tt4::Tt1::T12::Person& _internal_p() const;
  ::Temp1::T2::Tt4::Tt1::T12::Person* _internal_mutable_p();

  public:
  // .P1.Depth2Test3 DT3 = 3;
  bool has_dt3() const;
  void clear_dt3() ;
  const ::P1::Depth2Test3& dt3() const;
  PROTOBUF_NODISCARD ::P1::Depth2Test3* release_dt3();
  ::P1::Depth2Test3* mutable_dt3();
  void set_allocated_dt3(::P1::Depth2Test3* value);
  void unsafe_arena_set_allocated_dt3(::P1::Depth2Test3* value);
  ::P1::Depth2Test3* unsafe_arena_release_dt3();

  private:
  const ::P1::Depth2Test3& _internal_dt3() const;
  ::P1::Depth2Test3* _internal_mutable_dt3();

  public:
  // @@protoc_insertion_point(class_scope:Depth1Test2)
 private:
  class _Internal;
  friend class ::google::protobuf::internal::TcParser;
  static const ::google::protobuf::internal::TcParseTable<
      2, 3, 2,
      21, 2>
      _table_;

  static constexpr const void* _raw_default_instance_ =
      &_Depth1Test2_default_instance_;

  friend class ::google::protobuf::MessageLite;
  friend class ::google::protobuf::Arena;
  template <typename T>
  friend class ::google::protobuf::Arena::InternalHelper;
  using InternalArenaConstructable_ = void;
  using DestructorSkippable_ = void;
  struct Impl_ {
    inline explicit constexpr Impl_(
        ::google::protobuf::internal::ConstantInitialized) noexcept;
    inline explicit Impl_(::google::protobuf::internal::InternalVisibility visibility,
                          ::google::protobuf::Arena* arena);
    inline explicit Impl_(::google::protobuf::internal::InternalVisibility visibility,
                          ::google::protobuf::Arena* arena, const Impl_& from,
                          const Depth1Test2& from_msg);
    ::google::protobuf::internal::HasBits<1> _has_bits_;
    mutable ::google::protobuf::internal::CachedSize _cached_size_;
    ::google::protobuf::internal::ArenaStringPtr a_;
    ::Temp1::T2::Tt4::Tt1::T12::Person* p_;
    ::P1::Depth2Test3* dt3_;
    PROTOBUF_TSAN_DECLARE_MEMBER
  };
  union { Impl_ _impl_; };
  friend struct ::TableStruct_Depth1_2ftest2_2eproto;
};

// ===================================================================




// ===================================================================


#ifdef __GNUC__
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wstrict-aliasing"
#endif  // __GNUC__
// -------------------------------------------------------------------

// Depth1Test2

// string a = 1;
inline void Depth1Test2::clear_a() {
  ::google::protobuf::internal::TSanWrite(&_impl_);
  _impl_.a_.ClearToEmpty();
}
inline const std::string& Depth1Test2::a() const
    ABSL_ATTRIBUTE_LIFETIME_BOUND {
  // @@protoc_insertion_point(field_get:Depth1Test2.a)
  return _internal_a();
}
template <typename Arg_, typename... Args_>
inline PROTOBUF_ALWAYS_INLINE void Depth1Test2::set_a(Arg_&& arg,
                                                     Args_... args) {
  ::google::protobuf::internal::TSanWrite(&_impl_);
  _impl_.a_.Set(static_cast<Arg_&&>(arg), args..., GetArena());
  // @@protoc_insertion_point(field_set:Depth1Test2.a)
}
inline std::string* Depth1Test2::mutable_a() ABSL_ATTRIBUTE_LIFETIME_BOUND {
  std::string* _s = _internal_mutable_a();
  // @@protoc_insertion_point(field_mutable:Depth1Test2.a)
  return _s;
}
inline const std::string& Depth1Test2::_internal_a() const {
  ::google::protobuf::internal::TSanRead(&_impl_);
  return _impl_.a_.Get();
}
inline void Depth1Test2::_internal_set_a(const std::string& value) {
  ::google::protobuf::internal::TSanWrite(&_impl_);
  _impl_.a_.Set(value, GetArena());
}
inline std::string* Depth1Test2::_internal_mutable_a() {
  ::google::protobuf::internal::TSanWrite(&_impl_);
  return _impl_.a_.Mutable( GetArena());
}
inline std::string* Depth1Test2::release_a() {
  ::google::protobuf::internal::TSanWrite(&_impl_);
  // @@protoc_insertion_point(field_release:Depth1Test2.a)
  return _impl_.a_.Release();
}
inline void Depth1Test2::set_allocated_a(std::string* value) {
  ::google::protobuf::internal::TSanWrite(&_impl_);
  _impl_.a_.SetAllocated(value, GetArena());
  #ifdef PROTOBUF_FORCE_COPY_DEFAULT_STRING
        if (_impl_.a_.IsDefault()) {
          _impl_.a_.Set("", GetArena());
        }
  #endif  // PROTOBUF_FORCE_COPY_DEFAULT_STRING
  // @@protoc_insertion_point(field_set_allocated:Depth1Test2.a)
}

// .Temp1.T2.Tt4.Tt1.T12.Person p = 2;
inline bool Depth1Test2::has_p() const {
  bool value = (_impl_._has_bits_[0] & 0x00000001u) != 0;
  PROTOBUF_ASSUME(!value || _impl_.p_ != nullptr);
  return value;
}
inline const ::Temp1::T2::Tt4::Tt1::T12::Person& Depth1Test2::_internal_p() const {
  ::google::protobuf::internal::TSanRead(&_impl_);
  const ::Temp1::T2::Tt4::Tt1::T12::Person* p = _impl_.p_;
  return p != nullptr ? *p : reinterpret_cast<const ::Temp1::T2::Tt4::Tt1::T12::Person&>(::Temp1::T2::Tt4::Tt1::T12::_Person_default_instance_);
}
inline const ::Temp1::T2::Tt4::Tt1::T12::Person& Depth1Test2::p() const ABSL_ATTRIBUTE_LIFETIME_BOUND {
  // @@protoc_insertion_point(field_get:Depth1Test2.p)
  return _internal_p();
}
inline void Depth1Test2::unsafe_arena_set_allocated_p(::Temp1::T2::Tt4::Tt1::T12::Person* value) {
  ::google::protobuf::internal::TSanWrite(&_impl_);
  if (GetArena() == nullptr) {
    delete reinterpret_cast<::google::protobuf::MessageLite*>(_impl_.p_);
  }
  _impl_.p_ = reinterpret_cast<::Temp1::T2::Tt4::Tt1::T12::Person*>(value);
  if (value != nullptr) {
    _impl_._has_bits_[0] |= 0x00000001u;
  } else {
    _impl_._has_bits_[0] &= ~0x00000001u;
  }
  // @@protoc_insertion_point(field_unsafe_arena_set_allocated:Depth1Test2.p)
}
inline ::Temp1::T2::Tt4::Tt1::T12::Person* Depth1Test2::release_p() {
  ::google::protobuf::internal::TSanWrite(&_impl_);

  _impl_._has_bits_[0] &= ~0x00000001u;
  ::Temp1::T2::Tt4::Tt1::T12::Person* released = _impl_.p_;
  _impl_.p_ = nullptr;
#ifdef PROTOBUF_FORCE_COPY_IN_RELEASE
  auto* old = reinterpret_cast<::google::protobuf::MessageLite*>(released);
  released = ::google::protobuf::internal::DuplicateIfNonNull(released);
  if (GetArena() == nullptr) {
    delete old;
  }
#else   // PROTOBUF_FORCE_COPY_IN_RELEASE
  if (GetArena() != nullptr) {
    released = ::google::protobuf::internal::DuplicateIfNonNull(released);
  }
#endif  // !PROTOBUF_FORCE_COPY_IN_RELEASE
  return released;
}
inline ::Temp1::T2::Tt4::Tt1::T12::Person* Depth1Test2::unsafe_arena_release_p() {
  ::google::protobuf::internal::TSanWrite(&_impl_);
  // @@protoc_insertion_point(field_release:Depth1Test2.p)

  _impl_._has_bits_[0] &= ~0x00000001u;
  ::Temp1::T2::Tt4::Tt1::T12::Person* temp = _impl_.p_;
  _impl_.p_ = nullptr;
  return temp;
}
inline ::Temp1::T2::Tt4::Tt1::T12::Person* Depth1Test2::_internal_mutable_p() {
  ::google::protobuf::internal::TSanWrite(&_impl_);
  if (_impl_.p_ == nullptr) {
    auto* p = ::google::protobuf::Message::DefaultConstruct<::Temp1::T2::Tt4::Tt1::T12::Person>(GetArena());
    _impl_.p_ = reinterpret_cast<::Temp1::T2::Tt4::Tt1::T12::Person*>(p);
  }
  return _impl_.p_;
}
inline ::Temp1::T2::Tt4::Tt1::T12::Person* Depth1Test2::mutable_p() ABSL_ATTRIBUTE_LIFETIME_BOUND {
  _impl_._has_bits_[0] |= 0x00000001u;
  ::Temp1::T2::Tt4::Tt1::T12::Person* _msg = _internal_mutable_p();
  // @@protoc_insertion_point(field_mutable:Depth1Test2.p)
  return _msg;
}
inline void Depth1Test2::set_allocated_p(::Temp1::T2::Tt4::Tt1::T12::Person* value) {
  ::google::protobuf::Arena* message_arena = GetArena();
  ::google::protobuf::internal::TSanWrite(&_impl_);
  if (message_arena == nullptr) {
    delete reinterpret_cast<::google::protobuf::MessageLite*>(_impl_.p_);
  }

  if (value != nullptr) {
    ::google::protobuf::Arena* submessage_arena = reinterpret_cast<::google::protobuf::MessageLite*>(value)->GetArena();
    if (message_arena != submessage_arena) {
      value = ::google::protobuf::internal::GetOwnedMessage(message_arena, value, submessage_arena);
    }
    _impl_._has_bits_[0] |= 0x00000001u;
  } else {
    _impl_._has_bits_[0] &= ~0x00000001u;
  }

  _impl_.p_ = reinterpret_cast<::Temp1::T2::Tt4::Tt1::T12::Person*>(value);
  // @@protoc_insertion_point(field_set_allocated:Depth1Test2.p)
}

// .P1.Depth2Test3 DT3 = 3;
inline bool Depth1Test2::has_dt3() const {
  bool value = (_impl_._has_bits_[0] & 0x00000002u) != 0;
  PROTOBUF_ASSUME(!value || _impl_.dt3_ != nullptr);
  return value;
}
inline const ::P1::Depth2Test3& Depth1Test2::_internal_dt3() const {
  ::google::protobuf::internal::TSanRead(&_impl_);
  const ::P1::Depth2Test3* p = _impl_.dt3_;
  return p != nullptr ? *p : reinterpret_cast<const ::P1::Depth2Test3&>(::P1::_Depth2Test3_default_instance_);
}
inline const ::P1::Depth2Test3& Depth1Test2::dt3() const ABSL_ATTRIBUTE_LIFETIME_BOUND {
  // @@protoc_insertion_point(field_get:Depth1Test2.DT3)
  return _internal_dt3();
}
inline void Depth1Test2::unsafe_arena_set_allocated_dt3(::P1::Depth2Test3* value) {
  ::google::protobuf::internal::TSanWrite(&_impl_);
  if (GetArena() == nullptr) {
    delete reinterpret_cast<::google::protobuf::MessageLite*>(_impl_.dt3_);
  }
  _impl_.dt3_ = reinterpret_cast<::P1::Depth2Test3*>(value);
  if (value != nullptr) {
    _impl_._has_bits_[0] |= 0x00000002u;
  } else {
    _impl_._has_bits_[0] &= ~0x00000002u;
  }
  // @@protoc_insertion_point(field_unsafe_arena_set_allocated:Depth1Test2.DT3)
}
inline ::P1::Depth2Test3* Depth1Test2::release_dt3() {
  ::google::protobuf::internal::TSanWrite(&_impl_);

  _impl_._has_bits_[0] &= ~0x00000002u;
  ::P1::Depth2Test3* released = _impl_.dt3_;
  _impl_.dt3_ = nullptr;
#ifdef PROTOBUF_FORCE_COPY_IN_RELEASE
  auto* old = reinterpret_cast<::google::protobuf::MessageLite*>(released);
  released = ::google::protobuf::internal::DuplicateIfNonNull(released);
  if (GetArena() == nullptr) {
    delete old;
  }
#else   // PROTOBUF_FORCE_COPY_IN_RELEASE
  if (GetArena() != nullptr) {
    released = ::google::protobuf::internal::DuplicateIfNonNull(released);
  }
#endif  // !PROTOBUF_FORCE_COPY_IN_RELEASE
  return released;
}
inline ::P1::Depth2Test3* Depth1Test2::unsafe_arena_release_dt3() {
  ::google::protobuf::internal::TSanWrite(&_impl_);
  // @@protoc_insertion_point(field_release:Depth1Test2.DT3)

  _impl_._has_bits_[0] &= ~0x00000002u;
  ::P1::Depth2Test3* temp = _impl_.dt3_;
  _impl_.dt3_ = nullptr;
  return temp;
}
inline ::P1::Depth2Test3* Depth1Test2::_internal_mutable_dt3() {
  ::google::protobuf::internal::TSanWrite(&_impl_);
  if (_impl_.dt3_ == nullptr) {
    auto* p = ::google::protobuf::Message::DefaultConstruct<::P1::Depth2Test3>(GetArena());
    _impl_.dt3_ = reinterpret_cast<::P1::Depth2Test3*>(p);
  }
  return _impl_.dt3_;
}
inline ::P1::Depth2Test3* Depth1Test2::mutable_dt3() ABSL_ATTRIBUTE_LIFETIME_BOUND {
  _impl_._has_bits_[0] |= 0x00000002u;
  ::P1::Depth2Test3* _msg = _internal_mutable_dt3();
  // @@protoc_insertion_point(field_mutable:Depth1Test2.DT3)
  return _msg;
}
inline void Depth1Test2::set_allocated_dt3(::P1::Depth2Test3* value) {
  ::google::protobuf::Arena* message_arena = GetArena();
  ::google::protobuf::internal::TSanWrite(&_impl_);
  if (message_arena == nullptr) {
    delete reinterpret_cast<::google::protobuf::MessageLite*>(_impl_.dt3_);
  }

  if (value != nullptr) {
    ::google::protobuf::Arena* submessage_arena = reinterpret_cast<::google::protobuf::MessageLite*>(value)->GetArena();
    if (message_arena != submessage_arena) {
      value = ::google::protobuf::internal::GetOwnedMessage(message_arena, value, submessage_arena);
    }
    _impl_._has_bits_[0] |= 0x00000002u;
  } else {
    _impl_._has_bits_[0] &= ~0x00000002u;
  }

  _impl_.dt3_ = reinterpret_cast<::P1::Depth2Test3*>(value);
  // @@protoc_insertion_point(field_set_allocated:Depth1Test2.DT3)
}

#ifdef __GNUC__
#pragma GCC diagnostic pop
#endif  // __GNUC__

// @@protoc_insertion_point(namespace_scope)


// @@protoc_insertion_point(global_scope)

#include "google/protobuf/port_undef.inc"

#endif  // GOOGLE_PROTOBUF_INCLUDED_Depth1_2ftest2_2eproto_2epb_2eh
