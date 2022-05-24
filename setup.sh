#!/bin/bash

cd ~
sudo apt-get update -y
sudo apt-get install make git zlib1g-dev libssl-dev gperf cmake g++ -y
git clone --recursive https://github.com/tdlib/telegram-bot-api.git
rm -rfv telegram-bot-api/build
mkdir -p telegram-bot-api/build
cd telegram-bot-api/build
cmake -DCMAKE_BUILD_TYPE=Release -DCMAKE_INSTALL_PREFIX:PATH=.. ..
cmake --build . --target install
cd ~
rm -rfv ~/telegram-bot-api
