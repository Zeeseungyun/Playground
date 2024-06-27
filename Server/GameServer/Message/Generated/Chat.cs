// <auto-generated>
//     Generated by the protocol buffer compiler.  DO NOT EDIT!
//     source: Chat.proto
// </auto-generated>
#pragma warning disable 1591, 0612, 3021
#region Designer generated code

using pb = global::Google.Protobuf;
using pbc = global::Google.Protobuf.Collections;
using pbr = global::Google.Protobuf.Reflection;
using scg = global::System.Collections.Generic;
namespace Zee.Proto.Chat {

  /// <summary>Holder for reflection information generated from Chat.proto</summary>
  public static partial class ChatReflection {

    #region Descriptor
    /// <summary>File descriptor for Chat.proto</summary>
    public static pbr::FileDescriptor Descriptor {
      get { return descriptor; }
    }
    private static pbr::FileDescriptor descriptor;

    static ChatReflection() {
      byte[] descriptorData = global::System.Convert.FromBase64String(
          string.Concat(
            "CgpDaGF0LnByb3RvEg5aZWUuUHJvdG8uQ2hhdCKCAQoGU3BlYWsxEiYKAlJD",
            "GAEgASgOMhouWmVlLlByb3RvLkNoYXQuUmV0dXJuQ29kZRILCgNVSUQYAiAB",
            "KAMSCgoCSWQYAyABKAkSDwoHQ29udGVudBgEIAEoCRImCgdTcGVhazEyGAUg",
            "ASgLMhUuWmVlLlByb3RvLkNoYXQuU3BlYWsiawoFU3BlYWsSJgoCUkMYASAB",
            "KA4yGi5aZWUuUHJvdG8uQ2hhdC5SZXR1cm5Db2RlEgsKA1VJRBgCIAEoAxIK",
            "CgJJZBgDIAEoCRIPCgdDb250ZW50GAQgASgJEhAKCENvbnRlbnRzGAUgAygJ",
            "KhwKClJldHVybkNvZGUSDgoKUkNfU1VDQ0VTUxAAYgZwcm90bzM="));
      descriptor = pbr::FileDescriptor.FromGeneratedCode(descriptorData,
          new pbr::FileDescriptor[] { },
          new pbr::GeneratedClrTypeInfo(new[] {typeof(global::Zee.Proto.Chat.ReturnCode), }, null, new pbr::GeneratedClrTypeInfo[] {
            new pbr::GeneratedClrTypeInfo(typeof(global::Zee.Proto.Chat.Speak1), global::Zee.Proto.Chat.Speak1.Parser, new[]{ "RC", "UID", "Id", "Content", "Speak12" }, null, null, null, null),
            new pbr::GeneratedClrTypeInfo(typeof(global::Zee.Proto.Chat.Speak), global::Zee.Proto.Chat.Speak.Parser, new[]{ "RC", "UID", "Id", "Content", "Contents" }, null, null, null, null)
          }));
    }
    #endregion

  }
  #region Enums
  public enum ReturnCode {
    [pbr::OriginalName("RC_SUCCESS")] RcSuccess = 0,
  }

  #endregion

  #region Messages
  public sealed partial class Speak1 : pb::IMessage<Speak1>
  #if !GOOGLE_PROTOBUF_REFSTRUCT_COMPATIBILITY_MODE
      , pb::IBufferMessage
  #endif
  {
    private static readonly pb::MessageParser<Speak1> _parser = new pb::MessageParser<Speak1>(() => new Speak1());
    private pb::UnknownFieldSet _unknownFields;
    [global::System.Diagnostics.DebuggerNonUserCodeAttribute]
    [global::System.CodeDom.Compiler.GeneratedCode("protoc", null)]
    public static pb::MessageParser<Speak1> Parser { get { return _parser; } }

    [global::System.Diagnostics.DebuggerNonUserCodeAttribute]
    [global::System.CodeDom.Compiler.GeneratedCode("protoc", null)]
    public static pbr::MessageDescriptor Descriptor {
      get { return global::Zee.Proto.Chat.ChatReflection.Descriptor.MessageTypes[0]; }
    }

    [global::System.Diagnostics.DebuggerNonUserCodeAttribute]
    [global::System.CodeDom.Compiler.GeneratedCode("protoc", null)]
    pbr::MessageDescriptor pb::IMessage.Descriptor {
      get { return Descriptor; }
    }

    [global::System.Diagnostics.DebuggerNonUserCodeAttribute]
    [global::System.CodeDom.Compiler.GeneratedCode("protoc", null)]
    public Speak1() {
      OnConstruction();
    }

    partial void OnConstruction();

    [global::System.Diagnostics.DebuggerNonUserCodeAttribute]
    [global::System.CodeDom.Compiler.GeneratedCode("protoc", null)]
    public Speak1(Speak1 other) : this() {
      rC_ = other.rC_;
      uID_ = other.uID_;
      id_ = other.id_;
      content_ = other.content_;
      speak12_ = other.speak12_ != null ? other.speak12_.Clone() : null;
      _unknownFields = pb::UnknownFieldSet.Clone(other._unknownFields);
    }

    [global::System.Diagnostics.DebuggerNonUserCodeAttribute]
    [global::System.CodeDom.Compiler.GeneratedCode("protoc", null)]
    public Speak1 Clone() {
      return new Speak1(this);
    }

    /// <summary>Field number for the "RC" field.</summary>
    public const int RCFieldNumber = 1;
    private global::Zee.Proto.Chat.ReturnCode rC_ = global::Zee.Proto.Chat.ReturnCode.RcSuccess;
    /// <summary>
    ///Comment2 
    /// </summary>
    [global::System.Diagnostics.DebuggerNonUserCodeAttribute]
    [global::System.CodeDom.Compiler.GeneratedCode("protoc", null)]
    public global::Zee.Proto.Chat.ReturnCode RC {
      get { return rC_; }
      set {
        rC_ = value;
      }
    }

    /// <summary>Field number for the "UID" field.</summary>
    public const int UIDFieldNumber = 2;
    private long uID_;
    [global::System.Diagnostics.DebuggerNonUserCodeAttribute]
    [global::System.CodeDom.Compiler.GeneratedCode("protoc", null)]
    public long UID {
      get { return uID_; }
      set {
        uID_ = value;
      }
    }

    /// <summary>Field number for the "Id" field.</summary>
    public const int IdFieldNumber = 3;
    private string id_ = "";
    [global::System.Diagnostics.DebuggerNonUserCodeAttribute]
    [global::System.CodeDom.Compiler.GeneratedCode("protoc", null)]
    public string Id {
      get { return id_; }
      set {
        id_ = pb::ProtoPreconditions.CheckNotNull(value, "value");
      }
    }

    /// <summary>Field number for the "Content" field.</summary>
    public const int ContentFieldNumber = 4;
    private string content_ = "";
    [global::System.Diagnostics.DebuggerNonUserCodeAttribute]
    [global::System.CodeDom.Compiler.GeneratedCode("protoc", null)]
    public string Content {
      get { return content_; }
      set {
        content_ = pb::ProtoPreconditions.CheckNotNull(value, "value");
      }
    }

    /// <summary>Field number for the "Speak12" field.</summary>
    public const int Speak12FieldNumber = 5;
    private global::Zee.Proto.Chat.Speak speak12_;
    [global::System.Diagnostics.DebuggerNonUserCodeAttribute]
    [global::System.CodeDom.Compiler.GeneratedCode("protoc", null)]
    public global::Zee.Proto.Chat.Speak Speak12 {
      get { return speak12_; }
      set {
        speak12_ = value;
      }
    }

    [global::System.Diagnostics.DebuggerNonUserCodeAttribute]
    [global::System.CodeDom.Compiler.GeneratedCode("protoc", null)]
    public override bool Equals(object other) {
      return Equals(other as Speak1);
    }

    [global::System.Diagnostics.DebuggerNonUserCodeAttribute]
    [global::System.CodeDom.Compiler.GeneratedCode("protoc", null)]
    public bool Equals(Speak1 other) {
      if (ReferenceEquals(other, null)) {
        return false;
      }
      if (ReferenceEquals(other, this)) {
        return true;
      }
      if (RC != other.RC) return false;
      if (UID != other.UID) return false;
      if (Id != other.Id) return false;
      if (Content != other.Content) return false;
      if (!object.Equals(Speak12, other.Speak12)) return false;
      return Equals(_unknownFields, other._unknownFields);
    }

    [global::System.Diagnostics.DebuggerNonUserCodeAttribute]
    [global::System.CodeDom.Compiler.GeneratedCode("protoc", null)]
    public override int GetHashCode() {
      int hash = 1;
      if (RC != global::Zee.Proto.Chat.ReturnCode.RcSuccess) hash ^= RC.GetHashCode();
      if (UID != 0L) hash ^= UID.GetHashCode();
      if (Id.Length != 0) hash ^= Id.GetHashCode();
      if (Content.Length != 0) hash ^= Content.GetHashCode();
      if (speak12_ != null) hash ^= Speak12.GetHashCode();
      if (_unknownFields != null) {
        hash ^= _unknownFields.GetHashCode();
      }
      return hash;
    }

    [global::System.Diagnostics.DebuggerNonUserCodeAttribute]
    [global::System.CodeDom.Compiler.GeneratedCode("protoc", null)]
    public override string ToString() {
      return pb::JsonFormatter.ToDiagnosticString(this);
    }

    [global::System.Diagnostics.DebuggerNonUserCodeAttribute]
    [global::System.CodeDom.Compiler.GeneratedCode("protoc", null)]
    public void WriteTo(pb::CodedOutputStream output) {
    #if !GOOGLE_PROTOBUF_REFSTRUCT_COMPATIBILITY_MODE
      output.WriteRawMessage(this);
    #else
      if (RC != global::Zee.Proto.Chat.ReturnCode.RcSuccess) {
        output.WriteRawTag(8);
        output.WriteEnum((int) RC);
      }
      if (UID != 0L) {
        output.WriteRawTag(16);
        output.WriteInt64(UID);
      }
      if (Id.Length != 0) {
        output.WriteRawTag(26);
        output.WriteString(Id);
      }
      if (Content.Length != 0) {
        output.WriteRawTag(34);
        output.WriteString(Content);
      }
      if (speak12_ != null) {
        output.WriteRawTag(42);
        output.WriteMessage(Speak12);
      }
      if (_unknownFields != null) {
        _unknownFields.WriteTo(output);
      }
    #endif
    }

    #if !GOOGLE_PROTOBUF_REFSTRUCT_COMPATIBILITY_MODE
    [global::System.Diagnostics.DebuggerNonUserCodeAttribute]
    [global::System.CodeDom.Compiler.GeneratedCode("protoc", null)]
    void pb::IBufferMessage.InternalWriteTo(ref pb::WriteContext output) {
      if (RC != global::Zee.Proto.Chat.ReturnCode.RcSuccess) {
        output.WriteRawTag(8);
        output.WriteEnum((int) RC);
      }
      if (UID != 0L) {
        output.WriteRawTag(16);
        output.WriteInt64(UID);
      }
      if (Id.Length != 0) {
        output.WriteRawTag(26);
        output.WriteString(Id);
      }
      if (Content.Length != 0) {
        output.WriteRawTag(34);
        output.WriteString(Content);
      }
      if (speak12_ != null) {
        output.WriteRawTag(42);
        output.WriteMessage(Speak12);
      }
      if (_unknownFields != null) {
        _unknownFields.WriteTo(ref output);
      }
    }
    #endif

    [global::System.Diagnostics.DebuggerNonUserCodeAttribute]
    [global::System.CodeDom.Compiler.GeneratedCode("protoc", null)]
    public int CalculateSize() {
      int size = 0;
      if (RC != global::Zee.Proto.Chat.ReturnCode.RcSuccess) {
        size += 1 + pb::CodedOutputStream.ComputeEnumSize((int) RC);
      }
      if (UID != 0L) {
        size += 1 + pb::CodedOutputStream.ComputeInt64Size(UID);
      }
      if (Id.Length != 0) {
        size += 1 + pb::CodedOutputStream.ComputeStringSize(Id);
      }
      if (Content.Length != 0) {
        size += 1 + pb::CodedOutputStream.ComputeStringSize(Content);
      }
      if (speak12_ != null) {
        size += 1 + pb::CodedOutputStream.ComputeMessageSize(Speak12);
      }
      if (_unknownFields != null) {
        size += _unknownFields.CalculateSize();
      }
      return size;
    }

    [global::System.Diagnostics.DebuggerNonUserCodeAttribute]
    [global::System.CodeDom.Compiler.GeneratedCode("protoc", null)]
    public void MergeFrom(Speak1 other) {
      if (other == null) {
        return;
      }
      if (other.RC != global::Zee.Proto.Chat.ReturnCode.RcSuccess) {
        RC = other.RC;
      }
      if (other.UID != 0L) {
        UID = other.UID;
      }
      if (other.Id.Length != 0) {
        Id = other.Id;
      }
      if (other.Content.Length != 0) {
        Content = other.Content;
      }
      if (other.speak12_ != null) {
        if (speak12_ == null) {
          Speak12 = new global::Zee.Proto.Chat.Speak();
        }
        Speak12.MergeFrom(other.Speak12);
      }
      _unknownFields = pb::UnknownFieldSet.MergeFrom(_unknownFields, other._unknownFields);
    }

    [global::System.Diagnostics.DebuggerNonUserCodeAttribute]
    [global::System.CodeDom.Compiler.GeneratedCode("protoc", null)]
    public void MergeFrom(pb::CodedInputStream input) {
    #if !GOOGLE_PROTOBUF_REFSTRUCT_COMPATIBILITY_MODE
      input.ReadRawMessage(this);
    #else
      uint tag;
      while ((tag = input.ReadTag()) != 0) {
        switch(tag) {
          default:
            _unknownFields = pb::UnknownFieldSet.MergeFieldFrom(_unknownFields, input);
            break;
          case 8: {
            RC = (global::Zee.Proto.Chat.ReturnCode) input.ReadEnum();
            break;
          }
          case 16: {
            UID = input.ReadInt64();
            break;
          }
          case 26: {
            Id = input.ReadString();
            break;
          }
          case 34: {
            Content = input.ReadString();
            break;
          }
          case 42: {
            if (speak12_ == null) {
              Speak12 = new global::Zee.Proto.Chat.Speak();
            }
            input.ReadMessage(Speak12);
            break;
          }
        }
      }
    #endif
    }

    #if !GOOGLE_PROTOBUF_REFSTRUCT_COMPATIBILITY_MODE
    [global::System.Diagnostics.DebuggerNonUserCodeAttribute]
    [global::System.CodeDom.Compiler.GeneratedCode("protoc", null)]
    void pb::IBufferMessage.InternalMergeFrom(ref pb::ParseContext input) {
      uint tag;
      while ((tag = input.ReadTag()) != 0) {
        switch(tag) {
          default:
            _unknownFields = pb::UnknownFieldSet.MergeFieldFrom(_unknownFields, ref input);
            break;
          case 8: {
            RC = (global::Zee.Proto.Chat.ReturnCode) input.ReadEnum();
            break;
          }
          case 16: {
            UID = input.ReadInt64();
            break;
          }
          case 26: {
            Id = input.ReadString();
            break;
          }
          case 34: {
            Content = input.ReadString();
            break;
          }
          case 42: {
            if (speak12_ == null) {
              Speak12 = new global::Zee.Proto.Chat.Speak();
            }
            input.ReadMessage(Speak12);
            break;
          }
        }
      }
    }
    #endif

  }

  public sealed partial class Speak : pb::IMessage<Speak>
  #if !GOOGLE_PROTOBUF_REFSTRUCT_COMPATIBILITY_MODE
      , pb::IBufferMessage
  #endif
  {
    private static readonly pb::MessageParser<Speak> _parser = new pb::MessageParser<Speak>(() => new Speak());
    private pb::UnknownFieldSet _unknownFields;
    [global::System.Diagnostics.DebuggerNonUserCodeAttribute]
    [global::System.CodeDom.Compiler.GeneratedCode("protoc", null)]
    public static pb::MessageParser<Speak> Parser { get { return _parser; } }

    [global::System.Diagnostics.DebuggerNonUserCodeAttribute]
    [global::System.CodeDom.Compiler.GeneratedCode("protoc", null)]
    public static pbr::MessageDescriptor Descriptor {
      get { return global::Zee.Proto.Chat.ChatReflection.Descriptor.MessageTypes[1]; }
    }

    [global::System.Diagnostics.DebuggerNonUserCodeAttribute]
    [global::System.CodeDom.Compiler.GeneratedCode("protoc", null)]
    pbr::MessageDescriptor pb::IMessage.Descriptor {
      get { return Descriptor; }
    }

    [global::System.Diagnostics.DebuggerNonUserCodeAttribute]
    [global::System.CodeDom.Compiler.GeneratedCode("protoc", null)]
    public Speak() {
      OnConstruction();
    }

    partial void OnConstruction();

    [global::System.Diagnostics.DebuggerNonUserCodeAttribute]
    [global::System.CodeDom.Compiler.GeneratedCode("protoc", null)]
    public Speak(Speak other) : this() {
      rC_ = other.rC_;
      uID_ = other.uID_;
      id_ = other.id_;
      content_ = other.content_;
      contents_ = other.contents_.Clone();
      _unknownFields = pb::UnknownFieldSet.Clone(other._unknownFields);
    }

    [global::System.Diagnostics.DebuggerNonUserCodeAttribute]
    [global::System.CodeDom.Compiler.GeneratedCode("protoc", null)]
    public Speak Clone() {
      return new Speak(this);
    }

    /// <summary>Field number for the "RC" field.</summary>
    public const int RCFieldNumber = 1;
    private global::Zee.Proto.Chat.ReturnCode rC_ = global::Zee.Proto.Chat.ReturnCode.RcSuccess;
    /// <summary>
    ///Comment2 
    /// </summary>
    [global::System.Diagnostics.DebuggerNonUserCodeAttribute]
    [global::System.CodeDom.Compiler.GeneratedCode("protoc", null)]
    public global::Zee.Proto.Chat.ReturnCode RC {
      get { return rC_; }
      set {
        rC_ = value;
      }
    }

    /// <summary>Field number for the "UID" field.</summary>
    public const int UIDFieldNumber = 2;
    private long uID_;
    [global::System.Diagnostics.DebuggerNonUserCodeAttribute]
    [global::System.CodeDom.Compiler.GeneratedCode("protoc", null)]
    public long UID {
      get { return uID_; }
      set {
        uID_ = value;
      }
    }

    /// <summary>Field number for the "Id" field.</summary>
    public const int IdFieldNumber = 3;
    private string id_ = "";
    [global::System.Diagnostics.DebuggerNonUserCodeAttribute]
    [global::System.CodeDom.Compiler.GeneratedCode("protoc", null)]
    public string Id {
      get { return id_; }
      set {
        id_ = pb::ProtoPreconditions.CheckNotNull(value, "value");
      }
    }

    /// <summary>Field number for the "Content" field.</summary>
    public const int ContentFieldNumber = 4;
    private string content_ = "";
    [global::System.Diagnostics.DebuggerNonUserCodeAttribute]
    [global::System.CodeDom.Compiler.GeneratedCode("protoc", null)]
    public string Content {
      get { return content_; }
      set {
        content_ = pb::ProtoPreconditions.CheckNotNull(value, "value");
      }
    }

    /// <summary>Field number for the "Contents" field.</summary>
    public const int ContentsFieldNumber = 5;
    private static readonly pb::FieldCodec<string> _repeated_contents_codec
        = pb::FieldCodec.ForString(42);
    private readonly pbc::RepeatedField<string> contents_ = new pbc::RepeatedField<string>();
    [global::System.Diagnostics.DebuggerNonUserCodeAttribute]
    [global::System.CodeDom.Compiler.GeneratedCode("protoc", null)]
    public pbc::RepeatedField<string> Contents {
      get { return contents_; }
    }

    [global::System.Diagnostics.DebuggerNonUserCodeAttribute]
    [global::System.CodeDom.Compiler.GeneratedCode("protoc", null)]
    public override bool Equals(object other) {
      return Equals(other as Speak);
    }

    [global::System.Diagnostics.DebuggerNonUserCodeAttribute]
    [global::System.CodeDom.Compiler.GeneratedCode("protoc", null)]
    public bool Equals(Speak other) {
      if (ReferenceEquals(other, null)) {
        return false;
      }
      if (ReferenceEquals(other, this)) {
        return true;
      }
      if (RC != other.RC) return false;
      if (UID != other.UID) return false;
      if (Id != other.Id) return false;
      if (Content != other.Content) return false;
      if(!contents_.Equals(other.contents_)) return false;
      return Equals(_unknownFields, other._unknownFields);
    }

    [global::System.Diagnostics.DebuggerNonUserCodeAttribute]
    [global::System.CodeDom.Compiler.GeneratedCode("protoc", null)]
    public override int GetHashCode() {
      int hash = 1;
      if (RC != global::Zee.Proto.Chat.ReturnCode.RcSuccess) hash ^= RC.GetHashCode();
      if (UID != 0L) hash ^= UID.GetHashCode();
      if (Id.Length != 0) hash ^= Id.GetHashCode();
      if (Content.Length != 0) hash ^= Content.GetHashCode();
      hash ^= contents_.GetHashCode();
      if (_unknownFields != null) {
        hash ^= _unknownFields.GetHashCode();
      }
      return hash;
    }

    [global::System.Diagnostics.DebuggerNonUserCodeAttribute]
    [global::System.CodeDom.Compiler.GeneratedCode("protoc", null)]
    public override string ToString() {
      return pb::JsonFormatter.ToDiagnosticString(this);
    }

    [global::System.Diagnostics.DebuggerNonUserCodeAttribute]
    [global::System.CodeDom.Compiler.GeneratedCode("protoc", null)]
    public void WriteTo(pb::CodedOutputStream output) {
    #if !GOOGLE_PROTOBUF_REFSTRUCT_COMPATIBILITY_MODE
      output.WriteRawMessage(this);
    #else
      if (RC != global::Zee.Proto.Chat.ReturnCode.RcSuccess) {
        output.WriteRawTag(8);
        output.WriteEnum((int) RC);
      }
      if (UID != 0L) {
        output.WriteRawTag(16);
        output.WriteInt64(UID);
      }
      if (Id.Length != 0) {
        output.WriteRawTag(26);
        output.WriteString(Id);
      }
      if (Content.Length != 0) {
        output.WriteRawTag(34);
        output.WriteString(Content);
      }
      contents_.WriteTo(output, _repeated_contents_codec);
      if (_unknownFields != null) {
        _unknownFields.WriteTo(output);
      }
    #endif
    }

    #if !GOOGLE_PROTOBUF_REFSTRUCT_COMPATIBILITY_MODE
    [global::System.Diagnostics.DebuggerNonUserCodeAttribute]
    [global::System.CodeDom.Compiler.GeneratedCode("protoc", null)]
    void pb::IBufferMessage.InternalWriteTo(ref pb::WriteContext output) {
      if (RC != global::Zee.Proto.Chat.ReturnCode.RcSuccess) {
        output.WriteRawTag(8);
        output.WriteEnum((int) RC);
      }
      if (UID != 0L) {
        output.WriteRawTag(16);
        output.WriteInt64(UID);
      }
      if (Id.Length != 0) {
        output.WriteRawTag(26);
        output.WriteString(Id);
      }
      if (Content.Length != 0) {
        output.WriteRawTag(34);
        output.WriteString(Content);
      }
      contents_.WriteTo(ref output, _repeated_contents_codec);
      if (_unknownFields != null) {
        _unknownFields.WriteTo(ref output);
      }
    }
    #endif

    [global::System.Diagnostics.DebuggerNonUserCodeAttribute]
    [global::System.CodeDom.Compiler.GeneratedCode("protoc", null)]
    public int CalculateSize() {
      int size = 0;
      if (RC != global::Zee.Proto.Chat.ReturnCode.RcSuccess) {
        size += 1 + pb::CodedOutputStream.ComputeEnumSize((int) RC);
      }
      if (UID != 0L) {
        size += 1 + pb::CodedOutputStream.ComputeInt64Size(UID);
      }
      if (Id.Length != 0) {
        size += 1 + pb::CodedOutputStream.ComputeStringSize(Id);
      }
      if (Content.Length != 0) {
        size += 1 + pb::CodedOutputStream.ComputeStringSize(Content);
      }
      size += contents_.CalculateSize(_repeated_contents_codec);
      if (_unknownFields != null) {
        size += _unknownFields.CalculateSize();
      }
      return size;
    }

    [global::System.Diagnostics.DebuggerNonUserCodeAttribute]
    [global::System.CodeDom.Compiler.GeneratedCode("protoc", null)]
    public void MergeFrom(Speak other) {
      if (other == null) {
        return;
      }
      if (other.RC != global::Zee.Proto.Chat.ReturnCode.RcSuccess) {
        RC = other.RC;
      }
      if (other.UID != 0L) {
        UID = other.UID;
      }
      if (other.Id.Length != 0) {
        Id = other.Id;
      }
      if (other.Content.Length != 0) {
        Content = other.Content;
      }
      contents_.Add(other.contents_);
      _unknownFields = pb::UnknownFieldSet.MergeFrom(_unknownFields, other._unknownFields);
    }

    [global::System.Diagnostics.DebuggerNonUserCodeAttribute]
    [global::System.CodeDom.Compiler.GeneratedCode("protoc", null)]
    public void MergeFrom(pb::CodedInputStream input) {
    #if !GOOGLE_PROTOBUF_REFSTRUCT_COMPATIBILITY_MODE
      input.ReadRawMessage(this);
    #else
      uint tag;
      while ((tag = input.ReadTag()) != 0) {
        switch(tag) {
          default:
            _unknownFields = pb::UnknownFieldSet.MergeFieldFrom(_unknownFields, input);
            break;
          case 8: {
            RC = (global::Zee.Proto.Chat.ReturnCode) input.ReadEnum();
            break;
          }
          case 16: {
            UID = input.ReadInt64();
            break;
          }
          case 26: {
            Id = input.ReadString();
            break;
          }
          case 34: {
            Content = input.ReadString();
            break;
          }
          case 42: {
            contents_.AddEntriesFrom(input, _repeated_contents_codec);
            break;
          }
        }
      }
    #endif
    }

    #if !GOOGLE_PROTOBUF_REFSTRUCT_COMPATIBILITY_MODE
    [global::System.Diagnostics.DebuggerNonUserCodeAttribute]
    [global::System.CodeDom.Compiler.GeneratedCode("protoc", null)]
    void pb::IBufferMessage.InternalMergeFrom(ref pb::ParseContext input) {
      uint tag;
      while ((tag = input.ReadTag()) != 0) {
        switch(tag) {
          default:
            _unknownFields = pb::UnknownFieldSet.MergeFieldFrom(_unknownFields, ref input);
            break;
          case 8: {
            RC = (global::Zee.Proto.Chat.ReturnCode) input.ReadEnum();
            break;
          }
          case 16: {
            UID = input.ReadInt64();
            break;
          }
          case 26: {
            Id = input.ReadString();
            break;
          }
          case 34: {
            Content = input.ReadString();
            break;
          }
          case 42: {
            contents_.AddEntriesFrom(ref input, _repeated_contents_codec);
            break;
          }
        }
      }
    }
    #endif

  }

  #endregion

}

#endregion Designer generated code

