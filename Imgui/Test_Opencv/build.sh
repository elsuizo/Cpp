#!/usr/bin/env bash
mkdir -p build && \
pushd build && \
  g++\
    -o main \
    ../external/imgui/imgui.cpp \
    ../external/imgui/imgui_draw.cpp \
    ../src/main.cpp \
    -Wall \
    -g                      `# Generate complete debug info` \
    -std=c++11 \
    -I ../include \
    -I ../external/imgui \
    -L ../lib \
    `pkg-config opencv --cflags` \
    `pkg-config opencv --libs` \
    -lGL \
    -lGLU \
    -lX11 \
    -lXxf86vm \
    -lXrandr \
    -lpthread \
    -lXi \
    -lXinerama \
    -lXcursor && \
popd || exit 1
