#!/bin/bash
# usage: ./compile.sh src.cpp prog.exe
# compile the source using either the compiler specified in a comment in the source file,
# or using gcc -O3 by default une faute de frappe
ARG=$1
OUT=$2
STR="//compile: "
NBSTR=${#STR}
RES=$(grep -P "^$STR" $ARG | tail -c "+$NBSTR")
if [ "$RES" == "" ]; then
  COM="gcc -O3"
else
  COM="$RES"
fi
STR2="//options: "
NBSTR2=${#STR2}
OPT=$(grep -P "^$STR2" $ARG | tail -c "+$NBSTR2")
$COM $ARG -o $OUT -lstdc++ $OPT
