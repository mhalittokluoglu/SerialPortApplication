#!/bin/bash
cmake -S . -B BuildDirLinux -DCMAKE_BUILD_TYPE=Debug -DLOG_ENABLED=ON -DUDP_LOG=ON -DCONSOLE_LOG=OFF -DLINUX_SYSTEM=ON -DWINDOWS_SYSTEM=OFF