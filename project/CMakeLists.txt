cmake_minimum_required(VERSION 3.1)
project(qrcodegen VERSION 4.1.1)
set(TARGET_NAME qrcodegen)
set(CMAKE_CXX_STANDARD 11)
set(SOURCES
    BitBuffer.cpp
    QrCode.cpp
    QrCodeGeneratorWorker.cpp
    QrSegment.cpp
    QrCodeImage.cpp
)
set(HEADERS
    BitBuffer.h
    QrCode.h
    QrSegment.h
    QrCodeImage.h
)
add_library(qrcodegen SHARED BitBuffer.cpp QrCode.cpp QrCodeGeneratorDemo.cpp QrCodeGeneratorWorker.cpp QrSegment.cpp)
target_link_libraries(qrcodegen)
install(TARGETS qrcodegen RUNTIME DESTINATION lib
    LIBRARY DESTINATION lib
    ARCHIVE DESTINATION lib)
install(FILES BitBuffer.h QrCode.h QrSegment.h DESTINATION include/qrcodegen)
