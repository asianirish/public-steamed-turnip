TEMPLATE = app
CONFIG += console c++17
CONFIG -= app_bundle
CONFIG -= qt

TARGET = turnip

SOURCES += \
        App.cpp \
        ThisApp.cpp \
        cmd/Action.cpp \
        cmd/Global.cpp \
        cmd/Info.cpp \
        cmd/LineTranslator.cpp \
        cmd/Menu.cpp \
        cmd/PrintAction.cpp \
        cmd/Task.cpp \
        cmd/TaskManager.cpp \
        cmd/Translator.cpp \
        cmd/Value.cpp \
        cmd/def/ActionDef.cpp \
        cmd/def/ArgDef.cpp \
        cmd/def/TypeDef.cpp \
        cmd/err/AdditionalInfo.cpp \
        cmd/err/ArgumentConversionInfo.cpp \
        cmd/err/ArgumentInfo.cpp \
        cmd/err/ConversionException.cpp \
        cmd/err/Error.cpp \
        cmd/err/MissingRequiredArgumentInfo.cpp \
        cmd/rep/BoolRep.cpp \
        cmd/rep/CharRep.cpp \
        cmd/rep/DecIntRep.cpp \
        cmd/rep/HexIntRep.cpp \
        cmd/rep/IntRep.cpp \
        cmd/rep/NullRep.cpp \
        cmd/rep/Representation.cpp \
        cmd/rep/RepresentationManager.cpp \
        cmd/rep/SimpleCharRep.cpp \
        cmd/rep/SimpleStringRep.cpp \
        cmd/rep/StringRep.cpp \
        console/Reader.cpp \
        main.cpp

HEADERS += \
    App.h \
    ThisApp.h \
    cmd/Action.h \
    cmd/Global.h \
    cmd/Info.h \
    cmd/LineTranslator.h \
    cmd/Menu.h \
    cmd/PrintAction.h \
    cmd/Task.h \
    cmd/TaskManager.h \
    cmd/Translator.h \
    cmd/Types.h \
    cmd/Value.h \
    cmd/def/ActionDef.h \
    cmd/def/ArgDef.h \
    cmd/def/TypeDef.h \
    cmd/err/AdditionalInfo.h \
    cmd/err/ArgumentConversionInfo.h \
    cmd/err/ArgumentInfo.h \
    cmd/err/ConversionException.h \
    cmd/err/Error.h \
    cmd/err/MissingRequiredArgumentInfo.h \
    cmd/rep/BoolRep.h \
    cmd/rep/CharRep.h \
    cmd/rep/DecIntRep.h \
    cmd/rep/HexIntRep.h \
    cmd/rep/IntRep.h \
    cmd/rep/NullRep.h \
    cmd/rep/Representation.h \
    cmd/rep/RepresentationManager.h \
    cmd/rep/SimpleCharRep.h \
    cmd/rep/SimpleStringRep.h \
    cmd/rep/StringRep.h \
    common/Factory.h \
    common/LimitedStack.h \
    common/SharedMap.h \
    console/Reader.h
