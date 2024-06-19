// <auto-generated>
//     Generated by the protocol buffer compiler.  DO NOT EDIT!
//     source: Packet.proto
// </auto-generated>
#pragma warning disable 1591, 0612, 3021
#region Designer generated code

using pb = global::Google.Protobuf;
using pbc = global::Google.Protobuf.Collections;
using pbr = global::Google.Protobuf.Reflection;
using scg = global::System.Collections.Generic;
namespace Zee.Proto.Packet {

  /// <summary>Holder for reflection information generated from Packet.proto</summary>
  public static partial class PacketReflection {

    #region Descriptor
    /// <summary>File descriptor for Packet.proto</summary>
    public static pbr::FileDescriptor Descriptor {
      get { return descriptor; }
    }
    private static pbr::FileDescriptor descriptor;

    static PacketReflection() {
      byte[] descriptorData = global::System.Convert.FromBase64String(
          string.Concat(
            "CgxQYWNrZXQucHJvdG8SEFplZS5Qcm90by5QYWNrZXQiaQoGSGVhZGVyEhIK",
            "ClBhY2tldFNpemUYASABKAUSDQoFUG9pbnQYAiABKAUSEAoIU2VxdWVuY2UY",
            "AyABKAUSKgoKUGFja2V0VHlwZRgEIAEoDjIWLlplZS5Qcm90by5QYWNrZXQu",
            "VHlwZSpcCgRUeXBlEggKBE5vbmUQABIKCgZOb3RpZnkQARILCgdSZXF1ZXN0",
            "EAISDAoIUmVzcG9uc2UQAxIOCgpOb1Jlc3BvbnNlEAQSEwoPUmVzcG9uc2VU",
            "aW1lb3V0EAViBnByb3RvMw=="));
      descriptor = pbr::FileDescriptor.FromGeneratedCode(descriptorData,
          new pbr::FileDescriptor[] { },
          new pbr::GeneratedClrTypeInfo(new[] {typeof(global::Zee.Proto.Packet.Type), }, null, new pbr::GeneratedClrTypeInfo[] {
            new pbr::GeneratedClrTypeInfo(typeof(global::Zee.Proto.Packet.Header), global::Zee.Proto.Packet.Header.Parser, new[]{ "PacketSize", "Point", "Sequence", "PacketType" }, null, null, null, null)
          }));
    }
    #endregion

  }
  #region Enums
  public enum Type {
    [pbr::OriginalName("None")] None = 0,
    [pbr::OriginalName("Notify")] Notify = 1,
    [pbr::OriginalName("Request")] Request = 2,
    [pbr::OriginalName("Response")] Response = 3,
    [pbr::OriginalName("NoResponse")] NoResponse = 4,
    [pbr::OriginalName("ResponseTimeout")] ResponseTimeout = 5,
  }

  #endregion

  #region Messages
  public sealed partial class Header : pb::IMessage<Header>
  #if !GOOGLE_PROTOBUF_REFSTRUCT_COMPATIBILITY_MODE
      , pb::IBufferMessage
  #endif
  {
    private static readonly pb::MessageParser<Header> _parser = new pb::MessageParser<Header>(() => new Header());
    private pb::UnknownFieldSet _unknownFields;
    [global::System.Diagnostics.DebuggerNonUserCodeAttribute]
    [global::System.CodeDom.Compiler.GeneratedCode("protoc", null)]
    public static pb::MessageParser<Header> Parser { get { return _parser; } }

    [global::System.Diagnostics.DebuggerNonUserCodeAttribute]
    [global::System.CodeDom.Compiler.GeneratedCode("protoc", null)]
    public static pbr::MessageDescriptor Descriptor {
      get { return global::Zee.Proto.Packet.PacketReflection.Descriptor.MessageTypes[0]; }
    }

    [global::System.Diagnostics.DebuggerNonUserCodeAttribute]
    [global::System.CodeDom.Compiler.GeneratedCode("protoc", null)]
    pbr::MessageDescriptor pb::IMessage.Descriptor {
      get { return Descriptor; }
    }

    [global::System.Diagnostics.DebuggerNonUserCodeAttribute]
    [global::System.CodeDom.Compiler.GeneratedCode("protoc", null)]
    public Header() {
      OnConstruction();
    }

    partial void OnConstruction();

    [global::System.Diagnostics.DebuggerNonUserCodeAttribute]
    [global::System.CodeDom.Compiler.GeneratedCode("protoc", null)]
    public Header(Header other) : this() {
      packetSize_ = other.packetSize_;
      point_ = other.point_;
      sequence_ = other.sequence_;
      packetType_ = other.packetType_;
      _unknownFields = pb::UnknownFieldSet.Clone(other._unknownFields);
    }

    [global::System.Diagnostics.DebuggerNonUserCodeAttribute]
    [global::System.CodeDom.Compiler.GeneratedCode("protoc", null)]
    public Header Clone() {
      return new Header(this);
    }

    /// <summary>Field number for the "PacketSize" field.</summary>
    public const int PacketSizeFieldNumber = 1;
    private int packetSize_;
    [global::System.Diagnostics.DebuggerNonUserCodeAttribute]
    [global::System.CodeDom.Compiler.GeneratedCode("protoc", null)]
    public int PacketSize {
      get { return packetSize_; }
      set {
        packetSize_ = value;
      }
    }

    /// <summary>Field number for the "Point" field.</summary>
    public const int PointFieldNumber = 2;
    private int point_;
    [global::System.Diagnostics.DebuggerNonUserCodeAttribute]
    [global::System.CodeDom.Compiler.GeneratedCode("protoc", null)]
    public int Point {
      get { return point_; }
      set {
        point_ = value;
      }
    }

    /// <summary>Field number for the "Sequence" field.</summary>
    public const int SequenceFieldNumber = 3;
    private int sequence_;
    [global::System.Diagnostics.DebuggerNonUserCodeAttribute]
    [global::System.CodeDom.Compiler.GeneratedCode("protoc", null)]
    public int Sequence {
      get { return sequence_; }
      set {
        sequence_ = value;
      }
    }

    /// <summary>Field number for the "PacketType" field.</summary>
    public const int PacketTypeFieldNumber = 4;
    private global::Zee.Proto.Packet.Type packetType_ = global::Zee.Proto.Packet.Type.None;
    [global::System.Diagnostics.DebuggerNonUserCodeAttribute]
    [global::System.CodeDom.Compiler.GeneratedCode("protoc", null)]
    public global::Zee.Proto.Packet.Type PacketType {
      get { return packetType_; }
      set {
        packetType_ = value;
      }
    }

    [global::System.Diagnostics.DebuggerNonUserCodeAttribute]
    [global::System.CodeDom.Compiler.GeneratedCode("protoc", null)]
    public override bool Equals(object other) {
      return Equals(other as Header);
    }

    [global::System.Diagnostics.DebuggerNonUserCodeAttribute]
    [global::System.CodeDom.Compiler.GeneratedCode("protoc", null)]
    public bool Equals(Header other) {
      if (ReferenceEquals(other, null)) {
        return false;
      }
      if (ReferenceEquals(other, this)) {
        return true;
      }
      if (PacketSize != other.PacketSize) return false;
      if (Point != other.Point) return false;
      if (Sequence != other.Sequence) return false;
      if (PacketType != other.PacketType) return false;
      return Equals(_unknownFields, other._unknownFields);
    }

    [global::System.Diagnostics.DebuggerNonUserCodeAttribute]
    [global::System.CodeDom.Compiler.GeneratedCode("protoc", null)]
    public override int GetHashCode() {
      int hash = 1;
      if (PacketSize != 0) hash ^= PacketSize.GetHashCode();
      if (Point != 0) hash ^= Point.GetHashCode();
      if (Sequence != 0) hash ^= Sequence.GetHashCode();
      if (PacketType != global::Zee.Proto.Packet.Type.None) hash ^= PacketType.GetHashCode();
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
      if (PacketSize != 0) {
        output.WriteRawTag(8);
        output.WriteInt32(PacketSize);
      }
      if (Point != 0) {
        output.WriteRawTag(16);
        output.WriteInt32(Point);
      }
      if (Sequence != 0) {
        output.WriteRawTag(24);
        output.WriteInt32(Sequence);
      }
      if (PacketType != global::Zee.Proto.Packet.Type.None) {
        output.WriteRawTag(32);
        output.WriteEnum((int) PacketType);
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
      if (PacketSize != 0) {
        output.WriteRawTag(8);
        output.WriteInt32(PacketSize);
      }
      if (Point != 0) {
        output.WriteRawTag(16);
        output.WriteInt32(Point);
      }
      if (Sequence != 0) {
        output.WriteRawTag(24);
        output.WriteInt32(Sequence);
      }
      if (PacketType != global::Zee.Proto.Packet.Type.None) {
        output.WriteRawTag(32);
        output.WriteEnum((int) PacketType);
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
      if (PacketSize != 0) {
        size += 1 + pb::CodedOutputStream.ComputeInt32Size(PacketSize);
      }
      if (Point != 0) {
        size += 1 + pb::CodedOutputStream.ComputeInt32Size(Point);
      }
      if (Sequence != 0) {
        size += 1 + pb::CodedOutputStream.ComputeInt32Size(Sequence);
      }
      if (PacketType != global::Zee.Proto.Packet.Type.None) {
        size += 1 + pb::CodedOutputStream.ComputeEnumSize((int) PacketType);
      }
      if (_unknownFields != null) {
        size += _unknownFields.CalculateSize();
      }
      return size;
    }

    [global::System.Diagnostics.DebuggerNonUserCodeAttribute]
    [global::System.CodeDom.Compiler.GeneratedCode("protoc", null)]
    public void MergeFrom(Header other) {
      if (other == null) {
        return;
      }
      if (other.PacketSize != 0) {
        PacketSize = other.PacketSize;
      }
      if (other.Point != 0) {
        Point = other.Point;
      }
      if (other.Sequence != 0) {
        Sequence = other.Sequence;
      }
      if (other.PacketType != global::Zee.Proto.Packet.Type.None) {
        PacketType = other.PacketType;
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
            PacketSize = input.ReadInt32();
            break;
          }
          case 16: {
            Point = input.ReadInt32();
            break;
          }
          case 24: {
            Sequence = input.ReadInt32();
            break;
          }
          case 32: {
            PacketType = (global::Zee.Proto.Packet.Type) input.ReadEnum();
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
            PacketSize = input.ReadInt32();
            break;
          }
          case 16: {
            Point = input.ReadInt32();
            break;
          }
          case 24: {
            Sequence = input.ReadInt32();
            break;
          }
          case 32: {
            PacketType = (global::Zee.Proto.Packet.Type) input.ReadEnum();
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

