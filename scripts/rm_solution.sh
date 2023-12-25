#!/usr/bin/env bash

name=$1
srcPath="../src/$name"
testPath="../tests/$name"

rm -rf "$srcPath"
rm -rf "$testPath"

sed -i "" "s/add_subdirectory($name)//g" "../tests/CMakeLists.txt"
sed '/^$/d' "../tests/CMakeLists.txt" > .tmpFile && mv .tmpFile "../tests/CMakeLists.txt"
