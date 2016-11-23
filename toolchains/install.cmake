cmake_minimum_required(VERSION 3.0)

install(
  FILES "${CMAKE_CURRENT_LIST_DIR}/common.cmake"
  DESTINATION "${TOOLCHAINS_DELIV_DIR}"
)

if(__AGILIB_EMBEDDED)
install(
  FILES "${CMAKE_CURRENT_LIST_DIR}/embedded.cmake"
  DESTINATION "${TOOLCHAINS_DELIV_DIR}"
)
endif()

if(__AGILIB_PLATFORM_AVR)
install(
  FILES "${CMAKE_CURRENT_LIST_DIR}/AVR/AVR.cmake"
  DESTINATION "${TOOLCHAINS_DELIV_DIR}/AVR"
)
endif()

if(__AGILIB_FAMILY_AVR_megaAVR)
install(
  FILES
    "${CMAKE_CURRENT_LIST_DIR}/AVR/megaAVR.cmake"
    "${CMAKE_CURRENT_LIST_DIR}/AVR/${__AGILIB_CPU}.cmake"
  DESTINATION "${TOOLCHAINS_DELIV_DIR}/AVR"
)
endif()