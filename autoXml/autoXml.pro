#-------------------------------------------------
#
# Project created by QtCreator 2019-01-06T12:06:47
#
#-------------------------------------------------

QT       += core gui xml

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = autoXml
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

INCLUDEPATH += $$PWD/x2struct-master
include (../PUBLIC/ShareTools/ShareTools.pri)

SOURCES += \
        main.cpp \
        widget.cpp

HEADERS += \
        widget.h \
           x2struct-master/bson_builder.h \
           x2struct-master/bson_reader.h \
           x2struct-master/bson_writer.h \
           x2struct-master/config.h \
           x2struct-master/config_reader.h \
           x2struct-master/config_writer.h \
           x2struct-master/go_writer.h \
           x2struct-master/json_reader.h \
           x2struct-master/json_writer.h \
           x2struct-master/rapidjson_custom.h \
           x2struct-master/traits.h \
           x2struct-master/util.h \
           x2struct-master/x2struct.hpp \
           x2struct-master/xml_reader.h \
           x2struct-master/xml_writer.h \
           x2struct-master/xreader.h \
           x2struct-master/xtypes.h \
           x2struct-master/thirdparty/rapidjson/allocators.h \
           x2struct-master/thirdparty/rapidjson/cursorstreamwrapper.h \
           x2struct-master/thirdparty/rapidjson/document.h \
           x2struct-master/thirdparty/rapidjson/encodedstream.h \
           x2struct-master/thirdparty/rapidjson/encodings.h \
           x2struct-master/thirdparty/rapidjson/filereadstream.h \
           x2struct-master/thirdparty/rapidjson/filewritestream.h \
           x2struct-master/thirdparty/rapidjson/fwd.h \
           x2struct-master/thirdparty/rapidjson/istreamwrapper.h \
           x2struct-master/thirdparty/rapidjson/memorybuffer.h \
           x2struct-master/thirdparty/rapidjson/memorystream.h \
           x2struct-master/thirdparty/rapidjson/ostreamwrapper.h \
           x2struct-master/thirdparty/rapidjson/pointer.h \
           x2struct-master/thirdparty/rapidjson/prettywriter.h \
           x2struct-master/thirdparty/rapidjson/rapidjson.h \
           x2struct-master/thirdparty/rapidjson/reader.h \
           x2struct-master/thirdparty/rapidjson/schema.h \
           x2struct-master/thirdparty/rapidjson/stream.h \
           x2struct-master/thirdparty/rapidjson/stringbuffer.h \
           x2struct-master/thirdparty/rapidjson/writer.h \
           x2struct-master/thirdparty/rapidxml/rapidxml.hpp \
           x2struct-master/thirdparty/rapidxml/rapidxml_iterators.hpp \
           x2struct-master/thirdparty/rapidxml/rapidxml_print.hpp \
           x2struct-master/thirdparty/rapidxml/rapidxml_utils.hpp \
           x2struct-master/thirdparty/rapidjson/error/en.h \
           x2struct-master/thirdparty/rapidjson/error/error.h \
           x2struct-master/thirdparty/rapidjson/internal/biginteger.h \
           x2struct-master/thirdparty/rapidjson/internal/diyfp.h \
           x2struct-master/thirdparty/rapidjson/internal/dtoa.h \
           x2struct-master/thirdparty/rapidjson/internal/ieee754.h \
           x2struct-master/thirdparty/rapidjson/internal/itoa.h \
           x2struct-master/thirdparty/rapidjson/internal/meta.h \
           x2struct-master/thirdparty/rapidjson/internal/pow10.h \
           x2struct-master/thirdparty/rapidjson/internal/regex.h \
           x2struct-master/thirdparty/rapidjson/internal/stack.h \
           x2struct-master/thirdparty/rapidjson/internal/strfunc.h \
           x2struct-master/thirdparty/rapidjson/internal/strtod.h \
           x2struct-master/thirdparty/rapidjson/internal/swap.h \
           x2struct-master/thirdparty/rapidjson/msinttypes/inttypes.h \
           x2struct-master/thirdparty/rapidjson/msinttypes/stdint.h \
           x2struct-master/thirdparty/libbson/include/libbson-1.0/bcon.h \
           x2struct-master/thirdparty/libbson/include/libbson-1.0/bson-atomic.h \
           x2struct-master/thirdparty/libbson/include/libbson-1.0/bson-clock.h \
           x2struct-master/thirdparty/libbson/include/libbson-1.0/bson-compat.h \
           x2struct-master/thirdparty/libbson/include/libbson-1.0/bson-config.h \
           x2struct-master/thirdparty/libbson/include/libbson-1.0/bson-context.h \
           x2struct-master/thirdparty/libbson/include/libbson-1.0/bson-decimal128.h \
           x2struct-master/thirdparty/libbson/include/libbson-1.0/bson-endian.h \
           x2struct-master/thirdparty/libbson/include/libbson-1.0/bson-error.h \
           x2struct-master/thirdparty/libbson/include/libbson-1.0/bson-iter.h \
           x2struct-master/thirdparty/libbson/include/libbson-1.0/bson-json.h \
           x2struct-master/thirdparty/libbson/include/libbson-1.0/bson-keys.h \
           x2struct-master/thirdparty/libbson/include/libbson-1.0/bson-macros.h \
           x2struct-master/thirdparty/libbson/include/libbson-1.0/bson-md5.h \
           x2struct-master/thirdparty/libbson/include/libbson-1.0/bson-memory.h \
           x2struct-master/thirdparty/libbson/include/libbson-1.0/bson-oid.h \
           x2struct-master/thirdparty/libbson/include/libbson-1.0/bson-reader.h \
           x2struct-master/thirdparty/libbson/include/libbson-1.0/bson-stdint.h \
           x2struct-master/thirdparty/libbson/include/libbson-1.0/bson-string.h \
           x2struct-master/thirdparty/libbson/include/libbson-1.0/bson-types.h \
           x2struct-master/thirdparty/libbson/include/libbson-1.0/bson-utf8.h \
           x2struct-master/thirdparty/libbson/include/libbson-1.0/bson-value.h \
           x2struct-master/thirdparty/libbson/include/libbson-1.0/bson-version-functions.h \
           x2struct-master/thirdparty/libbson/include/libbson-1.0/bson-version.h \
           x2struct-master/thirdparty/libbson/include/libbson-1.0/bson-writer.h \
           x2struct-master/thirdparty/libbson/include/libbson-1.0/bson.h \
           /x2struct-master/x2struct.hpp \
           /x2struct-master/thirdparty/rapidjson/msinttypes/stdint.h \
           /x2struct-master/thirdparty/rapidjson/msinttypes/inttypes.h \
           x2struct-master/thirdparty/libconfig/include/libconfig.h++ \
    OTHER.h
FORMS += \
        widget.ui

CONFIG += c++14

DEFINES += XTOSTRUCT_XML

DISTFILES += \
    x2struct-master/README.md \
    x2struct-master/README.zh-cn.md

RESOURCES += \
    res.qrc
