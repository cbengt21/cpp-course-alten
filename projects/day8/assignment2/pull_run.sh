#!/usr/bin/env bash
git clone \
    --depth 1 \
    --filter=blob:none \
    --no-checkout \
    git@github.com:cbengt21/cpp-course-alten.git;
 cd cpp-course-alten
 git checkout main -- projects/miniProject/

cd miniProject/miniProject/
g++ main.cpp
a.out