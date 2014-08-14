#!/bin/bash
# create multiresolution windows icon
ICON_DST=../../src/qt/res/icons/greenbacks.ico

convert ../../src/qt/res/icons/greenbacks-16.png ../../src/qt/res/icons/greenbacks-32.png ../../src/qt/res/icons/greenbacks-48.png ${ICON_DST}
