cmake_minimum_required(VERSION 3.1)
project(qrcodegen VERSION 4.1.1)
set(TARGET_NAME qrcodegen)
set(CMAKE_CXX_STANDARD 11)
add_library(qrcodegen SHARED BitBuffer.cpp QrCode.cpp QrCodeGeneratorDemo.cpp QrCodeGeneratorWorker.cpp QrSegment.cpp)
set_target_properties(qrcodegen PROPERTIES VERSION "1.4.0")
set_target_properties(qrcodegen PROPERTIES PUBLIC_HEADER  )
target_include_directories(qrcodegen PRIVATE include)
target_link_libraries(qrcodegen)
install(TARGETS qrcodegen RUNTIME DESTINATION lib
    LIBRARY DESTINATION lib
    ARCHIVE DESTINATION lib)
install(FILES include/BitBuffer.h include/QrCode.h include/QrSegment.h DESTINATION include/qrcodegen)
