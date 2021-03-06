target_include_directories(slgh-compile PRIVATE ${DEPS_GHIDRA}/include)
target_include_directories(coronium PRIVATE ${DEPS_GHIDRA}/include)

target_sources(
  slgh-compile
  PRIVATE
  ${CMAKE_BINARY_DIR}/src/pcodeparse.cc
  ${CMAKE_BINARY_DIR}/src/slghparse.cc
  ${CMAKE_BINARY_DIR}/src/slghscan.cc
  ${CMAKE_BINARY_DIR}/src/xml.cc
  address.cc
  context.cc
  filemanage.cc
  float.cc
  globalcontext.cc
  opcodes.cc
  pcodecompile.cc
  pcoderaw.cc
  semantics.cc
  sleighbase.cc
  sleigh.cc
  slgh_compile.cc
  slghpatexpress.cc
  slghpattern.cc
  slghsymbol.cc
  space.cc
  translate.cc
)

target_sources(
  coronium
  PRIVATE
  ${CMAKE_BINARY_DIR}/src/pcodeparse.cc # PcodeSnippet
  ${CMAKE_BINARY_DIR}/src/xml.cc
  action.cc
  address.cc
  architecture.cc
  blockaction.cc
  block.cc
  capability.cc
  cast.cc
  comment.cc
  condexe.cc
  context.cc
  coreaction.cc
  cover.cc
  cpool.cc
  crc32.cc
  database.cc
  double.cc
  dynamic.cc
  emulate.cc
  emulateutil.cc
  filemanage.cc
  float.cc
  flow.cc
  fspec.cc
  funcdata_block.cc
  funcdata.cc
  funcdata_op.cc
  funcdata_varnode.cc
  globalcontext.cc
  heritage.cc
  inject_sleigh.cc
  jumptable.cc
  loadimage.cc
  memstate.cc
  merge.cc
  opbehavior.cc
  op.cc
  opcodes.cc
  options.cc
  override.cc
  pcodecompile.cc
  pcodeinject.cc
  pcoderaw.cc
  prefersplit.cc
  prettyprint.cc
  printc.cc
  printlanguage.cc
  rangeutil.cc
  ruleaction.cc
  semantics.cc
  sleigh_arch.cc
  sleighbase.cc
  sleigh.cc
  slghpatexpress.cc
  slghpattern.cc
  slghsymbol.cc
  space.cc
  stringmanage.cc
  subflow.cc
  transform.cc
  translate.cc
  type.cc
  typeop.cc
  userop.cc
  variable.cc
  varmap.cc
  varnode.cc
  unionresolve.cc
)

if(BFD)
  target_sources(
    coronium
    PRIVATE
    bfd_arch.cc
    loadimage_bfd.cc
  )
endif()

