#!/bin/bash

if [[ -z ${BINARY_PATH+1} ]];
then
  source "$(cd "$( dirname "${BASH_SOURCE[0]}" )" >/dev/null 2>&1 && pwd)"/set_vars.sh
fi

cmake -B "${APP_ROOT_PATH}/build" "${APP_ROOT_PATH}" "$@"
cmake --build "${APP_ROOT_PATH}/build" -j$(nproc)
