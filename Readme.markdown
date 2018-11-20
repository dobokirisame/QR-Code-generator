C++ QR Code generator library
=========================


Introduction
------------

This project is cropped version of original multilanguage project.
It reworked to build with cmake.


More information about QR Code technology and this library's design can be found on the project home page.

Install
--------
    cd project
    mkdir BUILD
    cd BUILD
    cmake -DCMAKE_INSTALL_PREFIX:PATH=${PREFIX} ..
    make
    make install

 
Example
--------

C++ language:

    #include <string>
    #include <vector>
    #include "QrCode.h"
    using namespace qrcodegen;
    
    // Simple operation
    QrCode qr0 = QrCode::encodeText("Hello, world!", QrCode::Ecc::MEDIUM);
    std::string svg = qr0.toSvgString(4);
    
    // Manual operation
    std::vector<QrSegment> segs =
        QrSegment::makeSegments("3141592653589793238462643383");
    QrCode qr1 = QrCode::encodeSegments(
        segs, QrCode::Ecc::HIGH, 5, 5, 2, false);
    for (int y = 0; y < qr1.getSize(); y++) {
        for (int x = 0; x < qr1.getSize(); x++) {
            (... paint qr1.getModule(x, y) ...)
        }
    }

