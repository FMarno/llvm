// NOTE: Assertions have been autogenerated by utils/update_cc_test_checks.py UTC_ARGS: --version 5
// RUN: %clangxx -O3 -fsycl -fsycl-device-only -fno-discard-value-names -S -emit-llvm -fno-sycl-instrument-device-code  -o - %s | FileCheck %s

// Linux/Windows have minor differences in the generated IR (e.g. TBAA
// metadata). Having linux-only checks eases the maintenance without sacrifising
// coverage of what's important for this test.
// REQUIRES: linux

#include <sycl/sycl.hpp>

using namespace sycl;
using namespace sycl::ext::oneapi::experimental;

namespace static_as_cast {
// CHECK-LABEL: define dso_local spir_func void @_ZN14static_as_cast19to_global_decoratedEPi(
// CHECK-SAME: ptr addrspace(4) dead_on_unwind noalias nocapture writable writeonly sret(%"class.sycl::_V1::multi_ptr") align 8 [[AGG_RESULT:%.*]], ptr addrspace(4) noundef [[P:%.*]]) local_unnamed_addr #[[ATTR0:[0-9]+]] !srcloc [[META6:![0-9]+]] !sycl_fixed_targets [[META7:![0-9]+]] {
// CHECK-NEXT:  [[ENTRY:.*:]]
// CHECK-NEXT:    [[CALL_I_I_I:%.*]] = tail call spir_func noundef ptr addrspace(1) @_Z33__spirv_GenericCastToPtr_ToGlobalPvi(ptr addrspace(4) noundef [[P]], i32 noundef 5) #[[ATTR3:[0-9]+]]
// CHECK-NEXT:    store ptr addrspace(1) [[CALL_I_I_I]], ptr addrspace(4) [[AGG_RESULT]], align 8, !tbaa [[TBAA8:![0-9]+]], !alias.scope [[META13:![0-9]+]]
// CHECK-NEXT:    ret void
//
SYCL_EXTERNAL auto to_global_decorated(int *p) {
  return static_address_cast<access::address_space::global_space,
                             access::decorated::yes>(p);
}
// CHECK-LABEL: define dso_local spir_func void @_ZN14static_as_cast23to_global_not_decoratedEPi(
// CHECK-SAME: ptr addrspace(4) dead_on_unwind noalias nocapture writable writeonly sret(%"class.sycl::_V1::multi_ptr.0") align 8 [[AGG_RESULT:%.*]], ptr addrspace(4) noundef [[P:%.*]]) local_unnamed_addr #[[ATTR0]] !srcloc [[META16:![0-9]+]] !sycl_fixed_targets [[META7]] {
// CHECK-NEXT:  [[ENTRY:.*:]]
// CHECK-NEXT:    [[CALL_I_I_I:%.*]] = tail call spir_func noundef ptr addrspace(1) @_Z33__spirv_GenericCastToPtr_ToGlobalPvi(ptr addrspace(4) noundef [[P]], i32 noundef 5) #[[ATTR3]]
// CHECK-NEXT:    store ptr addrspace(1) [[CALL_I_I_I]], ptr addrspace(4) [[AGG_RESULT]], align 8, !tbaa [[TBAA17:![0-9]+]], !alias.scope [[META19:![0-9]+]]
// CHECK-NEXT:    ret void
//
SYCL_EXTERNAL auto to_global_not_decorated(int *p) {
  return static_address_cast<access::address_space::global_space,
                             access::decorated::no>(p);
}
// CHECK-LABEL: define dso_local spir_func void @_ZN14static_as_cast20to_generic_decoratedEPi(
// CHECK-SAME: ptr addrspace(4) dead_on_unwind noalias nocapture writable writeonly sret(%"class.sycl::_V1::multi_ptr.1") align 8 [[AGG_RESULT:%.*]], ptr addrspace(4) noundef [[P:%.*]]) local_unnamed_addr #[[ATTR2:[0-9]+]] !srcloc [[META22:![0-9]+]] !sycl_fixed_targets [[META7]] {
// CHECK-NEXT:  [[ENTRY:.*:]]
// CHECK-NEXT:    store ptr addrspace(4) [[P]], ptr addrspace(4) [[AGG_RESULT]], align 8, !tbaa [[TBAA23:![0-9]+]], !alias.scope [[META25:![0-9]+]]
// CHECK-NEXT:    ret void
//
SYCL_EXTERNAL auto to_generic_decorated(int *p) {
  return static_address_cast<access::address_space::generic_space,
                             access::decorated::yes>(p);
}
// CHECK-LABEL: define dso_local spir_func void @_ZN14static_as_cast24to_generic_not_decoratedEPi(
// CHECK-SAME: ptr addrspace(4) dead_on_unwind noalias nocapture writable writeonly sret(%"class.sycl::_V1::multi_ptr.2") align 8 [[AGG_RESULT:%.*]], ptr addrspace(4) noundef [[P:%.*]]) local_unnamed_addr #[[ATTR2]] !srcloc [[META28:![0-9]+]] !sycl_fixed_targets [[META7]] {
// CHECK-NEXT:  [[ENTRY:.*:]]
// CHECK-NEXT:    store ptr addrspace(4) [[P]], ptr addrspace(4) [[AGG_RESULT]], align 8, !tbaa [[TBAA29:![0-9]+]], !alias.scope [[META31:![0-9]+]]
// CHECK-NEXT:    ret void
//
SYCL_EXTERNAL auto to_generic_not_decorated(int *p) {
  return static_address_cast<access::address_space::generic_space,
                             access::decorated::no>(p);
}
} // namespace static_as_cast

namespace dynamic_as_cast {
// CHECK-LABEL: define dso_local spir_func void @_ZN15dynamic_as_cast19to_global_decoratedEPi(
// CHECK-SAME: ptr addrspace(4) dead_on_unwind noalias nocapture writable writeonly sret(%"class.sycl::_V1::multi_ptr") align 8 [[AGG_RESULT:%.*]], ptr addrspace(4) noundef [[P:%.*]]) local_unnamed_addr #[[ATTR0]] !srcloc [[META34:![0-9]+]] !sycl_fixed_targets [[META7]] {
// CHECK-NEXT:  [[ENTRY:.*:]]
// CHECK-NEXT:    [[CALL_I_I_I:%.*]] = tail call spir_func noundef ptr addrspace(1) @_Z41__spirv_GenericCastToPtrExplicit_ToGlobalPvi(ptr addrspace(4) noundef [[P]], i32 noundef 5) #[[ATTR3]]
// CHECK-NEXT:    store ptr addrspace(1) [[CALL_I_I_I]], ptr addrspace(4) [[AGG_RESULT]], align 8, !tbaa [[TBAA8]], !alias.scope [[META35:![0-9]+]]
// CHECK-NEXT:    ret void
//
SYCL_EXTERNAL auto to_global_decorated(int *p) {
  return dynamic_address_cast<access::address_space::global_space,
                              access::decorated::yes>(p);
}
// CHECK-LABEL: define dso_local spir_func void @_ZN15dynamic_as_cast23to_global_not_decoratedEPi(
// CHECK-SAME: ptr addrspace(4) dead_on_unwind noalias nocapture writable writeonly sret(%"class.sycl::_V1::multi_ptr.0") align 8 [[AGG_RESULT:%.*]], ptr addrspace(4) noundef [[P:%.*]]) local_unnamed_addr #[[ATTR0]] !srcloc [[META38:![0-9]+]] !sycl_fixed_targets [[META7]] {
// CHECK-NEXT:  [[ENTRY:.*:]]
// CHECK-NEXT:    [[CALL_I_I_I:%.*]] = tail call spir_func noundef ptr addrspace(1) @_Z41__spirv_GenericCastToPtrExplicit_ToGlobalPvi(ptr addrspace(4) noundef [[P]], i32 noundef 5) #[[ATTR3]]
// CHECK-NEXT:    store ptr addrspace(1) [[CALL_I_I_I]], ptr addrspace(4) [[AGG_RESULT]], align 8, !tbaa [[TBAA17]], !alias.scope [[META39:![0-9]+]]
// CHECK-NEXT:    ret void
//
SYCL_EXTERNAL auto to_global_not_decorated(int *p) {
  return dynamic_address_cast<access::address_space::global_space,
                              access::decorated::no>(p);
}
// CHECK-LABEL: define dso_local spir_func void @_ZN15dynamic_as_cast20to_generic_decoratedEPi(
// CHECK-SAME: ptr addrspace(4) dead_on_unwind noalias nocapture writable writeonly sret(%"class.sycl::_V1::multi_ptr.1") align 8 [[AGG_RESULT:%.*]], ptr addrspace(4) noundef [[P:%.*]]) local_unnamed_addr #[[ATTR2]] !srcloc [[META42:![0-9]+]] !sycl_fixed_targets [[META7]] {
// CHECK-NEXT:  [[ENTRY:.*:]]
// CHECK-NEXT:    store ptr addrspace(4) [[P]], ptr addrspace(4) [[AGG_RESULT]], align 8, !tbaa [[TBAA23]], !alias.scope [[META43:![0-9]+]]
// CHECK-NEXT:    ret void
//
SYCL_EXTERNAL auto to_generic_decorated(int *p) {
  return dynamic_address_cast<access::address_space::generic_space,
                              access::decorated::yes>(p);
}
// CHECK-LABEL: define dso_local spir_func void @_ZN15dynamic_as_cast24to_generic_not_decoratedEPi(
// CHECK-SAME: ptr addrspace(4) dead_on_unwind noalias nocapture writable writeonly sret(%"class.sycl::_V1::multi_ptr.2") align 8 [[AGG_RESULT:%.*]], ptr addrspace(4) noundef [[P:%.*]]) local_unnamed_addr #[[ATTR2]] !srcloc [[META46:![0-9]+]] !sycl_fixed_targets [[META7]] {
// CHECK-NEXT:  [[ENTRY:.*:]]
// CHECK-NEXT:    store ptr addrspace(4) [[P]], ptr addrspace(4) [[AGG_RESULT]], align 8, !tbaa [[TBAA29]], !alias.scope [[META47:![0-9]+]]
// CHECK-NEXT:    ret void
//
SYCL_EXTERNAL auto to_generic_not_decorated(int *p) {
  return dynamic_address_cast<access::address_space::generic_space,
                              access::decorated::no>(p);
}
} // namespace dynamic_as_cast
