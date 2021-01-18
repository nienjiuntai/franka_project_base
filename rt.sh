#!/bin/bash
xz -cd linux-4.4.12.tar.xz | tar xvf -
cd linux-4.4.12
xzcat ../patch-4.4.12-rt19.patch.xz | patch -p1