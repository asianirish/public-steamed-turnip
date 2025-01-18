TEMPLATE = app
CONFIG += console c++17
CONFIG -= app_bundle
CONFIG -= qt

TARGET = turnip

DEFINES += TARGET_NAME=\\\"$$TARGET\\\"

SOURCES += \
        App.cpp \
        ThisApp.cpp \
        cmd/Action.cpp \
        cmd/ArgInfo.cpp \
        cmd/ArgManager.cpp \
        cmd/CompositeAction.cpp \
        cmd/ConditionalStringAction.cpp \
        cmd/DoNothing.cpp \
        cmd/Global.cpp \
        cmd/HelpAction.cpp \
        cmd/IfAction.cpp \
        cmd/Info.cpp \
        cmd/InstanceSafeAction.cpp \
        cmd/LineTranslator.cpp \
        cmd/Menu.cpp \
        cmd/MenuAction.cpp \
        cmd/Parameter.cpp \
        cmd/PrintAction.cpp \
        cmd/Result.cpp \
        cmd/SafeAction.cpp \
        cmd/Substitutor.cpp \
        cmd/Task.cpp \
        cmd/TaskIdGenerator.cpp \
        cmd/TaskIdIncGenerator.cpp \
        cmd/TaskManager.cpp \
        cmd/Translator.cpp \
        cmd/Value.cpp \
        cmd/def/ActionDef.cpp \
        cmd/def/ArgDef.cpp \
        cmd/def/MetaType.cpp \
        cmd/def/TypeDef.cpp \
        cmd/err/AdditionalInfo.cpp \
        cmd/err/ArgumentConversionInfo.cpp \
        cmd/err/ArgumentInfo.cpp \
        cmd/err/CommandNotFoundInfo.cpp \
        cmd/err/ConversionException.cpp \
        cmd/err/Error.cpp \
        cmd/err/MissingRequiredArgumentInfo.cpp \
        cmd/rep/BoolRep.cpp \
        cmd/rep/CharRep.cpp \
        cmd/rep/DecIntRep.cpp \
        cmd/rep/DoubleRep.cpp \
        cmd/rep/HexIntRep.cpp \
        cmd/rep/IntRep.cpp \
        cmd/rep/NullRep.cpp \
        cmd/rep/Representation.cpp \
        cmd/rep/SimpleCharRep.cpp \
        cmd/rep/SimpleStringRep.cpp \
        cmd/rep/StringRep.cpp \
        cmd/rep/TaskRep.cpp \
        console/Reader.cpp \
        example/MakeSentence.cpp \
        main.cpp \
        math/DegreesToRadians.cpp \
        math/Divide.cpp \
        math/IsEven.cpp \
        math/SineOfRadians.cpp \
        test/TestActionMap.cpp \
        test/TestCmdValue.cpp \
        test/TestLazyPointer.cpp \
        test/TestSharedVector.cpp

HEADERS += \
    App.h \
    ThisApp.h \
    cmd/Action.h \
    cmd/ArgInfo.h \
    cmd/ArgManager.h \
    cmd/CompositeAction.h \
    cmd/ConditionalStringAction.h \
    cmd/DoNothing.h \
    cmd/Global.h \
    cmd/HelpAction.h \
    cmd/IfAction.h \
    cmd/Info.h \
    cmd/InstanceSafeAction.h \
    cmd/LineTranslator.h \
    cmd/Menu.h \
    cmd/MenuAction.h \
    cmd/Parameter.h \
    cmd/PrintAction.h \
    cmd/Result.h \
    cmd/SafeAction.h \
    cmd/Substitutor.h \
    cmd/Task.h \
    cmd/TaskIdGenerator.h \
    cmd/TaskIdIncGenerator.h \
    cmd/TaskManager.h \
    cmd/Translator.h \
    cmd/Types.h \
    cmd/Value.h \
    cmd/def/ActionDef.h \
    cmd/def/ArgDef.h \
    cmd/def/MetaType.h \
    cmd/def/TypeDef.h \
    cmd/err/AdditionalInfo.h \
    cmd/err/ArgumentConversionInfo.h \
    cmd/err/ArgumentInfo.h \
    cmd/err/CommandNotFoundInfo.h \
    cmd/err/ConversionException.h \
    cmd/err/Error.h \
    cmd/err/MissingRequiredArgumentInfo.h \
    cmd/rep/BoolRep.h \
    cmd/rep/CharRep.h \
    cmd/rep/DecIntRep.h \
    cmd/rep/DoubleRep.h \
    cmd/rep/HexIntRep.h \
    cmd/rep/IntRep.h \
    cmd/rep/NullRep.h \
    cmd/rep/Representation.h \
    cmd/rep/SimpleCharRep.h \
    cmd/rep/SimpleStringRep.h \
    cmd/rep/StringRep.h \
    cmd/rep/TaskRep.h \
    common/Factory.h \
    common/LazyPointer.h \
    common/LimitedStack.h \
    common/SharedMap.h \
    common/SharedVector.h \
    console/Reader.h \
    example/MakeSentence.h \
    math/DegreesToRadians.h \
    math/Divide.h \
    math/IsEven.h \
    math/SineOfRadians.h \
    test/TestActionMap.h \
    test/TestCmdValue.h \
    test/TestLazyPointer.h \
    test/TestSharedVector.h
